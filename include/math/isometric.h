#   pragma once

#include "math/config.h"

namespace mt
{
    class isometric
    {
    public:
        float w;
        float h;

        MT_METHOD_INLINE isometric( float w, float h );

    public:
        MT_METHOD_INLINE void screen2iso( float _sx, float _sy, float * const _ix, float * const _iy ) const;
        MT_METHOD_INLINE void iso2screen( float _ix, float _iy, float * const _sx, float * const _sy ) const;
    };
}

#if MT_FORCE_INLINE == 1
#include "math/isometric.cpp"
#endif
