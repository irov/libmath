#pragma once

#include "math/config.h"

#include "math/utils.h"

#include "math/vec4.h"
#include "math/mat3.h"

namespace mt
{
    struct mat4f
    {
        mt::vec4f v0;
        mt::vec4f v1;
        mt::vec4f v2;
        mt::vec4f v3;

        mat4f();
        mat4f( const mt::vec4f & _v0, const mt::vec4f & _v1, const mt::vec4f & _v2, const mt::vec4f & _v3 );
        mat4f( const mt::mat4f & _rhs );

        mt::vec4f & operator [] ( size_t i );
        const mt::vec4f & operator [] ( size_t i )const;

        mt::mat4f & operator = ( const mt::mat4f & _rhs );

        void from_f12( const float * _v );
        void from_f16( const float * _v );

        float * buff();
        const float * buff() const;

        static const mt::mat4f & identity();
    };

    bool operator==( const mt::mat4f & _a, const mt::mat4f & _b );
    bool operator!=( const mt::mat4f & _a, const mt::mat4f & _b );

    mt::vec3f operator*( const mt::mat4f & m, const mt::vec3f & v );
    mt::vec3f operator*( const mt::vec3f & v, const mt::mat4f & m );

    mt::vec4f operator*( const mt::mat4f & m, const mt::vec4f & v );
    mt::vec4f operator*( const mt::vec4f & v, const mt::mat4f & m );

    mt::mat4f operator*( const mt::mat4f & _a, const mt::mat4f & _b );
    mt::mat4f operator*( const mt::mat4f & _a, const mt::mat3f & _b );

    mt::mat4f operator+( const mt::mat4f & _a, const mt::mat4f & _b );
    mt::mat4f operator-( const mt::mat4f & _a, const mt::mat4f & _b );

    bool cmp_m4_m4( const mt::mat4f & _a, const mt::mat4f & _b );

    void mul_m4_v2_z( mt::vec2f * const _out, const mt::mat4f & _m );
    void mul_m4_v3_z( mt::vec3f * const _out, const mt::mat4f & _m );
    void mul_m4_v4_z( mt::vec4f * const _out, const mt::mat4f & _m );

    void mul_v2_m4_v2( mt::vec2f * const _out, const mt::mat4f & _m, const mt::vec2f & _v );
    void mul_v3_m4_v3( mt::vec3f * const _out, const mt::mat4f & _m, const mt::vec3f & _v );

    void mul_v3_v3_m4( mt::vec3f * const _out, const mt::vec3f & _v, const mt::mat4f & _m );
    void mul_v3_v3_m4_r( mt::vec3f * const _out, const mt::vec3f & _v, const mt::mat4f & _m );
    float mul_v3_v3_m4_proj( mt::vec3f * const _out, const mt::vec3f & _v, const mt::mat4f & _m );

    void mul_v2_v2z_m4( mt::vec2f * const _out, const mt::mat4f & _m );
    void mul_v2_v2_m4( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat4f & _m );
    void mul_v2_v2_m4_r( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat4f & _m );
    void mul_v2_v3_m4( mt::vec2f * const _out, const mt::vec3f & _v, const mt::mat4f & _m );
    void mul_v2_v3_m4_r( mt::vec2f * const _out, const mt::vec3f & _v, const mt::mat4f & _m );
    void mul_v3_v2_m4( mt::vec3f * const _out, const mt::vec2f & _v, const mt::mat4f & _m );
    void mul_v3_v2_m4_r( mt::vec3f * const _out, const mt::vec2f & _v, const mt::mat4f & _m );
    void mul_v3_v2z_m4( mt::vec3f * const _out, const mt::mat4f & _m );

    void mul_m4_v4( mt::vec4f * const _out, const mt::mat4f & _m, const mt::vec4f & _v );
    void mul_v4_m4( mt::vec4f * const _out, const mt::vec4f & _a, const mt::mat4f & _b );
    void mul_v4_m4_r( mt::vec4f * const _out, const mt::vec4f & _a, const mt::mat4f & _b );
    void mul_v4_v3_m4( mt::vec4f * const _out, const mt::vec3f & _a, const mt::mat4f & _b );
    void mul_v3_v3_m4_homogenize( mt::vec3f * const _out, const mt::vec3f & _a, const mt::mat4f & _b );
    void mul_v2_v3_m4_homogenize( mt::vec2f * const _out, const mt::vec3f & _a, const mt::mat4f & _b );
    void mul_v3_v2_m4_homogenize( mt::vec3f * const _out, const mt::vec2f & _a, const mt::mat4f & _b );
    void mul_v2_v2_m4_homogenize( mt::vec2f * const _out, const mt::vec2f & _a, const mt::mat4f & _b );
    void mul_v2_v2z_m4_homogenize( mt::vec2f * const _out, const mt::mat4f & _b );


