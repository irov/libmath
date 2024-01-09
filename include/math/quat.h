#pragma once

#include "math/config.h"

#include "math/utils.h"

#include "math/mat4.h"

namespace mt
{
    struct quatf
    {
        float x;
        float y;
        float z;
        float w;

        quatf();
        quatf( float _x, float _y, float _z, float _w );
        quatf( float _angle, const mt::vec3f & _v );
        quatf( const mt::quatf & _q );

        void rotate( mt::vec3f * const _v ) const;
        void multiply( const mt::quatf & left, const mt::vec3f & right );
        float & operator[]( size_t i );
        const float operator[]( size_t i )const;

        quatf & operator=( const mt::quatf & q );

        float length() const;
        void normalize();

        float getYaw( bool _reprojectAxis = true ) const;
        float getPitch( bool _reprojectAxis = true ) const;
    };

    bool operator==( const mt::quatf & _a, const mt::quatf & _b );
    bool operator!=( const mt::quatf & _a, const mt::quatf & _b );
    quatf operator+( const mt::quatf & _a, const mt::quatf & _b );
    quatf operator-( const mt::quatf & _a, const mt::quatf & _b );
    quatf operator*( const mt::quatf & _a, const mt::quatf & _b );
    vec3f operator*( const mt::quatf & _q, const mt::vec3f & _v3 );
    quatf operator*( const mt::quatf & _q, float _v );
    quatf operator/( const mt::quatf & _q, float _v );

    bool cmp_q_q( const mt::quatf & _a, const mt::quatf & _b );

    void add_q_q( mt::quatf * const _out, const mt::quatf & _a, const mt::quatf & _b );
    void sub_q_q( mt::quatf * const _out, const mt::quatf & _a, const mt::quatf & _b );
    void mul_q_q( mt::quatf * const _out, const mt::quatf & _q1, const mt::quatf & _q2 );
    void mul_q_v3( mt::vec3f * const _out, const mt::quatf & _q, const mt::vec3f & _v3 );
    void scale_q_s( mt::quatf * const _out, const mt::quatf & _q, float _v );

    float dot_q_q( const mt::quatf & _a, const mt::quatf & _b );

    void norm_q_q( mt::quatf * const _out, const mt::quatf & _rhs );
    quatf norm_q( const mt::quatf & _rhs );
    void norm_safe_q( mt::quatf * const out, const mt::quatf & _rhs );
    quatf norm_safe_q( const mt::quatf & _rhs );

    void lerp_q_q( mt::quatf * const _q, const mt::quatf & _q1, const mt::quatf & _q2, float _t );

    void q_from_angle_axis( mt::quatf * const out, const mt::vec3f & _rhs, float _val );
    quatf q_from_angle_axis( const mt::vec3f & _rhs, float _val );

    void inverse_q( mt::quatf * const _out, const mt::quatf & _rhs );
    quatf inverse_q( const mt::quatf & _rhs );

    void exp_q( mt::quatf * const _out, const mt::quatf & _rhs );
    quatf exp_q( const mt::quatf & _rhs );

    void log_q( mt::quatf * const _out, const mt::quatf & _rhs );
    quatf log_q( const mt::quatf & _rhs );

    void q_from_rot_m3( mt::quatf * const out, const mt::mat3f & _rhs );
    quatf q_from_rot_m3( const mt::mat3f & _rhs );

    void q_to_rot_m3( mt::mat3f * const out, const mt::quatf & _rhs );
    mat3f q_to_rot_m3( const mt::quatf & _rhs );

    void q_from_rot_m4( mt::quatf * const _out, const mt::mat4f & _rhs );
    quatf q_from_rot_m4( const mt::mat4f & _rhs );

    void q_from_axes( mt::quatf * const out, const mt::vec3f & _x, const mt::vec3f & _y, const mt::vec3f & _z );
    quatf q_from_axes( const mt::vec3f & _x, const mt::vec3f & _y, const mt::vec3f & _z );

    void q_to_angle_axis( mt::vec3f * const _out, float * const _out1, const mt::quatf & _rhs );
    vec3f q_to_angle_axis( float * const _out, const mt::quatf & _rhs );

    void rotate_q( mt::quatf * const _out, const mt::vec3f & axis, float angle );

    void qpos_to_rot_m4( mt::mat4f * const out, const mt::quatf & _rhs, const mt::vec3f & _pos );
    mt::mat4f qpos_to_rot_m4( const mt::quatf & _rhs, const mt::vec3f & _pos );

    void make_quat_from_euler( mt::quatf * const _out, const mt::vec3f & _euler );
    void quat_to_euler( const mt::quatf & _q, mt::vec3f * const _euler );

    void make_quat_from_angle( mt::quatf * const _out, float _angle );

    float quatzw_to_angle( const mt::quatf & _q );
};
