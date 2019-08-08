#pragma once

#include "math/config.h"

#include "math/utils.h"

#include "math/vec2.h"

namespace mt
{
    struct mat2f
    {
        vec2f v0;
        vec2f v1;

        MT_METHOD_INLINE mat2f();
        MT_METHOD_INLINE mat2f( const mat2f & _m2 );
        MT_METHOD_INLINE mat2f( const vec2f & _v0, const vec2f & _v1 );

        MT_METHOD_INLINE vec2f & operator[]( size_t i );
        MT_METHOD_INLINE const vec2f & operator[]( size_t i )const;

        MT_METHOD_INLINE mat2f & operator=( const mat2f & _m2 );
    };

    MT_FUNCTION_INLINE bool operator==( const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE bool operator!=( const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE vec2f operator*( const mat2f & _m, const vec2f & _v );
    MT_FUNCTION_INLINE vec2f operator*( const vec2f & _v, const mat2f & _m );
    MT_FUNCTION_INLINE mat2f operator*( const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE mat2f operator+( const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE mat2f operator-( const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE mat2f operator*( const mat2f & _rhs, float _val );

    MT_FUNCTION_INLINE bool cmp_m2_m2( const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE void mul_m2_v2( vec2f & _out, const mat2f & _m, const vec2f & _v );
    MT_FUNCTION_INLINE void mul_v2_m2( vec2f & _out, const vec2f & _v, const mat2f & _m );
    MT_FUNCTION_INLINE void mul_m2_m2( mat2f & _out, const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE void add_m2_m2( mat2f & _out, const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE void sub_m2_m2( mat2f & _out, const mat2f & _a, const mat2f & _b );
    MT_FUNCTION_INLINE void scale_m2_s( mat2f & _out, const mat2f & _rhs, float _val );
    MT_FUNCTION_INLINE void scale_m2_s( mat2f & _out, float _val );

    MT_FUNCTION_INLINE void transpose_m2( mat2f & _out, const mat2f & _rhs );
    MT_FUNCTION_INLINE mat2f transpose_m2( const mat2f & _rhs );
}

#if MT_FORCE_INLINE == 1
#include "math/mat2_inline.h"
#endif
