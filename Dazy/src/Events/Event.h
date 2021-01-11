#pragma once
#include "Core.h"

namespace Dazy
{

#define DECLARE_EVENT_NAME(type) const char* GetName() const { return #type; }\
								explicit operator std::string() const { return GetName();} 
	namespace Event
	{
		struct WindowResize
		{
			unsigned int width, height;
		};

		struct WindowClose
		{
		};

		struct AppTickEvent
		{
		};

		class AppUpdateEvent : public Event
		{
		public:
			AppUpdateEvent() = default;

			EVENT_CLASS_TYPE(AppUpdate)
				EVENT_CLASS_CATEGORY(EventCategoryApplication)
		};

		class AppRenderEvent : public Event
		{
		public:
			AppRenderEvent() = default;

			EVENT_CLASS_TYPE(AppRender)
				EVENT_CLASS_CATEGORY(EventCategoryApplication)
		};

	}


	/*enum class Event : entt::hashed_string::hash_type;
	using EventRegistry = entt::basic_registry<Event>;*/

	//using Event = entt::hashed_string;
	//using EventType = entt::hashed_string::hash_type;
	//using Event = entt::hashed_string::data;

	//class EventHandler
	//{
	//	//static Add();

	//private:
	//	static EventRegistry eventReg;
	//};

	/*class Event
	{
		using value_type = entt::basic_hashed_string<char>;

		Event(const char* eventName)
			: value(eventName) { }

		bool operator==(const Event& e) { return value == e.value; }

	private:
		value_type value;
	};*/
}
