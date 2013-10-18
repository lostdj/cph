#pragma once
#ifndef _cph_h__platform
#define _cph_h__platform

//
//
//
#define _cph_arch_32 0
#define _cph_arch_64 0

#define _cph_arch_x86 0
#define _cph_arch_x64 0

#define _cph_bo_id 0
#define _cph_bo_be 0 // 1
#define _cph_bo_le 0 // 2
#define _cph_bo_net 0

#define _cph_os_win 0
#define _cph_os_winnt 0
#define _cph_os_win32 0
#define _cph_os_win64 0

#define _cph_posix 0
#define _cph_os_unix 0
#define _cph_os_linux 0

#define _cph_cc_msc 0
#define _cph_cc_msc7 0
#define _cph_cc_msc8 0
#define _cph_cc_msc9 0
#define _cph_cc_msc10 0
#define _cph_cc_msc11 0
#define _cph_cc_msc_major 0

#define _cph_cc_gnu 0
#define _cph_cc_mingw 0
#define _cph_cc_gnu3 0
#define _cph_cc_gnu4 0
#define _cph_cc_major 0
#define _cph_cc_gnu_minor 0
#define _cph_cc_gnu_patch 0

// Force inline.
#define _cph_inl_pre
#define _cph_inl_post

// No inline.
#define _cph_noinl

// Fastcall.
#define _cph_fc_pre
#define _cph_fc_post

// Dll.
#define _cph_dll_imp
#define _cph_dll_exp

// Etc.
#define _cph_quotemac(arg) #arg
#define _cph_quoteval(arg) _cph_quotemac(arg)
#define _cph_eval(arg) arg
#define _cph_concat_(x, y) x ## y
#define _cph_concat(x, y) _cph_concat_(x, y)
#define _cph_funcname
#define _cph_file_line /*__BASE_FILE__*/__FILE__ ":" _cph_quoteval(__LINE__)
#define _cph_cpp 0
#define null 0

#define likely
#define unlikely

#define elif    else if
#define forever for(;;)

//#define eq ==
//#define not_eq !=
//#define and &&
//#define or  ||
//#define not !
//#define bitnot ~
//#define bitand &
//#define bitor |
//#define xor ^

#define _cph_wsz

//
//
//
#if defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
	#undef _cph_arch_64
	#define _cph_arch_64 1

	#undef _cph_arch_x64
	#define _cph_arch_x64 1

	#undef _cph_os_win
	#define _cph_os_win 1

	#ifdef __NT__
		#undef _cph_os_winnt
		#define _cph_os_winnt 1
	#endif

	#undef _cph_os_win64
	#define _cph_os_win64 1

	#define WIN32_LEAN_AND_MEAN
	//#ifndef _UNICODE
	//	#define _UNICODE
	//#endif

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
	#undef _cph_arch_32
	#define _cph_arch_32 1

	#undef _cph_arch_x86
	#define _cph_arch_x86 1

	#undef _cph_os_win
	#define _cph_os_win 1

	#ifdef __NT__
		#undef _cph_os_winnt
		#define _cph_os_winnt 1
	#endif

	#undef _cph_os_win32
	#define _cph_os_win32 1

	#define WIN32_LEAN_AND_MEAN
	//#ifndef _UNICODE
	//	#define _UNICODE
	//#endif

// http://sourceforge.net/p/predef/wiki/Home/
// Type 'cpp -dM some.h', or 'gcc -dM -E - < /dev/null' to get a list of predefined macros.
#elif defined(linux) || defined(__linux) || defined(__linux__)
	#undef _cph_posix
	#define _cph_posix 1

	#undef _cph_os_unix
	#define _cph_os_unix 1

	#undef _cph_os_linux
	#define _cph_os_linux 1

	#if defined(i386) || defined(__i386)
		#undef _cph_arch_32
		#define _cph_arch_32 1

		#undef _cph_arch_x86
		#define _cph_arch_x86 1
	#elif defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(__amd64__ )
		#undef _cph_arch_64
		#define _cph_arch_64 1

		#undef _cph_arch_x64
		#define _cph_arch_x64 1
	#else
		#error "Unsupported architecture."
	#endif

#else
	#error "Unsupported target OS."
#endif

//
//
//
#if defined(_MSC_VER)
	#undef _cph_cc_msc
	#define _cph_cc_msc 1

	#if _MSC_VER == 1300
		#undef _cph_cc_msc7
		#define _cph_cc_msc7 1

		#undef _cph_cc_msc_major
		#define _cph_cc_msc_major 7
	#elif _MSC_VER == 1400
		#undef _cph_cc_msc8
		#define _cph_cc_msc8 1

		#undef _cph_cc_msc_major
		#define _cph_cc_msc_major 8
	#elif _MSC_VER == 1500
		#undef _cph_cc_msc9
		#define _cph_cc_msc9 1

		#undef _cph_cc_msc_major
		#define _cph_cc_msc_major 9
	#elif _MSC_VER == 1600
		#undef _cph_cc_msc10
		#define _cph_cc_msc10 1

		#undef _cph_cc_msc_major
		#define _cph_cc_msc_major 10
	#elif _MSC_VER == 1700
		#undef _cph_cc_msc11
		#define _cph_cc_msc11 1

		#undef _cph_cc_msc_major
		#define _cph_cc_msc_major 11
	#endif

	#undef _cph_funcname
	#define _cph_funcname __FUNCSIG__

	// warning C4201: nonstandard extension used : nameless struct/union
	#pragma warning(disable: 4201)

