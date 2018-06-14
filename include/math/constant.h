#pragma once

#include "math/config.h"

namespace mt
{
    namespace constant
    {
        constexpr const float pi = 3.1415926535897932384626433832795f;
        constexpr const float inv_pi = 0.31830988618379067153776752674503f;
        constexpr const float negative_pi = -3.1415926535897932384626433832795f;
        constexpr const float half_pi = 1.5707963267948966192313216916398f;
        constexpr const float two_pi = 6.283185307179586476925286766559f;
        constexpr const float inv_two_pi = 0.15915494309189533576888376337251f;
        constexpr const float e = 2.71828182845904523536f;
        constexpr const float sqrt2 = 1.4142135623730950488016887242097f;
        constexpr const float	deg2rad = 0.01745329251994329576923690768489f;
        constexpr const float	rad2deg = 57.295779513082320876798154814105f;
        constexpr const float eps = 0.00001f;
        constexpr const float eps2 = eps * 10.f;
        constexpr const float neps = -eps;
        constexpr const float one_eps = 1.f + eps;
        constexpr const float one_neps = 1.f - eps;
    }
}

#ifndef MT_NO_DEFINE
#   define MT_DEG2RAD( DEG ) (DEG * mt::constant::deg2rad)
#   define MT_RAD2DEG( RAD ) (RAD * mt::constant::rad2deg)
#endif