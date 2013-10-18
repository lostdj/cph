#pragma once
#ifndef _cph_h_private_chrono
#define _cph_h_private_chrono

#include "./../base/base.h"

#include "./platform.h"

// TODO: !
namespace cph
{
	namespace chrono
	{
		namespace cph__private
		{
			#if _cph_os_win
				struct SYSTEMTIME
				{
					cph::cph__private::WORD wYear;
					cph::cph__private::WORD wMonth;
					cph::cph__private::WORD wDayOfWeek;
					cph::cph__private::WORD wDay;
					cph::cph__private::WORD wHour;
					cph::cph__private::WORD wMinute;
					cph::cph__private::WORD wSecond;
					cph::cph__private::WORD wMilliseconds;
				};

				struct FILETIME
				{
					cph::cph__private::DWORD dwLowDateTime;
					cph::cph__private::DWORD dwHighDateTime;
				};

				struct TIME_ZONE_INFORMATION
				{
					cph::cph__private::LONG Bias;
					cph::cph__private::WCHAR StandardName[32];
					SYSTEMTIME StandardDate;
					cph::cph__private::LONG StandardBias;
					cph::cph__private::WCHAR DaylightName[32];
					SYSTEMTIME DaylightDate;
					cph::cph__private::LONG DaylightBias;
				};
			#elif _cph_posix
				// http://code.metager.de/source/xref/dlang/druntime/src/core/sys/posix/time.d
				typedef int clockid_t;
				enum
				{
					CLOCK_MONOTONIC = 1
				};

				typedef s4 time_t;

				struct timespec
				{
					time_t tv_sec;
					long   tv_nsec;
				};

				struct timeval
				{
					time_t tv_sec;
					long   tv_usec;
				};

				struct tm
				{
					int tm_sec;
					int tm_min;
					int tm_hour;
					int tm_mday;
					int tm_mon;
					int tm_year;
					int tm_wday;
					int tm_yday;
					int tm_isdst;
					// TODO: HAVE_STRUCT_TM_GMTOFF, HAVE_STRUCT_TM_TM_GMTOFF, HAVE_STRUCT_TM___TM_GMTOFF
					long tm_gmtoff;
					const char *tm_zone;
				};

				struct timezone
				{
					int tz_minuteswest;
					int tz_dsttime;
				};
			#endif

			namespace
			{
				#if _cph_os_win
					extern "C"
					{
						extern void WINAPI Sleep(cph::cph__private::DWORD);
						extern cph::cph__private::BOOL WINAPI QueryPerformanceFrequency(cph::cph__private::LARGE_INTEGER*);
						extern cph::cph__private::BOOL WINAPI QueryPerformanceCounter(cph::cph__private::LARGE_INTEGER*);
						// extern void WINAPI GetLocalTime(SYSTEMTIME*);
						extern cph::cph__private::BOOL WINAPI SystemTimeToFileTime(const SYSTEMTIME*, FILETIME*);
						extern cph::cph__private::BOOL WINAPI FileTimeToSystemTime(const FILETIME*, SYSTEMTIME*);
						extern cph::cph__private::BOOL WINAPI FileTimeToLocalFileTime(const FILETIME*, FILETIME*);
						extern cph::cph__private::BOOL WINAPI LocalFileTimeToFileTime(const FILETIME*, FILETIME*);
						extern void WINAPI GetSystemTimeAsFileTime(FILETIME*);

						enum
						{
							GetTimeZoneInformation_TIME_ZONE_ID_UNKNOWN  = 0,
							GetTimeZoneInformation_TIME_ZONE_ID_STANDARD = 1,
							GetTimeZoneInformation_TIME_ZONE_ID_DAYLIGHT = 2
						};
						extern cph::cph__private::DWORD WINAPI GetTimeZoneInformation(TIME_ZONE_INFORMATION*);
					}
				#elif _cph_posix
					extern "C"
					{
						extern int nanosleep(const struct timespec*, struct timespec*);
						extern int clock_gettime(clockid_t, timespec*);
						extern int gettimeofday(timeval*, timezone*);
						extern tm* localtime(const time_t*);
						//extern tm* localtime_r(const time_t*, tm*);
						extern tm* gmtime(const time_t*);
						extern time_t mktime(tm*);
					}
				#endif
			}
		}
	}
}

#endif // #ifndef _cph_h_private_chrono
