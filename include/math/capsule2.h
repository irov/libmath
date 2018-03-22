#pragma once

#include "math/config.h"

#include "math/segment2.h"

namespace mt
{
	class capsule2
	{
	public:
        //cppcheck-suppress uninitMemberVar
		capsule2()
		{
		}

		capsule2( const mt::segment2 & _segment, float _radius )
			: segment(_segment)
			, radius(_radius)
		{
		}

	public:
		mt::segment2 segment;
		float radius;
	};

	MT_FUNCTION_INLINE bool capsule2_intersect_segment(
		const mt::capsule2 & _capsule,
		const mt::segment2 & _segment );

	MT_FUNCTION_INLINE bool capsule2_intersect_capsule2(
		const mt::capsule2 & _capsule0,
		const mt::capsule2 & _capsule1 );
}

#if MT_FORCE_INLINE == 1
#include "math/capsule2_inline.h"
#endif
