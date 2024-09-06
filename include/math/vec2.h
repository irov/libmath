#pragma once

#include "math/config.h"
#include "math/utils.h"

namespace mt
{
    struct vec2f
    {
        float x;
        float y;

        vec2f();
        vec2f( float _x, float _y );
        vec2f( const mt::vec2f & _v2 );
        explicit vec2f( const float * _v );

        mt::vec2f & operator = ( const mt::vec2f & _v2 );

        float operator [] ( size_t i ) const;
        float & operator [] ( size_t i );

        template <int K>
        float get() const
        {
            return this->operator [] ( K );
        }

        template <int K>
        void set( float _value )
        {
            this->operator [] ( K ) = _value;
        }

        mt::vec2f & operator+=( const mt::vec2f & _v2 );
        mt::vec2f & operator-=( const mt::vec2f & _v2 );
        mt::vec2f & operator/=( float _v );
        mt::vec2f & operator*=( float _v );
        mt::vec2f & operator/=( const mt::vec2f & _v2 );
        mt::vec2f & operator*=( const mt::vec2f & _v2 );

        void from_f2( const float * _v );

        float sqrlength() const;
        float length() const;

        float * buff();
        const float * buff() const;

        static const mt::vec2f & identity();
    };

    MT_CONSTEXPR bool is_ident_v2( const mt::vec2f & _a )
    {
        return mt::equal_f_z( _a.x ) && mt::equal_f_z( _a.y );
    }

    MT_CONSTEXPR bool is_one_v2( const mt::vec2f & _a )
    {
        return mt::equal_f_1( _a.x ) && mt::equal_f_1( _a.y );
    }

    MT_CONSTEXPR bool is_zero_v2( const mt::vec2f & _a )
    {
        return mt::equal_f_z( _a.x ) && mt::equal_f_z( _a.y );
    }

    MT_CONSTEXPR bool equal_v2_v2( const mt::vec2f & _v1, const mt::vec2f & _v2 )
    {
        return mt::equal_f_f( _v1.x, _v2.x ) && mt::equal_f_f( _v1.y, _v2.y );
    }

    bool operator==( const mt::vec2f & _a, const mt::vec2f & _b );
    bool operator!=( const mt::vec2f & _a, const mt::vec2f & _b );
    mt::vec2f operator+( const mt::vec2f & _a, const mt::vec2f & _b );
    mt::vec2f operator-( const mt::vec2f & _a, const mt::vec2f & _b );
    mt::vec2f operator*( const mt::vec2f & _a, const mt::vec2f & _b );
    mt::vec2f operator*( const mt::vec2f & _rhs, float _val );
    mt::vec2f operator*( float _val, const mt::vec2f & _rhs );
    mt::vec2f operator/( const mt::vec2f & _a, const mt::vec2f & _b );
    mt::vec2f operator/( const mt::vec2f & _rhs, float _val );
    mt::vec2f operator/( float _val, const mt::vec2f & _rhs );
    mt::vec2f operator-( vec2f _rhs );
    mt::vec2f operator+( vec2f _rhs );

    void ident_v2( mt::vec2f * const _a );

    float length_v2( const mt::vec2f & _a );
    float length_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b );
    float sqrlength_v2( const mt::vec2f & _a );
    float sqrlength_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b );

    float length_f( const mt::vec2f & _a, const mt::vec2f & _b );

    bool cmp_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b );

    void add_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    void sub_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    void dir_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    void mul_v2_f( mt::vec2f * const _out, const mt::vec2f & _a, float _val );
    void mul_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    void div_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    void inv_v2( mt::vec2f * const _out, const mt::vec2f & _in );
    void neg_v2( mt::vec2f * const _out );

    float dot_v2( const mt::vec2f & a );
    float dot_v2_v2( const mt::vec2f & a, const mt::vec2f & b );

    float norm_v2_f( mt::vec2f * const _out, const mt::vec2f & _rhs );
    void norm_v2_v2( mt::vec2f * const _out, const mt::vec2f & _rhs );
    mt::vec2f norm_v2( const mt::vec2f & _rhs );
    void norm_safe_v2( mt::vec2f * const _out, const mt::vec2f & _rhs, float _err = 0.00001f );
    mt::vec2f norm_safe( const mt::vec2f & _rhs );

    void perp_v2_v2( vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    void perp_v2( mt::vec2f * const _out, const mt::vec2f & _in );
    mt::vec2f perp( const mt::vec2f & _rhs );

    void perp_left_v2( mt::vec2f * const _out, const mt::vec2f & _in );
    mt::vec2f perp_left( const mt::vec2f & _in );

    float is_left_v2( const mt::vec2f & p0, const mt::vec2f & p1, const mt::vec2f & p2 );
    float cross_v2( const mt::vec2f & a, const mt::vec2f & b );

    void project_v2_v2( mt::vec2f * const out, const mt::vec2f & a, const mt::vec2f & b );

    mt::vec2f slerp_v2_v2( const mt::vec2f & a, const mt::vec2f & b, float t );

    void rotate_v2( mt::vec2f * const _out, float _angle );

    void direction( mt::vec2f * const _out, float _angle );
    float signed_angle( const mt::vec2f & _vec );
};
