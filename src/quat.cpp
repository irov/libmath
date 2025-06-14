#include "math/quat.h"

#include "math/mat4.h"
#include "math/angle.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    //cppcheck-suppress uninitMemberVar
    quatf::quatf()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    quatf::quatf( float _x, float _y, float _z, float _w )
        : x( _x )
        , y( _y )
        , z( _z )
        , w( _w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    quatf::quatf( const mt::quatf & _q )
        : x( _q.x )
        , y( _q.y )
        , z( _q.z )
        , w( _q.w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    quatf::quatf( const mt::vec3f & _v, float _angle )
    {
        mt::q_from_angle_axis( this, _v, _angle );
    }
    //////////////////////////////////////////////////////////////////////////
    float & quatf::operator [] ( size_t i )
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    const float quatf::operator [] ( size_t i )const
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    quatf & quatf::operator = ( const mt::quatf & q )
    {
        x = q.x;
        y = q.y;
        z = q.z;
        w = q.w;
        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    float quatf::length() const
    {
        return MT_sqrtf( x * x + y * y + z * z + w * w );
    }
    //////////////////////////////////////////////////////////////////////////
    void quatf::normalize()
    {
        float inv_length = 1.f / this->length();

        x *= inv_length;
        y *= inv_length;
        z *= inv_length;
        w *= inv_length;
    }
    //////////////////////////////////////////////////////////////////////////
    void quatf::multiply( const mt::quatf & left, const mt::vec3f & right )
    {
        float a = -left.x * right.x - left.y * right.y - left.z * right.z;
        float b = left.w * right.x + left.y * right.z - right.y * left.z;
        float c = left.w * right.y + left.z * right.x - right.z * left.x;
        float d = left.w * right.z + left.x * right.y - right.x * left.y;

        w = a;
        x = b;
        y = c;
        z = d;
    }
    //////////////////////////////////////////////////////////////////////////
    void quatf::rotate( mt::vec3f * const _v ) const
    {
        quatf myInverse;
        myInverse.x = -x;
        myInverse.y = -y;
        myInverse.z = -z;
        myInverse.w = w;

        quatf left;
        left.multiply( *this, *_v );

        _v->x = left.w * myInverse.x + myInverse.w * left.x + left.y * myInverse.z - myInverse.y * left.z;
        _v->y = left.w * myInverse.y + myInverse.w * left.y + left.z * myInverse.x - myInverse.z * left.x;
        _v->z = left.w * myInverse.z + myInverse.w * left.z + left.x * myInverse.y - myInverse.x * left.y;
    }
    //////////////////////////////////////////////////////////////////////////
    float quatf::getPitch( bool _reprojectAxis ) const
    {
        if( _reprojectAxis == true )
        {
            float fTx = 2.f * x;
            float fTz = 2.f * z;
            float fTwx = fTx * w;
            float fTxx = fTx * x;
            float fTyz = fTz * y;
            float fTzz = fTz * z;

            return MT_atan2f( fTyz + fTwx, 1.0f - (fTxx + fTzz) ) * 180.f / 3.14f;
        }
        else
        {
            return MT_atan2f( 2 * (y * z + w * x), w * w - x * x - y * y + z * z );
        }
    }
    //////////////////////////////////////////////////////////////////////////
    float quatf::getYaw( bool _reprojectAxis ) const
    {
        if( _reprojectAxis == true )
        {
            float fTx = 2.f * x;
            float fTy = 2.f * y;
            float fTz = 2.f * z;
            float fTwy = fTy * w;
            float fTxx = fTx * x;
            float fTxz = fTz * x;
            float fTyy = fTy * y;

            return MT_atan2f( fTxz + fTwy, 1.0f - (fTxx + fTyy) );

        }
        else
        {
            return MT_asinf( -2 * (x * z - w * y) );
        }
    }
    //////////////////////////////////////////////////////////////////////////
    bool cmp_q_q( const mt::quatf & _a, const mt::quatf & _b )
    {
        return _a.w == _b.w && _a.x == _b.x && _a.y == _b.y && _a.z == _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator == ( const mt::quatf & _a, const mt::quatf & _b )
    {
        return mt::cmp_q_q( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator != ( const mt::quatf & _a, const mt::quatf & _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    void add_q_q( mt::quatf * const _out, const mt::quatf & _a, const mt::quatf & _b )
    {
        _out->x = _a.x + _b.x;
        _out->y = _a.y + _b.y;
        _out->z = _a.z + _b.z;
        _out->w = _a.w + _b.w;
    }
    //////////////////////////////////////////////////////////////////////////
    quatf operator + ( const mt::quatf & _a, const mt::quatf & _b )
    {
        quatf out;
        add_q_q( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void sub_q_q( quatf * const _out, const mt::quatf & _a, const mt::quatf & _b )
    {
        _out->x = _a.x - _b.x;
        _out->y = _a.y - _b.y;
        _out->z = _a.z - _b.z;
        _out->w = _a.w - _b.w;
    }
    //////////////////////////////////////////////////////////////////////////
    quatf operator - ( const mt::quatf & _a, const mt::quatf & _b )
    {
        mt::quatf out;
        mt::sub_q_q( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_q_q( quatf * const _out, const mt::quatf & _q1, const mt::quatf & _q2 )
    {
        _out->x = _q1.y * _q2.z - _q1.z * _q2.y + _q1.x * _q2.w + _q1.w * _q2.x;
        _out->y = _q1.z * _q2.x - _q1.x * _q2.z + _q1.y * _q2.w + _q1.w * _q2.y;
        _out->z = _q1.x * _q2.y - _q1.y * _q2.x + _q1.z * _q2.w + _q1.w * _q2.z;
        _out->w = _q1.w * _q2.w - _q1.x * _q2.x - _q1.y * _q2.y - _q1.z * _q2.z;
    }
    //////////////////////////////////////////////////////////////////////////
    quatf operator * ( const mt::quatf & _a, const mt::quatf & _b )
    {
        mt::quatf out;
        mt::mul_q_q( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_q_v3( mt::vec3f * const _out, const mt::quatf & _q, const mt::vec3f & _v3 )
    {
        mt::vec3f uv;
        mt::cross_v3_v3( &uv, mt::vec3f( _q.x, _q.y, _q.z ), _v3 );

        mt::vec3f uuv;
        mt::cross_v3_v3( &uuv, mt::vec3f( _q.x, _q.y, _q.z ), uv );

        uv *= 2.0f * _q.w;
        uuv *= 2.0f;

        mt::add_v3_v3( &uv, uv, uuv );
        mt::add_v3_v3( _out, _v3, uv );
    };
    //////////////////////////////////////////////////////////////////////////
    vec3f operator*( const mt::quatf & _q, const mt::vec3f & _v3 )
    {
        mt::vec3f out;
        mt::mul_q_v3( &out, _q, _v3 );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_q_s( mt::quatf * const _out, const mt::quatf & _q, float _v )
    {
        _out->w = _q.w * _v;
        _out->x = _q.x * _v;
        _out->y = _q.y * _v;
        _out->z = _q.z * _v;
    }
    //////////////////////////////////////////////////////////////////////////
    quatf operator * ( const mt::quatf & _q, float _v )
    {
        mt::quatf out;
        mt::scale_q_s( &out, _q, _v );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    quatf operator / ( const mt::quatf & _q, float _v )
    {
        return operator*( _q, 1 / _v );;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_q_q( const mt::quatf & _a, const mt::quatf & _b )
    {
        return _a.w * _b.w + _a.x * _b.x + _a.y * _b.y + _a.z * _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    void norm_q_q( mt::quatf * const _out, const mt::quatf & _rhs )
    {
        float l = _rhs.length();
        float inv_length = 1.f / l;

        *_out = _rhs * inv_length;
    }
    //////////////////////////////////////////////////////////////////////////
    quatf norm_q( const mt::quatf & _rhs )
    {
        mt::quatf out;
        mt::norm_q_q( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void norm_safe_q( mt::quatf * const _out, const mt::quatf & _rhs )
    {
        float len = _rhs.length();

        if( mt::equal_f_z( len ) == false )
        {
            *_out = _rhs / len;
        }
        else
        {
            *_out = _rhs;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    quatf norm_safe_q( const mt::quatf & _rhs )
    {
        mt::quatf out;
        mt::norm_safe_q( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void lerp_q_q( mt::quatf * const _out, const mt::quatf & _q1, const mt::quatf & _q2, float _t )
    {
        *_out = _q1 * (1.f - _t) + _q2 * _t;
        _out->normalize();
    }
    //////////////////////////////////////////////////////////////////////////
    void q_from_angle_axis( mt::quatf * const _out, const mt::vec3f & _rhs, float _val )
    {
        float hangle = mt::constant::deg2rad * _val * 0.5f;
        float fsin = MT_sinf( hangle );

        float i_length = 1.0f / MT_sqrtf( _rhs.x * _rhs.x + _rhs.y * _rhs.y + _rhs.z * _rhs.z );

        _out->w = MT_cosf( hangle );
        _out->x = fsin * _rhs[0] * i_length;
        _out->y = fsin * _rhs[1] * i_length;
        _out->z = fsin * _rhs[2] * i_length;
    };
    //////////////////////////////////////////////////////////////////////////
    quatf q_from_angle_axis( const mt::vec3f & _rhs, float _val )
    {
        mt::quatf out;
        mt::q_from_angle_axis( &out, _rhs, _val );

        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    void inverse_q( mt::quatf * const _out, const mt::quatf & _rhs )
    {
        float norm = _rhs.length();

        if( norm > 0.0f )
        {
            float invnorm = 1.f / norm;

            _out->w = _rhs.w * invnorm;
            _out->x = -_rhs.x * invnorm;
            _out->y = -_rhs.y * invnorm;
            _out->z = -_rhs.z * invnorm;
        }
        else
        {
            _out->w = _out->x = _out->y = _out->z = 0.f;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    quatf inverse_q( const mt::quatf & _rhs )
    {
        mt::quatf out;
        mt::inverse_q( &out, _rhs );

        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    void exp_q( quatf * const _out, const mt::quatf & _rhs )
    {
        float angle = MT_sqrtf( _rhs.x * _rhs.x + _rhs.y * _rhs.y + _rhs.z * _rhs.z );
        float fsin = MT_sinf( angle );

        _out->w = MT_cosf( angle );

        if( mt::equal_f_z( fsin ) == false )
        {
            float coef = fsin / angle;
            _out->x = coef * _rhs.x;
            _out->y = coef * _rhs.y;
            _out->z = coef * _rhs.z;
        }
        else
        {
            _out->x = _rhs.x;
            _out->y = _rhs.y;
            _out->z = _rhs.z;
        }
    };
    //////////////////////////////////////////////////////////////////////////
    quatf exp_q( const mt::quatf & _rhs )
    {
        mt::quatf out;
        mt::exp_q( &out, _rhs );

        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    void log_q( quatf * const _out, const mt::quatf & _rhs )
    {
        _out->w = 0.0f;

        if( MT_fabsf( _rhs[0] ) < 1.f )
        {
            float angle = MT_cosf( _rhs.w );
            float fsin = MT_sinf( angle );

            if( mt::equal_f_z( fsin ) == false )
            {
                float coef = angle / fsin;
                _out->x = coef * _rhs.x;
                _out->y = coef * _rhs.y;
                _out->z = coef * _rhs.z;

                return;
            }
        }

        _out->x = _rhs.x;
        _out->y = _rhs.y;
        _out->z = _rhs.z;
    };
    //////////////////////////////////////////////////////////////////////////
    quatf log_q( const mt::quatf & _rhs )
    {
        mt::quatf out;
        mt::log_q( &out, _rhs );

        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    void q_from_rot_m3( quatf * const _out, const mt::mat3f & _rhs )
    {
        float ftrace = _rhs.v0.x + _rhs.v1.y + _rhs.v2.z;
        float froot;

        if( ftrace > 0.0f )
        {
            froot = MT_sqrtf( ftrace + 1.0f );
            _out->w = 0.5f * froot;
            froot = 0.5f / froot;
            _out->x = (_rhs.v2.y - _rhs.v1.z) * froot;
            _out->y = (_rhs.v0.z - _rhs.v2.x) * froot;
            _out->z = (_rhs.v1.x - _rhs.v0.y) * froot;
        }
        else
        {
            int s_iNext[3] = {1, 2, 0};
            int i = 0;
            if( _rhs.v1.y > _rhs.v0.x )
            {
                i = 1;
            }

            if( _rhs.v2.z > _rhs[i][i] )
            {
                i = 2;
            }

            int j = s_iNext[i];
            int k = s_iNext[j];

            froot = MT_sqrtf( _rhs[i][i] - _rhs[j][j] - _rhs[k][k] + 1.0f );
            (*_out)[i] = 0.5f * froot;
            froot = 0.5f / froot;
            _out->w = (_rhs[k][j] - _rhs[j][k]) * froot;
            (*_out)[j] = (_rhs[j][i] + _rhs[i][j]) * froot;
            (*_out)[k] = (_rhs[k][i] + _rhs[i][k]) * froot;
        }
    };
    //////////////////////////////////////////////////////////////////////////
    quatf q_from_rot_m3( const mt::mat3f & _rhs )
    {
        mt::quatf out;
        mt::q_from_rot_m3( &out, _rhs );

        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    void q_from_rot_m4( quatf * const _out, const mt::mat4f & _rhs )
    {
        float ftrace = _rhs.v0.x + _rhs.v1.y + _rhs.v2.z;
        float froot;

        if( ftrace > 0.0f )
        {
            froot = MT_sqrtf( ftrace + 1.0f );
            _out->w = 0.5f * froot;
            froot = 0.5f / froot;
            _out->x = (_rhs[2][1] - _rhs[1][2]) * froot;
            _out->y = (_rhs[0][2] - _rhs[2][0]) * froot;
            _out->z = (_rhs[1][0] - _rhs[0][1]) * froot;
        }
        else
        {
            int s_iNext[3] = {1, 2, 0};
            int i = 0;
            if( _rhs.v1.y > _rhs.v0.x )
            {
                i = 1;
            }

            if( _rhs.v2.z > _rhs[i][i] )
            {
                i = 2;
            }

            int j = s_iNext[i];
            int k = s_iNext[j];

            froot = MT_sqrtf( _rhs[i][i] - _rhs[j][j] - _rhs[k][k] + 1.0f );
            (*_out)[i] = 0.5f * froot;
            froot = 0.5f / froot;
            _out->w = (_rhs[k][j] - _rhs[j][k]) * froot;
            (*_out)[j] = (_rhs[j][i] + _rhs[i][j]) * froot;
            (*_out)[k] = (_rhs[k][i] + _rhs[i][k]) * froot;
        }
    };
    //////////////////////////////////////////////////////////////////////////
    quatf q_from_rot_m4( const mt::mat4f & _rhs )
    {
        mt::quatf out;
        mt::q_from_rot_m4( &out, _rhs );

        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    void q_to_rot_m3( mat3f * const _out, const mt::quatf & _rhs )
    {
        float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
        x2 = _rhs.x + _rhs.x;
        y2 = _rhs.y + _rhs.y;
        z2 = _rhs.z + _rhs.z;
        xx = _rhs.x * x2;   xy = _rhs.x * y2;   xz = _rhs.x * z2;
        yy = _rhs.y * y2;   yz = _rhs.y * z2;   zz = _rhs.z * z2;
        wx = _rhs.w * x2;   wy = _rhs.w * y2;   wz = _rhs.w * z2;

        _out->v0.x = 1.0f - (yy + zz);
        _out->v0.y = xy - wz;
        _out->v0.z = xz + wy;
        _out->v1.x = xy + wz;
        _out->v1.y = 1.0f - (xx + zz);
        _out->v1.z = yz - wx;
        _out->v2.x = xz - wy;
        _out->v2.y = yz + wx;
        _out->v2.z = 1.0f - (xx + yy);
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f q_to_rot_m3( const mt::quatf & _rhs )
    {
        mt::mat3f out;
        mt::q_to_rot_m3( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void q_from_axes( quatf * const out, const mt::vec3f & _x, const mt::vec3f & _y, const mt::vec3f & _z )
    {
        mt::mat3f rot;
        mt::set_m3_from_axes( &rot, vec3f( _x.x, _y.x, _z.x ), vec3f( _x.y, _y.y, _z.y ), vec3f( _x.z, _y.z, _z.z ) );

        mt::q_from_rot_m3( out, rot );
    }
    //////////////////////////////////////////////////////////////////////////
    quatf q_from_axes( const mt::vec3f & _x, const mt::vec3f & _y, const mt::vec3f & _z )
    {
        mt::quatf out;
        mt::q_from_axes( &out, _x, _y, _z );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void q_to_angle_axis( vec3f * const _out, float * const _out1, const mt::quatf & _rhs )
    {
        float fsqrlen = _rhs[1] * _rhs[1] + _rhs[2] * _rhs[2] + _rhs[3] * _rhs[3];

        if( fsqrlen > 0.0f )
        {
            *_out1 = 2.0f * MT_acosf( _rhs[0] );
            float invl = 1.0f / MT_sqrtf( fsqrlen );

            _out->x = _rhs.x * invl;
            _out->y = _rhs.y * invl;
            _out->z = _rhs.z * invl;
        }
        else
        {
            *_out1 = 0.0f;
            _out->x = 1.0f;
            _out->y = 0.0f;
            _out->z = 0.0f;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f q_to_angle_axis( float * const _out, const mt::quatf & _rhs )
    {
        mt::vec3f out;
        mt::q_to_angle_axis( &out, _out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void rotate_q( quatf * const _out, const mt::vec3f & axis, float angle )
    {
        mt::quatf q = mt::q_from_angle_axis( axis, angle );

        *_out = *_out * q;
    }
    //////////////////////////////////////////////////////////////////////////
    void qpos_to_rot_m4( mat4f * const out, const mt::quatf & _rhs, const mt::vec3f & _pos )
    {
        float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
        x2 = _rhs.x + _rhs.x;
        y2 = _rhs.y + _rhs.y;
        z2 = _rhs.z + _rhs.z;
        xx = _rhs.x * x2;   xy = _rhs.x * y2;   xz = _rhs.x * z2;
        yy = _rhs.y * y2;   yz = _rhs.y * z2;   zz = _rhs.z * z2;
        wx = _rhs.w * x2;   wy = _rhs.w * y2;   wz = _rhs.w * z2;

        out->v0.x = 1.f - (yy + zz);
        out->v0.y = xy - wz;
        out->v0.z = xz + wy;
        out->v0.w = 0.f;
        out->v1.x = xy + wz;
        out->v1.y = 1.f - (xx + zz);
        out->v1.z = yz - wx;
        out->v1.w = 0.f;
        out->v2.x = xz - wy;
        out->v2.y = yz + wx;
        out->v2.z = 1.f - (xx + yy);
        out->v2.w = 0.f;
        out->v3.x = _pos.x;
        out->v3.y = _pos.y;
        out->v3.z = _pos.z;
        out->v3.w = 1.0f;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::mat4f qpos_to_rot_m4( const mt::quatf & _rhs, const mt::vec3f & _pos )
    {
        mt::mat4f out;
        mt::qpos_to_rot_m4( &out, _rhs, _pos );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void make_quat_from_euler( mt::quatf * const _out, const mt::vec3f & _euler )
    {
        float c1 = MT_cosf( _euler.z * 0.5f );
        float c2 = MT_cosf( _euler.y * 0.5f );
        float c3 = MT_cosf( _euler.x * 0.5f );
        float s1 = MT_sinf( _euler.z * 0.5f );
        float s2 = MT_sinf( _euler.y * 0.5f );
        float s3 = MT_sinf( _euler.x * 0.5f );

        mt::quatf q;
        q.x = c1 * c2 * s3 - s1 * s2 * c3;
        q.y = c1 * s2 * c3 + s1 * c2 * s3;
        q.z = s1 * c2 * c3 - c1 * s2 * s3;
        q.w = c1 * c2 * c3 + s1 * s2 * s3;

        mt::norm_q_q( _out, q );
    }
    //////////////////////////////////////////////////////////////////////////
    void make_quat_from_angle( quatf * const _out, float _angle )
    {
        float c = MT_cosf( _angle * 0.5f );
        float s = MT_sinf( _angle * 0.5f );

        _out->x = 0.f;
        _out->y = 0.f;
        _out->z = s;
        _out->w = c;
    }
    //////////////////////////////////////////////////////////////////////////
    void quat_to_euler( const mt::quatf & _q, mt::vec3f * const _euler )
    {
        float sqw = _q.w * _q.w;
        float sqx = _q.x * _q.x;
        float sqy = _q.y * _q.y;
        float sqz = _q.z * _q.z;

        float y = MT_asinf( 2.f * (_q.w * _q.y - _q.x * _q.z) );

        if( mt::constant::half_pi - MT_fabsf( y ) > mt::constant::eps )
        {
            _euler->z = MT_atan2f( 2.f * (_q.x * _q.y + _q.w * _q.z), sqx - sqy - sqz + sqw );
            _euler->x = MT_atan2f( 2.f * (_q.w * _q.x + _q.y * _q.z), sqw - sqx - sqy + sqz );
        }
        else
        {
            _euler->z = MT_atan2f( 2.f * (_q.y * _q.z - _q.x * _q.z), 2.f * (_q.x * _q.z + _q.y * _q.w) );
            _euler->x = 0.f;

            if( y < 0.f )
            {
                _euler->z = mt::constant::pi - _euler->z;
            }
        }

        _euler->y = y;
    }
    //////////////////////////////////////////////////////////////////////////
    float quatzw_to_angle( const mt::quatf & _q )
    {
        float sqw = _q.w * _q.w;
        float sqz = _q.z * _q.z;

        float angle = MT_atan2f( 2.f * (_q.w * _q.z), -sqz + sqw );

        return angle;
    }
    //////////////////////////////////////////////////////////////////////////
}
