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

    void line_from_two_point_v2( mt::line2f * const _line, const mt::vec2f & _a, const mt::vec2f & _b );
    float line_dot_point_v2( const mt::line2f & _line, const mt::vec2f & _a );
    bool line_intersect( const mt::line2f & _l1, const mt::line2f & _l2 );
    bool line_intersect_v2( const mt::line2f & _l1, const mt::line2f & _l2, mt::vec2f * const _p );
    void line_intersect_v2_np( const mt::line2f & _l1, const mt::line2f & _l2, mt::vec2f * const _p );
};