#pragma once
#ifndef _cph_h_debug_log
#define _cph_h_debug_log

#include "./base/base.h"

#include "./private/debug_log.h"

//
#ifdef _cph_cfg_logd_off
	#define _cph_logd(x) ((void)0)
#else
	#define _cph_logd(x) _cph_log_imp(<< "usr dbg: " << x, false)
#endif

#ifdef _cph_cfg_logt_off
	#define _cph_logt(x) ((void)0)
#else
	#define _cph_logt(x) _cph_log_imp(<< "usr trc: " << x, false)
#endif

#ifdef _cph_cfg_logi_off
	#define _cph_logi(x) ((void)0)
#else
	#define _cph_logi(x) _cph_log_imp(<< "usr inf: " << x, false)
#endif

#ifdef _cph_cfg_logw_off
	#define _cph_logw(x) ((void)0)
#else
	#define _cph_logw(x) _cph_log_imp(<< "usr WAR " _cph_file_line ":" << x, true)
#endif

#ifdef _cph_cfg_loge_off
	#define _cph_loge(x) ((void)0)
#else
	#define _cph_loge(x) _cph_log_imp(<< "usr ERR " _cph_file_line ":" << x, true)
#endif

#ifdef _cph_cfg_logf_off
	#define _cph_logf(x) ((void)0)
#else
	#define _cph_logf(x) _cph_log_imp(<< "usr FAT " _cph_file_line ":" << x, true)
#endif

//
#ifdef _cph_cfg_clogd_off
	#define _cph_clogd(x) ;
#elif defined(_cph_cfg_clogd_print_off)
	#define _cph_clogd(n, x) (n)
#else
	#define _cph_clogd(n, x) _cph_clog_imp(n, << "usr dbg cond in: " _cph_file_line ": " _cph_quotemac(n) " ... " << x, false)
#endif

#ifdef _cph_cfg_clogt_off
	#define _cph_clogt(x) ;
#elif defined(_cph_cfg_clogt_print_off)
	#define _cph_clogt(n, x) (n)
#else
	#define _cph_clogt(n, x) _cph_clog_imp(n, << "usr trc cond in: " _cph_file_line ": " _cph_quotemac(n) " ... " << x, false)
#endif

#ifdef _cph_cfg_clogi_off
	#define _cph_clogi(x) ;
#elif defined(_cph_cfg_clogi_print_off)
	#define _cph_clogi(n, x) (n)
#else
	#define _cph_clogi(n, x) _cph_clog_imp(n, << "usr inf cond in: " _cph_file_line ": " _cph_quotemac(n) " ... " << x, false)
#endif

#ifdef _cph_cfg_clogw_off
	#define _cph_clogw(x) ;
#elif defined(_cph_cfg_clogw_print_off)
	#define _cph_clogw(n, x) (n)
#else
	#define _cph_clogw(n, x) _cph_clog_imp(n, << "usr WAR cond in: " _cph_file_line ": " _cph_quotemac(n) " ... " << x, true)
#endif

#ifdef _cph_cfg_cloge_off
	#define _cph_cloge(x) ;
#elif defined(_cph_cfg_cloge_print_off)
	#define _cph_cloge(n, x) (n)
#else
	#define _cph_cloge(n, x) _cph_clog_imp(n, << "usr ERR cond in: " _cph_file_line ": " _cph_quotemac(n) " ... " << x, false)
#endif

#ifdef _cph_cfg_clogf_off
	#define _cph_clogf(x) ;
#elif defined(_cph_cfg_clogf_print_off)
	#define _cph_clogf(n, x) (n)
#else
	#define _cph_clogf(n, x) _cph_clog_imp(n, << "usr FAT cond in: " _cph_file_line ": " _cph_quotemac(n) " ... " << x, false)
#endif

#endif // #ifndef _cph_h_debug_log
