#pragma once

namespace rusty::maths
{
	struct Vector3
	{
		//Properties
		float x;
		float y;
		float z;

		//Methods
			//Constructors
		Vector3();
		Vector3(const float& x, const float& y, const float& z);

		//Operators
		//Vector3& add(const Vector3& vector);
		//Vector3& sub(const Vector3& vector);
		//Vector3& mul(const Vector3& vector);
		//Vector3& div(const Vector3& vector);
	};
}