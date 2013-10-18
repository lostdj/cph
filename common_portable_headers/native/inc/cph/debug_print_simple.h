#pragma once
#ifndef _cph_h_debug_print_simple
#define _cph_h_debug_print_simple

#include "./private/debug_print_simple.h"

#define _cph_sprint(...) cph::debug::print_simple::cph__private::printf(__VA_ARGS__), \
                              cph::debug::print_simple::cph__private::fflush(_cph_private_debug_print_simple_stdout)

#define _cph_sprinte(...) cph::debug::print_simple::cph__private::fprintf(_cph_private_debug_print_simple_stderr, __VA_ARGS__), \
                              cph::debug::print_simple::cph__private::fflush(_cph_private_debug_print_simple_stderr)

#endif // #ifndef _cph_h_debug_print_simple
