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

		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		unsigned int indices[3] = { 0, 1, 2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
			glClearColor(0.1, 0.1, 0.1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			glBindVertexArray(vertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

			window->OnUpdate();
		}
	}
}
