#pragma once

#include "math/config.h"

#include "math/segment2.h"

namespace mt
{
    struct capsule2
    {
        mt::segment2 segment;
        float radius;

        capsule2();
        capsule2( const mt::segment2 & _segment, float _radius );
    };

    bool capsule2_intersect_segment( const mt::capsule2 & _capsule, const mt::segment2 & _segment );
    bool capsule2_intersect_capsule2( const mt::capsule2 & _capsule0, const mt::capsule2 & _capsule1 );
}
