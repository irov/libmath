#	pragma once

#	include "config.h"

#	include "vec3.h"
#	include "mat4.h"

namespace mt
{
	class planef
	{
	public:
		float a;
		float b;
		float c;
		float d;

		LIBMATH_METHOD_INLINE planef();
		LIBMATH_METHOD_INLINE planef( const planef& plane );
		LIBMATH_METHOD_INLINE planef( const vec3f &_norm, float _dist );
		LIBMATH_METHOD_INLINE planef( float _x, float _y, float _z, float _d );

		LIBMATH_METHOD_INLINE float * buff();
		LIBMATH_METHOD_INLINE const float * buff() const;
	};

	LIBMATH_FUNCTION_INLINE void get_plane_normal( vec3f & _out, const planef & _plane );
	LIBMATH_FUNCTION_INLINE void get_plane_point( vec3f & _out, const planef & _plane );
	LIBMATH_FUNCTION_INLINE void set_plane_by_triangle( planef & _plane, const vec3f & _v0, const vec3f & _v1, const vec3f & _v2 );
	LIBMATH_FUNCTION_INLINE void set_plane_by_point_and_normal( planef & _plane, const vec3f & _point, const vec3f & _normal );
	LIBMATH_FUNCTION_INLINE bool projection_to_plane( vec3f & _out, const vec3f & _eye, const vec3f  & _dir, const planef & _plane );
	LIBMATH_FUNCTION_INLINE void reflect_plane( vec3f & _out, const vec3f  & _dir, const planef & _plane );
	LIBMATH_FUNCTION_INLINE void mul_plane_mat4( planef & _out, const planef & _plane, const mt::mat4f & _wm );
}

#	if LIBMATH_FORCE_INLINE == 1
#	include "plane_inline.h"
#	endif
