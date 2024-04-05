#pragma once

#include <stdint.h>

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef int8_t I8;
typedef int16_t I16;
typedef int32_t I32;
typedef int64_t I64;

struct cookie_info
{
	static constexpr char name[] = "Cookie";
	static constexpr int version_major = 0;
	static constexpr int version_minor = 0;
	static constexpr int version_revision = 0;
};

#define CK_DEBUG_BREAK() __debugbreak()
#ifdef DEBUG
#define CK_ASSERT(expr) assert(expr)
#else
#define CK_ASSERT(expr)
if (!(##expr))
{
	// Log the error to a file

}
#endif

