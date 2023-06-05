#pragma once

#include "math/config.h"

#include "math/vec3.h"

namespace mt
{
    struct mat3f
    {
        mt::vec3f v0;
        mt::vec3f v1;
        mt::vec3f v2;

        MT_METHOD_INLINE mat3f();
        MT_METHOD_INLINE mat3f( const mt::mat3f & _rhs );
        MT_METHOD_INLINE mat3f( const mt::vec3f & _v0, const mt::vec3f & _v1, const mt::vec3f & _v2 );
        MT_METHOD_INLINE mat3f( float _v00, float _v01, float _v02, float _v10, float _v11, float _v12, float _v20, float _v21, float _v22 );

        MT_METHOD_INLINE mt::vec3f & operator[]( size_t i );
        MT_METHOD_INLINE const mt::vec3f & operator[]( size_t i )const;

        MT_METHOD_INLINE mt::mat3f & operator=( const mt::mat3f & _rhs );

        MT_METHOD_INLINE float * buff();
    };

    MT_FUNCTION_INLINE bool operator==( const mt::mat3f & _a, const mt::mat3f & _b );
    MT_FUNCTION_INLINE bool operator!=( const mt::mat3f & _a, const mt::mat3f & _b );
    MT_FUNCTION_INLINE mt::vec3f operator*( const mt::mat3f & _m, const mt::vec3f & _v );
    MT_FUNCTION_INLINE mt::vec3f operator*( const mt::vec3f & _v, const mt::mat3f & _m );
    MT_FUNCTION_INLINE mt::vec2f operator*( const mt::vec2f & _v, const mt::mat3f & _m );
    MT_FUNCTION_INLINE mt::mat3f operator*( const mt::mat3f & _a, const mt::mat3f & _b );
    MT_FUNCTION_INLINE mt::mat3f operator+( const mt::mat3f & _a, const mt::mat3f & _b );
    MT_FUNCTION_INLINE mt::mat3f operator-( const mt::mat3f & _a, const mt::mat3f & _b );
    MT_FUNCTION_INLINE mt::mat3f operator*( const mt::mat3f & _rhs, float _val );

    MT_FUNCTION_INLINE float * buff_m3( const mt::mat3f & _a );

    MT_FUNCTION_INLINE bool cmp_m3_m3( const mt::mat3f & _a, const mt::mat3f & _b );

    MT_FUNCTION_INLINE void mul_m3_v3( mt::vec3f * const _out, const mt::mat3f & _m, const mt::vec3f & _v );
    MT_FUNCTION_INLINE void mul_m3_v2( mt::vec2f * const _out, const mt::mat3f & _m, const mt::vec2f & _v );
    MT_FUNCTION_INLINE void mul_v3_m3( mt::vec3f * const _out, const mt::vec3f & _v, const mt::mat3f & _m );
    MT_FUNCTION_INLINE void mul_v2_m3( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat3f & _m );
    MT_FUNCTION_INLINE void mul_v2_m3_r( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat3f & _m );

    MT_FUNCTION_INLINE void mul_m3_m3( mt::mat3f * const _out, const mt::mat3f & _a, const mt::mat3f & _b );
    MT_FUNCTION_INLINE void add_m3_m3( mt::mat3f * const _out, const mt::mat3f & _a, const mt::mat3f & _b );
    MT_FUNCTION_INLINE void sub_m3_m3( mt::mat3f * const _out, const mt::mat3f & _a, const mt::mat3f & _b );
    MT_FUNCTION_INLINE void scale_m3_s( mt::mat3f * const _out, const mt::mat3f & _rhs, float _val );
    MT_FUNCTION_INLINE void scale_m3_s( mt::mat3f * const _out, float _val );

    MT_FUNCTION_INLINE void scale_m3_m3( mt::mat3f * const _out, const mt::mat3f & _rhs, const mt::vec3f & _val );
    MT_FUNCTION_INLINE void scale_m3( mt::mat3f * const _out, const mt::vec3f & _val );

    MT_FUNCTION_INLINE void transpose_m3( mt::mat3f * const _out, const mt::mat3f & _rhs );
    MT_FUNCTION_INLINE mt::mat3f transpose_m3( const mt::mat3f & _rhs );

    MT_FUNCTION_INLINE float det_m3( const mt::mat3f & _rhs );

    MT_FUNCTION_INLINE void inv_m3( mt::mat3f * const _out, const mt::mat3f & _rhs );

    MT_FUNCTION_INLINE void ident_m3( mt::mat3f * const _out );

    MT_FUNCTION_INLINE void get_col_m3( mt::vec3f * const out, const mt::mat3f & _rhs, int _index );
    MT_FUNCTION_INLINE mt::vec3f get_col_m3( const mt::mat3f & _rhs, int _index );
    MT_FUNCTION_INLINE void set_col_m3( mt::mat3f * const out, const mt::vec3f & _rhs, int _index );

    MT_FUNCTION_INLINE void set_m3_from_axes( mt::mat3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b, const mt::vec3f & _c );
    MT_FUNCTION_INLINE mt::mat3f set_m3_from_axes( const mt::vec3f & _a, const mt::vec3f & _b, const mt::vec3f & _c );

    MT_FUNCTION_INLINE void make_rotate_x_axis_m3( mt::mat3f * const _out, float _angle );
    MT_FUNCTION_INLINE void make_rotate_y_axis_m3( mt::mat3f * const _out, float _angle );
    MT_FUNCTION_INLINE void make_rotate_z_axis_m3( mt::mat3f * const _out, float _angle );

    MT_FUNCTION_INLINE void translate_m3( mt::mat3f * const _out, const mt::mat3f & _in, const mt::vec2f & _offset );
}

#if MT_FORCE_INLINE == 1
#include "math/mat3.cpp"
#endif
