#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    struct line2f
    {
        float a;
        float b;
        float c;
    };

    MT_FUNCTION_INLINE void line_from_two_point_v2( mt::line2f & _line, const mt::vec2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE float line_dot_point_v2( mt::line2f & _line, const mt::vec2f & _a );
    MT_FUNCTION_INLINE bool line_intersect_v2( const mt::line2f & _l1, const mt::line2f & _l2, mt::vec2f & _p );
    MT_FUNCTION_INLINE void line_intersect_v2_np( const mt::line2f & _l1, const mt::line2f & _l2, mt::vec2f & _p );
};

#if MT_FORCE_INLINE == 1
#include "math/line2_inline.h"
#endif
