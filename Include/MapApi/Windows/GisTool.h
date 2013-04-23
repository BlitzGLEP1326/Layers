#pragma once

#ifdef __GNUC__
	#pragma GCC system_header
#elif defined _MSC_VER
	#pragma warning( push, 1 )
#endif

	#undef UNICODE
		#include <mapapi.h>
	#define UNICODE

#ifdef _MSC_VER
	#pragma warning( pop )
#endif
