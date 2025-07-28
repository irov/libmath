#include "math/box2.h"
#include "math/stdmath.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    box2f::box2f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    box2f::box2f( float _minx, float _miny, float _maxx, float _maxy )
        : minimum( _minx, _miny )
        , maximum( _maxx, _maxy )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    box2f::box2f( const mt::box2f & _box )
        : minimum( _box.minimum )
        , maximum( _box.maximum )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    box2f::box2f( const mt::vec2f & _min, const mt::vec2f & _max )
        : minimum( _min )
        , maximum( _max )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    mt::box2f & box2f::operator = ( const mt::box2f & _box )
    {
        minimum = _box.minimum;
        maximum = _box.maximum;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_infinity( mt::box2f * const box )
    {
        box->minimum.x = -MT_FLT_MAX;
        box->minimum.y = -MT_FLT_MAX;
        box->maximum.x = MT_FLT_MAX;
        box->maximum.y = MT_FLT_MAX;
    }
    //////////////////////////////////////////////////////////////////////////
    bool box2_is_infinity( const mt::box2f & box )
    {
        if( box.minimum.x != -MT_FLT_MAX )
        {
            return false;
        }

        if( box.minimum.y != -MT_FLT_MAX )
        {
            return false;
        }

        if( box.maximum.x != MT_FLT_MAX )
        {
            return false;
        }

        if( box.maximum.y != MT_FLT_MAX )
        {
            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_insideout( mt::box2f * const box )
    {
        box->minimum.x = MT_FLT_MAX;
        box->minimum.y = MT_FLT_MAX;
        box->maximum.x = -MT_FLT_MAX;
        box->maximum.y = -MT_FLT_MAX;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_reset( box2f * const box, const mt::vec2f & initValue )
    {
        box->maximum = initValue;
        box->minimum = initValue;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_reset( mt::box2f * const box, float x, float y )
    {
        mt::box2_reset( box, mt::vec2f( x, y ) );
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_add_internal_point( mt::box2f * const box, float x, float y )
    {
        if( x > box->maximum.x ) box->maximum.x = x;
        if( y > box->maximum.y ) box->maximum.y = y;
        if( x < box->minimum.x ) box->minimum.x = x;
        if( y < box->minimum.y ) box->minimum.y = y;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_add_internal_point( mt::box2f * const box, const mt::vec2f & p )
    {
        mt::box2_add_internal_point( box, p.x, p.y );
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_merge( mt::box2f * const box, const mt::box2f & external_box )
    {
        if( external_box.minimum.x < box->minimum.x ) box->minimum.x = external_box.minimum.x;
        if( external_box.minimum.y < box->minimum.y ) box->minimum.y = external_box.minimum.y;
        if( external_box.maximum.x > box->maximum.x ) box->maximum.x = external_box.maximum.x;
        if( external_box.maximum.y > box->maximum.y ) box->maximum.y = external_box.maximum.y;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_crop( mt::box2f * const box, const box2f & external_box )
    {
        if( external_box.minimum.x > box->minimum.x ) box->minimum.x = external_box.minimum.x;
        if( external_box.minimum.y > box->minimum.y ) box->minimum.y = external_box.minimum.y;
        if( external_box.maximum.x < box->maximum.x ) box->maximum.x = external_box.maximum.x;
        if( external_box.maximum.y < box->maximum.y ) box->maximum.y = external_box.maximum.y;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_transpose( mt::box2f * const _box, const mt::vec2f & _pos )
    {
        _box->minimum += _pos;
        _box->maximum += _pos;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_scale( mt::box2f * const _box, const mt::vec2f & _scale )
    {
        _box->minimum *= _scale;
        _box->maximum *= _scale;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_get_center( const mt::box2f & _box, mt::vec2f * const _pos )
    {
        *_pos = (_box.minimum + _box.maximum) * 0.5f;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_set_from_min_max( mt::box2f * const box, const mt::vec2f & minimum, const mt::vec2f & maximum )
    {
        box->minimum = minimum;
        box->maximum = maximum;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_set_from_two_point( mt::box2f * const box, const mt::vec2f & a, const mt::vec2f & b )
    {
        mt::box2_reset( box, a );
        mt::box2_add_internal_point( box, b );
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_set_from_center_and_extent( mt::box2f * const box, const mt::vec2f & center, const mt::vec2f & extent )
    {
        box->minimum = center - extent;
        box->maximum = center + extent;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_set_from_oriented_extent( mt::box2f * const box, const mt::vec2f & _offset, const mt::vec2f & _size, const mt::mat3f & _wm )
    {
        mt::vec2f bounds[4];

        bounds[0].x = _offset.x;
        bounds[0].y = _offset.y;

        bounds[1].x = _offset.x + _size.x;
        bounds[1].y = _offset.y;

        bounds[2].x = _offset.x;
        bounds[2].y = _offset.y + _size.y;

        bounds[3].x = _offset.x + _size.x;
        bounds[3].y = _offset.y + _size.y;

        mt::mul_v2_m3( &box->minimum, bounds[0], _wm );

        box->maximum = box->minimum;

        for( uint32_t i = 1; i != 4; ++i )
        {
            mt::vec2f temp;
            mt::mul_v2_m3( &temp, bounds[i], _wm );

            if( box->minimum.x > temp.x ) box->minimum.x = temp.x;
            if( box->minimum.y > temp.y ) box->minimum.y = temp.y;
            if( box->maximum.x < temp.x ) box->maximum.x = temp.x;
            if( box->maximum.y < temp.y ) box->maximum.y = temp.y;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_homogenize( mt::box2f * const box, const mt::vec2f & _begin, const mt::vec2f & _end, const mt::mat4f & _wm )
    {
        mt::vec2f bb_minimum_homogenize;
        mt::mul_v2_v2_m4_homogenize( &bb_minimum_homogenize, _begin, _wm );

        mt::vec2f bb_minimum_homogenize_n;
        bb_minimum_homogenize_n.x = (1.f + bb_minimum_homogenize.x) * 0.5f;
        bb_minimum_homogenize_n.y = (1.f - bb_minimum_homogenize.y) * 0.5f;

        mt::vec2f bb_maximum_homogenize;
        mt::mul_v2_v2_m4_homogenize( &bb_maximum_homogenize, _end, _wm );

        mt::vec2f bb_maximum_homogenize_n;
        bb_maximum_homogenize_n.x = (1.f + bb_maximum_homogenize.x) * 0.5f;
        bb_maximum_homogenize_n.y = (1.f - bb_maximum_homogenize.y) * 0.5f;

        mt::box2_set_from_min_max( box, bb_minimum_homogenize_n, bb_maximum_homogenize_n );
    }
    //////////////////////////////////////////////////////////////////////////
    bool box2_intersect( const mt::vec2f & _aminimum, const mt::vec2f & _amaximum, const mt::vec2f & _bminimum, const mt::vec2f & _bmaximum )
    {
        if( _amaximum.x < _bminimum.x || _aminimum.x > _bmaximum.x )
        {
            return false;
        }

        if( _amaximum.y < _bminimum.y || _aminimum.y > _bmaximum.y )
        {
            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    bool box2_exist( const mt::vec2f & _aminimum, const mt::vec2f & _amaximum, const mt::vec2f & _bminimum, const mt::vec2f & _bmaximum )
    {
        return (_aminimum.x >= _bminimum.x && _amaximum.x <= _bmaximum.x)
            && (_aminimum.y >= _bminimum.y && _amaximum.y <= _bmaximum.y);
    }
    //////////////////////////////////////////////////////////////////////////
    bool box2_intersect( const mt::vec2f & _minimum, const mt::vec2f & _maximum, const mt::vec2f & _p )
    {
        return mt::box2_intersect( _minimum, _maximum, _p, _p );
    }
    //////////////////////////////////////////////////////////////////////////
    bool box2_intersect( const mt::box2f & _a, const mt::box2f & _b )
    {
        return mt::box2_intersect( _a.minimum, _a.maximum, _b.minimum, _b.maximum );
    }
    //////////////////////////////////////////////////////////////////////////
    bool box2_intersect( const mt::box2f & _a, const mt::vec2f & _b )
    {
        return mt::box2_intersect( _a.minimum, _a.maximum, _b, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    bool box2_intersect( const mt::box2f & _a, const mt::vec2f & _b, float _radius )
    {
        if( _a.minimum.x > _b.x + _radius )
        {
            return false;
        }

        if( _a.maximum.x < _b.x - _radius )
        {
            return false;
        }

        if( _a.minimum.y > _b.y + _radius )
        {
            return false;
        }

        if( _a.maximum.y < _b.y - _radius )
        {
            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    bool box2_intersect( const mt::box2f & _a, const mt::vec2f & _b, float _radiusx, float _radiusy )
    {
        if( _a.minimum.x > _b.x + _radiusx )
        {
            return false;
        }

        if( _a.maximum.x < _b.x - _radiusx )
        {
            return false;
        }

        if( _a.minimum.y > _b.y + _radiusy )
        {
            return false;
        }

        if( _a.maximum.y < _b.y - _radiusy )
        {
            return false;
        }

        return true;
    }
    //////////////////////////////////////////////////////////////////////////
    void box2_mul_m4( mt::box2f * const _out, const mt::box2f & _a, const mt::mat4f & _b )
    {
        mt::mul_v2_v2_m4( &_out->minimum, _a.minimum, _b );
        mt::mul_v2_v2_m4( &_out->maximum, _a.maximum, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    mt::vec2f box2_size( const mt::box2f & _box )
    {
        return _box.maximum - _box.minimum;
    }
    //////////////////////////////////////////////////////////////////////////
}