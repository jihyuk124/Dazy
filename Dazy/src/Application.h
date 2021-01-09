#pragma once
#include "Core.h"

int main(int argc, char** argv);

namespace Dazy
{
	class Window;
	class WindowCloseEvent;
	class Event;

	class Application
	{
	public:
		Application(const char* name = "Dazy App");
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> window;
		bool running = true;

		friend int ::main(int argc, char** argv);
	};

	// To be defined in client
	Application* CreateApplication();
}
