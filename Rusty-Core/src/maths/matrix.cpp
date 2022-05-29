#include "maths.h"

using namespace rusty::maths;

/*
	element in a matrix is given by the formula: row + column * width =
	this remains true for column major ordering
*/

rusty::maths::Matrix::Matrix()
{
	//memset(this->elements, 0.0f, 16);
	for (int i = 0; i < 16; i++)
		elements[i] = 0.0f;
}

rusty::maths::Matrix::Matrix(float diagonal)
{
	for (int i = 0; i < 16; i++)
		elements[i] = 0.0f;

	elements[0 + 0 * 4] = diagonal;
	elements[1 + 1 * 4] = diagonal;
	elements[2 + 2 * 4] = diagonal;
	elements[3 + 3 * 4] = diagonal;


}

void rusty::maths::Matrix::multiply(const Matrix& matrix)
{
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			float sum = 0;
			for (int element = 0; element < 4; element++)
			{
				sum += elements[column + element * 4] * matrix.elements[element + row * 4];
			}
			elements[column + row * 4] = sum;
		}
	}
}

Matrix rusty::maths::Matrix::identity()
{
	return Matrix(1.0f);
}

Matrix rusty::maths::Matrix::perspective(float fov, float aspectRatio, float near, float far)
{
	//Returns the mapped values projected onto a perspective plane
	Matrix _matrix = Matrix();

	_matrix.elements[0 + 0 * 4] = 1.0f / (aspectRatio * tan(degreesToRadians(fov/2.0f)));
	_matrix.elements[1 + 1 * 4] = 1.0f / (tan(degreesToRadians(fov/2.0f)));
	_matrix.elements[2 + 2 * 4] = -(far + near) / (far - near);
	_matrix.elements[2 + 3 * 4] = -(2.0f * far * near) / (far - near);
	_matrix.elements[3 + 2 * 4] = -1.0f;

	return _matrix;
}

Matrix rusty::maths::Matrix::orthographic(float left, float right, float bottom, float top, float near, float far)
{
	//Returns the mapped values projected onto an orthographic plane
	Matrix _matrix = Matrix();
	_matrix.elements[0 + 0 * 4] = 2.0f / (right - left);
	_matrix.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	_matrix.elements[2 + 2 * 4] = -2.0f / (far - near);
	

	_matrix.elements[0 + 3 * 4] = -(right + left) / (right - left);
	_matrix.elements[1 + 3 * 4] = -(top + bottom) / (top - bottom);
	_matrix.elements[2 + 3 * 4] = -(far + near) / (far - near);
	_matrix.elements[3 + 3 * 4] = 1.0f;

	return _matrix;
}

Matrix rusty::maths::Matrix::translation(const Vector3& vector)
{
	Matrix _matrix = Matrix(1.0f);
	_matrix.elements[0 + 3 * 4] = vector.x;
	_matrix.elements[1 + 3 * 4] = vector.y;
	_matrix.elements[2 + 3 * 4] = vector.z;
	
	return _matrix;
}

Matrix rusty::maths::Matrix::axisAngle(float angle, const Vector3& axis)
{
	//Rotation about any arbitrary axis
	Matrix _matrix = Matrix(1.0f);
	angle = degreesToRadians(angle);
		
	float _cos = cos(angle);
	float _sin = sin(angle);

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;
	
	_matrix.elements[0 + 0 * 4] = x * (1 - _cos) + _cos;
	_matrix.elements[1 + 0 * 4] = y * x * (1 - _cos) + z * _sin;
	_matrix.elements[2 + 0 * 4] = x * z * (1 - _cos) - y * _sin;

	_matrix.elements[0 + 1 * 4] = x * y * (1 - _cos) - z * _sin;
	_matrix.elements[1 + 1 * 4] = y * (1 - _cos) + _cos;
	_matrix.elements[2 + 1 * 4] = y * z * (1 - _cos) + x * _sin;

	_matrix.elements[0 + 2 * 4] = x * z * (1 - _cos) + y * _sin;
	_matrix.elements[1 + 2 * 4] = y * z * (1 - _cos) - x * _sin;
	_matrix.elements[2 + 2 * 4] = z * (1 - _cos) + _cos;

	return _matrix;
}

Matrix rusty::maths::Matrix::scale(const float scalar)
{
	Matrix _matrix = Matrix(scalar);
	_matrix.elements[3 + 3 * 4] = 0.0f;
	return _matrix;
}

Matrix rusty::maths::Matrix::scale(const Vector3& scaleVector)
{
	Matrix _matrix = Matrix(1.0f);

	_matrix.elements[0 + 0 * 4] = scaleVector.x;
	_matrix.elements[1 + 1 * 4] = scaleVector.y;
	_matrix.elements[2 + 2 * 4] = scaleVector.z;

	return _matrix;
}
