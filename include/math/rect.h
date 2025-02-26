#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    struct rectf
    {
        float x;
        float y;
        float width;
        float height;

        rectf();
        rectf( const mt::rectf & _rect );
        rectf( float _x, float _y, float _width, float _height );
        mt::rectf & operator = ( const mt::rectf & _rect );

        bool empty() const;
    };

    bool rect_contains_point( const mt::rectf & _rect, const mt::vec2f & _point );
}
