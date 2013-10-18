#pragma once
#ifndef _cph_h_private_callstack_printer
#define _cph_h_private_callstack_printer

#include "./../base/base.h"

#include "./debug_log_simple.h"

namespace cph
{
	namespace debug
	{
		namespace callstack_printer
		{
			namespace cph__private
			{
				namespace
				{
					template<const char *from>
					class callstack_printer
					{
						public:
							const char *f;

							callstack_printer(const char *f) : f(f)
							{
								cph::debug::log_simple::cph__private::log(false, from, "trc FUNC -> ", "", f, "");
							}

							~callstack_printer()
							{
								cph::debug::log_simple::cph__private::log(false, from, "trc FUNC <- ", "", f, "");
							}
					};

					extern const char cph[] = "cph";
					extern const char usr[] = "usr";

					typedef callstack_printer<cph> cpcph;
					typedef callstack_printer<usr> cpusr;
				}
			}
		}
	}
}

#ifdef _cph_cfg_private_callstack_printer_on
	#define _cph_private_infunc cph::debug::callstack_printer::cph__private::cpcph ____hidden__callstack_printer(_cph_funcname)
#else
	#define _cph_private_infunc
#endif

#endif // #ifndef _cph_h_private_callstack_printer
