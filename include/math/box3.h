#pragma once

#include "math/config.h"

#include "math/plane.h"

namespace mt
{
    struct box3f
    {
        vec3f minimum;
        vec3f maximum;

        MT_METHOD_INLINE box3f();
        MT_METHOD_INLINE box3f( const box3f & _box );
        MT_METHOD_INLINE box3f( const vec3f &_min, const vec3f &_max );

        MT_METHOD_INLINE box3f & operator = ( const box3f & _box );
    };

    MT_FUNCTION_INLINE void reset( box3f & box, const vec3f & initValue );
    MT_FUNCTION_INLINE void reset( box3f & box, float x, float y, float z );
    MT_FUNCTION_INLINE void add_internal_point( box3f & box, float x, float y, float z );
    MT_FUNCTION_INLINE void add_internal_point( box3f & box, const vec3f & p );
    MT_FUNCTION_INLINE void set_box_from_min_max( box3f & box, const vec3f & min, const vec3f & max );
    MT_FUNCTION_INLINE void set_box_from_center_and_extent( box3f & box, const vec3f & center, const vec3f & extent );
    MT_FUNCTION_INLINE void get_point_from_box( vec3f point[8], const box3f & box );
    MT_FUNCTION_INLINE bool is_intersect( const box3f & _a, const box3f & _b );
}

#if MT_FORCE_INLINE == 1
#include "math/box3_inline.h"
#endif
