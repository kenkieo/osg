// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/Billboard>
#include <osg/Drawable>
#include <osg/Geode>
#include <osg/Group>
#include <osg/LOD>
#include <osg/MatrixTransform>
#include <osg/Node>
#include <osg/Object>
#include <osg/ProxyNode>
#include <osg/StateAttribute>
#include <osg/StateSet>
#include <osg/Texture>
#include <osg/Transform>
#include <osgUtil/Optimizer>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osgUtil::BaseOptimizerVisitor)
	I_BaseType(osg::NodeVisitor);
	I_Constructor2(IN, osgUtil::Optimizer *, optimizer, IN, unsigned int, operation);
	I_Method1(bool, isOperationPermissibleForObject, IN, const osg::StateSet *, object);
	I_Method1(bool, isOperationPermissibleForObject, IN, const osg::StateAttribute *, object);
	I_Method1(bool, isOperationPermissibleForObject, IN, const osg::Drawable *, object);
	I_Method1(bool, isOperationPermissibleForObject, IN, const osg::Node *, object);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgUtil::Optimizer::OptimizationOptions)
	I_EnumLabel(osgUtil::Optimizer::FLATTEN_STATIC_TRANSFORMS);
	I_EnumLabel(osgUtil::Optimizer::REMOVE_REDUNDANT_NODES);
	I_EnumLabel(osgUtil::Optimizer::REMOVE_LOADED_PROXY_NODES);
	I_EnumLabel(osgUtil::Optimizer::COMBINE_ADJACENT_LODS);
	I_EnumLabel(osgUtil::Optimizer::SHARE_DUPLICATE_STATE);
	I_EnumLabel(osgUtil::Optimizer::MERGE_GEODES);
	I_EnumLabel(osgUtil::Optimizer::MERGE_GEOMETRY);
	I_EnumLabel(osgUtil::Optimizer::CHECK_GEOMETRY);
	I_EnumLabel(osgUtil::Optimizer::SPATIALIZE_GROUPS);
	I_EnumLabel(osgUtil::Optimizer::COPY_SHARED_NODES);
	I_EnumLabel(osgUtil::Optimizer::TRISTRIP_GEOMETRY);
	I_EnumLabel(osgUtil::Optimizer::TESSELATE_GEOMETRY);
	I_EnumLabel(osgUtil::Optimizer::OPTIMIZE_TEXTURE_SETTINGS);
	I_EnumLabel(osgUtil::Optimizer::FLATTEN_BILLBOARDS);
	I_EnumLabel(osgUtil::Optimizer::DEFAULT_OPTIMIZATIONS);
	I_EnumLabel(osgUtil::Optimizer::ALL_OPTIMIZATIONS);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgUtil::Optimizer)
	I_Constructor0();
	I_Method0(void, reset);
	I_Method1(void, optimize, IN, osg::Node *, node);
	I_Method2(void, optimize, IN, osg::Node *, node, IN, unsigned int, options);
	I_Method1(void, setIsOperationPermissibleForObjectCallback, IN, osgUtil::Optimizer::IsOperationPermissibleForObjectCallback *, callback);
	I_Method0(osgUtil::Optimizer::IsOperationPermissibleForObjectCallback *, getIsOperationPermissibleForObjectCallback);
	I_Method0(const osgUtil::Optimizer::IsOperationPermissibleForObjectCallback *, getIsOperationPermissibleForObjectCallback);
	I_Method2(void, setPermissibleOptimizationsForObject, IN, const osg::Object *, object, IN, unsigned int, options);
	I_Method1(unsigned int, getPermissibleOptimizationsForObject, IN, const osg::Object *, object);
	I_Method2(bool, isOperationPermissibleForObject, IN, const osg::StateSet *, object, IN, unsigned int, option);
	I_Method2(bool, isOperationPermissibleForObject, IN, const osg::StateAttribute *, object, IN, unsigned int, option);
	I_Method2(bool, isOperationPermissibleForObject, IN, const osg::Drawable *, object, IN, unsigned int, option);
	I_Method2(bool, isOperationPermissibleForObject, IN, const osg::Node *, object, IN, unsigned int, option);
	I_Method2(bool, isOperationPermissibleForObjectImplementation, IN, const osg::StateSet *, stateset, IN, unsigned int, option);
	I_Method2(bool, isOperationPermissibleForObjectImplementation, IN, const osg::StateAttribute *, attribute, IN, unsigned int, option);
	I_Method2(bool, isOperationPermissibleForObjectImplementation, IN, const osg::Drawable *, drawable, IN, unsigned int, option);
	I_Method2(bool, isOperationPermissibleForObjectImplementation, IN, const osg::Node *, node, IN, unsigned int, option);
	I_Property(osgUtil::Optimizer::IsOperationPermissibleForObjectCallback *, IsOperationPermissibleForObjectCallback);
	I_IndexedProperty1(unsigned int, PermissibleOptimizationsForObject, const osg::Object *, object);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::CheckGeometryVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Geode &, geode);
	I_Method1(void, checkGeode, IN, osg::Geode &, geode);
END_REFLECTOR

TYPE_NAME_ALIAS(std::set< osg::Group * >, osgUtil::Optimizer::CombineLODsVisitor::GroupList);

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::CombineLODsVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::LOD &, lod);
	I_Method0(void, combineLODs);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::CombineStaticTransformsVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::MatrixTransform &, transform);
	I_Method1(bool, removeTransforms, IN, osg::Node *, nodeWeCannotRemove);
END_REFLECTOR

