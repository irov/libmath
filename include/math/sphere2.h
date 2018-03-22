#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{
	class sphere2
	{
	public:
        //cppcheck-suppress uninitMemberVar
		sphere2()
		{
		}

		sphere2( const mt::vec2f & _position, float _radius )
			: position( _position )
			, radius(_radius)
		{
		}

		sphere2( const mt::sphere2 & _sphere )
			: position( _sphere.position )
			, radius( _sphere.radius )
		{
		}

        sphere2 & operator = ( const sphere2 & _sphere )
        {
            position = _sphere.position;
            radius = _sphere.radius;

            return *this;
        }

	public:
		mt::vec2f position;
		float radius;
	};

	MT_FUNCTION_INLINE bool sphere2_intersect_sphere2( const mt::sphere2 & _sphere0, const mt::sphere2 & _sphere1 );
}

#if MT_FORCE_INLINE == 1
#include "math/sphere2_inline.h"
#endif
