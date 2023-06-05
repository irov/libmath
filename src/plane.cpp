#include "math/plane.h"

#if MT_FORCE_INLINE == 0
#include "math/utils.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE planef::planef()
        :a( 1.f )
        , b( 0.f )
        , c( 0.f )
        , d( 0.f )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE planef::planef( const mt::planef & _plane )
        :a( _plane.a )
        , b( _plane.b )
        , c( _plane.c )
        , d( _plane.d )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE planef::planef( const mt::vec3f & _norm, float _dist )
        :a( _norm.x )
        , b( _norm.y )
        , c( _norm.z )
        , d( _dist )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE planef::planef( float _a, float _b, float _c, float _d )
        : a( _a )
        , b( _b )
        , c( _c )
        , d( _d )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE mt::planef & planef::operator = ( const mt::planef & _plane )
    {
        a = _plane.a;
        b = _plane.b;
        c = _plane.c;
        d = _plane.d;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float * planef::buff()
    {
        return &a;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE const float * planef::buff() const
    {
        return &a;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void get_plane_normal( mt::vec3f * const _out, const mt::planef & _plane )
    {
        _out->x = _plane.a;
        _out->y = _plane.b;
        _out->z = _plane.c;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void get_plane_point( mt::vec3f * const _out, const mt::planef & _plane )
    {
        _out->x = -_plane.a * _plane.d;
        _out->y = -_plane.b * _plane.d;
        _out->z = -_plane.c * _plane.d;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_plane_by_triangle( planef * const _plane, const mt::vec3f & _v0, const mt::vec3f & _v1, const mt::vec3f & _v2 )
    {
        mt::vec3f edge0 = _v1 - _v0;
        mt::vec3f edge1 = _v2 - _v0;

        mt::vec3f norm;
        mt::cross_v3_v3_norm( &norm, edge0, edge1 );

        mt::set_plane_by_point_and_normal( _plane, _v0, norm );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_plane_by_point_and_normal( planef * const _plane, const mt::vec3f & _point, const mt::vec3f & _normal )
    {
        _plane->a = _normal.x;
        _plane->b = _normal.y;
        _plane->c = _normal.z;
        _plane->d = -mt::dot_v3_v3( _point, _normal );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool projection_to_plane( mt::vec3f * const _out, const mt::vec3f & _eye, const mt::vec3f & _dir, const mt::planef & _plane )
    {
        mt::vec3f norm( _plane.a, _plane.b, _plane.c );

        float dot_norm_eye = mt::dot_v3_v3( norm, _eye );

        if( mt::equal_f_z( dot_norm_eye ) == true )
        {
            return false;
        }

        *_out = _dir * (dot_norm_eye - _plane.d) / mt::dot_v3_v3( norm, _dir ) + _eye;

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void reflect_plane( mt::vec3f * const _out, const mt::vec3f & _dir, const mt::planef & _plane )
    {
        mt::vec3f norm( _plane.a, _plane.b, _plane.c );

        mt::reflect_v3_v3( _out, norm, _dir );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_plane_mat4( planef * const _out, const mt::planef & _plane, const mt::mat4f & _wm )
    {
        mt::vec3f dir;
        mt::get_plane_normal( &dir, _plane );

        mt::vec3f pos;
        mt::get_plane_point( &pos, _plane );

        mt::vec3f at = pos + dir;

        mt::vec3f pos_wm;
        mt::mul_v3_v3_m4( &pos_wm, pos, _wm );

        mt::vec3f at_wm;
        mt::mul_v3_v3_m4( &at_wm, at, _wm );

        mt::vec3f dir_wm;
        mt::dir_v3_v3( &dir_wm, pos_wm, at_wm );

        mt::set_plane_by_point_and_normal( _out, pos_wm, dir_wm );
    }
    //////////////////////////////////////////////////////////////////////////
}
#endif
