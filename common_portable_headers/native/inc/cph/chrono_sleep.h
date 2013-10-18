#pragma once
#ifndef _cph_h_chrono_sleep
#define _cph_h_chrono_sleep

#include "./base/base.h"

#include "./private/chrono.h"

#include "./chrono_k.h"
#include "./chrono_units.h"
#include "./chrono_conv.h"

#include "./debug_callstack_printer.h"

namespace cph
{
	namespace chrono
	{
		namespace sleep
		{
			namespace
			{
				void _cph_inl_pre
				sleep(timet time, units::e u = units::ms) _cph_inl_post
				{
					_cph_private_infunc;

					using namespace cph::cph__private;
					using namespace cph::chrono::cph__private;

					timet ms = conv::to_ms<timet>(time, u);

					#if _cph_os_win
						Sleep((cph::cph__private::DWORD)ms);
					#elif _cph_posix
						timespec ts;
						ts.tv_sec  = ms >= k::ms_in_sec ? ms / k::ms_in_sec : 0;
						ts.tv_nsec = (ms % ms_in_sec) * ns_in_ms;
						nanosleep(&t, null))
					#endif
				}

				void _cph_inl_pre
				sleep_min(timet time) _cph_inl_post
				{
					_cph_private_infunc;

					sleep(time, units::min);
				}

				void _cph_inl_pre
				sleep_sec(timet time) _cph_inl_post
				{
					_cph_private_infunc;

					sleep(time, units::sec);
				}

				void _cph_inl_pre
				sleep_ms(timet time) _cph_inl_post
				{
					_cph_private_infunc;

					sleep(time, units::ms);
				}

				void _cph_inl_pre
				sleep_us(timet time) _cph_inl_post
				{
					_cph_private_infunc;

					sleep(time, units::us);
				}

				void _cph_inl_pre
				sleep_ns(timet time) _cph_inl_post
				{
					_cph_private_infunc;

					sleep(time, units::ns);
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_chrono_sleep
