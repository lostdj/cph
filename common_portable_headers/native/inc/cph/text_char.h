#pragma once
#ifndef _cph_h_text_char
#define _cph_h_text_char

#include "./base/base.h"

namespace cph
{
	namespace text
	{
		namespace string
		{
			// TODO: C++11 char16_t and char32_t.

			//
			typedef u1 c8;
			typedef u2 c16;
			typedef u4 c32;

			//
			namespace
			{
				// TODO: alignof(1).
				struct cp8
				{
					c8 c[4];

					bool
					isnil() const
					{
						return !c[0];
					}

					u1
					sz() const
					{
						if(c[0] <= 0x7F)
							return 1;
						elif(c[1] <= 0xDF)
							return 2;
						elif(c[2] <= 0xEF)
							return 3;
						elif(c[3] <= 0xF7)
							return 4;
						else
							// TODO: assert?
							return 0;
					}

					cp8*
					next() const
					{
						return (cp8*)((u1*)this + sz());
					}

					u4
					utf16(/* TODO: BO? */) const
					{
						union
						{
							u4 cp;
							c16 r16[2];
						};
						cp = 0;

						if(c[0] <= 0x7F)
							r16[0] = static_cast<c16>(c[0]);
						elif(c[0] <= 0xDF)
							r16[0] = static_cast<c16>((c[0] << 6) + c[1] - 0x3080);
						elif(c[0] <= 0xEF)
							r16[0] = static_cast<c16>((c[0] << 12) + (c[1] << 6) + c[2] - 0x2080);
						elif(c[0] <= 0xF7)
							r16[0] = static_cast<c16>((utf32() >> 10) + 0xD7C0),
								r16[1] = static_cast<c16>((utf32() & 0x3FF) | 0xDC00);
						else
							// TODO: assert?
							return 0;

						return cp;
					}

					c32
					utf32() const
					{
						if(c[0] <= 0x7F)
							return static_cast<c32>(c[0]);
						elif(c[0] <= 0xDF)
							return static_cast<c32>((c[0] << 6) + c[1] - 0x3080);
						elif(c[0] <= 0xEF)
							return static_cast<c32>((c[0] << 12) + (c[1] << 6) + c[2] - 0x2080);
						elif(c[0] <= 0xF7)
							return
								static_cast<c32>((c[0] << 18) + (c[1] << 12) + (c[2] << 6) + c[3] - 0x3C82080);
						else
							// TODO: assert?
							return 0;
					}

					bool
					isvalid() const
					{
						// UTF-16 surrogate pairs.
						c32 r32 = utf32();
						if(r32 >= 0xD800 && r32 <= 0xDFFF)
							return false;

						// TODO: ...

						return true;
					}
				};
			}

			//
			namespace
			{
				// TODO: alignof(1).
				struct cp16
				{
					c16 c[2];

					bool
					isnil() const
					{
						return !c[0];
					}

					u1
					sz(/* TODO: BO? */) const
					{
						if(c[0] >= 0xD800 && c[0] <= 0xDBFF)
							return 2;
						else
							return 1;
					}

					cp16*
					next() const
					{
						return (cp16*)((u2*)this + (isbom() ? 2 : sz()));
					}

					u4
					utf8(/* TODO: BO? */) const
					{
						union
						{
							u4 cp;
							cp8 r8;
						};
						cp = 0;

						if(c[0] <= 0x7F)
							r8.c[0] = static_cast<c8>(c[0]);
						elif(c[0] <= 0x7FF)
							r8.c[0] = static_cast<c8>((c[0] >> 6) | 0xC0),
								r8.c[1] = static_cast<c8>((c[0] & 0x3F) | 0x80);
						elif(ispair())
							r8.c[0] = static_cast<c8>((utf32() >> 18) | 0xF0),
								r8.c[1] = static_cast<c8>(((utf32() >> 12) & 0x3F) | 0x80),
									r8.c[2] = static_cast<c8>(((utf32() >> 6) & 0x3F) | 0x80),
										r8.c[3] = static_cast<c8>((utf32() & 0x3F) | 0x80);
						else//elif(c[0] <= 0xFFFF)
							r8.c[0] = static_cast<c8>((c[0] >> 12) | 0xE0),
								r8.c[1] = static_cast<c8>(((c[0] >> 6) & 0x3F) | 0x80),
									r8.c[2] = static_cast<c8>((c[0] & 0x3F) | 0x80);
						// else
						// 	return 0;

						return cp;
					}

					c32
					utf32() const
					{
						if(ispair())
							return
								(((c32)c[0] << 10UL) + (c32)c[1] - ((0xD800 << 10UL) + 0xDC00 - 0x10000));
						else
							return static_cast<c32>(c[0]);
					}

					bool
					isbom() const
					{
						return
							(c[0] == 0xFE && c[1] == 0xFF)
							||
							(c[0] == 0xFF && c[1] == 0xFE);
					}

					bool
					bom() const
					{
						// BE.
						if(c[0] == 0xFE && c[1] == 0xFF)
							return true;
						// LE.
						else
							return false;
					}

					bool
					ispair() const
					{
						return
							(c[0] >= 0xD800 && c[0] <= 0xDBFF)  // LE, lead surrogate.
							||
							(c[1] >= 0xD800 && c[1] <= 0xDBFF); // BE, lead surrogate.

							// TODO: Assert for trail surrogate be in range of 0xDC00 .. 0xDFFF.
					}

					void
					swap()
					{
						c16 tmp = c[0];
						c[0] = c[1];
						c[1] = tmp;
					}
				};
			}

			//
			namespace
			{
				// TODO: alignof(1).
				struct cp32
				{
					c32 c;

					bool
					isnil() const
					{
						return !c;
					}

					u4
					utf8() const
					{
						union
						{
							u4 cp;
							cp8 r8;
						};
						cp = 0;

						if(c <= 0x7F)
							r8.c[0] = static_cast<c8>(c);
						elif(c <= 0x7FF)
							r8.c[0] = static_cast<c8>((c >> 6) | 0xC0),
								r8.c[1] = static_cast<c8>((c & 0x3F) | 0x80);
						elif(c <= 0xFFFF)
							r8.c[0] = static_cast<c8>((c >> 12) | 0xE0),
								r8.c[1] = static_cast<c8>(((c >> 6) & 0x3F) | 0x80),
									r8.c[2] = static_cast<c8>((c & 0x3F) | 0x80);
						elif(c <= 0x1FFFFF)
							r8.c[0] = static_cast<c8>((c >> 18) | 0xF0),
								r8.c[1] = static_cast<c8>(((c >> 12) & 0x3F) | 0x80),
									r8.c[2] = static_cast<c8>(((c >> 6) & 0x3F) | 0x80),
										r8.c[3] = static_cast<c8>((c & 0x3F) | 0x80);
						else
							// Wat?
							return 0;

						return cp;
					}

					u4
					utf16(/* TODO: BO? */) const
					{
						union
						{
							u4 cp;
							cp16 r16;
						};
						cp = 0;

						if(c >= 0x10000 && c <= 0x10FFFF)
							r16.c[0] = static_cast<c16>((c >> 10) + 0xD800),
								r16.c[1] = static_cast<c16>((c & 0x3FFUL) + 0xDC00);
						else
							cp = c;

						return cp;
					}
				};
			}
		}
	}
}

#endif // #ifndef _cph_h_text_char
