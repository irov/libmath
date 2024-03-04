#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    void polygon2_centroid( const mt::vec2f * _polygon, size_t _count, mt::vec2f * const _point );
    bool polygon2_intersect( const mt::vec2f * _polygon, size_t _count, const mt::vec2f & _point );
    bool polygon2_intersect( const mt::vec2f * _polygon, size_t _count, const mt::vec2f & _point, float _rx, float _ry );
    bool polygon2_intersect( const mt::vec2f * _polygon1, size_t _count1, const mt::vec2f * _polygon2, size_t _count2 );
}