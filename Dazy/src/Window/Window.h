#pragma once
#include <Core.h>
#include "entt.hpp"

struct GLFWwindow;

namespace Dazy
{
	struct WindowData
	{
		std::string title;
		uint32_t width;
		uint32_t height;
		bool VSync;

		WindowData(const std::string& title = "Dazy Engine",
			        uint32_t width = 1280,
			        uint32_t height = 720)
			: title(title), width(width), height(height), VSync(false)
		{
		}
	};

	// Interface representing a desktop system based Window
	class Window
	{
	public:
		template <typename ... Args>
		using EventCallbackFn = std::function<void(Args...)>;

		Window(const WindowData& data)
			: nativeWindow(nullptr), data(data) { }

		Window(const Window& other) = delete;
		Window(const Window&& other) = delete;
		Window& operator=(const Window& other) = delete;
		Window& operator=(const Window&& other) = delete;

		~Window() {};

		void Init();
		void DeInit();

		void OnUpdate();
		const bool IsCloseRequested() const;

		void SetVSync(const bool enabled);

		const WindowData& GetWindowData() const { return data; }

	private:
		GLFWwindow* nativeWindow;
		
		union
		{
			struct  
			{
				std::string title;
				uint32_t width;
				uint32_t height;
				bool VSync;
			};
			WindowData data;
		};
	};
}
