/* -*-c++-*- Present3D - Copyright (C) 1999-2006 Robert Osfield 
 *
 * This software is open source and may be redistributed and/or modified under  
 * the terms of the GNU General Public License (GPL) version 2.0.
 * The full license is in LICENSE.txt file included with this distribution,.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * include LICENSE.txt for more details.
*/

#ifndef SLIDESHOWCONSTRUCTOR
#define SLIDESHOWCONSTRUCTOR

#include <osg/Vec3>
#include <osg/Vec4>
#include <osg/Group>
#include <osg/ClearNode>
#include <osg/Switch>
#include <osg/AnimationPath>
#include <osg/ImageStream>
#include <osgText/Text>
#include <osgGA/GUIEventAdapter>

#include <osgDB/FileUtils>

#include "AnimationMaterial.h"
#include "SlideEventHandler.h"

namespace osgPresentation
{

class SlideShowConstructor
{
public:

    
    enum CoordinateFrame { SLIDE, MODEL };

    
    LayerAttributes* getOrCreateLayerAttributes(osg::Node* node);
    
    void setDuration(osg::Node* node,double duration)
    {
        getOrCreateLayerAttributes(node)->setDuration(duration);
    }
    
    void addKey(osg::Node* node,const KeyPosition& kp)
    {
        getOrCreateLayerAttributes(node)->addKey(kp);
    }

    void addRunString(osg::Node* node, const std::string& runString)
    {
        getOrCreateLayerAttributes(node)->addRunString(runString);
    }

    void setJump(osg::Node* node, bool relativeJump, int slideNum, int layerNum)
    {
        getOrCreateLayerAttributes(node)->setJump(relativeJump, slideNum, layerNum);
    }

    void addPresentationKey(const KeyPosition& kp)
    {
        if (!_presentationSwitch) createPresentation();            
        if (_presentationSwitch.valid()) addKey( _presentationSwitch.get(), kp);
    }

    void addPresentationRunString(const std::string& runString)
    {
        if (!_presentationSwitch) createPresentation();            
        if (_presentationSwitch.valid()) addRunString( _presentationSwitch.get(),runString);
    }

    void addSlideKey(const KeyPosition& kp)
    {
        if (!_slide) addSlide();
        if (_slide.valid()) addKey(_slide.get(),kp);
    }
    
    void addSlideRunString(const std::string& runString)
    {
        if (!_slide) addSlide();
        if (_slide.valid()) addRunString(_slide.get(),runString);
    }
    
    void setSlideJump(bool relativeJump, int switchNum, int layerNum)
    {
        if (!_slide) addSlide();
        if (_slide.valid()) setJump(_slide.get(),relativeJump, switchNum, layerNum);
    }

    void addLayerKey(const KeyPosition& kp)
    {
        if (!_currentLayer) addLayer();
        if (_currentLayer.valid()) addKey(_currentLayer.get(),kp);
    }

    void addLayerRunString(const std::string& runString)
    {
        if (!_currentLayer) addLayer();
        if (_currentLayer.valid()) addRunString(_currentLayer.get(),runString);
    }
    

    void setLayerJump(bool relativeJump, int switchNum, int layerNum)
    {
        if (!_currentLayer) addLayer();
        if (_currentLayer.valid()) setJump(_currentLayer.get(),relativeJump, switchNum, layerNum);
    }



    struct PositionData
    {
        PositionData():
            frame(SlideShowConstructor::SLIDE),
            position(0.0f,1.0f,0.0f),
            //position(0.5f,0.5f,0.0f),
            scale(1.0f,1.0f,1.0f),
            rotate(0.0f,0.0f,0.0f,1.0f),
            rotation(0.0f,0.0f,1.0f,0.0f),
            absolute_path(false),
            inverse_path(false),
            path_time_offset(0.0),
            path_time_multiplier(1.0f),
            path_loop_mode(osg::AnimationPath::NO_LOOPING),
            animation_material_time_offset(0.0),
            animation_material_time_multiplier(1.0),
            animation_material_loop_mode(ss3d::AnimationMaterial::NO_LOOPING) {}
    
        bool requiresPosition() const
        {
            return (position[0]!=0.0f || position[1]!=1.0f || position[2]!=1.0f);
        }

        bool requiresScale() const
        {
            return (scale[0]!=1.0f || scale[1]!=1.0f || scale[2]!=1.0f);
        }

        bool requiresRotate() const
        {
            return rotate[0]!=0.0f;
        }

        bool requiresAnimation() const
        {
            return (rotation[0]!=0.0f || !path.empty());
        }

        bool requiresMaterialAnimation() const
        {
            return !animation_material_filename.empty() || !fade.empty();
        }

