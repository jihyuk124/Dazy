#pragma once

int main(int argc, char** argv);

namespace Dazy
{
	class Application
	{
	public:
		Application(const char* name = "Dazy App");
		virtual ~Application();

	private:
		void Run();
		friend int ::main(int argc, char** argv);
	};

	// To be defined in client
	Application* CreateApplication();
}