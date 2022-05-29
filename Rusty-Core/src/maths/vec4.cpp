#include "vec4.h"

rusty::maths::Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

rusty::maths::Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

rusty::maths::Vector4& rusty::maths::Vector4::add(const Vector4& vector)
{
	return *this;
}
