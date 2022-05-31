#pragma once

#ifdef AS_PLATFORM_WINDOWS
	#ifdef AS_BUILD_DLL
		#define ASTAR_API __declspec(dllexport)
	#else
		#define ASTAR_API __declspec(dllimport)
	#endif
#else
	#error AStar only supports Windows
#endif

#define BIT(x) (1 << x)