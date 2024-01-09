#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    class convex8
    {
    public:
        convex8();

    public:
        const mt::vec2f & operator [] ( size_t i ) const;
        mt::vec2f & operator [] ( size_t i );

    public:
        void add( const mt::vec2f & v );
        const mt::vec2f & front() const;
        const mt::vec2f & back() const;
        uint32_t size() const;
        bool empty() const;
        void clear();

    protected:
        mt::vec2f point[8];
        uint32_t count;
    };

    void convex8_intersect( const mt::convex8 & _convex, const mt::convex8 & _clip, mt::convex8 & _result );
    float convex8_area( const mt::convex8 & _convex );
}
