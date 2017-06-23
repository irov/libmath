#	pragma once

#	include <stddef.h>

namespace mt
{
    namespace constant
    {
        const float pi = 3.14159265358979323846f;
        const float inv_pi = 1.f / pi;
        const float negative_pi = -pi;
        const float half_pi = pi * 0.5f;
        const float two_pi = 2.f * pi;
        const float inv_two_pi = 1.f / two_pi;
        const float e = 2.71828182845904523536f;
        const float sqrt2 = 1.4142135623730950488016887242097f;
        const float	deg2rad = pi / 180.f;
        const float	rad2deg = 180.f / pi;
        const float eps = 0.00001f;
        const float eps2 = eps * 10.f;
        const float neps = -eps;
        const float one_eps = 1.f + eps;
        const float one_neps = 1.f - eps;
    }
}

#	ifndef LIBMATH_FORCE_INLINE
#		ifdef _DEBUG
#			define LIBMATH_FORCE_INLINE 0
#		else
#			define LIBMATH_FORCE_INLINE 1
#		endif
#	endif


#	define LIBMATH_INLINE inline

#	if LIBMATH_FORCE_INLINE == 1
#		define LIBMATH_FUNCTION_INLINE LIBMATH_INLINE static
#		define LIBMATH_METHOD_INLINE LIBMATH_INLINE
#	else
#		define LIBMATH_FUNCTION_INLINE
#		define LIBMATH_METHOD_INLINE
#	endif