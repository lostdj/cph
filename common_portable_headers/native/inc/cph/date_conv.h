#pragma once
#ifndef _cph_h_date_conv
#define _cph_h_date_conv

#include "./base/base.h"

#include "./private/chrono.h"

#include "./chrono.h"
#include "./chrono_k.h"
#include "./chrono_units.h"
#include "./chrono_conv.h"
#include "./date.h"

namespace cph
{
	namespace date
	{
		namespace conv
		{
			namespace
			{
				void _cph_inl_pre
				gmt_from_ms(cph::chrono::timet ms, date &d) _cph_inl_post
				{
					using namespace cph::cph__private;
					using namespace cph::chrono::cph__private;

					#if _cph_os_win
						FILETIME ft;
						u8 t = cph::chrono::conv::to_us<cph::chrono::timet>(ms, cph::chrono::units::ms) + u8(11644473600000000);
						t *= 10;
						ft.dwLowDateTime = (DWORD)t;
						ft.dwHighDateTime = (DWORD)(t >> 32);

						SYSTEMTIME st;
						FileTimeToSystemTime(&ft, &st);

						d.year  = (u2)st.wYear;
						d.month = (u1)st.wMonth;
						d.weekd = !st.wDayOfWeek ? (u1)cph::date::weekday::Sun : (u1)st.wDayOfWeek;
						d.mday  = (u1)st.wDay;
						d.hour  = (u1)st.wHour;
						d.min   = (u1)st.wMinute;
						d.sec   = (u1)st.wSecond;
						d.ms    = (u2)st.wMilliseconds;
					#elif _cph_posix
						time_t tt = conv::to_sec<time_t>(ms, units::ms);
						tm tm = *gmtime(&tt);

						d.year  = (u2)tm.tm_year;
						d.month = (u1)tm.tm_mon + 1;
						d.weekd = !tm.tm_wday ? (u1)cph::date::weekday::Sun : (u1)tm.tm_wday;
						d.mday  = (u1)tm.tm_mday;
						d.hour  = (u1)tm.tm_hour;
						d.min   = (u1)tm.tm_min;
						d.sec   = (u1)tm.tm_sec;
						d.ms    = (u2)ms % 1000;
					#endif
				}

				void _cph_inl_pre
				local_from_ms(cph::chrono::timet ms, date &d) _cph_inl_post
				{
					using namespace cph::cph__private;
					using namespace cph::chrono::cph__private;

					#if _cph_os_win
						FILETIME ft;
						u8 t = cph::chrono::conv::to_us<cph::chrono::timet>(ms, cph::chrono::units::ms) + u8(11644473600000000);
						t *= 10;
						ft.dwLowDateTime = (DWORD)t;
						ft.dwHighDateTime = (DWORD)(t >> 32);

						{
							FILETIME tmp = ft;
							FileTimeToLocalFileTime(&ft, &tmp /*MSDN: This parameter cannot be the same as the lpFileTime parameter.*/);
							ft = tmp;
						}

						SYSTEMTIME st;
						FileTimeToSystemTime(&ft, &st);

						d.year  = (u2)st.wYear;
						d.month = (u1)st.wMonth;
						d.weekd = !st.wDayOfWeek ? (u1)cph::date::weekday::Sun : (u1)st.wDayOfWeek;
						d.mday  = (u1)st.wDay;
						d.hour  = (u1)st.wHour;
						d.min   = (u1)st.wMinute;
						d.sec   = (u1)st.wSecond;
						d.ms    = (u2)st.wMilliseconds;
					#elif _cph_posix
						time_t tt = conv::to_sec<time_t>(ms, units::ms);
						tm tm = *localtime(&tt);

						d.year  = (u2)tm.tm_year;
						d.month = (u1)tm.tm_mon + 1;
						d.weekd = !tm.tm_wday ? (u1)cph::date::weekday::Sun : (u1)tm.tm_wday;
						d.mday  = (u1)tm.tm_mday;
						d.hour  = (u1)tm.tm_hour;
						d.min   = (u1)tm.tm_min;
						d.sec   = (u1)tm.tm_sec;
						d.ms    = (u2)ms % 1000;
					#endif
				}

