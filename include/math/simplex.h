#pragma once

#include "math/vec3.h"

#include "math/config.h"

namespace mt
{
    class simplex_solver
    {
    public:
        MT_METHOD_INLINE simplex_solver();

    public:
        MT_METHOD_INLINE void reset();
        MT_METHOD_INLINE void addWPQ( const mt::vec3f & w, const mt::vec3f & p, const mt::vec3f & q );
        MT_METHOD_INLINE bool update( mt::vec3f & V );

    private:
        MT_METHOD_INLINE void remove_1();
        MT_METHOD_INLINE void remove_2();
        MT_METHOD_INLINE bool solve( mt::vec3f AO, mt::vec3f AB, mt::vec3f & V );
        MT_METHOD_INLINE bool solve( mt::vec3f AO, mt::vec3f AB, mt::vec3f AC, mt::vec3f & V );

    private:
        int size;
        float eps;

        mt::vec3f W[3];
        mt::vec3f P[3];
        mt::vec3f Q[3];
    };
};

#if MT_FORCE_INLINE == 1
#include "math/simplex_inline.h"
#endif
