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

        segment2( const segment2 & _segment )
            : a( _segment.a )
            , b( _segment.b )
        {
        }

    public:
        segment2 & operator = ( const segment2 & _segment )
        {
            a = _segment.a;
            b = _segment.b;

            return *this;
        }

    public:
        mt::vec2f a;
        mt::vec2f b;
    };

    MT_FUNCTION_INLINE float segment2_distance_squared(
        const mt::segment2 & _segment0,
        const mt::segment2 & _segment1,
        float & _sc,
        float & _tc );

    MT_FUNCTION_INLINE bool segment2_intersect_segment2(
        const mt::segment2 & _segment0,
        const mt::segment2 & _segment1,
        mt::vec2f & _intersectionPoint );

    MT_FUNCTION_INLINE void segment2_projection_point(
        const mt::segment2 & _segment0,
        const mt::vec2f & _point, mt::vec2f & _projection );
}

#if MT_FORCE_INLINE == 1
#include "math/segment2_inline.h"
#endif