    void mul_m4_m4( mt::mat4f * const _out, const mt::mat4f & _a, const mt::mat4f & _b );
    void mul_m4_m4_r( mt::mat4f * const _out, const mt::mat4f & _a, const mt::mat4f & _b );

    void mul_v4_m3_i( mt::vec4f * const _out, const mt::vec4f & _a, const mt::mat3f & _b );
    void mul_m4_m3( mt::mat4f * const _out, const mt::mat4f & _a, const mt::mat3f & _b );

    void add_m4_m4( mt::mat4f * const _out, const mt::mat4f & _a, const mt::mat4f & _b );
    void sub_m4_m4( mt::mat4f * const _out, const mt::mat4f & _a, const mt::mat4f & _b );

    void scale_m4_m4( mt::mat4f * const _out, const mt::mat4f & _rhs, const mt::vec4f & _val );
    void scale_m4( mt::mat4f * const _out, const mt::vec4f & _val );

    void scale_rotate_m4_m4( mt::mat4f * const _out, const mt::mat4f & _rhs, const mt::vec3f & _val );
    void scale_rotate_m4( mt::mat4f * const _out, const mt::vec3f & _val );

    void zero_m4( mt::mat4f * const _out );
    void ident_m4( mt::mat4f * const _out );

    bool is_ident_m34( const mt::mat4f & _out );

    void get_col_m4( mt::vec4f * const out, const mt::mat4f & _rhs, int _index );
    mt::vec4f get_col_m4( const mt::mat4f & _rhs, int _index );
    void set_col_m4( mt::mat4f * const out, const mt::vec4f & _rhs, int _index );

    void transpose_m4_m4( mt::mat4f * const _out, const mt::mat4f & _rhs );
    mt::mat4f transpose_m4( const mt::mat4f & _rhs );

    void extract_m4_m3( mt::mat3f * const _out, const mt::mat4f & _rhs );

    void inv_m4_m4( mt::mat4f * const _out, const mt::mat4f & _in );
    mt::mat4f inv_m4( const mt::mat4f & _rhs );

    void rotate_axis_m4( mt::mat4f * const out, const mt::vec3f & u, float degrees );

    void make_projection_fov_m4( mt::mat4f * const _out, float _fov, float _aspect, float _zn, float _zf );
    void make_projection_fov2_m4( mt::mat4f * const _out, float _fov, float _aspect, float _zn, float _zf );
    void make_projection_ortho_lh_m4( mt::mat4f * const _out, float _left, float _right, float _top, float _bottom, float _near, float _far );
    void make_projection_frustum_m4( mt::mat4f * const _out, float _left, float _right, float _top, float _bottom, float _near, float _far );

    void make_rotate_m4_euler( mt::mat4f * const _out, float _x, float _y, float _z );
    void make_rotate_m4_direction( mt::mat4f * const _out, const mt::vec3f & _direction, const mt::vec3f & _up );
    void make_rotate_m4_fixed_up( mt::mat4f * const _out, const mt::vec3f & _direction, const mt::vec3f & _up );
    void make_rotate_m4_fixed_left( mt::mat4f * const _out, const mt::vec3f & _direction, const mt::vec3f & _left );
    void make_rotate_m4_axes( mt::mat4f * const _out, const mt::vec3f & _direction, const mt::vec3f & _left, const mt::vec3f & _up );


    void make_rotate_x_axis_m4( mt::mat4f * const _out, float _angle );
    void make_rotate_y_axis_m4( mt::mat4f * const _out, float _angle );
    void make_rotate_z_axis_m4( mt::mat4f * const _out, float _angle );

    void make_skew_m4( mt::mat4f * const _out, float _x, float _y );
    void make_scale_m4( mt::mat4f * const _out, float _x, float _y, float _z );
    void make_translation_m4_v3( mt::mat4f * const _out, const mt::vec3f & _pos );
    void make_translation_m4( mt::mat4f * const _out, float _x, float _y, float _z );

    void make_lookat_m4( mt::mat4f * const _out, const mt::vec3f & _eye, const mt::vec3f & _dir, const mt::vec3f & _up, float _sign );

    void project_m4( mt::vec3f * const _out, const mt::vec3f & _vertex, float _width, float _height, const mt::mat4f & _projection, const mt::mat4f & _view, const mt::mat4f & _world );

    void make_euler_angles( mt::vec3f * const _euler, const mt::mat4f & _rotate );
}
