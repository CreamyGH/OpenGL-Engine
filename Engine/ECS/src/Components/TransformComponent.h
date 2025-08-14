#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>

//TODO add static, dynamic, world matrix
//static - loaded from assimp
//dynamic - set by you
//world - final matrix


struct TransformComponent
{
    glm::mat4 matrix = glm::mat4(1.0f);

    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 scale = glm::vec3(1.0f);
    glm::quat quaternion = glm::quat(glm::vec3(0.0f));
};