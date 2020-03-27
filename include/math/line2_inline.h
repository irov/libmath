#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void line_from_two_point_v2( mt::line2f & _line, const mt::vec2f & _a, const mt::vec2f & _b )
    {
        float a = _b.y - _a.y;
        float b = _a.x - _b.x;

        _line.a = a;
        _line.b = b;
        _line.c = a * _a.x + b * _a.y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float line_dot_point_v2( mt::line2f & _line, const mt::vec2f & _a )
    {
        return _line.a * _a.x + _line.b * _a.y + _line.c;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool line_intersect_v2( const mt::line2f & _l1, const mt::line2f & _l2, mt::vec2f & _p )
    {
        float zn = cross2_f( _l1.a, _l1.b, _l2.a, _l2.b );

        if( mt::equal_f_z( zn ) == true )
        {
            return false;
        }

        float inv_zn = 1.f / zn;

        _p.x = cross2_f( _l1.c, _l1.b, _l2.c, _l2.b ) * inv_zn;
        _p.y = cross2_f( _l1.a, _l1.c, _l2.a, _l2.c ) * inv_zn;

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void line_intersect_v2_np( const mt::line2f & _l1, const mt::line2f & _l2, mt::vec2f & _p )
    {
        float zn = cross2_f( _l1.a, _l1.b, _l2.a, _l2.b );

        float inv_zn = 1.f / zn;

        _p.x = -cross2_f( _l1.c, _l1.b, _l2.c, _l2.b ) * inv_zn;
        _p.y = -cross2_f( _l1.a, _l1.c, _l2.a, _l2.c ) * inv_zn;
    }
}
