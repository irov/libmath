#pragma once

#include "math/config.h"

#include "math/vec2.h"
#include "math/utils.h"

namespace mt
{
    struct mat2f
    {
        mt::vec2f v0;
        mt::vec2f v1;

        MT_METHOD_INLINE mat2f();
        MT_METHOD_INLINE mat2f( const mt::mat2f & _m2 );
        MT_METHOD_INLINE mat2f( const mt::vec2f & _v0, const mt::vec2f & _v1 );

        MT_METHOD_INLINE mt::vec2f & operator[]( size_t i );
        MT_METHOD_INLINE const mt::vec2f & operator[]( size_t i )const;

        MT_METHOD_INLINE mt::mat2f & operator=( const mt::mat2f & _m2 );
    };

    MT_FUNCTION_INLINE bool operator==( const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE bool operator!=( const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE mt::vec2f operator*( const mt::mat2f & _m, const mt::vec2f & _v );
    MT_FUNCTION_INLINE mt::vec2f operator*( const mt::vec2f & _v, const mt::mat2f & _m );
    MT_FUNCTION_INLINE mt::mat2f operator*( const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE mt::mat2f operator+( const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE mt::mat2f operator-( const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE mt::mat2f operator*( const mt::mat2f & _rhs, float _val );

    MT_FUNCTION_INLINE bool cmp_m2_m2( const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE void mul_m2_v2( mt::vec2f * const _out, const mt::mat2f & _m, const mt::vec2f & _v );
    MT_FUNCTION_INLINE void mul_v2_m2( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat2f & _m );
    MT_FUNCTION_INLINE void mul_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE void add_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE void sub_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b );
    MT_FUNCTION_INLINE void scale_m2_s( mt::mat2f * const _out, const mt::mat2f & _rhs, float _val );
    MT_FUNCTION_INLINE void scale_m2_s( mt::mat2f * const _out, float _val );

    MT_FUNCTION_INLINE void transpose_m2( mt::mat2f * const _out, const mt::mat2f & _rhs );
    MT_FUNCTION_INLINE mt::mat2f transpose_m2( const mt::mat2f & _rhs );
}

#if MT_FORCE_INLINE == 1
#include "math/mat2.cpp"
#endif
