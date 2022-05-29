#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace rusty::maths {
	inline float degreesToRadians(float value)
	{
		return (value * M_PI / 180);
	}
}
