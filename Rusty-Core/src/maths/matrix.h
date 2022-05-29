#pragma once

namespace rusty::maths
{
	struct Matrix
	{
		//Properties
		float elements[16];

		//Constructors
		Matrix();
		Matrix(float diagonal);

		void multiply(const Matrix& matrix);

		static Matrix identity();
		static Matrix perspective(float fov, float aspectRatio, float near, float far);
		static Matrix orthographic(float left, float right, float bottom, float top, float near, float far);

		static Matrix translation(const Vector3& vector);
		static Matrix axisAngle(float angle, const Vector3& axis);
		static Matrix scale(const float scalar);
		static Matrix scale(const Vector3& scaleVector);
	};
}
