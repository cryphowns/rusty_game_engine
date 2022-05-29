#include "vec3.h"

rusty::maths::Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

rusty::maths::Vector3::Vector3(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
