#pragma once

#include "math/config.h"

#include "math/vec3.h"

namespace mt
{
    struct vec4f
    {
        float x;
        float y;
        float z;
        float w;

        vec4f();
        vec4f( float _x, float _y, float _z, float _w );
        vec4f( const mt::vec4f & _v );
        vec4f( const mt::vec3f & _v, float _w );
        vec4f( const mt::vec2f & _v0, const mt::vec2f & _v1 );        
        explicit vec4f( const float * _v );

        mt::vec4f & operator=( const mt::vec4f & _rhs );

        float & operator []( size_t i );
        const float operator []( size_t i ) const;

        template <int K>
        float & get_t()
        {
            return this->operator [] ( K );
        }

        template <int K>
        float get_t() const
        {
            return this->operator [] ( K );
        }

        template <int K>
        void set_t( float _value )
        {
            this->operator [] ( K ) = _value;
        }

        void set( float _x, float _y, float _z, float _w );

        mt::vec4f & operator += ( const mt::vec4f & _rhs );
        mt::vec4f & operator -= ( const mt::vec4f & _rhs );
        mt::vec4f & operator *= ( const mt::vec4f & _rhs );
        mt::vec4f & operator /= ( const mt::vec4f & _rhs );
        mt::vec4f & operator *= ( const mt::vec2f & _rhs );
        mt::vec4f & operator /= ( const mt::vec2f & _rhs );
        mt::vec4f & operator *= ( const float _rhs );
        mt::vec4f & operator /= ( const float _rhs );

        float sqrlength() const;
        float length() const;

        const mt::vec3f & to_vec3f() const;

        float * buff();
        const float * buff() const;
    };

    bool operator==( const mt::vec4f & _a, const mt::vec4f & _b );
    bool operator!=( const mt::vec4f & _a, const mt::vec4f & _b );

    mt::vec4f operator+( const mt::vec4f & _a, const mt::vec4f & _b );
    mt::vec4f operator-( const mt::vec4f & _a, const mt::vec4f & _b );
    mt::vec4f operator*( const mt::vec4f & _rhs, const mt::vec4f & _val );
    mt::vec4f operator/( const mt::vec4f & _rhs, const mt::vec4f & _val );
    mt::vec4f operator*( const mt::vec4f & _rhs, const mt::vec2f & _val );
    mt::vec4f operator/( const mt::vec4f & _rhs, const mt::vec2f & _val );
    mt::vec4f operator*( const mt::vec4f & _rhs, const float _val );
    mt::vec4f operator/( const mt::vec4f & _rhs, const float _val );
    mt::vec4f operator-( vec4f _rhs );

    void ident_v4( mt::vec4f * const _rhs );
    float length_v4( const mt::vec4f & _rhs );

    void extract_v4_v3( mt::vec3f * const _out, const mt::vec4f & _rhs );

    void set_v4_v3( mt::vec4f * const _out, const mt::vec3f & _rhs );

    bool cmp_v4_v4( const mt::vec4f & _a, const mt::vec4f & _b );

    void add_v4_v3( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec3f & _b );
    void add_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec4f & _b );

    void sub_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec4f & _b );
    void scale_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, float _val );
    void neg_v4( mt::vec4f * const _out );

    float dot_v4_z( const mt::vec4f & a );
    float dot_v4_v2( const mt::vec4f & a, const mt::vec2f & b );
    float dot_v4_v3( const mt::vec4f & a, const mt::vec3f & b );
    float dot_v4_v4( const mt::vec4f & a, const mt::vec4f & b );

    void norm_v4_v4( mt::vec4f * const _out, const mt::vec4f & _rhs );
    float norm_v4_v4_f( mt::vec4f * const _out, const mt::vec4f & _rhs );
    mt::vec4f norm_v4_v4( const mt::vec4f & _rhs );
    void norm_safe_v4( mt::vec4f * const _out, const mt::vec4f & _rhs, float _err = 1e-06 );
    mt::vec4f norm_safe_v4( const mt::vec4f & _rhs );

    void homogenize_v4( mt::vec4f * const _out, const mt::vec4f & _rhs );
    void homogenize_v3_v4( mt::vec3f * const _out, const mt::vec4f & _rhs );
    mt::vec4f homogenize_v4( const mt::vec4f & _rhs );
};
