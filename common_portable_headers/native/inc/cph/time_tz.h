#pragma once
#ifndef _cph_h_time_tz
#define _cph_h_time_tz

#include "./base/base.h"

#include "./private/chrono.h"

#include "./chrono.h"

namespace cph
{
	namespace time
	{
		namespace tz
		{
			struct tzinfo
			{
				cph::chrono::timest off;    // Offset in minutes.
				cph::chrono::timest dstoff; // Minutes.
				b1 dst;
			};

			namespace
			{
				void _cph_inl_pre
				local(tzinfo &ti) _cph_inl_post
				{
					using namespace cph::cph__private;
					using namespace cph::chrono::cph__private;

					#if _cph_os_win
						TIME_ZONE_INFORMATION tzi;
						DWORD dst = GetTimeZoneInformation(&tzi);

						ti.off = -tzi.Bias;
						ti.dstoff = -tzi.DaylightBias;
						ti.dst = dst == GetTimeZoneInformation_TIME_ZONE_ID_DAYLIGHT;
					#elif _cph_posix
						// TODO: HAVE_STRUCT_TM_GMTOFF, HAVE_STRUCT_TM_TM_GMTOFF, HAVE_STRUCT_TM___TM_GMTOFF

						timeval tv;
						gettimeofday(&tv, null);

						time_t tt = tv.tv_sec;
						tm tm = *gmtime(&tt);

						ti.off = tm.tm_gmtoff;
						ti.dstoff = 60;
						ti.dst = tm.isdst;
					#endif
				}

				tzinfo _cph_inl_pre
				local() _cph_inl_post
				{
					tzinfo ti;

					local(ti);

					return ti;
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_time_tz
