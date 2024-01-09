#include "math/mat2.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    mat2f::mat2f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mat2f::mat2f( const mt::mat2f & _m2 )
        : v0( _m2.v0 )
        , v1( _m2.v1 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mat2f::mat2f( const mt::vec2f & _v0, const mt::vec2f & _v1 )
        : v0( _v0 )
        , v1( _v1 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & mat2f::operator []( size_t i )
    {
        return (&v0)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec2f & mat2f::operator []( size_t i )const
    {
        return (&v0)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    mt::mat2f & mat2f::operator=( const mt::mat2f & _m2 )
    {
        v0 = _m2.v0;
        v1 = _m2.v1;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    bool cmp_m2_m2( const mt::mat2f & _a, const mt::mat2f & _b )
    {
        return mt::cmp_v2_v2( _a.v0, _b.v0 ) && mt::cmp_v2_v2( _a.v1, _b.v1 );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator==( const mt::mat2f & _a, const mt::mat2f & _b )
    {
        return mt::cmp_m2_m2( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator!=( const mt::mat2f & _a, const mt::mat2f & _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_m2_v2( mt::vec2f * const _out, const mt::mat2f & _m, const mt::vec2f & _v )
    {
        _out->x = mt::dot_v2_v2( _m.v0, _v );
        _out->y = mt::dot_v2_v2( _m.v1, _v );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator*( const mt::mat2f & _m, const mt::vec2f & _v )
    {
        mt::vec2f out;
        mt::mul_m2_v2( &out, _m, _v );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_v2_m2( mt::vec2f * const _out, const mt::vec2f & _v, const mt::mat2f & _m )
    {
        _out->x = _m.v0.x * _v.x + _m.v1.x * _v.y;
        _out->y = _m.v0.y * _v.x + _m.v1.y * _v.y;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f operator* ( const mt::vec2f & _v, const mt::mat2f & _m )
    {
        mt::vec2f out;
        mt::mul_v2_m2( &out, _v, _m );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void mul_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b )
    {
        _out->v0.x = _a.v0.x * _b.v0.x + _a.v0.y * _b.v1.x;
        _out->v0.y = _a.v0.x * _b.v0.y + _a.v0.y * _b.v1.y;
        _out->v1.x = _a.v1.x * _b.v0.x + _a.v1.y * _b.v1.x;
        _out->v1.y = _a.v1.x * _b.v0.y + _a.v1.y * _b.v1.y;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::mat2f operator* ( const mt::mat2f & _a, const mt::mat2f & _b )
    {
        mt::mat2f out;
        mt::mul_m2_m2( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void add_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b )
    {
        mt::add_v2_v2( &_out->v0, _a.v0, _b.v0 );
        mt::add_v2_v2( &_out->v1, _a.v1, _b.v1 );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::mat2f operator+( const mt::mat2f & _a, const mt::mat2f & _b )
    {
        mt::mat2f out;
        mt::add_m2_m2( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void sub_m2_m2( mt::mat2f * const _out, const mt::mat2f & _a, const mt::mat2f & _b )
    {
        mt::sub_v2_v2( &_out->v0, _a.v0, _b.v0 );
        mt::sub_v2_v2( &_out->v1, _a.v1, _b.v1 );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::mat2f operator-( const mt::mat2f & _a, const mt::mat2f & _b )
    {
        mt::mat2f out;
        mt::sub_m2_m2( &out, _a, _b );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_m2_s( mt::mat2f * const _out, const mt::mat2f & _rhs, float _val )
    {
        mt::mul_v2_f( &_out->v0, _rhs.v0, _val );
        mt::mul_v2_f( &_out->v1, _rhs.v1, _val );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::mat2f operator*( const mt::mat2f & _rhs, float _val )
    {
        mt::mat2f out;
        mt::scale_m2_s( &out, _rhs, _val );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    void scale_m2_s( mt::mat2f * const _out, float _val )
    {
        mt::mul_v2_f( &_out->v0, _out->v0, _val );
        mt::mul_v2_f( &_out->v1, _out->v1, _val );
    }
    //////////////////////////////////////////////////////////////////////////
    void transpose_m2( mt::mat2f * const _out, const mt::mat2f & _rhs )
    {
        _out->v0.x = _rhs.v0.x;
        _out->v0.y = _rhs.v1.x;

        _out->v1.x = _rhs.v0.y;
        _out->v1.y = _rhs.v1.y;
    }
    //////////////////////////////////////////////////////////////////////////
    mt::mat2f transpose_m2( const mt::mat2f & _rhs )
    {
        mt::mat2f out;
        transpose_m2( &out, _rhs );

        return out;
    }
    //////////////////////////////////////////////////////////////////////////
}