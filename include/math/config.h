#pragma once

#include <stddef.h>
#include <stdint.h>

#ifndef MT_NO_DEFINE
#include <math.h>
#include <float.h>

#define MT_FLT_MAX FLT_MAX 
#define MT_FLT_MIN FLT_MIN

#define MT_floorf (::floorf)
#define MT_acosf (::acosf)
#define MT_asinf (::asinf)
#define MT_atan2f (::atan2f)
#define MT_sqrtf (::sqrtf)
#define MT_powf (::powf)
#define MT_cosf (::cosf)
#define MT_sinf (::sinf)
#define MT_tanf (::tanf)
#define MT_fabsf (::fabsf)
#endif

#ifndef MT_NO_ASSERT
#include <assert.h>

#define MT_assert(A) assert(A)
#else
#define MT_assert(A)
#endif


#ifndef MT_FORCE_INLINE
#   ifdef _DEBUG
#       define MT_FORCE_INLINE 0
#	else
#       define MT_FORCE_INLINE 1
#	endif
#endif

#define MT_INLINE inline

#if MT_FORCE_INLINE == 1
#	define MT_FUNCTION_INLINE MT_INLINE static
#	define MT_METHOD_INLINE MT_INLINE
#else
#	define MT_FUNCTION_INLINE
#	define MT_METHOD_INLINE
#endif
