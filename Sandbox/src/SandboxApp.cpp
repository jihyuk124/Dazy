#include "SandboxApp.h"

// entry point
#include "Core/EntryPoint.h"
Dazy::Application* Dazy::CreateApplication()
{
	return new Sandbox();
}

Sandbox::Sandbox()
{
	LOG_DEBUG("�̰��� {0}", "test");
}

Sandbox::~Sandbox()
{

}
