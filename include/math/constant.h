#pragma once

#include "math/config.h"

namespace mt
{
    namespace constant
    {
        MT_CONSTVAR const float pi = 3.1415926535897932384626433832795f;
        MT_CONSTVAR const float inv_pi = 0.31830988618379067153776752674503f;
        MT_CONSTVAR const float inv_two_pi = 0.15915494309189533576888376337251f;
        MT_CONSTVAR const float negative_pi = -3.1415926535897932384626433832795f;
        MT_CONSTVAR const float zero_pi = 0.f;
        MT_CONSTVAR const float fourth_pi = 0.78539816339744830961566084581988f;
        MT_CONSTVAR const float half_pi = 1.5707963267948966192313216916398f;
        MT_CONSTVAR const float one_and_a_half_pi = 4.7123889803846898576939650749193f;
        MT_CONSTVAR const float two_pi = 6.283185307179586476925286766559f;
        MT_CONSTVAR const float e = 2.71828182845904523536f;
        MT_CONSTVAR const float sqrt2 = 1.4142135623730950488016887242097f;
        MT_CONSTVAR const float deg2rad = 0.01745329251994329576923690768489f;
        MT_CONSTVAR const float rad2deg = 57.295779513082320876798154814105f;
        MT_CONSTVAR const float eps = 0.00001f;
        MT_CONSTVAR const float eps2 = eps * 10.f;
        MT_CONSTVAR const float neps = -eps;
        MT_CONSTVAR const float one_eps = 1.f + eps;
        MT_CONSTVAR const float one_neps = 1.f - eps;
        MT_CONSTVAR const float log2 = 0.69314718055994530941723212145818f;
        MT_CONSTVAR const float inv_log2 = 1.4426950408889634073599246810019f;
    }
}

#ifndef MT_NO_DEFINE
#   define MT_DEG2RAD( DEG ) ((DEG) * mt::constant::deg2rad)
#   define MT_RAD2DEG( RAD ) ((RAD) * mt::constant::rad2deg)
#endif