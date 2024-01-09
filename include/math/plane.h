#pragma once

#include "math/config.h"

#include "math/vec3.h"
#include "math/mat4.h"

namespace mt
{
    class planef
    {
    public:
        float a;
        float b;
        float c;
        float d;

        planef();
        planef( const mt::planef & _plane );
        planef( const mt::vec3f & _norm, float _dist );
        planef( float _a, float _b, float _c, float _d );

        mt::planef & operator = ( const mt::planef & _plane );

        float * buff();
        const float * buff() const;
    };

    void get_plane_normal( mt::vec3f * const _out, const mt::planef & _plane );
    void get_plane_point( mt::vec3f * const _out, const mt::planef & _plane );
    void set_plane_by_triangle( mt::planef * const _plane, const mt::vec3f & _v0, const mt::vec3f & _v1, const mt::vec3f & _v2 );
    void set_plane_by_point_and_normal( mt::planef * const _plane, const mt::vec3f & _point, const mt::vec3f & _normal );
    bool projection_to_plane( mt::vec3f * const _out, const mt::vec3f & _eye, const mt::vec3f & _dir, const mt::planef & _plane );
    void reflect_plane( mt::vec3f * const _out, const mt::vec3f & _dir, const mt::planef & _plane );
    void mul_plane_mat4( mt::planef * const _out, const mt::planef & _plane, const mt::mat4f & _wm );
}
