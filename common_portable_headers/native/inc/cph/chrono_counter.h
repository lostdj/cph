#pragma once
#ifndef _cph_h_chrono_counter
#define _cph_h_chrono_counter

#include "./base/base.h"

#include "./private/chrono.h"

#include "./chrono.h"
#include "./chrono_k.h"
#include "./chrono_units.h"
#include "./chrono_conv.h"

#include "./debug_callstack_printer.h"

// Stopwatch.

namespace cph
{
	namespace chrono
	{
		class counter
		{
		public:
			timet offset;

			_cph_inl_pre
			counter() _cph_inl_post
			{
				_cph_private_infunc;

				using namespace cph::cph__private;
				using namespace cph::chrono::cph__private;

				#if _cph_os_win
					freq.QuadPart = 0;
					ticks.QuadPart = 0;
					QueryPerformanceFrequency(&freq);
				#endif

				offset = raw();
			}

			timet _cph_inl_pre
			raw() _cph_inl_post
			{
				_cph_private_infunc;

				using namespace cph::cph__private;
				using namespace cph::chrono::cph__private;

				#if _cph_os_win
					QueryPerformanceCounter(&ticks);

					return (timet)
						(ticks.QuadPart * k::ns_in_sec / freq.QuadPart);
				#elif _cph_posix
					clock_gettime(CLOCK_MONOTONIC, &ts);

					return
						(ts.tv_sec * k::ns_in_sec) + (ts.tv_nsec);
				#endif
			}

			timet _cph_inl_pre
			sec() _cph_inl_post
			{
				_cph_private_infunc;

				return conv::to_sec<timet>(raw() - offset, units::ns);
			}

			timet _cph_inl_pre
			ms() _cph_inl_post
			{
				_cph_private_infunc;

				return conv::to_ms<timet>(raw() - offset, units::ns);
			}

			timet _cph_inl_pre
			us() _cph_inl_post
			{
				_cph_private_infunc;

				return conv::to_us<timet>(raw() - offset, units::ns);
			}

			timet _cph_inl_pre
			ns() _cph_inl_post
			{
				_cph_private_infunc;

				return raw() - offset;
			}

			void _cph_inl_pre
			restart() _cph_inl_post
			{
				_cph_private_infunc;

				offset = raw();
			}

		private:
			#if _cph_os_win
				cph::cph__private::LARGE_INTEGER freq;
				cph::cph__private::LARGE_INTEGER ticks;
			#elif _cph_posix
				cph::chrono::cph__private::timespec ts;
			#endif
		};
	}
}

#endif // #ifndef _cph_h_chrono_counter
