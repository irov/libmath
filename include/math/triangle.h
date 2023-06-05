#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{    
    MT_FUNCTION_INLINE bool triangle_intersect_v2( const mt::vec2f & _a, const mt::vec2f & _b, const mt::vec2f & _c, const mt::vec2f & _p );
    MT_FUNCTION_INLINE bool triangle_intersect_triangle( const mt::vec2f & a1, const mt::vec2f & a2, const mt::vec2f & a3, const mt::vec2f & b1, const mt::vec2f & b2, const mt::vec2f & b3 );
}

#if MT_FORCE_INLINE == 1
#include "math/triangle.cpp"
#endif