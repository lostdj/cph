#pragma once
#ifndef _cph_h_private_platform
#define _cph_h_private_platform

#include "./../base/base.h"

// TODO: !
namespace cph
{
	namespace cph__private
	{
		#if _cph_os_win
			#define WINAPI __stdcall

			typedef int WINBOOL;
			typedef WINBOOL BOOL;

			typedef unsigned short WORD;
			typedef unsigned long DWORD;

			typedef long LONG;
			typedef unsigned long ULONG;

			typedef s8 LONGLONG;
			typedef u8 DWORDLONG;
			typedef DWORDLONG ULONGLONG;

			typedef wchar_t WCHAR;

			union LARGE_INTEGER
			{
				__extension__ struct
				{
					DWORD LowPart;
					LONG  HighPart;
				};

				LONGLONG QuadPart;
			};

			union ULARGE_INTEGER
			{
				__extension__ struct
				{
					DWORD LowPart;
					LONG  HighPart;
				};

				ULONGLONG QuadPart;
			};
		#elif _cph_posix
			//
		#endif

		namespace
		{
			#if _cph_os_win
				//
			#elif _cph_posix
				//
			#endif
		}
	}
}

#endif // #ifndef _cph_h_private_platform
