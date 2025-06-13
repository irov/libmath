#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    struct vec3f
    {
        float x;
        float y;
        float z;

        vec3f();
        vec3f( float _x, float _y, float _z );
        vec3f( const mt::vec3f & _v );
        vec3f( const mt::vec2f & _v, float _z );
        explicit vec3f( const float * _v );

        mt::vec3f & operator = ( const mt::vec3f & _rhs );

        float operator [] ( size_t i ) const;
        float & operator [] ( size_t i );

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

        void set( float _x, float _y, float _z );

        mt::vec3f & operator += ( const mt::vec3f & _rhs );
        mt::vec3f & operator -= ( const mt::vec3f & _rhs );
        mt::vec3f & operator *= ( const mt::vec3f & _rhs );
        mt::vec3f & operator /= ( const mt::vec3f & _rhs );
        mt::vec3f & operator *= ( const float _rhs );
        mt::vec3f & operator /= ( const float _rhs );
        
        float sqrlength() const;
        float length() const;

        mt::vec2f to_vec2f() const;
        void from_f3( const float * _v );
        void from_f2( const float * _v, float _z );

        float * buff();
        const float * buff() const;

        static const mt::vec3f & identity();
    };

    MT_CONSTEXPR bool is_ident_v3( const mt::vec3f & _a )
    {
        return _a.x == 0.f && _a.y == 0.f && _a.z == 0.f;
    }

    MT_CONSTEXPR bool is_one_v3( const mt::vec3f & _a )
    {
        return _a.x == 1.f && _a.y == 1.f && _a.z == 1.f;
    }

    MT_CONSTEXPR bool is_zero_v3( const mt::vec3f & _a )
    {
        return _a.x == 0.f && _a.y == 0.f && _a.z == 0.f;
    }

    bool operator==( const mt::vec3f & _a, const mt::vec3f & _b );
    bool operator!=( const mt::vec3f & _a, const mt::vec3f & _b );

    vec3f operator+( const mt::vec3f & _a, const mt::vec3f & _b );
    vec3f operator-( const mt::vec3f & _a, const mt::vec3f & _b );
    vec3f operator*( const mt::vec3f & _a, const mt::vec3f & _b );
    vec3f operator*( const mt::vec3f & _rhs, const float _val );
    vec3f operator*( const float _val, const mt::vec3f & _rhs );
    vec3f operator/( const mt::vec3f & _a, const mt::vec3f & _b );
    vec3f operator/( const mt::vec3f & _rhs, const float _val );
    vec3f operator-( vec3f _rhs );

    void ident_v3( mt::vec3f * const _out );

    float length_f( const mt::vec3f & _a, const mt::vec3f & _b );
    float length_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b );
    float length_v3( const mt::vec3f & _a );
    float sqrlength_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b );
    float sqrlength_v3( const mt::vec3f & _a );

    void dir_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b );
    float dir_v3_v3_f( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b );

    bool cmp_v3_v2( const mt::vec3f & _a, const mt::vec2f & _b );
    bool cmp_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b );

    void add_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b );
    void sub_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b );
    void scale_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, float _val );
    void mul_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b );
    void neg_v3( mt::vec3f * const _out );

    float dot_v3( const mt::vec3f & a );
    float dot_v3_v3( const mt::vec3f & a, const mt::vec3f & b );
    float dot_v3_v3_clamp( const mt::vec3f & a, const mt::vec3f & b );

    float dot_v3_v2( const mt::vec3f & a, const mt::vec2f & b );

    void reflect_v3_v3( mt::vec3f * const_out, const mt::vec3f & _a, const mt::vec3f & _b );
    vec3f reflect_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b );

    float project_to_line_v3_v3( mt::vec3f * const_out, const mt::vec3f & _a, const mt::vec3f & _b, const mt::vec3f & _c );

    void cross_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b );
    vec3f cross_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b );

    void cross_v3_v3_norm( mt::vec3f * const_out, const mt::vec3f & _a, const mt::vec3f & _b );

    void norm_v3_v3( mt::vec3f * const _out, const mt::vec3f & _rhs );
    float norm_v3_v3_f( mt::vec3f * const _out, const mt::vec3f & _rhs );
    vec3f norm_v3( const mt::vec3f & _rhs );
    void norm_safe_v3( mt::vec3f * const _out, const mt::vec3f & _rhs, float _err = 1e-06 );
    vec3f norm_safe_v3( const mt::vec3f & _rhs );

    float get_axis_angle( const mt::vec3f & dir, int axis );

    void linerp_v3( mt::vec3f * const _out, const mt::vec3f & _in1, const mt::vec3f & _in2, float _scale );
    float follow_v3( mt::vec3f * const _out, const mt::vec3f & _in1, const mt::vec3f & _in2, float _step );
};
