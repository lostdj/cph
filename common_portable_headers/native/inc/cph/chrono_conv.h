#pragma once
#ifndef _cph_h_chrono_conv
#define _cph_h_chrono_conv

#include "./base/base.h"

#include "./chrono_k.h"
#include "./chrono_units.h"

namespace cph
{
	namespace chrono
	{
		namespace conv
		{
			namespace
			{
				template<typename R, typename A1>
				R _cph_inl_pre
				to_cent(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val;

						case deca:
							return (R)((f8)val / (f8)deca_in_cent);

						case year:
							return (R)((f8)val / (f8)year_in_cent);

						case month:
							return (R)((f8)val / (f8)month_in_cent);

						case week:
							return (R)((f8)val / (f8)week_in_cent);

						case day:
							return (R)((f8)val / (f8)day_in_cent);

						case hour:
							return (R)((f8)val / (f8)hour_in_cent);

						case min:
							return (R)((f8)val / (f8)min_in_cent);

						case sec:
							return (R)((f8)val / (f8)sec_in_cent);

						case ms:
							return (R)((f8)val / (f8)ms_in_cent);

						case us:
							return (R)((f8)val / (f8)us_in_cent);

						case ns:
							return (R)((f8)val / (f8)ns_in_cent);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_deca(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * deca_in_cent;

						case deca:
							return val;

						case year:
							return (R)((f8)val / (f8)year_in_deca);

						case month:
							return (R)((f8)val / (f8)month_in_deca);

						case week:
							return (R)((f8)val / (f8)week_in_deca);

						case day:
							return (R)((f8)val / (f8)day_in_deca);

						case hour:
							return (R)((f8)val / (f8)hour_in_deca);

						case min:
							return (R)((f8)val / (f8)min_in_deca);

						case sec:
							return (R)((f8)val / (f8)sec_in_deca);

						case ms:
							return (R)((f8)val / (f8)ms_in_deca);

						case us:
							return (R)((f8)val / (f8)us_in_deca);

						case ns:
							return (R)((f8)val / (f8)ns_in_deca);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_year(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * year_in_cent;

						case deca:
							return val * year_in_deca;

						case year:
							return val;

						case month:
							return (R)((f8)val / (f8)month_in_year);

						case week:
							return (R)((f8)val / (f8)week_in_year);

						case day:
							return (R)((f8)val / (f8)day_in_year);

						case hour:
							return (R)((f8)val / (f8)hour_in_year);

						case min:
							return (R)((f8)val / (f8)min_in_year);

						case sec:
							return (R)((f8)val / (f8)sec_in_year);

						case ms:
							return (R)((f8)val / (f8)ms_in_year);

						case us:
							return (R)((f8)val / (f8)us_in_year);

						case ns:
							return (R)((f8)val / (f8)ns_in_year);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_month(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * month_in_cent;

						case deca:
							return val * month_in_deca;

						case year:
							return val * month_in_year;

						case month:
							return val;

						case week:
							return (R)((f8)val / (f8)week_in_month);

						case day:
							return (R)((f8)val / (f8)day_in_month);

						case hour:
							return (R)((f8)val / (f8)hour_in_month);

						case min:
							return (R)((f8)val / (f8)min_in_month);

						case sec:
							return (R)((f8)val / (f8)sec_in_month);

						case ms:
							return (R)((f8)val / (f8)ms_in_month);

						case us:
							return (R)((f8)val / (f8)us_in_month);

						case ns:
							return (R)((f8)val / (f8)ns_in_month);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_week(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * week_in_cent;

						case deca:
							return val * week_in_deca;

						case year:
							return val * week_in_year;

						case month:
							return val * week_in_month;

						case week:
							return val;

						case day:
							return (R)((f8)val / (f8)day_in_week);

						case hour:
							return (R)((f8)val / (f8)hour_in_week);

						case min:
							return (R)((f8)val / (f8)min_in_week);

						case sec:
							return (R)((f8)val / (f8)sec_in_week);

						case ms:
							return (R)((f8)val / (f8)ms_in_week);

						case us:
							return (R)((f8)val / (f8)us_in_week);

						case ns:
							return (R)((f8)val / (f8)ns_in_week);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_day(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * day_in_cent;

						case deca:
							return val * day_in_deca;

						case year:
							return val * day_in_year;

						case month:
							return val * day_in_month;

						case week:
							return val * day_in_week;

						case day:
							return val;

						case hour:
							return (R)((f8)val / (f8)hour_in_day);

						case min:
							return (R)((f8)val / (f8)min_in_day);

						case sec:
							return (R)((f8)val / (f8)sec_in_day);

						case ms:
							return (R)((f8)val / (f8)ms_in_day);

						case us:
							return (R)((f8)val / (f8)us_in_day);

						case ns:
							return (R)((f8)val / (f8)ns_in_day);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_hour(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * hour_in_cent;

						case deca:
							return val * hour_in_deca;

						case year:
							return val * hour_in_year;

						case month:
							return val * hour_in_month;

						case week:
							return val * hour_in_week;

						case day:
							return val * hour_in_day;

						case hour:
							return val;

						case min:
							return (R)((f8)val / (f8)min_in_hour);

						case sec:
							return (R)((f8)val / (f8)sec_in_hour);

						case ms:
							return (R)((f8)val / (f8)ms_in_hour);

						case us:
							return (R)((f8)val / (f8)us_in_hour);

						case ns:
							return (R)((f8)val / (f8)ns_in_hour);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_min(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * min_in_cent;

						case deca:
							return val * min_in_deca;

						case year:
							return val * min_in_year;

						case month:
							return val * min_in_month;

						case week:
							return val * min_in_week;

						case day:
							return val * min_in_day;

						case hour:
							return val * min_in_hour;

						case min:
							return val;

						case sec:
							return (R)((f8)val / (f8)sec_in_min);

						case ms:
							return (R)((f8)val / (f8)ms_in_min);

						case us:
							return (R)((f8)val / (f8)us_in_min);

						case ns:
							return (R)((f8)val / (f8)ns_in_min);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_sec(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * sec_in_cent;

						case deca:
							return val * sec_in_deca;

						case year:
							return val * sec_in_year;

						case month:
							return val * sec_in_month;

						case week:
							return val * sec_in_week;

						case day:
							return val * sec_in_day;

						case hour:
							return val * sec_in_hour;

						case min:
							return val * sec_in_min;

						case sec:
							return val;

						case ms:
							return (R)((f8)val / (f8)ms_in_sec);

						case us:
							return (R)((f8)val / (f8)us_in_sec);

						case ns:
							return (R)((f8)val / (f8)ns_in_sec);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_ms(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * ms_in_cent;

						case deca:
							return val * ms_in_deca;

						case year:
							return val * ms_in_year;

						case month:
							return val * ms_in_month;

						case week:
							return val * ms_in_week;

						case day:
							return val * ms_in_day;

						case hour:
							return val * ms_in_hour;

						case min:
							return val * ms_in_min;

						case sec:
							return val * ms_in_sec;

						case ms:
							return val;

						case us:
							return (R)((f8)val / (f8)us_in_ms);

						case ns:
							return (R)((f8)val / (f8)ns_in_ms);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_us(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * us_in_cent;

						case deca:
							return val * us_in_deca;

						case year:
							return val * us_in_year;

						case month:
							return val * us_in_month;

						case week:
							return val * us_in_week;

						case day:
							return val * us_in_day;

						case hour:
							return val * us_in_hour;

						case min:
							return val * us_in_min;

						case sec:
							return val * us_in_sec;

						case ms:
							return val * us_in_ms;

						case us:
							return val;

						case ns:
							return (R)((f8)val / (f8)ns_in_us);
					}

					return 0;
				}

				template<typename R, typename A1>
				R _cph_inl_pre
				to_ns(A1 val, cph::chrono::units::e from) _cph_inl_post
				{
					using namespace cph::chrono::units;
					using namespace cph::chrono::k;

					switch(from)
					{
						case cent:
							return val * ns_in_cent;

						case deca:
							return val * ns_in_deca;

						case year:
							return val * ns_in_year;

						case month:
							return val * ns_in_month;

						case week:
							return val * ns_in_week;

						case day:
							return val * ns_in_day;

						case hour:
							return val * ns_in_hour;

						case min:
							return val * ns_in_min;

						case sec:
							return val * ns_in_sec;

						case ms:
							return val * ns_in_ms;

						case us:
							return val * ns_in_us;

						case ns:
							return val;
					}

					return 0;
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_chrono_conv
