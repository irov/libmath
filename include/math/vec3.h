#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    struct vec3f
    {
        typedef float value_type;
        typedef float element_type;

        float x;
        float y;
        float z;

        MT_METHOD_INLINE vec3f();
        MT_METHOD_INLINE vec3f( float _x, float _y, float _z );
        MT_METHOD_INLINE vec3f( const vec3f & _v );

        MT_METHOD_INLINE explicit vec3f( const vec2f & _v, float _z );

        MT_METHOD_INLINE vec3f & operator = ( const vec3f & _rhs );

        MT_METHOD_INLINE float operator [] ( size_t i ) const;
        MT_METHOD_INLINE float & operator [] ( size_t i );

        MT_METHOD_INLINE vec3f & operator += ( const vec3f & _rhs );
        MT_METHOD_INLINE vec3f & operator -= ( const vec3f & _rhs );
        MT_METHOD_INLINE vec3f & operator /= ( const float _rhs );
        MT_METHOD_INLINE vec3f & operator *= ( const float _rhs );
        MT_METHOD_INLINE float sqrlength() const;
        MT_METHOD_INLINE float length() const;

        MT_METHOD_INLINE vec2f to_vec2f() const;
        MT_METHOD_INLINE void from_f3( const float * _v );
        MT_METHOD_INLINE void from_f2( const float * _v );

        MT_METHOD_INLINE float * buff();
        MT_METHOD_INLINE const float * buff() const;

        static MT_METHOD_INLINE const vec3f & identity();
    };

    MT_FUNCTION_INLINE bool operator==( const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE bool operator!=( const vec3f& _a, const vec3f& _b );

    MT_FUNCTION_INLINE vec3f operator+( const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE vec3f operator-( const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE vec3f operator*( const vec3f& _a, const vec3f & _b );
    MT_FUNCTION_INLINE vec3f operator*( const vec3f& _rhs, const float _val );
    MT_FUNCTION_INLINE vec3f operator*( const float _val, const vec3f& _rhs );
    MT_FUNCTION_INLINE vec3f operator/( const vec3f& _a, const vec3f & _b );
    MT_FUNCTION_INLINE vec3f operator/( const vec3f& _rhs, const float _val );
    MT_FUNCTION_INLINE vec3f operator-( vec3f _rhs );

    MT_FUNCTION_INLINE void ident_v3( vec3f& _a );
    MT_FUNCTION_INLINE bool is_ident_v3( const vec3f & _a );

    MT_FUNCTION_INLINE float length( const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE float length_v3_v3( const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE float length_v3( const vec3f& _a );
    MT_FUNCTION_INLINE float sqrlength_v3_v3( const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE float sqrlength_v3( const vec3f& _a );

    MT_FUNCTION_INLINE void dir_v3_v3( vec3f & _out, const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE float dir_v3_v3_f( vec3f & _out, const vec3f& _a, const vec3f& _b );

    MT_FUNCTION_INLINE bool cmp_v3_v2( const vec3f& _a, const vec2f& _b );
    MT_FUNCTION_INLINE bool cmp_v3_v3( const vec3f& _a, const vec3f& _b );

    MT_FUNCTION_INLINE void add_v3_v3( vec3f& _out, const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE void sub_v3_v3( vec3f& _out, const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE void scale_v3_v3( vec3f& _out, const vec3f& _a, float _val );
    MT_FUNCTION_INLINE void mul_v3_v3( vec3f& _out, const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE void neg_v3( vec3f& _out );

    MT_FUNCTION_INLINE float dot_v3( const vec3f &a );
    MT_FUNCTION_INLINE float dot_v3_v3( const vec3f &a, const vec3f &b );
    MT_FUNCTION_INLINE float dot_v3_v3_clamp( const vec3f &a, const vec3f &b );

    MT_FUNCTION_INLINE float dot_v3_v2( const vec3f &a, const vec2f &b );

    MT_FUNCTION_INLINE void reflect_v3_v3( vec3f& _out, const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE vec3f reflect_v3_v3( const vec3f& _a, const vec3f& _b );

    MT_FUNCTION_INLINE float project_to_line_v3_v3( vec3f& _out, const vec3f& _a, const vec3f& _b, const vec3f & _c );

    MT_FUNCTION_INLINE void cross_v3_v3( vec3f& _out, const vec3f& _a, const vec3f& _b );
    MT_FUNCTION_INLINE vec3f cross_v3_v3( const vec3f& _a, const vec3f& _b );

    MT_FUNCTION_INLINE void cross_v3_v3_norm( vec3f& _out, const vec3f& _a, const vec3f& _b );

    MT_FUNCTION_INLINE void norm_v3_v3( vec3f& _out, const vec3f& _rhs );
    MT_FUNCTION_INLINE float norm_v3_v3_f( vec3f& _out, const vec3f& _rhs );
    MT_FUNCTION_INLINE vec3f norm_v3( const vec3f& _rhs );
    MT_FUNCTION_INLINE void norm_safe_v3( vec3f& out, const vec3f& _rhs, float err = 1e-06 );
    MT_FUNCTION_INLINE vec3f norm_safe_v3( const vec3f& _rhs );

    MT_FUNCTION_INLINE float get_axis_angle( const vec3f & dir, int axis );

    MT_FUNCTION_INLINE void linerp_v3( mt::vec3f & _out, const mt::vec3f & _in1, const mt::vec3f & _in2, float _scale );
    MT_FUNCTION_INLINE float follow_v3( mt::vec3f & _out, const mt::vec3f & _in1, const mt::vec3f & _in2, float _step );
};

#if MT_FORCE_INLINE == 1
#include "math/vec3_inline.h"
#endif
