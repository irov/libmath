#pragma once

#include "math/config.h"

#include "math/vec2.h"

namespace mt
{    
	class convex8
	{
    public:
        MT_METHOD_INLINE convex8();

    public:
        MT_METHOD_INLINE const mt::vec2f & operator [] ( size_t i ) const;
        MT_METHOD_INLINE mt::vec2f & operator [] ( size_t i );

    public:
        MT_METHOD_INLINE void add( const mt::vec2f & v );
        MT_METHOD_INLINE const mt::vec2f & front() const;
        MT_METHOD_INLINE const mt::vec2f & back() const;
        MT_METHOD_INLINE uint32_t size() const;
        MT_METHOD_INLINE bool empty() const;
        MT_METHOD_INLINE void clear();

    protected:
		mt::vec2f point[8];
		uint32_t count;
	};

	MT_FUNCTION_INLINE void convex8_intersect( const mt::convex8 & _convex, const mt::convex8 & _clip, mt::convex8 & _result );
    MT_FUNCTION_INLINE float convex8_area( const mt::convex8 & _convex );
}

#if MT_FORCE_INLINE == 1
#	include "convex8_inline.h"
#endif
