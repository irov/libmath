#include "math/polygon2.h"
    
#include "math/segment2.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    void polygon2_centroid( const mt::vec2f * _polygon, size_t _count, mt::vec2f * const _point )
    {
        if( _count == 0 )
        {
            *_point = mt::vec2f( 0.f, 0.f );

            return;
        }

        mt::vec2f centroid_point( 0.f, 0.f );
        float centroid_area = 0.f;

        for( size_t i = 0; i != _count - 1; ++i )
        {
            float x0 = _polygon[i + 0].x;
            float y0 = _polygon[i + 0].y;
            float x1 = _polygon[i + 1].x;
            float y1 = _polygon[i + 1].y;

            float a = x0 * y1 - x1 * y0;

            centroid_area += a;

            centroid_point.x += (x0 + x1) * a;
            centroid_point.y += (y0 + y1) * a;
        }

        {
            float x0 = _polygon[_count - 1].x;
            float y0 = _polygon[_count - 1].y;
            float x1 = _polygon[0].x;
            float y1 = _polygon[0].y;

            float a = x0 * y1 - x1 * y0;

            centroid_area += a;

            centroid_point.x += (x0 + x1) * a;
            centroid_point.y += (y0 + y1) * a;
        }

        centroid_area *= 0.5f;

        float centroid_area_inv6 = 6.f / centroid_area;

        centroid_point.x *= centroid_area_inv6;
        centroid_point.y *= centroid_area_inv6;

        *_point = centroid_point;
    }
    //////////////////////////////////////////////////////////////////////////
    static float __polygon2_is_left( const mt::vec2f & _v0, const mt::vec2f & _v1, const mt::vec2f & _point )
    {
        return (_v1.x - _v0.x) * (_point.y - _v0.y) - (_point.x - _v0.x) * (_v1.y - _v0.y);
    }
    //////////////////////////////////////////////////////////////////////////
    bool polygon2_intersect( const mt::vec2f * _polygon, size_t _count, const mt::vec2f & _point )
    {
        int32_t wn = 0;

        for( size_t i = 0; i != _count; ++i )
        {
            size_t next_i = (i + 1) % _count;

            const mt::vec2f & v0 = _polygon[i];
            const mt::vec2f & v1 = _polygon[next_i];

            if( v0.y <= _point.y )
            {
                if( v1.y > _point.y )
                {
                    if( __polygon2_is_left( v0, v1, _point ) > 0.f )
                    {
                        ++wn;
                    }
                }
            }
            else
            {
                if( v1.y <= _point.y )
                {
                    if( __polygon2_is_left( v0, v1, _point ) < 0.f )
                    {
                        --wn;
                    }
                }
            }
        }

        if( wn == 0 )
        {
            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    bool polygon2_intersect( const mt::vec2f * _polygon, size_t _count, const mt::vec2f & _point, float _rx, float _ry )
    {
        if( polygon2_intersect( _polygon, _count, _point ) == true )
        {
            return true;
        }

        float rxxinv = 1.f / (_rx * _rx);
        float ryyinv = 1.f / (_ry * _ry);

        for( size_t index = 0; index != _count; ++index )
        {
            size_t next_index = (index + 1) % _count;

            const mt::vec2f & v0 = _polygon[index];
            const mt::vec2f & v1 = _polygon[next_index];

            mt::vec2f projection;
            mt::segment2_projection_v2( mt::segment2( v0, v1 ), _point, &projection );

            mt::vec2f dp = _point - projection;

            float d = (dp.x * dp.x) * rxxinv + (dp.y * dp.y) * ryyinv;

            if( d <= 1.f )
            {
                return true;
            }
        }

        return false;
    }
    //////////////////////////////////////////////////////////////////////////
    bool polygon2_intersect( const mt::vec2f * _polygon1, size_t _count1, const mt::vec2f * _polygon2, size_t _count2 )
    {
        if( _count1 == 0 || _count2 == 0 )
        {
            return false;
        }

        const mt::vec2f & p10 = _polygon1[0];

        if( mt::polygon2_intersect( _polygon2, _count2, p10 ) == true )
        {
            return true;
        }

        const mt::vec2f & p20 = _polygon2[0];

        if( mt::polygon2_intersect( _polygon1, _count1, p20 ) == true )
        {
            return true;
        }

        for( size_t i = 0; i != _count1; ++i )
        {
            size_t next_i = (i + 1) % _count1;

            const mt::vec2f & p1 = _polygon1[i];
            const mt::vec2f & p2 = _polygon1[next_i];

            for( size_t j = 0; j != _count2; ++j )
            {
                size_t next_j = (j + 1) % _count2;

                const mt::vec2f & p3 = _polygon2[j];
                const mt::vec2f & p4 = _polygon2[next_j];

                if( mt::segment2_intersect( p1, p2, p3, p4 ) == true )
                {
                    return true;
                }
            }
        }

        return false;
    }
    //////////////////////////////////////////////////////////////////////////
}