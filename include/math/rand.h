#pragma once

#include "math/config.h"

namespace mt
{
    MT_FUNCTION_INLINE float randf( float _max )
    {
        float rnf = static_cast<float>(MT_rand()) / (static_cast<float>(RAND_MAX) + 1.0f);
        float rf = _max * rnf;
        return rf;
    }

    /* Равномерное распределение с a != b */
    MT_FUNCTION_INLINE float range_randf( float _a, float _b )
    {
        if( _a > _b )
        {
            return _a;
        }

        float max = (_b - _a);
        float rf = mt::randf( max );

        return _a + rf;
    }

    MT_FUNCTION_INLINE uint32_t rand( uint32_t _max )
    {
        uint64_t r = MT_rand();
        r *= _max;
        r /= (RAND_MAX + 1);

        return r;
    }

    MT_FUNCTION_INLINE uint32_t range_rand( uint32_t _a, uint32_t _b )
    {
        if( _a > _b )
        {
            return _a;
        }

        uint32_t max = (_b - _a);
        uint32_t ri = mt::rand( max );

        return _a + ri;
    }
}
