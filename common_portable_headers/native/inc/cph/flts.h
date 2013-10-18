#pragma once
#ifndef _cph_h_flts
#define _cph_h_flts

#include "./base/base.h"

#include "./private/flts.h"

#include "./debug_callstack_printer.h"

namespace cph
{
	namespace flts
	{
		namespace
		{
			u4 _cph_inl_pre
			to_bits(f4 f) _cph_inl_post
			{
				_cph_private_infunc;

				u4 bits;

				byte *s = (byte*)&f;
				byte *d = (byte*)&bits;

				d[0] = s[0];
				d[1] = s[1];
				d[2] = s[2];
				d[3] = s[3];

				return bits;
			}

			f4 _cph_inl_pre
			from_bits(u4 bits) _cph_inl_post
			{
				_cph_private_infunc;

				f4 f;

				byte *s = (byte*)&bits;
				byte *d = (byte*)&f;

				d[0] = s[0];
				d[1] = s[1];
				d[2] = s[2];
				d[3] = s[3];

				return f;
			}

			u8 _cph_inl_pre
			to_bits(f8 f) _cph_inl_post
			{
				_cph_private_infunc;

				u8 bits;

				byte *s = (byte*)&f;
				byte *d = (byte*)&bits;

				d[0] = s[0];
				d[1] = s[1];
				d[2] = s[2];
				d[3] = s[3];
				d[4] = s[4];
				d[5] = s[5];
				d[6] = s[6];
				d[7] = s[7];

				return bits;
			}

			f8 _cph_inl_pre
			from_bits(u8 bits) _cph_inl_post
			{
				_cph_private_infunc;

				f8 f;

				byte *s = (byte*)&bits;
				byte *d = (byte*)&f;

				d[0] = s[0];
				d[1] = s[1];
				d[2] = s[2];
				d[3] = s[3];
				d[4] = s[4];
				d[5] = s[5];
				d[6] = s[6];
				d[7] = s[7];

				return f;
			}
		}

		namespace
		{
			// Breaks value into two parts: the integer part
			// (stored in the object pointed by intPart)
			// and the fractional part (returned by the function).
			f8 _cph_inl_pre
			modf(f8 val, f8 *intpart) _cph_inl_post {return cph__private::modf(val, intpart);}

			// Breaks the floating point number value into its binary
			// significand (a floating point value between 0.5(included)
			// and 1.0(excluded)) and an integral exponent for 2.
			f4 _cph_inl_pre
			frexp(f4 val, s4 *exp) _cph_inl_post {return cph__private::frexpf(val, exp);}
			f8 _cph_inl_pre
			frexp(f8 val, s4 *exp) _cph_inl_post {return cph__private::frexp(val, exp);}

			// Returns the largest integral value that is not greater than value.
			f4 _cph_inl_pre
			floor(f4 val) _cph_inl_post {return cph__private::floorf(val);}
			f8 _cph_inl_pre
			floor(f8 val) _cph_inl_post {return cph__private::floor(val);}

			// Returns the smallest integral value that is not less than value.
			f4 _cph_inl_pre
			ceil(f4 val) _cph_inl_post {return cph__private::ceilf(val);}
			f8 _cph_inl_pre
			ceil(f8 val) _cph_inl_post {return cph__private::ceil(val);}

			// Computes nearest integer not greater in magnitude than val.
			f4 _cph_inl_pre
			trunc(f4 val) _cph_inl_post {return cph__private::truncf(val);}
			f8 _cph_inl_pre
			trunc(f8 val) _cph_inl_post {return cph__private::trunc(val);}

			// TODO: C99's fpclassify().
		}

		namespace
		{
			// Rounds a value to the nearest integral value.
			f8 _cph_inl_pre
			round(f8 val) _cph_inl_post {return cph__private::round(val);}

			// Rounds a value to to a specified number of fractional digits.
			f8 _cph_inl_pre
			round(f8 val, byte digits) _cph_inl_post {return cph__private::round(val, digits);}

			// Rounds a value to to the nearest integer. A parameter
			// specifies how to round the value if it is midway
			// between two other numbers: to even / away from zero.
			f8 _cph_inl_pre
			round(f8 val, bool toeven) _cph_inl_post {return cph__private::round(val, toeven);}

			// Rounds a value to the specified number of fractional digits.
			// A parameter specifies how to round the value if it is
			// midway between two other numbers: to even / away from zero.
			f8 _cph_inl_pre
			round(f8 val, byte digits, bool toeven) _cph_inl_post {return cph__private::round(val, digits, toeven);}
		}
	}
}

#endif // #ifndef _cph_h_flts
