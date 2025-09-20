#include "GLTextureUploader.h"

TextureHandle GLTextureUploader::CreateTextureHandle(const std::vector<uint8_t> &pixelData, const TextureDesc &desc, const SamplerDesc &sampler, const TextureViewDesc &view)
{
    m_UploadedTextures[m_NextHandle] = std::make_unique<GLTextureGPU>();
    
    GLTextureGPU* texture = m_UploadedTextures[m_NextHandle].get();

    GenerateGLObjects(texture, desc.dimension);

    SetTexture(pixelData, desc, texture);
    SetSampler(sampler, texture);
    
    UpdateBindlessHandle(texture);

    m_NextHandle++;
    return m_NextHandle - 1;
}

void GLTextureUploader::UpdateTextureHandle(TextureHandle oldHandle, const std::vector<uint8_t> &pixelData, const TextureDesc &desc, const SamplerDesc &sampler, const TextureViewDesc &view)
{    
    GLTextureGPU* texture = m_UploadedTextures[oldHandle].get();

    SetTexture(pixelData, desc, texture);
    SetSampler(sampler, texture);
    
    ClearBindlessHandle(texture);
    UpdateBindlessHandle(texture);
}

void GLTextureUploader::ReleaseHandle(TextureHandle handle)
{
    LOG_ASSERT(m_UploadedTextures.contains(handle), "This texture handle doesn't exist");

    GLTextureGPU* texture = m_UploadedTextures[handle].get();

    ClearBindlessHandle(texture);
    DeleteGLObjects(texture);
    m_UploadedTextures.erase(handle);
}

void GLTextureUploader::GenerateGLObjects(GLTextureGPU* texture, TextureDimension dimension)
{
    const GLenum target = ToGLTarget(dimension);
    glCreateTextures(target, 1, &texture->id);

    glCreateSamplers(1, &texture->sampler);
}

void GLTextureUploader::DeleteGLObjects(GLTextureGPU *texture)
{
    glDeleteTextures(1, &texture->id);
    glDeleteSamplers(1, &texture->sampler);
}

void GLTextureUploader::UpdateBindlessHandle(GLTextureGPU *texture)
{
    const GLuint64 handle = glGetTextureSamplerHandleARB(texture->id, texture->sampler);
    glMakeTextureHandleResidentARB(handle);
    texture->bindlessHandle = handle;
}

void GLTextureUploader::ClearBindlessHandle(GLTextureGPU *texture)
{
    glMakeTextureHandleNonResidentARB(texture->bindlessHandle);
    texture->bindlessHandle = 0;
}

void GLTextureUploader::SetTexture(const std::vector<uint8_t> &pixelData, const TextureDesc &textureDesc, GLTextureGPU *texture)
{
    LOG_ASSERT(!pixelData.empty(), "Pixel data is empty!");

    const GLenum internalFmt = ToGLInternalFormat(textureDesc.format);

    GLenum uploadFmt = 0, uploadType = 0;
    ToGLUploadFormatType(textureDesc.format, uploadFmt, uploadType);


    switch (textureDesc.dimension) 
    {
        case TextureDimension::Tex2D:
            glTextureStorage2D(texture->id, textureDesc.mipLevels, internalFmt, textureDesc.width, textureDesc.height);
            break;

        case TextureDimension::Tex2DArray:
        case TextureDimension::Cube:
        case TextureDimension::CubeArray:
            // TODO: requires explicitly passing the number of layers; from TextureDesc.itself the depth doesn't always appear (Cube=6).
            glTextureStorage3D(texture->id, textureDesc.mipLevels, internalFmt, textureDesc.width, textureDesc.height,
                               (textureDesc.dimension==TextureDimension::Tex2DArray) ? textureDesc.depth :
                               (textureDesc.dimension==TextureDimension::Cube)      ? 6 :
                               (textureDesc.dimension==TextureDimension::CubeArray) ? textureDesc.depth*6 : 1);
            break;

        case TextureDimension::Tex3D:
            glTextureStorage3D(texture->id, textureDesc.mipLevels, internalFmt, textureDesc.width, textureDesc.height, textureDesc.depth);
            break;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    switch (textureDesc.dimension) 
    {
        case TextureDimension::Tex2D:
            glTextureSubImage2D(texture->id, 0, 0, 0, textureDesc.width, textureDesc.height,
                                uploadFmt, uploadType, pixelData.data());
        break;

        case TextureDimension::Tex2DArray:
        case TextureDimension::Cube:

        case TextureDimension::CubeArray:
            const GLsizei layers =
                (textureDesc.dimension==TextureDimension::Tex2DArray) ? textureDesc.depth :
                (textureDesc.dimension==TextureDimension::Cube)      ? 6 :
                (textureDesc.dimension==TextureDimension::CubeArray) ? textureDesc.depth*6 : 1;

            glTextureSubImage3D(texture->id, 0, 0, 0, 0,
                                textureDesc.width, textureDesc.height, layers,
                                uploadFmt, uploadType, pixelData.data());
        break;

        case TextureDimension::Tex3D:
            glTextureSubImage3D(texture->id, 0, 0, 0, 0,
                                    textureDesc.width, textureDesc.height, textureDesc.depth,
                                    uploadFmt, uploadType, pixelData.data());
        break;

        default:
            LOG_ASSERT(false, "Invalid texture dimension")
        break;
    }

    if (textureDesc.generateMips && textureDesc.mipLevels > 1) {
        glGenerateTextureMipmap(texture->id);
    }

    glTextureParameteri(texture->id, GL_TEXTURE_BASE_LEVEL, 0);
    glTextureParameteri(texture->id, GL_TEXTURE_MAX_LEVEL,  textureDesc.mipLevels - 1);
}

void GLTextureUploader::SetSampler(const SamplerDesc &sampler, GLTextureGPU *texture)
{
    const bool hasMips = GLHasMips(texture->id);

    glSamplerParameteri(texture->sampler, GL_TEXTURE_MIN_FILTER, PickGLMinFilter(sampler.minFilter, hasMips));
    glSamplerParameteri(texture->sampler, GL_TEXTURE_MAG_FILTER, PickGLMagFilter(sampler.magFilter));

    glSamplerParameteri(texture->sampler, GL_TEXTURE_WRAP_S, ToGLWrap(sampler.u));
    glSamplerParameteri(texture->sampler, GL_TEXTURE_WRAP_T, ToGLWrap(sampler.v));
    glSamplerParameteri(texture->sampler, GL_TEXTURE_WRAP_R, ToGLWrap(sampler.w));

    if (sampler.maxAniso > 1.0f) 
    {
        GLfloat maxAniso = 1.0f;
        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY ,&maxAniso);
        if (maxAniso > 0.0f) 
        {
            glSamplerParameterf(texture->sampler, GL_TEXTURE_MAX_ANISOTROPY,
                                (GLfloat)std::min(sampler.maxAniso, (float)maxAniso));
        }
    }

}

