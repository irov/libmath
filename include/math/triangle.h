#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    bool triangle_intersect_v2( const mt::vec2f & _a, const mt::vec2f & _b, const mt::vec2f & _c, const mt::vec2f & _p );
    bool triangle_intersect_triangle( const mt::vec2f & a1, const mt::vec2f & a2, const mt::vec2f & a3, const mt::vec2f & b1, const mt::vec2f & b2, const mt::vec2f & b3 );
}