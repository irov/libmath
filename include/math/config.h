#	pragma once

#	include <stddef.h>

namespace mt
{
    namespace constant
    {
        const float pi = 3.1415926535897932384626433832795f;
        const float inv_pi = 0.31830988618379067153776752674503f;
        const float negative_pi = -3.1415926535897932384626433832795f;
        const float half_pi = 1.5707963267948966192313216916398f;
        const float two_pi = 6.283185307179586476925286766559f;
        const float inv_two_pi = 0.15915494309189533576888376337251f;
        const float e = 2.71828182845904523536f;
        const float sqrt2 = 1.4142135623730950488016887242097f;
        const float	deg2rad = 0.01745329251994329576923690768489f;
        const float	rad2deg = 57.295779513082320876798154814105f;
        const float eps = 0.00001f;
        const float eps2 = eps * 10.f;
        const float neps = -eps;
        const float one_eps = 1.f + eps;
        const float one_neps = 1.f - eps;
    }
}

#   define MT_DEG2RAD( DEG ) (DEG * mt::constant::deg2rad)
#   define MT_RAD2DEG( RAD ) (RAD * mt::constant::rad2deg)

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