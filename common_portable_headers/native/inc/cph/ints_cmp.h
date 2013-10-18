#pragma once
#ifndef _cph_h_ints_cmp
#define _cph_h_ints_cmp

#include "./base/base.h"

namespace cph
{
	namespace ints
	{
		namespace cmp
		{
			namespace
			{
				#if _cph_cc_msc
					#pragma warning(push)
					#pragma warning(disable: 4018) // signed/unsigned mismatch level 3
					#pragma warning(disable: 4389) // signed/unsigned mismatch level 4
				#elif _cph_cc_gnu
					#pragma GCC diagnostic push
					#pragma GCC diagnostic ignored "-Wsign-compare"
				#endif

				//
				bool _cph_inl_pre eq(s1 s, u1 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s1 s, u2 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s1 s, u4 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s1 s, u8 u) _cph_inl_post {return s < 0 ? false : s == u;}

				bool _cph_inl_pre eq(s2 s, u1 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s2 s, u2 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s2 s, u4 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s2 s, u8 u) _cph_inl_post {return s < 0 ? false : s == u;}		

				bool _cph_inl_pre eq(s4 s, u1 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s4 s, u2 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s4 s, u4 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s4 s, u8 u) _cph_inl_post {return s < 0 ? false : s == u;}

				bool _cph_inl_pre eq(s8 s, u1 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s8 s, u2 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s8 s, u4 u) _cph_inl_post {return s < 0 ? false : s == u;}
				bool _cph_inl_pre eq(s8 s, u8 u) _cph_inl_post {return s < 0 ? false : s == u;}

				//
				bool _cph_inl_pre ne(s1 s, u1 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s1 s, u2 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s1 s, u4 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s1 s, u8 u) _cph_inl_post {return s < 0 ? true : s != u;}

				bool _cph_inl_pre ne(s2 s, u1 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s2 s, u2 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s2 s, u4 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s2 s, u8 u) _cph_inl_post {return s < 0 ? true : s != u;}		

				bool _cph_inl_pre ne(s4 s, u1 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s4 s, u2 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s4 s, u4 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s4 s, u8 u) _cph_inl_post {return s < 0 ? true : s != u;}

				bool _cph_inl_pre ne(s8 s, u1 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s8 s, u2 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s8 s, u4 u) _cph_inl_post {return s < 0 ? true : s != u;}
				bool _cph_inl_pre ne(s8 s, u8 u) _cph_inl_post {return s < 0 ? true : s != u;}

				//
				bool _cph_inl_pre gt(s1 s, u1 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s1 s, u2 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s1 s, u4 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s1 s, u8 u) _cph_inl_post {return s < 0 ? false : s > u;}

				bool _cph_inl_pre gt(s2 s, u1 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s2 s, u2 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s2 s, u4 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s2 s, u8 u) _cph_inl_post {return s < 0 ? false : s > u;}		

				bool _cph_inl_pre gt(s4 s, u1 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s4 s, u2 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s4 s, u4 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s4 s, u8 u) _cph_inl_post {return s < 0 ? false : s > u;}

				bool _cph_inl_pre gt(s8 s, u1 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s8 s, u2 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s8 s, u4 u) _cph_inl_post {return s < 0 ? false : s > u;}
				bool _cph_inl_pre gt(s8 s, u8 u) _cph_inl_post {return s < 0 ? false : s > u;}

				//
				bool _cph_inl_pre lt(s1 s, u1 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s1 s, u2 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s1 s, u4 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s1 s, u8 u) _cph_inl_post {return s < 0 ? true : s < u;}

				bool _cph_inl_pre lt(s2 s, u1 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s2 s, u2 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s2 s, u4 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s2 s, u8 u) _cph_inl_post {return s < 0 ? true : s < u;}		

				bool _cph_inl_pre lt(s4 s, u1 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s4 s, u2 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s4 s, u4 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s4 s, u8 u) _cph_inl_post {return s < 0 ? true : s < u;}

