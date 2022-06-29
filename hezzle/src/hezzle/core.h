#pragma once


#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HEZZLE_API _declspec(dllexport)
	#else
		#define HEZZLE_API _declspec(dllimport) 
	#endif
#else
	#error hezzle only support windows!
#endif
