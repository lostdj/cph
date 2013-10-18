#pragma once
#ifndef _cph_h_bits_endian
#define _cph_h_bits_endian

#include "./base/base.h"

#include "./private/bits_endian.h"

namespace cph
{
	namespace bits
	{
		struct endian
		{
			// Always swap.
			typedef cph__private::endian<true> forced;

			// From BE to native.
			typedef cph__private::endian<(bool)_cph_bo_le> frombe;
			// From LE to native.
			typedef cph__private::endian<(bool)_cph_bo_be> fromle;

			// From native to BE.
			typedef cph__private::endian<(bool)_cph_bo_le> tobe;
			// From native to LE.
			typedef cph__private::endian<(bool)_cph_bo_be> tole;
		};
	}
}

#endif // #ifndef _cph_h_bits_endian
