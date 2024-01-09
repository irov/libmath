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
    MT_CONSTEXPR uint32_t factorial( uint32_t _value )
    {
        if( _value == 0 )
        {
            return 1;
        }

        uint32_t f = 1;
        uint32_t d = 0;

        for( uint32_t i = 0; i != _value; ++i )
        {
            ++d;

            f *= d;
        }

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
    MT_CONSTEXPR uint32_t integer_pow( uint32_t _value, uint32_t _count )
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
}