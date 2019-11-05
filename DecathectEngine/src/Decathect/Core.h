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

#define BIT(x) (1 << x)