#include "math/vec2.h"

#include "math/angle.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    //cppcheck-suppress uninitMemberVar
    vec2f::vec2f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec2f::vec2f( float _x, float _y )
        : x( _x )
        , y( _y )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec2f::vec2f( const mt::vec2f & _v2 )
        : x( _v2.x )
        , y( _v2.y )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    vec2f::vec2f( const float * _v )
        : x( _v[0] )
        , y( _v[1] )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & vec2f::operator = ( const mt::vec2f & _v2 )
    {
        x = _v2.x;
        y = _v2.y;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    float vec2f::operator [] ( size_t i ) const
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    float & vec2f::operator [] ( size_t i )
    {
        return (&x)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & vec2f::operator+=( const mt::vec2f & _v2 )
    {
        x += _v2.x;
        y += _v2.y;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & vec2f::operator-=( const mt::vec2f & _v2 )
    {
        x -= _v2.x;
        y -= _v2.y;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & vec2f::operator/=( float _v )
    {
        operator *= ( 1.f / _v );

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & vec2f::operator*=( float _v )
    {
        x *= _v;
        y *= _v;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & vec2f::operator/=( const mt::vec2f & _v2 )
    {
        x /= _v2.x;
        y /= _v2.y;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & vec2f::operator*=( const mt::vec2f & _v2 )
    {
        x *= _v2.x;
        y *= _v2.y;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    void vec2f::from_f2( const float * _v )
    {
        x = _v[0];
        y = _v[1];
    }
    //////////////////////////////////////////////////////////////////////////
    float vec2f::sqrlength() const
    {
        return x * x + y * y;
    }
    //////////////////////////////////////////////////////////////////////////
    float vec2f::length() const
    {
        float sql = this->sqrlength();

        return MT_sqrtf( sql );
    }
    //////////////////////////////////////////////////////////////////////////
    float * vec2f::buff()
    {
        return &x;
    }
    //////////////////////////////////////////////////////////////////////////
    const float * vec2f::buff() const
    {
        return &x;
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec2f & vec2f::identity()
    {
        static mt::vec2f v( 0.f, 0.f );

        return v;
    }
    //////////////////////////////////////////////////////////////////////////
    void ident_v2( vec2f * const _a )
    {
        _a->x = 0.f;
        _a->y = 0.f;
    }
    //////////////////////////////////////////////////////////////////////////
    float length_f( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        float l = length_v2_v2( _a, _b );

        return l;
    }
    //////////////////////////////////////////////////////////////////////////
    float length_v2( const mt::vec2f & _a )
    {
        float l = _a.length();

        return l;
    }
    //////////////////////////////////////////////////////////////////////////
    float sqrlength_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        mt::vec2f c = _a - _b;

        float sqrlength = c.sqrlength();

        return sqrlength;
    }
    //////////////////////////////////////////////////////////////////////////
    float length_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        mt::vec2f c = _a - _b;

        float l = c.length();

        return l;
    }
    //////////////////////////////////////////////////////////////////////////
    bool cmp_v2_v2( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        return mt::equal_f_f( _a.x, _b.x ) == true && mt::equal_f_f( _a.y, _b.y ) == true;
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator==( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        return mt::cmp_v2_v2( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator!=( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    void add_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b )
    {
        _out->x = _a.x + _b.x;
        _out->y = _a.y + _b.y;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator+( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        mt::vec2f out;
        mt::add_v2_v2( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void sub_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b )
    {
        _out->x = _a.x - _b.x;
        _out->y = _a.y - _b.y;
    }
    //////////////////////////////////////////////////////////////////////////
    void dir_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b )
    {
        mt::vec2f out;
        mt::sub_v2_v2( &out, _a, _b );

        mt::norm_v2_v2( _out, out );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator-( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        mt::vec2f out;
        mt::sub_v2_v2( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_v2_f( mt::vec2f * const _out, const mt::vec2f & _a, float _val )
    {
        _out->x = _a.x * _val;
        _out->y = _a.y * _val;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b )
    {
        _out->x = _a.x * _b.x;
        _out->y = _a.y * _b.y;
    }
    //////////////////////////////////////////////////////////////////////////
    void div_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b )
    {
        _out->x = _a.x / _b.x;
        _out->y = _a.y / _b.y;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator*( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        mt::vec2f out;
        mt::mul_v2_v2( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator*( const mt::vec2f & _rhs, float _val )
    {
        mt::vec2f out;
        mt::mul_v2_f( &out, _rhs, _val );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator * ( float _val, const mt::vec2f & _rhs )
    {
        mt::vec2f out;
        mt::mul_v2_f( &out, _rhs, _val );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator/( const mt::vec2f & _a, const mt::vec2f & _b )
    {
        mt::vec2f out;
        mt::div_v2_v2( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator / ( const mt::vec2f & _rhs, float _val )
    {
        return operator*( _rhs, 1 / _val );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator / ( float _val, const mt::vec2f & _rhs )
    {
        return mt::vec2f( _val / _rhs.x, _val / _rhs.y );
    }
    //////////////////////////////////////////////////////////////////////////
    void inv_v2( mt::vec2f * const _out, const mt::vec2f & _in )
    {
        _out->x = 1.f / _in.x;
        _out->y = 1.f / _in.y;
    }
    //////////////////////////////////////////////////////////////////////////
    void neg_v2( mt::vec2f * const _out )
    {
        _out->x = -_out->x;
        _out->y = -_out->y;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator-( vec2f _rhs )
    {
        mt::neg_v2( &_rhs );

        return _rhs;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator+( vec2f _rhs )
    {
        return _rhs;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v2( const mt::vec2f & a )
    {
        return a.x * a.x + a.y * a.y;
    }
    //////////////////////////////////////////////////////////////////////////
    float dot_v2_v2( const mt::vec2f & a, const mt::vec2f & b )
    {
        return a.x * b.x + a.y * b.y;
    }
    //////////////////////////////////////////////////////////////////////////
    void norm_v2_v2( mt::vec2f * const _out, const mt::vec2f & _rhs )
    {
        float l = _rhs.length();

        *_out = _rhs / l;
    }
    //////////////////////////////////////////////////////////////////////////
    float norm_v2_f( mt::vec2f * const _out, const mt::vec2f & _rhs )
    {
        float l = _rhs.length();

        *_out = _rhs / l;

        return l;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f norm_v2( const mt::vec2f & _rhs )
    {
        mt::vec2f out;
        mt::norm_v2_v2( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void norm_safe_v2( mt::vec2f * const _out, const mt::vec2f & _rhs, float _err )
    {
        float l = _rhs.length();

        if( l > _err )
        {
            *_out = _rhs / l;
        }
        else
        {
            *_out = _rhs;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f norm_safe( const mt::vec2f & _rhs )
    {
        mt::vec2f out;
        mt::norm_safe_v2( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void perp_v2_v2( mt::vec2f * const _out, const mt::vec2f & _a, const mt::vec2f & _b )
    {
        mt::vec2f d;
        mt::dir_v2_v2( &d, _a, _b );

        mt::perp_v2( _out, d );
    }
    //////////////////////////////////////////////////////////////////////////
    void perp_v2( mt::vec2f * const _out, const mt::vec2f & _in )
    {
        _out->x = -_in.y;
        _out->y = _in.x;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f perp( const mt::vec2f & _rhs )
    {
        mt::vec2f pv;
        mt::perp_v2( &pv, _rhs );

        return pv;
    }
    //////////////////////////////////////////////////////////////////////////
    void perp_left_v2( mt::vec2f * const _out, const mt::vec2f & _in )
    {
        _out->x = _in.y;
        _out->y = -_in.x;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f perp_left( const mt::vec2f & _in )
    {
        mt::vec2f pv;
        mt::perp_left_v2( &pv, _in );

        return pv;
    }
    //////////////////////////////////////////////////////////////////////////
    float is_left_v2( const mt::vec2f & p0, const mt::vec2f & p1, const mt::vec2f & p2 )
    {
        return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
    }
    //////////////////////////////////////////////////////////////////////////
    float cross_v2( const mt::vec2f & a, const mt::vec2f & b )
    {
        return a.x * b.y - a.y * b.x;
    }
    //////////////////////////////////////////////////////////////////////////
    void project_v2_v2( mt::vec2f * const out, const mt::vec2f & a, const mt::vec2f & b )
    {
        float dp = mt::dot_v2_v2( a, b );

        out->x = dp * a.x;
        out->y = dp * a.y;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f slerp_v2_v2( const mt::vec2f & a, const mt::vec2f & b, float t )
    {
        float asqrl = a.sqrlength();
        float bsqrl = b.sqrlength();

        float s = MT_sqrtf( asqrl * bsqrl );
        float cos = mt::dot_v2_v2( a, b ) / s;
        if( cos > 1.f )
        {
            cos = 1.f;
        }
        else if( cos < -1.f )
        {
            cos = -1.f;
        }

        float theta = MT_acosf( cos );

        if( theta == 0.f )
        {
            return a;
        }

        float d = 1.f / MT_sinf( theta );
        float s0 = MT_sinf( (1.f - t) * theta );
        float s1 = MT_sinf( t * theta );

        float s2x = (a.x * s0 + b.x * s1) * d;
        float s2y = (a.y * s0 + b.y * s1) * d;
        mt::vec2f s2( s2x, s2y );

        return s2;
    }
    //////////////////////////////////////////////////////////////////////////
    void rotate_v2( mt::vec2f * const _out, float _angle )
    {
        mt::vec2f v = *_out;

        float sin_angle = MT_sinf( _angle );
        float cos_angle = MT_cosf( _angle );
        _out->x = cos_angle * v.x - sin_angle * v.y;
        _out->y = cos_angle * v.y + sin_angle * v.x;
    }
    //////////////////////////////////////////////////////////////////////////
    void direction( mt::vec2f * const _out, float _angle )
    {
        float cos_angle = MT_cosf( _angle );
        float sin_angle = MT_sinf( _angle );

        _out->x = cos_angle;
        _out->y = sin_angle;
    }
    //////////////////////////////////////////////////////////////////////////
    float signed_angle( const mt::vec2f & _vec )
    {
        float l = _vec.length();

        if( l < 0.00001f )
        {
            return 0.f;
        }

        float cos = _vec.x / l;

        float x = mt::angle_acos32( cos );

        if( _vec.y < 0.f )
        {
            return mt::constant::two_pi - x;
        }

        return x;
    }
    //////////////////////////////////////////////////////////////////////////
}