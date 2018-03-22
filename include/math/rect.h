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

		MT_METHOD_INLINE rectf();
		MT_METHOD_INLINE rectf(const rectf & _rect);
		MT_METHOD_INLINE explicit rectf(float _x, float _y, float _width, float _height);
		MT_METHOD_INLINE rectf & operator = (const rectf & _rhs);

        MT_METHOD_INLINE bool empty() const;
	};

    MT_FUNCTION_INLINE bool rect_contains_point( const rectf & _rect, const mt::vec2f & _point );
}

#if MT_FORCE_INLINE == 1
#include "math/rect_inline.h"
#endif
