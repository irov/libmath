#pragma once

#include "math/config.h"

#include "math/plane.h"

namespace mt
{
    struct box3f
    {
        mt::vec3f minimum;
        mt::vec3f maximum;

        box3f();
        box3f( const mt::box3f & _box );
        box3f( const mt::vec3f & _min, const mt::vec3f & _max );

        mt::box3f & operator = ( const mt::box3f & _box );
    };

    void reset( mt::box3f * const box, const mt::vec3f & initValue );
    void reset( mt::box3f * const box, float x, float y, float z );
    void add_internal_point( mt::box3f * const box, float x, float y, float z );
    void add_internal_point( mt::box3f * const box, const mt::vec3f & p );
    void set_box_from_min_max( mt::box3f * const box, const mt::vec3f & min, const mt::vec3f & max );
    void set_box_from_center_and_extent( mt::box3f * const box, const mt::vec3f & center, const mt::vec3f & extent );
    void get_box_uvh_vector( const mt::box3f & box, mt::vec3f uvh[3] );
    void get_point_from_box( const mt::box3f & box, mt::vec3f point[8] );
    bool is_intersect( const mt::box3f & _a, const mt::box3f & _b );
}
