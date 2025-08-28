#pragma once

#include <span>
#include <glm/glm.hpp>

#include "DrawItem.h"

struct FrameData
{
    glm::mat4 viewProj;
    glm::vec4 cameraPos_and_exposure;   // xyz + w

    std::span<DrawItem> drawList;
    // glm::uvec2 lightsBaseCount;         // (0, count)
    // glm::uvec2 frameSize;               // (w,h)
    // glm::uvec2 invFrameSize;            // (1/w,1/h) * 1e6 np., albo trzymasz to w float w innym miejscu
    // uint64_t skyboxHandle;
    // uint64_t hdrHandle;               // combined
    // uint64_t shadow2DArrayHandle;     // combined
    // uint64_t shadowCubeHandle;        // combined
};