        CoordinateFrame                         frame;
        osg::Vec3                               position;
        osg::Vec3                               scale;
        osg::Vec4                               rotate;
        osg::Vec4                               rotation;
        std::string                             animation_name;
        bool                                    absolute_path;
        bool                                    inverse_path;
        double                                  path_time_offset;
        double                                  path_time_multiplier;
        osg::AnimationPath::LoopMode            path_loop_mode;
        std::string                             path;
        double                                  animation_material_time_offset;
        double                                  animation_material_time_multiplier;
        ss3d::AnimationMaterial::LoopMode       animation_material_loop_mode;
        std::string                             animation_material_filename;
        std::string                             fade;
    };

    struct ModelData
    {
        ModelData():
            effect("") {}
            
        std::string effect;
    };

    struct ImageData
    {
        ImageData():
            width(1.0f),
            height(1.0f),
            region(0.0f,0.0f,1.0f,1.0f),
            region_in_pixel_coords(false),
            texcoord_rotate(0.0f),
            loopingMode(osg::ImageStream::NO_LOOPING),
            page(-1),
            backgroundColor(1.0f,1.0f,1.0f,1.0f) {}
            
        float                           width;
        float                           height;
        osg::Vec4                       region;
        bool                            region_in_pixel_coords;
        float                           texcoord_rotate;
        osg::ImageStream::LoopingMode   loopingMode;
        int                             page;
        osg::Vec4                       backgroundColor;
    };

    struct FontData
    {
        FontData():
            font("fonts/arial.ttf"),
            layout(osgText::Text::LEFT_TO_RIGHT),
            alignment(osgText::Text::LEFT_BASE_LINE),
            axisAlignment(osgText::Text::XZ_PLANE),
            characterSize(0.04f),
            maximumHeight(1.0f),
            maximumWidth(1.0f),
            color(1.0f,1.0f,1.0f,1.0f) {}

        std::string                     font;
        osgText::Text::Layout           layout;
        osgText::Text::AlignmentType    alignment;
        osgText::Text::AxisAlignment    axisAlignment;
        float                           characterSize;
        float                           maximumHeight;
        float                           maximumWidth;
        osg::Vec4                       color;
    };


    SlideShowConstructor(const osgDB::ReaderWriter::Options* options);

    void createPresentation();
    
    void setBackgroundColor(const osg::Vec4& color, bool updateClearNode);
    const osg::Vec4& getBackgroundColor() const { return _backgroundColor; }
    
    void setTextColor(const osg::Vec4& color);
    const osg::Vec4& getTextColor() const { return _textFontDataDefault.color; }
    
    void setPresentationName(const std::string& name);
    
    void setPresentationAspectRatio(float aspectRatio);

    void setPresentationAspectRatio(const std::string& str);
    
    void setPresentationDuration(double duration);


    void addSlide();
    
    void selectSlide(int slideNum);


    void setSlideTitle(const std::string& name, PositionData& positionData, FontData& fontData)
    {
        _titlePositionData = positionData;
        _titleFontData = fontData;
        _slideTitle = name;
    }

    void setSlideBackground(const std::string& name) { _slideBackgroundImageFileName = name; }
    
    void setSlideDuration(double duration);


    void addLayer(bool inheritPreviousLayers=true, bool defineAsBaseLayer=false);
    
    void selectLayer(int layerNum);
    
    void setLayerDuration(double duration);

    
    // title settings
    FontData& getTitleFontData() { return _titleFontData; }
    FontData& getTitleFontDataDefault() { return _titleFontDataDefault; }

    PositionData& getTitlePositionData() { return _titlePositionData; }
    PositionData& getTitlePositionDataDefault() { return _titlePositionDataDefault; }

    // text settings
    FontData& getTextFontData() { return _textFontData; }
    FontData& getTextFontDataDefault() { return _textFontDataDefault; }
    
    PositionData& getTextPositionData() { return _textPositionData; }
    PositionData& getTextPositionDataDefault() { return _textPositionDataDefault; }

    void translateTextCursor(const osg::Vec3& delta) { _textPositionData.position += delta; }

    // image settings
    PositionData& getImagePositionData() { return _imagePositionData; }
    PositionData& getImagePositionDataDefault() { return _imagePositionDataDefault; }

    // model settings
    PositionData& getModelPositionData() { return _modelPositionData; }
    PositionData& getModelPositionDataDefault() { return _modelPositionDataDefault; }


    void layerClickToDoOperation(Operation operation, bool relativeJump=true, int slideNum=0, int layerNum=0);
    void layerClickToDoOperation(const std::string& command, Operation operation, bool relativeJump=true, int slideNum=0, int layerNum=0);
    void layerClickEventOperation(const KeyPosition& keyPos, bool relativeJump=true, int slideNum=0, int layerNum=0);

