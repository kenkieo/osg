// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/Node>
#include <osg/ObserverNodePath>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::ObserverNodePath)
	I_DeclaringFile("osg/ObserverNodePath");
	I_BaseType(osg::Observer);
	I_Constructor0(____ObserverNodePath,
	               "",
	               "");
	I_Constructor1(IN, const osg::ObserverNodePath &, rhs,
	               Properties::NON_EXPLICIT,
	               ____ObserverNodePath__C5_ObserverNodePath_R1,
	               "",
	               "");
	I_Constructor1(IN, const osg::NodePath &, nodePath,
	               Properties::NON_EXPLICIT,
	               ____ObserverNodePath__C5_osg_NodePath_R1,
	               "",
	               "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method1(void, setNodePath, IN, const osg::RefNodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __void__setNodePath__C5_osg_RefNodePath_R1,
	          "",
	          "");
	I_Method1(void, setNodePath, IN, const osg::NodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __void__setNodePath__C5_osg_NodePath_R1,
	          "",
	          "");
	I_Method0(void, clearNodePath,
	          Properties::NON_VIRTUAL,
	          __void__clearNodePath,
	          "",
	          "");
	I_Method1(bool, getRefNodePath, IN, osg::RefNodePath &, refNodePath,
	          Properties::NON_VIRTUAL,
	          __bool__getRefNodePath__RefNodePath_R1,
	          "Get a thread safe RefNodePath. ",
	          "");
	I_Method1(bool, getNodePath, IN, osg::NodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __bool__getNodePath__NodePath_R1,
	          "Get a lightweight NodePath that isn't thread safe but may be safely used in single threaded applications, or when its known that the NodePath won't be invalidated during usage of the NodePath. ",
	          "");
	I_ProtectedMethod1(void, _setNodePath, IN, const osg::NodePath &, nodePath,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___setNodePath__C5_osg_NodePath_R1,
	                   "",
	                   "");
	I_ProtectedMethod0(void, _clearNodePath,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void___clearNodePath,
	                   "",
	                   "");
	I_ProtectedMethod1(bool, objectUnreferenced, IN, void *, x,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__objectUnreferenced__void_P1,
	                   "objectUnreferenced(void*) is called when the observed object's referenced count goes to zero, indicating that the object will be deleted unless a new reference is made to it. ",
	                   "If you wish to prevent deletion of the object then it's reference count should be incremented such as via taking a ref_ptr<> to it, if no refernce is taken by any of the observers of the object then the object will be deleted, and objectDeleted will in turn be called. return true if the Observer wishes to removed from the oberseved objects observer set. ");
	I_SimpleProperty(const osg::RefNodePath &, NodePath, 
	                 0, 
	                 __void__setNodePath__C5_osg_RefNodePath_R1);
END_REFLECTOR

TYPE_NAME_ALIAS(std::list< osg::ref_ptr< osg::Node > >, osg::RefNodePath)

STD_LIST_REFLECTOR(std::list< osg::ref_ptr< osg::Node > >)

