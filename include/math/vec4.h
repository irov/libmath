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

        MT_METHOD_INLINE vec4f();
        MT_METHOD_INLINE vec4f( float _x, float _y, float _z, float _w );
        MT_METHOD_INLINE vec4f( const mt::vec2f & _v0, const mt::vec2f & _v1 );
        MT_METHOD_INLINE vec4f( const mt::vec4f & _v );
        MT_METHOD_INLINE explicit vec4f( const mt::vec3f & _v );
        MT_METHOD_INLINE vec4f( const mt::vec3f & _v, float _w );

        MT_METHOD_INLINE mt::vec4f & operator=( const mt::vec4f & _rhs );

        MT_METHOD_INLINE float & operator []( size_t i );
        MT_METHOD_INLINE const float operator []( size_t i ) const;

        MT_METHOD_INLINE mt::vec4f & operator+=( const mt::vec4f & _rhs );
        MT_METHOD_INLINE mt::vec4f & operator-=( const mt::vec4f & _rhs );
        MT_METHOD_INLINE mt::vec4f & operator *= ( const mt::vec2f & _rhs );
        MT_METHOD_INLINE mt::vec4f & operator /= ( const mt::vec2f & _rhs );
        MT_METHOD_INLINE mt::vec4f & operator *= ( const float _rhs );
        MT_METHOD_INLINE mt::vec4f & operator /= ( const float _rhs );


        MT_METHOD_INLINE float sqrlength() const;
        MT_METHOD_INLINE float length() const;

        MT_METHOD_INLINE const mt::vec3f & to_vec3f() const;

        MT_METHOD_INLINE float * buff();
        MT_METHOD_INLINE const float * buff() const;
    };

    MT_FUNCTION_INLINE bool operator==( const mt::vec4f & _a, const mt::vec4f & _b );
    MT_FUNCTION_INLINE bool operator!=( const mt::vec4f & _a, const mt::vec4f & _b );

    MT_FUNCTION_INLINE mt::vec4f operator+( const mt::vec4f & _a, const mt::vec4f & _b );
    MT_FUNCTION_INLINE mt::vec4f operator-( const mt::vec4f & _a, const mt::vec4f & _b );
    MT_FUNCTION_INLINE mt::vec4f operator*( const mt::vec4f & _rhs, const mt::vec4f & _val );
    MT_FUNCTION_INLINE mt::vec4f operator/( const mt::vec4f & _rhs, const mt::vec4f & _val );
    MT_FUNCTION_INLINE mt::vec4f operator*( const mt::vec4f & _rhs, const mt::vec2f & _val );
    MT_FUNCTION_INLINE mt::vec4f operator/( const mt::vec4f & _rhs, const mt::vec2f & _val );
    MT_FUNCTION_INLINE mt::vec4f operator*( const mt::vec4f & _rhs, const float _val );
    MT_FUNCTION_INLINE mt::vec4f operator/( const mt::vec4f & _rhs, const float _val );
    MT_FUNCTION_INLINE mt::vec4f operator-( vec4f _rhs );

    MT_FUNCTION_INLINE void ident_v4( mt::vec4f * const _rhs );
    MT_FUNCTION_INLINE float length_v4( const mt::vec4f & _rhs );

    MT_FUNCTION_INLINE void extract_v4_v3( mt::vec3f * const _out, const mt::vec4f & _rhs );

    MT_FUNCTION_INLINE void set_v4_v3( mt::vec4f * const _out, const mt::vec3f & _rhs );

    MT_FUNCTION_INLINE bool cmp_v4_v4( const mt::vec4f & _a, const mt::vec4f & _b );

    MT_FUNCTION_INLINE void add_v4_v3( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec3f & _b );
    MT_FUNCTION_INLINE void add_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec4f & _b );

    MT_FUNCTION_INLINE void sub_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec4f & _b );
    MT_FUNCTION_INLINE void scale_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, float _val );
    MT_FUNCTION_INLINE void neg_v4( mt::vec4f * const _out );

    MT_FUNCTION_INLINE float dot_v4_z( const mt::vec4f & a );
    MT_FUNCTION_INLINE float dot_v4_v2( const mt::vec4f & a, const mt::vec2f & b );
    MT_FUNCTION_INLINE float dot_v4_v3( const mt::vec4f & a, const mt::vec3f & b );
    MT_FUNCTION_INLINE float dot_v4_v4( const mt::vec4f & a, const mt::vec4f & b );

    MT_FUNCTION_INLINE void norm_v4( mt::vec4f * const _out, const mt::vec4f & _rhs );
    MT_FUNCTION_INLINE mt::vec4f norm_v4( const mt::vec4f & _rhs );
    MT_FUNCTION_INLINE void norm_safe_v4( mt::vec4f * const _out, const mt::vec4f & _rhs, float _err = 1e-06 );
    MT_FUNCTION_INLINE mt::vec4f norm_safe_v4( const mt::vec4f & _rhs );

    MT_FUNCTION_INLINE void homogenize_v4( mt::vec4f * const _out, const mt::vec4f & _rhs );
    MT_FUNCTION_INLINE void homogenize_v3_v4( mt::vec3f * const _out, const mt::vec4f & _rhs );
    MT_FUNCTION_INLINE mt::vec4f homogenize_v4( const mt::vec4f & _rhs );
};

#if MT_FORCE_INLINE == 1
#include "math/vec4.cpp"
#endif
