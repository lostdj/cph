#pragma once
#ifndef _cph_h_private_debug_print_simple
#define _cph_h_private_debug_print_simple

#include "./../base/base.h"

namespace cph
{
	namespace debug
	{
		namespace print_simple
		{
			namespace cph__private
			{
				namespace
				{
					extern "C"
					{
						extern int printf(const char*, ...);
					}

					#if _cph_cc_msc && _cph_os_win
						struct FILE
						{
							char *_ptr;
							int   _cnt;
							char *_base;
							int   _flag;
							int   _file;
							int   _charbuf;
							int   _bufsiz;
							char *_tmpfname;
						};

						#if _cph_cc_msc_msvcrt_dll
							extern "C"/*_cph_dll_imp*/ FILE * __cdecl __iob_func(void);
						#elif _cph_cc_msc_msvcrt_static
							extern "C" FILE * __cdecl __iob_func(void);
						#endif

						#define _cph_private_debug_print_simple_stdout (&cph::debug::print_simple::cph__private::__iob_func()[1])
						#define _cph_private_debug_print_simple_stderr (&cph::debug::print_simple::cph__private::__iob_func()[2])
					#elif _cph_cc_mingw
						struct FILE
						{
							char*	_ptr;
							int	_cnt;
							char*	_base;
							int	_flag;
							int	_file;
							int	_charbuf;
							int	_bufsiz;
							char*	_tmpfname;
						};

						//extern FILE (*_imp___iob)[];
						//#define _cph_private_debug_print_simple__iob (*cph::debug::print_simple::cph__private::_imp___iob)
						extern "C" FILE _iob[];
						#define _cph_private_debug_print_simple__iob _iob

						#define _cph_private_debug_print_simple_stdout (&cph::debug::print_simple::cph__private::_cph_private_debug_print_simple__iob[1/*STDOUT_FILENO*/])
						#define _cph_private_debug_print_simple_stderr (&cph::debug::print_simple::cph__private::_cph_private_debug_print_simple__iob[2/*STDERR_FILENO*/])
					#else
						#error "Fixme."
					#endif

					extern "C"
					{
						extern int fprintf(FILE*, const char*, ...);
						extern int fflush(FILE*);
					}
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_private_debug_print_simple
