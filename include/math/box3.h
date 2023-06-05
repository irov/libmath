#pragma once

#include "math/config.h"

#include "math/plane.h"

namespace mt
{
    struct box3f
    {
        mt::vec3f minimum;
        mt::vec3f maximum;

        MT_METHOD_INLINE box3f();
        MT_METHOD_INLINE box3f( const mt::box3f & _box );
        MT_METHOD_INLINE box3f( const mt::vec3f & _min, const mt::vec3f & _max );

        MT_METHOD_INLINE mt::box3f & operator = ( const mt::box3f & _box );
    };

    MT_FUNCTION_INLINE void reset( mt::box3f * const box, const mt::vec3f & initValue );
    MT_FUNCTION_INLINE void reset( mt::box3f * const box, float x, float y, float z );
    MT_FUNCTION_INLINE void add_internal_point( mt::box3f * const box, float x, float y, float z );
    MT_FUNCTION_INLINE void add_internal_point( mt::box3f * const box, const mt::vec3f & p );
    MT_FUNCTION_INLINE void set_box_from_min_max( mt::box3f * const box, const mt::vec3f & min, const mt::vec3f & max );
    MT_FUNCTION_INLINE void set_box_from_center_and_extent( mt::box3f * const box, const mt::vec3f & center, const mt::vec3f & extent );
    MT_FUNCTION_INLINE void get_box_uvh_vector( const mt::box3f & box, mt::vec3f uvh[3] );
    MT_FUNCTION_INLINE void get_point_from_box( const mt::box3f & box, mt::vec3f point[8] );
    MT_FUNCTION_INLINE bool is_intersect( const mt::box3f & _a, const mt::box3f & _b );
}

#if MT_FORCE_INLINE == 1
#include "math/box3.cpp"
#endif
