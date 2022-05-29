#pragma once
#include <iostream>

namespace rusty::maths
{
	struct Vector2
	{
		//Properties
		float x;
		float y;

		//Methods
			//Constructors
		Vector2();
		Vector2(const float& x, const float& y);

			//Operators
			//Oerations that take vector values
		Vector2& add(const Vector2& vector);
		Vector2& sub(const Vector2& vector);
		Vector2& mul(const Vector2& vector);
		Vector2& div(const Vector2& vector);
			//Operations that take scalar values
		Vector2& mul(const int scale);
		Vector2& div(const int scale);
		

			//Getters
		float magnitude() const;
		Vector2& unit();
		Vector2& operator+ (const Vector2& vector);
		Vector2& operator- (const Vector2& vector);
		friend std::ostream& operator<< (std::ostream& stream, const Vector2& vector);
		
	};
}
