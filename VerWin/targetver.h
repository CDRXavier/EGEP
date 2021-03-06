#pragma once

//Include SDKDDKVer.h to define the highest usable version of Windows platform.

//To modify the macros, in a header file(for example, targetver.h which is included when you
//create a project that targets Windows), add the following lines.
//
//#define WINVER 0x0A00
//#define _WIN32_WINNT 0x0A00
//that targets the windows 10 system.
//
//If you don't see all of these versions of Windows listed in a copy of 
//SDKDDKVer.h that you're looking at, you probably are using an older version of the Windows SDK.
//By default, Win32 projects in Visual Studio 2017 use the Windows 10 SDK.


#include <winsdkver.h>
#define WINVER _WIN32_WINNT_WIN2K
#define _WIN32_WINNT _WIN32_WINNT_WIN2K
#include <SDKDDKVer.h>
//must include the return at the end of file
