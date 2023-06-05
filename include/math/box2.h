#pragma once

#include "math/config.h"

#include "math/mat3.h"
#include "math/mat4.h"

namespace mt
{
    struct box2f
    {
        mt::vec2f minimum;
        mt::vec2f maximum;

        MT_METHOD_INLINE box2f();
        MT_METHOD_INLINE box2f( float _minx, float _miny, float _maxx, float _maxy );
        MT_METHOD_INLINE box2f( const mt::box2f & _box );
        MT_METHOD_INLINE box2f( const mt::vec2f & _min, const mt::vec2f & _max );

        MT_METHOD_INLINE box2f & operator = ( const mt::box2f & _box );
    };

    MT_FUNCTION_INLINE void infinity_box( mt::box2f * const box );
    MT_FUNCTION_INLINE bool is_infinity_box( const mt::box2f & box );
    MT_FUNCTION_INLINE void insideout_box( mt::box2f * const box );
    MT_FUNCTION_INLINE void reset( mt::box2f * const box, const mt::vec2f & initValue );
    MT_FUNCTION_INLINE void reset( mt::box2f * const box, float x, float y );
    MT_FUNCTION_INLINE void add_internal_point( mt::box2f * const box, float x, float y );
    MT_FUNCTION_INLINE void add_internal_point( mt::box2f * const box, const mt::vec2f & p );
    MT_FUNCTION_INLINE void merge_box( mt::box2f * const box, const mt::box2f & external_box );
    MT_FUNCTION_INLINE void crop_box( mt::box2f * const box, const mt::box2f & external_box );
    MT_FUNCTION_INLINE void transpose_box( mt::box2f * const _box, const mt::vec2f & _pos );
    MT_FUNCTION_INLINE void scale_box( mt::box2f * const _box, const mt::vec2f & _scale );
    MT_FUNCTION_INLINE void get_center_box( const mt::box2f & _box, mt::vec2f * const _pos );
    MT_FUNCTION_INLINE void set_box_from_min_max( mt::box2f * const box, const mt::vec2f & minimum, const mt::vec2f & maximum );
    MT_FUNCTION_INLINE void set_box_from_two_point( mt::box2f * const box, const mt::vec2f & a, const mt::vec2f & b );
    MT_FUNCTION_INLINE void set_box_from_center_and_extent( mt::box2f * const box, const mt::vec2f & center, const mt::vec2f & extent );
    MT_FUNCTION_INLINE void set_box_from_oriented_extent( mt::box2f * const box, const mt::vec2f & _offset, const mt::vec2f & _size, const mt::mat3f & _wm );
    MT_FUNCTION_INLINE void set_box_homogenize( mt::box2f * const box, const mt::vec2f & _begin, const mt::vec2f & _end, const mt::mat4f & _wm );
    MT_FUNCTION_INLINE bool is_exist( const mt::vec2f & _aminimum, const mt::vec2f & _amaximum, const mt::vec2f & _bminimum, const mt::vec2f & _bmaximum );
    MT_FUNCTION_INLINE bool is_intersect( const mt::vec2f & _aminimum, const mt::vec2f & _amaximum, const mt::vec2f & _bminimum, const mt::vec2f & _bmaximum );
    MT_FUNCTION_INLINE bool is_intersect( const mt::vec2f & _minimum, const mt::vec2f & _maximum, const mt::vec2f & _p );
    MT_FUNCTION_INLINE bool is_intersect( const mt::box2f & _a, const mt::box2f & _b );
    MT_FUNCTION_INLINE bool is_intersect( const mt::box2f & _a, const mt::vec2f & _b );
    MT_FUNCTION_INLINE bool is_intersect( const mt::box2f & _a, const mt::vec2f & _b, float _radius );
    MT_FUNCTION_INLINE bool is_intersect( const mt::box2f & _a, const mt::vec2f & _b, float _radiusx, float _radiusy );
    MT_FUNCTION_INLINE void mul_box2_m4( mt::box2f * const _out, const mt::box2f & _a, const mt::mat4f & _b );
    MT_FUNCTION_INLINE mt::vec2f box_size( const mt::box2f & _box );
}

#if MT_FORCE_INLINE == 1
#include "math/box2.cpp"
#endif
