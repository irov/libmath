#	include "utils.h"

#	include <math.h>

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f::vec3f() 
	{
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f::vec3f(float _x, float _y, float _z)
		:x(_x)
		,y(_y)
		,z(_z)
	{
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f::vec3f(const vec3f& _v)
		:x(_v.x)
		,y(_v.y)
		,z(_v.z)
	{}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f::vec3f(const vec2f& _v, float _z)
		:x(_v.x)
		,y(_v.y)
		,z(_z)
	{}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f& vec3f::operator=(const vec3f& _rhs)
    {
        x = _rhs.x;
        y = _rhs.y;
        z = _rhs.z;     

        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE float vec3f::operator[](size_t i) const
	{
		return (&x)[i];
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE float& vec3f::operator[](size_t i)
	{
		return (&x)[i];
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f& vec3f::operator+=(const vec3f& _rhs)
	{
		x += _rhs.x;
		y += _rhs.y;
		z += _rhs.z;

		return *this;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f& vec3f::operator-=(const vec3f& _rhs)
	{
		x -= _rhs.x;
		y -= _rhs.y;
		z -= _rhs.z;

		return *this;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f& vec3f::operator /= (const float _rhs)
	{
		operator *= (1.f/_rhs); 

		return *this;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec3f& vec3f::operator *= (const float _rhs)
	{
		x *= _rhs;
		y *= _rhs;
		z *= _rhs;

		return *this;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE float vec3f::sqrlength()	const
	{
		return	x * x + y * y + z * z;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE float vec3f::length()	const
	{
		float sqrlen = this->sqrlength();
        float len = sqrtf(sqrlen);

		return len;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE vec2f vec3f::to_vec2f() const
	{
		return mt::vec2f(x, y);
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE void vec3f::from_f3( const float * _v )
	{
		x = _v[0];
		y = _v[1];
		z = _v[2];
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE float * vec3f::buff()
	{
		return &x;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_METHOD_INLINE const float * vec3f::buff() const
	{
		return &x;
	}
    //////////////////////////////////////////////////////////////////////////
    LIBMATH_METHOD_INLINE const vec3f & vec3f::identity()
    {
        static mt::vec3f v( 0.f, 0.f, 0.f );

        return v;
    }
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void ident_v3( vec3f& _a )
	{
		_a.x = 0.f;
		_a.y = 0.f;
		_a.z = 0.f;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE bool is_ident_v3( const vec3f & _a )
	{
		return mt::equal_f_z( _a.x ) && mt::equal_f_z( _a.y ) && mt::equal_f_z( _a.z );
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float length( const vec3f& _a, const vec3f& _b )
	{
		return length_v3_v3( _a, _b );
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float length_v3_v3(const vec3f& _a, const vec3f& _b)
	{
		vec3f c = _a - _b;
        float len = c.length();

		return len;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float sqrlength_v3_v3(const vec3f& _a, const vec3f& _b)
	{
		vec3f c = _a - _b;
		float sqrlength = c.sqrlength();

		return sqrlength;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float sqrlength_v3( const vec3f& _a )
	{
		float sqrlength = _a.sqrlength();

		return sqrlength;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void dir_v3_v3(vec3f & _out, const vec3f& _a, const vec3f& _b)
	{
		vec3f dir = _b - _a;
		
		mt::norm_v3_v3( _out, dir );
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float dir_v3_v3_f( vec3f & _out, const vec3f& _a, const vec3f& _b )
	{
		vec3f dir = _b - _a;

		float length = mt::norm_v3_v3_f( _out, dir );

		return length;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float length_v3(const vec3f& _a)
	{
        float len = _a.length();

		return len;
	}
	//////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE bool cmp_v3_v2( const vec3f& _a, const vec2f& _b )
	{
		return mt::equal_f_f( _a.x, _b.x ) == true &&
			mt::equal_f_f( _a.y, _b.y ) == true;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE bool cmp_v3_v3(const vec3f& _a, const vec3f& _b)
	{
		return mt::equal_f_f( _a.x, _b.x ) == true && 
			mt::equal_f_f( _a.y, _b.y ) == true && 
			mt::equal_f_f( _a.z, _b.z ) == true;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE bool operator==(const vec3f& _a, const vec3f& _b) 
	{
		return cmp_v3_v3(_a, _b);
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE bool operator!=(const vec3f& _a, const vec3f& _b) 
	{
		return !operator==(_a, _b);
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void add_v3_v3(vec3f& _out,const vec3f& _a, const vec3f& _b)
	{
		_out.x = _a.x + _b.x;
		_out.y = _a.y + _b.y;
		_out.z = _a.z + _b.z;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f operator+(const vec3f& _a, const vec3f& _b) 
	{
		vec3f out;
		add_v3_v3(out, _a, _b);
		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void sub_v3_v3(vec3f& _out,const vec3f& _a, const vec3f& _b)
	{
		_out.x = _a.x - _b.x;
		_out.y = _a.y - _b.y;
		_out.z = _a.z - _b.z;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f operator-(const vec3f& _a, const vec3f& _b) 
	{
		vec3f out;
		sub_v3_v3(out, _a, _b);
		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f operator*(const vec3f& _a, const vec3f & _b)
	{
		vec3f out;
		mul_v3_v3( out, _a, _b );
		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void scale_v3_v3(vec3f& _out, const vec3f& _a, float _val)
	{
		_out.x = _a.x * _val;
		_out.y = _a.y * _val;
		_out.z = _a.z * _val;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void mul_v3_v3( vec3f& _out, const vec3f& _a, const vec3f& _b )
	{
		_out.x = _a.x * _b.x;
		_out.y = _a.y * _b.y;
		_out.z = _a.z * _b.z;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f operator*(const vec3f& _rhs, const float _val) 
	{
		vec3f out;
		scale_v3_v3(out, _rhs, _val);
		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f operator*(const float _val, const vec3f& _rhs)
	{
		vec3f out;
		scale_v3_v3(out, _rhs, _val);
		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f operator/(const vec3f& _a, const vec3f & _b)
	{
		vec3f out;
		out.x = _a.x / _b.x;
		out.y = _a.y / _b.y;
		out.z = _a.z / _b.z;

		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f operator/(const vec3f& _rhs, const float _val) 
	{
		return operator*(_rhs, 1/_val);
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void neg_v3(vec3f& _out)
	{
		_out.x = -_out.x;
		_out.y = -_out.y;
		_out.z = -_out.z;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f operator-(vec3f _rhs)
	{
		neg_v3(_rhs);
		return _rhs;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float dot_v3( const vec3f &a )
	{
		return a.x * a.x + a.y * a.y + a.z * a.z;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float dot_v3_v3(const vec3f &a, const vec3f &b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
    //////////////////////////////////////////////////////////////////////////
    LIBMATH_FUNCTION_INLINE float dot_v3_v2( const vec3f &a, const vec2f &b )
    {
        return a.x * b.x + a.y * b.y;
    }
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float dot_v3_v3_clamp(const vec3f &a, const vec3f &b)
	{
		float dot = a.x * b.x + a.y * b.y + a.z * b.z;
		if(dot > 1.0f) dot = 1.0f;
		if(dot < -1.0f) dot = -1.0f;
		return dot;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void reflect_v3_v3(vec3f& _out, const vec3f& _a, const vec3f& _b)
	{
		_out = _a - _b * dot_v3_v3( _a, _b ) * 2.0f;
	}	
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f reflect_v3_v3(const vec3f& _a, const vec3f& _b)
	{
		vec3f out;
		reflect_v3_v3(out, _a, _b);
		return out;
	}	
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float project_to_line_v3_v3( vec3f& _out, const vec3f& _a, const vec3f& _b, const vec3f & _c )
	{
		float da = mt::dot_v3_v3( _c - _a, _b - _a );
		float db = mt::dot_v3_v3( _b - _a, _b - _a );

		float dab = (da / db);

		_out = _a + (_b - _a) * dab;
		
		return dab;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void cross_v3_v3(vec3f& _out, const vec3f& _a, const vec3f& _b)
	{
		_out.x = _a.y*_b.z - _a.z*_b.y;
		_out.y = _a.z*_b.x - _a.x*_b.z;
		_out.z = _a.x*_b.y - _a.y*_b.x;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f cross_v3_v3(const vec3f& _a, const vec3f& _b)
	{
		vec3f out;
		cross_v3_v3(out, _a, _b);
		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void cross_v3_v3_norm(vec3f& _out, const vec3f& _a, const vec3f& _b)
	{
		_out.x = _a.y*_b.z - _a.z*_b.y;
		_out.y = _a.z*_b.x - _a.x*_b.z;
		_out.z = _a.x*_b.y - _a.y*_b.x;

		norm_v3_v3( _out, _out );
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void norm_v3_v3( vec3f& _out, const vec3f& _rhs )
	{
		_out = _rhs / _rhs.length();
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float norm_v3_v3_f( vec3f& _out, const vec3f & _rhs )
	{
		float l = _rhs.length();

		_out = _rhs / l;

		return l;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f norm_v3(const vec3f& _rhs)
	{
		vec3f out;
		norm_v3_v3( out, _rhs );

		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void norm_safe_v3(vec3f& out, const vec3f& _rhs, float err)
	{
		float len = _rhs.length();
		if (len > err)
        {
			out = _rhs / len;
		}
		else
		{
			out = _rhs;
		}
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE vec3f norm_safe_v3(const vec3f& _rhs)
	{
		vec3f out;
		norm_safe_v3(out, _rhs);
		return out;
	}
    //////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float get_axis_angle(const vec3f& dir, int axis)
	{
		int ind1 = 1; //axis == 0
		int ind2 = 2; //axis == 0

		if( axis == 1 )	
		{
			ind1 = 0; 
			ind2 = 2;
		}
		else if( axis == 2 )
		{
			ind1 = 0; 
			ind2 = 1;
		}

		float result = 0.f;

		vec2f d(dir[ind1], dir[ind2]);
		vec2f n;
		mt::norm_v2_v2(n, d);

		if( (n.x >= 0) && (n.y >= 0) )
		{
			result = asinf(n.y);
		}

		if( (n.x <= 0) && (n.y <= 0) )
		{
			result = constant::pi + asinf(-n.y);
		}

		if( (n.x >= 0) && (n.y <= 0) )
		{
			result = constant::half_pi - asinf(-n.y);
		}

		if( (n.x <= 0) && (n.y >= 0) )
		{
			result = constant::pi - asinf(n.y);
		}

		return constant::half_pi - result;
	}
	//////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE void linerp_v3( mt::vec3f & _out, const mt::vec3f & _in1, const mt::vec3f & _in2, float _scale )
	{
		mt::linerp_f1( _out.x, _in1.x, _in2.x, _scale );
		mt::linerp_f1( _out.y, _in1.y, _in2.y, _scale );
		mt::linerp_f1( _out.z, _in1.z, _in2.z, _scale );
	}
	//////////////////////////////////////////////////////////////////////////
	LIBMATH_FUNCTION_INLINE float follow_v3( mt::vec3f & _out, const mt::vec3f & _in1, const mt::vec3f & _in2, float _step )
	{
		mt::vec3f dir;
		float length = mt::dir_v3_v3_f( dir, _in1, _in2 );

		if( length - _step < 0.f )
		{
			_out = _in2;

			return _step - length;
		}

		_out = _in1 + dir * _step;

		return 0.f;
	}
}
