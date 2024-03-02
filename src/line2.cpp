#include "math/line2.h"

#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    void line2_from_two_point_v2( mt::line2f * const _line, const mt::vec2f & _a, const mt::vec2f & _b )
    {
        float a = _b.y - _a.y;
        float b = _a.x - _b.x;

        _line->a = a;
        _line->b = b;
        _line->c = a * _a.x + b * _a.y;
    }
    //////////////////////////////////////////////////////////////////////////
    float line2_dot_point_v2( const mt::line2f & _line, const mt::vec2f & _a )
    {
        float dot = _line.a * _a.x + _line.b * _a.y + _line.c;

        return dot;
    }
    //////////////////////////////////////////////////////////////////////////
    bool line2_intersect( const mt::line2f & _l1, const mt::line2f & _l2 )
    {
        float zn = mt::cross2_f( _l1.a, _l1.b, _l2.a, _l2.b );

        bool intersect = mt::equal_f_z( zn );

        return intersect;
    }
    //////////////////////////////////////////////////////////////////////////
    bool line2_intersect_point( const mt::line2f & _l1, const mt::line2f & _l2, mt::vec2f * const _p )
    {
        float zn = mt::cross2_f( _l1.a, _l1.b, _l2.a, _l2.b );

        if( mt::equal_f_z( zn ) == true )
        {
            return false;
        }

        float inv_zn = 1.f / zn;

        _p->x = mt::cross2_f( _l1.c, _l1.b, _l2.c, _l2.b ) * inv_zn;
        _p->y = mt::cross2_f( _l1.a, _l1.c, _l2.a, _l2.c ) * inv_zn;

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    void line2_intersect_v2_np( const mt::line2f & _l1, const mt::line2f & _l2, mt::vec2f * const _p )
    {
        float zn = mt::cross2_f( _l1.a, _l1.b, _l2.a, _l2.b );

        float inv_zn = 1.f / zn;

        _p->x = mt::cross2_f( _l1.c, _l1.b, _l2.c, _l2.b ) * inv_zn;
        _p->y = mt::cross2_f( _l1.a, _l1.c, _l2.a, _l2.c ) * inv_zn;
    }
    //////////////////////////////////////////////////////////////////////////
}