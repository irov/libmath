#pragma once

#include <stddef.h>
#include <stdint.h>

#ifndef MT_NO_MATH
#   include <math.h>

#   define MT_floorf (::floorf)
#   define MT_acosf (::acosf)
#   define MT_asinf (::asinf)
#   define MT_atan2f (::atan2f)
#   define MT_atanf (::atanf)
#   define MT_sqrtf (::sqrtf)
#   define MT_powf (::powf)
#   define MT_cosf (::cosf)
#   define MT_sinf (::sinf)
#   define MT_tanf (::tanf)
#   define MT_fabsf (::fabsf)
#   define MT_logf (::logf)
#   define MT_log10f (::log10f)
#   define MT_roundf (::roundf)
#   define MT_ceilf (::ceilf)

#   define MT_floor (::floor)
#   define MT_acos (::acos)
#   define MT_asin (::asin)
#   define MT_atan2 (::atan2)
#   define MT_atan (::atan)
#   define MT_sqrt (::sqrt)
#   define MT_pow (::pow)
#   define MT_cos (::cos)
#   define MT_sin (::sin)
#   define MT_tan (::tan)
#   define MT_fabs (::fabs)
#   define MT_log (::log)
#   define MT_log10 (::log10)
#   define MT_round (::round)
#   define MT_ceil (::ceil)
#endif

#ifndef MT_NO_FLOAT
#   include <float.h>

#   define MT_FLT_MAX FLT_MAX 
#   define MT_FLT_MIN FLT_MIN
#endif

#ifndef MT_NO_ASSERT
#   include <assert.h>
#   define MT_assert(A) assert(A)
#else
#   define MT_assert(A)
#endif


#ifndef MT_FORCE_INLINE
#   ifndef NDEBUG
#       define MT_FORCE_INLINE 0
#   else
#       define MT_FORCE_INLINE 1
#   endif
#endif

#ifndef MT_INLINE
#   define MT_INLINE inline
#endif

#ifndef MT_CONSTEXPR
#   ifdef __cplusplus
#       if __cplusplus >= 201402L
#           define MT_CONSTFUNC constexpr
#           define MT_CONSTEXPR constexpr
#           define MT_CONSTVAR constexpr
#       elif __cplusplus >= 201103L
#           define MT_CONSTFUNC inline
#           define MT_CONSTEXPR constexpr
#           define MT_CONSTVAR constexpr
#       else
#           define MT_CONSTFUNC inline
#           define MT_CONSTEXPR inline
#           define MT_CONSTVAR static
#       endif
#   else
#       define MT_CONSTEXPR inline
#       define MT_CONSTVAR static
#   endif
#endif

#if MT_FORCE_INLINE == 1
#   define MT_FUNCTION_INLINE MT_INLINE static
#   define MT_METHOD_INLINE MT_INLINE
#else
#   define MT_FUNCTION_INLINE
#   define MT_METHOD_INLINE
#endif
