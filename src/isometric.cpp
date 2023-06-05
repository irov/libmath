#include "math/isometric.h"

#if MT_FORCE_INLINE == 0
namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE isometric::isometric( float _w, float _h )
        : w( _w )
        , h( _h )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void isometric::screen2iso( float _sx, float _sy, float * const _ix, float * const _iy ) const
    {
        float w_inv = 1.f / w;
        float h_inv = 1.f / h;

        *_ix = _sx * w_inv + _sy * h_inv;
        *_iy = _sy * h_inv - _sx * w_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void isometric::iso2screen( float _ix, float _iy, float * const _sx, float * const _sy ) const
    {
        float hw = w * 0.5f;
        float hh = h * 0.5f;

        *_sx = _ix * hw - _iy * hw;
        *_sy = _ix * hh + _iy * hh;
    }
    //////////////////////////////////////////////////////////////////////////
}
#endif

