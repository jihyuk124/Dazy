#pragma once
#include "Core.h"
#include "Graphics/Shader.h"

int main(int argc, char** argv);

namespace Dazy
{
	class Window;

	class Application
	{
	protected:
		Application(const char* name = "Dazy App");
	
	public:
		virtual ~Application();

		static Application* GetInstance();

		void Run();

	private:
		std::unique_ptr<Window> window;
		bool running = true;

		unsigned int vertexArray, vertexBuffer, indexBuffer;
		std::unique_ptr<Shader> shader;

		static Application* instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in client
	Application* CreateApplication();
}
