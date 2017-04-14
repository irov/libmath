#	pragma once

#	include "config.h"

#	include <stdlib.h>

namespace mt
{
	LIBMATH_FUNCTION_INLINE float randf( float _max )
	{
		float rnf = static_cast<float>( ::rand() ) / ( static_cast<float>(RAND_MAX) + 1.0f);
		float rf = _max * rnf;
		return rf;
	}

	/* Равномерное распределение с a != b */
	LIBMATH_FUNCTION_INLINE float range_randf( float _a, float _b )
	{
		if( _a > _b )
		{
			return _a;
		}

		float max = ( _b - _a );
		float rf = randf( max );

		return _a + rf;
	}

	LIBMATH_FUNCTION_INLINE uint32_t rand( uint32_t _max )
	{
		float rf = randf( static_cast<float>(_max) );

		uint32_t ri = static_cast<uint32_t>(rf);

		return ri;
	}

	LIBMATH_FUNCTION_INLINE uint32_t range_rand( uint32_t _a, uint32_t _b )
	{
		if( _a > _b )
		{
			return _a;
		}

		uint32_t max = (_b - _a);
		uint32_t ri = mt::rand( max );

		return _a + ri;
	}
}
