#pragma once
#ifndef _cph_h_private_bits
#define _cph_h_private_bits

#include "./../base/base.h"

namespace cph
{
	namespace bits
	{
		namespace cph__private
		{
			#if _cph_cc_msc
				extern "C"
				{
					extern unsigned char _BitScanReverse(unsigned long*, unsigned long);
					extern unsigned char _BitScanForward(unsigned long*, unsigned long);

					#if _cph_arch_64
						extern unsigned char _BitScanReverse64(unsigned long*, unsigned __int64);
						extern unsigned char _BitScanForward64(unsigned long*, unsigned __int64);
					#endif
				}

				#pragma intrinsic(_BitScanReverse)
				#pragma intrinsic(_BitScanForward)
				#if _cph_arch_64
					#pragma intrinsic(_BitScanReverse64)
					#pragma intrinsic(_BitScanForward64)
				#endif
			#endif
		}
	}
}

#endif // #ifndef _cph_h_private_bits
