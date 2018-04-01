#pragma once

#include "math/config.h"
#include "math/constant.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE float abs_f( float _x )
    {
        return (_x >= 0.f) ? _x : -_x;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE float min_f( float _x, float _y )
    {
        return (_x < _y) ? _x : _y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE float max_f( float _x, float _y )
    {
        return (_x > _y) ? _x : _y;
    }
    //////////////////////////////////////////////////////////////////////////    
    MT_INLINE float ltrim_f( float _value, float _trim )
    {
        if( _value < _trim )
        {
            return _trim;
        }

        return _value;
    }

    //////////////////////////////////////////////////////////////////////////
    template<class T>
    MT_INLINE T ltrim( T _value, T _trim )
    {
        if( _value < _trim )
        {
            return _trim;
        }

        return _value;
    }
    //////////////////////////////////////////////////////////////////////////
    template<class T>
    MT_INLINE T rtrim( T _value, T _trim )
    {
        if( _value > _trim )
        {
            return _trim;
        }

        return _value;
    }
    //////////////////////////////////////////////////////////////////////////
    template<class T>
    MT_INLINE T crop( T _value, T _min, T _max )
    {
        if( _value < _min )
        {
            return _min;
        }

        if( _value > _max )
        {
            return _max;
        }

        return _value;
    }
    //////////////////////////////////////////////////////////////////////////
    template< typename T >
    MT_INLINE T clamp( const T & _leftBound, const T & _value, const T & _rightBound )
    {
        T clampedValue = _value;

        if( _value < _leftBound )
        {
            clampedValue = _leftBound;
        }
        else if( _value > _rightBound )
        {
            clampedValue = _rightBound;
        }

        return clampedValue;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE bool equal_f_f_e( float _a, float _b, float _e )
    {
        return (_a >= (_b - _e)) && (_a <= (_b + _e));
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE bool equal_f_f( float _a, float _b )
    {
        return (_a >= (_b + mt::constant::neps)) && (_a <= (_b + mt::constant::eps));
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE bool equal_f_z( float _f )
    {
        return (_f >= mt::constant::neps) && (_f <= mt::constant::eps);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE bool equal_f_1( float _f )
    {
        return (_f >= mt::constant::one_eps) && (_f <= mt::constant::one_neps);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE bool greatequal_f_z( float _f )
    {
        return _f >= mt::constant::one_neps;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE uint32_t factorial( uint32_t _value )
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
    MT_INLINE float factorialf( uint32_t _value )
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
    MT_INLINE float integral_powf( float _value, uint32_t _count )
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
    MT_INLINE bool is_pow2( uint32_t _n )
    {
        return !(_n & (_n - 1));
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE uint32_t next_pow2( uint32_t _n )
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
    MT_INLINE uint32_t get_np2( uint32_t _n )
    {
        uint32_t p2 = 0;
        while( (_n >>= 1) != 0 )
        {
            ++p2;
        }

        return p2;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE float length( float _a, float _b )
    {
        float d = _a - _b;

        if( d >= 0.f )
        {
            return d;
        }

        return -d;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE void linerp_f1( float & _out, float _in1, float _in2, float _scale )
    {
        _out = _in1 + (_in2 - _in1) * _scale;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_INLINE float cross2_f( float _a, float _b, float _c, float _d )
    {
        return _a * _d - _c * _b;
    }
}