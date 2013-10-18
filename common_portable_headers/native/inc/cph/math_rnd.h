#pragma once
#ifndef _cph_h_math_rnd
#define _cph_h_math_rnd

#include "./base/base.h"

#include "./math.h"

#include "./debug_callstack_printer.h"

namespace cph
{
	namespace math
	{
		class rnd
		{
		public:
			rnd()
			{
				_cph_private_infunc;

				;
			}

			rnd(u8 seed)
			{
				sets(seed);
			}

			_cph_noinl
			void
			sets(u8 seed)
			{
				_cph_private_infunc;

				x = 362436;
				y = 15;

				// if(!seed)
				// 	seed = getSeed();

				u4 j = (u4)(seed & 0xFFFFFFFF);

				for(u4 i = 0; i < 16; i++)
				{
					j ^= j << 13;
					j ^= j >> 17;
					j ^= j << 5;
					z[i] = j;
				}

				z[15] = (u4)(seed ^ (seed >> 32));
			}

			_cph_noinl
			u4
			next()
			{
				_cph_private_infunc;

				u4 o, r = 0xFFFFFFFE;
				u8 t, a = 487198574;

				y = (y + 1) & 15;
				t = a * z[y] + x;

				x = (u4)(t >> 32);
				o = (u4)(t + x);

				if(o < x)
				{
					++o;
					++x;
				}

				return (z[y] = r - o);
			}

			s4
			get()
			{
				_cph_private_infunc;

				return static_cast<s4>(next());
			}

			s4
			get(u4 max)
			{
				_cph_private_infunc;

				return static_cast<s4>(next() / 4294967296.0 * max);
			}

			s4
			get(s4 min, s4 max)
			{
				_cph_private_infunc;

				if(min > max)
					min = max - 1;

				return (min + static_cast<s4>(next() / 4294967296.0 * (max - min)));
			}

			f8
			flt()
			{
				_cph_private_infunc;

				return get() / 4294967296.0;
			}

			f8
			flt(f8 min, f8 max)
			{
				_cph_private_infunc;

				return flt() * (max - min) + min;
			}

			// Not thread-safe.
			// Returns something between ~0.0 and ~1.0.
			_cph_noinl
			f8
			gauss()
			{
				_cph_private_infunc;

				double range = 0.09;
				double center = 0.5;

				double r;
				{
					// +stolen Apache Harmony luni
					if(havenextgauss)
					{
						havenextgauss = false;
						r = nextgauss;
					}
					else
					{
						f8 v1, v2, s;
						do
						{
							v1 = 2 * flt() - 1;
							v2 = 2 * flt() - 1;
							s = v1 * v1 + v2 * v2;
						} while (s >= 1);
						double norm = sqrt(-2 * log(s) / s);
						nextgauss = v2 * norm;
						havenextgauss = true;
						r = v1 * norm;
					}
					// -stolen
				}

				return r * range + center;
			}

			f8
			gauss(double min, double max)
			{
				_cph_private_infunc;

				return gauss() * (max - min) + min;
			}

		private:
			f8 nextgauss;

			u4 x;
			u4 y;
			u4 z[16];

			b1 havenextgauss;
		};
	}
}

#endif // #ifndef _cph_h_math_rnd
