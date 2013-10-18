#pragma once
#ifndef _cph_h_bits
#define _cph_h_bits

#include "./base/base.h"

#include "./private/bits.h"

#include "./math.h"

#include "./debug_callstack_printer.h"

namespace cph
{
	namespace bits
	{
		namespace
		{
			template<typename T>
			bool _cph_inl_pre
			get(T n, u1 pos) _cph_inl_post
			{
				_cph_private_infunc;

				return n & (1 << pos);
			}

			template<typename T>
			T _cph_inl_pre
			get(T n, u1 pos, u1 sz) _cph_inl_post
			{
				_cph_private_infunc;

				T n1 = n >> pos;			
				T n2 = T(cph::math::pow(2, sz) - 1);

				return n1 & n2;
			}

			template<typename T>
			T _cph_inl_pre
			set(T n, u1 pos, bool val) _cph_inl_post
			{
				_cph_private_infunc;

				if(val)
					n |= T(1) << pos;
				else
					n &= ~(T(1) << pos);

				return n;
			}

			template<typename T>
			T _cph_inl_pre
			set(T n, u1 pos, u1 sz, T val) _cph_inl_post
			{
				_cph_private_infunc;

				T n1 = T(cph::math::pow(2, sz) - 1);
				n1 = n1 << pos;
				n = n & ~n1;

				val = val << pos;

				return n | val;
			}
		}

		namespace
		{
			template<typename T>
			T _cph_inl_pre
			rotl(T n, u4 c) _cph_inl_post
			{
				_cph_private_infunc;

				return (n << c) | (n >> (sizeof(T) * 8 - c));
			}

			template<typename T>
			T _cph_inl_pre
			rotr(T n, u4 c) _cph_inl_post
			{
				_cph_private_infunc;

				return (n >> c) | (n << (sizeof(T) * 8 - c));
			}
		}

		namespace
		{
			// Index of the most significant 1-bit.
			u4 _cph_inl_pre
			msindex(u4 n, bool *zero = null) _cph_inl_post
			{
				_cph_private_infunc;

				if(!n)
					return (zero ? *zero = true, 0 : 0);

				u4 index = 0;

				#if _cph_cc_msc
					cph__private::_BitScanReverse((unsigned long*)&index, n);
				#elif _cph_cc_gnu
					index = __builtin_clzl(n);
					index = sizeof(u4) * 8 - index - 1;
				#endif

				return index;
			}

			u4 _cph_inl_pre
			msindex(u8 n, bool *zero = null) _cph_inl_post
			{
				_cph_private_infunc;

				if(!n)
					return (zero ? *zero = true, 0 : 0);

				u4 index = 0;

				#if _cph_cc_msc
					#if _cph_arch_32 && _cph_bo_le
						if(((u4*)&n)[1])
						{
							cph__private::_BitScanReverse((unsigned long*)&index, ((u4*)&n)[1]);
							index += sizeof(u4) * 8;
						}
						else
						{
							cph__private::_BitScanReverse((unsigned long*)&index, ((u4*)&n)[0]);
						}
					#elif _cph_arch_64
						cph__private::_BitScanReverse64((unsigned long*)&index, n);
					#else
						#error "Fixme."
					#endif

				#elif _cph_cc_gnu
					index = __builtin_clzll(n);
					index = sizeof(u8) * 8 - index - 1;
				#endif

				return index;
			}
		}

		namespace
		{
			// Index of the least significant 1-bit.
			u4 _cph_inl_pre
			lsindex(u4 n, bool *zero = null) _cph_inl_post
			{
				_cph_private_infunc;

				if(!n)
					return (zero ? *zero = true, 0 : 0);

				u4 index = 0;

				#if _cph_cc_msc
					cph__private::_BitScanForward((unsigned long*)&index, n);
				#elif _cph_cc_gnu
					index = __builtin_ctzl(n);
				#endif

				return index;
			}

