#pragma once

#include <stddef.h>
#include <stdint.h>

#ifndef MT_CONSTEXPR
#   ifdef __cplusplus
#       if __cplusplus >= 201402L
#           define MT_CONSTFUNC constexpr
#           define MT_CONSTEXPR constexpr
#           define MT_CONSTVAR constexpr
#       elif __cplusplus >= 201103L
#           define MT_CONSTFUNC inline
#           define MT_CONSTEXPR constexpr
#           define MT_CONSTVAR constexpr
#       else
#           define MT_CONSTFUNC inline
#           define MT_CONSTEXPR inline
#           define MT_CONSTVAR static
#       endif
#   else
#       define MT_CONSTEXPR inline
#       define MT_CONSTVAR static
#   endif
#endif

#ifndef MT_NOEXCEPT
#   ifdef __cplusplus
#       if __cplusplus >= 201103L
#           define MT_NOEXCEPT noexcept
#       else
#           define MT_NOEXCEPT throw()
#       endif
#   else
#       define MT_NOEXCEPT
#   endif
#endif