#   pragma once

#include "math/config.h"

namespace mt
{
    class isometric
    {
    public:
        float w;
        float h;

        isometric( float w, float h );

    public:
        void screen2iso( float _sx, float _sy, float * const _ix, float * const _iy ) const;
        void iso2screen( float _ix, float _iy, float * const _sx, float * const _sy ) const;
    };
}
