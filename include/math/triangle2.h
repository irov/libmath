#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    struct triangle2
    {
        mt::vec2f v0;
        mt::vec2f v1;
        mt::vec2f v2;
    };

    bool triangle2_intersect( const triangle2 & _a, const mt::vec2f & _p );
    bool triangle2_intersect( const triangle2 & _a, const triangle2 & _b );
}