#if !defined(CRY_FOUNDATION_H)
	#define CRY_FOUNDATION_H
#pragma once
	#if !defined(_CRT_SECURE_NO_WARNINGS)
		#define _CRT_SECURE_NO_WARNINGS
	#endif
//	
// 排除极少数使用的函数
//
	#define WIN32_LEAN_AND_MEAN
//
// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。
// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// 将 _WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。
//
	#include <SDKDDKVer.h>
	#include <Windows.h>
	#include <stdint.h>
	#include <stdio.h>
	#include <tchar.h>
//
// 避免库与库之间冲突
//
	#if !defined(CRY_STATIC)
		#define CRY_STATIC
	#endif

	#if defined(_WIN32) && defined(_DLL)
		#if !defined(CRY_DLL) && !defined(CRY_STATIC)
			#define CRY_DLL
		#endif
	#endif

	#if (defined(_WIN32) && defined(CRY_DLL))
		#if defined(CRY_EXPORT)
			#define FunctionExport __declspec(dllexport)
		#else
			#define FunctionExport __declspec(dllimport)
		#endif
	#else
		#define FunctionExport
	#endif
	
	#if defined(_MSC_VER)
		#if defined(CRY_DLL)
			#if defined(_DEBUG)
				#define CRY_LIB_SUFFIX "d.lib"
			#else
				#define CRY_LIB_SUFFIX ".lib"
			#endif
			#elif defined(_DLL)
			#if defined(_DEBUG)
				#define CRY_LIB_SUFFIX "d.lib"
			#else
				#define CRY_LIB_SUFFIX ".lib"
			#endif
			#else
			#if defined(_DEBUG)
				#define CRY_LIB_SUFFIX "d.lib"
			#else
				#define CRY_LIB_SUFFIX ".lib"
			#endif
		#endif
	#endif
	#if !defined(CRY_EXPORT)
		#pragma comment(lib, "CryFoundation" CRY_LIB_SUFFIX)
	#endif
#endif