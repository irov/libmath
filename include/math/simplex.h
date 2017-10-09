#	pragma once

#	include	"math/vec3.h"

#	include "math/config.h"

namespace mt
{
	class simplex_solver
	{
	public:
		LIBMATH_METHOD_INLINE simplex_solver();

	public:
		LIBMATH_METHOD_INLINE void reset();
		LIBMATH_METHOD_INLINE void addWPQ( const mt::vec3f & w, const mt::vec3f & p, const mt::vec3f & q  );
		LIBMATH_METHOD_INLINE bool update( mt::vec3f & V );

	private:
		LIBMATH_METHOD_INLINE void remove_1();
		LIBMATH_METHOD_INLINE void remove_2();
		LIBMATH_METHOD_INLINE bool solve( mt::vec3f AO, mt::vec3f AB, mt::vec3f & V );
		LIBMATH_METHOD_INLINE bool solve( mt::vec3f AO, mt::vec3f AB, mt::vec3f AC, mt::vec3f & V );

	private:
		int size;
		float eps;

		mt::vec3f W[3];
		mt::vec3f P[3];
		mt::vec3f Q[3];
	};
};

#	if LIBMATH_FORCE_INLINE == 1
#	include	"math/simplex_inline.h"
#	endif
