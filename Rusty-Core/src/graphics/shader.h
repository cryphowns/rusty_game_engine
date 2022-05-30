#pragma once
#include <vector>
#include <GL/glew.h>
#include <iostream>
#include "../utils/file_handler.h"
namespace rusty::graphics
{
	class Shader
	{
	private:
		GLuint m_shaderID;
		const char* m_vertPath;
		const char* m_fragPath;
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void enable() const;
		void disable() const;
	private: 
		GLuint m_load();
	};
}