			u4 _cph_inl_pre
			lsindex(u8 n, bool *zero = null) _cph_inl_post
			{
				_cph_private_infunc;

				if(!n)
					return (zero ? *zero = true, 0 : 0);

				u4 index = 0;

				#if _cph_cc_msc
					#if _cph_arch_32 && _cph_bo_le
						if(((u4*)&n)[0])
						{
							cph__private::_BitScanForward((unsigned long*)&index, ((u4*)&n)[0]);
						}
						else
						{
							cph__private::_BitScanForward((unsigned long*)&index, ((u4*)&n)[1]);
							index += sizeof(u4) * 8;
						}
					#elif _cph_arch_64
						cph__private::_BitScanForward64((unsigned long*)&index, n);
					#else
						#error "Fixme."
					#endif
				#elif _cph_cc_gnu
					index = __builtin_ctzll(n);
				#endif

				return index;
			}
		}

		namespace
		{
			u4 _cph_inl_pre
			leading_zeros(u4 n, bool *zero = null) _cph_inl_post
			{
				_cph_private_infunc;

				if(!n)
					return (zero ? *zero = true, 0 : 0);

				u4 z = 0;

				#if _cph_cc_msc
					cph__private::_BitScanReverse((unsigned long*)&z, n);
					z = sizeof(u4) * 8 - (z + 1);
				#elif _cph_cc_gnu
					z = __builtin_clzl(n);
				#endif

				return z;
			}

			u4 _cph_inl_pre
			leading_zeros(u8 n, bool *zero = null) _cph_inl_post
			{
				_cph_private_infunc;

				if(!n)
					return (zero ? *zero = true, 0 : 0);

				u4 z = 0;

				#if _cph_cc_msc
					#if _cph_arch_32 && _cph_bo_le
						if(((u4*)&n)[1])
						{
							cph__private::_BitScanReverse((unsigned long*)&z, ((u4*)&n)[1]);
							z = sizeof(u4) * 8 - z - 1;
						}
						else
						{
							cph__private::_BitScanReverse((unsigned long*)&z, ((u4*)&n)[0]);
							z = sizeof(u4) * 8 + sizeof(u4) * 8 - z - 1;
						}
					#elif _cph_arch_64
						cph__private::_BitScanReverse64((unsigned long*)&z, n);
						z = sizeof(u8) * 8 - (z + 1);
					#else
						#error "Fixme."
					#endif
				#elif _cph_cc_gnu
					z = __builtin_clzll(n);
				#endif

				return z;
			}
		}

		namespace
		{
			u4 _cph_inl_pre
			trailing_zeros(u4 n, bool *zero = null) _cph_inl_post
			{
				_cph_private_infunc;

				if(!n)
					return (zero ? *zero = true, 0 : 0);

				u4 z = 0;

				#if _cph_cc_msc
					cph__private::_BitScanForward((unsigned long*)&z, n);
				#elif _cph_cc_gnu
					z = __builtin_ctzl(n);
				#endif

				return z;
			}

			u4 _cph_inl_pre
			trailing_zeros(u8 n, bool *zero = null) _cph_inl_post
			{
				_cph_private_infunc;

				if(!n)
					return (zero ? *zero = true, 0 : 0);

				u4 z = 0;

				#if _cph_cc_msc
					#if _cph_arch_32 && _cph_bo_le
						if(((u4*)&n)[0])
						{
							cph__private::_BitScanForward((unsigned long*)&z, ((u4*)&n)[0]);
						}
						else
						{
							cph__private::_BitScanForward((unsigned long*)&z, ((u4*)&n)[1]);
							z += sizeof(u4) * 8;
						}
					#elif _cph_arch_64
						cph__private::_BitScanForward64((unsigned long*)&z, n);

					#else
						#error "Fixme."
					#endif
				#elif _cph_cc_gnu
					z = __builtin_ctzll(n);
				#endif

				return z;
			}
		}
	}
}

#endif // #ifndef _cph_h_bits
