#include "math/triangle2.h"

#include "math/line2.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    static float __triangle2_sign( float px, float py, float qx, float qy, float rx, float ry )
    {
        return (px - rx) * (qy - ry) - (qx - rx) * (py - ry);
    }
    //////////////////////////////////////////////////////////////////////////
    bool triangle2_intersect( const triangle2 & _a, const mt::vec2f & _p )
    {
        float d1 = __triangle2_sign( _p.x, _p.y, _a.v0.x, _a.v0.y, _a.v1.x, _a.v1.y );
        float d2 = __triangle2_sign( _p.x, _p.y, _a.v1.x, _a.v1.y, _a.v2.x, _a.v2.y );
        float d3 = __triangle2_sign( _p.x, _p.y, _a.v2.x, _a.v2.y, _a.v0.x, _a.v0.y );

        bool has_neg = (d1 < 0.f) || (d2 < 0.f) || (d3 < 0.f);
        bool has_pos = (d1 > 0.f) || (d2 > 0.f) || (d3 > 0.f);

        return !(has_neg && has_pos);
    }
    //////////////////////////////////////////////////////////////////////////
    bool triangle2_intersect( const triangle2 & _a, const triangle2 & _b )
    {
        mt::line2f la1;
        mt::line2f la2;
        mt::line2f la3;
        mt::line2_from_two_point_v2( &la1, _a.v1, _a.v0 );
        mt::line2_from_two_point_v2( &la2, _a.v2, _a.v1 );
        mt::line2_from_two_point_v2( &la3, _a.v0, _a.v2 );

        mt::line2f lb1;
        mt::line2f lb2;
        mt::line2f lb3;
        mt::line2_from_two_point_v2( &lb1, _b.v1, _b.v0 );
        mt::line2_from_two_point_v2( &lb2, _b.v2, _b.v1 );
        mt::line2_from_two_point_v2( &lb3, _b.v0, _b.v2 );

        if( mt::line2_dot_point_v2( la1, _b.v0 ) > 0.f &&
            mt::line2_dot_point_v2( la1, _b.v1 ) > 0.f &&
            mt::line2_dot_point_v2( la1, _b.v2 ) > 0.f )
        {
            return false;
        }

        if( mt::line2_dot_point_v2( la2, _b.v0 ) > 0.f &&
            mt::line2_dot_point_v2( la2, _b.v1 ) > 0.f &&
            mt::line2_dot_point_v2( la2, _b.v2 ) > 0.f )
        {
            return false;
        }

        if( mt::line2_dot_point_v2( la3, _b.v0 ) > 0.f &&
            mt::line2_dot_point_v2( la3, _b.v1 ) > 0.f &&
            mt::line2_dot_point_v2( la3, _b.v2 ) > 0.f )
        {
            return false;
        }

        if( mt::line2_dot_point_v2( lb1, _a.v0 ) > 0.f &&
            mt::line2_dot_point_v2( lb1, _a.v1 ) > 0.f &&
            mt::line2_dot_point_v2( lb1, _a.v2 ) > 0.f )
        {
            return false;
        }

        if( mt::line2_dot_point_v2( lb2, _a.v0 ) > 0.f &&
            mt::line2_dot_point_v2( lb2, _a.v1 ) > 0.f &&
            mt::line2_dot_point_v2( lb2, _a.v2 ) > 0.f )
        {
            return false;
        }

        if( mt::line2_dot_point_v2( lb3, _a.v0 ) > 0.f &&
            mt::line2_dot_point_v2( lb3, _a.v1 ) > 0.f &&
            mt::line2_dot_point_v2( lb3, _a.v2 ) > 0.f )
        {
            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
}