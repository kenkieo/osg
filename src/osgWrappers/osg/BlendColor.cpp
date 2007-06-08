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

#include <osg/BlendColor>
#include <osg/CopyOp>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/Vec4>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::BlendColor)
	I_DeclaringFile("osg/BlendColor");
	I_BaseType(osg::StateAttribute);
	I_Constructor0(____BlendColor,
	               "",
	               "");
	I_Constructor1(IN, const osg::Vec4 &, constantColor,
	               Properties::NON_EXPLICIT,
	               ____BlendColor__C5_osg_Vec4_R1,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::BlendColor &, trans, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____BlendColor__C5_BlendColor_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an attribute, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an attribute, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "Return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "Return the name of the attribute's library. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "Return the name of the attribute's class type. ",
	          "");
	I_Method0(osg::StateAttribute::Type, getType,
	          Properties::VIRTUAL,
	          __Type__getType,
	          "Return the Type identifier of the attribute's class type. ",
	          "");
	I_Method1(int, compare, IN, const osg::StateAttribute &, sa,
	          Properties::VIRTUAL,
	          __int__compare__C5_StateAttribute_R1,
	          "Return -1 if *this < *rhs, 0 if *this==*rhs, 1 if *this>*rhs. ",
	          "");
	I_Method1(bool, getModeUsage, IN, osg::StateAttribute::ModeUsage &, usage,
	          Properties::VIRTUAL,
	          __bool__getModeUsage__StateAttribute_ModeUsage_R1,
	          "Return the modes associated with this StateAttribute. ",
	          "");
	I_Method1(void, setConstantColor, IN, const osg::Vec4 &, color,
	          Properties::NON_VIRTUAL,
	          __void__setConstantColor__C5_osg_Vec4_R1,
	          "",
	          "");
	I_Method0(osg::Vec4 &, getConstantColor,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4_R1__getConstantColor,
	          "",
	          "");
	I_Method0(const osg::Vec4 &, getConstantColor,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Vec4_R1__getConstantColor,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::State &, state,
	          Properties::VIRTUAL,
	          __void__apply__State_R1,
	          "apply the OpenGL state attributes. ",
	          "The render info for the current OpenGL context is passed in to allow the StateAttribute to obtain details on the the current context and state.");
	I_StaticMethod2(osg::BlendColor::Extensions *, getExtensions, IN, unsigned int, contextID, IN, bool, createIfNotInitalized,
	                __Extensions_P1__getExtensions__unsigned_int__bool_S,
	                "Returns the Extensions object for the given context. ",
	                "If createIfNotInitalized is true and the Exentsions object doesn't exist, getExtensions() creates it on the given context. Returns NULL if createIfNotInitalized is false and the Extensions object doesn't exist. ");
	I_StaticMethod2(void, setExtensions, IN, unsigned int, contextID, IN, osg::BlendColor::Extensions *, extensions,
	                __void__setExtensions__unsigned_int__Extensions_P1_S,
	                "setExtensions() allows users to override the extensions across graphics contexts. ",
	                "Typically used when you have different extensions supported across graphics pipes, but need to ensure that they all use the same low common denominator extensions. ");
	I_SimpleProperty(const osg::Vec4 &, ConstantColor, 
	                 __C5_osg_Vec4_R1__getConstantColor, 
	                 __void__setConstantColor__C5_osg_Vec4_R1);
	I_SimpleProperty(osg::StateAttribute::Type, Type, 
	                 __Type__getType, 
	                 0);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::BlendColor::Extensions)
	I_DeclaringFile("osg/BlendColor");
	I_BaseType(osg::Referenced);
	I_Constructor1(IN, unsigned int, contextID,
	               Properties::NON_EXPLICIT,
	               ____Extensions__unsigned_int,
	               "",
	               "");
	I_Constructor1(IN, const osg::BlendColor::Extensions &, rhs,
	               Properties::NON_EXPLICIT,
	               ____Extensions__C5_Extensions_R1,
	               "",
	               "");
	I_Method1(void, lowestCommonDenominator, IN, const osg::BlendColor::Extensions &, rhs,
	          Properties::NON_VIRTUAL,
	          __void__lowestCommonDenominator__C5_Extensions_R1,
	          "",
	          "");
	I_Method1(void, setupGLExtenions, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __void__setupGLExtenions__unsigned_int,
	          "",
	          "");
	I_Method1(void, setBlendColorSupported, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setBlendColorSupported__bool,
	          "",
	          "");
	I_Method0(bool, isBlendColorSupported,
	          Properties::NON_VIRTUAL,
	          __bool__isBlendColorSupported,
	          "",
	          "");
	I_Method1(void, setBlendColorProc, IN, void *, ptr,
	          Properties::NON_VIRTUAL,
	          __void__setBlendColorProc__void_P1,
	          "",
	          "");
	I_Method4(void, glBlendColor, IN, GLclampf, red, IN, GLclampf, green, IN, GLclampf, blue, IN, GLclampf, alpha,
	          Properties::NON_VIRTUAL,
	          __void__glBlendColor__GLclampf__GLclampf__GLclampf__GLclampf,
	          "",
	          "");
	I_SimpleProperty(void *, BlendColorProc, 
	                 0, 
	                 __void__setBlendColorProc__void_P1);
	I_SimpleProperty(bool, BlendColorSupported, 
	                 0, 
	                 __void__setBlendColorSupported__bool);
END_REFLECTOR

