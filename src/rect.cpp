#include "math/rect.h"

#if MT_FORCE_INLINE == 0
namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE rectf::rectf()
        : x( 0.f )
        , y( 0.f )
        , width( 0.f )
        , height( 0.f )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE rectf::rectf( float _x, float _y, float _width, float _height )
        : x( _x )
        , y( _y )
        , width( _width )
        , height( _height )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE rectf::rectf( const mt::rectf & _rect )
        : x( _rect.x )
        , y( _rect.y )
        , width( _rect.width )
        , height( _rect.height )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE mt::rectf & rectf::operator = ( const mt::rectf & _rect )
    {
        x = _rect.x;
        y = _rect.y;
        width = _rect.width;
        height = _rect.height;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE bool rectf::empty() const
    {
        if( width == 0.f || height == 0.f )
        {
            return true;
        }

        return false;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool rect_contains_point( const mt::rectf & _rect, const mt::vec2f & _point )
    {
        if( _point.x >= _rect.x && _point.x <= _rect.x + _rect.width && _point.y >= _rect.y && _point.y <= _rect.y + _rect.height )
        {
            return true;
        }

        return false;
    }
    //////////////////////////////////////////////////////////////////////////
}
#endif
