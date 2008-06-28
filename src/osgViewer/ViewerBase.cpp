/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2006 Robert Osfield 
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/

#include <stdlib.h>
#include <string.h>

#include <osgViewer/ViewerBase>
#include <osgViewer/View>
#include <osgViewer/Renderer>

#include <osg/io_utils>

#include <osg/TextureCubeMap>
#include <osg/TextureRectangle>
#include <osg/TexMat>
#include <osg/DeleteHandler>

#include <osgUtil/Optimizer>
#include <osgUtil/IntersectionVisitor>

static osg::ApplicationUsageProxy ViewerBase_e0(osg::ApplicationUsage::ENVIRONMENTAL_VARIABLE,"OSG_CONFIG_FILE <filename>","Specify a viewer configuration file to load by default.");
static osg::ApplicationUsageProxy ViewerBase_e1(osg::ApplicationUsage::ENVIRONMENTAL_VARIABLE,"OSG_THREADING <value>","Set the threading model using by Viewer, <value> can be SingleThreaded, CullDrawThreadPerContext, DrawThreadPerContext or CullThreadPerCameraDrawThreadPerContext.");
static osg::ApplicationUsageProxy ViewerBase_e2(osg::ApplicationUsage::ENVIRONMENTAL_VARIABLE,"OSG_SCREEN <value>","Set the default screen that windows should open up on.");
static osg::ApplicationUsageProxy ViewerBase_e3(osg::ApplicationUsage::ENVIRONMENTAL_VARIABLE,"OSG_WINDOW x y width height","Set the default window dimensions that windows should open up on.");


using namespace osgViewer;

ViewerBase::ViewerBase():
    osg::Object(true)
{
    _firstFrame = true;
    _done = false;
    _keyEventSetsDone = osgGA::GUIEventAdapter::KEY_Escape;
    _quitEventSetsDone = true;
    _releaseContextAtEndOfFrameHint = true;
    _threadingModel = AutomaticSelection;
    _threadsRunning = false;
    _endBarrierPosition = AfterSwapBuffers;
}

ViewerBase::ViewerBase(const ViewerBase& base):
    osg::Object(true)
{
    _firstFrame = true;
    _done = false;
    _keyEventSetsDone = osgGA::GUIEventAdapter::KEY_Escape;
    _quitEventSetsDone = true;
    _releaseContextAtEndOfFrameHint = true;
    _threadingModel = AutomaticSelection;
    _threadsRunning = false;
    _endBarrierPosition = AfterSwapBuffers;
}

void ViewerBase::setThreadingModel(ThreadingModel threadingModel)
{
    if (_threadingModel == threadingModel) return;
    
    if (_threadsRunning) stopThreading();
    
    _threadingModel = threadingModel;

    if (isRealized() && _threadingModel!=SingleThreaded) startThreading();
}

ViewerBase::ThreadingModel ViewerBase::suggestBestThreadingModel()
{
    const char* str = getenv("OSG_THREADING");
    if (str)
    {
        if (strcmp(str,"SingleThreaded")==0) return SingleThreaded;
        else if (strcmp(str,"CullDrawThreadPerContext")==0) return CullDrawThreadPerContext;
        else if (strcmp(str,"DrawThreadPerContext")==0) return DrawThreadPerContext;
        else if (strcmp(str,"CullThreadPerCameraDrawThreadPerContext")==0) return CullThreadPerCameraDrawThreadPerContext;
    }

    Contexts contexts;
    getContexts(contexts);
    
    if (contexts.empty()) return SingleThreaded;

#if 0
    // temporary hack to disable multi-threading under Windows till we find good solutions for
    // crashes that users are seeing.
    return SingleThreaded;
#endif

    Cameras cameras;
    getCameras(cameras);

    if (cameras.empty()) return SingleThreaded;


    int numProcessors = OpenThreads::GetNumberOfProcessors();

    if (contexts.size()==1)
    {
        if (numProcessors==1) return SingleThreaded;
        else return DrawThreadPerContext;
    }
    
#if 1
    if (numProcessors >= static_cast<int>(cameras.size()+contexts.size()))
    {
        return CullThreadPerCameraDrawThreadPerContext;
    }
#endif

    return DrawThreadPerContext;
}

