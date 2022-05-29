#include "window.h"
#include <iostream>

rusty::graphics::Window::Window(const char* name, int width, int height)
{
	m_name = name;
	m_height = height;
	m_width = width;
	init();

	for (int i = 0; i < 1024; i++)
	{
		m_keys[i] = false;
	}

	for (int i = 0; i < 32; i++)
	{
		m_mouseButtons[i] = false;
	}
}

rusty::graphics::Window::~Window()
{
	glfwTerminate();
}

void rusty::graphics::Window::render()
{
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}

void rusty::graphics::Window::update()
{
	glfwPollEvents();
	//glfwGetFramebufferSize(m_window, &m_width, &m_height);
	
	glfwSwapBuffers(m_window);
}

bool rusty::graphics::Window::windowClosed() const
{
	return glfwWindowShouldClose(m_window);
}

bool rusty::graphics::Window::isKeyPressed(unsigned int keycode)
{
	if (keycode > 1024)
	{
		return false;
	}
	return m_keys[keycode];
}

void rusty::graphics::Window::init()
{
	//Initialize GLFW Library, throw error if fails
	if (!glfwInit())
	{
		std::cout << "Error initializing GLFW, program will terminate\a" << std::endl;
		this->~Window();
	}

	//Initialize and setup window
	m_window = glfwCreateWindow(m_width, m_height, m_name, NULL, NULL);
	if (!m_window)
	{
		std::cout << "Failed to initialize window!\a" << std::endl;
		this->~Window();
	}
	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, this);
	glfwSetWindowSizeCallback(m_window, resizeCallback);
	glfwSetKeyCallback(m_window, keyCallback);
	glfwSetMouseButtonCallback(m_window, mouseCallback);
	if (glfwRawMouseMotionSupported())
		glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
	glfwSetCursorPosCallback(m_window, mousePositionCallback);

	std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

	//Initialize GLEW Library
	if (!(glewInit() == GLEW_OK))
	{
		std::cout << "Error initializing GLEW, program will terminate\a" << std::endl;
		this->~Window();
	}
}

void rusty::graphics::Window::resizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void rusty::graphics::Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* windowObject = (Window*) glfwGetWindowUserPointer(window);
	if (action != GLFW_RELEASE)
	{
		windowObject->m_keys[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		windowObject->m_keys[key] = false;
	}
}

void rusty::graphics::Window::mouseCallback(GLFWwindow* window, int button, int action, int mods)
{
	Window* windowObject = (Window*)glfwGetWindowUserPointer(window);
	if (action != GLFW_RELEASE)
	{
		windowObject->m_mouseButtons[button] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		windowObject->m_mouseButtons[button] = false;
	}
}

void rusty::graphics::Window::mousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	Window* windowObject = (Window*) glfwGetWindowUserPointer(window);
	windowObject->mouseX = xpos;
	windowObject->mouseY = ypos;
}