void GLTextureUploader::CleanAllTextures()
{
    for (auto& textures : m_UploadedTextures) 
    {
        GLTextureGPU* texture = textures.second.get();
        DeleteGLObjects(texture);
        ClearBindlessHandle(texture);
    }

    m_UploadedTextures.clear();
}

GLenum GLTextureUploader::ToGLInternalFormat(TextureFormat format)
{
    switch (format)
    {
        case TextureFormat::RGBA8_UNorm: return GL_RGBA8;
        case TextureFormat::RGBA8_sRGB:  return GL_SRGB8_ALPHA8;
        case TextureFormat::RG16F:       return GL_RG16F;
        case TextureFormat::RGBA16F:     return GL_RGBA16F;
        case TextureFormat::RGBA32F:     return GL_RGBA32F;
        case TextureFormat::D24S8:       return GL_DEPTH24_STENCIL8;
    }
    return GL_RGBA8;
}

void GLTextureUploader::ToGLUploadFormatType(TextureFormat f, GLenum &fmt, GLenum &type)
{
    switch (f)
    {
        case TextureFormat::RGBA8_UNorm:
        case TextureFormat::RGBA8_sRGB:
            fmt = GL_RGBA; type = GL_UNSIGNED_BYTE; return;
        case TextureFormat::RG16F:
            fmt = GL_RG;   type = GL_HALF_FLOAT;    return;
        case TextureFormat::RGBA16F:
            fmt = GL_RGBA; type = GL_HALF_FLOAT;    return;
        case TextureFormat::RGBA32F:
            fmt = GL_RGBA; type = GL_FLOAT;         return;
        case TextureFormat::D24S8:
            fmt = GL_DEPTH_STENCIL; type = GL_UNSIGNED_INT_24_8; return;
    }
}

GLenum GLTextureUploader::ToGLTarget(TextureDimension dimension)
{
    switch (dimension) 
    {
        case TextureDimension::Tex2D:      return GL_TEXTURE_2D;
        case TextureDimension::Tex2DArray: return GL_TEXTURE_2D_ARRAY;
        case TextureDimension::Cube:       return GL_TEXTURE_CUBE_MAP;
        case TextureDimension::CubeArray:  return GL_TEXTURE_CUBE_MAP_ARRAY;
        case TextureDimension::Tex3D:      return GL_TEXTURE_3D;
    }
    return GL_TEXTURE_2D;
}

GLenum GLTextureUploader::PickGLMinFilter(Filter filter, bool hasMips)
{
    switch (filter) 
    {
        case Filter::Nearest: return hasMips ? GL_NEAREST_MIPMAP_NEAREST : GL_NEAREST;
        case Filter::Linear:  return hasMips ? GL_LINEAR_MIPMAP_LINEAR   : GL_LINEAR;
        case Filter::Aniso:   return hasMips ? GL_LINEAR_MIPMAP_LINEAR   : GL_LINEAR;
    }
    return GL_LINEAR;
}

GLenum GLTextureUploader::PickGLMagFilter(Filter filter)
{
    switch (filter)
    {
        case Filter::Nearest: return GL_NEAREST;
        case Filter::Linear:
        case Filter::Aniso:   return GL_LINEAR;
    }
        return GL_LINEAR;
}

GLenum GLTextureUploader::ToGLWrap(Address adress)
{
    switch (adress) 
    {
        case Address::Repeat: return GL_REPEAT;
        case Address::Clamp:  return GL_CLAMP_TO_EDGE;
        case Address::Mirror: return GL_MIRRORED_REPEAT;
    }
    return GL_REPEAT;
}

bool GLTextureUploader::GLHasMips(GLuint tex)
{
    if (!tex) return false;

    GLint levels = 0;
    glGetTextureParameteriv(tex, GL_TEXTURE_IMMUTABLE_LEVELS, &levels);

    if (levels > 1) return true;

    GLint baseL = 0; 
    GLint maxL = 0;

    glGetTextureParameteriv(tex, GL_TEXTURE_BASE_LEVEL, &baseL);
    glGetTextureParameteriv(tex, GL_TEXTURE_MAX_LEVEL,  &maxL);

    return (maxL - baseL) >= 1;
}