void ViewerBase::setUpThreading()
{
    Contexts contexts;
    getContexts(contexts);

    if (_threadingModel==SingleThreaded)
    {
        if (_threadsRunning) stopThreading();
        else
        {
            // we'll set processor affinity here to help single threaded apps
            // with multiple processor cores, and using the database pager.
            int numProcessors = OpenThreads::GetNumberOfProcessors();
            bool affinity = numProcessors>1;    
            if (affinity) 
            {
                OpenThreads::SetProcessorAffinityOfCurrentThread(0);

                Scenes scenes;
                getScenes(scenes);
                
                for(Scenes::iterator itr = scenes.begin();
                    itr != scenes.end();
                    ++itr)
                {
                    Scene* scene = *itr;
                    osgDB::DatabasePager* dp = scene->getDatabasePager();
                    if (dp)
                    {
                        for(unsigned int i=0; i<dp->getNumDatabaseThreads(); ++i)
                        {
                            osgDB::DatabasePager::DatabaseThread* dt = dp->getDatabaseThread(i);
                            dt->setProcessorAffinity(1);
                        }
                    }
                }
            
            }
        }
    }
    else
    {
        if (!_threadsRunning) startThreading();
    }
    
}

void ViewerBase::setEndBarrierPosition(BarrierPosition bp)
{
    if (_endBarrierPosition == bp) return;
    
    if (_threadsRunning) stopThreading();
    
    _endBarrierPosition = bp;

    if (_threadingModel!=SingleThreaded) startThreading();
}


void ViewerBase::stopThreading()
{
    if (!_threadsRunning) return;

    osg::notify(osg::INFO)<<"ViewerBase::stopThreading() - stopping threading"<<std::endl;

    Contexts contexts;
    getContexts(contexts);

    Cameras cameras;
    getCameras(cameras);

    Contexts::iterator gcitr;
    Cameras::iterator citr;

    for(Cameras::iterator camItr = cameras.begin();
        camItr != cameras.end();
        ++camItr)
    {
        osg::Camera* camera = *camItr;
        Renderer* renderer = dynamic_cast<Renderer*>(camera->getRenderer());
        if (renderer) renderer->release();
    }

    // delete all the graphics threads.    
    for(gcitr = contexts.begin();
        gcitr != contexts.end();
        ++gcitr)
    {
        (*gcitr)->setGraphicsThread(0);
    }

    // delete all the camera threads.    
    for(citr = cameras.begin();
        citr != cameras.end();
        ++citr)
    {
        (*citr)->setCameraThread(0);
    }

    for(Cameras::iterator camItr = cameras.begin();
        camItr != cameras.end();
        ++camItr)
    {
        osg::Camera* camera = *camItr;
        Renderer* renderer = dynamic_cast<Renderer*>(camera->getRenderer());
        if (renderer)
        {
            renderer->setGraphicsThreadDoesCull( true );
            renderer->setDone(false);
        }
    }


    _threadsRunning = false;
    _startRenderingBarrier = 0;
    _endRenderingDispatchBarrier = 0;
    _endDynamicDrawBlock = 0;

    osg::notify(osg::INFO)<<"Viewer::stopThreading() - stopped threading."<<std::endl;
}

