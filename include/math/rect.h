#	pragma once

#	include "math/config.h"

#	include "math/vec2.h"

namespace mt
{
	//////////////////////////////////////////////////////////////////////////
	struct rectf
	{
		float x;
		float y;
		float width;
		float height;

		LIBMATH_METHOD_INLINE rectf();
		LIBMATH_METHOD_INLINE rectf(const rectf & _rect);
		LIBMATH_METHOD_INLINE explicit rectf(float _x, float _y, float _width, float _height);
		LIBMATH_METHOD_INLINE rectf & operator = (const rectf & _rhs);

        LIBMATH_METHOD_INLINE bool empty() const;
	};

    LIBMATH_FUNCTION_INLINE bool rect_contains_point( const rectf & _rect, const mt::vec2f & _point );
}

#	if LIBMATH_FORCE_INLINE == 1
#		include "math/rect_inline.h"
#	endif