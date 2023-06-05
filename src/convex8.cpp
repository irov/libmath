#include "math/convex8.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    convex8::convex8()
        : count( 0 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec2f & convex8::operator [] ( size_t i ) const
    {
        return this->point[i];
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f & convex8::operator [] ( size_t i )
    {
        return this->point[i];
    }
    //////////////////////////////////////////////////////////////////////////
    void convex8::add( const mt::vec2f & v )
    {
        this->point[this->count++] = v;
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec2f & convex8::front() const
    {
        return this->point[0];
    }
    //////////////////////////////////////////////////////////////////////////
    const mt::vec2f & convex8::back() const
    {
        return this->point[this->count - 1];
    }
    //////////////////////////////////////////////////////////////////////////
    uint32_t convex8::size() const
    {
        return this->count;
    }
    //////////////////////////////////////////////////////////////////////////
    bool convex8::empty() const
    {
        return this->count == 0U;
    }
    //////////////////////////////////////////////////////////////////////////
    void convex8::clear()
    {
        this->count = 0U;
    }
    //////////////////////////////////////////////////////////////////////////
    int32_t convex8_line_sect( const mt::vec2f & x0, const mt::vec2f & x1, const mt::vec2f & y0, const mt::vec2f & y1, mt::vec2f & res )
    {
        vec2f dx = x1 - x0;
        vec2f dy = y1 - y0;
        vec2f d = x0 - y0;

        float dyx = mt::cross_v2( dy, dx );

        if( mt::equal_f_z( dyx ) == true )
        {
            return 0;
        }

        float dyx2 = mt::cross_v2( d, dx ) / dyx;

        if( dyx2 <= 0.f || dyx2 >= 1.f )
        {
            return 0;
        }

        res.x = y0.x + dyx2 * dy.x;
        res.y = y0.y + dyx2 * dy.y;

        return 1;
    }
    //////////////////////////////////////////////////////////////////////////
    int convex8_left_of( const mt::vec2f & a, const mt::vec2f & b, const mt::vec2f & c )
    {
        mt::vec2f tmp1 = b - a;
        mt::vec2f tmp2 = c - b;
        float x = mt::cross_v2( tmp1, tmp2 );

        int winding = x < 0.f ? -1 : (x > 0 ? 1 : 0);

        return winding;
    }
    //////////////////////////////////////////////////////////////////////////
    void convex8_poly_edge_clip( const mt::convex8 & sub, const mt::vec2f & x0, const mt::vec2f & x1, int left, mt::convex8 & res )
    {
        res.clear();

        const mt::vec2f * v0 = &sub.back();

        int side0 = mt::convex8_left_of( x0, x1, *v0 );

        if( side0 != -left )
        {
            res.add( *v0 );
        }

        uint32_t sub_count = sub.size();

        for( uint32_t i = 0; i != sub_count; ++i )
        {
            const mt::vec2f & v1 = sub[i];

            int side1 = mt::convex8_left_of( x0, x1, v1 );

            if( side0 + side1 == 0 && side0 != 0 )
            {
                mt::vec2f tmp;
                if( mt::convex8_line_sect( x0, x1, *v0, v1, tmp ) != 0 )
                {
                    res.add( tmp );
                }
            }

            if( i == sub_count - 1 )
            {
                break;
            }

            if( side1 != -left )
            {
                res.add( v1 );
            }

            v0 = &v1;
            side0 = side1;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    int convex8_poly_winding( const mt::convex8 & c )
    {
        const mt::vec2f & v0 = c[0];
        const mt::vec2f & v1 = c[1];
        const mt::vec2f & v2 = c[2];

        int winding = mt::convex8_left_of( v0, v1, v2 );

        return winding;
    }
    //////////////////////////////////////////////////////////////////////////
    void convex8_intersect( const mt::convex8 & _convex, const mt::convex8 & _clip, mt::convex8 & _result )
    {
        mt::convex8 P1, P2;
        mt::convex8 * p1 = &P1;
        mt::convex8 * p2 = &P2;
        mt::convex8 * tmp;

        uint32_t cc = _clip.size();

        int dir = mt::convex8_poly_winding( _clip );

        const mt::vec2f & clip_back = _clip.back();
        const mt::vec2f & clip_front = _clip.front();

        mt::convex8_poly_edge_clip( _convex, clip_back, clip_front, dir, *p2 );

        for( uint32_t i = 0; i != cc - 1; ++i )
        {
            tmp = p2;
            p2 = p1;
            p1 = tmp;

            if( p1->empty() == true )
            {
                p2->clear();
                break;
            }

            const mt::vec2f & clipi0 = _clip[i + 0];
            const mt::vec2f & clipi1 = _clip[i + 1];

            mt::convex8_poly_edge_clip( *p1, clipi0, clipi1, dir, *p2 );
        }

        uint32_t p2s = p2->size();

        for( uint32_t i = 0; i != p2s; ++i )
        {
            const mt::vec2f & v = (*p2)[i];

            _result.add( v );
        }
    }
    //////////////////////////////////////////////////////////////////////////
    float convex8_area( const mt::convex8 & _convex )
    {
        float double_area = 0.f;

        uint32_t n = _convex.size();

        uint32_t j = n - 1;
        for( uint32_t i = 0; i < n; i++ )
        {
            const mt::vec2f & vi = _convex[i];
            const mt::vec2f & vj = _convex[j];

            float local_area = (vj.x + vi.x) * (vj.y - vi.y);
            double_area += local_area;
            j = i;
        }

        float area = mt::abs_f( double_area * 0.5f );

        return area;
    }
    //////////////////////////////////////////////////////////////////////////
}