				bool _cph_inl_pre lt(s8 s, u1 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s8 s, u2 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s8 s, u4 u) _cph_inl_post {return s < 0 ? true : s < u;}
				bool _cph_inl_pre lt(s8 s, u8 u) _cph_inl_post {return s < 0 ? true : s < u;}

				//
				bool _cph_inl_pre ge(s1 s, u1 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s1 s, u2 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s1 s, u4 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s1 s, u8 u) _cph_inl_post {return s < 0 ? false : s >= u;}

				bool _cph_inl_pre ge(s2 s, u1 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s2 s, u2 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s2 s, u4 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s2 s, u8 u) _cph_inl_post {return s < 0 ? false : s >= u;}		

				bool _cph_inl_pre ge(s4 s, u1 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s4 s, u2 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s4 s, u4 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s4 s, u8 u) _cph_inl_post {return s < 0 ? false : s >= u;}

				bool _cph_inl_pre ge(s8 s, u1 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s8 s, u2 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s8 s, u4 u) _cph_inl_post {return s < 0 ? false : s >= u;}
				bool _cph_inl_pre ge(s8 s, u8 u) _cph_inl_post {return s < 0 ? false : s >= u;}

				//
				bool _cph_inl_pre le(s1 s, u1 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s1 s, u2 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s1 s, u4 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s1 s, u8 u) _cph_inl_post {return s < 0 ? true : s <= u;}

				bool _cph_inl_pre le(s2 s, u1 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s2 s, u2 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s2 s, u4 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s2 s, u8 u) _cph_inl_post {return s < 0 ? true : s <= u;}		

				bool _cph_inl_pre le(s4 s, u1 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s4 s, u2 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s4 s, u4 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s4 s, u8 u) _cph_inl_post {return s < 0 ? true : s <= u;}

				bool _cph_inl_pre le(s8 s, u1 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s8 s, u2 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s8 s, u4 u) _cph_inl_post {return s < 0 ? true : s <= u;}
				bool _cph_inl_pre le(s8 s, u8 u) _cph_inl_post {return s < 0 ? true : s <= u;}

				//
				//
				//

				//
				bool _cph_inl_pre eq(u1 u, s1 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u2 u, s1 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u4 u, s1 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u8 u, s1 s) _cph_inl_post {return s < 0 ? false : u == s;}

				bool _cph_inl_pre eq(u1 u, s2 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u2 u, s2 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u4 u, s2 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u8 u, s2 s) _cph_inl_post {return s < 0 ? false : u == s;}		

				bool _cph_inl_pre eq(u1 u, s4 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u2 u, s4 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u4 u, s4 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u8 u, s4 s) _cph_inl_post {return s < 0 ? false : u == s;}

				bool _cph_inl_pre eq(u1 u, s8 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u2 u, s8 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u4 u, s8 s) _cph_inl_post {return s < 0 ? false : u == s;}
				bool _cph_inl_pre eq(u8 u, s8 s) _cph_inl_post {return s < 0 ? false : u == s;}

				//
				bool _cph_inl_pre ne(u1 u, s1 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u2 u, s1 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u4 u, s1 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u8 u, s1 s) _cph_inl_post {return s < 0 ? true : u != s;}

				bool _cph_inl_pre ne(u1 u, s2 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u2 u, s2 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u4 u, s2 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u8 u, s2 s) _cph_inl_post {return s < 0 ? true : u != s;}		

				bool _cph_inl_pre ne(u1 u, s4 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u2 u, s4 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u4 u, s4 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u8 u, s4 s) _cph_inl_post {return s < 0 ? true : u != s;}

				bool _cph_inl_pre ne(u1 u, s8 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u2 u, s8 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u4 u, s8 s) _cph_inl_post {return s < 0 ? true : u != s;}
				bool _cph_inl_pre ne(u8 u, s8 s) _cph_inl_post {return s < 0 ? true : u != s;}

