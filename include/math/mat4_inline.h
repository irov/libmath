#include "math/angle.h"

namespace mt
{
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE mat4f::mat4f()
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE mat4f::mat4f( const mat4f& _rhs )
        :v0( _rhs.v0 )
        , v1( _rhs.v1 )
        , v2( _rhs.v2 )
        , v3( _rhs.v3 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE mat4f::mat4f( const vec4f & _v0, const vec4f & _v1, const vec4f & _v2, const vec4f & _v3 )
        :v0( _v0 )
        , v1( _v1 )
        , v2( _v2 )
        , v3( _v3 )
    {
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE vec4f& mat4f::operator[]( size_t i )
    {
        return (&v0)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE const vec4f& mat4f::operator[]( size_t i )const
    {
        return (&v0)[i];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE mat4f& mat4f::operator=( const mat4f& _rhs )
    {
        v0 = _rhs.v0;
        v1 = _rhs.v1;
        v2 = _rhs.v2;
        v3 = _rhs.v3;
        return *this;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void mat4f::from_f12( const float * _v )
    {
        v0.x = _v[0 * 3 + 0];
        v0.y = _v[0 * 3 + 1];
        v0.z = _v[0 * 3 + 2];
        v0.w = 0.f;

        v1.x = _v[1 * 3 + 0];
        v1.y = _v[1 * 3 + 1];
        v1.z = _v[1 * 3 + 2];
        v1.w = 0.f;

        v2.x = _v[2 * 3 + 0];
        v2.y = _v[2 * 3 + 1];
        v2.z = _v[2 * 3 + 2];
        v2.w = 0.f;

        v3.x = _v[3 * 3 + 0];
        v3.y = _v[3 * 3 + 1];
        v3.z = _v[3 * 3 + 2];
        v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE void mat4f::from_f16( const float * _v )
    {
        v0.x = _v[0 * 4 + 0];
        v0.y = _v[0 * 4 + 1];
        v0.z = _v[0 * 4 + 2];
        v0.w = _v[0 * 4 + 3];

        v1.x = _v[1 * 4 + 0];
        v1.y = _v[1 * 4 + 1];
        v1.z = _v[1 * 4 + 2];
        v1.w = _v[1 * 4 + 3];

        v2.x = _v[2 * 4 + 0];
        v2.y = _v[2 * 4 + 1];
        v2.z = _v[2 * 4 + 2];
        v2.w = _v[2 * 4 + 3];

        v3.x = _v[3 * 4 + 0];
        v3.y = _v[3 * 4 + 1];
        v3.z = _v[3 * 4 + 2];
        v3.w = _v[3 * 4 + 3];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE float * mat4f::buff()
    {
        return v0.buff();
    }
    //////////////////////////////////////////////////////////////////////////
    MT_METHOD_INLINE const float * mat4f::buff() const
    {
        return v0.buff();
    }
    MT_METHOD_INLINE const mat4f & mat4f::identity()
    {
        static mat4f ident(
            vec4f( 1.f, 0.f, 0.f, 0.f ),
            vec4f( 0.f, 1.f, 0.f, 0.f ),
            vec4f( 0.f, 0.f, 1.f, 0.f ),
            vec4f( 0.f, 0.f, 0.f, 1.f ) );

        return ident;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool cmp_m4_m4( const mat4f& _a, const mat4f& _b )
    {
        return	cmp_v4_v4( _a.v0, _b.v0 ) &&
            cmp_v4_v4( _a.v1, _b.v1 ) &&
            cmp_v4_v4( _a.v2, _b.v2 ) &&
            cmp_v4_v4( _a.v3, _b.v3 );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool operator==( const mat4f& _a, const mat4f& _b )
    {
        return	cmp_m4_m4( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool operator!=( const mat4f& _a, const mat4f& _b )
    {
        return !operator==( _a, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_v2_z( vec2f& _out, const mat4f& _m )
    {
        _out.x = dot_v4_z( _m.v0 );
        _out.y = dot_v4_z( _m.v1 );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_v3_z( vec3f& _out, const mat4f& _m )
    {
        _out.x = dot_v4_z( _m.v0 );
        _out.y = dot_v4_z( _m.v1 );
        _out.z = dot_v4_z( _m.v2 );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_v4_z( vec4f& _out, const mat4f& _m )
    {
        _out.x = dot_v4_z( _m.v0 );
        _out.y = dot_v4_z( _m.v1 );
        _out.z = dot_v4_z( _m.v2 );
        _out.w = dot_v4_z( _m.v3 );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_v2( vec2f& _out, const mat4f& _m, const vec2f& _v )
    {
        _out.x = dot_v4_v2( _m.v0, _v );
        _out.y = dot_v4_v2( _m.v1, _v );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_v3( vec3f& _out, const mat4f& _m, const vec3f& _v )
    {
        _out.x = dot_v4_v3( _m.v0, _v );
        _out.y = dot_v4_v3( _m.v1, _v );
        _out.z = dot_v4_v3( _m.v2, _v );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec3f operator*( const mat4f& m, const vec3f& v )
    {
        vec3f out;
        mul_m4_v3( out, m, v );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v3_v3_m4( vec3f& _out, const vec3f& _v, const mat4f& _m )
    {
        mul_v3_v3_m4_r( _out, _v, _m );

        _out.x += _m.v3.x;
        _out.y += _m.v3.y;
        _out.z += _m.v3.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v3_v3_m4_r( vec3f& _out, const vec3f& _v, const mat4f& _m )
    {
        _out.x = _m.v0.x * _v.x + _m.v1.x * _v.y + _m.v2.x * _v.z;
        _out.y = _m.v0.y * _v.x + _m.v1.y * _v.y + _m.v2.y * _v.z;
        _out.z = _m.v0.z * _v.x + _m.v1.z * _v.y + _m.v2.z * _v.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE float mul_v3_v3_m4_proj( vec3f& _out, const vec3f& _v, const mat4f& _m )
    {
        mul_v3_v3_m4( _out, _v, _m );

        float w = 1.f / _out.z;
        _out *= w;

        return w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v2_v2_m4( vec2f& _out, const vec2f& _v, const mat4f& _m )
    {
        mul_v2_v2_m4_r( _out, _v, _m );

        _out.x += _m.v3.x;
        _out.y += _m.v3.y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v2_v3_m4( vec2f& _out, const vec3f& _v, const mat4f& _m )
    {
        mul_v2_v3_m4_r( _out, _v, _m );

        _out.x += _m.v3.x;
        _out.y += _m.v3.y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v2_v3_m4_r( vec2f& _out, const vec3f& _v, const mat4f& _m )
    {
        _out.x = _m.v0.x * _v.x + _m.v1.x * _v.y + _m.v2.x * _v.z;
        _out.y = _m.v0.y * _v.x + _m.v1.y * _v.y + _m.v2.y * _v.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v3_v2_m4( vec3f& _out, const vec2f& _v, const mat4f& _m )
    {
        mul_v3_v2_m4_r( _out, _v, _m );

        _out.x += _m.v3.x;
        _out.y += _m.v3.y;
        _out.z += _m.v3.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v2_v2_m4_r( vec2f& _out, const vec2f& _v, const mat4f& _m )
    {
        _out.x = _m.v0.x * _v.x + _m.v1.x * _v.y;
        _out.y = _m.v0.y * _v.x + _m.v1.y * _v.y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v3_v2_m4_r( vec3f & _out, const vec2f& _v, const mat4f& _m )
    {
        _out.x = _m.v0.x * _v.x + _m.v1.x * _v.y;
        _out.y = _m.v0.y * _v.x + _m.v1.y * _v.y;
        _out.z = _m.v0.z * _v.x + _m.v1.z * _v.y;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec3f operator*( const vec3f& v, const mat4f& m )
    {
        vec3f out;
        mul_v3_v3_m4( out, v, m );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_v4( vec4f& _out, const mat4f& _m, const vec4f& _v )
    {
        _out.x = dot_v4_v4( _m.v0, _v );
        _out.y = dot_v4_v4( _m.v1, _v );
        _out.z = dot_v4_v4( _m.v2, _v );
        _out.w = dot_v4_v4( _m.v3, _v );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator*( const mat4f& m, const vec4f& v )
    {
        vec4f out;
        mul_m4_v4( out, m, v );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v4_m4( vec4f & _out, const vec4f & _a, const mat4f & _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _a.z * _b.v2.x + _a.w * _b.v3.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _a.z * _b.v2.y + _a.w * _b.v3.y;
        _out.z = _a.x * _b.v0.z + _a.y * _b.v1.z + _a.z * _b.v2.z + _a.w * _b.v3.z;
        _out.w = _a.x * _b.v0.w + _a.y * _b.v1.w + _a.z * _b.v2.w + _a.w * _b.v3.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v4_m4_r( vec4f & _out, const vec4f & _a, const mat4f & _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _a.z * _b.v2.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _a.z * _b.v2.y;
        _out.z = _a.x * _b.v0.z + _a.y * _b.v1.z + _a.z * _b.v2.z;
        _out.w = 0.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v4_m4_r1( vec4f & _out, const vec4f & _a, const mat4f & _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _a.z * _b.v2.x + _a.w * _b.v3.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _a.z * _b.v2.y + _a.w * _b.v3.y;
        _out.z = _a.x * _b.v0.z + _a.y * _b.v1.z + _a.z * _b.v2.z + _a.w * _b.v3.z;
        _out.w = _b.v3.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v4_v3_m4( vec4f & _out, const vec3f & _a, const mat4f & _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _a.z * _b.v2.x + _b.v3.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _a.z * _b.v2.y + _b.v3.y;
        _out.z = _a.x * _b.v0.z + _a.y * _b.v1.z + _a.z * _b.v2.z + _b.v3.z;
        _out.w = _a.x * _b.v0.w + _a.y * _b.v1.w + _a.z * _b.v2.w + _b.v3.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v3_v3_m4_homogenize( vec3f & _out, const vec3f & _a, const mat4f & _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _a.z * _b.v2.x + _b.v3.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _a.z * _b.v2.y + _b.v3.y;
        _out.z = _a.x * _b.v0.z + _a.y * _b.v1.z + _a.z * _b.v2.z + _b.v3.z;

        float w = _a.x * _b.v0.w + _a.y * _b.v1.w + _a.z * _b.v2.w + _b.v3.w;
        float w_inv = 1.f / w;

        _out.x *= w_inv;
        _out.y *= w_inv;
        _out.z *= w_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v2_v3_m4_homogenize( vec2f & _out, const vec3f & _a, const mat4f & _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _a.z * _b.v2.x + _b.v3.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _a.z * _b.v2.y + _b.v3.y;

        float w = _a.x * _b.v0.w + _a.y * _b.v1.w + _a.z * _b.v2.w + _b.v3.w;
        float w_inv = 1.f / w;

        _out.x *= w_inv;
        _out.y *= w_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v2_v2_m4_homogenize( vec2f & _out, const vec2f & _a, const mat4f & _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _b.v3.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _b.v3.y;

        float w = _a.x * _b.v0.w + _a.y * _b.v1.w + _b.v3.w;
        float w_inv = 1.f / w;

        _out.x *= w_inv;
        _out.y *= w_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v2_v2z_m4_homogenize( vec2f & _out, const mat4f & _b )
    {
        _out.x = _b.v3.x;
        _out.y = _b.v3.y;

        float w = _b.v3.w;
        float w_inv = 1.f / w;

        _out.x *= w_inv;
        _out.y *= w_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v3_v2_m4_homogenize( vec3f & _out, const vec2f & _a, const mat4f & _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _b.v3.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _b.v3.y;
        _out.z = _a.x * _b.v0.z + _a.y * _b.v1.z + _b.v3.z;

        float w = _a.x * _b.v0.w + _a.y * _b.v1.w + _b.v3.w;
        float w_inv = 1.f / w;

        _out.x *= w_inv;
        _out.y *= w_inv;
        _out.z *= w_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f operator* ( const vec4f& v, const mat4f& m )
    {
        vec4f out;
        mul_v4_m4( out, v, m );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_m4( mat4f& _out, const mat4f& _a, const mat4f& _b )
    {
        MT_assert( &_out != &_a );
        MT_assert( &_out != &_b );

        mul_v4_m4( _out.v0, _a.v0, _b );
        mul_v4_m4( _out.v1, _a.v1, _b );
        mul_v4_m4( _out.v2, _a.v2, _b );
        mul_v4_m4( _out.v3, _a.v3, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_m4_r( mat4f& _out, const mat4f& _a, const mat4f& _b )
    {
        MT_assert( &_out != &_a );
        MT_assert( &_out != &_b );

        mul_v4_m4_r( _out.v0, _a.v0, _b );
        mul_v4_m4_r( _out.v1, _a.v1, _b );
        mul_v4_m4_r( _out.v2, _a.v2, _b );
        mul_v4_m4_r1( _out.v3, _a.v3, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_v4_m3_i( vec4f & _out, const vec4f & _a, const mat3f& _b )
    {
        _out.x = _a.x * _b.v0.x + _a.y * _b.v1.x + _a.z * _b.v2.x;
        _out.y = _a.x * _b.v0.y + _a.y * _b.v1.y + _a.z * _b.v2.y;
        _out.z = _a.x * _b.v0.z + _a.y * _b.v1.z + _a.z * _b.v2.z;
        _out.w = _a.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void mul_m4_m3( mat4f& _out, const mat4f& _a, const mat3f& _b )
    {
        MT_assert( &_out != &_a );

        mul_v4_m3_i( _out.v0, _a.v0, _b );
        mul_v4_m3_i( _out.v1, _a.v1, _b );
        mul_v4_m3_i( _out.v2, _a.v2, _b );
        mul_v4_m3_i( _out.v3, _a.v3, _b );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE mat4f operator* ( const mat4f& _a, const mat4f& _b )
    {
        mat4f out;
        mul_m4_m4( out, _a, _b );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE mat4f operator* ( const mat4f& _a, const mat3f& _b )
    {
        mat4f out;
        mul_m4_m3( out, _a, _b );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void add_m4_m4( mat4f& _out, const mat4f& _a, const mat4f& _b )
    {
        add_v4_v4( _out.v0, _a.v0, _b.v0 );
        add_v4_v4( _out.v1, _a.v1, _b.v1 );
        add_v4_v4( _out.v2, _a.v2, _b.v2 );
        add_v4_v4( _out.v3, _a.v3, _b.v3 );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE mat4f operator+( const mat4f& _a, const mat4f& _b )
    {
        mat4f out;
        add_m4_m4( out, _a, _b );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void sub_m4_m4( mat4f& _out, const mat4f& _a, const mat4f& _b )
    {
        sub_v4_v4( _out.v0, _a.v0, _b.v0 );
        sub_v4_v4( _out.v1, _a.v1, _b.v1 );
        sub_v4_v4( _out.v2, _a.v2, _b.v2 );
        sub_v4_v4( _out.v3, _a.v3, _b.v3 );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE mat4f operator-( const mat4f& _a, const mat4f& _b )
    {
        mat4f out;
        sub_m4_m4( out, _a, _b );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void scale_m4_m4( mat4f& _out, const mat4f& _rhs, const mt::vec4f & _val )
    {
        scale_v4_v4( _out.v0, _rhs.v0, _val.x );
        scale_v4_v4( _out.v1, _rhs.v1, _val.y );
        scale_v4_v4( _out.v2, _rhs.v2, _val.z );
        scale_v4_v4( _out.v3, _rhs.v3, _val.w );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void scale_m4( mat4f& _out, const mt::vec4f & _val )
    {
        scale_m4_m4( _out, _out, _val );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void scale_rotate_m4_m4( mat4f& _out, const mat4f& _rhs, const mt::vec3f & _val )
    {
        scale_v4_v4( _out.v0, _rhs.v0, _val.x );
        scale_v4_v4( _out.v1, _rhs.v1, _val.y );
        scale_v4_v4( _out.v2, _rhs.v2, _val.z );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void scale_rotate_m4( mat4f& _out, const mt::vec3f &_val )
    {
        scale_rotate_m4_m4( _out, _out, _val );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void zero_m4( mat4f& _out )
    {
        ident_v4( _out.v0 );
        ident_v4( _out.v1 );
        ident_v4( _out.v2 );
        ident_v4( _out.v3 );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void ident_m4( mat4f& _out )
    {
        _out.v0.x = 1.f;
        _out.v0.y = 0.f;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;
        _out.v1.x = 0.f;
        _out.v1.y = 1.f;
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;
        _out.v2.x = 0.f;
        _out.v2.y = 0.f;
        _out.v2.z = 1.f;
        _out.v2.w = 0.f;
        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = 0.f;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE bool is_ident_m34( const mat4f& _out )
    {
        return
            equal_f_1( _out.v0.x ) == true && equal_f_z( _out.v0.y ) == true && equal_f_z( _out.v0.z ) == true &&
            equal_f_z( _out.v1.x ) == true && equal_f_1( _out.v1.y ) == true && equal_f_z( _out.v1.z ) == true &&
            equal_f_z( _out.v2.x ) == true && equal_f_z( _out.v2.y ) == true && equal_f_1( _out.v2.z ) == true &&
            equal_f_z( _out.v3.x ) == true && equal_f_z( _out.v3.y ) == true && equal_f_z( _out.v3.z ) == true;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void get_col_m4( vec4f& out, const mat4f& _rhs, int _index )
    {
        out.x = _rhs.v0[_index];
        out.y = _rhs.v1[_index];
        out.z = _rhs.v2[_index];
        out.w = _rhs.v3[_index];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE vec4f get_col_m4( const mat4f& _rhs, int _index )
    {
        vec4f ret;
        get_col_m4( ret, _rhs, _index );
        return ret;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void set_col_m4( mat4f& out, const vec4f& _rhs, int _index )
    {
        out.v0[_index] = _rhs.x;
        out.v1[_index] = _rhs.y;
        out.v2[_index] = _rhs.z;
        out.v3[_index] = _rhs.w;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void transpose_m4( mat4f& _out, const mat4f& _rhs )
    {
        _out[0][0] = _rhs[0][0];
        _out[1][1] = _rhs[1][1];
        _out[2][2] = _rhs[2][2];
        _out[3][3] = _rhs[3][3];

        _out[1][0] = _rhs[0][1];
        _out[2][0] = _rhs[0][2];
        _out[2][1] = _rhs[1][2];
        _out[3][0] = _rhs[0][3];
        _out[3][1] = _rhs[1][3];
        _out[3][2] = _rhs[2][3];

        _out[0][1] = _rhs[1][0];
        _out[0][2] = _rhs[2][0];
        _out[1][2] = _rhs[2][1];
        _out[0][3] = _rhs[3][0];
        _out[1][3] = _rhs[3][1];
        _out[2][3] = _rhs[3][2];
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE mat4f transpose_m4( const mat4f& _rhs )
    {
        mat4f out;
        transpose_m4( out, _rhs );
        return out;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void extract_m4_m3( mat3f& _out, const mat4f& _rhs )
    {
        extract_v4_v3( _out.v0, _rhs.v0 );
        extract_v4_v3( _out.v1, _rhs.v1 );
        extract_v4_v3( _out.v2, _rhs.v2 );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void inv_m4_m4( mat4f & _out, const mat4f & _in )
    {
        float v0x = _in.v1.y  * _in.v2.z * _in.v3.w -
            _in.v1.y  * _in.v2.w * _in.v3.z -
            _in.v2.y  * _in.v1.z  * _in.v3.w +
            _in.v2.y  * _in.v1.w  * _in.v3.z +
            _in.v3.y * _in.v1.z  * _in.v2.w -
            _in.v3.y * _in.v1.w  * _in.v2.z;

        float v1x = -_in.v1.x  * _in.v2.z * _in.v3.w +
            _in.v1.x  * _in.v2.w * _in.v3.z +
            _in.v2.x  * _in.v1.z  * _in.v3.w -
            _in.v2.x  * _in.v1.w  * _in.v3.z -
            _in.v3.x * _in.v1.z  * _in.v2.w +
            _in.v3.x * _in.v1.w  * _in.v2.z;

        float v2x = _in.v1.x  * _in.v2.y * _in.v3.w -
            _in.v1.x  * _in.v2.w * _in.v3.y -
            _in.v2.x  * _in.v1.y * _in.v3.w +
            _in.v2.x  * _in.v1.w * _in.v3.y +
            _in.v3.x * _in.v1.y * _in.v2.w -
            _in.v3.x * _in.v1.w * _in.v2.y;

        float v3x = -_in.v1.x  * _in.v2.y * _in.v3.z +
            _in.v1.x  * _in.v2.z * _in.v3.y +
            _in.v2.x  * _in.v1.y * _in.v3.z -
            _in.v2.x  * _in.v1.z * _in.v3.y -
            _in.v3.x * _in.v1.y * _in.v2.z +
            _in.v3.x * _in.v1.z * _in.v2.y;

        float v0y = -_in.v0.y  * _in.v2.z * _in.v3.w +
            _in.v0.y  * _in.v2.w * _in.v3.z +
            _in.v2.y  * _in.v0.z * _in.v3.w -
            _in.v2.y  * _in.v0.w * _in.v3.z -
            _in.v3.y * _in.v0.z * _in.v2.w +
            _in.v3.y * _in.v0.w * _in.v2.z;

        float v1y = _in.v0.x  * _in.v2.z * _in.v3.w -
            _in.v0.x  * _in.v2.w * _in.v3.z -
            _in.v2.x  * _in.v0.z * _in.v3.w +
            _in.v2.x  * _in.v0.w * _in.v3.z +
            _in.v3.x * _in.v0.z * _in.v2.w -
            _in.v3.x * _in.v0.w * _in.v2.z;

        float v2y = -_in.v0.x  * _in.v2.y * _in.v3.w +
            _in.v0.x  * _in.v2.w * _in.v3.y +
            _in.v2.x  * _in.v0.y * _in.v3.w -
            _in.v2.x  * _in.v0.w * _in.v3.y -
            _in.v3.x * _in.v0.y * _in.v2.w +
            _in.v3.x * _in.v0.w * _in.v2.y;

        float v3y = _in.v0.x  * _in.v2.y * _in.v3.z -
            _in.v0.x  * _in.v2.z * _in.v3.y -
            _in.v2.x  * _in.v0.y * _in.v3.z +
            _in.v2.x  * _in.v0.z * _in.v3.y +
            _in.v3.x * _in.v0.y * _in.v2.z -
            _in.v3.x * _in.v0.z * _in.v2.y;

        float v0z = _in.v0.y  * _in.v1.z * _in.v3.w -
            _in.v0.y  * _in.v1.w * _in.v3.z -
            _in.v1.y  * _in.v0.z * _in.v3.w +
            _in.v1.y  * _in.v0.w * _in.v3.z +
            _in.v3.y * _in.v0.z * _in.v1.w -
            _in.v3.y * _in.v0.w * _in.v1.z;

        float v1z = -_in.v0.x  * _in.v1.z * _in.v3.w +
            _in.v0.x  * _in.v1.w * _in.v3.z +
            _in.v1.x  * _in.v0.z * _in.v3.w -
            _in.v1.x  * _in.v0.w * _in.v3.z -
            _in.v3.x * _in.v0.z * _in.v1.w +
            _in.v3.x * _in.v0.w * _in.v1.z;

        float v2z = _in.v0.x  * _in.v1.y * _in.v3.w -
            _in.v0.x  * _in.v1.w * _in.v3.y -
            _in.v1.x  * _in.v0.y * _in.v3.w +
            _in.v1.x  * _in.v0.w * _in.v3.y +
            _in.v3.x * _in.v0.y * _in.v1.w -
            _in.v3.x * _in.v0.w * _in.v1.y;

        float v3z = -_in.v0.x  * _in.v1.y * _in.v3.z +
            _in.v0.x  * _in.v1.z * _in.v3.y +
            _in.v1.x  * _in.v0.y * _in.v3.z -
            _in.v1.x  * _in.v0.z * _in.v3.y -
            _in.v3.x * _in.v0.y * _in.v1.z +
            _in.v3.x * _in.v0.z * _in.v1.y;

        float v0w = -_in.v0.y * _in.v1.z * _in.v2.w +
            _in.v0.y * _in.v1.w * _in.v2.z +
            _in.v1.y * _in.v0.z * _in.v2.w -
            _in.v1.y * _in.v0.w * _in.v2.z -
            _in.v2.y * _in.v0.z * _in.v1.w +
            _in.v2.y * _in.v0.w * _in.v1.z;

        float v1w = _in.v0.x * _in.v1.z * _in.v2.w -
            _in.v0.x * _in.v1.w * _in.v2.z -
            _in.v1.x * _in.v0.z * _in.v2.w +
            _in.v1.x * _in.v0.w * _in.v2.z +
            _in.v2.x * _in.v0.z * _in.v1.w -
            _in.v2.x * _in.v0.w * _in.v1.z;

        float v2w = -_in.v0.x * _in.v1.y * _in.v2.w +
            _in.v0.x * _in.v1.w * _in.v2.y +
            _in.v1.x * _in.v0.y * _in.v2.w -
            _in.v1.x * _in.v0.w * _in.v2.y -
            _in.v2.x * _in.v0.y * _in.v1.w +
            _in.v2.x * _in.v0.w * _in.v1.y;

        float v3w = _in.v0.x * _in.v1.y * _in.v2.z -
            _in.v0.x * _in.v1.z * _in.v2.y -
            _in.v1.x * _in.v0.y * _in.v2.z +
            _in.v1.x * _in.v0.z * _in.v2.y +
            _in.v2.x * _in.v0.y * _in.v1.z -
            _in.v2.x * _in.v0.z * _in.v1.y;

        float det = _in.v0.x * v0x + _in.v0.y * v1x + _in.v0.z * v2x + _in.v0.w * v3x;

        if( det == 0.f )
        {
            mt::ident_m4( _out );

            return;
        }

        float det_inv = 1.f / det;

        _out.v0.x = v0x * det_inv;
        _out.v0.y = v0y * det_inv;
        _out.v0.z = v0z * det_inv;
        _out.v0.w = v0w * det_inv;
        _out.v1.x = v1x * det_inv;
        _out.v1.y = v1y * det_inv;
        _out.v1.z = v1z * det_inv;
        _out.v1.w = v1w * det_inv;
        _out.v2.x = v2x * det_inv;
        _out.v2.y = v2y * det_inv;
        _out.v2.z = v2z * det_inv;
        _out.v2.w = v2w * det_inv;
        _out.v3.x = v3x * det_inv;
        _out.v3.y = v3y * det_inv;
        _out.v3.z = v3z * det_inv;
        _out.v3.w = v3w * det_inv;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE mat4f inv_m4( const mat4f& _rhs )
    {
        mat4f out;
        inv_m4_m4( out, _rhs );
        return out;
    }

    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void rotate_axis_m4( mat4f &out, const vec3f &u, float degrees )
    {
        float c = MT_cosf( degrees );
        float s = MT_sinf( degrees );
        float ic = 1.f - c;

        float icux = ic * u.x;
        float icuxy = icux * u.y;
        float icuxz = icux * u.z;
        float icuyz = ic * u.y*u.z;

        float suy = s * u.y;
        float suz = s * u.z;
        float sux = s * u.x;

        mat3f m;

        m[0][0] = c + ic * u.x*u.x; m[0][1] = icuxy - suz; m[0][2] = icuxz + suy;
        m[1][0] = icuxy + suz; m[1][1] = c + ic * u.y*u.y; m[1][2] = icuyz - sux;
        m[2][0] = icuxz - suy; m[2][1] = icuyz + sux; m[2][2] = c + ic * u.z*u.z;

        out = out * m;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_projection_ortho_lh_m4( mat4f & _out, float _left, float _right, float _top, float _bottom, float _near, float _far )
    {
        // 2/(r-l)      0            0           0
        _out.v0.x = 2.f / (_right - _left);
        _out.v0.y = 0.f;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        //0            2/(t-b)      0           0
        _out.v1.x = 0.f;
        _out.v1.y = 2.f / (_top - _bottom);
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        //0            0            1/(zf-zn)   0
        _out.v2.x = 0.f;
        _out.v2.y = 0.f;
        _out.v2.z = 1.f / (_far - _near);
        _out.v2.w = 0.f;

        //(l+r)/(l-r)  (t+b)/(b-t)  zn/(zn-zf)  1
        _out.v3.x = (_left + _right) / (_left - _right);
        _out.v3.y = (_bottom + _top) / (_bottom - _top);
        _out.v3.z = _near / (_near - _far);
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_projection_frustum_m4( mat4f & _out, float _left, float _right, float _top, float _bottom, float _near, float _far )
    {
        //2*zn/(r-l)   0            0              0
        //0            2*zn/(t-b)   0              0
        //(l+r)/(l-r)  (t+b)/(b-t)  zf/(zf-zn)     1
        //0            0            zn*zf/(zn-zf)  0

        _out.v0.x = 2.f * _near / (_right - _left);
        _out.v0.y = 0.f;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        _out.v1.x = 0.f;
        _out.v1.y = 2.f * _near / (_top - _bottom);
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        _out.v2.x = (_left + _right) / (_left - _right);
        _out.v2.y = (_top + _bottom) / (_bottom - _top);
        _out.v2.z = (_far) / (_far - _near);
        _out.v2.w = 1.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = (_near * _far) / (_near - _far);
        _out.v3.w = 0.f;
    }

    MT_FUNCTION_INLINE void make_projection_fov_m4( mat4f & _out, float _fov, float _aspect, float _zn, float _zf )
    {
        float yscale = 1.f / MT_tanf( _fov * 0.5f );
        float xscale = yscale / _aspect;

        _out.v0.x = xscale;
        _out.v0.y = 0.f;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        _out.v1.x = 0.f;
        _out.v1.y = yscale;
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        _out.v2.x = 0.f;
        _out.v2.y = 0.f;
        _out.v2.z = _zf / (_zf - _zn);
        _out.v2.w = 1.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = -_zn * _zf / (_zf - _zn);
        _out.v3.w = 0.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_projection_fov2_m4( mat4f & _out, float _fov, float _aspect, float _zn, float _zf )
    {
        float yscale = 1.f / MT_tanf( _fov * 0.5f );
        float xscale = yscale / _aspect;

        _out.v0.x = xscale;
        _out.v0.y = 0.f;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        _out.v1.x = 0.f;
        _out.v1.y = yscale;
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        _out.v2.x = 0.f;
        _out.v2.y = 0.f;
        _out.v2.z = -(_zf + _zn) / (_zf - _zn);
        _out.v2.w = -1.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = -2.f * _zn * _zf / (_zf - _zn);
        _out.v3.w = 0.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_rotate_m4_euler( mat4f & _out, float _x, float _y, float _z )
    {
        float ca = MT_cosf( _x );
        float cb = MT_cosf( _y );
        float cy = MT_cosf( _z );

        float sa = MT_sinf( _x );
        float sb = MT_sinf( _y );
        float sy = MT_sinf( _z );

        _out.v0.x = ca * cb;
        _out.v0.y = ca * sb * sy - sa * cy;
        _out.v0.z = ca * sb * cy + sa * sy;
        _out.v0.w = 0.f;

        _out.v1.x = sa * cb;
        _out.v1.y = sa * sb * sy + ca * cy;
        _out.v1.z = sa * sb * cy - ca * sy;
        _out.v1.w = 0.f;

        _out.v2.x = -sb;
        _out.v2.y = cb * sy;
        _out.v2.z = cb * cy;
        _out.v2.w = 0.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = 0.f;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_rotate_m4_direction( mat4f & _out, const vec3f & _direction, const vec3f & _up )
    {
        vec3f xaxis;
        mt::norm_v3_v3( xaxis, _direction );

        vec3f yaxis;
        mt::cross_v3_v3_norm( yaxis, _up, xaxis );

        vec3f zaxis;
        mt::cross_v3_v3_norm( zaxis, xaxis, yaxis );

        mt::make_rotate_m4_axes( _out, xaxis, yaxis, zaxis );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_rotate_m4_fixed_up( mat4f & _out, const vec3f & _direction, const vec3f & _up )
    {
        vec3f zaxis;
        mt::norm_v3_v3( zaxis, _up );

        vec3f yaxis;
        mt::cross_v3_v3_norm( yaxis, zaxis, _direction );

        vec3f xaxis;
        mt::cross_v3_v3_norm( xaxis, yaxis, zaxis );

        mt::make_rotate_m4_axes( _out, xaxis, yaxis, zaxis );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_rotate_m4_fixed_left( mat4f & _out, const vec3f & _direction, const vec3f & _left )
    {
        vec3f yaxis;
        mt::norm_v3_v3( yaxis, _left );

        vec3f zaxis;
        mt::cross_v3_v3_norm( zaxis, _direction, yaxis );

        vec3f xaxis;
        mt::cross_v3_v3_norm( xaxis, yaxis, zaxis );

        mt::make_rotate_m4_axes( _out, xaxis, yaxis, zaxis );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_rotate_m4_axes( mat4f & _out, const vec3f & _direction, const vec3f & _left, const vec3f & _up )
    {
        _out.v0.x = _direction.x;
        _out.v0.y = _direction.y;
        _out.v0.z = _direction.z;
        _out.v0.w = 0.f;

        _out.v1.x = _left.x;
        _out.v1.y = _left.y;
        _out.v1.z = _left.z;
        _out.v1.w = 0.f;

        _out.v2.x = _up.x;
        _out.v2.y = _up.y;
        _out.v2.z = _up.z;
        _out.v2.w = 0.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = 0.f;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_rotate_x_axis_m4( mat4f & _out, float _angle )
    {
        float cosa = MT_cosf( _angle );
        float sina = MT_sinf( _angle );

        _out.v0.x = 1.f;
        _out.v0.y = 0.f;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        _out.v1.x = 0.f;
        _out.v1.y = cosa;
        _out.v1.z = -sina;
        _out.v1.w = 0.f;

        _out.v2.x = 0.f;
        _out.v2.y = sina;
        _out.v2.z = cosa;
        _out.v2.w = 0.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = 0.f;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_rotate_y_axis_m4( mat4f & _out, float _angle )
    {
        float cosa = MT_cosf( _angle );
        float sina = MT_sinf( _angle );

        _out.v0.x = cosa;
        _out.v0.y = 0.f;
        _out.v0.z = sina;
        _out.v0.w = 0.f;

        _out.v1.x = 0.f;
        _out.v1.y = 1.f;
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        _out.v2.x = -sina;
        _out.v2.y = 0.f;
        _out.v2.z = cosa;
        _out.v2.w = 0.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = 0.f;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_rotate_z_axis_m4( mat4f & _out, float _angle )
    {
        float cosa = MT_cosf( _angle );
        float sina = MT_sinf( _angle );

        _out.v0.x = cosa;
        _out.v0.y = -sina;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        _out.v1.x = sina;
        _out.v1.y = cosa;
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        _out.v2.x = 0.f;
        _out.v2.y = 0.f;
        _out.v2.z = 1.f;
        _out.v2.w = 0.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = 0.f;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_skew_m4( mat4f & _out, float _x, float _y )
    {
        _out.v0.x = 1.f;
        _out.v0.y = _y;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        _out.v1.x = _x;
        _out.v1.y = 1.f;
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        _out.v2.x = 0.f;
        _out.v2.y = 0.f;
        _out.v2.z = 1.f;
        _out.v2.w = 0.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = 0.f;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_scale_m4( mat4f & _out, float _x, float _y, float _z )
    {
        _out.v0.x = _x;
        _out.v0.y = 0.f;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        _out.v1.x = 0.f;
        _out.v1.y = _y;
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        _out.v2.x = 0.f;
        _out.v2.y = 0.f;
        _out.v2.z = _z;
        _out.v2.w = 0.f;

        _out.v3.x = 0.f;
        _out.v3.y = 0.f;
        _out.v3.z = 0.f;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_translation_m4_v3( mat4f & _out, const mt::vec3f & _pos )
    {
        make_translation_m4( _out, _pos.x, _pos.y, _pos.z );
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_translation_m4( mat4f & _out, float _x, float _y, float _z )
    {
        _out.v0.x = 1.f;
        _out.v0.y = 0.f;
        _out.v0.z = 0.f;
        _out.v0.w = 0.f;

        _out.v1.x = 0.f;
        _out.v1.y = 1.f;
        _out.v1.z = 0.f;
        _out.v1.w = 0.f;

        _out.v2.x = 0.f;
        _out.v2.y = 0.f;
        _out.v2.z = 1.f;
        _out.v2.w = 0.f;

        _out.v3.x = _x;
        _out.v3.y = _y;
        _out.v3.z = _z;
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_lookat_m4( mat4f & _out, const vec3f & _eye, const vec3f & _dir, const vec3f & _up, float _sign )
    {
        vec3f zaxis;
        norm_v3_v3( zaxis, _dir );

        vec3f xaxis;
        cross_v3_v3_norm( xaxis, _up, zaxis );

        vec3f yaxis;
        cross_v3_v3( yaxis, zaxis, xaxis );

        xaxis *= _sign;

        //yaxis = cross(zaxis, xaxis)
        //vec3f yaxis;
        //cross_v3_v3( yaxis, zaxis, xaxis );

        //xaxis.x           yaxis.x           zaxis.x          0
        //xaxis.y           yaxis.y           zaxis.y          0
        //xaxis.z           yaxis.z           zaxis.z          0
        //-dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)  l
        _out.v0.x = xaxis.x;
        _out.v0.y = yaxis.x;
        _out.v0.z = zaxis.x;
        _out.v0.w = 0.f;

        _out.v1.x = xaxis.y;
        _out.v1.y = yaxis.y;
        _out.v1.z = zaxis.y;
        _out.v1.w = 0.f;

        _out.v2.x = xaxis.z;
        _out.v2.y = yaxis.z;
        _out.v2.z = zaxis.z;
        _out.v2.w = 0.f;

        _out.v3.x = -dot_v3_v3( xaxis, _eye );
        _out.v3.y = -dot_v3_v3( yaxis, _eye );
        _out.v3.z = -dot_v3_v3( zaxis, _eye );
        _out.v3.w = 1.f;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void project_m4( vec3f & _out, const vec3f & _vertex, float _width, float _height, const mat4f & _projection, const mat4f & _view, const mat4f & _world )
    {
        mat4f m1;
        mat4f m2;

        vec3f vec;
        vec3f vec_i;

        mul_m4_m4( m1, _world, _view );
        mul_m4_m4( m2, m1, _projection );
        mul_v3_v3_m4_proj( vec, _vertex, m2 );

        _out.x = (1.0f + vec.x) * _width * 0.5f;
        _out.y = (1.0f + vec.y) * _height * 0.5f;
        _out.z = vec.z;
    }
    //////////////////////////////////////////////////////////////////////////
    MT_FUNCTION_INLINE void make_euler_angles( mt::vec3f & _euler, const mat4f & _rotate )
    {
        float sinY = _rotate.v2.x;

        float x;
        float y;
        float z;

        float fsinY = MT_fabsf( sinY );

        if( mt::equal_f_f( fsinY, 1.f ) == true )
        {
            x = 0.f;

            if( mt::equal_f_f( sinY, -1.f ) == true )
            {
                y = x + MT_atan2f( _rotate.v0.y, _rotate.v0.z );
                z = constant::half_pi;

            }
            else
            {
                y = -x + MT_atan2f( -_rotate.v0.y, -_rotate.v0.z );
                z = -constant::half_pi;
            }
        }
        else if( mt::equal_f_f( sinY, 0.f ) == true )
        {
            x = MT_atan2f( _rotate.v1.x, _rotate.v0.x );
            y = 0.f;
            z = MT_atan2f( _rotate.v2.y, _rotate.v2.z );

        }
        else
        {
            y = -MT_asinf( sinY );
            float cosY = MT_cosf( y );
            float one_div_cosY = 1.f / cosY;

            x = MT_atan2f( _rotate.v1.x * one_div_cosY, _rotate.v0.x * one_div_cosY );
            z = MT_atan2f( _rotate.v2.y * one_div_cosY, _rotate.v2.z * one_div_cosY );
        }

        _euler.x = x;
        _euler.y = y;
        _euler.z = z;
    }
}
