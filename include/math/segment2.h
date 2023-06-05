#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    class segment2
    {
    public:
        //cppcheck-suppress uninitMemberVar
        segment2()
        {
        }

        segment2( const mt::vec2f & _a, const mt::vec2f & _b )
            : a( _a )
            , b( _b )
        {
        }

        segment2( const mt::segment2 & _segment )
            : a( _segment.a )
            , b( _segment.b )
        {
        }

    public:
        segment2 & operator = ( const mt::segment2 & _segment )
        {
            a = _segment.a;
            b = _segment.b;

            return *this;
        }

    public:
        mt::vec2f a;
        mt::vec2f b;
    };

    float segment2_distance_squared( const mt::segment2 & _segment0, const mt::segment2 & _segment1, float * const _sc, float * const _tc );
    bool segment2_intersect_segment2( const mt::segment2 & _segment0, const mt::segment2 & _segment1 );
    bool segment2_intersect_segment2_point( const mt::segment2 & _segment0, const mt::segment2 & _segment1, mt::vec2f * const _intersectionPoint );
    void segment2_projection_point( const mt::segment2 & _segment0, const mt::vec2f & _point, mt::vec2f * const _projection );
}
