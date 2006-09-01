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

#include <osgDB/FileUtils>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< std::string >, osgDB::DirectoryContents);

BEGIN_ENUM_REFLECTOR(osgDB::CaseSensitivity)
	I_EnumLabel(osgDB::CASE_SENSITIVE);
	I_EnumLabel(osgDB::CASE_INSENSITIVE);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgDB::FileType)
	I_EnumLabel(osgDB::FILE_NOT_FOUND);
	I_EnumLabel(osgDB::REGULAR_FILE);
	I_EnumLabel(osgDB::DIRECTORY);
END_REFLECTOR

