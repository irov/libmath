#include "math/segment2.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    //cppcheck-suppress uninitMemberVar
    segment2::segment2()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    segment2::segment2( const mt::vec2f & _a, const mt::vec2f & _b )
        : a( _a )
        , b( _b )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    segment2::segment2( const mt::segment2 & _segment )
        : a( _segment.a )
        , b( _segment.b )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    segment2 & segment2::operator = ( const mt::segment2 & _segment )
    {
        a = _segment.a;
        b = _segment.b;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    float segment2_distance_squared( const mt::segment2 & _segment0, const mt::segment2 & _segment1, float * const _sc, float * const _tc )
    {
        mt::vec2f w0 = _segment0.a - _segment1.a;

        mt::vec2f a_direction = _segment0.b - _segment0.a;
        mt::vec2f b_direction = _segment1.b - _segment1.a;

        float a = mt::dot_v2_v2( a_direction, a_direction );
        float b = mt::dot_v2_v2( a_direction, b_direction );
        float c = mt::dot_v2_v2( b_direction, b_direction );
        float d = mt::dot_v2_v2( a_direction, w0 );
        float e = mt::dot_v2_v2( b_direction, w0 );

        float denom = a * c - b * b;
        float sn, sd, tn, td;

        if( mt::equal_f_z( denom ) == true )
        {
            sd = td = c;
            sn = 0.f;
            tn = e;
        }
        else
        {
            sd = td = denom;
            sn = b * e - c * d;
            tn = a * e - b * d;

            if( sn < 0.f )
            {
                sn = 0.f;
                tn = e;
                td = c;
            }
            else if( sn > sd )
            {
                sn = sd;
                tn = e + b;
                td = c;
            }
        }

        if( tn < 0.f )
        {
            *_tc = 0.f;

            if( -d < 0.f )
            {
                *_sc = 0.f;
            }
            else if( -d > a )
            {
                *_sc = 1.f;
            }
            else
            {
                *_sc = -d / a;
            }
        }
        else if( tn > td )
        {
            *_tc = 1.f;

            if( (-d + b) < 0.f )
            {
                *_sc = 0.f;
            }
            else if( (-d + b) > a )
            {
                *_sc = 1.f;
            }
            else
            {
                *_sc = (-d + b) / a;
            }
        }
        else
        {
            *_tc = tn / td;
            *_sc = sn / sd;
        }

        mt::vec2f wc = w0 + *_sc * a_direction - *_tc * b_direction;

        float wcd = mt::dot_v2_v2( wc, wc );

        return wcd;
    }
    //////////////////////////////////////////////////////////////////////////
    bool segment2_intersect( const mt::vec2f & _a0, const mt::vec2f & _b0, const mt::vec2f & _a1, const mt::vec2f & _b1 )
    {
        if( _a0 == _a1 || _a0 == _b1 || _b0 == _a1 || _b0 == _b1 )
        {
            return false;
        }

        float x1 = _a0.x;
        float y1 = _a0.y;
        float x2 = _b0.x;
        float y2 = _b0.y;
        float x3 = _a1.x;
        float y3 = _a1.y;
        float x4 = _b1.x;
        float y4 = _b1.y;

        float ua = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
        float ub = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);
        float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);

        if( mt::equal_f_z( denom ) == true )
        {
            return false;
        }

        float denom_inv = 1.f / denom;

        ua *= denom_inv;
        ub *= denom_inv;

        if( (0.f > ua) || (ua > 1.f) || (0.f > ub) || (ub > 1.f) )
        {
            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    bool segment2_intersect( const mt::segment2 & _segment0, const mt::segment2 & _segment1 )
    {
        return segment2_intersect( _segment0.a, _segment0.b, _segment1.a, _segment1.b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool segment2_intersect( const mt::segment2 & _segment0, const mt::segment2 & _segment1, mt::vec2f * const _p )
    {
        if( _segment0.a == _segment1.a ||
            _segment0.a == _segment1.b ||
            _segment0.b == _segment1.a ||
            _segment0.b == _segment1.b )
        {
            return false;
        }

        float x1 = _segment0.a.x;
        float y1 = _segment0.a.y;
        float x2 = _segment0.b.x;
        float y2 = _segment0.b.y;
        float x3 = _segment1.a.x;
        float y3 = _segment1.a.y;
        float x4 = _segment1.b.x;
        float y4 = _segment1.b.y;

        float ua = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
        float ub = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);
        float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);

        if( mt::equal_f_z( denom ) == true )
        {
            return false;
        }

        float denom_inv = 1.f / denom;

        ua *= denom_inv;
        ub *= denom_inv;

        if( (0.f > ua) || (ua > 1.f) || (0.f > ub) || (ub > 1.f) )
        {
            return false;
        }

        _p->x = x1 + ua * (x2 - x1);
        _p->y = y1 + ua * (y2 - y1);

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    void segment2_projection_v2( const mt::segment2 & _segment0, const mt::vec2f & _point, mt::vec2f * const _out )
    {
        const float sqrl = mt::sqrlength_v2_v2( _segment0.a, _segment0.b );

        mt::vec2f p0 = _point - _segment0.a;
        mt::vec2f p1 = _segment0.b - _segment0.a;
        float t = mt::dot_v2_v2( p0, p1 ) / sqrl;

        float tn = mt::clampf( 0.f, t, 1.f );

        *_out = _segment0.a + tn * (_segment0.b - _segment0.a);
    }
    //////////////////////////////////////////////////////////////////////////
}