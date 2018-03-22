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
        MT_METHOD_INLINE void screen2iso( float sx, float sy, float & ix, float & iy );
        MT_METHOD_INLINE void iso2screen( float ix, float iy, float & sx, float & sy );
    };
}

#if MT_FORCE_INLINE == 1
#include "math/isometric_inline.h"
#endif
