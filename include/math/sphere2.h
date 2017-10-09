#	pragma once

#	include "math/config.h"

#	include "math/vec2.h"

namespace mt
{
	class sphere2
	{
	public:
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

	public:
		mt::vec2f position;
		float radius;
	};

	LIBMATH_FUNCTION_INLINE bool sphere2_intersect_sphere2( const mt::sphere2 & _sphere0, const mt::sphere2 & _sphere1 );
}

#	if LIBMATH_FORCE_INLINE == 1
#		include "math/sphere2_inline.h"
#	endif