				cph::chrono::timet _cph_inl_pre
				local_to_ms(date &d) _cph_inl_post
				{
					using namespace cph::cph__private;
					using namespace cph::chrono::cph__private;

					#if _cph_os_win						
						SYSTEMTIME st;
						st.wYear         = d.year;
						st.wMonth        = d.month;
						st.wDayOfWeek    = d.weekd == (u1)cph::date::weekday::Sun ? 0 : d.weekd;
						st.wDay          = d.mday;
						st.wHour         = d.hour;
						st.wMinute       = d.min;
						st.wSecond       = d.sec;
						st.wMilliseconds = d.ms;

						FILETIME ft;
						SystemTimeToFileTime(&st, &ft);
						{
							FILETIME tmp;
							LocalFileTimeToFileTime(&ft, &tmp /*MSDN: This parameter cannot be the same as the lpFileTime parameter.*/);
							ft = tmp;
						}

						cph::chrono::timet r = 0;
						r |= ft.dwHighDateTime;
						r <<= 32;
						r |= ft.dwLowDateTime;
						r /= 10;
						r -= u8(11644473600000000);

						return cph::chrono::conv::to_ms<cph::chrono::timet>(r, cph::chrono::units::us);
					#elif _cph_posix
						tm tm;
						tm.tm_year = d.year;
						tm.tm_mon  = d.mon - 1;
						tm.tm_wday = d.weekd == (u1)cph::date::weekday::Sun ? 0 : d.weekd;
						tm.tm_mday = d.mday;
						tm.tm_hour = d.hour;
						tm.tm_min  = d.min;
						tm.tm_sec  = d.sec;

						cph::chrono::timet r = mktime(&tm);

						return cph::chrono::conv::to_ms<cph::chrono::timet>(r, cph::chrono::units::sec);
					#endif
				}

				cph::chrono::timet _cph_inl_pre
				gmt_to_ms(date &d) _cph_inl_post
				{
					using namespace cph::cph__private;
					using namespace cph::chrono::cph__private;

					// MinGW gives wrong result.
					// #if _cph_os_win						
					// 	SYSTEMTIME st;
					// 	st.wYear         = d.year;
					// 	st.wMonth        = d.month;
					// 	st.wDayOfWeek    = d.weekd == (u1)cph::date::weekday::Sun ? 0 : d.weekd;
					// 	st.wDay          = d.mday;
					// 	st.wHour         = d.hour;
					// 	st.wMinute       = d.min;
					// 	st.wSecond       = d.sec;
					// 	st.wMilliseconds = d.ms;

					// 	FILETIME ft;
					// 	SystemTimeToFileTime(&st, &ft);

					// 	cph::chrono::timet r = 0;
					// 	r |= ft.dwHighDateTime;
					// 	r <<= 32;
					// 	r |= ft.dwLowDateTime;
					// 	r /= 10;
					// 	r -= u8(11644473600000000);

					// 	return cph::chrono::conv::to_ms<cph::chrono::timet>(r, cph::chrono::units::us);

					// #elif _cph_posix
						cph::chrono::timet r;

						// +stolen APR
							cph::chrono::timet year = d.year - 1900;
							cph::chrono::timet days;
							static const int dayoffset[12] =
							{306, 337, 0, 31, 61, 92, 122, 153, 184, 214, 245, 275};

							/* shift new year to 1st March in order to make leap year calc easy */

							if ((d.month - 1) < 2)
								year--;

							/* Find number of days since 1st March 1900 (in the Gregorian calendar). */

							days = year * 365 + year / 4 - year / 100 + (year / 100 + 3) / 4;
							days += dayoffset[(d.month - 1)] + d.mday - 1;
							days -= 25508;           /* 1 jan 1970 is 25508 days since 1 mar 1900 */
							days = ((days * 24 + d.hour) * 60 + d.min) * 60 + d.sec;

							// if (days < 0) {
							// 	return APR_EBADDATE;
							// }
							r = days * cph::chrono::k::ms_in_sec + d.ms;
						// -stolen APR

						return r;

					// #endif
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_date_conv
