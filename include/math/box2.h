#	pragma once

#	include "config.h"

#	include "mat3.h"
#	include "mat4.h"

namespace mt
{
	struct box2f
	{
		vec2f minimum; 
		vec2f maximum;

		LIBMATH_METHOD_INLINE box2f();
		LIBMATH_METHOD_INLINE box2f( float _minx, float _miny, float _maxx, float _maxy );
		LIBMATH_METHOD_INLINE box2f( const box2f & _box );
		LIBMATH_METHOD_INLINE box2f( const vec2f & _vb, const vec2f & _ve );
	};

	LIBMATH_FUNCTION_INLINE void ident_box(box2f & box);
	LIBMATH_FUNCTION_INLINE void reset(box2f & box,const vec2f & initValue);
	LIBMATH_FUNCTION_INLINE void reset(box2f & box,float x, float y);
	LIBMATH_FUNCTION_INLINE void add_internal_point(box2f & box, float x,float y);
	LIBMATH_FUNCTION_INLINE void add_internal_point(box2f & box, const vec2f & p);
	LIBMATH_FUNCTION_INLINE void merge_box( box2f & box, const box2f & external_box );
	LIBMATH_FUNCTION_INLINE void transpose_box( box2f & _box, const mt::vec2f & _pos );
	LIBMATH_FUNCTION_INLINE void scale_box( box2f & _box, const mt::vec2f & _scale );
	LIBMATH_FUNCTION_INLINE void get_center_box( const box2f & _box, mt::vec2f & _pos );
	LIBMATH_FUNCTION_INLINE void set_box_from_min_max(box2f & box, const vec2f & min, const vec2f & max);
	LIBMATH_FUNCTION_INLINE void set_box_from_two_point( box2f & box, const vec2f & a, const vec2f & b );
	LIBMATH_FUNCTION_INLINE void set_box_from_center_and_extent(box2f & box, const vec2f & center, const vec2f & extent);
	LIBMATH_FUNCTION_INLINE void set_box_from_oriented_extent( box2f & box, const mt::vec2f & _offset, const mt::vec2f & _size, const mt::mat3f & _wm );
	LIBMATH_FUNCTION_INLINE void set_box_homogenize( box2f & box, const mt::vec2f & _begin, const mt::vec2f & _end, const mt::mat4f & _wm );
    LIBMATH_FUNCTION_INLINE bool is_exist( const vec2f & _aminimum, const vec2f & _amaximum, const vec2f & _bminimum, const vec2f & _bmaximum );
	LIBMATH_FUNCTION_INLINE bool is_intersect( const vec2f & _aminimum, const vec2f & _amaximum, const vec2f & _bminimum, const vec2f & _bmaximum );
	LIBMATH_FUNCTION_INLINE bool is_intersect( const vec2f & _minimum, const vec2f & _maximum, const vec2f & _p );
	LIBMATH_FUNCTION_INLINE bool is_intersect(const box2f & _a, const box2f & _b);
    LIBMATH_FUNCTION_INLINE bool is_intersect(const box2f & _a, const vec2f & _b);
	LIBMATH_FUNCTION_INLINE bool is_intersect(const box2f & _a, const vec2f & _b, float _radius);
	LIBMATH_FUNCTION_INLINE void mul_box2_m4( box2f & _out, const box2f & _a, const mat4f & _b );
	LIBMATH_FUNCTION_INLINE vec2f box_size( const box2f& _box );
}

#	if LIBMATH_FORCE_INLINE == 1
#	include "box2_inline.h"
#	endif
