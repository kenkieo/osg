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

#include <osg/Billboard>
#include <osg/Geode>
#include <osg/Group>
#include <osg/LOD>
#include <osg/LightSource>
#include <osg/Node>
#include <osg/OccluderNode>
#include <osg/Projection>
#include <osg/Switch>
#include <osg/Transform>
#include <osgGA/EventQueue>
#include <osgGA/EventVisitor>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::list< osg::ref_ptr< osgGA::GUIEventAdapter > >, osgGA::EventVisitor::EventList);

BEGIN_OBJECT_REFLECTOR(osgGA::EventVisitor)
	I_BaseType(osg::NodeVisitor);
	I_Constructor0();
	I_Method1(void, setActionAdapter, IN, osgGA::GUIActionAdapter *, actionAdapter);
	I_Method0(osgGA::GUIActionAdapter *, getActionAdapter);
	I_Method0(const osgGA::GUIActionAdapter *, getActionAdapter);
	I_Method1(void, addEvent, IN, osgGA::GUIEventAdapter *, event);
	I_Method1(void, removeEvent, IN, osgGA::GUIEventAdapter *, event);
	I_Method1(void, setEventHandled, IN, bool, handled);
	I_Method0(bool, getEventHandled);
	I_Method1(void, setEvents, IN, const osgGA::EventQueue::Events &, events);
	I_Method0(osgGA::EventQueue::Events &, getEvents);
	I_Method0(const osgGA::EventQueue::Events &, getEvents);
	I_Method0(void, reset);
	I_Method1(void, apply, IN, osg::Node &, node);
	I_Method1(void, apply, IN, osg::Geode &, node);
	I_Method1(void, apply, IN, osg::Billboard &, node);
	I_Method1(void, apply, IN, osg::LightSource &, node);
	I_Method1(void, apply, IN, osg::Group &, node);
	I_Method1(void, apply, IN, osg::Transform &, node);
	I_Method1(void, apply, IN, osg::Projection &, node);
	I_Method1(void, apply, IN, osg::Switch &, node);
	I_Method1(void, apply, IN, osg::LOD &, node);
	I_Method1(void, apply, IN, osg::OccluderNode &, node);
	I_Property(osgGA::GUIActionAdapter *, ActionAdapter);
	I_Property(bool, EventHandled);
	I_Property(const osgGA::EventQueue::Events &, Events);
END_REFLECTOR