    void addBullet(const std::string& bullet, PositionData& positionData, FontData& fontData);
    
    void addParagraph(const std::string& paragraph, PositionData& positionData, FontData& fontData);
    
    void addImage(const std::string& filename,const PositionData& positionData, const ImageData& imageData);

    void addStereoImagePair(const std::string& filenameLeft, const ImageData& imageDataLeft, const std::string& filenameRight,const ImageData& imageDataRight, const PositionData& positionData);

    void addVNC(const std::string& filename,const PositionData& positionData, const ImageData& imageData);
    void addBrowser(const std::string& filename,const PositionData& positionData, const ImageData& imageData);
    void addPDF(const std::string& filename,const PositionData& positionData, const ImageData& imageData);
    osg::Image* addInteractiveImage(const std::string& filename,const PositionData& positionData, const ImageData& imageData);

    void addModel(osg::Node* subgraph, const PositionData& positionData, const ModelData& modelData);

    void addModel(const std::string& filename, const PositionData& positionData, const ModelData& modelData);
    
    void addVolume(const std::string& filename, const PositionData& positionData);

    osg::Group* takePresentation() { return _root.release(); }
    
    osg::Group* getPresentation() { return _root.get(); }

    osg::Switch* getPresentationSwitch() { return _presentationSwitch.get(); }

    osg::Switch* getCurrentSlide() { return _slide.get(); }
    
    osg::Group* getCurrentLayer() { return _currentLayer.get(); }

    void setLoopPresentation(bool loop) { _loopPresentation = loop; }
    bool getLoopPresentation() const { return _loopPresentation; }

    void setAutoSteppingActive(bool flag = true) { _autoSteppingActive = flag; }
    bool getAutoSteppingActive() const { return _autoSteppingActive; }

protected:

    void findImageStreamsAndAddCallbacks(osg::Node* node);

    osg::Geometry* createTexturedQuadGeometry(const osg::Vec3& pos, const osg::Vec4& rotation, float width,float height, osg::Image* image, bool& usedTextureRectangle);

    osg::Vec3 computePositionInModelCoords(const PositionData& positionData) const;
    void updatePositionFromInModelCoords(const osg::Vec3& vertex, PositionData& positionData) const;
    
    osg::Vec3 convertSlideToModel(const osg::Vec3& position) const;
    osg::Vec3 convertModelToSlide(const osg::Vec3& position) const;

    osg::AnimationPathCallback* getAnimationPathCallback(const PositionData& positionData);
    
    osg::Node* attachMaterialAnimation(osg::Node* model, const PositionData& positionData);
    bool attachTexMat(osg::StateSet* stateset, const ImageData& imageData, float s, float t, bool textureRectangle);
    
    osg::StateSet* createTransformStateSet()
    {
        osg::StateSet* stateset = new osg::StateSet;
        stateset->setMode(GL_NORMALIZE,osg::StateAttribute::ON);
        return stateset;
    }

    osg::ref_ptr<const osgDB::ReaderWriter::Options> _options;

    osg::Vec3   _slideOrigin;
    osg::Vec3   _eyeOrigin;
    float       _slideWidth;
    float       _slideHeight;
    float       _slideDistance;

    // title settings
    FontData        _titleFontData;
    FontData        _titleFontDataDefault;

    PositionData    _titlePositionData;
    PositionData    _titlePositionDataDefault;

    // text settings
    FontData        _textFontData;
    FontData        _textFontDataDefault;
    
    PositionData    _textPositionData;
    PositionData    _textPositionDataDefault;

    // image settings
    PositionData    _imagePositionData;
    PositionData    _imagePositionDataDefault;

    // model settings
    PositionData    _modelPositionData;
    PositionData    _modelPositionDataDefault;


    bool        _loopPresentation;
    bool        _autoSteppingActive;
    osg::Vec4   _backgroundColor;
    std::string _presentationName;
    double      _presentationDuration;

    osg::ref_ptr<osg::Group>        _root;
    osg::ref_ptr<osg::Switch>       _presentationSwitch;
    
    osg::ref_ptr<osg::ClearNode>    _slideClearNode;
    osg::ref_ptr<osg::Switch>       _slide;
    std::string                     _slideTitle;
    std::string                     _slideBackgroundImageFileName;
    
    osg::ref_ptr<osg::Group>        _previousLayer;
    osg::ref_ptr<osg::Group>        _currentLayer;
    
    osg::ref_ptr<FilePathData>      _filePathData;
    
    std::string findFileAndRecordPath(const std::string& filename);
    
    void recordOptionsFilePath(const osgDB::Options* options);

};

}

#endif
