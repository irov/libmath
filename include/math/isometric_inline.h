namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE isometric::isometric( float w, float h )
        : w( w )
        , h( h )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void isometric::screen2iso( float sx, float sy, float & ix, float & iy ) const
    {
        ix = sx / w + sy / h;
        iy = sy / h - sx / w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void isometric::iso2screen( float ix, float iy, float & sx, float & sy ) const
    {
        float hw = w * 0.5f;
        float hh = h * 0.5f;

        sx = ix * hw - iy * hw;
        sy = ix * hh + iy * hh;
    }
}