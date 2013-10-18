#pragma once
#ifndef _cph_h_chrono_k
#define _cph_h_chrono_k

#include "./base/base.h"

#include "./chrono.h"

namespace cph
{
	namespace chrono
	{
		namespace k
		{
			namespace
			{
				const timet deca_in_cent = 10;

				const timet year_in_deca  = 10;
				const timet year_in_cent  = 100;

				const timet month_in_year = 12;
				const timet month_in_deca = year_in_deca * month_in_year; // ~
				const timet month_in_cent = year_in_cent * month_in_year; // ~

				const timet week_in_month = 4;  // ~
				const timet week_in_year  = 52; // ~
				const timet week_in_deca  = year_in_deca * week_in_year; // ~
				const timet week_in_cent  = year_in_cent * week_in_year; // ~

				const timet day_in_week   = 7;
				const timet day_in_month  = 30;  // ~
				const timet day_in_year   = 365;  // ~
				const timet day_in_deca   = year_in_deca * day_in_year; // ~
				const timet day_in_cent   = year_in_cent * day_in_year; // ~

				const timet hour_in_day   = 24;
				const timet hour_in_week  = 168;
				const timet hour_in_month = day_in_month * hour_in_day;  // ~
				const timet hour_in_year  = day_in_year  * hour_in_day;  // ~
				const timet hour_in_deca  = year_in_deca * hour_in_year; // ~
				const timet hour_in_cent  = year_in_cent * hour_in_year; // ~

				const timet min_in_hour   = 60;
				const timet min_in_day    = 1440;
				const timet min_in_week   = 10080;
				const timet min_in_month  = day_in_month * min_in_day;  // ~
				const timet min_in_year   = day_in_year  * min_in_day;  // ~
				const timet min_in_deca   = year_in_deca * min_in_year; // ~
				const timet min_in_cent   = year_in_cent * min_in_year; // ~

				const timet sec_in_min    = 60;
				const timet sec_in_hour   = 3600;
				const timet sec_in_day    = 86400;
				const timet sec_in_week   = 604800;
				const timet sec_in_month  = day_in_month * sec_in_day;  // ~
				const timet sec_in_year   = day_in_year  * sec_in_day;  // ~
				const timet sec_in_deca   = year_in_deca * sec_in_year; // ~
				const timet sec_in_cent   = year_in_cent * sec_in_year; // ~

				const timet ms_in_sec     = 1000;
				const timet ms_in_min     = 60000;
				const timet ms_in_hour    = 3600000;
				const timet ms_in_day     = 86400000;
				const timet ms_in_week    = 604800000;
				const timet ms_in_month   = day_in_month * ms_in_day;  // ~
				const timet ms_in_year    = day_in_year  * ms_in_day;  // ~
				const timet ms_in_deca    = year_in_deca * ms_in_year; // ~
				const timet ms_in_cent    = year_in_cent * ms_in_year; // ~

				const timet us_in_ms      = 1000;
				const timet us_in_sec     = 1000000;
				const timet us_in_min     = sec_in_min   * us_in_sec;
				const timet us_in_hour    = min_in_hour  * us_in_min;
				const timet us_in_day     = hour_in_day  * us_in_hour;
				const timet us_in_week    = day_in_week  * us_in_day;
				const timet us_in_month   = day_in_month * us_in_day;  // ~
				const timet us_in_year    = day_in_year  * us_in_day;  // ~
				const timet us_in_deca    = year_in_deca * us_in_year; // ~
				const timet us_in_cent    = year_in_cent * us_in_year; // ~

				const timet ns_in_us      = 1000;
				const timet ns_in_ms      = 1000000;
				const timet ns_in_sec     = 1000000000;
				const timet ns_in_min     = sec_in_min   * ns_in_sec;
				const timet ns_in_hour    = min_in_hour  * ns_in_min;
				const timet ns_in_day     = hour_in_day  * ns_in_hour;
				const timet ns_in_week    = day_in_week  * ns_in_day;
				const timet ns_in_month   = day_in_month * ns_in_day;  // ~
				const timet ns_in_year    = day_in_year  * ns_in_day;  // ~
				const timet ns_in_deca    = year_in_deca * ns_in_year; // ~
				const timet ns_in_cent    = year_in_cent * ns_in_year; // ~
			}
		}
	}
}

#endif // #ifndef _cph_h_chrono_k
