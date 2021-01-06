#pragma once
#include "PlatformDetection.h"
#include "Log.h"

// debug break
#ifdef _DEBUG
	#if defined(_PLATFORM_WINDOWS)
		#define DEBUGBREAK() __debugbreak()
	#elif defined(_PLATFORM_LINUX)
		#include <signal.h>
		#define DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif

	#define _ENABLE_ASSERTS
#else
	#define DEBUGBREAK()
#endif

#ifdef _ENABLE_ASSERTS
	#define ASSERT(expr) assert(expr)
	#define ASSERT_MSG(expr, msg) assert((expr)&&(msg))
#else
	#define ASSERT(expr) ((void)0)
	#define ASSERT_MSG(expr, msg) ((void)0)
#endif