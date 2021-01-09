#pragma once
#include "Core.h"
#include "Window/Window.h"

struct GLFWwindow;

namespace Dazy
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return data.width; }
		unsigned int GetHeight() const override { return data.height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callbackFn) override { data.eventCallback = callbackFn; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool VSync;

			EventCallbackFn eventCallback;
		};

		WindowData data;
	};

}
