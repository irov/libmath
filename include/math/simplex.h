#pragma once

#include "math/vec3.h"

#include "math/config.h"

namespace mt
{
    struct simplex_solver
    {
        int size;
        float eps;

        mt::vec3f W[3];
        mt::vec3f P[3];
        mt::vec3f Q[3];

        simplex_solver();

        void reset();
        void addWPQ( const mt::vec3f & w, const mt::vec3f & p, const mt::vec3f & q );
        bool update( mt::vec3f * const _out );

        void remove_1();
        void remove_2();
        bool solve( const mt::vec3f & _ao, const mt::vec3f & _ab, mt::vec3f * const _out );
        bool solve( const mt::vec3f & _ao, const mt::vec3f & _ab, const mt::vec3f & _ac, mt::vec3f * const _out );
    };
};
