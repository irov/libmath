#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    struct convex8
    {
        mt::vec2f point[8];
        uint32_t count;

        convex8();

        const mt::vec2f & operator [] ( size_t i ) const;
        mt::vec2f & operator [] ( size_t i );

        void add( const mt::vec2f & v );
        const mt::vec2f & front() const;
        const mt::vec2f & back() const;
        uint32_t size() const;
        bool empty() const;
        void clear();
    };

    void convex8_intersect( const mt::convex8 & _convex, const mt::convex8 & _clip, mt::convex8 & _result );
    float convex8_area( const mt::convex8 & _convex );
}
