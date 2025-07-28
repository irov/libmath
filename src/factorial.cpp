#include "math/factorial.h"
#include "math/stdmath.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    uint32_t factorial32( uint32_t _value )
    {
        uint32_t factorial_numbers[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

        MT_assert( _value < sizeof( factorial_numbers ) / sizeof( factorial_numbers[0] ) );

        uint32_t f = factorial_numbers[_value];

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
    uint64_t factorial64( uint32_t _value )
    {
        uint64_t factorial_numbers[] = {
            1ULL, 1ULL, 2ULL, 6ULL, 24ULL, 120ULL, 720ULL, 5040ULL, 40320ULL, 362880ULL, 3628800ULL,
            39916800ULL, 479001600ULL, 6227020800ULL, 87178291200ULL, 1307674368000ULL,
            20922789888000ULL, 355687428096000ULL, 6402373705728000ULL,
            121645100408832000ULL, 2432902008176640000ULL
        };

        MT_assert( _value < sizeof( factorial_numbers ) / sizeof( factorial_numbers[0] ) );

        uint64_t f = factorial_numbers[_value];

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
    float factorialf( uint32_t _value )
    {
        if( _value == 0 )
        {
            return 1.f;
        }

        float f = 1.f;
        float d = 0.f;

        for( uint32_t i = 0; i != _value; ++i )
        {
            d += 1.f;

            f *= d;
        }

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
}