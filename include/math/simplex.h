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

        MT_METHOD_INLINE simplex_solver();

        MT_METHOD_INLINE void reset();
        MT_METHOD_INLINE void addWPQ( const mt::vec3f & w, const mt::vec3f & p, const mt::vec3f & q );
        MT_METHOD_INLINE bool update( mt::vec3f * const _out );

        MT_METHOD_INLINE void remove_1();
        MT_METHOD_INLINE void remove_2();
        MT_METHOD_INLINE bool solve( const mt::vec3f & _ao, const mt::vec3f & _ab, mt::vec3f * const _out );
        MT_METHOD_INLINE bool solve( const mt::vec3f & _ao, const mt::vec3f & _ab, const mt::vec3f & _ac, mt::vec3f * const _out );
    };
};

#if MT_FORCE_INLINE == 1
#include "math/simplex.cpp"
#endif
