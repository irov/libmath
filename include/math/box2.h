#pragma once

#include "math/config.h"

#include "math/mat3.h"
#include "math/mat4.h"

namespace mt
{
    struct box2f
    {
        vec2f minimum;
        vec2f maximum;

        MT_METHOD_INLINE box2f();
        MT_METHOD_INLINE box2f( float _minx, float _miny, float _maxx, float _maxy );
        MT_METHOD_INLINE box2f( const box2f & _box );
        MT_METHOD_INLINE box2f( const vec2f & _min, const vec2f & _max );

        MT_METHOD_INLINE box2f & operator = ( const box2f & _box );
    };

    MT_FUNCTION_INLINE void infinity_box( box2f & box );
    MT_FUNCTION_INLINE void insideout_box( box2f & box );
    MT_FUNCTION_INLINE void reset( box2f & box, const vec2f & initValue );
    MT_FUNCTION_INLINE void reset( box2f & box, float x, float y );
    MT_FUNCTION_INLINE void add_internal_point( box2f & box, float x, float y );
    MT_FUNCTION_INLINE void add_internal_point( box2f & box, const vec2f & p );
    MT_FUNCTION_INLINE void merge_box( box2f & box, const box2f & external_box );
    MT_FUNCTION_INLINE void crop_box( box2f & box, const box2f & external_box );
    MT_FUNCTION_INLINE void transpose_box( box2f & _box, const mt::vec2f & _pos );
    MT_FUNCTION_INLINE void scale_box( box2f & _box, const mt::vec2f & _scale );
    MT_FUNCTION_INLINE void get_center_box( const box2f & _box, mt::vec2f & _pos );
    MT_FUNCTION_INLINE void set_box_from_min_max( box2f & box, const vec2f & minimum, const vec2f & maximum );
    MT_FUNCTION_INLINE void set_box_from_two_point( box2f & box, const vec2f & a, const vec2f & b );
    MT_FUNCTION_INLINE void set_box_from_center_and_extent( box2f & box, const vec2f & center, const vec2f & extent );
    MT_FUNCTION_INLINE void set_box_from_oriented_extent( box2f & box, const mt::vec2f & _offset, const mt::vec2f & _size, const mt::mat3f & _wm );
    MT_FUNCTION_INLINE void set_box_homogenize( box2f & box, const mt::vec2f & _begin, const mt::vec2f & _end, const mt::mat4f & _wm );
    MT_FUNCTION_INLINE bool is_exist( const vec2f & _aminimum, const vec2f & _amaximum, const vec2f & _bminimum, const vec2f & _bmaximum );
    MT_FUNCTION_INLINE bool is_intersect( const vec2f & _aminimum, const vec2f & _amaximum, const vec2f & _bminimum, const vec2f & _bmaximum );
    MT_FUNCTION_INLINE bool is_intersect( const vec2f & _minimum, const vec2f & _maximum, const vec2f & _p );
    MT_FUNCTION_INLINE bool is_intersect( const box2f & _a, const box2f & _b );
    MT_FUNCTION_INLINE bool is_intersect( const box2f & _a, const vec2f & _b );
    MT_FUNCTION_INLINE bool is_intersect( const box2f & _a, const vec2f & _b, float _radius );
    MT_FUNCTION_INLINE bool is_intersect( const box2f & _a, const vec2f & _b, float _radiusx, float _radiusy );
    MT_FUNCTION_INLINE void mul_box2_m4( box2f & _out, const box2f & _a, const mat4f & _b );
    MT_FUNCTION_INLINE vec2f box_size( const box2f& _box );
}

#if MT_FORCE_INLINE == 1
#include "math/box2_inline.h"
#endif
