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
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/TexEnv>
#include <osg/Vec4>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osg::TexEnv::Mode)
	I_EnumLabel(osg::TexEnv::DECAL);
	I_EnumLabel(osg::TexEnv::MODULATE);
	I_EnumLabel(osg::TexEnv::BLEND);
	I_EnumLabel(osg::TexEnv::REPLACE);
	I_EnumLabel(osg::TexEnv::ADD);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::TexEnv)
	I_BaseType(osg::StateAttribute);
	I_ConstructorWithDefaults1(IN, osg::TexEnv::Mode, mode, osg::TexEnv::MODULATE);
	I_ConstructorWithDefaults2(IN, const osg::TexEnv &, texenv, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(osg::StateAttribute::Type, getType);
	I_Method0(bool, isTextureAttribute);
	I_Method1(int, compare, IN, const osg::StateAttribute &, sa);
	I_Method1(void, setMode, IN, osg::TexEnv::Mode, mode);
	I_Method0(osg::TexEnv::Mode, getMode);
	I_Method1(void, setColor, IN, const osg::Vec4 &, color);
	I_Method0(osg::Vec4 &, getColor);
	I_Method0(const osg::Vec4 &, getColor);
	I_Method1(void, apply, IN, osg::State &, state);
	I_Property(const osg::Vec4 &, Color);
	I_Property(osg::TexEnv::Mode, Mode);
	I_ReadOnlyProperty(osg::StateAttribute::Type, Type);
END_REFLECTOR