void ViewerBase::startThreading()
{
    if (_threadsRunning) return;
    
    osg::notify(osg::INFO)<<"Viewer::startThreading() - starting threading"<<std::endl;
    
    // release any context held by the main thread.
    releaseContext();

    _threadingModel = _threadingModel==AutomaticSelection ? suggestBestThreadingModel() : _threadingModel;

    Contexts contexts;
    getContexts(contexts);
    
    osg::notify(osg::INFO)<<"Viewer::startThreading() - contexts.size()="<<contexts.size()<<std::endl;

    Cameras cameras;
    getCameras(cameras);
    
    unsigned int numThreadsOnStartBarrier = 0;
    unsigned int numThreadsOnEndBarrier = 0;
    switch(_threadingModel)
    {
        case(SingleThreaded): 
            numThreadsOnStartBarrier = 1;
            numThreadsOnEndBarrier = 1;
            return;
        case(CullDrawThreadPerContext): 
            numThreadsOnStartBarrier = contexts.size()+1;
            numThreadsOnEndBarrier = contexts.size()+1;
            break;
        case(DrawThreadPerContext): 
            numThreadsOnStartBarrier = 1;
            numThreadsOnEndBarrier = 1;
            break;
        case(CullThreadPerCameraDrawThreadPerContext): 
            numThreadsOnStartBarrier = cameras.size()+1;
            numThreadsOnEndBarrier = 1; 
            break;
        default:
            osg::notify(osg::NOTICE)<<"Error: Threading model not selected"<<std::endl;
            return;
    }

    // using multi-threading so make sure that new objects are allocated with thread safe ref/unref
    osg::Referenced::setThreadSafeReferenceCounting(true);

    Scenes scenes;
    getScenes(scenes);
    for(Scenes::iterator scitr = scenes.begin();
        scitr != scenes.end();
        ++scitr)
    {
        if ((*scitr)->getSceneData())
        {
            osg::notify(osg::INFO)<<"Making scene thread safe"<<std::endl;

            // make sure that existing scene graph objects are allocated with thread safe ref/unref
            (*scitr)->getSceneData()->setThreadSafeRefUnref(true);

            // update the scene graph so that it has enough GL object buffer memory for the graphics contexts that will be using it.
            (*scitr)->getSceneData()->resizeGLObjectBuffers(osg::DisplaySettings::instance()->getMaxNumberOfGraphicsContexts());
        }
    }
        
    int numProcessors = OpenThreads::GetNumberOfProcessors();
    bool affinity = numProcessors>1;    
    
    Contexts::iterator citr;

    unsigned int numViewerDoubleBufferedRenderingOperation = 0;

    bool graphicsThreadsDoesCull = _threadingModel == CullDrawThreadPerContext || _threadingModel==SingleThreaded;

    for(Cameras::iterator camItr = cameras.begin();
        camItr != cameras.end();
        ++camItr)
    {
        osg::Camera* camera = *camItr;
        Renderer* renderer = dynamic_cast<Renderer*>(camera->getRenderer());
        if (renderer)
        {
            renderer->setGraphicsThreadDoesCull(graphicsThreadsDoesCull);
            renderer->setDone(false);
            ++numViewerDoubleBufferedRenderingOperation;
        }
    }

    if (_threadingModel==CullDrawThreadPerContext)
    {
        _startRenderingBarrier = 0;
        _endRenderingDispatchBarrier = 0;
        _endDynamicDrawBlock = 0;
    }
    else if (_threadingModel==DrawThreadPerContext || 
             _threadingModel==CullThreadPerCameraDrawThreadPerContext)
    {
        _startRenderingBarrier = 0;
        _endRenderingDispatchBarrier = 0;
        _endDynamicDrawBlock = new osg::EndOfDynamicDrawBlock(numViewerDoubleBufferedRenderingOperation);
        
#ifndef OSGUTIL_RENDERBACKEND_USE_REF_PTR
        if (!osg::Referenced::getDeleteHandler()) osg::Referenced::setDeleteHandler(new osg::DeleteHandler(2));
        else osg::Referenced::getDeleteHandler()->setNumFramesToRetainObjects(2);
#endif
    }
    
    if (numThreadsOnStartBarrier>1)
    {
        _startRenderingBarrier = new osg::BarrierOperation(numThreadsOnStartBarrier, osg::BarrierOperation::NO_OPERATION);
    }

    if (numThreadsOnEndBarrier>1)
    {
        _endRenderingDispatchBarrier = new osg::BarrierOperation(numThreadsOnEndBarrier, osg::BarrierOperation::NO_OPERATION);
    }


    osg::ref_ptr<osg::BarrierOperation> swapReadyBarrier = contexts.empty() ? 0 : new osg::BarrierOperation(contexts.size(), osg::BarrierOperation::NO_OPERATION);

    osg::ref_ptr<osg::SwapBuffersOperation> swapOp = new osg::SwapBuffersOperation();

    typedef std::map<OpenThreads::Thread*, int> ThreadAffinityMap;
    ThreadAffinityMap threadAffinityMap;

    unsigned int processNum = 1;
    for(citr = contexts.begin();
        citr != contexts.end();
        ++citr, ++processNum)
    {
        osg::GraphicsContext* gc = (*citr);
        
        if (!gc->isRealized())
        {
            osg::notify(osg::INFO)<<"ViewerBase::startThreading() : Realizng window "<<gc<<std::endl;
            gc->realize();
        }
        
        gc->getState()->setDynamicObjectRenderingCompletedCallback(_endDynamicDrawBlock.get());

        // create the a graphics thread for this context
        gc->createGraphicsThread();

        if (affinity) gc->getGraphicsThread()->setProcessorAffinity(processNum % numProcessors);
        threadAffinityMap[gc->getGraphicsThread()] = processNum % numProcessors;

        // add the startRenderingBarrier
        if (_threadingModel==CullDrawThreadPerContext && _startRenderingBarrier.valid()) gc->getGraphicsThread()->add(_startRenderingBarrier.get());

        // add the rendering operation itself.
        gc->getGraphicsThread()->add(new osg::RunOperations());

        if (_threadingModel==CullDrawThreadPerContext && _endBarrierPosition==BeforeSwapBuffers && _endRenderingDispatchBarrier.valid())
        {
            // add the endRenderingDispatchBarrier
            gc->getGraphicsThread()->add(_endRenderingDispatchBarrier.get());
        }

        if (swapReadyBarrier.valid()) gc->getGraphicsThread()->add(swapReadyBarrier.get());

        // add the swap buffers
        gc->getGraphicsThread()->add(swapOp.get());

        if (_threadingModel==CullDrawThreadPerContext && _endBarrierPosition==AfterSwapBuffers && _endRenderingDispatchBarrier.valid())
        {
            // add the endRenderingDispatchBarrier
            gc->getGraphicsThread()->add(_endRenderingDispatchBarrier.get());
        }

    }

    if (_threadingModel==CullThreadPerCameraDrawThreadPerContext && numThreadsOnStartBarrier>1)
    {
        Cameras::iterator camItr;

        for(camItr = cameras.begin();
            camItr != cameras.end();
            ++camItr, ++processNum)
        {
            osg::Camera* camera = *camItr;
            camera->createCameraThread();

            if (affinity) camera->getCameraThread()->setProcessorAffinity(processNum % numProcessors);
            threadAffinityMap[camera->getCameraThread()] = processNum % numProcessors;

            osg::GraphicsContext* gc = camera->getGraphicsContext();

            // add the startRenderingBarrier
            if (_startRenderingBarrier.valid()) camera->getCameraThread()->add(_startRenderingBarrier.get());

            Renderer* renderer = dynamic_cast<Renderer*>(camera->getRenderer());
            renderer->setGraphicsThreadDoesCull(false);
            camera->getCameraThread()->add(renderer);
            
            if (_endRenderingDispatchBarrier.valid())
            {
                // add the endRenderingDispatchBarrier
                gc->getGraphicsThread()->add(_endRenderingDispatchBarrier.get());
            }

        }

        for(camItr = cameras.begin();
            camItr != cameras.end();
            ++camItr)
        {
            osg::Camera* camera = *camItr;
            if (camera->getCameraThread() && !camera->getCameraThread()->isRunning())
            {
                osg::notify(osg::INFO)<<"  camera->getCameraThread()-> "<<camera->getCameraThread()<<std::endl;
                camera->getCameraThread()->startThread();
            }
        }
    }

#if 0    
    if (affinity) 
    {
        OpenThreads::SetProcessorAffinityOfCurrentThread(0);
        if (_scene.valid() && _scene->getDatabasePager())
        {
#if 0        
            _scene->getDatabasePager()->setProcessorAffinity(1);
#else
            _scene->getDatabasePager()->setProcessorAffinity(0);
#endif
        }
    }
#endif

#if 0
    if (affinity)
    {
        for(ThreadAffinityMap::iterator titr = threadAffinityMap.begin();
            titr != threadAffinityMap.end();
            ++titr)
        {
            titr->first->setProcessorAffinity(titr->second);
        }
    }
#endif


    for(citr = contexts.begin();
        citr != contexts.end();
        ++citr)
    {
        osg::GraphicsContext* gc = (*citr);
        if (gc->getGraphicsThread() && !gc->getGraphicsThread()->isRunning())
        {
            osg::notify(osg::INFO)<<"  gc->getGraphicsThread()->startThread() "<<gc->getGraphicsThread()<<std::endl;
            gc->getGraphicsThread()->startThread();
            // OpenThreads::Thread::YieldCurrentThread();
        }
    }

    _threadsRunning = true;

    osg::notify(osg::INFO)<<"Set up threading"<<std::endl;
}

