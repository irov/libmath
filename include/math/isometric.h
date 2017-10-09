#   pragma once

#	include "math/config.h"

namespace mt
{
    class isometric
    {
    public:
        float w;
        float h;

        LIBMATH_METHOD_INLINE isometric( float w, float h );

    public:
        LIBMATH_METHOD_INLINE void screen2iso( float sx, float sy, float & ix, float & iy );
        LIBMATH_METHOD_INLINE void iso2screen( float ix, float iy, float & sx, float & sy );
    };
}

#	if LIBMATH_FORCE_INLINE == 1
#	include "math/isometric_inline.h"
#	endif