#elif defined(__GNUC__)
	#undef _cph_cc_gnu
	#define _cph_cc_gnu 1

	#ifdef __MINGW32__
		#undef _cph_cc_mingw
		#define _cph_cc_mingw 1
	#endif

	#if __GNUC__ == 3
		#undef _cph_cc_gnu3
		#define _cph_cc_gnu3 1
	#elif __GNUC__ == 4
		#undef _cph_cc_gnu4
		#define _cph_cc_gnu4 1
	#endif

	#undef _cph_cc_gnu_major
	#undef _cph_cc_gnu_minor
	#undef _cph_cc_gnu_patch
	#define _cph_cc_gnu_major __GNUC__
	#define _cph_cc_gnu_minor __GNUC_MINOR__
	#define _cph_cc_gnu_patch __GNUC_PATCHLEVEL__

	#undef _cph_funcname
	#define _cph_funcname __PRETTY_FUNCTION__
#else
	#error "Unsupported compiler."
#endif

#if !_cph_cc_gnu
	#define __extension__
#endif

//
//
//
#if _cph_arch_x86 || _cph_arch_x64
	#undef _cph_bo_le
	#define _cph_bo_le 2

	#undef _cph_bo_id
	#define _cph_bo_id _cph_bo_le
#else
	#error "Unknown endianness."
#endif

//
//
//
#if _cph_cc_msc
	#undef _cph_inl_pre
	#define _cph_inl_pre __forceinline

	#undef _cph_inl_post
	#define _cph_inl_post

	#undef _cph_noinl
	#define _cph_noinl __declspec(noinline)
#elif _cph_cc_gnu
	#undef _cph_inl_pre
	#define _cph_inl_pre __inline

	#if _cph_cc_major > 3
		#undef _cph_inl_post
		#define _cph_inl_post __attribute__((always_inline))
	#else
		#undef _cph_inl_post
		#define _cph_inl_post
	#endif

	#undef _cph_noinl
	#define _cph_noinl __attribute__ ((noinline))
#endif

//
//
//
#if _cph_arch_x86
	#if _cph_cc_msc
		#undef _cph_fc_pre
		#define _cph_fc_pre __fastcall

		#undef _cph_fc_post
		#define _cph_fc_post
	#elif _cph_cc_gnu
		#if _cph_cc_gnu_major > 3 || (_cph_cc_gnu3 && _cph_cc_gnu_minor > 3)
			#undef _cph_fc_pre
			#define _cph_fc_pre

			#undef _cph_fc_post
			#define _cph_fc_post __attribute__((fastcall))
		#else
			#undef _cph_fc_pre
			#define _cph_fc_pre

			#undef _cph_fc_post
			#define _cph_fc_post
		#endif
	#endif
#endif

//
//
//
#if _cph_cc_msc || _cph_cc_mingw
	#undef _cph_dll_imp
	#define _cph_dll_imp __declspec(dllimport)

	#undef _cph_dll_exp
	#define _cph_dll_exp __declspec(dllexport)
#elif _cph_cc_gnu
	#undef _cph_dll_imp
	#define _cph_dll_imp

	#undef _cph_dll_exp
	#define _cph_dll_exp __attribute__((visibility("default")))
#endif

//
//
//
#ifdef __cplusplus
	#undef _cph_cpp
	#define _cph_cpp 1

	#if _cph_cc_msc && _cph_cc_msc_major >= 10
		#undef null
		#define null nullptr
	#elif _cph_cc_gnu && (_cph_cc_gnu_major > 4 || (_cph_cc_gnu4 && _cph_cc_gnu_minor >= 6))
		#undef null
		#define null nullptr
	#elif _cph_arch_32
		#undef null
		#define null 0
	#elif _cph_arch_64
		#undef null
		#define null (0L)
	#else
		#error "Undefined: null."
	#endif
#else
	#undef null
	#define null ((void *)0)
#endif

//
//
//
#if _cph_cc_gnu
	#undef likely
	#define likely(exp) __builtin_expect((exp) != 0, true)

	#undef unlikely
	#define unlikely(exp) __builtin_expect((exp) != 0, false)
#else
	#undef likely
	#define likely(exp) exp

	#undef unlikely
	#define unlikely(exp) exp
#endif

//
//
//
namespace cph
{
	typedef unsigned char      b1;
	typedef unsigned char      byte;
	typedef unsigned char      octet;
	typedef signed char        s1;
	typedef unsigned char      u1;
	typedef signed short int   s2;
	typedef unsigned short int u2;

	#if _cph_cc_msc
		typedef signed   __int32 s4;
		typedef unsigned __int32 u4;
		typedef signed   __int64 s8;
		typedef unsigned __int64 u8;
	#elif _cph_cc_gnu
		#if _cph_arch_32
			typedef signed int         s4;
			typedef unsigned int       u4;
			typedef signed long long   s8;
			typedef unsigned long long u8;
		#elif _cph_arch_64
			typedef signed int         s4;
			typedef unsigned int       u4;
			typedef signed long int    s8;
			typedef unsigned long int  u8;
		#endif
	#endif

	#if _cph_arch_32
		#undef _cph_wsz
		#define _cph_wsz 4

		typedef s4 sw;
		typedef u4 uw;
		typedef s4 ptrd;
	#elif _cph_arch_64
		#undef _cph_wsz
		#define _cph_wsz 8

		typedef s8 sw;
		typedef u8 uw;
		typedef s8 ptrd;
	#else
		#error "Undeclared: sw, uw, ptrd."
	#endif

	typedef float  f4;
	typedef double f8;
}

#endif // #ifndef _cph_h__platform
