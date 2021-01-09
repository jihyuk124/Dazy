//#include "Window.h"
//
//#ifdef _PLATFORM_WINDOWS
//#include "Platform/Windows/WindowsWindow.h"
//#endif
//
//namespace Dazy
//{
//	Scope<Window> Window::Create(const WindowProps& props)
//	{
//#ifdef _PLATFORM_WINDOWS
//		return CreateScope<WindowsWindow>(props);
//#else
//		DZ_ASSERT_MSG(false, "Unknown platform!");
//		return nullptr;
//#endif
//	}
//
//}
