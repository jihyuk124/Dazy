#pragma once

// Platform detect
#ifdef _WIN32
	#ifdef _WIN64
		#define _PLATFORM_WINDOWS
	#else
		#error "Windows X86 is not supported"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator not supported"
	#elif TARGET_OS_IPHONE == 1
		#define _PLATFORM_IOS
		#error "IOS is not supported"
	#elif TARGET_OS_MAC == 1
		#define _PLATFORM_MACOS
	#else
		#error "Unknown Apple platform"
	#endif
#elif defined(__ANDROID__)
	#define _PLATFORM_ANDROID
	#error "Android is not supported"
#elif defined(__linux__)
	#define _PLATFORM_LINUX
#else
	#error "Unknown platform"
#endif