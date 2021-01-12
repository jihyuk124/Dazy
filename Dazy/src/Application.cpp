#include "Application.h"
#include "Log.h"
#include "Window/Window.h"

#include <glad/glad.h>
#include "glm.hpp"

namespace Dazy
{
	Application* Application::instance = nullptr;

	Application::Application(const char* name)
	{
		window = std::unique_ptr<Window>(new Window(WindowData()));
		window->Init();
	}

	Application::~Application()
	{	
		window->DeInit();
	}

	Application* Application::GetInstance()
	{
		if (!Application::instance)
			Application::instance = CreateApplication();

		return Application::instance;
	}

	void Application::Run()
	{
		while (!window->IsCloseRequested())
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			window->OnUpdate();
		}
	}
}
