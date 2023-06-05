#include "math/box3.h"

#if MT_FORCE_INLINE == 0
namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box3f::box3f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box3f::box3f( const mt::box3f & _box )
        : minimum( _box.minimum )
        , maximum( _box.maximum )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box3f::box3f( const mt::vec3f & _min, const mt::vec3f & _max )
        : minimum( _min )
        , maximum( _max )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box3f & box3f::operator = ( const mt::box3f & _box )
    {
        minimum = _box.minimum;
        maximum = _box.maximum;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void reset( mt::box3f * const box, const mt::vec3f & initValue )
    {
        box->maximum = initValue;
        box->minimum = initValue;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void reset( mt::box3f * const box, float x, float y, float z )
    {
        mt::reset( box, mt::vec3f( x, y, z ) );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void add_internal_point( mt::box3f * const box, float x, float y, float z )
    {
        if( x > box->maximum.x ) box->maximum.x = x;
        if( y > box->maximum.y ) box->maximum.y = y;
        if( z > box->maximum.z ) box->maximum.z = z;
        if( x < box->minimum.x ) box->minimum.x = x;
        if( y < box->minimum.y ) box->minimum.y = y;
        if( z < box->minimum.z ) box->minimum.z = z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void add_internal_point( mt::box3f * const box, const mt::vec3f & p )
    {
        mt::add_internal_point( box, p.x, p.y, p.z );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_box_from_min_max( mt::box3f * const box, const mt::vec3f & min, const mt::vec3f & max )
    {
        box->minimum = min;
        box->maximum = max;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_box_from_center_and_extent( mt::box3f * const box, const mt::vec3f & center, const mt::vec3f & extent )
    {
        box->minimum = center - extent;
        box->maximum = center + extent;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void get_box_uvh_vector( const mt::box3f & box, mt::vec3f uvh[3] )
    {
        mt::vec3f vDir = box.maximum - box.minimum;
        uvh[0] = mt::vec3f( vDir.x, 0, 0 );
        uvh[1] = mt::vec3f( 0, vDir.y, 0 );
        uvh[2] = mt::vec3f( 0, 0, vDir.z );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void get_point_from_box( const mt::box3f & box, mt::vec3f point[8] )
    {
        mt::vec3f uvh[3];
        mt::get_box_uvh_vector( box, uvh );

        point[0] = box.minimum;
        point[1] = box.minimum + uvh[0];
        point[2] = box.minimum + uvh[0] + uvh[1];
        point[3] = box.minimum + uvh[1];
        point[4] = box.minimum + uvh[2];
        point[5] = box.minimum + uvh[0] + uvh[2];
        point[6] = box.minimum + uvh[0] + uvh[1] + uvh[2];
        point[7] = box.minimum + uvh[1] + uvh[2];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool is_intersect( const mt::box3f & _a, const mt::box3f & _b )
    {
        return (_a.maximum.y > _b.minimum.y && _a.minimum.y < _b.maximum.y &&
            _a.maximum.x > _b.minimum.x && _a.minimum.x < _b.maximum.x &&
            _a.maximum.z > _b.minimum.z && _a.minimum.z < _b.maximum.z);
    }
    //////////////////////////////////////////////////////////////////////////
}
#endif
