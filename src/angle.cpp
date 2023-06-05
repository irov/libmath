#include "math/angle.h"

#if MT_FORCE_INLINE == 0
#include "math/constant.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float angle_norm( float _angle )
    {
        if( _angle < 0.f )
        {
            float pi_count = MT_floorf( _angle * mt::constant::inv_two_pi );
            float pi_abs = pi_count * mt::constant::two_pi;

            _angle -= pi_abs;
        }

        if( _angle > mt::constant::two_pi )
        {
            float pi_count = MT_floorf( _angle * mt::constant::inv_two_pi );
            float pi_abs = pi_count * mt::constant::two_pi;

            _angle -= pi_abs;
        }

        return _angle;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float angle_norm2( float _angle )
    {
        float angle2 = mt::angle_norm( _angle + mt::constant::pi );

        angle2 += mt::constant::negative_pi;

        return angle2;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void angle_correct_interpolate_from_to( float _from, float _to, float * const _correct_from, float * const _correct_to )
    {
        float norm_angle_from = mt::angle_norm( _from );
        float norm_angle_to = mt::angle_norm( _to );

        float correct_angle = norm_angle_to;

        if( norm_angle_to > norm_angle_from )
        {
            float dist = norm_angle_to - norm_angle_from;

            if( (norm_angle_from + mt::constant::two_pi) - norm_angle_to < dist )
            {
                correct_angle = norm_angle_to - mt::constant::two_pi;
            }
        }
        else
        {
            float dist = norm_angle_from - norm_angle_to;

            if( (norm_angle_to + mt::constant::two_pi) - norm_angle_from < dist )
            {
                correct_angle = norm_angle_to + mt::constant::two_pi;
            }
        }

        *_correct_from = norm_angle_from;
        *_correct_to = correct_angle;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float angle_length( float _angle1, float _angle2 )
    {
        float correct_angle_from;
        float correct_angle_to;
        mt::angle_correct_interpolate_from_to( _angle1, _angle2, &correct_angle_from, &correct_angle_to );

        float l = correct_angle_to - correct_angle_from;

        return l;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float angle_norm360( float _angle )
    {
        if( (_angle >= 360.f) || (_angle < 0.f) )
        {
            _angle -= MT_floorf( _angle / 360.f ) * 360.f;
        }

        return _angle;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float angle_norm180( float _angle )
    {
        _angle = angle_norm360( _angle );

        if( _angle > 180.f )
        {
            _angle -= 360.f;
        }

        return _angle;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float angle_delta_deg( float _angle1, float _angle2 )
    {
        float angle = mt::angle_norm180( _angle1 - _angle2 );

        return angle;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float angle_acos32( float _angle )
    {
        if( _angle <= -1.f )
        {
            return mt::constant::pi;
        }

        if( _angle >= 1.f )
        {
            return 0.f;
        }

        float a = MT_acosf( _angle );

        return a;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float angle_in_interval_deg( float _angle, float _min, float _max )
    {
        float delta = mt::angle_delta_deg( _max, _min );
        float delta1 = mt::angle_delta_deg( _angle, _min );

        return ((delta >= delta1) && (delta1 >= 0.f));
    }
    //////////////////////////////////////////////////////////////////////////
}
#endif