void ViewerBase::checkWindowStatus()
{
    Contexts contexts;
    getContexts(contexts);
    
    // osg::notify(osg::NOTICE)<<"Viewer::checkWindowStatus() - "<<contexts.size()<<std::endl;
    
    if (contexts.size()==0)
    {
        _done = true;
        if (areThreadsRunning()) stopThreading();
    }
}

void ViewerBase::addUpdateOperation(osg::Operation* operation)
{
    if (!operation) return;

    if (!_updateOperations) _updateOperations = new osg::OperationQueue;
    
    _updateOperations->add(operation);
}

void ViewerBase::removeUpdateOperation(osg::Operation* operation)
{
    if (!operation) return;

    if (_updateOperations.valid())
    {
        _updateOperations->remove(operation);
    } 
}

int ViewerBase::run()
{
    if (!isRealized())
    {
        realize();
    }

#if 0
    while (!done())
    {
        frame();
    }
#else

    const char* str = getenv("OSG_RUN_FRAME_COUNT");
    if (str)
    {
        int runTillFrameNumber = atoi(str);
        while (!done() && getViewerFrameStamp()->getFrameNumber()<runTillFrameNumber)
        {
            frame();
        }
    }
    else
    {
        while (!done())
        {
            frame();
        }
    }
#endif    
    return 0;
}

