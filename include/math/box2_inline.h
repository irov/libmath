namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box2f::box2f()
    {}
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box2f::box2f( float _minx, float _miny, float _maxx, float _maxy )
        : minimum( _minx, _miny )
        , maximum( _maxx, _maxy )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box2f::box2f( const box2f & _box )
        : minimum( _box.minimum )
        , maximum( _box.maximum )
    {}
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box2f::box2f( const vec2f & _min, const vec2f & _max )
        : minimum( _min )
        , maximum( _max )
    {}
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE box2f & box2f::operator = ( const box2f & _box )
    {
        minimum = _box.minimum;
        maximum = _box.maximum;

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void infinity_box( box2f & box )
    {
        box.minimum.x = -MT_FLT_MAX;
        box.minimum.y = -MT_FLT_MAX;
        box.maximum.x = MT_FLT_MAX;
        box.maximum.y = MT_FLT_MAX;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void insideout_box( box2f & box )
    {
        box.minimum.x = MT_FLT_MAX;
        box.minimum.y = MT_FLT_MAX;
        box.maximum.x = -MT_FLT_MAX;
        box.maximum.y = -MT_FLT_MAX;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void reset( box2f & box, const vec2f &initValue )
    {
        box.maximum = initValue;
        box.minimum = initValue;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void reset( box2f & box, float x, float y )
    {
        reset( box, vec2f( x, y ) );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void add_internal_point( box2f & box, float x, float y )
    {
        if( x > box.maximum.x ) box.maximum.x = x;
        if( y > box.maximum.y ) box.maximum.y = y;
        if( x < box.minimum.x ) box.minimum.x = x;
        if( y < box.minimum.y ) box.minimum.y = y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void add_internal_point( box2f & box, const vec2f &p )
    {
        add_internal_point( box, p.x, p.y );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void merge_box( box2f & box, const box2f & external_box )
    {
        if( external_box.minimum.x < box.minimum.x ) box.minimum.x = external_box.minimum.x;
        if( external_box.minimum.y < box.minimum.y ) box.minimum.y = external_box.minimum.y;
        if( external_box.maximum.x > box.maximum.x ) box.maximum.x = external_box.maximum.x;
        if( external_box.maximum.y > box.maximum.y ) box.maximum.y = external_box.maximum.y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void crop_box( box2f & box, const box2f & external_box )
    {
        if( external_box.minimum.x > box.minimum.x ) box.minimum.x = external_box.minimum.x;
        if( external_box.minimum.y > box.minimum.y ) box.minimum.y = external_box.minimum.y;
        if( external_box.maximum.x < box.maximum.x ) box.maximum.x = external_box.maximum.x;
        if( external_box.maximum.y < box.maximum.y ) box.maximum.y = external_box.maximum.y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void transpose_box( box2f & _box, const mt::vec2f & _pos )
    {
        _box.minimum += _pos;
        _box.maximum += _pos;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void scale_box( box2f & _box, const mt::vec2f & _scale )
    {
        _box.minimum *= _scale;
        _box.maximum *= _scale;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void get_center_box( const box2f & _box, mt::vec2f & _pos )
    {
        _pos = (_box.minimum + _box.maximum) * 0.5f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_box_from_min_max( box2f & box, const vec2f &minimum, const vec2f &maximum )
    {
        box.minimum = minimum;
        box.maximum = maximum;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_box_from_two_point( box2f & box, const vec2f & a, const vec2f & b )
    {
        mt::reset( box, a );
        mt::add_internal_point( box, b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_box_from_center_and_extent( box2f & box, const vec2f &center, const vec2f &extent )
    {
        box.minimum = center - extent;
        box.maximum = center + extent;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_box_from_oriented_extent( box2f & box, const mt::vec2f & _offset, const mt::vec2f& _size, const mt::mat3f& _wm )
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

        mt::mul_v2_m3( box.minimum, bounds[0], _wm );

        box.maximum = box.minimum;

        mt::vec2f temp;

        for( uint32_t i = 1; i != 4; ++i )
        {
            mt::mul_v2_m3( temp, bounds[i], _wm );

            if( box.maximum.x < temp.x ) box.maximum.x = temp.x;
            if( box.maximum.y < temp.y ) box.maximum.y = temp.y;

            if( box.minimum.x > temp.x ) box.minimum.x = temp.x;
            if( box.minimum.y > temp.y ) box.minimum.y = temp.y;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_box_homogenize( box2f & box, const mt::vec2f & _begin, const mt::vec2f & _end, const mt::mat4f & _wm )
    {
        mt::vec2f bb_minimum_homogenize;
        mt::mul_v2_v2_m4_homogenize( bb_minimum_homogenize, _begin, _wm );

        mt::vec2f bb_minimum_homogenize_n;
        bb_minimum_homogenize_n.x = (1.f + bb_minimum_homogenize.x) * 0.5f;
        bb_minimum_homogenize_n.y = (1.f - bb_minimum_homogenize.y) * 0.5f;

        mt::vec2f bb_maximum_homogenize;
        mt::mul_v2_v2_m4_homogenize( bb_maximum_homogenize, _end, _wm );

        mt::vec2f bb_maximum_homogenize_n;
        bb_maximum_homogenize_n.x = (1.f + bb_maximum_homogenize.x) * 0.5f;
        bb_maximum_homogenize_n.y = (1.f - bb_maximum_homogenize.y) * 0.5f;

        mt::set_box_from_min_max( box, bb_minimum_homogenize_n, bb_maximum_homogenize_n );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool is_intersect( const vec2f & _aminimum, const vec2f & _amaximum, const vec2f & _bminimum, const vec2f & _bmaximum )
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
    MT_FUNCTION_INLINE bool is_exist( const vec2f & _aminimum, const vec2f & _amaximum, const vec2f & _bminimum, const vec2f & _bmaximum )
    {
        return (_aminimum.x >= _bminimum.x && _amaximum.x <= _bmaximum.x)
            && (_aminimum.y >= _bminimum.y && _amaximum.y <= _bmaximum.y);
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool is_intersect( const vec2f & _minimum, const vec2f & _maximum, const vec2f & _p )
    {
        return is_intersect( _minimum, _maximum, _p, _p );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool is_intersect( const box2f & _a, const box2f & _b )
    {
        return is_intersect( _a.minimum, _a.maximum, _b.minimum, _b.maximum );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool is_intersect( const box2f & _a, const vec2f & _b )
    {
        return is_intersect( _a.minimum, _a.maximum, _b, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool is_intersect( const box2f & _a, const vec2f & _b, float _radius )
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
    MT_FUNCTION_INLINE bool is_intersect( const box2f & _a, const vec2f & _b, float _radiusx, float _radiusy )
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
    MT_FUNCTION_INLINE void mul_box2_m4( box2f & _out, const box2f & _a, const mat4f & _b )
    {
        mt::mul_v2_v2_m4( _out.minimum, _a.minimum, _b );
        mt::mul_v2_v2_m4( _out.maximum, _a.maximum, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec2f box_size( const box2f& _box )
    {
        return _box.maximum - _box.minimum;
    }
}
