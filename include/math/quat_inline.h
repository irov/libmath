#include "math/mat4.h"
#include "math/angle.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    //cppcheck-suppress uninitMemberVar
    MT_METHOD_INLINE quatf::quatf()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE quatf::quatf( float _x, float _y, float _z, float _w )
        : x( _x )
        , y( _y )
        , z( _z )
        , w( _w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE quatf::quatf( float _angle, const mt::vec3f & _v )
    {
        *this = q_from_angle_axis( _v, _angle );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE quatf::quatf( const quatf& _q )
        : x( _q.x )
        , y( _q.y )
        , z( _q.z )
        , w( _q.w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float& quatf::operator[]( size_t i )
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE const float quatf::operator[]( size_t i )const
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE quatf& quatf::operator=( const quatf& q )
    {
        x = q.x;
        y = q.y;
        z = q.z;
        w = q.w;
        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float quatf::length() const
    {
        return MT_sqrtf( x*x + y * y + z * z + w * w );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void quatf::normalize()
    {
        float inv_length = 1.f / this->length();

        x *= inv_length;
        y *= inv_length;
        z *= inv_length;
        w *= inv_length;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void quatf::multiply( const quatf& left, const vec3f& right )
    {
        float a, b, c, d;

        a = -left.x*right.x - left.y*right.y - left.z *right.z;
        b = left.w*right.x + left.y*right.z - right.y*left.z;
        c = left.w*right.y + left.z*right.x - right.z*left.x;
        d = left.w*right.z + left.x*right.y - right.x*left.y;

        w = a;
        x = b;
        y = c;
        z = d;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void quatf::rotate( vec3f & v ) const
    {
        quatf myInverse;
        myInverse.x = -x;//*msq;
        myInverse.y = -y;//*msq;
        myInverse.z = -z;//*msq;
        myInverse.w = w;//*msq;

        quatf left;

        left.multiply( *this, v );

        v.x = left.w*myInverse.x + myInverse.w*left.x + left.y*myInverse.z - myInverse.y*left.z;
        v.y = left.w*myInverse.y + myInverse.w*left.y + left.z*myInverse.x - myInverse.z*left.x;
        v.z = left.w*myInverse.z + myInverse.w*left.z + left.x*myInverse.y - myInverse.x*left.y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float quatf::getPitch( bool _reprojectAxis ) const
    {
        if( _reprojectAxis == true )
        {
            // pitch = atan2(localy.z, localy.y)
            // pick parts of yAxis() implementation that we need
            float fTx = 2.f*x;
            //float fTy  = 2.f*y;
            float fTz = 2.f*z;
            float fTwx = fTx * w;
            float fTxx = fTx * x;
            float fTyz = fTz * y;
            float fTzz = fTz * z;

            // Vector3(fTxy-fTwz, 1.0-(fTxx+fTzz), fTyz+fTwx);
            return MT_atan2f( fTyz + fTwx, 1.0f - (fTxx + fTzz) ) * 180.f / 3.14f;
        }
        else
        {
            // internal version
            return MT_atan2f( 2 * (y*z + w * x), w*w - x * x - y * y + z * z );
        }
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float quatf::getYaw( bool _reprojectAxis ) const
    {
        if( _reprojectAxis == true )
        {
            float fTx = 2.f*x;
            float fTy = 2.f*y;
            float fTz = 2.f*z;
            float fTwy = fTy * w;
            float fTxx = fTx * x;
            float fTxz = fTz * x;
            float fTyy = fTy * y;

            return MT_atan2f( fTxz + fTwy, 1.0f - (fTxx + fTyy) );

        }
        else
        {
            return MT_asinf( -2 * (x*z - w * y) );
        }
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool cmp_q_q( const quatf& _a, const quatf& _b )
    {
        return	mt::equal_f_f( _a.w, _b.w ) == true &&
            mt::equal_f_f( _a.x, _b.x ) == true &&
            mt::equal_f_f( _a.y, _b.y ) == true &&
            mt::equal_f_f( _a.z, _b.z ) == true;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool operator==( const quatf& _a, const quatf& _b )
    {
        return cmp_q_q( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool operator!=( const quatf& _a, const quatf& _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void add_q_q( quatf&	_out, const quatf& _a, const quatf& _b )
    {
        _out[0] = _a[0] + _b[0];
        _out[1] = _a[1] + _b[1];
        _out[2] = _a[2] + _b[2];
        _out[3] = _a[3] + _b[3];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf operator+( const quatf& _a, const quatf& _b )
    {
        quatf out;
        add_q_q( out, _a, _b );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void sub_q_q( quatf&	_out, const quatf& _a, const quatf& _b )
    {
        _out[0] = _a[0] - _b[0];
        _out[1] = _a[1] - _b[1];
        _out[2] = _a[2] - _b[2];
        _out[3] = _a[3] - _b[3];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf operator-( const quatf& _a, const quatf& _b )
    {
        quatf out;
        sub_q_q( out, _a, _b );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_q_q( quatf& _out, const quatf& _q1, const quatf& _q2 )
    {
        _out.x = _q1.y * _q2.z - _q1.z * _q2.y + _q1.x *_q2.w + _q1.w * _q2.x;
        _out.y = _q1.z * _q2.x - _q1.x * _q2.z + _q1.y *_q2.w + _q1.w * _q2.y;
        _out.z = _q1.x * _q2.y - _q1.y * _q2.x + _q1.z *_q2.w + _q1.w * _q2.z;
        _out.w = _q1.w * _q2.w - _q1.x * _q2.x - _q1.y *_q2.y - _q1.z * _q2.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf operator*( const quatf& _a, const quatf& _b )
    {
        quatf out;
        mul_q_q( out, _a, _b );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_q_v3( vec3f &_out, const quatf& _q, const vec3f& _v3 )
    {
        vec3f uv;
        vec3f uuv;
        cross_v3_v3( uv, mt::vec3f( _q.x, _q.y, _q.z ), _v3 );
        cross_v3_v3( uuv, mt::vec3f( _q.x, _q.y, _q.z ), uv );
        uv *= 2.0f*_q.w;
        uuv *= 2.0f;
        add_v3_v3( uv, uv, uuv );
        add_v3_v3( _out, _v3, uv );
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec3f operator*( const quatf& _q, const vec3f& _v3 )
    {
        vec3f out;
        mul_q_v3( out, _q, _v3 );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void scale_q_s( quatf &_out, const quatf& _q, float _v )
    {
        _out.w = _q.w * _v;
        _out.x = _q.x * _v;
        _out.y = _q.y * _v;
        _out.z = _q.z * _v;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf operator*( const quatf& _q, float _v )
    {
        quatf out;
        scale_q_s( out, _q, _v );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf operator/( const quatf& _q, float _v )
    {
        return operator*( _q, 1 / _v );;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float dot_q_q( const quatf& _a, const quatf& _b )
    {
        return  _a.w * _b.w + _a.x * _b.x + _a.y * _b.y + _a.z * _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void norm_q_q( quatf& _out, const quatf& _rhs )
    {
        float length = _rhs.length();
        float inv_length = 1.f / length;

        _out = _rhs * inv_length;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf norm_q( const quatf& _rhs )
    {
        quatf	out;
        norm_q_q( out, _rhs );
        return	out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void norm_safe_q( quatf& out, const quatf& _rhs )
    {
        float len = _rhs.length();

        if( mt::equal_f_z( len ) == false )
        {
            out = _rhs / len;
        }
        else
        {
            out = _rhs;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf norm_safe_q( const quatf & _rhs )
    {
        quatf out;
        norm_safe_q( out, _rhs );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void lerp_q_q( quatf & _q, const quatf & _q1, const quatf & _q2, float _t )
    {
        _q = _q1 * (1.f - _t) + _q2 * _t;
        _q.normalize();
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void q_from_angle_axis( quatf& out, const vec3f & _rhs, float _val )
    {
        float hangle = 0.01745329251994329547f * _val * 0.5f;
        float fsin = MT_sinf( hangle );

        float i_length = 1.0f / MT_sqrtf( _rhs.x*_rhs.x + _rhs.y*_rhs.y + _rhs.z*_rhs.z );

        out.w = MT_cosf( hangle );
        out.x = fsin * _rhs[0] * i_length;
        out.y = fsin * _rhs[1] * i_length;
        out.z = fsin * _rhs[2] * i_length;
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf q_from_angle_axis( const vec3f& _rhs, float _val )
    {
        quatf out;
        q_from_angle_axis( out, _rhs, _val );
        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void inverse_q( quatf& _out, const quatf& _rhs )
    {
        float norm = _rhs.length();

        if( norm > 0.0f )
        {
            float invnorm = 1.0f / norm;
            _out.w = _rhs.w*invnorm;
            _out.x = -_rhs.x*invnorm;
            _out.y = -_rhs.y*invnorm;
            _out.z = -_rhs.z*invnorm;
        }
        else
        {
            _out.w = _out.x = _out.y = _out.z = 0.0f;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf inverse_q( const quatf& _rhs )
    {
        quatf out;
        inverse_q( out, _rhs );
        return	out;
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void exp_q( quatf& _out, const quatf& _rhs )
    {
        /*
            If q = A*(x*i+y*j+z*k) where (x,y,z) is unit length, then
            exp(q) = cos(A)+sin(A)*(x*i+y*j+z*k).  If sin(A) is near zero,
            use exp(q) = cos(A)+A*(x*i+y*j+z*k) since A/sin(A) has limit 1.
            */

        float angle = MT_sqrtf( _rhs.x*_rhs.x + _rhs.y*_rhs.y + _rhs.z*_rhs.z );
        float fsin = MT_sinf( angle );

        _out.w = MT_cosf( angle );

        if( mt::equal_f_z( fsin ) == false )
        {
            float coef = fsin / angle;
            _out.x = coef * _rhs.x;
            _out.y = coef * _rhs.y;
            _out.z = coef * _rhs.z;
        }
        else
        {
            _out.x = _rhs.x;
            _out.y = _rhs.y;
            _out.z = _rhs.z;
        }
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf exp_q( const quatf& _rhs )
    {
        quatf out;
        exp_q( out, _rhs );
        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void log_q( quatf& _out, const quatf& _rhs )
    {
        _out.w = 0.0f;

        if( MT_fabsf( _rhs[0] ) < 1.f )
        {
            float angle = MT_cosf( _rhs.w );
            float fsin = MT_sinf( angle );

            if( mt::equal_f_z( fsin ) == false )
            {
                float coef = angle / fsin;
                _out.x = coef * _rhs.x;
                _out.y = coef * _rhs.y;
                _out.z = coef * _rhs.z;

                return;
            }
        }

        _out.x = _rhs.x;
        _out.y = _rhs.y;
        _out.z = _rhs.z;
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf log_q( const quatf& _rhs )
    {
        quatf	out;
        log_q( out, _rhs );
        return	out;
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void q_from_rot_m3( quatf& out, const mat3f& _rhs )
    {
        float ftrace = _rhs.v0.x + _rhs.v1.y + _rhs.v2.z;
        float froot;

        if( ftrace > 0.0f )
        {
            froot = MT_sqrtf( ftrace + 1.0f );
            out.w = 0.5f*froot;
            froot = 0.5f / froot;
            out.x = (_rhs.v2.y - _rhs.v1.z)*froot;
            out.y = (_rhs.v0.z - _rhs.v2.x)*froot;
            out.z = (_rhs.v1.x - _rhs.v0.y)*froot;
        }
        else
        {
            int s_iNext[3] = { 1, 2, 0 };
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
            out[i] = 0.5f*froot;
            froot = 0.5f / froot;
            out.w = (_rhs[k][j] - _rhs[j][k])*froot;
            out[j] = (_rhs[j][i] + _rhs[i][j])*froot;
            out[k] = (_rhs[k][i] + _rhs[i][k])*froot;
        }
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf q_from_rot_m3( const mat3f& _rhs )
    {
        quatf out;
        q_from_rot_m3( out, _rhs );
        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void q_from_rot_m4( quatf& out, const mat4f& _rhs )
    {
        float ftrace = _rhs.v0.x + _rhs.v1.y + _rhs.v2.z;
        float froot;

        if( ftrace > 0.0f )
        {
            froot = MT_sqrtf( ftrace + 1.0f );
            out.w = 0.5f*froot;
            froot = 0.5f / froot;
            out.x = (_rhs[2][1] - _rhs[1][2])*froot;
            out.y = (_rhs[0][2] - _rhs[2][0])*froot;
            out.z = (_rhs[1][0] - _rhs[0][1])*froot;
        }
        else
        {
            int s_iNext[3] = { 1, 2, 0 };
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
            out[i] = 0.5f*froot;
            froot = 0.5f / froot;
            out.w = (_rhs[k][j] - _rhs[j][k])*froot;
            out[j] = (_rhs[j][i] + _rhs[i][j])*froot;
            out[k] = (_rhs[k][i] + _rhs[i][k])*froot;
        }
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf q_from_rot_m4( const mat4f& _rhs )
    {
        quatf out;
        q_from_rot_m4( out, _rhs );
        return out;
    };
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void q_to_rot_m3( mat3f& out, const quatf& _rhs )
    {
        float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
        x2 = _rhs.x + _rhs.x;
        y2 = _rhs.y + _rhs.y;
        z2 = _rhs.z + _rhs.z;
        xx = _rhs.x * x2;   xy = _rhs.x * y2;   xz = _rhs.x * z2;
        yy = _rhs.y * y2;   yz = _rhs.y * z2;   zz = _rhs.z * z2;
        wx = _rhs.w * x2;   wy = _rhs.w * y2;   wz = _rhs.w * z2;

        out[0][0] = 1.0f - (yy + zz);		out[0][1] = xy - wz;			out[0][2] = xz + wy;
        out[1][0] = xy + wz;			out[1][1] = 1.0f - (xx + zz);		out[1][2] = yz - wx;
        out[2][0] = xz - wy;			out[2][1] = yz + wx;			out[2][2] = 1.0f - (xx + yy);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE mat3f q_to_rot_m3( const quatf& _rhs )
    {
        mat3f out;
        q_to_rot_m3( out, _rhs );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void q_from_axes( quatf& out, const vec3f& _x, const vec3f& _y, const vec3f& _z )
    {
        mat3f rot;
        set_m3_from_axes( rot,
            vec3f( _x.x, _y.x, _z.x ),
            vec3f( _x.y, _y.y, _z.y ),
            vec3f( _x.z, _y.z, _z.z )
        );
        q_from_rot_m3( out, rot );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE quatf q_from_axes( const vec3f& _x, const vec3f& _y, const vec3f& _z )
    {
        quatf out;
        q_from_axes( out, _x, _y, _z );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void q_to_angle_axis( vec3f& _out, float& _out1, const quatf& _rhs )
    {
        float fsqrlen = _rhs[1] * _rhs[1] + _rhs[2] * _rhs[2] + _rhs[3] * _rhs[3];
        if( fsqrlen > 0.0f )
        {
            _out1 = 2.0f * MT_acosf( _rhs[0] );
            float invl = 1.0f / MT_sqrtf( fsqrlen );
            _out[0] = _rhs[0] * invl;
            _out[1] = _rhs[1] * invl;
            _out[2] = _rhs[2] * invl;
        }
        else
        {
            _out1 = 0.0f;
            _out[0] = 1.0f;
            _out[1] = 0.0f;
            _out[2] = 0.0f;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec3f q_to_angle_axis( float& _out, const quatf& _rhs )
    {
        vec3f out;
        q_to_angle_axis( out, _out, _rhs );
        return	out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void rotate_q( quatf& _out, const vec3f& axis, float angle )
    {
        quatf q = q_from_angle_axis( axis, angle );
        _out = _out * q;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void qpos_to_rot_m4( mat4f& out, const quatf& _rhs, const vec3f& _pos )
    {
        float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
        x2 = _rhs.x + _rhs.x;
        y2 = _rhs.y + _rhs.y;
        z2 = _rhs.z + _rhs.z;
        xx = _rhs.x * x2;   xy = _rhs.x * y2;   xz = _rhs.x * z2;
        yy = _rhs.y * y2;   yz = _rhs.y * z2;   zz = _rhs.z * z2;
        wx = _rhs.w * x2;   wy = _rhs.w * y2;   wz = _rhs.w * z2;

        out[0][0] = 1.f - (yy + zz);		out[0][1] = xy - wz;			out[0][2] = xz + wy;			out[0][3] = 0.f;
        out[1][0] = xy + wz;				out[1][1] = 1.f - (xx + zz);	out[1][2] = yz - wx;			out[1][3] = 0.f;
        out[2][0] = xz - wy;				out[2][1] = yz + wx;			out[2][2] = 1.f - (xx + yy);	out[2][3] = 0.f;
        out[3][0] = _pos.x;				out[3][1] = _pos.y;			out[3][2] = _pos.z;			out[3][3] = 1.0f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE mat4f qpos_to_rot_m4( const quatf& _rhs, const vec3f& _pos )
    {
        mat4f	out;
        qpos_to_rot_m4( out, _rhs, _pos );
        return	out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_quat_from_euler( quatf & _out, const mt::vec3f & _euler )
    {
        float c1 = MT_cosf( _euler.z * 0.5f );
        float c2 = MT_cosf( _euler.y * 0.5f );
        float c3 = MT_cosf( _euler.x * 0.5f );
        float s1 = MT_sinf( _euler.z * 0.5f );
        float s2 = MT_sinf( _euler.y * 0.5f );
        float s3 = MT_sinf( _euler.x * 0.5f );

        quatf q;
        q.x = c1 * c2 * s3 - s1 * s2 * c3;
        q.y = c1 * s2 * c3 + s1 * c2 * s3;
        q.z = s1 * c2 * c3 - c1 * s2 * s3;
        q.w = c1 * c2 * c3 + s1 * s2 * s3;

        norm_q_q( _out, q );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_quat_from_angle( quatf & _out, float _angle )
    {
        float c = MT_cosf( _angle * 0.5f );
        float s = MT_sinf( _angle * 0.5f );

        _out.x = 0.f;
        _out.y = 0.f;
        _out.z = s;
        _out.w = c;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void quat_to_euler( const quatf & _q, mt::vec3f & _euler )
    {
        float sqw = _q.w * _q.w;
        float sqx = _q.x * _q.x;
        float sqy = _q.y * _q.y;
        float sqz = _q.z * _q.z;

        _euler.y = MT_asinf( 2.f * (_q.w * _q.y - _q.x * _q.z) );

        if( mt::constant::half_pi - MT_fabsf( _euler.y ) > mt::constant::eps )
        {
            _euler.z = MT_atan2f( 2.f * (_q.x * _q.y + _q.w * _q.z), sqx - sqy - sqz + sqw );
            _euler.x = MT_atan2f( 2.f * (_q.w * _q.x + _q.y * _q.z), sqw - sqx - sqy + sqz );
        }
        else
        {
            _euler.z = MT_atan2f( 2.f * (_q.y * _q.z - _q.x * _q.z), 2.f * (_q.x * _q.z + _q.y * _q.w) );
            _euler.x = 0.f;

            if( _euler.y < 0.f )
            {
                _euler.z = mt::constant::pi - _euler.z;
            }
        }
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float quatzw_to_angle( const quatf & _q )
    {
        float sqw = _q.w * _q.w;
        float sqz = _q.z * _q.z;

        float angle = MT_atan2f( 2.f * (_q.w * _q.z), -sqz + sqw );

        return angle;
    }
}
