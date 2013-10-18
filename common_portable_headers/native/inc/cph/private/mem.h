#pragma once
#ifndef _cph_h_private_mem
#define _cph_h_private_mem

#include "./../base/base.h"

namespace cph
{
	namespace mem
	{
		namespace cph__private
		{
			namespace
			{
				extern "C"
				{
					extern void* memset(void*, int, uw);
					extern void* memcpy(void*, const void*, uw);
					extern void* memmove(void*, const void*, uw);
					extern int   memcmp(const void*, const void*, uw);
					extern void* memchr(const void*, int, uw);
				}
			}
		}
	}
}

#endif // #ifndef _cph_h_private_mem
