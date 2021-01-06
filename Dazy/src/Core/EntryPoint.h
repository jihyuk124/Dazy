#pragma once
#include "Core.h"
#include "Application.h"

#ifdef _PLATFORM_WINDOWS
extern Dazy::Application* Dazy::CreateApplication();

int main(int argc, char** argv)
{
	Dazy::Logger::Init();

	auto app = Dazy::CreateApplication();
	app->Run();
	delete app;
}
#endif
