#pragma once

#include <glm/glm.hpp>

struct CameraComponent
{
	glm::vec3 position = glm::vec3(0.0f);
	glm::mat4 viewProj = glm::mat4(1.0f);

	float rollAngle = 0.0f;
	float pitchAngle = 0.0f;
	float yawAngle = -90.0f;
	float FOV = 45.0f;

	float nearPlane = 0.1f;
	float farPlane = 100.0f;
};