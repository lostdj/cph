#pragma once
#ifndef _cph_h_text_string
#define _cph_h_text_string

#include "./base/base.h"

#include "./text_char.h"

namespace cph
{
	namespace text
	{
		namespace string
		{
			//
			namespace
			{
				// TODO: alignof(1).
				struct str8
				{
					// Temp.
					typedef u4 str8size;
					str8size z;

					#if _cph_cc_msc
						#pragma warning(push)
						#pragma warning(disable: 4200) // nonstandard extension used : zero-sized array in struct/union
					#elif _cph_cc_gnu
						#pragma GCC diagnostic push
						#pragma GCC diagnostic ignored "-pedantic"
					#endif

						c8 s[];

					#if _cph_cc_msc
						#pragma warning(pop)
					#elif _cph_cc_gnu
						#pragma GCC diagnostic pop
					#endif

					u4
					sz() const
					{
						return z;
					}

					u4
					newstr16sz() const
					{
						return sz() * 2;
					}

					c8*
					str()
					{
						return s;
					}

					const c8 *
					cstr() const
					{
						return s;
					}

					cp8*
					first() const
					{
						return (cp8*)s;
					}
				};

				template<u4 Tsz>
				struct tstr8
				{
					u4 z;
					c8 s[Tsz];

					_cph_inl_pre
					str8&
					str() _cph_inl_post
					{
						return *(str8*)this;
					}

					_cph_inl_pre
					const str8&
					cstr() const _cph_inl_post
					{
						return *(str8*)this;
					}
				};

				#define _cph_mkstr8(var, str) cph::text::string::tstr8<sizeof(str)> var = {sizeof(str), str};
			}

			//
			namespace
			{
				// TODO: alignof(1).
				struct str16
				{
					// Temp.
					u4 z;

					#if _cph_cc_msc
						#pragma warning(push)
						#pragma warning(disable: 4200) // nonstandard extension used : zero-sized array in struct/union
					#elif _cph_cc_gnu
						#pragma GCC diagnostic push
						#pragma GCC diagnostic ignored "-pedantic"
					#endif

						c16 s[];

					#if _cph_cc_msc
						#pragma warning(pop)
					#elif _cph_cc_gnu
						#pragma GCC diagnostic pop
					#endif

					u4
					sz() const
					{
						return z;
					}

					u4
					newstr8sz() const
					{
						return u4(sz() * 1.5);
					}

					c16*
					str()
					{
						return s;
					}

					const c16*
					cstr() const
					{
						return s;
					}

					cp16*
					first() const
					{
						return (cp16*)s;
					}
				};
			}

			//
			// TODO: alignof(1).
			// struct str32
			// {
			// 	#if _cph_cc_msc
			// 		#pragma warning(push)
			// 		#pragma warning(disable: 4200) // nonstandard extension used : zero-sized array in struct/union
			// 	#elif _cph_cc_gnu
			// 		#pragma GCC diagnostic push
			// 		#pragma GCC diagnostic ignored "-pedantic"
			// 	#endif

			// 		c32 s[];

			// 	#if _cph_cc_msc
			// 		#pragma warning(pop)
			// 	#elif _cph_cc_gnu
			// 		#pragma GCC diagnostic pop
			// 	#endif
			// };
		}
	}
}

#endif // #ifndef _cph_h_text_string
