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

        box2f();
        box2f( float _minx, float _miny, float _maxx, float _maxy );
        box2f( const mt::box2f & _box );
        box2f( const mt::vec2f & _min, const mt::vec2f & _max );

        box2f & operator = ( const mt::box2f & _box );
    };

    void box2_infinity( mt::box2f * const box );
    bool box2_is_infinity( const mt::box2f & box );
    void box2_insideout( mt::box2f * const box );
    void box2_reset( mt::box2f * const box, const mt::vec2f & initValue );
    void box2_reset( mt::box2f * const box, float x, float y );
    void box2_add_internal_point( mt::box2f * const box, float x, float y );
    void box2_add_internal_point( mt::box2f * const box, const mt::vec2f & p );
    void box2_merge( mt::box2f * const box, const mt::box2f & external_box );
    void box2_crop( mt::box2f * const box, const mt::box2f & external_box );
    void box2_transpose( mt::box2f * const _box, const mt::vec2f & _pos );
    void box2_scale( mt::box2f * const _box, const mt::vec2f & _scale );
    void box2_get_center( const mt::box2f & _box, mt::vec2f * const _pos );
    void box2_set_from_min_max( mt::box2f * const box, const mt::vec2f & minimum, const mt::vec2f & maximum );
    void box2_set_from_two_point( mt::box2f * const box, const mt::vec2f & a, const mt::vec2f & b );
    void box2_set_from_center_and_extent( mt::box2f * const box, const mt::vec2f & center, const mt::vec2f & extent );
    void box2_set_from_oriented_extent( mt::box2f * const box, const mt::vec2f & _offset, const mt::vec2f & _size, const mt::mat3f & _wm );
    void box2_homogenize( mt::box2f * const box, const mt::vec2f & _begin, const mt::vec2f & _end, const mt::mat4f & _wm );
    bool box2_exist( const mt::vec2f & _aminimum, const mt::vec2f & _amaximum, const mt::vec2f & _bminimum, const mt::vec2f & _bmaximum );
    bool box2_intersect( const mt::vec2f & _aminimum, const mt::vec2f & _amaximum, const mt::vec2f & _bminimum, const mt::vec2f & _bmaximum );
    bool box2_intersect( const mt::vec2f & _minimum, const mt::vec2f & _maximum, const mt::vec2f & _p );
    bool box2_intersect( const mt::box2f & _a, const mt::box2f & _b );
    bool box2_intersect( const mt::box2f & _a, const mt::vec2f & _b );
    bool box2_intersect( const mt::box2f & _a, const mt::vec2f & _b, float _radius );
    bool box2_intersect( const mt::box2f & _a, const mt::vec2f & _b, float _radiusx, float _radiusy );
    void box2_mul_m4( mt::box2f * const _out, const mt::box2f & _a, const mt::mat4f & _b );
    mt::vec2f box2_size( const mt::box2f & _box );
}
