#pragma once
#ifndef _cph_h_private_bits_endian
#define _cph_h_private_bits_endian

#include "./../base/base.h"

#include "./debug_callstack_printer.h"

namespace cph
{
	namespace bits
	{
		namespace cph__private
		{
			template<bool convert>
			class endian
			{
			public:
				static
				u1 _cph_inl_pre
				swap(u1 v) _cph_inl_post
				{
					_cph_private_infunc;

					return v;
				}

				static
				s1 _cph_inl_pre
				swap(s1 v) _cph_inl_post
				{
					_cph_private_infunc;

					return v;
				}

				static
				u2 _cph_inl_pre
				swap(u2 v) _cph_inl_post
				{
					_cph_private_infunc;

					return !convert ? v :
					  (((v >> 8) & 0x00FF) |
					   ((v << 8) & 0xFF00));
				}

				static
				s2 _cph_inl_pre
				swap(s2 v) _cph_inl_post
				{
					_cph_private_infunc;

					return (s2)swap((u2)v);
				}

				static
				u4 _cph_inl_pre
				swap(u4 v) _cph_inl_post
				{
					_cph_private_infunc;

					return !convert ? v :
					  (((v >> 24) & 0x000000FF) |
					   ((v >>  8) & 0x0000FF00) |
					   ((v <<  8) & 0x00FF0000) |
					   ((v << 24) & 0xFF000000));
				}

				static
				s4 _cph_inl_pre
				swap(s4 v) _cph_inl_post
				{
					_cph_private_infunc;

					return (s4)swap((u4)v);
				}

				static
				u8 _cph_inl_pre
				swap(u8 v) _cph_inl_post
				{
					_cph_private_infunc;

					return !convert ? v :
					  (((u8)swap((u4)(v >> 32))) |
					   ((u8)swap((u4)(v & 0xFFFFFFFF)) << 32));
					  // (((u8)swap((u4)(v >> 32)) << 32) |
					  //  ((u8)swap((u4)(v & 0xFFFFFFFF))));
				}

				static
				u8 _cph_inl_pre
				swap_v2(u8 v) _cph_inl_post
				{
					_cph_private_infunc;

					return !convert ? v :
					  (((u8)swap((u4)(v >> 32)) << 32) |
					   ((u8)swap((u4)(v & 0xFFFFFFFF))));
				}

				static
				s8 _cph_inl_pre
				swap(s8 v) _cph_inl_post
				{
					_cph_private_infunc;

					return (s8)swap((u8)v);
				}

				static
				f4 _cph_inl_pre
				swap(f4 v) _cph_inl_post
				{
					_cph_private_infunc;

					if(!t(convert))
						return v;

					f4 r;
					byte *floatToConvert = (byte*)&v;
					byte *returnFloat    = (byte*)&r;

					returnFloat[0] = floatToConvert[3];
					returnFloat[1] = floatToConvert[2];
					returnFloat[2] = floatToConvert[1];
					returnFloat[3] = floatToConvert[0];

					return r;
				}

				static
				f8 _cph_inl_pre
				swap(f8 v) _cph_inl_post
				{
					_cph_private_infunc;

					if(!t(convert))
						return v;

					f8 r;
					byte *floatToConvert = (byte*)&v;
					byte *returnFloat    = (byte*)&r;

					returnFloat[0] = floatToConvert[7];
					returnFloat[1] = floatToConvert[6];
					returnFloat[2] = floatToConvert[5];
					returnFloat[3] = floatToConvert[4];
					returnFloat[4] = floatToConvert[3];
					returnFloat[5] = floatToConvert[2];
					returnFloat[6] = floatToConvert[1];
					returnFloat[7] = floatToConvert[0];

					return r;
				}

				private:
					// Workaround on "warning C4127: conditional expression is constant".
					static
					bool _cph_inl_pre
					t(bool v) _cph_inl_post
					{
						return v;
					}
			};
		}
	}
}

#endif // #ifndef _cph_h_private_bits_endian
