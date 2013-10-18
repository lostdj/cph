#pragma once
#ifndef _cph_h_private_flts
#define _cph_h_private_flts

#include "./../base/base.h"

#include "./../math.h"

#include "./debug_callstack_printer.h"

namespace cph
{
	namespace flts
	{
		namespace cph__private
		{
			namespace
			{
				extern "C"
				{
					extern f8 modf(f8, f8*);

					extern f4 frexpf(f4, int*);
					extern f8 frexp(f8, int*);

					extern f4 floorf(f4);
					extern f8 floor(f8);

					extern f4 ceilf(f4);
					extern f8 ceil(f8);

					extern f4 truncf(f4);
					extern f8 trunc(f8);
				}
			}

			namespace
			{
				// +stolen Mono BCL
				_cph_noinl f8 round(f8 value)
				{
					_cph_private_infunc;

					f8 intPart = floor(value), decPart = value - intPart;

					return
						((((decPart == 0.5) && ((2.0 * ((intPart / 2.0) - floor(intPart / 2.0))) != 0.0)) || (decPart > 0.5)) ? ++intPart : intPart);
				}

				#if _cph_cc_msc && _cph_cc_msc_msvcrt_dll
					#if _cph_arch_32
						extern "C" double *_imp___HUGE;
						static double CPH_HUGE_VAL = *_imp___HUGE;
					#elif _cph_arch_64
						extern "C" double *__imp__HUGE;
						static double CPH_HUGE_VAL = *__imp__HUGE;
					#endif
				#elif _cph_cc_msc && _cph_cc_msc_msvcrt_static
					extern "C" double _HUGE;
					static double CPH_HUGE_VAL = _HUGE;
				#endif
				_cph_noinl f8 round(f8 value, byte digits, bool toeven)
				{
					_cph_private_infunc;

					#if _cph_cc_mingw
						extern double *__imp__HUGE;
						static double CPH_HUGE_VAL = *__imp__HUGE;
					#elif _cph_cc_gnu
						static double CPH_HUGE_VAL = __builtin_huge_val();
					#endif

					f8 intPart, decPart, p;

					if(value == CPH_HUGE_VAL)
						return CPH_HUGE_VAL;
					elif(value == -CPH_HUGE_VAL)
						return -CPH_HUGE_VAL;
					elif(!digits)
						return cph::flts::cph__private::round(value);

					p = cph::math::pow(10, digits);
					decPart = modf(value, &intPart);
					decPart *= 1000000000000000ULL;

					if(!toeven && decPart > 0)
						decPart = ceil(decPart);
					else
						decPart = floor(decPart);

					decPart /= (1000000000000000ULL / p);

					if(!toeven)
					{
						if(decPart > 0)
							decPart = floor(decPart + 0.5);
						else
							decPart = ceil(decPart - 0.5);
					}
					else
					{
						decPart = cph::flts::cph__private::round(decPart);
					}

					decPart /= p;

					return cph::flts::cph__private::round((intPart + decPart) * p) / p;
				}

				_cph_noinl f8 round(f8 value, byte digits)
				{
					_cph_private_infunc;

					return cph::flts::cph__private::round(value, digits, true);
				}

				_cph_noinl f8 round(f8 value, bool toeven)
				{
					_cph_private_infunc;

					if(toeven)
						return cph::flts::cph__private::round(value);
					else
						return (value > 0 ? floor(value + 0.5) : ceil(value - 0.5));

					return value;
				}
				// -stolen
			}
		}
	}
}

#endif // #ifndef _cph_h_private_flts
