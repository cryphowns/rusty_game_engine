#pragma once

namespace rusty::maths
{
	struct Vector4
	{
		//Properties
		float x;
		float y;
		float z;
		float w;

		//Methods
			//Constructors
		Vector4();
		Vector4(const float& x, const float& y, const float& z, const float& w);

		//Operators
		Vector4& add(const Vector4& vector);
		Vector4& sub(const Vector4& vector);
		Vector4& mul(const Vector4& vector);
		Vector4& div(const Vector4& vector);
	};
}