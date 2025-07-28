#include "math/vec3.h"
#include "math/stdmath.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    //cppcheck-suppress uninitMemberVar
    vec3f::vec3f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f::vec3f( float _x, float _y, float _z )
        : x( _x )
        , y( _y )
        , z( _z )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f::vec3f( const mt::vec3f & _v )
        : x( _v.x )
        , y( _v.y )
        , z( _v.z )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f::vec3f( const mt::vec2f & _v, float _z )
        : x( _v.x )
        , y( _v.y )
        , z( _z )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f::vec3f( const float * _v )
        : x( _v[0] )
        , y( _v[1] )
        , z( _v[2] )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f & vec3f::operator = ( const mt::vec3f & _rhs )
    {
        this->x = _rhs.x;
        this->y = _rhs.y;
        this->z = _rhs.z;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    float vec3f::operator [] ( size_t i ) const
    {
        return (&this->x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    float & vec3f::operator [] ( size_t i )
    {
        return (&this->x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f & vec3f::operator += ( const mt::vec3f & _rhs )
    {
        this->x += _rhs.x;
        this->y += _rhs.y;
        this->z += _rhs.z;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f & vec3f::operator -= ( const mt::vec3f & _rhs )
    {
        this->x -= _rhs.x;
        this->y -= _rhs.y;
        this->z -= _rhs.z;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f & vec3f::operator *= ( const mt::vec3f & _rhs )
    {
        this->x *= _rhs.x;
        this->y *= _rhs.y;
        this->z *= _rhs.z;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f & vec3f::operator /= ( const mt::vec3f & _rhs )
    {
        this->x /= _rhs.x;
        this->y /= _rhs.y;
        this->z /= _rhs.z;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f & vec3f::operator *= ( const float _rhs )
    {
        this->x *= _rhs;
        this->y *= _rhs;
        this->z *= _rhs;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f & vec3f::operator /= ( const float _rhs )
    {
        operator *= ( 1.f / _rhs );

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    void vec3f::set( float _x, float _y, float _z )
    {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }
    //////////////////////////////////////////////////////////////////////////
    float vec3f::sqrlength() const
    {
        return this->x * this->x + this->y * this->y + this->z * this->z;
    }
    //////////////////////////////////////////////////////////////////////////
    float vec3f::length() const
    {
        float sqrlen = this->sqrlength();

        float len = MT_sqrtf( sqrlen );

        return len;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f vec3f::to_vec2f() const
    {
        return mt::vec2f( this->x, this->y );
    }
    //////////////////////////////////////////////////////////////////////////
    void vec3f::from_f3( const float * _v )
    {
        this->x = _v[0];
        this->y = _v[1];
        this->z = _v[2];
    }
    //////////////////////////////////////////////////////////////////////////
    void vec3f::from_f2( const float * _v, float _z )
    {
        this->x = _v[0];
        this->y = _v[1];
        this->z = _z;
    }
    //////////////////////////////////////////////////////////////////////////
    float * vec3f::buff()
    {
        return &this->x;
    }
    //////////////////////////////////////////////////////////////////////////
    const float * vec3f::buff() const
    {
        return &this->x;
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec3f & vec3f::identity()
    {
        static mt::vec3f v( 0.f, 0.f, 0.f );

        return v;
    }
    //////////////////////////////////////////////////////////////////////////
    void ident_v3( mt::vec3f * const _out )
    {
        _out->x = 0.f;
        _out->y = 0.f;
        _out->z = 0.f;
    }
    //////////////////////////////////////////////////////////////////////////
    float length_f( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        return mt::length_v3_v3( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    float length_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f c = _a - _b;
        float len = c.length();

        return len;
    }
    //////////////////////////////////////////////////////////////////////////
    float sqrlength_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f c = _a - _b;
        float sqrlength = c.sqrlength();

        return sqrlength;
    }
    //////////////////////////////////////////////////////////////////////////
    float sqrlength_v3( const mt::vec3f & _a )
    {
        float sqrlength = _a.sqrlength();

        return sqrlength;
    }
    //////////////////////////////////////////////////////////////////////////
    void dir_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f dir = _b - _a;

        mt::norm_v3_v3( _out, dir );
    }
    //////////////////////////////////////////////////////////////////////////
    float dir_v3_v3_f( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f dir = _b - _a;

        float l = mt::norm_v3_v3_f( _out, dir );

        return l;
    }
    //////////////////////////////////////////////////////////////////////////
    float length_v3( const mt::vec3f & _a )
    {
        float len = _a.length();

        return len;
    }
    //////////////////////////////////////////////////////////////////////////
    bool cmp_v3_v2( const mt::vec3f & _a, const mt::vec2f & _b )
    {
        return _a.x == _b.x && _a.y == _b.y;
    }
    //////////////////////////////////////////////////////////////////////////
    bool cmp_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        return _a.x == _b.x && _a.y == _b.y && _a.z == _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator == ( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        return mt::cmp_v3_v3( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator != ( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        return !operator == ( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    void add_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b )
    {
        _out->x = _a.x + _b.x;
        _out->y = _a.y + _b.y;
        _out->z = _a.z + _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f operator + ( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f out;
        mt::add_v3_v3( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void sub_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b )
    {
        _out->x = _a.x - _b.x;
        _out->y = _a.y - _b.y;
        _out->z = _a.z - _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f operator - ( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f out;
        mt::sub_v3_v3( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f operator * ( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f out;
        mt::mul_v3_v3( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, float _val )
    {
        _out->x = _a.x * _val;
        _out->y = _a.y * _val;
        _out->z = _a.z * _val;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b )
    {
        _out->x = _a.x * _b.x;
        _out->y = _a.y * _b.y;
        _out->z = _a.z * _b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f operator * ( const mt::vec3f & _rhs, const float _val )
    {
        mt::vec3f out;
        mt::scale_v3_v3( &out, _rhs, _val );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f operator * ( const float _val, const mt::vec3f & _rhs )
    {
        mt::vec3f out;
        mt::scale_v3_v3( &out, _rhs, _val );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f operator / ( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f out;
        out.x = _a.x / _b.x;
        out.y = _a.y / _b.y;
        out.z = _a.z / _b.z;

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f operator / ( const mt::vec3f & _rhs, const float _val )
    {
        return operator*( _rhs, 1 / _val );
    }
    //////////////////////////////////////////////////////////////////////////
    void neg_v3( mt::vec3f * const _out )
    {
        _out->x = -_out->x;
        _out->y = -_out->y;
        _out->z = -_out->z;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f operator - ( vec3f _rhs )
    {
        mt::neg_v3( &_rhs );

        return _rhs;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v3( const mt::vec3f & a )
    {
        return a.x * a.x + a.y * a.y + a.z * a.z;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v3_v3( const mt::vec3f & a, const mt::vec3f & b )
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v3_v2( const mt::vec3f & a, const mt::vec2f & b )
    {
        return a.x * b.x + a.y * b.y;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v3_v3_clamp( const mt::vec3f & a, const mt::vec3f & b )
    {
        float dot = a.x * b.x + a.y * b.y + a.z * b.z;
        if( dot > 1.0f ) dot = 1.0f;
        if( dot < -1.0f ) dot = -1.0f;
        return dot;
    }
    //////////////////////////////////////////////////////////////////////////
    void reflect_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b )
    {
        *_out = _a - _b * mt::dot_v3_v3( _a, _b ) * 2.0f;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f reflect_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f out;
        mt::reflect_v3_v3( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    float project_to_line_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b, const mt::vec3f & _c )
    {
        float da = mt::dot_v3_v3( _c - _a, _b - _a );
        float db = mt::dot_v3_v3( _b - _a, _b - _a );

        float dab = (da / db);

        *_out = _a + (_b - _a) * dab;

        return dab;
    }
    //////////////////////////////////////////////////////////////////////////
    void cross_v3_v3( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b )
    {
        _out->x = _a.y * _b.z - _a.z * _b.y;
        _out->y = _a.z * _b.x - _a.x * _b.z;
        _out->z = _a.x * _b.y - _a.y * _b.x;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f cross_v3_v3( const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::vec3f out;
        mt::cross_v3_v3( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void cross_v3_v3_norm( mt::vec3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b )
    {
        mt::cross_v3_v3( _out, _a, _b );
        mt::norm_v3_v3( _out, *_out );
    }
    //////////////////////////////////////////////////////////////////////////
    void norm_v3_v3( mt::vec3f * const _out, const mt::vec3f & _rhs )
    {
        *_out = _rhs / _rhs.length();
    }
    //////////////////////////////////////////////////////////////////////////
    float norm_v3_v3_f( mt::vec3f * const _out, const mt::vec3f & _rhs )
    {
        float l = _rhs.length();

        *_out = _rhs / l;

        return l;
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f norm_v3( const mt::vec3f & _rhs )
    {
        mt::vec3f out;
        mt::norm_v3_v3( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void norm_safe_v3( mt::vec3f * const _out, const mt::vec3f & _rhs, float _err )
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
    vec3f norm_safe_v3( const mt::vec3f & _rhs )
    {
        mt::vec3f out;
        mt::norm_safe_v3( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    float get_axis_angle( const mt::vec3f & dir, int axis )
    {
        int ind1 = 1;
        int ind2 = 2;

        if( axis == 1 )
        {
            ind1 = 0;
            ind2 = 2;
        }
        else if( axis == 2 )
        {
            ind1 = 0;
            ind2 = 1;
        }

        float result = 0.f;

        float dx = dir[ind1];
        float dy = dir[ind2];

        mt::vec2f d( dx, dy );

        mt::vec2f n;
        mt::norm_v2_v2( &n, d );

        if( n.x >= 0.f && n.y >= 0.f )
        {
            result = MT_asinf( n.y );
        }
        else if( n.x <= 0.f && n.y <= 0.f )
        {
            result = mt::constant::pi + MT_asinf( -n.y );
        }
        else if( n.x >= 0.f && n.y <= 0.f )
        {
            result = mt::constant::half_pi - MT_asinf( -n.y );
        }
        else if( n.x <= 0.f && n.y >= 0.f )
        {
            result = mt::constant::pi - MT_asinf( n.y );
        }

        float angle = mt::constant::half_pi - result;

        return angle;
    }
    //////////////////////////////////////////////////////////////////////////
    void linerp_v3( mt::vec3f * const _out, const mt::vec3f & _in1, const mt::vec3f & _in2, float _scale )
    {
        _out->x = mt::linerp_f1( _in1.x, _in2.x, _scale );
        _out->y = mt::linerp_f1( _in1.y, _in2.y, _scale );
        _out->z = mt::linerp_f1( _in1.z, _in2.z, _scale );
    }
    //////////////////////////////////////////////////////////////////////////
    float follow_v3( mt::vec3f * const _out, const mt::vec3f & _in1, const mt::vec3f & _in2, float _step )
    {
        mt::vec3f dir;
        float l = mt::dir_v3_v3_f( &dir, _in1, _in2 );

        if( l - _step < 0.f )
        {
            *_out = _in2;

            return _step - l;
        }

        *_out = _in1 + dir * _step;

        return 0.f;
    }
    //////////////////////////////////////////////////////////////////////////
}