#pragma once

#include "math/config.h"

#include "math/segment2.h"

namespace mt
{
    class capsule2
    {
    public:
        //cppcheck-suppress uninitMemberVar
        capsule2()
        {
        }

        capsule2( const mt::segment2 & _segment, float _radius )
            : segment( _segment )
            , radius( _radius )
        {
        }

    public:
        mt::segment2 segment;
        float radius;
    };

    bool capsule2_intersect_segment( const mt::capsule2 & _capsule, const mt::segment2 & _segment );
    bool capsule2_intersect_capsule2( const mt::capsule2 & _capsule0, const mt::capsule2 & _capsule1 );
}
