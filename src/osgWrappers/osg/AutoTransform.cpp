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

#include <osg/AutoTransform>
#include <osg/BoundingSphere>
#include <osg/CopyOp>
#include <osg/Matrix>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/Quat>
#include <osg/Vec3>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osg::AutoTransform::AutoRotateMode)
	I_DeclaringFile("osg/AutoTransform");
	I_EnumLabel(osg::AutoTransform::NO_ROTATION);
	I_EnumLabel(osg::AutoTransform::ROTATE_TO_SCREEN);
	I_EnumLabel(osg::AutoTransform::ROTATE_TO_CAMERA);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::AutoTransform)
	I_DeclaringFile("osg/AutoTransform");
	I_BaseType(osg::Transform);
	I_Constructor0(____AutoTransform,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::AutoTransform &, pat, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____AutoTransform__C5_AutoTransform_R1__C5_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "clone an object of the same type as the node. ",
	          "");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "return a clone of a node, with Object* return type. ",
	          "");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the node's class type. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the node's library. ",
	          "");
	I_Method1(void, accept, IN, osg::NodeVisitor &, nv,
	          Properties::VIRTUAL,
	          __void__accept__NodeVisitor_R1,
	          "Visitor Pattern : calls the apply method of a NodeVisitor with this node's type. ",
	          "");
	I_Method0(osg::AutoTransform *, asAutoTransform,
	          Properties::VIRTUAL,
	          __AutoTransform_P1__asAutoTransform,
	          "",
	          "");
	I_Method0(const osg::AutoTransform *, asAutoTransform,
	          Properties::VIRTUAL,
	          __C5_AutoTransform_P1__asAutoTransform,
	          "",
	          "");
	I_Method1(void, setPosition, IN, const osg::Vec3 &, pos,
	          Properties::NON_VIRTUAL,
	          __void__setPosition__C5_Vec3_R1,
	          "",
	          "");
	I_Method0(const osg::Vec3 &, getPosition,
	          Properties::NON_VIRTUAL,
	          __C5_Vec3_R1__getPosition,
	          "",
	          "");
	I_Method1(void, setRotation, IN, const osg::Quat &, quat,
	          Properties::NON_VIRTUAL,
	          __void__setRotation__C5_Quat_R1,
	          "",
	          "");
	I_Method0(const osg::Quat &, getRotation,
	          Properties::NON_VIRTUAL,
	          __C5_Quat_R1__getRotation,
	          "",
	          "");
	I_Method1(void, setScale, IN, float, scale,
	          Properties::NON_VIRTUAL,
	          __void__setScale__float,
	          "",
	          "");
	I_Method1(void, setScale, IN, const osg::Vec3 &, scale,
	          Properties::NON_VIRTUAL,
	          __void__setScale__C5_Vec3_R1,
	          "",
	          "");
	I_Method0(const osg::Vec3 &, getScale,
	          Properties::NON_VIRTUAL,
	          __C5_Vec3_R1__getScale,
	          "",
	          "");
	I_Method1(void, setPivotPoint, IN, const osg::Vec3 &, pivot,
	          Properties::NON_VIRTUAL,
	          __void__setPivotPoint__C5_Vec3_R1,
	          "",
	          "");
	I_Method0(const osg::Vec3 &, getPivotPoint,
	          Properties::NON_VIRTUAL,
	          __C5_Vec3_R1__getPivotPoint,
	          "",
	          "");
	I_Method1(void, setAutoUpdateEyeMovementTolerance, IN, float, tolerance,
	          Properties::NON_VIRTUAL,
	          __void__setAutoUpdateEyeMovementTolerance__float,
	          "",
	          "");
	I_Method0(float, getAutoUpdateEyeMovementTolerance,
	          Properties::NON_VIRTUAL,
	          __float__getAutoUpdateEyeMovementTolerance,
	          "",
	          "");
	I_Method1(void, setAutoRotateMode, IN, osg::AutoTransform::AutoRotateMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setAutoRotateMode__AutoRotateMode,
	          "",
	          "");
	I_Method0(osg::AutoTransform::AutoRotateMode, getAutoRotateMode,
	          Properties::NON_VIRTUAL,
	          __AutoRotateMode__getAutoRotateMode,
	          "",
	          "");
	I_Method1(void, setAutoScaleToScreen, IN, bool, autoScaleToScreen,
	          Properties::NON_VIRTUAL,
	          __void__setAutoScaleToScreen__bool,
	          "",
	          "");
	I_Method0(bool, getAutoScaleToScreen,
	          Properties::NON_VIRTUAL,
	          __bool__getAutoScaleToScreen,
	          "",
	          "");
	I_Method2(bool, computeLocalToWorldMatrix, IN, osg::Matrix &, matrix, IN, osg::NodeVisitor *, nv,
	          Properties::VIRTUAL,
	          __bool__computeLocalToWorldMatrix__Matrix_R1__NodeVisitor_P1,
	          "",
	          "");
	I_Method2(bool, computeWorldToLocalMatrix, IN, osg::Matrix &, matrix, IN, osg::NodeVisitor *, nv,
	          Properties::VIRTUAL,
	          __bool__computeWorldToLocalMatrix__Matrix_R1__NodeVisitor_P1,
	          "",
	          "");
	I_Method0(osg::BoundingSphere, computeBound,
	          Properties::VIRTUAL,
	          __BoundingSphere__computeBound,
	          "Overrides Group's computeBound. ",
	          "There is no need to override in subclasses from osg::Transform since this computeBound() uses the underlying matrix (calling computeMatrix if required).");
	I_ProtectedMethod0(void, computeMatrix,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeMatrix,
	                   "",
	                   "");
	I_SimpleProperty(osg::AutoTransform::AutoRotateMode, AutoRotateMode, 
	                 __AutoRotateMode__getAutoRotateMode, 
	                 __void__setAutoRotateMode__AutoRotateMode);
	I_SimpleProperty(bool, AutoScaleToScreen, 
	                 __bool__getAutoScaleToScreen, 
	                 __void__setAutoScaleToScreen__bool);
	I_SimpleProperty(float, AutoUpdateEyeMovementTolerance, 
	                 __float__getAutoUpdateEyeMovementTolerance, 
	                 __void__setAutoUpdateEyeMovementTolerance__float);
	I_SimpleProperty(const osg::Vec3 &, PivotPoint, 
	                 __C5_Vec3_R1__getPivotPoint, 
	                 __void__setPivotPoint__C5_Vec3_R1);
	I_SimpleProperty(const osg::Vec3 &, Position, 
	                 __C5_Vec3_R1__getPosition, 
	                 __void__setPosition__C5_Vec3_R1);
	I_SimpleProperty(const osg::Quat &, Rotation, 
	                 __C5_Quat_R1__getRotation, 
	                 __void__setRotation__C5_Quat_R1);
	I_SimpleProperty(const osg::Vec3 &, Scale, 
	                 __C5_Vec3_R1__getScale, 
	                 __void__setScale__C5_Vec3_R1);
END_REFLECTOR

