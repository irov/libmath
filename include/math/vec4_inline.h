#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    //cppcheck-suppress uninitMemberVar
    MT_METHOD_INLINE vec4f::vec4f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f::vec4f( float _x, float _y, float _z, float _w )
        :x( _x )
        , y( _y )
        , z( _z )
        , w( _w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f::vec4f( const vec2f & _v0, const vec2f & _v1 )
        :x( _v0.x )
        , y( _v0.y )
        , z( _v1.x )
        , w( _v1.y )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f::vec4f( const vec4f & _v )
        :x( _v.x )
        , y( _v.y )
        , z( _v.z )
        , w( _v.w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f::vec4f( const vec3f & _v )
        :x( _v.x )
        , y( _v.y )
        , z( _v.z )
        , w( 0.f )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f::vec4f( const vec3f & _v, float _w )
        :x( _v.x )
        , y( _v.y )
        , z( _v.z )
        , w( _w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f & vec4f::operator=( const vec4f & _rhs )
    {
        x = _rhs.x;
        y = _rhs.y;
        z = _rhs.z;
        w = _rhs.w;
        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float & vec4f::operator[]( size_t i )
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE const float vec4f::operator[]( size_t i )const
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f & vec4f::operator+=( const vec4f & _rhs )
    {
        x += _rhs.x;
        y += _rhs.y;
        z += _rhs.z;
        w += _rhs.w;
        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f & vec4f::operator -= ( const vec4f & _rhs )
    {
        x -= _rhs.x;
        y -= _rhs.y;
        z -= _rhs.z;
        w -= _rhs.w;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f & vec4f::operator *= ( const vec2f & _rhs )
    {
        x *= _rhs.x;
        y *= _rhs.y;
        z *= _rhs.x;
        w *= _rhs.y;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f & vec4f::operator /= ( const vec2f & _rhs )
    {
        return operator *= ( 1.f / _rhs );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f & vec4f::operator *= ( const float _rhs )
    {
        x *= _rhs;
        y *= _rhs;
        z *= _rhs;
        w *= _rhs;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f & vec4f::operator /= ( const float _rhs )
    {
        return operator *= ( 1.f / _rhs );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float vec4f::sqrlength() const
    {
        return	x * x + y * y + z * z + w * w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float vec4f::length() const
    {
        float sqlen = this->sqrlength();

        float len = MT_sqrtf( sqlen );

        return len;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE const vec3f & vec4f::to_vec3f() const
    {
        return *(vec3f *)(&x);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float * vec4f::buff()
    {
        return &x;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE const float * vec4f::buff() const
    {
        return &x;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void ident_v4( vec4f & _rhs )
    {
        _rhs.x = 0.f;
        _rhs.y = 0.f;
        _rhs.z = 0.f;
        _rhs.w = 0.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void extract_v4_v3( vec3f & _out, const vec4f & _rhs )
    {
        _out.x = _rhs.x;
        _out.y = _rhs.y;
        _out.z = _rhs.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_v4_v3( vec4f & _out, const vec3f & _rhs )
    {
        _out.x = _rhs.x;
        _out.y = _rhs.y;
        _out.z = _rhs.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool cmp_v4_v4( const vec4f & _a, const vec4f & _b )
    {
        return	mt::equal_f_f( _a.x, _b.x ) == true &&
            mt::equal_f_f( _a.y, _b.y ) == true &&
            mt::equal_f_f( _a.z, _b.z ) == true &&
            mt::equal_f_f( _a.w, _b.w ) == true;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool operator==( const vec4f & _a, const vec4f & _b )
    {
        return cmp_v4_v4( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool operator!=( const vec4f & _a, const vec4f & _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void add_v4_v3( vec4f & _out, const vec4f & _a, const vec3f & _b )
    {
        _out.x = _a.x + _b.x;
        _out.y = _a.y + _b.y;
        _out.z = _a.z + _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void add_v4_v4( vec4f & _out, const vec4f & _a, const vec4f & _b )
    {
        _out.x = _a.x + _b.x;
        _out.y = _a.y + _b.y;
        _out.z = _a.z + _b.z;
        _out.w = _a.w + _b.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator+( const vec4f & _a, const vec4f & _b )
    {
        vec4f	out;
        add_v4_v4( out, _a, _b );
        return	out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void sub_v4_v4( vec4f & _out, const vec4f & _a, const vec4f & _b )
    {
        _out.x = _a.x - _b.x;
        _out.y = _a.y - _b.y;
        _out.z = _a.z - _b.z;
        _out.w = _a.w - _b.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator-( const vec4f & _a, const vec4f & _b )
    {
        vec4f	out;
        sub_v4_v4( out, _a, _b );
        return	out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void scale_v4_v4( vec4f & _out, const vec4f & _a, float _val )
    {
        _out.x = _a.x * _val;
        _out.y = _a.y * _val;
        _out.z = _a.z * _val;
        _out.w = _a.w * _val;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator*( const vec4f & _rhs, const vec4f & _val )
    {
        return vec4f( _rhs.x * _val.x, _rhs.y * _val.y, _rhs.z * _val.z, _rhs.w * _val.w );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator/( const vec4f & _rhs, const vec4f & _val )
    {
        return vec4f( _rhs.x / _val.x, _rhs.y / _val.y, _rhs.z / _val.z, _rhs.w / _val.w );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator*( const vec4f & _rhs, const vec2f & _val )
    {
        return vec4f( _rhs.x * _val.x, _rhs.y * _val.y, _rhs.z * _val.x, _rhs.w * _val.y );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator/( const vec4f & _rhs, const vec2f & _val )
    {
        return operator*( _rhs, 1.f / _val );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator*( const vec4f & _rhs, const float _val )
    {
        vec4f out;
        scale_v4_v4( out, _rhs, _val );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator/( const vec4f & _rhs, const float _val )
    {
        return operator*( _rhs, 1.f / _val );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void neg_v4( vec4f & _out )
    {
        _out.x = -_out.x;
        _out.y = -_out.y;
        _out.z = -_out.z;
        _out.w = -_out.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator-( vec4f _rhs )
    {
        neg_v4( _rhs );
        return	_rhs;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float dot_v4_z( const vec4f & a )
    {
        return a.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float dot_v4_v2( const vec4f & a, const vec2f & b )
    {
        return a.x * b.x + a.y * b.y + a.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float dot_v4_v3( const vec4f & a, const vec3f & b )
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float dot_v4_v4( const vec4f & a, const vec4f & b )
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void norm_v4( vec4f & _out, const vec4f & _rhs )
    {
        _out = _rhs / _rhs.length();
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f norm_v4( const vec4f & _rhs )
    {
        vec4f	out;
        norm_v4( out, _rhs );
        return	out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void norm_safe_v4( vec4f & out, const vec4f & _rhs, float err )
    {
        float	len = _rhs.length();
        if( len > err )
        {
            out = _rhs / len;
            return;
        }
        out = _rhs;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f norm_safe_v4( const vec4f & _rhs )
    {
        vec4f	out;
        norm_safe_v4( out, _rhs );
        return	out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void homogenize_v4( vec4f & _out, const vec4f & _rhs )
    {
        float w_inv = 1.f / _rhs.w;

        _out.x = _rhs.x * w_inv;
        _out.y = _rhs.y * w_inv;
        _out.z = _rhs.z * w_inv;
        _out.w = 1.0f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void homogenize_v3_v4( vec3f & _out, const vec4f & _rhs )
    {
        float w_inv = 1.f / _rhs.w;

        _out.x = _rhs.x * w_inv;
        _out.y = _rhs.y * w_inv;
        _out.z = _rhs.z * w_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f homogenize_v4( const vec4f & _rhs )
    {
        vec4f	out;
        homogenize_v4( out, _rhs );
        return	out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float length_v4( const vec4f & _rhs )
    {
        return _rhs.length();
    }

}
