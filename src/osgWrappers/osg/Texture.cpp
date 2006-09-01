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
#include <osg/GraphicsContext>
#include <osg/Image>
#include <osg/Object>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/Texture>
#include <osg/Vec4>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::list< osg::ref_ptr< osg::Texture::TextureObject > >, osg::Texture::TextureObjectList);

TYPE_NAME_ALIAS(osg::buffered_object< osg::Texture::TextureObjectList >, osg::Texture::TextureObjectListMap);

BEGIN_ENUM_REFLECTOR(osg::Texture::WrapParameter)
	I_EnumLabel(osg::Texture::WRAP_S);
	I_EnumLabel(osg::Texture::WRAP_T);
	I_EnumLabel(osg::Texture::WRAP_R);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Texture::WrapMode)
	I_EnumLabel(osg::Texture::CLAMP);
	I_EnumLabel(osg::Texture::CLAMP_TO_EDGE);
	I_EnumLabel(osg::Texture::CLAMP_TO_BORDER);
	I_EnumLabel(osg::Texture::REPEAT);
	I_EnumLabel(osg::Texture::MIRROR);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Texture::FilterParameter)
	I_EnumLabel(osg::Texture::MIN_FILTER);
	I_EnumLabel(osg::Texture::MAG_FILTER);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Texture::FilterMode)
	I_EnumLabel(osg::Texture::LINEAR);
	I_EnumLabel(osg::Texture::LINEAR_MIPMAP_LINEAR);
	I_EnumLabel(osg::Texture::LINEAR_MIPMAP_NEAREST);
	I_EnumLabel(osg::Texture::NEAREST);
	I_EnumLabel(osg::Texture::NEAREST_MIPMAP_LINEAR);
	I_EnumLabel(osg::Texture::NEAREST_MIPMAP_NEAREST);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Texture::InternalFormatMode)
	I_EnumLabel(osg::Texture::USE_IMAGE_DATA_FORMAT);
	I_EnumLabel(osg::Texture::USE_USER_DEFINED_FORMAT);
	I_EnumLabel(osg::Texture::USE_ARB_COMPRESSION);
	I_EnumLabel(osg::Texture::USE_S3TC_DXT1_COMPRESSION);
	I_EnumLabel(osg::Texture::USE_S3TC_DXT3_COMPRESSION);
	I_EnumLabel(osg::Texture::USE_S3TC_DXT5_COMPRESSION);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Texture::ShadowCompareFunc)
	I_EnumLabel(osg::Texture::LEQUAL);
	I_EnumLabel(osg::Texture::GEQUAL);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::Texture::ShadowTextureMode)
	I_EnumLabel(osg::Texture::LUMINANCE);
	I_EnumLabel(osg::Texture::INTENSITY);
	I_EnumLabel(osg::Texture::ALPHA);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::Texture)
	I_BaseType(osg::StateAttribute);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, const osg::Texture &, text, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method0(osg::StateAttribute::Type, getType);
	I_Method0(bool, isTextureAttribute);
	I_Method0(GLenum, getTextureTarget);
	I_Method1(bool, getModeUsage, IN, osg::StateAttribute::ModeUsage &, usage);
	I_Method0(int, getTextureWidth);
	I_Method0(int, getTextureHeight);
	I_Method0(int, getTextureDepth);
	I_Method2(void, setWrap, IN, osg::Texture::WrapParameter, which, IN, osg::Texture::WrapMode, wrap);
	I_Method1(osg::Texture::WrapMode, getWrap, IN, osg::Texture::WrapParameter, which);
	I_Method1(void, setBorderColor, IN, const osg::Vec4 &, color);
	I_Method0(const osg::Vec4 &, getBorderColor);
	I_Method1(void, setBorderWidth, IN, GLint, width);
	I_Method0(GLint, getBorderWidth);
	I_Method2(void, setFilter, IN, osg::Texture::FilterParameter, which, IN, osg::Texture::FilterMode, filter);
	I_Method1(osg::Texture::FilterMode, getFilter, IN, osg::Texture::FilterParameter, which);
	I_Method1(void, setMaxAnisotropy, IN, float, anis);
	I_Method0(float, getMaxAnisotropy);
	I_Method1(void, setUseHardwareMipMapGeneration, IN, bool, useHardwareMipMapGeneration);
	I_Method0(bool, getUseHardwareMipMapGeneration);
	I_Method1(void, setUnRefImageDataAfterApply, IN, bool, flag);
	I_Method0(bool, getUnRefImageDataAfterApply);
	I_Method1(void, setClientStorageHint, IN, bool, flag);
	I_Method0(bool, getClientStorageHint);
	I_Method1(void, setResizeNonPowerOfTwoHint, IN, bool, flag);
	I_Method0(bool, getResizeNonPowerOfTwoHint);
	I_Method1(void, setInternalFormatMode, IN, osg::Texture::InternalFormatMode, mode);
	I_Method0(osg::Texture::InternalFormatMode, getInternalFormatMode);
	I_Method1(void, setInternalFormat, IN, GLint, internalFormat);
	I_Method0(GLint, getInternalFormat);
	I_Method0(bool, isCompressedInternalFormat);
	I_Method1(void, setSourceFormat, IN, GLenum, sourceFormat);
	I_Method0(GLenum, getSourceFormat);
	I_Method1(void, setSourceType, IN, GLenum, sourceType);
	I_Method0(GLenum, getSourceType);
	I_Method1(osg::Texture::TextureObject *, getTextureObject, IN, unsigned int, contextID);
	I_Method0(void, dirtyTextureObject);
	I_Method0(bool, areAllTextureObjectsLoaded);
	I_Method1(unsigned int &, getTextureParameterDirty, IN, unsigned int, contextID);
	I_Method0(void, dirtyTextureParameters);
	I_Method1(void, setShadowComparison, IN, bool, flag);
	I_Method1(void, setShadowCompareFunc, IN, osg::Texture::ShadowCompareFunc, func);
	I_Method0(osg::Texture::ShadowCompareFunc, getShadowCompareFunc);
	I_Method1(void, setShadowTextureMode, IN, osg::Texture::ShadowTextureMode, mode);
	I_Method0(osg::Texture::ShadowTextureMode, getShadowTextureMode);
	I_Method1(void, setShadowAmbient, IN, float, shadow_ambient);
	I_Method0(float, getShadowAmbient);
	I_Method2(void, setImage, IN, unsigned int, face, IN, osg::Image *, image);
	I_Method1(osg::Image *, getImage, IN, unsigned int, face);
	I_Method1(const osg::Image *, getImage, IN, unsigned int, face);
	I_Method0(unsigned int, getNumImages);
	I_Method1(void, setReadPBuffer, IN, osg::GraphicsContext *, context);
	I_Method0(osg::GraphicsContext *, getReadPBuffer);
	I_Method0(const osg::GraphicsContext *, getReadPBuffer);
	I_Method1(void, apply, IN, osg::State &, state);
	I_Method1(void, compileGLObjects, IN, osg::State &, state);
	I_MethodWithDefaults1(void, releaseGLObjects, IN, osg::State *, state, 0);
	I_Method6(void, applyTexImage2D_load, IN, osg::State &, state, IN, GLenum, target, IN, const osg::Image *, image, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, numMipmapLevels);
	I_Method7(void, applyTexImage2D_subload, IN, osg::State &, state, IN, GLenum, target, IN, const osg::Image *, image, IN, GLsizei, width, IN, GLsizei, height, IN, GLint, inInternalFormat, IN, GLsizei, numMipmapLevels);
	I_Method1(void, takeTextureObjects, IN, osg::Texture::TextureObjectListMap &, toblm);
	I_StaticMethod2(osg::Texture::Extensions *, getExtensions, IN, unsigned int, contextID, IN, bool, createIfNotInitalized);
	I_StaticMethod2(void, setExtensions, IN, unsigned int, contextID, IN, osg::Texture::Extensions *, extensions);
	I_StaticMethod1(bool, isCompressedInternalFormat, IN, GLint, internalFormat);
	I_StaticMethod6(void, getCompressedSize, IN, GLenum, internalFormat, IN, GLint, width, IN, GLint, height, IN, GLint, depth, IN, GLint &, blockSize, IN, GLint &, size);
	I_StaticMethod2(osg::Texture::TextureObject *, generateTextureObject, IN, unsigned int, contextID, IN, GLenum, target);
	I_StaticMethod8(osg::Texture::TextureObject *, generateTextureObject, IN, unsigned int, contextID, IN, GLenum, target, IN, GLint, numMipmapLevels, IN, GLenum, internalFormat, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, depth, IN, GLint, border);
	I_StaticMethod1(void, setMinimumNumberOfTextureObjectsToRetainInCache, IN, unsigned int, minimum);
	I_StaticMethod0(unsigned int, getMinimumNumberOfTextureObjectsToRetainInCache);
	I_StaticMethod1(void, flushAllDeletedTextureObjects, IN, unsigned int, contextID);
	I_StaticMethod3(void, flushDeletedTextureObjects, IN, unsigned int, contextID, IN, double, currentTime, IN, double &, availableTime);
	I_Property(const osg::Vec4 &, BorderColor);
	I_Property(GLint, BorderWidth);
	I_Property(bool, ClientStorageHint);
	I_IndexedProperty1(osg::Texture::FilterMode, Filter, osg::Texture::FilterParameter, which);
	I_ArrayProperty_G(osg::Image *, Image, Images, unsigned int, void);
	I_Property(GLint, InternalFormat);
	I_Property(osg::Texture::InternalFormatMode, InternalFormatMode);
	I_Property(float, MaxAnisotropy);
	I_Property(osg::GraphicsContext *, ReadPBuffer);
	I_Property(bool, ResizeNonPowerOfTwoHint);
	I_Property(float, ShadowAmbient);
	I_Property(osg::Texture::ShadowCompareFunc, ShadowCompareFunc);
	I_WriteOnlyProperty(bool, ShadowComparison);
	I_Property(osg::Texture::ShadowTextureMode, ShadowTextureMode);
	I_Property(GLenum, SourceFormat);
	I_Property(GLenum, SourceType);
	I_ReadOnlyProperty(int, TextureDepth);
	I_ReadOnlyProperty(int, TextureHeight);
	I_ReadOnlyProperty(GLenum, TextureTarget);
	I_ReadOnlyProperty(int, TextureWidth);
	I_ReadOnlyProperty(osg::StateAttribute::Type, Type);
	I_Property(bool, UnRefImageDataAfterApply);
	I_Property(bool, UseHardwareMipMapGeneration);
	I_IndexedProperty1(osg::Texture::WrapMode, Wrap, osg::Texture::WrapParameter, which);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::Texture::Extensions)
	I_BaseType(osg::Referenced);
	I_Constructor1(IN, unsigned int, contextID);
	I_Constructor1(IN, const osg::Texture::Extensions &, rhs);
	I_Method1(void, lowestCommonDenominator, IN, const osg::Texture::Extensions &, rhs);
	I_Method1(void, setupGLExtensions, IN, unsigned int, contextID);
	I_Method1(void, setMultiTexturingSupported, IN, bool, flag);
	I_Method0(bool, isMultiTexturingSupported);
	I_Method1(void, setTextureFilterAnisotropicSupported, IN, bool, flag);
	I_Method0(bool, isTextureFilterAnisotropicSupported);
	I_Method1(void, setTextureCompressionARBSupported, IN, bool, flag);
	I_Method0(bool, isTextureCompressionARBSupported);
	I_Method1(void, setTextureCompressionS3TCSupported, IN, bool, flag);
	I_Method0(bool, isTextureCompressionS3TCSupported);
	I_Method1(void, setTextureMirroredRepeatSupported, IN, bool, flag);
	I_Method0(bool, isTextureMirroredRepeatSupported);
	I_Method1(void, setTextureEdgeClampSupported, IN, bool, flag);
	I_Method0(bool, isTextureEdgeClampSupported);
	I_Method1(void, setTextureBorderClampSupported, IN, bool, flag);
	I_Method0(bool, isTextureBorderClampSupported);
	I_Method1(void, setGenerateMipMapSupported, IN, bool, flag);
	I_Method0(bool, isGenerateMipMapSupported);
	I_Method1(void, setShadowSupported, IN, bool, flag);
	I_Method0(bool, isShadowSupported);
	I_Method1(void, setShadowAmbientSupported, IN, bool, flag);
	I_Method0(bool, isShadowAmbientSupported);
	I_Method1(void, setMaxTextureSize, IN, GLint, maxsize);
	I_Method0(GLint, maxTextureSize);
	I_Method1(void, setNumTextureUnits, IN, GLint, nunits);
	I_Method0(GLint, numTextureUnits);
	I_Method0(bool, isCompressedTexImage2DSupported);
	I_Method1(void, setCompressedTexImage2DProc, IN, void *, ptr);
	I_Method8(void, glCompressedTexImage2D, IN, GLenum, target, IN, GLint, level, IN, GLenum, internalformat, IN, GLsizei, width, IN, GLsizei, height, IN, GLint, border, IN, GLsizei, imageSize, IN, const GLvoid *, data);
	I_Method1(void, setCompressedTexSubImage2DProc, IN, void *, ptr);
	I_Method9(void, glCompressedTexSubImage2D, IN, GLenum, target, IN, GLint, level, IN, GLint, xoffset, IN, GLint, yoffset, IN, GLsizei, width, IN, GLsizei, height, IN, GLenum, format, IN, GLsizei, type, IN, const GLvoid *, data);
	I_Method1(void, setGetCompressedTexImageProc, IN, void *, ptr);
	I_Method3(void, glGetCompressedTexImage, IN, GLenum, target, IN, GLint, level, IN, GLvoid *, data);
	I_Method0(bool, isClientStorageSupported);
	I_Method1(bool, isNonPowerOfTwoTextureSupported, IN, GLenum, filter);
	I_WriteOnlyProperty(void *, CompressedTexImage2DProc);
	I_WriteOnlyProperty(void *, CompressedTexSubImage2DProc);
	I_WriteOnlyProperty(bool, GenerateMipMapSupported);
	I_WriteOnlyProperty(void *, GetCompressedTexImageProc);
	I_WriteOnlyProperty(GLint, MaxTextureSize);
	I_WriteOnlyProperty(bool, MultiTexturingSupported);
	I_WriteOnlyProperty(GLint, NumTextureUnits);
	I_WriteOnlyProperty(bool, ShadowAmbientSupported);
	I_WriteOnlyProperty(bool, ShadowSupported);
	I_WriteOnlyProperty(bool, TextureBorderClampSupported);
	I_WriteOnlyProperty(bool, TextureCompressionARBSupported);
	I_WriteOnlyProperty(bool, TextureCompressionS3TCSupported);
	I_WriteOnlyProperty(bool, TextureEdgeClampSupported);
	I_WriteOnlyProperty(bool, TextureFilterAnisotropicSupported);
	I_WriteOnlyProperty(bool, TextureMirroredRepeatSupported);
	I_WriteOnlyProperty(unsigned int, upGLExtensions);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::Texture::TextureObject)
	I_BaseType(osg::Referenced);
	I_Constructor2(IN, GLuint, id, IN, GLenum, target);
	I_Constructor8(IN, GLuint, id, IN, GLenum, target, IN, GLint, numMipmapLevels, IN, GLenum, internalFormat, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, depth, IN, GLint, border);
	I_Method7(bool, match, IN, GLenum, target, IN, GLint, numMipmapLevels, IN, GLenum, internalFormat, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, depth, IN, GLint, border);
	I_Method0(void, bind);
	I_MethodWithDefaults1(void, setAllocated, IN, bool, allocated, true);
	I_Method6(void, setAllocated, IN, GLint, numMipmapLevels, IN, GLenum, internalFormat, IN, GLsizei, width, IN, GLsizei, height, IN, GLsizei, depth, IN, GLint, border);
	I_Method0(bool, isAllocated);
	I_Method0(bool, isReusable);
	I_WriteOnlyProperty(bool, Allocated);
	I_PublicMemberProperty(GLuint, _id);
	I_PublicMemberProperty(GLenum, _target);
	I_PublicMemberProperty(GLint, _numMipmapLevels);
	I_PublicMemberProperty(GLenum, _internalFormat);
	I_PublicMemberProperty(GLsizei, _width);
	I_PublicMemberProperty(GLsizei, _height);
	I_PublicMemberProperty(GLsizei, _depth);
	I_PublicMemberProperty(GLint, _border);
	I_PublicMemberProperty(bool, _allocated);
	I_PublicMemberProperty(double, _timeStamp);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::buffered_object< osg::Texture::TextureObjectList >)
	I_Constructor0();
	I_Constructor1(IN, unsigned int, size);
	I_Method1(void, setAllElementsTo, IN, const osg::Texture::TextureObjectList &, t);
	I_Method0(void, clear);
	I_Method0(bool, empty);
	I_Method0(unsigned int, size);
	I_WriteOnlyProperty(const osg::Texture::TextureObjectList &, AllElementsTo);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osg::Texture::TextureObject >)
	I_Constructor0();
	I_Constructor1(IN, osg::Texture::TextureObject *, ptr);
	I_Constructor1(IN, const osg::ref_ptr< osg::Texture::TextureObject > &, rp);
	I_Method0(osg::Texture::TextureObject *, get);
	I_Method0(bool, valid);
	I_Method0(osg::Texture::TextureObject *, release);
	I_Method1(void, swap, IN, osg::ref_ptr< osg::Texture::TextureObject > &, rp);
	I_ReadOnlyProperty(osg::Texture::TextureObject *, );
END_REFLECTOR

STD_LIST_REFLECTOR(std::list< osg::ref_ptr< osg::Texture::TextureObject > >);

