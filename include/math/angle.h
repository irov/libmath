#pragma once

#include "math/config.h"

namespace mt
{
    float angle_norm( float _angle );
    float angle_norm2( float _angle );
    void angle_correct_interpolate_from_to( float _from, float _to, float * const _correct_from, float * const _correct_to );
    float angle_length( float _angle1, float _angle2 );
    float angle_norm360( float _angle );
    float angle_norm180( float _angle );
    float angle_delta_deg( float _angle1, float _angle2 );
    float angle_acos32( float _angle );
    float angle_in_interval_deg( float _angle, float _min, float _max );
}