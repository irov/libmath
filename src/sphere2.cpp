#include "math/sphere2.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    //cppcheck-suppress uninitMemberVar
    sphere2::sphere2()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    sphere2::sphere2( const mt::vec2f & _position, float _radius )
        : position( _position )
        , radius( _radius )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    sphere2::sphere2( const mt::sphere2 & _sphere )
        : position( _sphere.position )
        , radius( _sphere.radius )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    sphere2 & sphere2::operator = ( const sphere2 & _sphere )
    {
        position = _sphere.position;
        radius = _sphere.radius;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    bool sphere2_intersect_sphere2( const mt::sphere2 & _sphere0, const mt::sphere2 & _sphere1 )
    {
        float distance = _sphere0.radius + _sphere1.radius;

        float sqrlength = mt::sqrlength_v2_v2( _sphere0.position, _sphere1.position );

        if( sqrlength > distance * distance )
        {
            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
}