#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

#include "binding.h"
#include <sphere.h>

namespace Engine
{
namespace GPUData
{
struct CamParams
{
    CamParams() = default;
    CamParams(const glm::mat4& view,
              const glm::mat4& projection,
              const glm::vec3& eye);
    glm::vec4 eye;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
};

struct SphereInfo
{
    SphereInfo() = default;
    SphereInfo(const Primitive::Sphere& sphere);
    unsigned int numVertices;
    unsigned int numIndices;
    unsigned int isNormalized; // bool
    float sh0Threshold;
};

struct GridInfo
{
    GridInfo() = default;
    GridInfo(const glm::ivec4& dims);
    glm::ivec4 gridDims;
    glm::ivec4 sliceIndex;
    glm::ivec4 isSliceDirty;
};

class ShaderData
{
public:
    ShaderData();
    ShaderData(void* data, BindableProperty binding, size_t sizeofT);
    ShaderData(void* data, BindableProperty binding, size_t sizeofT, GLenum usage);
    void ModifySubData(GLintptr offset, GLsizeiptr size, const void* data);
    void ToGPU();
private:
    GLuint mSSBO = 0;
    BindableProperty mBinding;
    bool isDirty = true;
    void* mData;
};
} // namespace GPUData
} // namespace Engine
