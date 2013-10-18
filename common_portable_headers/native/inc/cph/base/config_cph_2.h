#pragma once
#ifndef _cph_h__config_cph_2
#define _cph_h__config_cph_2

#ifdef _cph_cfg_config_user_2
	#include _cph_cfg_config_user_2
#endif

//
//#define _cph_cc_msc_msvcrt_dll 0
//#define _cph_cc_msc_msvcrt_static 0
#if defined(_cph_cfg_msvcrt_dll) && defined(_cph_cfg_msvcrt_static)
	#error "Wat?"
#elif defined(_cph_cfg_msvcrt_dll)
	#undef _cph_cc_msc_msvcrt_dll
	#define _cph_cc_msc_msvcrt_dll 1

	#undef _cph_cc_msc_msvcrt_static
	#define _cph_cc_msc_msvcrt_static 0
#elif defined(_cph_cfg_msvcrt_static)
	#undef _cph_cc_msc_msvcrt_dll
	#define _cph_cc_msc_msvcrt_dll 0

	#undef _cph_cc_msc_msvcrt_static
	#define _cph_cc_msc_msvcrt_static 1
#endif

//
#if !defined(_cph_cfg_basic_szof_check) || _cph_cfg_basic_szof_check
	#include "./../debug_assert_static.h"
	namespace cph
	{
		namespace cph__private
		{
			namespace assert_static_cfg_basic_szof_check
			{ 
				namespace
				{
					_cph_assert_static(sizeof(byte) == 1, szofbyte);
					_cph_assert_static(sizeof(octet) == 1, szofoctet);
					_cph_assert_static(sizeof(s1) == 1, szofs1);
					_cph_assert_static(sizeof(u1) == 1, szofu1);
					_cph_assert_static(sizeof(s2) == 2, szofs2);
					_cph_assert_static(sizeof(u2) == 2, szofu2);
					_cph_assert_static(sizeof(s4) == 4, szofs4);
					_cph_assert_static(sizeof(u4) == 4, szofu4);
					_cph_assert_static(sizeof(s8) == 8, szofs8);
					_cph_assert_static(sizeof(u8) == 8, szofu8);
					_cph_assert_static(sizeof(f4) == 4, szoff4);
					_cph_assert_static(sizeof(f8) == 8, szoff8);

					_cph_assert_static(sizeof(uw) == sizeof(void*), szofword);
				}
			}
		}
	}
#endif

#endif // #ifndef _cph_h__config_cph_2
