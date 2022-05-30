#include "shader.h"

rusty::graphics::Shader::Shader(const char* vertPath, const char* fragPath)
	m_vertPath(vertPath), m_fragPath(fragPath)
{
	m_shaderID = m_load();
}

rusty::graphics::Shader::~Shader()
{
}

void rusty::graphics::Shader::enable() const
{
}

void rusty::graphics::Shader::disable() const
{
}

GLuint rusty::graphics::Shader::m_load()
{
	GLuint program = glCreateProgram();
	GLuint vertexShade = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShade = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vertSource = read_file(m_vertPath).c_str();
	const char* fragSource = read_file(m_fragPath).c_str();

	glShaderSource(vertexShade, 1, &vertSource, NULL);
	glCompileShader(vertexShade);

	GLint result;
	glGetShaderiv(vertexShade, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(vertexShade, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(vertexShade, length, &length, &error[0]);
		std::cout << &error[0] << std::endl;
		glDeleteShader(vertexShade);
	}
	return GLuint();
}
