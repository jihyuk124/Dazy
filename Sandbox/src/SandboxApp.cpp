#include "SandboxApp.h"

// entry point
#include "EntryPoint.h"

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
