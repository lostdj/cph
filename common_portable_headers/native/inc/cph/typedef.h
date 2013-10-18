#pragma once
#ifndef _cph_h_typedef
#define _cph_h_typedef

#include "./base/base.h"

// Strong typedef.

// +stolen Boost 1.53.0
// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
	#define _cph_typedef(T, D)                                      \
		struct D                                                      \
			: cph::strong_typedef::totally_ordered1< D                  \
			, cph::strong_typedef::totally_ordered2< D, T               \
			> >                                                         \
		{                                                             \
			T t;                                                        \
			/*explicit */D(const T t_) : t((T)t_) {};                   \
			D(){};                                                      \
			D(const D & t_) : t(t_.t){}                                 \
			D & operator=(const D & rhs) { t = (T)rhs.t; return *this;} \
			D & operator=(const T & rhs) { t = (T)rhs; return *this;}   \
			/*operator const T & () const {return t; }*/                \
			operator T & () { return t; }                               \
			bool operator==(const D & rhs) const { return t == rhs.t; } \
			bool operator<(const D & rhs) const { return t < rhs.t; }   \
		}

	namespace cph
	{
		namespace strong_typedef
		{
			template <typename T> class empty_base
			{
				// Helmut Zeisel, empty base class optimization bug with GCC 3.0.0
				#if defined(__GNUC__) && __GNUC__==3 && __GNUC_MINOR__==0 && __GNU_PATCHLEVEL__==0
					bool dummy; 
				#endif
			};

			template <class T, class B = empty_base<T> >
			struct less_than_comparable1 : B
			{
				friend bool operator>(const T& x, const T& y)  { return y < x; }
				friend bool operator<=(const T& x, const T& y) { return !static_cast<bool>(y < x); }
				friend bool operator>=(const T& x, const T& y) { return !static_cast<bool>(x < y); }
			};

			template <class T, class U, class B = empty_base<T> >
			struct less_than_comparable2 : B
			{
				friend bool operator<=(const T& x, const U& y) { return !static_cast<bool>(x > y); }
				friend bool operator>=(const T& x, const U& y) { return !static_cast<bool>(x < y); }
				friend bool operator>(const U& x, const T& y)  { return y < x; }
				friend bool operator<(const U& x, const T& y)  { return y > x; }
				friend bool operator<=(const U& x, const T& y) { return !static_cast<bool>(y < x); }
				friend bool operator>=(const U& x, const T& y) { return !static_cast<bool>(y > x); }
			};

			template <class T, class B = empty_base<T> >
			struct equality_comparable1 : B
			{
				friend bool operator!=(const T& x, const T& y) { return !static_cast<bool>(x == y); }
			};

			template <class T, class U, class B = empty_base<T> >
			struct equality_comparable2 : B
			{
				friend bool operator==(const U& y, const T& x) { return x == y; }
				friend bool operator!=(const U& y, const T& x) { return !static_cast<bool>(x == y); }
				friend bool operator!=(const T& y, const U& x) { return !static_cast<bool>(y == x); }
			};

			template <class T, class B = empty_base<T> >
			struct totally_ordered1
				: less_than_comparable1<T
				, equality_comparable1<T, B
      		> > {};

			template <class T, class U, class B = empty_base<T> >
			struct totally_ordered2
				: less_than_comparable2<T, U
				, equality_comparable2<T, U, B
					> > {};
		}
	}
// -stolen Boost

#endif // #ifndef _cph_h_typedef
