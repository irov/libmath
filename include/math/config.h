#	pragma once

#   include <stddef.h>
#   include <math.h>

#   define math_floorf ::floorf
#   define math_acosf ::acosf
#   define math_asinf ::asinf
#   define math_atan2f ::atan2f
#   define math_sqrtf ::sqrtf
#   define math_powf ::powf
#   define math_cosf ::cosf
#   define math_sinf ::sinf
#   define math_tanf ::tanf
#   define math_fabsf ::fabsf

#   include <assert.h>

#   define math_assert assert


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