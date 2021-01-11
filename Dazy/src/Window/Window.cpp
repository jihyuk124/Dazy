#include "Window.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Dazy
{
	static bool GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		LOG_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	void Window::Init()
	{
		if (!GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			ASSERT_MSG(success, "Could not intialize GLFW!");
		
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFWInitialized = true;
		}

		LOG_CORE_INFO("Creating window {0} ({1}, {2})", title, width, height);

		nativeWindow = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
		
		glfwMakeContextCurrent(nativeWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ASSERT_MSG(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(nativeWindow, &data);
		SetVSync(true);
		
		glfwSetWindowSizeCallback(nativeWindow, [](GLFWwindow* nativeWindow, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(nativeWindow);
			data.width = width;
			data.height = height;

			LOG_DEBUG("WindowResize : {0}, {1}", width, height);
		});

		/*glfwSetWindowCloseCallback(nativeWindow, [](GLFWwindow* nativeWindow)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(nativeWindow);
			LOG_DEBUG("WindowClose");
		});*/


		glfwSetKeyCallback(nativeWindow, [](GLFWwindow* nativeWindow, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(nativeWindow);
		
			switch (action)
			{
				case GLFW_PRESS:
				{
					LOG_DEBUG("KeyPress : KeyCode({0}), repeat(false)", key);
					break;
				}
				case GLFW_RELEASE:
				{
					LOG_DEBUG("KeyRelease : {0}", key);
					break;
				}
				case GLFW_REPEAT:
				{
					LOG_DEBUG("KeyPress : KeyCode({0}), repeat(true)", key);
					break;
				}
			}
		});
		

		glfwSetMouseButtonCallback(nativeWindow, [](GLFWwindow* nativeWindow, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(nativeWindow);
		
			switch (action)
			{
				case GLFW_PRESS:
				{
					LOG_DEBUG("MouseButtonPress : Button({0})", button);
					break;
				}
				case GLFW_RELEASE:
				{
					LOG_DEBUG("MouseButtonRelease : Button({0})", button);
					break;
				}
			}
		});

		glfwSetScrollCallback(nativeWindow, [](GLFWwindow* nativeWindow, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(nativeWindow);

			LOG_DEBUG("Scroll : XOffset({0}), YOffset{1}", xOffset, yOffset);
		});
		
		glfwSetCursorPosCallback(nativeWindow, [](GLFWwindow* nativeWindow, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(nativeWindow);
			LOG_DEBUG("CursorPos : XPos({0}), YPos{1}", xPos, yPos);
		});
	}

	void Window::DeInit()
	{
		glfwDestroyWindow(nativeWindow);
		glfwTerminate();
		LOG_DEBUG("Window terminated");
	}

	void Window::OnUpdate()
	{
		glfwSwapBuffers(nativeWindow);
		glfwPollEvents();
	}

	const bool Window::IsCloseRequested() const
	{
		return glfwWindowShouldClose(nativeWindow);
	}

	void Window::SetVSync(const bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.VSync = enabled;
	}
}
