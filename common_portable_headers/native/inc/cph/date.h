#pragma once
#ifndef _cph_h_date
#define _cph_h_date

#include "./base/base.h"

#include "./chrono.h"
#include "./date_sym.h"

namespace cph
{
	namespace date
	{
		struct date
		{
			u2 year;
			u1 month;
			u1 weekd;
			u1 mday;
			u1 hour;
			u1 min;
			u1 sec;
			u2 ms;
		};

		struct datex : public date
		{
			cph::chrono::timet epoch;
		};
	}
}

#endif // #ifndef _cph_h_date
