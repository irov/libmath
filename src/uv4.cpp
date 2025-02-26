#include "math/uv4.h"

#include "math/line2.h"
#include "math/vec3.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    uv4f::uv4f()
        : p0( 0.f, 0.f )
        , p1( 1.f, 0.f )
        , p2( 1.f, 1.f )
        , p3( 0.f, 1.f )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    uv4f::uv4f( const mt::vec2f & _p0, const mt::vec2f & _p1, const mt::vec2f & _p2, const mt::vec2f & _p3 )
        : p0( _p0 )
        , p1( _p1 )
        , p2( _p2 )
        , p3( _p3 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    uv4f::uv4f( const mt::vec4f & _mask )
        : p0( _mask.x, _mask.y )
        , p1( _mask.z, _mask.y )
        , p2( _mask.z, _mask.w )
        , p3( _mask.x, _mask.w )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    uv4f::uv4f( const mt::uv4f & _uv )
        : p0( _uv.p0 )
        , p1( _uv.p1 )
        , p2( _uv.p2 )
        , p3( _uv.p3 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec2f & uv4f::operator [] ( size_t i ) const
    {
        return (&p0)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & uv4f::operator [] ( size_t i )
    {
        return (&p0)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    mt::uv4f & uv4f::operator = ( const mt::uv4f & _rhs )
    {
        p0 = _rhs.p0;
        p1 = _rhs.p1;
        p2 = _rhs.p2;
        p3 = _rhs.p3;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4f::set( const mt::vec2f & _p0, const mt::vec2f & _p1, const mt::vec2f & _p2, const mt::vec2f & _p3 )
    {
        p0 = _p0;
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
    }
    //////////////////////////////////////////////////////////////////////////
    float * uv4f::buff()
    {
        return p0.buff();
    }
    //////////////////////////////////////////////////////////////////////////
    const float * uv4f::buff() const
    {
        return p0.buff();
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::uv4f & uv4f::identity()
    {
        static mt::uv4f uv;

        return uv;
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator == ( const mt::uv4f & _a, const mt::uv4f & _b )
    {
        return mt::uv4_cmp( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool operator != ( const mt::uv4f & _a, const mt::uv4f & _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool uv4_cmp( const mt::uv4f & _a, const mt::uv4f & _b )
    {
        return mt::cmp_v2_v2( _a.p0, _b.p0 ) == true &&
            mt::cmp_v2_v2( _a.p1, _b.p1 ) == true &&
            mt::cmp_v2_v2( _a.p2, _b.p2 ) == true &&
            mt::cmp_v2_v2( _a.p3, _b.p3 ) == true;
    }
    //////////////////////////////////////////////////////////////////////////
    bool uv4_is_identity( const mt::uv4f & _uv )
    {
        float uv_c = _uv.p0.x + _uv.p0.y +
            _uv.p1.x + _uv.p1.y +
            _uv.p2.x + _uv.p2.y +
            _uv.p3.x + _uv.p3.y;

        if( mt::equal_f_f( uv_c, 4.f ) == false )
        {
            return false;
        }

        return mt::equal_f_z( _uv.p0.x ) == true &&
            mt::equal_f_z( _uv.p0.y ) == true &&
            mt::equal_f_1( _uv.p1.x ) == true &&
            mt::equal_f_z( _uv.p1.y ) == true &&
            mt::equal_f_1( _uv.p2.x ) == true &&
            mt::equal_f_1( _uv.p2.y ) == true &&
            mt::equal_f_z( _uv.p3.x ) == true &&
            mt::equal_f_1( _uv.p3.y ) == true;
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_identity( mt::uv4f * const _uv )
    {
        *_uv = mt::uv4f();
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_from_mask( mt::uv4f * const _out, const mt::vec4f & _mask )
    {
        _out->p0 = mt::vec2f( _mask.x, _mask.y );
        _out->p1 = mt::vec2f( _mask.z, _mask.y );
        _out->p2 = mt::vec2f( _mask.z, _mask.w );
        _out->p3 = mt::vec2f( _mask.x, _mask.w );
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_rotate( mt::uv4f * const _out )
    {
        mt::vec2f tmp = _out->p0;
        _out->p0 = _out->p1;
        _out->p1 = _out->p2;
        _out->p2 = _out->p3;
        _out->p3 = tmp;
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_swap_u( mt::uv4f * const _out )
    {
        mt::vec2f tmp_0 = _out->p0;
        _out->p0 = _out->p1;
        _out->p1 = tmp_0;

        mt::vec2f tmp_1 = _out->p2;
        _out->p2 = _out->p3;
        _out->p3 = tmp_1;
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_swap_v( mt::uv4f * const _out )
    {
        mt::vec2f tmp_0 = _out->p0;
        _out->p0 = _out->p3;
        _out->p3 = tmp_0;

        mt::vec2f tmp_1 = _out->p1;
        _out->p1 = _out->p2;
        _out->p2 = tmp_1;
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_scale( mt::uv4f * const _out, const mt::uv4f & _uv, const mt::vec2f & _scale )
    {
        _out->p0 = _uv.p0;
        _out->p1 = _uv.p0 + (_uv.p1 - _uv.p0) * _scale;
        _out->p2 = _uv.p1 + (_uv.p2 - _uv.p1) * _scale;
        _out->p3 = _uv.p0 + (_uv.p3 - _uv.p0) * _scale;
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_quad_point( mt::vec2f * const _out, const mt::uv4f & _uv, const mt::vec2f & _point )
    {
        *_out = _uv.p0 + (_uv.p2 - _uv.p0) * _point;
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_quad_point_rotate( mt::vec2f * const _out, const mt::uv4f & _uv, const mt::vec2f & _point )
    {
        *_out = _uv.p0 + (_uv.p2 - _uv.p0) * mt::vec2f( _point.y, _point.x );
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_multiply_tetragon( mt::uv4f * const _out, const mt::uv4f & _uv1, const mt::uv4f & _uv2 )
    {
        const mt::vec2f & A = _uv1.p0;
        const mt::vec2f & B = _uv1.p1;
        const mt::vec2f & C = _uv1.p2;
        const mt::vec2f & D = _uv1.p3;

        for( size_t i = 0; i != 4; ++i )
        {
            const mt::vec2f & uv = _uv2[i];

            mt::vec2f AB = A + (B - A) * uv.x;
            mt::vec2f DC = D + (C - D) * uv.x;

            mt::vec2f AD = A + (D - A) * uv.y;
            mt::vec2f BC = B + (C - B) * uv.y;

            mt::line2f uv_l1;
            mt::line2_from_two_point_v2( &uv_l1, AB, DC );

            mt::line2f uv_l2;
            mt::line2_from_two_point_v2( &uv_l2, AD, BC );

            mt::vec2f new_uv;
            mt::line2_intersect_v2_np( uv_l1, uv_l2, &new_uv );

            (*_out)[i] = new_uv;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_multiply_tetragon_vp( mt::uv4f * const _out, const mt::uv4f & _uv1, const mt::vec2f * _uv2 )
    {
        const mt::vec2f & A = _uv1.p0;
        const mt::vec2f & B = _uv1.p1;
        const mt::vec2f & C = _uv1.p2;
        const mt::vec2f & D = _uv1.p3;

        for( size_t i = 0; i != 4; ++i )
        {
            const mt::vec2f & uv = _uv2[i];

            mt::vec2f AB = A + (B - A) * uv.x;
            mt::vec2f DC = D + (C - D) * uv.x;

            mt::vec2f AD = A + (D - A) * uv.y;
            mt::vec2f BC = B + (C - B) * uv.y;

            mt::line2f uv_l1;
            mt::line2_from_two_point_v2( &uv_l1, AB, DC );

            mt::line2f uv_l2;
            mt::line2_from_two_point_v2( &uv_l2, AD, BC );

            mt::vec2f new_uv;
            mt::line2_intersect_v2_np( uv_l1, uv_l2, &new_uv );

            (*_out)[i] = new_uv;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_multiply_tetragon_v2( mt::vec2f * const _out, const mt::uv4f & _uv, const mt::vec2f & _p )
    {
        const mt::vec2f & A = _uv.p0;
        const mt::vec2f & B = _uv.p1;
        const mt::vec2f & C = _uv.p2;
        const mt::vec2f & D = _uv.p3;

        mt::vec2f AB = A + (B - A) * _p.x;
        mt::vec2f DC = D + (C - D) * _p.x;

        mt::vec2f AD = A + (D - A) * _p.y;
        mt::vec2f BC = B + (C - B) * _p.y;

        mt::line2f uv_l1;
        mt::line2_from_two_point_v2( &uv_l1, AB, DC );

        mt::line2f uv_l2;
        mt::line2_from_two_point_v2( &uv_l2, AD, BC );

        mt::vec2f new_uv;
        mt::line2_intersect_v2_np( uv_l1, uv_l2, &new_uv );

        *_out = new_uv;
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_multiply_tetragon_v4( mt::uv4f * const _out, const mt::uv4f & _uv, const mt::vec4f & _mask )
    {
        mt::uv4f uv2;
        mt::uv4_from_mask( &uv2, _mask );

        mt::uv4_multiply_tetragon( _out, _uv, uv2 );
    }
    //////////////////////////////////////////////////////////////////////////
    void uv4_calc_point( const mt::vec2f & _a, const mt::vec2f & _b, const mt::vec2f & _c, const mt::vec2f & _auv, const mt::vec2f & _buv, const mt::vec2f & _cuv, const mt::vec2f & _point, mt::vec2f * const _uv )
    {
        mt::vec2f uvA = _auv;
        mt::vec2f dAB = _b - _a;
        mt::vec2f dAC = _c - _a;

        float inv_v = 1.f / (dAB.x * dAC.y - dAB.y * dAC.x);
        dAB *= inv_v;
        dAC *= inv_v;

        mt::vec2f dac;
        dac.x = dAC.x * _a.y - dAC.y * _a.x;
        dac.y = -(dAB.x * _a.y - dAB.y * _a.x);

        dAB *= -1.f;

        dAB.x *= -1.f;
        dAC.x *= -1.f;

        mt::vec2f duvAB = _buv - uvA;
        mt::vec2f duvAC = _cuv - uvA;

        float a = mt::dot_v3_v3( mt::vec3f( dac.x, dAC.y, dAC.x ), mt::vec3f( 1.f, _point.x, _point.y ) );
        float b = mt::dot_v3_v3( mt::vec3f( dac.y, dAB.y, dAB.x ), mt::vec3f( 1.f, _point.x, _point.y ) );

        float u = mt::dot_v3_v3( mt::vec3f( uvA.x, duvAB.x, duvAC.x ), mt::vec3f( 1.f, a, b ) );
        float v = mt::dot_v3_v3( mt::vec3f( uvA.y, duvAB.y, duvAC.y ), mt::vec3f( 1.f, a, b ) );

        _uv->x = u;
        _uv->y = v;
    }
    //////////////////////////////////////////////////////////////////////////
}
