#pragma once

#include "math/config.h"
#include "math/utils.h"

namespace mt
{
    struct vec2f
    {
        float x;
        float y;

        MT_METHOD_INLINE vec2f();
        MT_METHOD_INLINE vec2f( float _x, float _y );
        MT_METHOD_INLINE vec2f( const mt::vec2f & _v2 );
        MT_METHOD_INLINE explicit vec2f( const float * _v );

        MT_METHOD_INLINE mt::vec2f & operator = ( const mt::vec2f & _v2 );

        MT_METHOD_INLINE float operator [] ( size_t i ) const;
        MT_METHOD_INLINE float & operator [] ( size_t i );

        template <int K>
        MT_METHOD_INLINE float get() const
        {
            return this->operator [] ( K );
        }

        template <int K>
        MT_METHOD_INLINE void set( float _value )
        {
            this->operator [] ( K ) = _value;
        }

        MT_METHOD_INLINE mt::vec2f & operator+=( const mt::vec2f & _v2 );
        MT_METHOD_INLINE mt::vec2f & operator-=( const mt::vec2f & _v2 );
        MT_METHOD_INLINE mt::vec2f & operator/=( float _v );
        MT_METHOD_INLINE mt::vec2f & operator*=( float _v );
        MT_METHOD_INLINE mt::vec2f & operator/=( const mt::vec2f & _v2 );
        MT_METHOD_INLINE mt::vec2f & operator*=( const mt::vec2f & _v2 );

        MT_METHOD_INLINE void from_f2( const float * _v );

        MT_METHOD_INLINE float sqrlength() const;
        MT_METHOD_INLINE float length() const;

        MT_METHOD_INLINE float * buff();
        MT_METHOD_INLINE const float * buff() const;

        static MT_METHOD_INLINE const mt::vec2f & identity();
    };

    MT_CONSTEXPR bool is_ident_v2( const mt::vec2f & _a )
    {
        return mt::equal_f_z( _a.x ) && mt::equal_f_z( _a.y );
    }

    MT_CONSTEXPR bool is_one_v2( const mt::vec2f & _a )
    {
        return mt::equal_f_1( _a.x ) && mt::equal_f_1( _a.y );
    }

    MT_FUNCTION_INLINE bool operator==( const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE bool operator!=( const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE mt::vec2f operator+( const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE mt::vec2f operator-( const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE mt::vec2f operator*( const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE mt::vec2f operator*( const mt::vec2f & _rhs, float _val );
    MT_FUNCTION_INLINE mt::vec2f operator*( float _val, const mt::vec2f & _rhs );
    MT_FUNCTION_INLINE mt::vec2f operator/( const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE mt::vec2f operator/( const mt::vec2f & _rhs, float _val );
    MT_FUNCTION_INLINE mt::vec2f operator/( float _val, const mt::vec2f & _rhs );
    MT_FUNCTION_INLINE mt::vec2f operator-( vec2f _rhs );
    MT_FUNCTION_INLINE mt::vec2f operator+( vec2f _rhs );

    MT_FUNCTION_INLINE void ident_v2( mt::vec2f * const _a );

    MT_FUNCTION_INLINE float length_v2( const mt::vec2f & _a );
    MT_FUNCTION_INLINE float sqrlength_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE float length_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b );

    MT_FUNCTION_INLINE float length_f( const mt::vec2f & _a, const mt::vec2f & _b );

    MT_FUNCTION_INLINE bool cmp_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b );

    MT_FUNCTION_INLINE void add_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE void sub_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE void dir_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE void mul_v2_f( mt::vec2f * const _out, const mt::vec2f & _a, float _val );
    MT_FUNCTION_INLINE void mul_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE void div_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE void inv_v2( mt::vec2f * const _out, const mt::vec2f & _in );
    MT_FUNCTION_INLINE void neg_v2( mt::vec2f * const _out );

    MT_FUNCTION_INLINE float dot_v2( const mt::vec2f & a );
    MT_FUNCTION_INLINE float dot_v2_v2( const mt::vec2f & a, const mt::vec2f & b );

    MT_FUNCTION_INLINE float norm_v2_f( mt::vec2f * const _out, const mt::vec2f & _rhs );
    MT_FUNCTION_INLINE void norm_v2_v2( mt::vec2f * const _out, const mt::vec2f & _rhs );
    MT_FUNCTION_INLINE mt::vec2f norm_v2( const mt::vec2f & _rhs );
    MT_FUNCTION_INLINE void norm_safe_v2( mt::vec2f * const _out, const mt::vec2f & _rhs, float _err = 0.00001f );
    MT_FUNCTION_INLINE mt::vec2f norm_safe( const mt::vec2f & _rhs );

    MT_FUNCTION_INLINE void perp_v2_v2( vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE void perp_v2( mt::vec2f * const _out, const mt::vec2f & _in );
    MT_FUNCTION_INLINE mt::vec2f perp( const mt::vec2f & _rhs );

    MT_FUNCTION_INLINE void perp_left_v2( mt::vec2f * const _out, const mt::vec2f & _in );
    MT_FUNCTION_INLINE mt::vec2f perp_left( const mt::vec2f & _in );

    MT_FUNCTION_INLINE float is_left_v2( const mt::vec2f & p0, const mt::vec2f & p1, const mt::vec2f & p2 );
    MT_FUNCTION_INLINE float cross_v2( const mt::vec2f & a, const mt::vec2f & b );

    MT_FUNCTION_INLINE void project_v2_v2( mt::vec2f * const out, const mt::vec2f & a, const mt::vec2f & b );

    MT_FUNCTION_INLINE mt::vec2f slerp_v2_v2( const mt::vec2f & a, const mt::vec2f & b, float t );

    MT_FUNCTION_INLINE void rotate_v2( mt::vec2f * const _out, float _angle );

    MT_FUNCTION_INLINE void direction( mt::vec2f * const _out, float _angle );
    MT_FUNCTION_INLINE float signed_angle( const mt::vec2f & _vec );
};

#if MT_FORCE_INLINE == 1
#include "math/vec2.cpp"
#endif
