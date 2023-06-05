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

        mat2f();
        mat2f( const mt::mat2f & _m2 );
        mat2f( const mt::vec2f & _v0, const mt::vec2f & _v1 );

        mt::vec2f & operator[]( size_t i );
        const mt::vec2f & operator[]( size_t i )const;

        mt::mat2f & operator=( const mt::mat2f & _m2 );
    };

    bool operator==( const mt::mat2f & _a, const mt::mat2f & _b );
    bool operator!=( const mt::mat2f & _a, const mt::mat2f & _b );
    mt::vec2f operator*( const mt::mat2f & _m, const mt::vec2f & _v );
    mt::vec2f operator*( const mt::vec2f & _v, const mt::mat2f & _m );
    mt::mat2f operator*( const mt::mat2f & _a, const mt::mat2f & _b );
    mt::mat2f operator+( const mt::mat2f & _a, const mt::mat2f & _b );
    mt::mat2f operator-( const mt::mat2f & _a, const mt::mat2f & _b );
    mt::mat2f operator*( const mt::mat2f & _rhs, float _val );

    bool cmp_m2_m2( const mt::mat2f & _a, const mt::mat2f & _b );
    void mul_m2_v2( mt::vec2f * const _out, const mt::mat2f & _m, const mt::vec2f & _v );
    void mul_v2_m2( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat2f & _m );
    void mul_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b );
    void add_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b );
    void sub_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b );
    void scale_m2_s( mt::mat2f * const _out, const mt::mat2f & _rhs, float _val );
    void scale_m2_s( mt::mat2f * const _out, float _val );

    void transpose_m2( mt::mat2f * const _out, const mt::mat2f & _rhs );
    mt::mat2f transpose_m2( const mt::mat2f & _rhs );
}
