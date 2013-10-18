#pragma once
#ifndef _cph_h_callstack_printer
#define _cph_h_callstack_printer

#include "./base/base.h"

#include "./private/debug_callstack_printer.h"

#ifdef _cph_cfg_callstack_printer_on
	#define _cph_infunc cph::debug::callstack_printer::cph__private::cpusr ____hidden__callstack_printer(_cph_funcname)
#else
	#define _cph_infunc
#endif

#endif // #ifndef _cph_h_callstack_printer
