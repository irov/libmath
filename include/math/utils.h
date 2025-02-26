#pragma once

#include "math/config.h"
#include "math/constant.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR float abs_f( float _x )
    {
        return (_x >= 0.f) ? _x : -_x;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR float min_f( float _x, float _y )
    {
        return (_x < _y) ? _x : _y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR float max_f( float _x, float _y )
    {
        return (_x > _y) ? _x : _y;
    }
    //////////////////////////////////////////////////////////////////////////    
    MT_CONSTEXPR float ltrim_f( float _value, float _trim )
    {
        return (_value < _trim) ? _trim : _value;
    }
    //////////////////////////////////////////////////////////////////////////
    template<class T>
    MT_CONSTEXPR T ltrim( T _value, T _trim )
    {
        return (_value < _trim) ? _trim : _value;
    }
    //////////////////////////////////////////////////////////////////////////
    template<class T>
    MT_CONSTEXPR T rtrim( T _value, T _trim )
    {
        return (_value > _trim) ? _trim : _value;
    }
    //////////////////////////////////////////////////////////////////////////
    template<class T>
    MT_CONSTEXPR T crop( T _value, T _min, T _max )
    {
        return (_value < _min) ? _min : ((_value > _max) ? _max : _value);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR float clampf( float _leftBound, float _value, float _rightBound )
    {
        return max_f( _leftBound, min_f( _rightBound, _value ) );
    }
    //////////////////////////////////////////////////////////////////////////
    template< typename T >
    MT_CONSTEXPR T clamp( T _leftBound, T _value, T _rightBound )
    {
        return (_value < _leftBound) ? _leftBound : ((_value > _rightBound) ? _rightBound : _value);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR bool equal_f_f_e( float _a, float _b, float _e )
    {
        return (_a >= (_b - _e)) && (_a <= (_b + _e));
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR bool equal_f_f( float _a, float _b )
    {
        return (_a >= (_b + mt::constant::neps)) && (_a <= (_b + mt::constant::eps));
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR bool equal_f_z( float _f )
    {
        return (_f >= mt::constant::neps) && (_f <= mt::constant::eps);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR bool equal_f_1( float _f )
    {
        return (_f >= mt::constant::one_neps) && (_f <= mt::constant::one_eps);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR bool greatequal_f_z( float _f )
    {
        return _f >= mt::constant::one_neps;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR uint32_t fibo32( uint32_t _value )
    {
        uint32_t fibo_numbers[] = {
            0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,
            377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711,
            28657, 46368, 75025, 121393, 196418, 317811, 514229,
            832040, 1346269, 2178309, 3524578, 5702887, 9227465,
            14930352, 24157817, 39088169, 63245986, 102334155,
            165580141, 267914296, 433494437, 701408733,
            1134903170, 1836311903, 2971215073
        };

        MT_assert( _value <= sizeof( fibo_numbers ) / sizeof( fibo_numbers[0] ) );

        uint32_t f = fibo_numbers[_value];

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR uint64_t fibo64( uint64_t _value )
    {
        uint64_t fibo_numbers[] = {
            0ULL, 1ULL, 1ULL, 2ULL, 3ULL, 5ULL, 8ULL, 13ULL, 21ULL, 34ULL, 55ULL, 89ULL, 144ULL, 233ULL,
            377ULL, 610ULL, 987ULL, 1597ULL, 2584ULL, 4181ULL, 6765ULL, 10946ULL, 17711ULL,
            28657ULL, 46368ULL, 75025ULL, 121393ULL, 196418ULL, 317811ULL, 514229ULL,
            832040ULL, 1346269ULL, 2178309ULL, 3524578ULL, 5702887ULL, 9227465ULL,
            14930352ULL, 24157817ULL, 39088169ULL, 63245986ULL, 102334155ULL,
            165580141ULL, 267914296ULL, 433494437ULL, 701408733ULL, 1134903170ULL,
            1836311903ULL, 2971215073ULL, 4807526976ULL, 7778742049ULL,
            12586269025ULL, 20365011074ULL, 32951280099ULL, 53316291173ULL,
            86267571272ULL, 139583862445ULL, 225851433717ULL, 365435296162ULL,
            591286729879ULL, 956722026041ULL, 1548008755920ULL, 2504730781961ULL,
            4052739537881ULL, 6557470319842ULL, 10610209857723ULL, 17167680177565ULL,
            27777890035288ULL, 44945570212853ULL, 72723460248141ULL, 117669030460994ULL,
            190392490709135ULL, 308061521170129ULL, 498454011879264ULL, 806515533049393ULL,
            1304969544928657ULL, 2111485077978050ULL, 3416454622906707ULL, 5527939700884757ULL,
            8944394323791464ULL, 14472334024676221ULL, 23416728348467685ULL, 37889062373143906ULL,
            61305790721611591ULL, 99194853094755497ULL, 160500643816367088ULL, 259695496911122585ULL,
            420196140727489673ULL, 679891637638612258ULL, 1100087778366101931ULL, 1779979416004714189ULL,
            2880067194370816120ULL, 4660046610375530309ULL, 7540113804746346429ULL, 12200160415121876738ULL
        };

        MT_assert( _value <= sizeof( fibo_numbers ) / sizeof( fibo_numbers[0] ) );

        uint64_t f = fibo_numbers[_value];

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR double fibo_bine( double _value )
    {
        const double fplus = (1.0 + 2.2360679774997896964091736687313) * 0.5;
        const double fplusn = MT_pow( fplus, _value );

        const double fminus = (1.0 - 2.2360679774997896964091736687313) * 0.5;
        const double fminusn = MT_pow( fminus, _value );

        double fbine = (fplusn - fminusn) * 0.44721359549995793928183473374626;

        return fbine;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR uint32_t factorial32( uint32_t _value )
    {
        uint32_t factorial_numbers[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

        MT_assert( _value < sizeof( factorial_numbers ) / sizeof( factorial_numbers[0] ) );

        uint32_t f = factorial_numbers[_value];

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR uint64_t factorial64( uint32_t _value )
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
    MT_CONSTEXPR float factorialf( uint32_t _value )
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
    MT_CONSTEXPR uint32_t integral_pow32( uint32_t _value, uint32_t _count )
    {
        if( _count == 0 )
        {
            return 1;
        }

        uint32_t f = _value;

        for( uint32_t i = 1; i != _count; ++i )
        {
            f *= _value;
        }

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR uint64_t integral_pow64( uint64_t _value, uint64_t _count )
    {
        if( _count == 0 )
        {
            return 1;
        }

        uint64_t f = _value;

        for( uint64_t i = 1; i != _count; ++i )
        {
            f *= _value;
        }

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR float integral_powf( float _value, uint32_t _count )
    {
        if( _count == 0 )
        {
            return 1.f;
        }

        float f = _value;

        for( uint32_t i = 1; i != _count; ++i )
        {
            f *= _value;
        }

        return f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR bool is_pow2( uint32_t _n )
    {
        return !(_n & (_n - 1));
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR uint32_t next_pow2( uint32_t _n )
    {
        --_n;
        _n |= _n >> 16;
        _n |= _n >> 8;
        _n |= _n >> 4;
        _n |= _n >> 2;
        _n |= _n >> 1;
        ++_n;

        return _n;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR uint32_t get_np2( uint32_t _n )
    {
        uint32_t p2 = 0;
        while( (_n >>= 1) != 0 )
        {
            ++p2;
        }

        return p2;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR float length_f( float _a, float _b )
    {
        if( _a >= _b )
        {
            return _a - _b;
        }
        else
        {
            return _b - _a;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR float linerp_f1( float _in1, float _in2, float _scale )
    {
        return _in1 + (_in2 - _in1) * _scale;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_CONSTEXPR float cross2_f( float _a, float _b, float _c, float _d )
    {
        return _a * _d - _c * _b;
    }
    //////////////////////////////////////////////////////////////////////////
}