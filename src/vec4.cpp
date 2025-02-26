#include "math/vec4.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    //cppcheck-suppress uninitMemberVar
    vec4f::vec4f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec4f::vec4f( float _x, float _y, float _z, float _w )
        :x( _x )
        , y( _y )
        , z( _z )
        , w( _w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec4f::vec4f( const mt::vec4f & _v )
        :x( _v.x )
        , y( _v.y )
        , z( _v.z )
        , w( _v.w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec4f::vec4f( const mt::vec3f & _v, float _w )
        :x( _v.x )
        , y( _v.y )
        , z( _v.z )
        , w( _w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec4f::vec4f( const mt::vec2f & _v0, const mt::vec2f & _v1 )
        :x( _v0.x )
        , y( _v0.y )
        , z( _v1.x )
        , w( _v1.y )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec4f::vec4f( const float * _v )
        : x( _v[0] )
        , y( _v[1] )
        , z( _v[2] )
        , w( _v[3] )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator = ( const mt::vec4f & _rhs )
    {
        x = _rhs.x;
        y = _rhs.y;
        z = _rhs.z;
        w = _rhs.w;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    float & vec4f::operator [] ( size_t i )
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    const float vec4f::operator [] ( size_t i )const
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator += ( const mt::vec4f & _rhs )
    {
        x += _rhs.x;
        y += _rhs.y;
        z += _rhs.z;
        w += _rhs.w;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator -= ( const mt::vec4f & _rhs )
    {
        x -= _rhs.x;
        y -= _rhs.y;
        z -= _rhs.z;
        w -= _rhs.w;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator *= ( const mt::vec4f & _rhs )
    {
        x *= _rhs.x;
        y *= _rhs.y;
        z *= _rhs.z;
        w *= _rhs.w;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator /= ( const mt::vec4f & _rhs )
    {
        x *= _rhs.x;
        y *= _rhs.y;
        z *= _rhs.z;
        w *= _rhs.w;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator *= ( const mt::vec2f & _rhs )
    {
        x *= _rhs.x;
        y *= _rhs.y;
        z *= _rhs.x;
        w *= _rhs.y;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator /= ( const mt::vec2f & _rhs )
    {
        return operator *= ( 1.f / _rhs );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator *= ( const float _rhs )
    {
        x *= _rhs;
        y *= _rhs;
        z *= _rhs;
        w *= _rhs;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f & vec4f::operator /= ( const float _rhs )
    {
        return operator *= ( 1.f / _rhs );
    }
    //////////////////////////////////////////////////////////////////////////
    void vec4f::set( float _x, float _y, float _z, float _w )
    {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }
    //////////////////////////////////////////////////////////////////////////
    float vec4f::sqrlength() const
    {
        return x * x + y * y + z * z + w * w;
    }
    //////////////////////////////////////////////////////////////////////////
    float vec4f::length() const
    {
        float sqlen = this->sqrlength();

        float len = MT_sqrtf( sqlen );

        return len;
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec3f & vec4f::to_vec3f() const
    {
        return *(vec3f *)(&x);
    }
    //////////////////////////////////////////////////////////////////////////
    float * vec4f::buff()
    {
        return &x;
    }
    //////////////////////////////////////////////////////////////////////////
    const float * vec4f::buff() const
    {
        return &x;
    }
    //////////////////////////////////////////////////////////////////////////
    void ident_v4( mt::vec4f * const _out )
    {
        _out->x = 0.f;
        _out->y = 0.f;
        _out->z = 0.f;
        _out->w = 0.f;
    }
    //////////////////////////////////////////////////////////////////////////
    void extract_v4_v3( mt::vec3f * const _out, const mt::vec4f & _rhs )
    {
        _out->x = _rhs.x;
        _out->y = _rhs.y;
        _out->z = _rhs.z;
    }
    //////////////////////////////////////////////////////////////////////////
    void set_v4_v3( mt::vec4f * const _out, const mt::vec3f & _rhs )
    {
        _out->x = _rhs.x;
        _out->y = _rhs.y;
        _out->z = _rhs.z;
    }
    //////////////////////////////////////////////////////////////////////////
    bool cmp_v4_v4( const mt::vec4f & _a, const mt::vec4f & _b )
    {
        return
            mt::equal_f_f( _a.x, _b.x ) == true &&
            mt::equal_f_f( _a.y, _b.y ) == true &&
            mt::equal_f_f( _a.z, _b.z ) == true &&
            mt::equal_f_f( _a.w, _b.w ) == true;
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator == ( const mt::vec4f & _a, const mt::vec4f & _b )
    {
        return mt::cmp_v4_v4( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator != ( const mt::vec4f & _a, const mt::vec4f & _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    void add_v4_v3( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec3f & _b )
    {
        _out->x = _a.x + _b.x;
        _out->y = _a.y + _b.y;
        _out->z = _a.z + _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    void add_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec4f & _b )
    {
        _out->x = _a.x + _b.x;
        _out->y = _a.y + _b.y;
        _out->z = _a.z + _b.z;
        _out->w = _a.w + _b.w;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator + ( const mt::vec4f & _a, const mt::vec4f & _b )
    {
        mt::vec4f out;
        mt::add_v4_v4( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void sub_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, const mt::vec4f & _b )
    {
        _out->x = _a.x - _b.x;
        _out->y = _a.y - _b.y;
        _out->z = _a.z - _b.z;
        _out->w = _a.w - _b.w;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator - ( const mt::vec4f & _a, const mt::vec4f & _b )
    {
        mt::vec4f out;
        mt::sub_v4_v4( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_v4_v4( mt::vec4f * const _out, const mt::vec4f & _a, float _val )
    {
        _out->x = _a.x * _val;
        _out->y = _a.y * _val;
        _out->z = _a.z * _val;
        _out->w = _a.w * _val;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator * ( const mt::vec4f & _rhs, const mt::vec4f & _val )
    {
        return mt::vec4f( _rhs.x * _val.x, _rhs.y * _val.y, _rhs.z * _val.z, _rhs.w * _val.w );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator / ( const mt::vec4f & _rhs, const mt::vec4f & _val )
    {
        return mt::vec4f( _rhs.x / _val.x, _rhs.y / _val.y, _rhs.z / _val.z, _rhs.w / _val.w );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator * ( const mt::vec4f & _rhs, const mt::vec2f & _val )
    {
        return mt::vec4f( _rhs.x * _val.x, _rhs.y * _val.y, _rhs.z * _val.x, _rhs.w * _val.y );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator / ( const mt::vec4f & _rhs, const mt::vec2f & _val )
    {
        return operator * ( _rhs, 1.f / _val );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator * ( const mt::vec4f & _rhs, const float _val )
    {
        mt::vec4f out;
        mt::scale_v4_v4( &out, _rhs, _val );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator / ( const mt::vec4f & _rhs, const float _val )
    {
        return operator * ( _rhs, 1.f / _val );
    }
    //////////////////////////////////////////////////////////////////////////
    void neg_v4( mt::vec4f * const _out )
    {
        _out->x = -_out->x;
        _out->y = -_out->y;
        _out->z = -_out->z;
        _out->w = -_out->w;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f operator - ( vec4f _rhs )
    {
        mt::neg_v4( &_rhs );

        return _rhs;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v4_z( const mt::vec4f & a )
    {
        return a.w;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v4_v2( const mt::vec4f & a, const mt::vec2f & b )
    {
        return a.x * b.x + a.y * b.y + a.w;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v4_v3( const mt::vec4f & a, const mt::vec3f & b )
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v4_v4( const mt::vec4f & a, const mt::vec4f & b )
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }
    //////////////////////////////////////////////////////////////////////////
    void norm_v4_v4( mt::vec4f * const _out, const mt::vec4f & _rhs )
    {
        float l = _rhs.length();

        *_out = _rhs / l;
    }
    //////////////////////////////////////////////////////////////////////////
    float norm_v4_v4_f( mt::vec4f * const _out, const mt::vec4f & _rhs )
    {
        float l = _rhs.length();

        *_out = _rhs / l;

        return l;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f norm_v4_v4( const mt::vec4f & _rhs )
    {
        mt::vec4f out;
        mt::norm_v4_v4( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void norm_safe_v4( mt::vec4f * const _out, const mt::vec4f & _rhs, float _err )
    {
        float len = _rhs.length();

        if( len > _err )
        {
            *_out = _rhs / len;
        }
        else
        {
            *_out = _rhs;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f norm_safe_v4( const mt::vec4f & _rhs )
    {
        mt::vec4f out;
        mt::norm_safe_v4( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void homogenize_v4( mt::vec4f * const _out, const mt::vec4f & _rhs )
    {
        float w_inv = 1.f / _rhs.w;

        _out->x = _rhs.x * w_inv;
        _out->y = _rhs.y * w_inv;
        _out->z = _rhs.z * w_inv;
        _out->w = 1.0f;
    }
    //////////////////////////////////////////////////////////////////////////
    void homogenize_v3_v4( mt::vec3f * const _out, const mt::vec4f & _rhs )
    {
        float w_inv = 1.f / _rhs.w;

        _out->x = _rhs.x * w_inv;
        _out->y = _rhs.y * w_inv;
        _out->z = _rhs.z * w_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec4f homogenize_v4( const mt::vec4f & _rhs )
    {
        mt::vec4f out;
        mt::homogenize_v4( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    float length_v4( const mt::vec4f & _rhs )
    {
        float l = _rhs.length();

        return l;
    }
    //////////////////////////////////////////////////////////////////////////

}