				//
				bool _cph_inl_pre gt(u1 u, s1 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u2 u, s1 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u4 u, s1 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u8 u, s1 s) _cph_inl_post {return s < 0 ? true : u > s;}

				bool _cph_inl_pre gt(u1 u, s2 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u2 u, s2 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u4 u, s2 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u8 u, s2 s) _cph_inl_post {return s < 0 ? true : u > s;}		

				bool _cph_inl_pre gt(u1 u, s4 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u2 u, s4 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u4 u, s4 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u8 u, s4 s) _cph_inl_post {return s < 0 ? true : u > s;}

				bool _cph_inl_pre gt(u1 u, s8 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u2 u, s8 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u4 u, s8 s) _cph_inl_post {return s < 0 ? true : u > s;}
				bool _cph_inl_pre gt(u8 u, s8 s) _cph_inl_post {return s < 0 ? true : u > s;}

				//
				bool _cph_inl_pre lt(u1 u, s1 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u2 u, s1 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u4 u, s1 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u8 u, s1 s) _cph_inl_post {return s < 0 ? false : u < s;}

				bool _cph_inl_pre lt(u1 u, s2 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u2 u, s2 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u4 u, s2 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u8 u, s2 s) _cph_inl_post {return s < 0 ? false : u < s;}		

				bool _cph_inl_pre lt(u1 u, s4 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u2 u, s4 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u4 u, s4 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u8 u, s4 s) _cph_inl_post {return s < 0 ? false : u < s;}

				bool _cph_inl_pre lt(u1 u, s8 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u2 u, s8 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u4 u, s8 s) _cph_inl_post {return s < 0 ? false : u < s;}
				bool _cph_inl_pre lt(u8 u, s8 s) _cph_inl_post {return s < 0 ? false : u < s;}

				//
				bool _cph_inl_pre ge(u1 u, s1 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u2 u, s1 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u4 u, s1 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u8 u, s1 s) _cph_inl_post {return s < 0 ? true : u >= s;}

				bool _cph_inl_pre ge(u1 u, s2 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u2 u, s2 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u4 u, s2 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u8 u, s2 s) _cph_inl_post {return s < 0 ? true : u >= s;}		

				bool _cph_inl_pre ge(u1 u, s4 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u2 u, s4 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u4 u, s4 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u8 u, s4 s) _cph_inl_post {return s < 0 ? true : u >= s;}

				bool _cph_inl_pre ge(u1 u, s8 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u2 u, s8 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u4 u, s8 s) _cph_inl_post {return s < 0 ? true : u >= s;}
				bool _cph_inl_pre ge(u8 u, s8 s) _cph_inl_post {return s < 0 ? true : u >= s;}

				//
				bool _cph_inl_pre le(u1 u, s1 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u2 u, s1 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u4 u, s1 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u8 u, s1 s) _cph_inl_post {return s < 0 ? false : u <= s;}

				bool _cph_inl_pre le(u1 u, s2 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u2 u, s2 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u4 u, s2 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u8 u, s2 s) _cph_inl_post {return s < 0 ? false : u <= s;}		

				bool _cph_inl_pre le(u1 u, s4 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u2 u, s4 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u4 u, s4 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u8 u, s4 s) _cph_inl_post {return s < 0 ? false : u <= s;}

				bool _cph_inl_pre le(u1 u, s8 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u2 u, s8 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u4 u, s8 s) _cph_inl_post {return s < 0 ? false : u <= s;}
				bool _cph_inl_pre le(u8 u, s8 s) _cph_inl_post {return s < 0 ? false : u <= s;}

				#if _cph_cc_msc
					#pragma warning(pop)
				#elif _cph_cc_gnu
					#pragma GCC diagnostic pop
				#endif
			}
		}
	}
}

#endif // #ifndef _cph_h_ints_cmp