void ViewerBase::frame(double simulationTime)
{
    if (_done) return;

    // osg::notify(osg::NOTICE)<<std::endl<<"CompositeViewer::frame()"<<std::endl<<std::endl;

    if (_firstFrame)
    {
        viewerInit();
        
        if (!isRealized())
        {
            realize();
        }
        
        _firstFrame = false;
    }
    advance(simulationTime);
    
    eventTraversal();
    updateTraversal();
    renderingTraversals();
}


void ViewerBase::renderingTraversals()
{
    bool _outputMasterCameraLocation = false;
    if (_outputMasterCameraLocation)
    {
        Views views;
        getViews(views);

        for(Views::iterator itr = views.begin();
            itr != views.end();
            ++itr)
        {
            osgViewer::View* view = *itr;
            if (view)
            {
                const osg::Matrixd& m = view->getCamera()->getInverseViewMatrix();
                osg::notify(osg::NOTICE)<<"View "<<view<<", Master Camera position("<<m.getTrans()<<"), rotation("<<m.getRotate()<<")"<<std::endl;
            }
        }
    }
        
    // check to see if windows are still valid
    checkWindowStatus();

    if (_done) return;

    double beginRenderingTraversals = elapsedTime();

    osg::FrameStamp* frameStamp = getViewerFrameStamp();

    Scenes scenes;
    getScenes(scenes);
    
    for(Scenes::iterator sitr = scenes.begin();
        sitr != scenes.end();
        ++sitr)
    {
        Scene* scene = *sitr;
        osgDB::DatabasePager* dp = scene ? scene->getDatabasePager() : 0;
        if (dp)
        {
            dp->signalBeginFrame(frameStamp);
        }
        
        if (scene->getSceneData())
        {
            // fire off a build of the bounding volumes while we 
            // are still running single threaded.
            scene->getSceneData()->getBound();
        }
    }

    // osg::notify(osg::NOTICE)<<std::endl<<"Start frame"<<std::endl;
    

    Contexts contexts;
    getContexts(contexts);

    Cameras cameras;
    getCameras(cameras);
    
    Contexts::iterator itr;
    
    bool doneMakeCurrentInThisThread = false;

    // dispatch the the rendering threads
    if (_startRenderingBarrier.valid()) _startRenderingBarrier->block();

    if (_endDynamicDrawBlock.valid())
    {
        _endDynamicDrawBlock->reset();
    }
    
    // reset any double buffer graphics objects
    for(Cameras::iterator camItr = cameras.begin();
        camItr != cameras.end();
        ++camItr)
    {
        osg::Camera* camera = *camItr;
        Renderer* renderer = dynamic_cast<Renderer*>(camera->getRenderer());
        if (renderer)
        {
            if (!renderer->getGraphicsThreadDoesCull() && !(camera->getCameraThread()))
            {
                renderer->cull();
            }
        }
    }

    for(itr = contexts.begin();
        itr != contexts.end();
        ++itr)
    {
        if (_done) return;
        if (!((*itr)->getGraphicsThread()) && (*itr)->valid())
        {
            doneMakeCurrentInThisThread = true; 
            makeCurrent(*itr);
            (*itr)->runOperations();
        }
    }

    // osg::notify(osg::NOTICE)<<"Joing _endRenderingDispatchBarrier block "<<_endRenderingDispatchBarrier.get()<<std::endl;

    // wait till the rendering dispatch is done.
    if (_endRenderingDispatchBarrier.valid()) _endRenderingDispatchBarrier->block();

    for(itr = contexts.begin();
        itr != contexts.end();
        ++itr)
    {
        if (_done) return;

        if (!((*itr)->getGraphicsThread()) && (*itr)->valid())
        { 
            doneMakeCurrentInThisThread = true; 
            makeCurrent(*itr);
            (*itr)->swapBuffers();
        }
    }

    for(Scenes::iterator sitr = scenes.begin();
        sitr != scenes.end();
        ++sitr)
    {
        Scene* scene = *sitr;
        osgDB::DatabasePager* dp = scene ? scene->getDatabasePager() : 0;
        if (dp)
        {
            dp->signalEndFrame();
        }
    }

    // wait till the dynamic draw is complete.
    if (_endDynamicDrawBlock.valid()) 
    {
        // osg::Timer_t startTick = osg::Timer::instance()->tick();
        _endDynamicDrawBlock->block();
        // osg::notify(osg::NOTICE)<<"Time waiting "<<osg::Timer::instance()->delta_m(startTick, osg::Timer::instance()->tick())<<std::endl;;
    }
    
    if (_releaseContextAtEndOfFrameHint && doneMakeCurrentInThisThread)
    {
        //osg::notify(osg::NOTICE)<<"Doing release context"<<std::endl;
        releaseContext();
    }

    if (getStats() && getStats()->collectStats("update"))
    {
        double endRenderingTraversals = elapsedTime();

        // update current frames stats
        getStats()->setAttribute(frameStamp->getFrameNumber(), "Rendering traversals begin time ", beginRenderingTraversals);
        getStats()->setAttribute(frameStamp->getFrameNumber(), "Rendering traversals end time ", endRenderingTraversals);
        getStats()->setAttribute(frameStamp->getFrameNumber(), "Rendering traversals time taken", endRenderingTraversals-beginRenderingTraversals);
    }
}

