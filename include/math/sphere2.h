#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    struct sphere2
    {
        mt::vec2f position;
        float radius;
        
        sphere2();
        sphere2( const mt::vec2f & _position, float _radius );
        sphere2( const mt::sphere2 & _sphere );
        sphere2 & operator = ( const sphere2 & _sphere );
    };

    bool sphere2_intersect_sphere2( const mt::sphere2 & _sphere0, const mt::sphere2 & _sphere1 );
}
