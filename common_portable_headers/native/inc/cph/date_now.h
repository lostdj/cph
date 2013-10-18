#pragma once
#ifndef _cph_h_date_now
#define _cph_h_date_now

#include "./base/base.h"

#include "./time_now.h"
#include "./date.h"
#include "./date_conv.h"

namespace cph
{
	namespace date
	{
		namespace now
		{
			namespace
			{
				void _cph_inl_pre
				gmt(date &d) _cph_inl_post
				{
					cph::date::conv::gmt_from_ms(cph::time::now::ms(), d);
				}

				void _cph_inl_pre
				local(date &d) _cph_inl_post
				{
					cph::date::conv::local_from_ms(cph::time::now::ms(), d);
				}

				date _cph_inl_pre
				gmt() _cph_inl_post
				{
					date d;

					gmt(d);

					return d;
				}

				date _cph_inl_pre
				local() _cph_inl_post
				{
					date d;

					local(d);

					return d;
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_date_now
