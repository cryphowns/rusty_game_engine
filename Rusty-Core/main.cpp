#include <iostream>
#include "src/graphics/window.h"
#include "src/maths/maths.h"
#include "src/maths/matrix.h"

using namespace rusty::maths;

int main()
{
	rusty::graphics::Window window("Test Window", 800, 600);
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Matrix myMatrix = Matrix::translation(Vector3(3.0f, 4.0f, 1.0f));

	for (int i = 0; i < 16; i++)
	{
		if (i > 0 && i % 4 == 0)
		{
			std::cout << std::endl;
		}
		std::cout << myMatrix.elements[i] << " ";
	}

	while (!window.windowClosed())
	{
		window.render();
		glDrawArrays(GL_ARRAY_BUFFER, vao, 6);
		window.update();
	}

	window.~Window();

	system("PAUSE");
	return 0;
}