#include "math/mat3.h"

#include "math/angle.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    mat3f::mat3f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f::mat3f( const mt::mat3f & _rhs )
        : v0( _rhs.v0 )
        , v1( _rhs.v1 )
        , v2( _rhs.v2 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f::mat3f( const mt::vec3f & _v0, const mt::vec3f & _v1, const mt::vec3f & _v2 )
        : v0( _v0 )
        , v1( _v1 )
        , v2( _v2 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f::mat3f( float _v00, float _v01, float _v02, float _v10, float _v11, float _v12, float _v20, float _v21, float _v22 )
        : v0( _v00, _v01, _v02 )
        , v1( _v10, _v11, _v12 )
        , v2( _v20, _v21, _v22 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f & mat3f::operator []( size_t i )
    {
        return (&v0)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec3f & mat3f::operator []( size_t i )const
    {
        return (&v0)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    mt::mat3f & mat3f::operator=( const mt::mat3f & _rhs )
    {
        v0 = _rhs.v0;
        v1 = _rhs.v1;
        v2 = _rhs.v2;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    float * mat3f::buff()
    {
        return v0.buff();
    }
    //////////////////////////////////////////////////////////////////////////
    float * buff_m3( const mt::mat3f & _a )
    {
        return (float *)&_a.v0.x;
    }
    //////////////////////////////////////////////////////////////////////////
    bool cmp_m3_m3( const mt::mat3f & _a, const mt::mat3f & _b )
    {
        return mt::cmp_v3_v3( _a.v0, _b.v0 ) && mt::cmp_v3_v3( _a.v1, _b.v1 ) && mt::cmp_v3_v3( _a.v2, _b.v2 );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator==( const mt::mat3f & _a, const mt::mat3f & _b )
    {
        return mt::cmp_m3_m3( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator!=( const mt::mat3f & _a, const mt::mat3f & _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_m3_v3( mt::vec3f * const _out, const mt::mat3f & _m, const mt::vec3f & _v )
    {
        _out->x = mt::dot_v3_v3( _m.v0, _v );
        _out->y = mt::dot_v3_v3( _m.v1, _v );
        _out->z = mt::dot_v3_v3( _m.v2, _v );
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_m3_v2( mt::vec2f * const _out, const mt::mat3f & _m, const mt::vec2f & _v )
    {
        _out->x = mt::dot_v3_v2( _m.v0, _v );
        _out->y = mt::dot_v3_v2( _m.v1, _v );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f operator*( const mt::mat3f & _m, const mt::vec3f & _v )
    {
        mt::vec3f out;
        mt::mul_m3_v3( &out, _m, _v );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_v3_m3( mt::vec3f * const _out, const mt::vec3f & _v, const mt::mat3f & _m )
    {
        _out->x = _m.v0.x * _v.x + _m.v1.x * _v.y + _m.v2.z * _v.z;
        _out->y = _m.v0.y * _v.x + _m.v1.y * _v.y + _m.v2.z * _v.z;
        _out->z = _m.v0.z * _v.x + _m.v1.z * _v.y + _m.v2.z * _v.z;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec3f operator* ( const mt::vec3f & _v, const mt::mat3f & _m )
    {
        mt::vec3f out;
        mt::mul_v3_m3( &out, _v, _m );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_v2_m3( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat3f & _m )
    {
        mt::mul_v2_m3_r( _out, _v, _m );

        _out->x += _m.v2.x;
        _out->y += _m.v2.y;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator * ( const mt::vec2f & _v, const mt::mat3f & _m )
    {
        mt::vec2f out;
        mt::mul_v2_m3( &out, _v, _m );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_v2_m3_r( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat3f & _m )
    {
        _out->x = _m.v0.x * _v.x + _m.v1.x * _v.y;
        _out->y = _m.v0.y * _v.x + _m.v1.y * _v.y;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_m3_m3_i( mt::vec3f * const _out, const mt::vec3f & _a, const mt::mat3f & _b )
    {
        _out->x = _a.x * _b.v0.x + _a.y * _b.v1.x + _a.z * _b.v2.x;
        _out->y = _a.x * _b.v0.y + _a.y * _b.v1.y + _a.z * _b.v2.y;
        _out->z = _a.x * _b.v0.z + _a.y * _b.v1.z + _a.z * _b.v2.z;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_m3_m3( mt::mat3f * const _out, const mt::mat3f & _a, const mt::mat3f & _b )
    {
        mt::mul_m3_m3_i( &_out->v0, _a.v0, _b );
        mt::mul_m3_m3_i( &_out->v1, _a.v1, _b );
        mt::mul_m3_m3_i( &_out->v2, _a.v2, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f operator * ( const mt::mat3f & _a, const mt::mat3f & _b )
    {
        mt::mat3f out;
        mt::mul_m3_m3( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void add_m3_m3( mt::mat3f * const _out, const mt::mat3f & _a, const mt::mat3f & _b )
    {
        mt::add_v3_v3( &_out->v0, _a.v0, _b.v0 );
        mt::add_v3_v3( &_out->v1, _a.v1, _b.v1 );
        mt::add_v3_v3( &_out->v2, _a.v2, _b.v2 );
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f operator + ( const mt::mat3f & _a, const mt::mat3f & _b )
    {
        mt::mat3f out;
        mt::add_m3_m3( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void sub_m3_m3( mt::mat3f * const _out, const mt::mat3f & _a, const mt::mat3f & _b )
    {
        mt::sub_v3_v3( &_out->v0, _a.v0, _b.v0 );
        mt::sub_v3_v3( &_out->v1, _a.v1, _b.v1 );
        mt::sub_v3_v3( &_out->v2, _a.v2, _b.v2 );
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f operator - ( const mt::mat3f & _a, const mt::mat3f & _b )
    {
        mt::mat3f out;
        mt::sub_m3_m3( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_m3_s( mt::mat3f * const _out, const mt::mat3f & _rhs, float _val )
    {
        mt::scale_v3_v3( &_out->v0, _rhs.v0, _val );
        mt::scale_v3_v3( &_out->v1, _rhs.v1, _val );
        mt::scale_v3_v3( &_out->v2, _rhs.v2, _val );
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f operator * ( const mt::mat3f & _rhs, float _val )
    {
        mt::mat3f out;
        mt::scale_m3_s( &out, _rhs, _val );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_m3_s( mt::mat3f * const _out, float _val )
    {
        mt::scale_v3_v3( &_out->v0, _out->v0, _val );
        mt::scale_v3_v3( &_out->v1, _out->v1, _val );
        mt::scale_v3_v3( &_out->v2, _out->v2, _val );
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_m3_m3( mt::mat3f * const _out, const mt::mat3f & _rhs, const mt::vec3f & _val )
    {
        mt::scale_v3_v3( &_out->v0, _rhs.v0, _val.x );
        mt::scale_v3_v3( &_out->v1, _rhs.v1, _val.y );
        mt::scale_v3_v3( &_out->v2, _rhs.v2, _val.z );
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_m3( mt::mat3f * const _out, const mt::vec3f & _val )
    {
        mt::scale_m3_m3( _out, *_out, _val );
    }
    //////////////////////////////////////////////////////////////////////////
    void transpose_m3( mt::mat3f * const _out, const mt::mat3f & _rhs )
    {
        _out->v0.x = _rhs.v0.x;
        _out->v1.y = _rhs.v1.y;
        _out->v2.z = _rhs.v2.z;

        _out->v1.x = _rhs.v0.y;
        _out->v2.x = _rhs.v0.z;
        _out->v2.y = _rhs.v1.z;

        _out->v0.y = _rhs.v1.x;
        _out->v0.z = _rhs.v2.x;
        _out->v1.z = _rhs.v2.y;
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f transpose_m3( const mt::mat3f & _rhs )
    {
        mt::mat3f out;
        mt::transpose_m3( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    float det_m3( const mt::mat3f & _rhs )
    {
        float cof00 = _rhs.v1[1] * _rhs.v2[2] - _rhs.v1[2] * _rhs.v2[1];
        float cof10 = _rhs.v1[2] * _rhs.v2[0] - _rhs.v1[0] * _rhs.v2[2];
        float cof20 = _rhs.v1[0] * _rhs.v2[1] - _rhs.v1[1] * _rhs.v2[0];

        float det = _rhs.v0.x * cof00 + _rhs.v0.y * cof10 + _rhs.v0.z * cof20;

        return det;
    }
    //////////////////////////////////////////////////////////////////////////
    void inv_m3( mt::mat3f * const _out, const mt::mat3f & _rhs )
    {
        _out->v0[0] = _rhs.v1[1] * _rhs.v2[2] - _rhs.v1[2] * _rhs.v2[1];
        _out->v0[1] = _rhs.v0[2] * _rhs.v2[1] - _rhs.v0[1] * _rhs.v2[2];
        _out->v0[2] = _rhs.v0[1] * _rhs.v1[2] - _rhs.v0[2] * _rhs.v1[1];
        _out->v1[0] = _rhs.v1[2] * _rhs.v2[0] - _rhs.v1[0] * _rhs.v2[2];
        _out->v1[1] = _rhs.v0[0] * _rhs.v2[2] - _rhs.v0[2] * _rhs.v2[0];
        _out->v1[2] = _rhs.v0[2] * _rhs.v1[0] - _rhs.v0[0] * _rhs.v1[2];
        _out->v2[0] = _rhs.v1[0] * _rhs.v2[1] - _rhs.v1[1] * _rhs.v2[0];
        _out->v2[1] = _rhs.v0[1] * _rhs.v2[0] - _rhs.v0[0] * _rhs.v2[1];
        _out->v2[2] = _rhs.v0[0] * _rhs.v1[1] - _rhs.v0[1] * _rhs.v1[0];

        float det =
            _rhs.v0[0] * _out->v0[0] +
            _rhs.v0[1] * _out->v1[0] +
            _rhs.v0[2] * _out->v2[0];

        float idet = 1.0f / det;

        _out->v0[0] *= idet;
        _out->v1[0] *= idet;
        _out->v2[0] *= idet;
        _out->v0[1] *= idet;
        _out->v1[1] *= idet;
        _out->v2[1] *= idet;
        _out->v0[2] *= idet;
        _out->v1[2] *= idet;
        _out->v2[2] *= idet;
    }
    //////////////////////////////////////////////////////////////////////////
    void ident_m3( mt::mat3f * const _out )
    {
        mt::ident_v3( &_out->v0 );
        mt::ident_v3( &_out->v1 );
        mt::ident_v3( &_out->v2 );

        _out->v0.x = 1.f;
        _out->v1.y = 1.f;
        _out->v2.z = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    void get_col_m3( mt::vec3f * const out, const mt::mat3f & _rhs, int _index )
    {
        out->x = _rhs.v0[_index];
        out->y = _rhs.v1[_index];
        out->z = _rhs.v2[_index];
    }
    //////////////////////////////////////////////////////////////////////////
    vec3f get_col_m3( const mt::mat3f & _rhs, int _index )
    {
        mt::vec3f out;
        mt::get_col_m3( &out, _rhs, _index );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void set_col_m3( mt::mat3f * const out, const mt::vec3f & _rhs, int _index )
    {
        out->v0[_index] = _rhs.x;
        out->v1[_index] = _rhs.y;
        out->v2[_index] = _rhs.z;
    }
    //////////////////////////////////////////////////////////////////////////
    void set_m3_from_axes( mt::mat3f * const _out, const mt::vec3f & _a, const mt::vec3f & _b, const mt::vec3f & _c )
    {
        _out->v0 = _a;
        _out->v1 = _b;
        _out->v2 = _c;
    }
    //////////////////////////////////////////////////////////////////////////
    mat3f set_m3_from_axes( const mt::vec3f & _a, const mt::vec3f & _b, const mt::vec3f & _c )
    {
        mt::mat3f m;
        mt::set_m3_from_axes( &m, _a, _b, _c );

        return m;
    }
    //////////////////////////////////////////////////////////////////////////
    void make_rotate_x_axis_m3( mt::mat3f * const _out, float _angle )
    {
        float cosa = MT_cosf( _angle );
        float sina = MT_sinf( _angle );

        _out->v0.x = 1.f;
        _out->v0.y = 0.f;
        _out->v0.z = 0.f;

        _out->v1.x = 0.f;
        _out->v1.y = cosa;
        _out->v1.z = -sina;

        _out->v2.x = 0.f;
        _out->v2.y = sina;
        _out->v2.z = cosa;
    }
    //////////////////////////////////////////////////////////////////////////
    void make_rotate_y_axis_m3( mt::mat3f * const _out, float _angle )
    {
        float cosa = MT_cosf( _angle );
        float sina = MT_sinf( _angle );

        _out->v0.x = cosa;
        _out->v0.y = 0.f;
        _out->v0.z = sina;

        _out->v1.x = 0.f;
        _out->v1.y = 1.f;
        _out->v1.z = 0.f;

        _out->v2.x = -sina;
        _out->v2.y = 0.f;
        _out->v2.z = cosa;
    }
    //////////////////////////////////////////////////////////////////////////
    void make_rotate_z_axis_m3( mt::mat3f * const _out, float _angle )
    {
        float cosa = MT_cosf( _angle );
        float sina = MT_sinf( _angle );

        _out->v0.x = cosa;
        _out->v0.y = -sina;
        _out->v0.z = 0.f;

        _out->v1.x = sina;
        _out->v1.y = cosa;
        _out->v1.z = 0.f;

        _out->v2.x = 0.f;
        _out->v2.y = 0.f;
        _out->v2.z = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    void translate_m3( mt::mat3f * const _out, const mt::mat3f & _in, const mt::vec2f & _offset )
    {
        _out->v0 = _in.v0;
        _out->v1 = _in.v1;
        _out->v2.x = _in.v2.x + _offset.x;
        _out->v2.y = _in.v2.y + _offset.y;
        _out->v2.z = _in.v2.z;
    }
    //////////////////////////////////////////////////////////////////////////
}