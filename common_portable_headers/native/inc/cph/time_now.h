#pragma once
#ifndef _cph_h_time_now
#define _cph_h_time_now

#include "./base/base.h"

#include "./private/chrono.h"

#include "./chrono.h"
#include "./chrono_k.h"
#include "./chrono_units.h"
#include "./chrono_conv.h"

namespace cph
{
	namespace time
	{
		namespace now
		{
			namespace
			{
				// GMT? UTC? Leap seconds? I have no idea.
				cph::chrono::timet _cph_inl_pre
				ms() _cph_inl_post
				{
					using namespace cph::cph__private;
					using namespace cph::chrono::cph__private;

					#if _cph_os_win
						FILETIME ft;
						cph::chrono::timet r = 0;

						GetSystemTimeAsFileTime(&ft);

						r |= ft.dwHighDateTime;
						r <<= 32;
						r |= ft.dwLowDateTime;
						r /= 10;
						r -= u8(11644473600000000);

						return cph::chrono::conv::to_ms<cph::chrono::timet>(r, cph::chrono::units::us);
					#elif _cph_posix
						timeval tv;
						gettimeofday(&tv, null);

						return tv.tv_sec * k::ms_in_sec + tv.tv_usec / k::us_in_ms;
					#endif
				}

				cph::chrono::timet _cph_inl_pre
				sec() _cph_inl_post
				{
					return cph::chrono::conv::to_sec<cph::chrono::timet>(ms(), cph::chrono::units::ms);
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_chrono_now
