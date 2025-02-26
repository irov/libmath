#pragma once

#include "math/config.h"

#include "math/vec4.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    struct uv4f
    {
        vec2f p0;
        vec2f p1;
        vec2f p2;
        vec2f p3;

        uv4f();
        uv4f( const mt::uv4f & _uv );
        uv4f( const mt::vec2f & _p0, const mt::vec2f & _p1, const mt::vec2f & _p2, const mt::vec2f & _p3 );
        explicit uv4f( const mt::vec4f & _mask );

        mt::vec2f & operator [] ( size_t i );
        const mt::vec2f & operator []( size_t i ) const;

        mt::uv4f & operator = ( const mt::uv4f & _rhs );

        template <int K>
        mt::vec2f & get_t()
        {
            return this->operator [] ( K );
        }

        template <int K>
        const mt::vec2f & get_t() const
        {
            return this->operator [] ( K );
        }

        template <int K>
        void set_t( const mt::vec2f & _value )
        {
            this->operator [] ( K ) = _value;
        }

        void set( const mt::vec2f & _p0, const mt::vec2f & _p1, const mt::vec2f & _p2, const mt::vec2f & _p3 );

        float * buff();
        const float * buff() const;

        static const mt::uv4f & identity();
    };

    bool operator==( const mt::uv4f & _a, const mt::uv4f & _b );
    bool operator!=( const mt::uv4f & _a, const mt::uv4f & _b );

    bool uv4_is_identity( const mt::uv4f & _uv );
    void uv4_identity( mt::uv4f * const _out );
    bool uv4_cmp( const mt::uv4f & _a, const mt::uv4f & _b );
    void uv4_from_mask( mt::uv4f * const _out, const mt::vec4f & _mask );
    void uv4_rotate( mt::uv4f * const _out );
    void uv4_swap_u( mt::uv4f * const _out );
    void uv4_swap_v( mt::uv4f * const _out );
    void uv4_scale( mt::uv4f * const _out, const mt::uv4f & _uv, const mt::vec2f & _scale );
    void uv4_quad_point( mt::vec2f * const _out, const mt::uv4f & _uv, const mt::vec2f & _point );
    void uv4_quad_point_rotate( mt::vec2f * const _out, const mt::uv4f & _uv, const mt::vec2f & _point );
    void uv4_multiply_tetragon( mt::uv4f * const _out, const mt::uv4f & _uv1, const mt::uv4f & _uv2 );
    void uv4_multiply_tetragon_v4( mt::uv4f * const _out, const mt::uv4f & _uv, const mt::vec4f & _mask );
    void uv4_multiply_tetragon_vp( mt::uv4f * const _out, const mt::uv4f & _uv1, const mt::vec2f * const _uv2 );
    void uv4_multiply_tetragon_v2( mt::vec2f * const _out, const mt::uv4f & _uv, const mt::vec2f & _p );
    void uv4_calc_point( const mt::vec2f & _a, const mt::vec2f & _b, const mt::vec2f & _c, const mt::vec2f & _auv, const mt::vec2f & _buv, const mt::vec2f & _cuv, const mt::vec2f & _point, mt::vec2f * const _uv );
}
