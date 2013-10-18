#pragma once
#ifndef _cph_h_mem
#define _cph_h_mem

#include "./base/base.h"

#include "./private/mem.h"

#include "./debug_callstack_printer.h"

namespace cph
{
	namespace mem
	{
		namespace
		{
			template<typename T>
			T _cph_inl_pre
			pad(T base, u4 alignment) _cph_inl_post
			{
				_cph_private_infunc;

			  return T(((uw)base + (alignment - 1)) & ~(alignment - 1));
			}

			template<typename T>
			T _cph_inl_pre
			pad2(T base) _cph_inl_post
			{
				_cph_private_infunc;

			  return T(pad(base, 2));
			}

			template<typename T>
			T _cph_inl_pre
			pad4(T base) _cph_inl_post
			{
				_cph_private_infunc;

			  return T(pad(base, 4));
			}

			template<typename T>
			T _cph_inl_pre
			pad8(T base) _cph_inl_post
			{
				_cph_private_infunc;

			  return T(pad(base, 8));
			}
		}

		namespace
		{
			//
			template<typename T>
			bool _cph_inl_pre
			aligned(T base, u4 alignment) _cph_inl_post
			{
				_cph_private_infunc;

			  return base == pad(base, alignment);
			}

			template<typename T>
			bool _cph_inl_pre
			aligned2(T base) _cph_inl_post
			{
				_cph_private_infunc;

			  return base == pad2(base);
			}

			template<typename T>
			bool _cph_inl_pre
			aligned4(T base) _cph_inl_post
			{
				_cph_private_infunc;

			  return base == pad4(base);
			}

			template<typename T>
			bool _cph_inl_pre
			aligned8(T base) _cph_inl_post
			{
				_cph_private_infunc;

			  return base == pad8(base);
			}
		}

		namespace
		{
			template<typename T>
			void _cph_inl_pre
			zero(T *ptr, uw bytes) _cph_inl_post
			{
				_cph_private_infunc;

				cph__private::memset((void*)ptr, 0, bytes);
			}

			template<typename T>
			void _cph_inl_pre
			set(T *ptr, byte val, uw bytes) _cph_inl_post
			{
				_cph_private_infunc;

				cph__private::memset((void*)ptr, val, bytes);
			}

			template<typename A, typename B>
			void _cph_inl_pre
			copy(const A *src, B *dst, uw bytes) _cph_inl_post
			{
				_cph_private_infunc;

				cph__private::memcpy((void*)dst, (void*)src, bytes);
			}

			template<typename A, typename B>
			void _cph_inl_pre
			move(const A *src, B *dst, uw bytes) _cph_inl_post
			{
				_cph_private_infunc;

				cph__private::memmove((void*)dst, (void*)src, bytes);
			}
		}

		namespace
		{
			template<typename A, typename B>
			bool _cph_inl_pre
			compare(const A *mem1, const B *mem2, uw bytes) _cph_inl_post
			{
				_cph_private_infunc;

				return cph__private::memcmp((void*)mem1, (void*)mem2, bytes) == false;
			}

			template<typename T>
			T* _cph_inl_pre
			find(const T *ptr, byte val, uw bytes)
			{
				_cph_private_infunc;

				return (T*)cph__private::memchr((void*)ptr, val, bytes);
			}

			template<typename T>
			T* _cph_inl_pre
			find(const T *ptr, byte val)
			{
				_cph_private_infunc;

				return find(ptr, val, ~(uw)0);
			}

			template<typename T>
			uw _cph_inl_pre
			len(const T *ptr, byte val)
			{
				_cph_private_infunc;

				T* r = find(ptr, val);

				return r ? (uw)r - (uw)ptr : 0;
			}
		}
	}
}

#endif // #ifndef _cph_h_mem
