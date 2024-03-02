#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    struct segment2
    {   
        mt::vec2f a;
        mt::vec2f b;

        segment2();
        segment2( const mt::vec2f & _a, const mt::vec2f & _b );
        segment2( const mt::segment2 & _segment );
        segment2 & operator = ( const mt::segment2 & _segment );
    };

    float segment2_distance_squared( const mt::segment2 & _segment0, const mt::segment2 & _segment1, float * const _sc, float * const _tc );
    bool segment2_intersect( const mt::vec2f & _a0, const mt::vec2f & _b0, const mt::vec2f & _a1, const mt::vec2f & _b1 );
    bool segment2_intersect( const mt::segment2 & _segment0, const mt::segment2 & _segment1 );
    bool segment2_intersect( const mt::segment2 & _segment0, const mt::segment2 & _segment1, mt::vec2f * const _intersectionPoint );
    void segment2_projection_v2( const mt::segment2 & _segment0, const mt::vec2f & _point, mt::vec2f * const _projection );
}
