#pragma once
#ifndef _cph_h_math
#define _cph_h_math

#include "./base/base.h"

#include "./private/math.h"

namespace cph
{
	namespace math
	{
		namespace k
		{
			namespace
			{
				const f8 E  = 2.7182818284590452354;
				const f8 PI = 3.14159265358979323846;

				const f8 deg_in_rad = 57.2957795;
				const f8 rad_in_deg = 0.0174532925;
			}
		}

		namespace
		{
			template<typename T>
			T _cph_inl_pre
			abs(T val) _cph_inl_post {return val <= T(0) ? T(0) - val : val;}

			template<typename T>
			T _cph_inl_pre
			min(T val1, T val2) _cph_inl_post {return val1 <= val2 ? val1 : val2;}

			template<typename T>
			T _cph_inl_pre
			max(T val1, T val2) _cph_inl_post {return val1 >= val2 ? val1 : val2;}

			f4 _cph_inl_pre
			deg2rad(f4 deg) _cph_inl_post {return deg * ((f4)k::PI / 180);}
			f8 _cph_inl_pre
			deg2rad(f8 deg) _cph_inl_post {return deg * (k::PI / 180);}

			f4 _cph_inl_pre
			rad2deg(f4 rad) _cph_inl_post {return rad * (180 / (f4)k::PI);}
			f8 _cph_inl_pre
			rad2deg(f8 rad) _cph_inl_post {return rad * (180 / k::PI);}

			// Computes the E raised to the given power.
			f4 _cph_inl_pre
			exp(f4 pow) _cph_inl_post {return cph__private::expf(pow);}
			f8 _cph_inl_pre
			exp(f8 pow) _cph_inl_post {return cph__private::exp(pow);}

			// Computes 2 raised to the given power.
			f4 _cph_inl_pre
			exp2(f4 pow) _cph_inl_post {return cph__private::exp2f(pow);}
			f8 _cph_inl_pre
			exp2(f8 pow) _cph_inl_post {return cph__private::exp2(pow);}

			// Returns the natural logarithm of value.
			f4 _cph_inl_pre
			log(f4 val) _cph_inl_post {return cph__private::logf(val);}
			f8 _cph_inl_pre
			log(f8 val) _cph_inl_post {return cph__private::log(val);}

			// Computes the base 2 logarithm of val.
			f4 _cph_inl_pre
			log2(f4 val) _cph_inl_post {return cph__private::log2f(val);}
			f8 _cph_inl_pre
			log2(f8 val) _cph_inl_post {return cph__private::log2(val);}

			// Returns the common (base-10) logarithm of value.
			f4 _cph_inl_pre
			log10(f4 val) _cph_inl_post {return cph__private::log10f(val);}
			f8 _cph_inl_pre
			log10(f8 val) _cph_inl_post {return cph__private::log10(val);}

			// Returns base raised to the power exponent: base ^ exponent.
			f4 _cph_inl_pre
			pow(f4 base, f4 exp) _cph_inl_post {return cph__private::powf(base, exp);}
			f8 _cph_inl_pre
			pow(f8 base, s4 exp) _cph_inl_post {return cph__private::pow(base, (f8)exp);}
			f8 _cph_inl_pre
			pow(f8 base, f8 exp) _cph_inl_post {return cph__private::pow(base, exp);}

			u4 _cph_inl_pre
			npo2(u4 val) _cph_inl_post
			{
				--val;
				val |= val>>1;
				val |= val>>2;
				val |= val>>4;
				val |= val>>8;
				val |= val>>16;
				++val;

				return val;
			}

			//
			f4 _cph_inl_pre
			sqrt(f4 val) _cph_inl_post {return cph__private::sqrtf(val);}
			f8 _cph_inl_pre
			sqrt(f8 val) _cph_inl_post {return cph__private::sqrt(val);}

			// Returns the resulting floating point value from multiplying
			// value (the significand) by 2 raised to the power of exponent
			// (the exponent): value * 2 ^ exponent.
			f4 _cph_inl_pre
			ldexp(f4 val, s4 exp) _cph_inl_post {return cph__private::ldexpf(val, exp);}
			f8 _cph_inl_pre
			ldexp(f8 val, s4 exp) _cph_inl_post {return cph__private::ldexp(val, exp);}

			//
			f4 _cph_inl_pre sin(f4 v) _cph_inl_post {return cph__private::sinf(v);}
			f8 _cph_inl_pre sin(f8 v) _cph_inl_post {return cph__private::sin(v);}
			f4 _cph_inl_pre cos(f4 v) _cph_inl_post {return cph__private::cosf(v);}
			f8 _cph_inl_pre cos(f8 v) _cph_inl_post {return cph__private::cos(v);}
			f4 _cph_inl_pre tan(f4 v) _cph_inl_post {return cph__private::tanf(v);}
			f8 _cph_inl_pre tan(f8 v) _cph_inl_post {return cph__private::tan(v);}

			f4 _cph_inl_pre asin(f4 v) _cph_inl_post {return cph__private::asinf(v);}
			f8 _cph_inl_pre asin(f8 v) _cph_inl_post {return cph__private::asin(v);}
			f4 _cph_inl_pre acos(f4 v) _cph_inl_post {return cph__private::acosf(v);}
			f8 _cph_inl_pre acos(f8 v) _cph_inl_post {return cph__private::acos(v);}
			f4 _cph_inl_pre atan(f4 v) _cph_inl_post {return cph__private::atanf(v);}
			f8 _cph_inl_pre atan(f8 v) _cph_inl_post {return cph__private::atan(v);}

			f4 _cph_inl_pre atan(f4 y, f4 x) _cph_inl_post {return cph__private::atan2f(y, x);}
			f8 _cph_inl_pre atan(f8 y, f8 x) _cph_inl_post {return cph__private::atan2(y, x);}

			// Hyperbolic functions.
			f4 _cph_inl_pre hsin(f4 v) _cph_inl_post {return cph__private::sinhf(v);}
			f8 _cph_inl_pre hsin(f8 v) _cph_inl_post {return cph__private::sinh(v);}
			f4 _cph_inl_pre hcos(f4 v) _cph_inl_post {return cph__private::coshf(v);}
			f8 _cph_inl_pre hcos(f8 v) _cph_inl_post {return cph__private::cosh(v);}
			f4 _cph_inl_pre htan(f4 v) _cph_inl_post {return cph__private::tanhf(v);}
			f8 _cph_inl_pre htan(f8 v) _cph_inl_post {return cph__private::tanh(v);}

			f4 _cph_inl_pre hasin(f4 v) _cph_inl_post {return cph__private::asinhf(v);}
			f8 _cph_inl_pre hasin(f8 v) _cph_inl_post {return cph__private::asinh(v);}
			f4 _cph_inl_pre hacos(f4 v) _cph_inl_post {return cph__private::acoshf(v);}
			f8 _cph_inl_pre hacos(f8 v) _cph_inl_post {return cph__private::acosh(v);}
			f4 _cph_inl_pre hatan(f4 v) _cph_inl_post {return cph__private::atanhf(v);}
			f8 _cph_inl_pre hatan(f8 v) _cph_inl_post {return cph__private::atanh(v);}
		}
	}
}

#endif // #ifndef _cph_h_math
