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

#include <OpenThreads/ReentrantMutex>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(OpenThreads::ReentrantMutex)
	I_DeclaringFile("OpenThreads/ReentrantMutex");
	I_BaseType(OpenThreads::Mutex);
	I_Constructor0(____ReentrantMutex,
	               "",
	               "");
	I_Method0(int, lock,
	          Properties::VIRTUAL,
	          __int__lock,
	          "Lock the mutex. ",
	          "0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, unlock,
	          Properties::VIRTUAL,
	          __int__unlock,
	          "Unlock the mutex. ",
	          "0 if normal, -1 if errno set, errno code otherwise. ");
	I_Method0(int, trylock,
	          Properties::VIRTUAL,
	          __int__trylock,
	          "Test if mutex can be locked. ",
	          "0 if normal, -1 if errno set, errno code otherwise. ");
END_REFLECTOR

