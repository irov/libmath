#pragma once

#include "math/config.h"

#include "math/vec4.h"

namespace mt
{
	//////////////////////////////////////////////////////////////////////////
	struct uv4f
	{
		vec2f p0;
		vec2f p1;
		vec2f p2;
		vec2f p3;

		MT_METHOD_INLINE uv4f();
		MT_METHOD_INLINE uv4f( const uv4f & _uv );
		MT_METHOD_INLINE explicit uv4f( const vec2f & _p0, const vec2f & _p1, const vec2f & _p2, const vec2f & _p3 );
		MT_METHOD_INLINE explicit uv4f( const vec4f & _mask );
		MT_METHOD_INLINE const mt::vec2f & operator [] ( size_t i ) const;
		MT_METHOD_INLINE mt::vec2f & operator [] ( size_t i );
		MT_METHOD_INLINE uv4f & operator = ( const uv4f & _rhs );

        static MT_METHOD_INLINE const uv4f & identity();
	};

    MT_FUNCTION_INLINE bool operator==( const uv4f& _a, const uv4f & _b );
    MT_FUNCTION_INLINE bool operator!=( const uv4f& _a, const uv4f & _b );

	MT_FUNCTION_INLINE bool uv4_identity( const mt::uv4f & _uv );
    MT_FUNCTION_INLINE bool cmp_uv4_uv4( const mt::uv4f& _a, const mt::uv4f& _b );
	MT_FUNCTION_INLINE void uv4_from_mask( mt::uv4f & _out, const mt::vec4f & _mask );
	MT_FUNCTION_INLINE void uv4_rotate( mt::uv4f & _out );
	MT_FUNCTION_INLINE void uv4_swap_u( mt::uv4f & _out );
	MT_FUNCTION_INLINE void uv4_swap_v( mt::uv4f & _out );
	MT_FUNCTION_INLINE void uv4_scale( mt::uv4f & _out, const mt::uv4f & _uv, const mt::vec2f & _scale );
    MT_FUNCTION_INLINE void uv4_quad_point( mt::vec2f & _out, const mt::uv4f & _uv, const mt::vec2f & _point );
	MT_FUNCTION_INLINE void multiply_tetragon_uv4( mt::uv4f & _out, const mt::uv4f & _uv1, const mt::uv4f & _uv2 );
	MT_FUNCTION_INLINE void multiply_tetragon_uv4_v4( mt::uv4f & _out, const mt::uv4f & _uv, const mt::vec4f & _mask );
	MT_FUNCTION_INLINE void multiply_tetragon_uv4_vp( mt::uv4f & _out, const mt::uv4f & _uv1, const mt::vec2f * _uv2 );
	MT_FUNCTION_INLINE void multiply_tetragon_uv4_v2( mt::vec2f & _out, const mt::uv4f & _uv, const mt::vec2f & _p );
	MT_FUNCTION_INLINE mt::vec2f calc_point_uv( const mt::vec2f & _a, const mt::vec2f & _b, const mt::vec2f & _c, const mt::vec2f & _auv, const mt::vec2f & _buv, const mt::vec2f & _cuv, const mt::vec2f & _point );
}

#if MT_FORCE_INLINE == 1
#include "math/uv4_inline.h"
#endif
