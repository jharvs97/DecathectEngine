#pragma once

#ifdef DCTHCT_PLATFORM_WINDOWS
	#ifdef DCTHCT_BUILD_DLL
		#define DCTHCT_API __declspec(dllexport)
	#else
		#define DCTHCT_API __declspec(dllimport)
	#endif
#else
	#error Decathect only supports Windows
#endif

#ifdef DCTHCT_ENABLE_ASSERTS
	#define DCTHCT_ASSERT(stmnt, ...) { if(!(stmnt)) { DCTHCT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DCTHCT_CORE_ASSERT(stmnt, ...) { if(!(stmnt)) { DCTHCT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DCTHCT_ASSERT(stmnt, ...)
	#define DCTHCT_CORE_ASSERT(stmnt, ...)
#endif

#define BIT(x) (1 << x)