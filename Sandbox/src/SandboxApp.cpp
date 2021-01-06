#include "SandboxApp.h"

// entry point
#include "Core/EntryPoint.h"

Dazy::Application* Dazy::CreateApplication()
{
	return new Sandbox();
}

Sandbox::Sandbox()
{
	
}

Sandbox::~Sandbox()
{

}
