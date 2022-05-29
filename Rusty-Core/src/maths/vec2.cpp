#include "vec2.h"

rusty::maths::Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

rusty::maths::Vector2::Vector2(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
}

rusty::maths::Vector2& rusty::maths::Vector2::add(const Vector2& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	return *this;
}

rusty::maths::Vector2& rusty::maths::Vector2::sub(const Vector2& vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	return *this;
}

rusty::maths::Vector2& rusty::maths::Vector2::mul(const Vector2& vector)
{
	this->x *= vector.x;
	this->y *= vector.y;
	return *this;
}

rusty::maths::Vector2& rusty::maths::Vector2::div(const Vector2& vector)
{
	this->x /= vector.x;
	this->y /= vector.y;

	return *this;
}

rusty::maths::Vector2& rusty::maths::Vector2::mul(const int scale)
{
	this->x *= scale;
	this->y *= scale;

	return *this;
}

rusty::maths::Vector2& rusty::maths::Vector2::div(const int scale)
{
	this->x /= scale;
	this->y /= scale;

	return *this;
}

float rusty::maths::Vector2::magnitude() const
{
	//magnitude: sqrt(x^2 + y^2) or (x^2 + y^2)^0.5
	float result = sqrtf(powf(x, 2.0f) + powf(y, 2.0f));
	return result;
}

rusty::maths::Vector2& rusty::maths::Vector2::unit()
{
	//TODO: Account for negatives, too lazy to start
	return *this;
}

rusty::maths::Vector2& rusty::maths::Vector2::operator+(const Vector2& vector)
{
	return this->add(vector);
}

rusty::maths::Vector2& rusty::maths::Vector2::operator-(const Vector2& vector)
{
	return this->sub(vector);
}

std::ostream& rusty::maths::operator<<(std::ostream& stream, const Vector2& vector)
{
	stream << "Vector: [" << vector.x << ", " << vector.y << "]";
	return stream;
}
