return function()
	warnings "Off"

	includedirs
	{
		"ThirdParty/glfw/include"
	}

	files
	{
		"ThirdParty/glfw/include/GLFW/glfw3.h",
		"ThirdParty/glfw/include/GLFW/glfw3native.h",
		"ThirdParty/glfw/src/glfw_config.h",
		"ThirdParty/glfw/src/context.c",
		"ThirdParty/glfw/src/init.c",
		"ThirdParty/glfw/src/input.c",
		"ThirdParty/glfw/src/monitor.c",
		"ThirdParty/glfw/src/vulkan.c",
		"ThirdParty/glfw/src/window.c"
	}

	filter "system:windows"
		files
		{
			"ThirdParty/glfw/src/win32_init.c",
			"ThirdParty/glfw/src/win32_monitor.c",
			"ThirdParty/glfw/src/win32_time.c",
			"ThirdParty/glfw/src/win32_thread.c",
			"ThirdParty/glfw/src/win32_window.c",
			"ThirdParty/glfw/src/wgl_context.c",
			"ThirdParty/glfw/src/egl_context.c",
			"ThirdParty/glfw/src/osmesa_context.c"
		}

		defines
		{
			"_GLFW_WIN32"
		}


		links("opengl32.lib")

	filter "system:linux"
		files
		{
			"ThirdParty/glfw/src/x11_init.c",
			"ThirdParty/glfw/src/x11_monitor.c",
			"ThirdParty/glfw/src/x11_window.c",
			"ThirdParty/glfw/src/xkb_unicode.c",
			"ThirdParty/glfw/src/posix_time.c",
			"ThirdParty/glfw/src/posix_thread.c",
			"ThirdParty/glfw/src/glx_context.c",
			"ThirdParty/glfw/src/egl_context.c",
			"ThirdParty/glfw/src/osmesa_context.c",
			"ThirdParty/glfw/src/linux_joystick.c"
		}

		defines
		{
			"_GLFW_X11"
		}

	filter { }
end