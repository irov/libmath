#include "math/capsule2.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    bool capsule2_intersect_segment( const mt::capsule2 & _capsule, const mt::segment2 & _segment )
    {
        float s, t;
        float distancesq = mt::segment2_distance_squared( _capsule.segment, _segment, &s, &t );

        return distancesq <= _capsule.radius * _capsule.radius;
    }
    //////////////////////////////////////////////////////////////////////////
    bool capsule2_intersect_capsule2( const mt::capsule2 & _capsule0, const mt::capsule2 & _capsule1 )
    {
        float radiusSum = _capsule0.radius + _capsule1.radius;

        float s, t;
        float distancesq = mt::segment2_distance_squared( _capsule0.segment, _capsule1.segment, &s, &t );

        return distancesq <= radiusSum * radiusSum;
    }
    //////////////////////////////////////////////////////////////////////////
}