#pragma once
#ifndef _cph_h_private_math
#define _cph_h_private_math

#include "./../base/base.h"

namespace cph
{
	namespace math
	{
		namespace cph__private
		{
			namespace
			{
				extern "C"
				{
					extern f4 expf(f4);
					extern f8 exp(f8);

					extern f4 exp2f(f4);
					extern f8 exp2(f8);

					extern f4 logf(f4);
					extern f8 log(f8);

					extern f4 log2f(f4);
					extern f8 log2(f8);

					extern f4 log10f(f4);
					extern f8 log10(f8);

					extern f4 powf(f4, f4);
					extern f8 pow(f8, f8);

					extern f4 sqrtf(f4);
					extern f8 sqrt(f8);

					extern f4 ldexpf(f4, int);
					extern f8 ldexp(f8, int);

					extern f4 sinf(f4); extern f8 sin(f8);
					extern f4 cosf(f4); extern f8 cos(f8);
					extern f4 tanf(f4); extern f8 tan(f8);

					extern f4 asinf(f4); extern f8 asin(f8);
					extern f4 acosf(f4); extern f8 acos(f8);
					extern f4 atanf(f4); extern f8 atan(f8);

					extern f4 atan2f(f4, f4); extern f8 atan2(f8, f8);

					extern f4 sinhf(f4); extern f8 sinh(f8);
					extern f4 coshf(f4); extern f8 cosh(f8);
					extern f4 tanhf(f4); extern f8 tanh(f8);

					extern f4 asinhf(f4); extern f8 asinh(f8);
					extern f4 acoshf(f4); extern f8 acosh(f8);
					extern f4 atanhf(f4); extern f8 atanh(f8);
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_private_math
