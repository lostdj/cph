#pragma once
#ifndef _cph_h_private_debug_log
#define _cph_h_private_debug_log

#include "./../base/base.h"

#include "./../text_string.h"

#include "./debug_log_simple.h"

namespace cph
{
	namespace debug
	{
		namespace log
		{
			namespace cph__private
			{
				namespace
				{
					class counter
					{
						public:
							u4 c;

							#if _cph_cc_msc
								#pragma warning(push)
								#pragma warning(disable: 4100) // unreferenced formal parameter
							#elif _cph_cc_gnu
								#pragma GCC diagnostic push
								#pragma GCC diagnostic ignored "-Wunused-parameter"
							#endif

							counter& operator <<(bool v) {c += 5 + 1; return *this;}

							counter& operator <<(s1 v)   {c += 1 + 3 + 1; return *this;}
							counter& operator <<(u1 v)   {c += 0 + 3 + 1; return *this;}

							counter& operator <<(s2 v)   {c += 1 + 5 + 1; return *this;}
							counter& operator <<(u2 v)   {c += 0 + 5 + 1; return *this;}

							counter& operator <<(s4 v)   {c += 1 + 10 + 1; return *this;}
							counter& operator <<(u4 v)   {c += 0 + 10 + 1; return *this;}

							counter& operator <<(s8 v)   {c += 1 + 19 + 1; return *this;}
							counter& operator <<(u8 v)   {c += 0 + 20 + 1; return *this;}

							counter& operator <<(void *v) {c += 16 + 1; return *this;}

							counter& operator <<(f4 v)   {c += 1 + 20 + 1 + 1; return *this;}
							counter& operator <<(f8 v)   {c += 1 + 40 + 1 + 1; return *this;}

							template<u4 sz>
							counter&
							operator <<(const char (&s)[sz])
							{c += sz - 1; return *this;}

							counter&
							operator <<(const cph::text::string::str8 *s)
							{c += s->sz() - 1; return *this;}

							counter&
							operator <<(const cph::text::string::str8 &s)
							{c += s.sz() - 1; return *this;}

							#if _cph_cc_msc
								#pragma warning(pop)
							#elif _cph_cc_gnu
								#pragma GCC diagnostic pop
							#endif
					};
				}

				namespace
				{
					class printer
					{
						public:
							cph::text::string::str8 *s;
							u4 pos;

							// b1 /*bin, */dec_, hex_;

							printer(u4 c, bool printtime = true) : s(null), pos(0)//,
								// /*bin(false), */dec_(true), hex_(false)
							{
								cph::text::string::str8::str8size s8s = sizeof(_cph_private_debug_log_simple_timefmt) + c + 1;
								s = (cph::text::string::str8*)new/*(std::nothrow)*/ byte[sizeof(cph::text::string::str8::str8size) + s8s];
								if(s)
									s->z = s8s;
								else
									_cph_private_sloge("\r\n\r\nOut of memory.\r\n\r\n");

								if(printtime)
									timestamp();
							}

							~printer()
							{
								if(s)
									delete[] s;
							}

							printer& dummy()
							{
								return *this;
							}

							// printer& dec()
							// {
							// 	dec_ = true;
							// 	hex_ = false;

							// 	return *this;
							// }

							// printer& hex()
							// {
							// 	dec_ = false;
							// 	hex_ = true;

							// 	return *this;
							// }

							// printer& reset_radix()
							// {
							// 	dec_ = true;
							// 	hex_ = false;
							// }

							printer& timestamp()
							{
								if(!s)
									return *this;

								cph::debug::log_simple::cph__private::timestamp(*s);
								pos += sizeof(_cph_private_debug_log_simple_timefmt) - 1;
								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, " ");

								return *this;
							}

							void end(bool err)
							{
								if(!err)
									_cph_sprint("\n"
									            "%s",
									            s != null ? (const char*)s->cstr() : "");
								else
									_cph_sprinte("\n\n==========================================\n"
									             "%s"
									             "\n------------------------------------------\n",
									             s != null ? (const char*)s->cstr() : "");
							}

							printer& operator <<(bool v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, v ? "true" : "false");

								return *this;
							}

							printer& operator <<(s1 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%hhd", v);

								return *this;
							}
							printer& operator <<(u1 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%hhu", v);

								return *this;
							}

							printer& operator <<(s2 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%hd", v);

								return *this;
							}
							printer& operator <<(u2 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%hu", v);

								return *this;
							}

							printer& operator <<(s4 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%ld", v);

								return *this;
							}
							printer& operator <<(u4 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%lu", v);

								return *this;
							}

							printer& operator <<(s8 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%lld", v);

								return *this;
							}
							printer& operator <<(u8 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%llu", v);

								return *this;
							}

							printer& operator <<(void *v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%p", v);

								return *this;
							}

							printer& operator <<(f4 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%.5g", v);

								return *this;
							}
							printer& operator <<(f8 v)
							{
								if(!s)
									return *this;

								pos += _cph_private_snprintf((char*)s->str() + pos, s->sz() - pos, "%.8g", v);

								return *this;
							}

							printer& operator <<(const char *s)
							{
								if(!this->s || !s)
									return *this;

								pos += _cph_private_snprintf((char*)this->s->str() + pos, this->s->sz() - pos, "%s", s);

								return *this;
							}

							printer& operator <<(const cph::text::string::str8 *s)
							{
								if(!this->s || !s)
									return *this;

								pos += _cph_private_snprintf((char*)this->s->str() + pos, this->s->sz() - pos, "%s", s != null ? (char*)s->cstr() : "");

								return *this;
							}

							printer& operator <<(const cph::text::string::str8 &s)
							{
								if(!this->s)
									return *this;

								pos += _cph_private_snprintf((char*)this->s->str() + pos, this->s->sz() - pos, "%s", s.cstr());

								return *this;
							}
					};
				}
			}
		}
	}
}

#define _cph_log_imp(x, err) (cph::debug::log::cph__private::printer((cph::debug::log::cph__private::counter() x).c) x).end(err)
#define _cph_clog_imp(n, x, err) (n ? ((cph::debug::log::cph__private::printer((cph::debug::log::cph__private::counter() x).c) x).end(err)), true : false)

#endif // #ifndef _cph_h_private_debug_log