TYPE_NAME_ALIAS(std::set< osg::Node * >, osgUtil::Optimizer::CopySharedSubgraphsVisitor::SharedNodeList);

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::CopySharedSubgraphsVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Node &, node);
	I_Method0(void, copySharedNodes);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osg::NodePath >, osgUtil::Optimizer::FlattenBillboardVisitor::NodePathList);

TYPE_NAME_ALIAS(std::map< osg::Billboard * COMMA  osgUtil::Optimizer::FlattenBillboardVisitor::NodePathList >, osgUtil::Optimizer::FlattenBillboardVisitor::BillboardNodePathMap);

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::FlattenBillboardVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method0(void, reset);
	I_Method1(void, apply, IN, osg::Billboard &, billboard);
	I_Method0(void, process);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::FlattenStaticTransformsVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Node &, geode);
	I_Method1(void, apply, IN, osg::Geode &, geode);
	I_Method1(void, apply, IN, osg::Billboard &, geode);
	I_Method1(void, apply, IN, osg::ProxyNode &, node);
	I_Method1(void, apply, IN, osg::Transform &, transform);
	I_Method1(bool, removeTransforms, IN, osg::Node *, nodeWeCannotRemove);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::IsOperationPermissibleForObjectCallback)
	I_BaseType(osg::Referenced);
	I_Constructor0();
	I_Method3(bool, isOperationPermissibleForObjectImplementation, IN, const osgUtil::Optimizer *, optimizer, IN, const osg::StateSet *, stateset, IN, unsigned int, option);
	I_Method3(bool, isOperationPermissibleForObjectImplementation, IN, const osgUtil::Optimizer *, optimizer, IN, const osg::StateAttribute *, attribute, IN, unsigned int, option);
	I_Method3(bool, isOperationPermissibleForObjectImplementation, IN, const osgUtil::Optimizer *, optimizer, IN, const osg::Drawable *, drawable, IN, unsigned int, option);
	I_Method3(bool, isOperationPermissibleForObjectImplementation, IN, const osgUtil::Optimizer *, optimizer, IN, const osg::Node *, node, IN, unsigned int, option);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::MergeGeodesVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Group &, group);
	I_Method1(bool, mergeGeodes, IN, osg::Group &, group);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::MergeGeometryVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, setTargetMaximumNumberOfVertices, IN, unsigned int, num);
	I_Method0(unsigned int, getTargetMaximumNumberOfVertices);
	I_Method1(void, apply, IN, osg::Geode &, geode);
	I_Method1(void, apply, IN, osg::Billboard &, x);
	I_Method1(bool, mergeGeode, IN, osg::Geode &, geode);
	I_Property(unsigned int, TargetMaximumNumberOfVertices);
END_REFLECTOR

TYPE_NAME_ALIAS(std::set< osg::Node * >, osgUtil::Optimizer::RemoveEmptyNodesVisitor::NodeList);

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::RemoveEmptyNodesVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Geode &, geode);
	I_Method1(void, apply, IN, osg::Group &, group);
	I_Method0(void, removeEmptyNodes);
END_REFLECTOR

TYPE_NAME_ALIAS(std::set< osg::Node * >, osgUtil::Optimizer::RemoveLoadedProxyNodesVisitor::NodeList);

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::RemoveLoadedProxyNodesVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::ProxyNode &, group);
	I_Method0(void, removeRedundantNodes);
END_REFLECTOR

TYPE_NAME_ALIAS(std::set< osg::Node * >, osgUtil::Optimizer::RemoveRedundantNodesVisitor::NodeList);

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::RemoveRedundantNodesVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Group &, group);
	I_Method1(void, apply, IN, osg::Transform &, transform);
	I_Method0(void, removeRedundantNodes);
END_REFLECTOR

TYPE_NAME_ALIAS(std::set< osg::Group * >, osgUtil::Optimizer::SpatializeGroupsVisitor::GroupsToDivideList);

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::SpatializeGroupsVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Group &, group);
	I_MethodWithDefaults1(bool, divide, IN, unsigned int, maxNumTreesPerCell, 8);
	I_Method2(bool, divide, IN, osg::Group *, group, IN, unsigned int, maxNumTreesPerCell);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::StateVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method0(void, reset);
	I_Method1(void, apply, IN, osg::Node &, node);
	I_Method1(void, apply, IN, osg::Geode &, geode);
	I_Method0(void, optimize);
END_REFLECTOR

TYPE_NAME_ALIAS(std::set< osg::Group * >, osgUtil::Optimizer::TesselateVisitor::GroupList);

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::TesselateVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults1(IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Geode &, geode);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Optimizer::TextureVisitor)
	I_BaseType(osgUtil::BaseOptimizerVisitor);
	I_ConstructorWithDefaults7(IN, bool, changeAutoUnRef, , IN, bool, valueAutoUnRef, , IN, bool, changeClientImageStorage, , IN, bool, valueClientImageStorage, , IN, bool, changeAnisotropy, , IN, float, valueAnisotropy, , IN, osgUtil::Optimizer *, optimizer, 0);
	I_Method1(void, apply, IN, osg::Geode &, node);
	I_Method1(void, apply, IN, osg::Node &, node);
	I_Method1(void, apply, IN, osg::StateSet &, stateset);
	I_Method1(void, apply, IN, osg::Texture &, texture);
END_REFLECTOR

STD_MAP_REFLECTOR(std::map< osg::Billboard * COMMA  osgUtil::Optimizer::FlattenBillboardVisitor::NodePathList >);

STD_SET_REFLECTOR(std::set< osg::Group * >);

STD_SET_REFLECTOR(std::set< osg::Node * >);

