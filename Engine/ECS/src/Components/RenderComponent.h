#pragma once

#include <stdint.h>

struct RenderComponent
{
	uint32_t meshID;
	uint32_t materialID;
	bool isVisible;
};