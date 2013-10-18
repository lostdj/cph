#pragma once
#ifndef _cph_h_private_debug_log_simple
#define _cph_h_private_debug_log_simple

#include "./../base/base.h"

#include "./../debug_print_simple.h"
#include "./../text_string.h"
#include "./../date_now.h"
#include "./../time_tz.h"
#include "./../chrono_conv.h"
#include "./../math.h"

namespace cph
{
	namespace debug
	{
		namespace log_simple
		{
			namespace cph__private
			{
				namespace
				{
					extern "C"
					{
						extern int printf(const char*, ...);

						#if _cph_cc_msc
							extern int sprintf_s(char*, uw, const char*, ...);
							#define _cph_private_snprintf cph::debug::log_simple::cph__private::sprintf_s
						#else
							extern int snprintf(char*, int, const char*, ...);
							#define _cph_private_snprintf cph::debug::log_simple::cph__private::snprintf
						#endif
					}
				}

				namespace
				{
					void _cph_inl_pre
					timestamp(cph::text::string::str8 &s) _cph_inl_post
					{
						//
						cph::date::date d = cph::date::now::local();

						//
						cph::time::tz::tzinfo tz = cph::time::tz::local();
						cph::chrono::timest tzoff = tz.dst ? tz.off + tz.dstoff : tz.off;
						// 30 min?
						tzoff = cph::chrono::conv::to_hour<cph::chrono::timest>(tzoff, cph::chrono::units::min);

						//
						_cph_private_snprintf((char*)s.str(), s.sz(), "%02d.%02d %02d:%02d:%02d.%03d"/*"%04d.%02d.%02d %02d:%02d:%02d.%03d%c%02d"*/,
							/*d.year, */d.month, d.mday,
							d.hour, d.min, d.sec, d.ms/*,
							(tzoff < 0 ? '-' : '+'),
							cph::math::abs(tzoff)*/);
					}

					void _cph_inl_pre
					log(bool err, const char *from, const char *lvl, const char *fileline, const char *func, const char *m) _cph_inl_post
					{
						//#define _cph_private_debug_log_simple_timefmt "2013.04.24 19.13.20.123+11"
						#define _cph_private_debug_log_simple_timefmt "04.24 19:13:20.123"
						#define _cph_private_debug_log_simple_fmt "%s %s %s%s%s%s"

						//
						const u4 timestc = sizeof(_cph_private_debug_log_simple_timefmt);
						cph::text::string::tstr8<timestc> timest = {timestc, ""};
						timestamp(timest.str());

						//
						if(!err)
							_cph_sprint("\n"
							            _cph_private_debug_log_simple_fmt,
							            timest.str().s, from, lvl, fileline, func, m);
						else
							_cph_sprinte("\n\n==========================================\n"
							             _cph_private_debug_log_simple_fmt
							             "\n------------------------------------------\n",
							             timest.str().s, from, lvl, fileline, func, m);
					}

					bool _cph_inl_pre
					clog(bool cond, bool print, bool err, const char *from, const char *lvl, const char *fileline, const char *func, const char *m) _cph_inl_post
					{
						if(cond && print)
							log(err, from, lvl, fileline, func, m);

						return cond;
					}
				}
			}
		}
	}
}

#define _cph_slog_imp(...) cph::debug::log_simple::cph__private::log(__VA_ARGS__)
#define _cph_sclog_imp(x, ...) cph::debug::log_simple::cph__private::clog((x), __VA_ARGS__)

//
#ifdef _cph_cfg_private_slogd_off
	#define _cph_private_slogd(x) ((void)0)
#else
	#define _cph_private_slogd(x) _cph_slog_imp(false, "cph", "dbg", "", "", ": " x)
#endif

#ifdef _cph_cfg_private_slogt_off
	#define _cph_private_slogt(x) ((void)0)
#else
	#define _cph_private_slogt(x) _cph_slog_imp(false, "cph", "trc", "", "", ": " x)
#endif

#ifdef _cph_cfg_private_slogi_off
	#define _cph_private_slogi(x) ((void)0)
#else
	#define _cph_private_slogi(x) _cph_slog_imp(false, "cph", "inf", "", "", ": " x)
#endif

#ifdef _cph_cfg_private_slogw_off
	#define _cph_private_slogw(x) ((void)0)
#else
	#define _cph_private_slogw(x) _cph_slog_imp(true,  "cph", "WAR ", _cph_file_line, "", ": " x)
#endif

#ifdef _cph_cfg_private_sloge_off
	#define _cph_private_sloge(x) ((void)0)
#else
	#define _cph_private_sloge(x) _cph_slog_imp(true,  "cph", "ERR ", _cph_file_line, "", ": " x)
#endif

#ifdef _cph_cfg_private_slogf_off
	#define _cph_private_slogf(x) ((void)0)
#else
	#define _cph_private_slogf(x) _cph_slog_imp(true,  "cph", "FAT ", _cph_file_line, "", ": " x)
#endif

//
#ifdef _cph_cfg_private_sclogd_print_off
	#define _cph_private_sclogd_print false
#else
	#define _cph_private_sclogd_print true
#endif

#ifdef _cph_cfg_private_sclogt_print_off
	#define _cph_private_sclogt_print false
#else
	#define _cph_private_sclogt_print true
#endif

#ifdef _cph_cfg_private_sclogi_print_off
	#define _cph_private_sclogi_print false
#else
	#define _cph_private_sclogi_print true
#endif

#ifdef _cph_cfg_private_sclogw_print_off
	#define _cph_private_sclogw_print false
#else
	#define _cph_private_sclogw_print true
#endif

#ifdef _cph_cfg_private_scloge_print_off
	#define _cph_private_scloge_print false
#else
	#define _cph_private_scloge_print true
#endif

#ifdef _cph_cfg_private_sclogf_print_off
	#define _cph_private_sclogf_print false
#else
	#define _cph_private_sclogf_print true
#endif

//
#ifdef _cph_cfg_private_sclogd_off
	#define _cph_private_sclogd(x) ;
#else
	#define _cph_private_sclogd(x) _cph_sclog_imp((x), _cph_private_sclogd_print, false, "cph", "dbg cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_private_sclogt_off
	#define _cph_private_sclogt(x) ;
#else
	#define _cph_private_sclogt(x) _cph_sclog_imp((x), _cph_private_sclogt_print, false, "cph", "trc cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_private_sclogi_off
	#define _cph_private_sclogi(x) ;
#else
	#define _cph_private_sclogi(x) _cph_sclog_imp((x), _cph_private_sclogi_print, false, "cph", "inf cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_private_sclogw_off
	#define _cph_private_sclogw(x) ;
#else
	#define _cph_private_sclogw(x) _cph_sclog_imp((x), _cph_private_sclogw_print, true,  "cph", "WAR cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_private_scloge_off
	#define _cph_private_scloge(x) ;
#else
	#define _cph_private_scloge(x) _cph_sclog_imp((x), _cph_private_scloge_print, true,  "cph", "ERR cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_private_sclogf_off
	#define _cph_private_sclogf(x) ;
#else
	#define _cph_private_sclogf(x) _cph_sclog_imp((x), _cph_private_sclogf_print, true,  "cph", "FAT cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#endif // #ifndef _cph_h_private_debug_log_simple
