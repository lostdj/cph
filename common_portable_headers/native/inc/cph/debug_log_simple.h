#pragma once
#ifndef _cph_h_debug_log_simple
#define _cph_h_debug_log_simple

#include "./base/base.h"

#include "./private/debug_log_simple.h"

#include "./debug_print_simple.h"

//
#ifdef _cph_cfg_slogd_off
	#define _cph_slogd(x) ((void)0)
#else
	#define _cph_slogd(x) _cph_slog_imp(false, "usr", "dbg", "", "", ": " x)
#endif

#ifdef _cph_cfg_slogt_off
	#define _cph_slogt(x) ((void)0)
#else
	#define _cph_slogt(x) _cph_slog_imp(false, "usr", "trc", "", "", ": " x)
#endif

#ifdef _cph_cfg_slogi_off
	#define _cph_slogi(x) ((void)0)
#else
	#define _cph_slogi(x) _cph_slog_imp(false, "usr", "inf", "", "", ": " x)
#endif

#ifdef _cph_cfg_slogw_off
	#define _cph_slogw(x) ((void)0)
#else
	#define _cph_slogw(x) _cph_slog_imp(true,  "usr", "WAR ", _cph_file_line, "", ": " x)
#endif

#ifdef _cph_cfg_sloge_off
	#define _cph_sloge(x) ((void)0)
#else
	#define _cph_sloge(x) _cph_slog_imp(true,  "usr", "ERR ", _cph_file_line, "", ": " x)
#endif

#ifdef _cph_cfg_slogf_off
	#define _cph_slogf(x) ((void)0)
#else
	#define _cph_slogf(x) _cph_slog_imp(true,  "usr", "FAT ", _cph_file_line, "", ": " x)
#endif

//
#ifdef _cph_cfg_sclogd_off
	#define _cph_sclogd(x) ;
#elif defined(_cph_cfg_sclogd_print_off)
	#define _cph_sclogd(x) _cph_sclog_imp((x), false, false, "usr", "dbg cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#else
	#define _cph_sclogd(x) _cph_sclog_imp((x), true, false, "usr", "dbg cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_sclogt_off
	#define _cph_sclogt(x) ;
#elif defined(_cph_cfg_sclogt_print_off)
	#define _cph_sclogt(x) _cph_sclog_imp((x), false, false, "usr", "trc cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#else
	#define _cph_sclogt(x) _cph_sclog_imp((x), true, false, "usr", "trc cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_sclogi_off
	#define _cph_sclogi(x) ;
#elif defined(_cph_cfg_sclogi_print_off)
	#define _cph_sclogi(x) _cph_sclog_imp((x), false, false, "usr", "inf cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#else
	#define _cph_sclogi(x) _cph_sclog_imp((x), true, false, "usr", "inf cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_sclogw_off
	#define _cph_sclogw(x) ;
#elif defined(_cph_cfg_sclogw_print_off)
	#define _cph_sclogw(x) _cph_sclog_imp((x), false, true,  "usr", "WAR cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#else
	#define _cph_sclogw(x) _cph_sclog_imp((x), true, true,  "usr", "WAR cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_scloge_off
	#define _cph_scloge(x) ;
#elif defined(_cph_cfg_scloge_print_off)
	#define _cph_scloge(x) _cph_sclog_imp((x), false, true,  "usr", "ERR cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#else
	#define _cph_scloge(x) _cph_sclog_imp((x), true, true,  "usr", "ERR cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#ifdef _cph_cfg_sclogf_off
	#define _cph_sclogf(x) ;
#elif defined(_cph_cfg_sclogf_print_off)
	#define _cph_sclogf(x) _cph_sclog_imp((x), false, true,  "usr", "FAT cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#else
	#define _cph_sclogf(x) _cph_sclog_imp((x), true, true,  "usr", "FAT cond in ", _cph_file_line, "", ": " _cph_quotemac(x))
#endif

#endif // #ifndef _cph_h_private_debug_log_simple
