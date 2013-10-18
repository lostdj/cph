#pragma once
#ifndef _cph_h_debug_assert_static
#define _cph_h_debug_assert_static

#define _cph_assert_static(condition, text) \
	static_assert(condition, #text)

/*
#define _cph_assert_static(condition, text) \
 	typedef byte static_assertion_##text##_failed[1]; \
 	typedef byte static_assertion_##text##_failed[(condition) ? 1 : 0]
*/

#endif // #ifndef _cph_h_debug_assert_static
