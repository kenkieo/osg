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

#include <osg/Referenced>
#include <osg/RenderInfo>
#include <osg/State>
#include <osg/View>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_VALUE_REFLECTOR(osg::RenderInfo)
	I_DeclaringFile("osg/RenderInfo");
	I_Constructor0(____RenderInfo,
	               "",
	               "");
	I_Constructor1(IN, const osg::RenderInfo &, rhs,
	               Properties::NON_EXPLICIT,
	               ____RenderInfo__C5_RenderInfo_R1,
	               "",
	               "");
	I_Constructor2(IN, osg::State *, state, IN, osg::View *, view,
	               ____RenderInfo__State_P1__View_P1,
	               "",
	               "");
	I_Method0(unsigned int, getContextID,
	          Properties::NON_VIRTUAL,
	          __unsigned_int__getContextID,
	          "",
	          "");
	I_Method1(void, setState, IN, osg::State *, state,
	          Properties::NON_VIRTUAL,
	          __void__setState__State_P1,
	          "",
	          "");
	I_Method0(osg::State *, getState,
	          Properties::NON_VIRTUAL,
	          __State_P1__getState,
	          "",
	          "");
	I_Method0(const osg::State *, getState,
	          Properties::NON_VIRTUAL,
	          __C5_State_P1__getState,
	          "",
	          "");
	I_Method1(void, setView, IN, osg::View *, view,
	          Properties::NON_VIRTUAL,
	          __void__setView__View_P1,
	          "",
	          "");
	I_Method0(osg::View *, getView,
	          Properties::NON_VIRTUAL,
	          __View_P1__getView,
	          "",
	          "");
	I_Method0(const osg::View *, getView,
	          Properties::NON_VIRTUAL,
	          __C5_View_P1__getView,
	          "",
	          "");
	I_Method1(void, setUserData, IN, osg::Referenced *, userData,
	          Properties::NON_VIRTUAL,
	          __void__setUserData__Referenced_P1,
	          "",
	          "");
	I_Method0(osg::Referenced *, getUserData,
	          Properties::NON_VIRTUAL,
	          __Referenced_P1__getUserData,
	          "",
	          "");
	I_Method0(const osg::Referenced *, getUserData,
	          Properties::NON_VIRTUAL,
	          __C5_Referenced_P1__getUserData,
	          "",
	          "");
	I_SimpleProperty(unsigned int, ContextID, 
	                 __unsigned_int__getContextID, 
	                 0);
	I_SimpleProperty(osg::State *, State, 
	                 __State_P1__getState, 
	                 __void__setState__State_P1);
	I_SimpleProperty(osg::Referenced *, UserData, 
	                 __Referenced_P1__getUserData, 
	                 __void__setUserData__Referenced_P1);
	I_SimpleProperty(osg::View *, View, 
	                 __View_P1__getView, 
	                 __void__setView__View_P1);
END_REFLECTOR

