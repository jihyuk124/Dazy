#pragma once
#include "Core.h"
#include "Application.h"

#ifdef _PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	Dazy::Logger::Init();

	auto app = Dazy::Application::GetInstance();
	app->Run();
	delete app;
}
#endif
