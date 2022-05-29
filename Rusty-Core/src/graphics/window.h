#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace rusty::graphics
{ 
	class Window
	{
	//Fields
	private:
		int m_width, m_height;
		const char* m_name;
		GLFWwindow* m_window;
		bool m_windowClosed;

		bool m_keys[1024];
		bool m_mouseButtons[32];
		double mouseX, mouseY;

	//Methods
	public:
		Window(const char* name, int width, int height);
		~Window();

		void render();
		void update();
		//Suffixing with const lets the compiler know this method is an accessor not a modifier
		bool windowClosed() const;
		bool isKeyPressed(unsigned int keycode);
			
	private:
		void init();
		static void resizeCallback(GLFWwindow* window, int width, int height);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
		static void mousePositionCallback(GLFWwindow* window, double xpos, double ypos);
	};
}
