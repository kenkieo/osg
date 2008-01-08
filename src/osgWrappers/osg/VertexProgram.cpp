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
#include <osg/Matrix>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/Vec4>
#include <osg/VertexProgram>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::map< GLuint COMMA  osg::Vec4 >, osg::VertexProgram::LocalParamList)

TYPE_NAME_ALIAS(std::map< GLenum COMMA  osg::Matrix >, osg::VertexProgram::MatrixList)

BEGIN_OBJECT_REFLECTOR(osg::VertexProgram)
	I_DeclaringFile("osg/VertexProgram");
	I_BaseType(osg::StateAttribute);
	I_Constructor0(____VertexProgram,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::VertexProgram &, vp, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____VertexProgram__C5_VertexProgram_R1__C5_CopyOp_R1,
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
	          __int__compare__C5_osg_StateAttribute_R1,
	          "Return -1 if *this < *rhs, 0 if *this==*rhs, 1 if *this>*rhs. ",
	          "");
	I_Method1(bool, getModeUsage, IN, osg::StateAttribute::ModeUsage &, usage,
	          Properties::VIRTUAL,
	          __bool__getModeUsage__StateAttribute_ModeUsage_R1,
	          "Return the modes associated with this StateAttribute. ",
	          "");
	I_Method1(GLuint &, getVertexProgramID, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __GLuint_R1__getVertexProgramID__unsigned_int,
	          "Get the handle to the vertex program ID for the current context. ",
	          "");
	I_Method1(void, setVertexProgram, IN, const char *, program,
	          Properties::NON_VIRTUAL,
	          __void__setVertexProgram__C5_char_P1,
	          "Set the vertex program using a C style string. ",
	          "");
	I_Method1(void, setVertexProgram, IN, const std::string &, program,
	          Properties::NON_VIRTUAL,
	          __void__setVertexProgram__C5_std_string_R1,
	          "Set the vertex program using C++ style string. ",
	          "");
	I_Method0(const std::string &, getVertexProgram,
	          Properties::NON_VIRTUAL,
	          __C5_std_string_R1__getVertexProgram,
	          "Get the vertex program. ",
	          "");
	I_Method2(void, setProgramLocalParameter, IN, const GLuint, index, IN, const osg::Vec4 &, p,
	          Properties::NON_VIRTUAL,
	          __void__setProgramLocalParameter__C5_GLuint__C5_Vec4_R1,
	          "Set Program Parameters. ",
	          "");
	I_Method1(void, setLocalParameters, IN, const osg::VertexProgram::LocalParamList &, lpl,
	          Properties::NON_VIRTUAL,
	          __void__setLocalParameters__C5_LocalParamList_R1,
	          "Set list of Program Parameters. ",
	          "");
	I_Method0(osg::VertexProgram::LocalParamList &, getLocalParameters,
	          Properties::NON_VIRTUAL,
	          __LocalParamList_R1__getLocalParameters,
	          "Get list of Program Parameters. ",
	          "");
	I_Method0(const osg::VertexProgram::LocalParamList &, getLocalParameters,
	          Properties::NON_VIRTUAL,
	          __C5_LocalParamList_R1__getLocalParameters,
	          "Get const list of Program Parameters. ",
	          "");
	I_Method2(void, setMatrix, IN, const GLenum, mode, IN, const osg::Matrix &, matrix,
	          Properties::NON_VIRTUAL,
	          __void__setMatrix__C5_GLenum__C5_Matrix_R1,
	          "Matrix. ",
	          "");
	I_Method1(void, setMatrices, IN, const osg::VertexProgram::MatrixList &, matrices,
	          Properties::NON_VIRTUAL,
	          __void__setMatrices__C5_MatrixList_R1,
	          "Set list of Matrices. ",
	          "");
	I_Method0(osg::VertexProgram::MatrixList &, getMatrices,
	          Properties::NON_VIRTUAL,
	          __MatrixList_R1__getMatrices,
	          "Get list of Matrices. ",
	          "");
	I_Method0(const osg::VertexProgram::MatrixList &, getMatrices,
	          Properties::NON_VIRTUAL,
	          __C5_MatrixList_R1__getMatrices,
	          "Get list of Matrices. ",
	          "");
	I_Method0(void, dirtyVertexProgramObject,
	          Properties::NON_VIRTUAL,
	          __void__dirtyVertexProgramObject,
	          "Force a recompile on next apply() of associated OpenGL vertex program objects. ",
	          "");
	I_Method1(void, apply, IN, osg::State &, state,
	          Properties::VIRTUAL,
	          __void__apply__State_R1,
	          "apply the OpenGL state attributes. ",
	          "The render info for the current OpenGL context is passed in to allow the StateAttribute to obtain details on the the current context and state. ");
	I_Method1(void, compileGLObjects, IN, osg::State &, state,
	          Properties::VIRTUAL,
	          __void__compileGLObjects__State_R1,
	          "Default to nothing to compile - all state is applied immediately. ",
	          "");
	I_Method1(void, resizeGLObjectBuffers, IN, unsigned int, maxSize,
	          Properties::VIRTUAL,
	          __void__resizeGLObjectBuffers__unsigned_int,
	          "Resize any per context GLObject buffers to specified size. ",
	          "");
	I_MethodWithDefaults1(void, releaseGLObjects, IN, osg::State *, state, 0,
	                      Properties::VIRTUAL,
	                      __void__releaseGLObjects__State_P1,
	                      "Release any OpenGL objects in specified graphics context if State object is passed, otherwise release OpenGL objects for all graphics contexts if State object pointer is NULL. ",
	                      "");
	I_StaticMethod2(void, deleteVertexProgramObject, IN, unsigned int, contextID, IN, GLuint, handle,
	                __void__deleteVertexProgramObject__unsigned_int__GLuint_S,
	                "Use deleteVertexProgramObject instead of glDeletePrograms to allow OpenGL Vertex Program objects to cached until they can be deleted by the OpenGL context in which they were created, specified by contextID. ",
	                "");
	I_StaticMethod3(void, flushDeletedVertexProgramObjects, IN, unsigned int, contextID, IN, double, currentTime, IN, double &, availableTime,
	                __void__flushDeletedVertexProgramObjects__unsigned_int__double__double_R1_S,
	                "Flush all the cached vertex programs which need to be deleted in the OpenGL context related to contextID. ",
	                "");
	I_StaticMethod1(void, discardDeletedVertexProgramObjects, IN, unsigned int, contextID,
	                __void__discardDeletedVertexProgramObjects__unsigned_int_S,
	                "discard all the cached vertex programs which need to be deleted in the OpenGL context related to contextID. ",
	                "Note, unlike flush no OpenGL calls are made, instead the handles are all removed. this call is useful for when an OpenGL context has been destroyed. ");
	I_StaticMethod2(osg::VertexProgram::Extensions *, getExtensions, IN, unsigned int, contextID, IN, bool, createIfNotInitalized,
	                __Extensions_P1__getExtensions__unsigned_int__bool_S,
	                "Function to call to get the extension of a specified context. ",
	                "If the Extension object for that context has not yet been created and the 'createIfNotInitalized' flag been set to false then returns NULL. If 'createIfNotInitalized' is true then the Extensions object is automatically created. However, in this case the extension object will only be created with the graphics context associated with ContextID. ");
	I_StaticMethod2(void, setExtensions, IN, unsigned int, contextID, IN, osg::VertexProgram::Extensions *, extensions,
	                __void__setExtensions__unsigned_int__Extensions_P1_S,
	                "The setExtensions method allows users to override the extensions across graphics contexts. ",
	                "Typically used when you have different extensions supported across graphics pipes but need to ensure that they all use the same low common denominator extensions. ");
	I_SimpleProperty(const osg::VertexProgram::LocalParamList &, LocalParameters, 
	                 __C5_LocalParamList_R1__getLocalParameters, 
	                 __void__setLocalParameters__C5_LocalParamList_R1);
	I_SimpleProperty(const osg::VertexProgram::MatrixList &, Matrices, 
	                 __C5_MatrixList_R1__getMatrices, 
	                 __void__setMatrices__C5_MatrixList_R1);
	I_SimpleProperty(osg::StateAttribute::Type, Type, 
	                 __Type__getType, 
	                 0);
	I_SimpleProperty(const std::string &, VertexProgram, 
	                 __C5_std_string_R1__getVertexProgram, 
	                 __void__setVertexProgram__C5_std_string_R1);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::VertexProgram::Extensions)
	I_DeclaringFile("osg/VertexProgram");
	I_BaseType(osg::Referenced);
	I_Constructor1(IN, unsigned int, contextID,
	               Properties::NON_EXPLICIT,
	               ____Extensions__unsigned_int,
	               "",
	               "");
	I_Constructor1(IN, const osg::VertexProgram::Extensions &, rhs,
	               Properties::NON_EXPLICIT,
	               ____Extensions__C5_Extensions_R1,
	               "",
	               "");
	I_Method1(void, lowestCommonDenominator, IN, const osg::VertexProgram::Extensions &, rhs,
	          Properties::NON_VIRTUAL,
	          __void__lowestCommonDenominator__C5_Extensions_R1,
	          "",
	          "");
	I_Method1(void, setupGLExtensions, IN, unsigned int, contextID,
	          Properties::NON_VIRTUAL,
	          __void__setupGLExtensions__unsigned_int,
	          "",
	          "");
	I_Method1(void, setVertexProgramSupported, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setVertexProgramSupported__bool,
	          "",
	          "");
	I_Method0(bool, isVertexProgramSupported,
	          Properties::NON_VIRTUAL,
	          __bool__isVertexProgramSupported,
	          "",
	          "");
	I_Method2(void, glBindProgram, IN, GLenum, target, IN, GLuint, id,
	          Properties::NON_VIRTUAL,
	          __void__glBindProgram__GLenum__GLuint,
	          "",
	          "");
	I_Method2(void, glGenPrograms, IN, GLsizei, n, IN, GLuint *, programs,
	          Properties::NON_VIRTUAL,
	          __void__glGenPrograms__GLsizei__GLuint_P1,
	          "",
	          "");
	I_Method2(void, glDeletePrograms, IN, GLsizei, n, IN, GLuint *, programs,
	          Properties::NON_VIRTUAL,
	          __void__glDeletePrograms__GLsizei__GLuint_P1,
	          "",
	          "");
	I_Method4(void, glProgramString, IN, GLenum, target, IN, GLenum, format, IN, GLsizei, len, IN, const void *, string,
	          Properties::NON_VIRTUAL,
	          __void__glProgramString__GLenum__GLenum__GLsizei__C5_void_P1,
	          "",
	          "");
	I_Method3(void, glProgramLocalParameter4fv, IN, GLenum, target, IN, GLuint, index, IN, const GLfloat *, params,
	          Properties::NON_VIRTUAL,
	          __void__glProgramLocalParameter4fv__GLenum__GLuint__C5_GLfloat_P1,
	          "",
	          "");
	I_SimpleProperty(bool, VertexProgramSupported, 
	                 0, 
	                 __void__setVertexProgramSupported__bool);
END_REFLECTOR

