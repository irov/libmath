#	pragma once

#	include "config.h"

namespace mt
{
	struct vec2f
	{
		typedef float value_type;
		typedef float element_type;

		float x;
		float y;

		LIBMATH_METHOD_INLINE vec2f();
		LIBMATH_METHOD_INLINE vec2f(float _x, float _y);		
		LIBMATH_METHOD_INLINE vec2f(const vec2f & _v);
		LIBMATH_METHOD_INLINE explicit vec2f( const float * _v );

		LIBMATH_METHOD_INLINE vec2f & operator = (const vec2f & _rhs);
		
		LIBMATH_METHOD_INLINE float operator [] ( size_t i ) const;
		LIBMATH_METHOD_INLINE float & operator [] ( size_t i );

		template <int K>
		LIBMATH_METHOD_INLINE float get() const
		{
			return this->operator [] (K);
		}

		template <int K>
		LIBMATH_METHOD_INLINE void set( float _value )
		{
			this->operator [] (K) = _value;
		}

		LIBMATH_METHOD_INLINE vec2f& operator+=(const vec2f & _rhs);
		LIBMATH_METHOD_INLINE vec2f& operator-=(const vec2f &	_rhs);
		LIBMATH_METHOD_INLINE vec2f& operator/=(const float _rhs);
		LIBMATH_METHOD_INLINE vec2f& operator*=(const float _rhs);
		LIBMATH_METHOD_INLINE vec2f& operator/=(const vec2f & _rhs);
		LIBMATH_METHOD_INLINE vec2f& operator*=(const vec2f & _rhs);

		LIBMATH_METHOD_INLINE void from_f2( const float * _v );

		LIBMATH_METHOD_INLINE float sqrlength() const;
		LIBMATH_METHOD_INLINE float length() const;

		LIBMATH_METHOD_INLINE float * buff();
		LIBMATH_METHOD_INLINE const float * buff() const;

        static LIBMATH_METHOD_INLINE const vec2f & identity();
	};

	LIBMATH_FUNCTION_INLINE bool operator==(const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE bool operator!=(const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE vec2f operator+(const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE vec2f operator-(const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE vec2f operator*(const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE vec2f operator*(const vec2f& _rhs, float _val);
	LIBMATH_FUNCTION_INLINE vec2f operator*(float _val, const vec2f& _rhs);
	LIBMATH_FUNCTION_INLINE vec2f operator/(const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE vec2f operator/(const vec2f& _rhs, float _val);
	LIBMATH_FUNCTION_INLINE vec2f operator/(float _val, const vec2f& _rhs);
	LIBMATH_FUNCTION_INLINE vec2f operator-(vec2f _rhs);
	LIBMATH_FUNCTION_INLINE vec2f operator+(vec2f _rhs);

	LIBMATH_FUNCTION_INLINE void ident_v2(vec2f& _a);	

	LIBMATH_FUNCTION_INLINE float length_v2(const vec2f& _a);
	LIBMATH_FUNCTION_INLINE float sqrlength_v2_v2(const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE float length_v2_v2(const vec2f& _a, const vec2f& _b);

	LIBMATH_FUNCTION_INLINE float length( const vec2f & _a, const vec2f & _b );

	LIBMATH_FUNCTION_INLINE bool cmp_v2_v2( const vec2f& _a, const vec2f& _b );

	LIBMATH_FUNCTION_INLINE void add_v2_v2(vec2f& _out,const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE void sub_v2_v2(vec2f& _out,const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE void dir_v2_v2(vec2f& _out,const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE void mul_v2_f(vec2f& _out, const vec2f& _a, float _val);
	LIBMATH_FUNCTION_INLINE void mul_v2_v2(vec2f& _out, const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE void div_v2_v2(vec2f& _out, const vec2f& _a, const vec2f& _b);
	LIBMATH_FUNCTION_INLINE void inv_v2(vec2f& _out, const vec2f & _in);
	LIBMATH_FUNCTION_INLINE void neg_v2(vec2f& _out);

	LIBMATH_FUNCTION_INLINE float dot_v2( const vec2f & a );
	LIBMATH_FUNCTION_INLINE float dot_v2_v2( const vec2f& a, const vec2f& b );
	
	LIBMATH_FUNCTION_INLINE float norm_v2_f(vec2f& _out, const vec2f& _rhs);
	LIBMATH_FUNCTION_INLINE void norm_v2_v2(vec2f& _out, const vec2f& _rhs);
	LIBMATH_FUNCTION_INLINE vec2f norm_v2(const vec2f& _rhs);
	LIBMATH_FUNCTION_INLINE void norm_safe_v2(vec2f& out, const vec2f& _rhs, float err = 0.00001f);
	LIBMATH_FUNCTION_INLINE vec2f norm_safe(const vec2f& _rhs);

	LIBMATH_FUNCTION_INLINE void perp_v2_v2( vec2f& _out, const vec2f& _a, const vec2f& _b );
	LIBMATH_FUNCTION_INLINE void perp_v2(vec2f& out, const vec2f& in);
	LIBMATH_FUNCTION_INLINE vec2f perp(const vec2f&	in);

	LIBMATH_FUNCTION_INLINE void perp_left_v2(vec2f& out, const vec2f& in);
	LIBMATH_FUNCTION_INLINE vec2f perp_left(const vec2f&	in);

	LIBMATH_FUNCTION_INLINE float is_left_v2(const vec2f& P0, const vec2f& P1, const vec2f& P2);
	LIBMATH_FUNCTION_INLINE float pseudo_cross_v2(const vec2f& a, const vec2f& b);

	LIBMATH_FUNCTION_INLINE void project_v2_v2(vec2f & out, const vec2f& a, const vec2f& b);

	LIBMATH_FUNCTION_INLINE vec2f slerp_v2_v2(const vec2f& a, const vec2f& b, float t);

	LIBMATH_FUNCTION_INLINE void rotate_v2(vec2f& _out, float _angle);

	LIBMATH_FUNCTION_INLINE void direction( mt::vec2f & _vec, float _angle );
	LIBMATH_FUNCTION_INLINE float signed_angle(const mt::vec2f & _vec);
};

#	if LIBMATH_FORCE_INLINE == 1
#	include "vec2_inline.h"
#	endif
