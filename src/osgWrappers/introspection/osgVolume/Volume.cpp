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
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osgVolume/Volume>
#include <osgVolume/VolumeTechnique>
#include <osgVolume/VolumeTile>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/observer_ptr>
        
BEGIN_OBJECT_REFLECTOR(osgVolume::Volume)
	I_DeclaringFile("osgVolume/Volume");
	I_BaseType(osg::Group);
	I_Constructor0(____Volume,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgVolume::Volume &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____Volume__C5_Volume_R1__C5_osg_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
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
	          __void__accept__osg_NodeVisitor_R1,
	          "Visitor Pattern : calls the apply method of a NodeVisitor with this node's type. ",
	          "");
	I_Method1(void, traverse, IN, osg::NodeVisitor &, x,
	          Properties::VIRTUAL,
	          __void__traverse__osg_NodeVisitor_R1,
	          "Traverse downwards : calls children's accept method with NodeVisitor. ",
	          "");
	I_Method1(osgVolume::VolumeTile *, getVolumeTile, IN, const osgVolume::TileID &, tileID,
	          Properties::NON_VIRTUAL,
	          __VolumeTile_P1__getVolumeTile__C5_TileID_R1,
	          "Get the VolumeTile for a given VolumeTileID. ",
	          "");
	I_Method1(const osgVolume::VolumeTile *, getVolumeTile, IN, const osgVolume::TileID &, tileID,
	          Properties::NON_VIRTUAL,
	          __C5_VolumeTile_P1__getVolumeTile__C5_TileID_R1,
	          "Get the const VolumeTile for a given VolumeTileID. ",
	          "");
	I_Method1(void, setVolumeTechniquePrototype, IN, osgVolume::VolumeTechnique *, volumeTechnique,
	          Properties::NON_VIRTUAL,
	          __void__setVolumeTechniquePrototype__VolumeTechnique_P1,
	          "Set the VolumeTechnique prototype that nested VolumeTile should clone if they haven't already been assigned a volume rendering technique. ",
	          "");
	I_Method0(osgVolume::VolumeTechnique *, getVolumeTechniquePrototype,
	          Properties::NON_VIRTUAL,
	          __VolumeTechnique_P1__getVolumeTechniquePrototype,
	          "Get the VolumeTechnique prototype. ",
	          "");
	I_Method0(const osgVolume::VolumeTechnique *, getVolumeTechniquePrototype,
	          Properties::NON_VIRTUAL,
	          __C5_VolumeTechnique_P1__getVolumeTechniquePrototype,
	          "Get the const VolumeTechnique prototype. ",
	          "");
	I_ProtectedMethod0(void, dirtyRegisteredVolumeTiles,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__dirtyRegisteredVolumeTiles,
	                   "",
	                   "");
	I_ProtectedMethod1(void, registerVolumeTile, IN, osgVolume::VolumeTile *, tile,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__registerVolumeTile__VolumeTile_P1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, unregisterVolumeTile, IN, osgVolume::VolumeTile *, tile,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__unregisterVolumeTile__VolumeTile_P1,
	                   "",
	                   "");
	I_SimpleProperty(osgVolume::VolumeTechnique *, VolumeTechniquePrototype, 
	                 __VolumeTechnique_P1__getVolumeTechniquePrototype, 
	                 __void__setVolumeTechniquePrototype__VolumeTechnique_P1);
END_REFLECTOR

