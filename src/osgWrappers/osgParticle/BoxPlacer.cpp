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

#include <osg/CopyOp>
#include <osg/Object>
#include <osg/Vec3>
#include <osgParticle/BoxPlacer>
#include <osgParticle/Particle>
#include <osgParticle/range>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgParticle::BoxPlacer)
	I_DeclaringFile("osgParticle/BoxPlacer");
	I_BaseType(osgParticle::CenteredPlacer);
	I_Constructor0(____BoxPlacer,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgParticle::BoxPlacer &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____BoxPlacer__C5_BoxPlacer_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(const osgParticle::rangef &, getXRange,
	          Properties::NON_VIRTUAL,
	          __C5_rangef_R1__getXRange,
	          "Get the range of possible values for radius. ",
	          "");
	I_Method1(void, setXRange, IN, const osgParticle::rangef &, r,
	          Properties::NON_VIRTUAL,
	          __void__setXRange__C5_rangef_R1,
	          "Set the range of possible values for radius. ",
	          "");
	I_Method2(void, setXRange, IN, float, r1, IN, float, r2,
	          Properties::NON_VIRTUAL,
	          __void__setXRange__float__float,
	          "Set the range of possible values for radius. ",
	          "");
	I_Method0(const osgParticle::rangef &, getYRange,
	          Properties::NON_VIRTUAL,
	          __C5_rangef_R1__getYRange,
	          "Get the range of possible values for the central angle. ",
	          "");
	I_Method1(void, setYRange, IN, const osgParticle::rangef &, r,
	          Properties::NON_VIRTUAL,
	          __void__setYRange__C5_rangef_R1,
	          "Set the range of possible values for the central angle. ",
	          "");
	I_Method2(void, setYRange, IN, float, r1, IN, float, r2,
	          Properties::NON_VIRTUAL,
	          __void__setYRange__float__float,
	          "Set the range of possible values for the central angle. ",
	          "");
	I_Method0(const osgParticle::rangef &, getZRange,
	          Properties::NON_VIRTUAL,
	          __C5_rangef_R1__getZRange,
	          "Get the range of possible values for the height. ",
	          "");
	I_Method1(void, setZRange, IN, const osgParticle::rangef &, r,
	          Properties::NON_VIRTUAL,
	          __void__setZRange__C5_rangef_R1,
	          "Set the range of possible values for the height. ",
	          "");
	I_Method2(void, setZRange, IN, float, r1, IN, float, r2,
	          Properties::NON_VIRTUAL,
	          __void__setZRange__float__float,
	          "Set the range of possible values for the height. ",
	          "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, place, IN, osgParticle::Particle *, P,
	          Properties::VIRTUAL,
	          __void__place__Particle_P1,
	          "Place a particle. Do not call it manually. ",
	          "");
	I_Method0(osg::Vec3, getControlPosition,
	          Properties::VIRTUAL,
	          __osg_Vec3__getControlPosition,
	          "return the control position ",
	          "");
	I_SimpleProperty(osg::Vec3, ControlPosition, 
	                 __osg_Vec3__getControlPosition, 
	                 0);
	I_SimpleProperty(const osgParticle::rangef &, XRange, 
	                 __C5_rangef_R1__getXRange, 
	                 __void__setXRange__C5_rangef_R1);
	I_SimpleProperty(const osgParticle::rangef &, YRange, 
	                 __C5_rangef_R1__getYRange, 
	                 __void__setYRange__C5_rangef_R1);
	I_SimpleProperty(const osgParticle::rangef &, ZRange, 
	                 __C5_rangef_R1__getZRange, 
	                 __void__setZRange__C5_rangef_R1);
END_REFLECTOR

