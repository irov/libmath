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

        MT_METHOD_INLINE quatf();
        MT_METHOD_INLINE quatf( float _x, float _y, float _z, float _w );
        MT_METHOD_INLINE quatf( float _angle, const mt::vec3f & _v );
        MT_METHOD_INLINE quatf( const mt::quatf & _q );

        MT_METHOD_INLINE void rotate( mt::vec3f * const _v ) const;
        MT_METHOD_INLINE void multiply( const mt::quatf & left, const mt::vec3f & right );
        MT_METHOD_INLINE float & operator[]( size_t i );
        MT_METHOD_INLINE const float operator[]( size_t i )const;

        MT_METHOD_INLINE quatf & operator=( const mt::quatf & q );

        MT_METHOD_INLINE float length() const;
        MT_METHOD_INLINE void normalize();

        MT_METHOD_INLINE float getYaw( bool _reprojectAxis = true ) const;
        MT_METHOD_INLINE float getPitch( bool _reprojectAxis = true ) const;
    };

    MT_FUNCTION_INLINE bool operator==( const mt::quatf & _a, const mt::quatf & _b );
    MT_FUNCTION_INLINE bool operator!=( const mt::quatf & _a, const mt::quatf & _b );
    MT_FUNCTION_INLINE quatf operator+( const mt::quatf & _a, const mt::quatf & _b );
    MT_FUNCTION_INLINE quatf operator-( const mt::quatf & _a, const mt::quatf & _b );
    MT_FUNCTION_INLINE quatf operator*( const mt::quatf & _a, const mt::quatf & _b );
    MT_FUNCTION_INLINE vec3f operator*( const mt::quatf & _q, const mt::vec3f & _v3 );
    MT_FUNCTION_INLINE quatf operator*( const mt::quatf & _q, float _v );
    MT_FUNCTION_INLINE quatf operator/( const mt::quatf & _q, float _v );

    MT_FUNCTION_INLINE bool cmp_q_q( const mt::quatf & _a, const mt::quatf & _b );

    MT_FUNCTION_INLINE void add_q_q( mt::quatf * const _out, const mt::quatf & _a, const mt::quatf & _b );
    MT_FUNCTION_INLINE void sub_q_q( mt::quatf * const _out, const mt::quatf & _a, const mt::quatf & _b );
    MT_FUNCTION_INLINE void mul_q_q( mt::quatf * const _out, const mt::quatf & _q1, const mt::quatf & _q2 );
    MT_FUNCTION_INLINE void mul_q_v3( mt::vec3f * const _out, const mt::quatf & _q, const mt::vec3f & _v3 );
    MT_FUNCTION_INLINE void scale_q_s( mt::quatf * const _out, const mt::quatf & _q, float _v );

    MT_FUNCTION_INLINE float dot_q_q( const mt::quatf & _a, const mt::quatf & _b );

    MT_FUNCTION_INLINE void norm_q_q( mt::quatf * const _out, const mt::quatf & _rhs );
    MT_FUNCTION_INLINE quatf norm_q( const mt::quatf & _rhs );
    MT_FUNCTION_INLINE void norm_safe_q( mt::quatf * const out, const mt::quatf & _rhs );
    MT_FUNCTION_INLINE quatf norm_safe_q( const mt::quatf & _rhs );

    MT_FUNCTION_INLINE void lerp_q_q( mt::quatf * const _q, const mt::quatf & _q1, const mt::quatf & _q2, float _t );

    MT_FUNCTION_INLINE void q_from_angle_axis( mt::quatf * const out, const mt::vec3f & _rhs, float _val );
    MT_FUNCTION_INLINE quatf q_from_angle_axis( const mt::vec3f & _rhs, float _val );

    MT_FUNCTION_INLINE void inverse_q( mt::quatf * const _out, const mt::quatf & _rhs );
    MT_FUNCTION_INLINE quatf inverse_q( const mt::quatf & _rhs );

    MT_FUNCTION_INLINE void exp_q( mt::quatf * const _out, const mt::quatf & _rhs );
    MT_FUNCTION_INLINE quatf exp_q( const mt::quatf & _rhs );

    MT_FUNCTION_INLINE void log_q( mt::quatf * const _out, const mt::quatf & _rhs );
    MT_FUNCTION_INLINE quatf log_q( const mt::quatf & _rhs );

    MT_FUNCTION_INLINE void q_from_rot_m3( mt::quatf * const out, const mt::mat3f & _rhs );
    MT_FUNCTION_INLINE quatf q_from_rot_m3( const mt::mat3f & _rhs );

    MT_FUNCTION_INLINE void q_to_rot_m3( mt::mat3f * const out, const mt::quatf & _rhs );
    MT_FUNCTION_INLINE mat3f q_to_rot_m3( const mt::quatf & _rhs );

    MT_FUNCTION_INLINE void q_from_rot_m4( mt::quatf * const _out, const mt::mat4f & _rhs );
    MT_FUNCTION_INLINE quatf q_from_rot_m4( const mt::mat4f & _rhs );

    MT_FUNCTION_INLINE void q_from_axes( mt::quatf * const out, const mt::vec3f & _x, const mt::vec3f & _y, const mt::vec3f & _z );
    MT_FUNCTION_INLINE quatf q_from_axes( const mt::vec3f & _x, const mt::vec3f & _y, const mt::vec3f & _z );

    MT_FUNCTION_INLINE void q_to_angle_axis( mt::vec3f * const _out, float * const _out1, const mt::quatf & _rhs );
    MT_FUNCTION_INLINE vec3f q_to_angle_axis( float * const _out, const mt::quatf & _rhs );

    MT_FUNCTION_INLINE void rotate_q( mt::quatf * const _out, const mt::vec3f & axis, float angle );

    MT_FUNCTION_INLINE void qpos_to_rot_m4( mt::mat4f * const out, const mt::quatf & _rhs, const mt::vec3f & _pos );
    MT_FUNCTION_INLINE mt::mat4f qpos_to_rot_m4( const mt::quatf & _rhs, const mt::vec3f & _pos );

    MT_FUNCTION_INLINE void make_quat_from_euler( mt::quatf * const _out, const mt::vec3f & _euler );
    MT_FUNCTION_INLINE void quat_to_euler( const mt::quatf & _q, mt::vec3f * const _euler );

    MT_FUNCTION_INLINE void make_quat_from_angle( mt::quatf * const _out, float _angle );

    MT_FUNCTION_INLINE float quatzw_to_angle( const mt::quatf & _q );
};

#if MT_FORCE_INLINE == 1
#include "math/quat.cpp"
#endif
