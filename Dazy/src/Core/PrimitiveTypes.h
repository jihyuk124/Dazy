#pragma once

using uint8 =	unsigned char;
using uint16 =	unsigned short int;
using uint32 =	unsigned int;
using uint64 =	unsigned long long;

using int8 =	signed char;
using int16 =	signed short int;
using int32 =	signed int;
using int64 =	signed long long;

static_assert(sizeof(int8) == 1, "int8 size must be 1 bytes.");
static_assert(sizeof(int16) == 2, "int16 size must be 2 bytes.");
static_assert(sizeof(int32) == 4, "int32 size must be 4 bytes.");
static_assert(sizeof(int64) == 8, "int64 size must be 8 bytes.");

using wchar =	wchar_t;
// using tchar =	wchar;

/*
// An 8-bit unicode character type. In-memory only. 8-bit representation. (since C++20)
using char8 =	char8_t;

// A 16-bit unicode character type. In-memory only.
using char16 =	char16_t;

// A 32-bit unicode character type. In-memory only. 32-bit representation.
using char32 =	char32_t;
*/
