#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// float3
	//=========================================================
    float3::float3(const bool3& v)          {   x = v.x ? 1.0f : 0.0f;  y = v.y ? 1.0f : 0.0f;  z = v.z ? 1.0f : 0.0f;  }
    float3::float3(const uint3& v)          {   x = (float)v.x;         y = (float)v.y;         z = (float)v.z;         }
    float3::float3(const int3& v)           {   x = (float)v.x;         y = (float)v.y;         z = (float)v.z;         }
    //float3::float3(const half3& v)        {   x = (float)v.x;         y = (float)v.y;         z = (float)v.z;         }
    float3::float3(const float3& v)         {   x = v.x;                y = v.y;                z = v.z;                }
    float3::float3(const double3& v)        {   x = (float)v.x;         y = (float)v.y;         z = (float)v.z;         }


    float4 float3::xxxx()   const           { return float4(x, x, x, x); }
    float4 float3::xxxy()   const           { return float4(x, x, x, y); }
    float4 float3::xxxz()   const           { return float4(x, x, x, z); }
    float4 float3::xxyx()   const           { return float4(x, x, y, x); }
    float4 float3::xxyy()   const           { return float4(x, x, y, y); }
    float4 float3::xxyz()   const           { return float4(x, x, y, z); }
    float4 float3::xxzx()   const           { return float4(x, x, z, x); }
    float4 float3::xxzy()   const           { return float4(x, x, z, y); }
    float4 float3::xxzz()   const           { return float4(x, x, z, z); }
    float4 float3::xyxx()   const           { return float4(x, y, x, x); }
    float4 float3::xyxy()   const           { return float4(x, y, x, y); }
    float4 float3::xyxz()   const           { return float4(x, y, x, z); }
    float4 float3::xyyx()   const           { return float4(x, y, y, x); }
    float4 float3::xyyy()   const           { return float4(x, y, y, y); }
    float4 float3::xyyz()   const           { return float4(x, y, y, z); }
    float4 float3::xyzx()   const           { return float4(x, y, z, x); }
    float4 float3::xyzy()   const           { return float4(x, y, z, y); }
    float4 float3::xyzz()   const           { return float4(x, y, z, z); }
    float4 float3::xzxx()   const           { return float4(x, z, x, x); }
    float4 float3::xzxy()   const           { return float4(x, z, x, y); }
    float4 float3::xzxz()   const           { return float4(x, z, x, z); }
    float4 float3::xzyx()   const           { return float4(x, z, y, x); }
    float4 float3::xzyy()   const           { return float4(x, z, y, y); }
    float4 float3::xzyz()   const           { return float4(x, z, y, z); }
    float4 float3::xzzx()   const           { return float4(x, z, z, x); }
    float4 float3::xzzy()   const           { return float4(x, z, z, y); }
    float4 float3::xzzz()   const           { return float4(x, z, z, z); }
    float4 float3::yxxx()   const           { return float4(y, x, x, x); }
    float4 float3::yxxy()   const           { return float4(y, x, x, y); }
    float4 float3::yxxz()   const           { return float4(y, x, x, z); }
    float4 float3::yxyx()   const           { return float4(y, x, y, x); }
    float4 float3::yxyy()   const           { return float4(y, x, y, y); }
    float4 float3::yxyz()   const           { return float4(y, x, y, z); }
    float4 float3::yxzx()   const           { return float4(y, x, z, x); }
    float4 float3::yxzy()   const           { return float4(y, x, z, y); }
    float4 float3::yxzz()   const           { return float4(y, x, z, z); }
    float4 float3::yyxx()   const           { return float4(y, y, x, x); }
    float4 float3::yyxy()   const           { return float4(y, y, x, y); }
    float4 float3::yyxz()   const           { return float4(y, y, x, z); }
    float4 float3::yyyx()   const           { return float4(y, y, y, x); }
    float4 float3::yyyy()   const           { return float4(y, y, y, y); }
    float4 float3::yyyz()   const           { return float4(y, y, y, z); }
    float4 float3::yyzx()   const           { return float4(y, y, z, x); }
    float4 float3::yyzy()   const           { return float4(y, y, z, y); }
    float4 float3::yyzz()   const           { return float4(y, y, z, z); }
    float4 float3::yzxx()   const           { return float4(y, z, x, x); }
    float4 float3::yzxy()   const           { return float4(y, z, x, y); }
    float4 float3::yzxz()   const           { return float4(y, z, x, z); }
    float4 float3::yzyx()   const           { return float4(y, z, y, x); }
    float4 float3::yzyy()   const           { return float4(y, z, y, y); }
    float4 float3::yzyz()   const           { return float4(y, z, y, z); }
    float4 float3::yzzx()   const           { return float4(y, z, z, x); }
    float4 float3::yzzy()   const           { return float4(y, z, z, y); }
    float4 float3::yzzz()   const           { return float4(y, z, z, z); }
    float4 float3::zxxx()   const           { return float4(z, x, x, x); }
    float4 float3::zxxy()   const           { return float4(z, x, x, y); }
    float4 float3::zxxz()   const           { return float4(z, x, x, z); }
    float4 float3::zxyx()   const           { return float4(z, x, y, x); }
    float4 float3::zxyy()   const           { return float4(z, x, y, y); }
    float4 float3::zxyz()   const           { return float4(z, x, y, z); }
    float4 float3::zxzx()   const           { return float4(z, x, z, x); }
    float4 float3::zxzy()   const           { return float4(z, x, z, y); }
    float4 float3::zxzz()   const           { return float4(z, x, z, z); }
    float4 float3::zyxx()   const           { return float4(z, y, x, x); }
    float4 float3::zyxy()   const           { return float4(z, y, x, y); }
    float4 float3::zyxz()   const           { return float4(z, y, x, z); }
    float4 float3::zyyx()   const           { return float4(z, y, y, x); }
    float4 float3::zyyy()   const           { return float4(z, y, y, y); }
    float4 float3::zyyz()   const           { return float4(z, y, y, z); }
    float4 float3::zyzx()   const           { return float4(z, y, z, x); }
    float4 float3::zyzy()   const           { return float4(z, y, z, y); }
    float4 float3::zyzz()   const           { return float4(z, y, z, z); }
    float4 float3::zzxx()   const           { return float4(z, z, x, x); }
    float4 float3::zzxy()   const           { return float4(z, z, x, y); }
    float4 float3::zzxz()   const           { return float4(z, z, x, z); }
    float4 float3::zzyx()   const           { return float4(z, z, y, x); }
    float4 float3::zzyy()   const           { return float4(z, z, y, y); }
    float4 float3::zzyz()   const           { return float4(z, z, y, z); }
    float4 float3::zzzx()   const           { return float4(z, z, z, x); }
    float4 float3::zzzy()   const           { return float4(z, z, z, y); }
    float4 float3::zzzz()   const           { return float4(z, z, z, z); }
    float3 float3::xxx()    const           { return float3(x, x, x); }
    float3 float3::xxy()    const           { return float3(x, x, y); }
    float3 float3::xxz()    const           { return float3(x, x, z); }
    float3 float3::xyx()    const           { return float3(x, y, x); }
    float3 float3::xyy()    const           { return float3(x, y, y); }
    float3 float3::xyz()    const           { return float3(x, y, z); }
    void   float3::xyz(const float3& v)     { x = v.x; y = v.y; z = v.z; }
    float3 float3::xzx()    const           { return float3(x, z, x); }
    float3 float3::xzy()    const           { return float3(x, z, y); }
    void   float3::xzy(const float3& v)     { x = v.x; z = v.y; y = v.z; }
    float3 float3::xzz()    const           { return float3(x, z, z); }
    float3 float3::yxx()    const           { return float3(y, x, x); }
    float3 float3::yxy()    const           { return float3(y, x, y); }
    float3 float3::yxz()    const           { return float3(y, x, z); }
    void   float3::yxz(const float3& v)     { y = v.x; x = v.y; z = v.z; }
    float3 float3::yyx()    const           { return float3(y, y, x); }
    float3 float3::yyy()    const           { return float3(y, y, y); }
    float3 float3::yyz()    const           { return float3(y, y, z); }
    float3 float3::yzx()    const           { return float3(y, z, x); }
    void   float3::yzx(const float3& v)     { y = v.x; z = v.y; x = v.z; }
    float3 float3::yzy()    const           { return float3(y, z, y); }
    float3 float3::yzz()    const           { return float3(y, z, z); }
    float3 float3::zxx()    const           { return float3(z, x, x); }
    float3 float3::zxy()    const           { return float3(z, x, y); }
    void   float3::zxy(const float3& v)     { z = v.x; x = v.y; y = v.z; }
    float3 float3::zxz()    const           { return float3(z, x, z); }
    float3 float3::zyx()    const           { return float3(z, y, x); }
    void   float3::zyx(const float3& v)     { z = v.x; y = v.y; x = v.z; }
    float3 float3::zyy()    const           { return float3(z, y, y); }
    float3 float3::zyz()    const           { return float3(z, y, z); }
    float3 float3::zzx()    const           { return float3(z, z, x); }
    float3 float3::zzy()    const           { return float3(z, z, y); }
    float3 float3::zzz()    const           { return float3(z, z, z); }
    float2 float3::xx()     const           { return float2(x, x); }
    float2 float3::xy()     const           { return float2(x, y); }
    void   float3::xy(const float2& v)      { x = v.x; y = v.y; }
    float2 float3::xz()     const           { return float2(x, z); }
    void   float3::xz(const float2& v)      { x = v.x; z = v.y; }
    float2 float3::yx()     const           { return float2(y, x); }
    void   float3::yx(const float2& v)      { y = v.x; x = v.y; }
    float2 float3::yy()     const           { return float2(y, y); }
    float2 float3::yz()     const           { return float2(y, z); }
    void   float3::yz(const float2& v)      { y = v.x; z = v.y; }
    float2 float3::zx()     const           { return float2(z, x); }
    void   float3::zx(const float2& v)      { z = v.x; x = v.y; }
    float2 float3::zy()     const           { return float2(z, y); }
    void   float3::zy(const float2& v)      { z = v.x; y = v.y; }
    float2 float3::zz()     const           { return float2(z, z); }

	//=========================================================
	// float3x2
	//=========================================================
    float3x2::float3x2(bool v)
	{
		c0 = math::select(float3(0.0f), float3(1.0f), v);
		c1 = math::select(float3(0.0f), float3(1.0f), v);
	}
	float3x2::float3x2(const bool3x2& v)
	{
		c0 = math::select(float3(0.0f), float3(1.0f), v.c0);
		c1 = math::select(float3(0.0f), float3(1.0f), v.c1);
	}
    float3x2::float3x2(const uint3x2& v)		{   c0 = v.c0;			c1 = v.c1;          }
    float3x2::float3x2(const int3x2& v)         {   c0 = v.c0;          c1 = v.c1;          }
    float3x2::float3x2(const float3x2& v)	    {   c0 = v.c0;          c1 = v.c1;		    }
    float3x2::float3x2(const double3x2& v)      {   c0 = (float3)v.c0;  c1 = (float3)v.c1;  }


	//=========================================================
	// float3x3
	//=========================================================
	/// <summary>Constructs a float3x3 matrix from a single bool value by converting it to float and assigning it to every component.</summary>
    /// <param name="v">bool to convert to float3x3</param>
    float3x3::float3x3(bool v)
    {
        c0 = math::select(float3(0.0f), float3(1.0f), v);
        c1 = math::select(float3(0.0f), float3(1.0f), v);
        c2 = math::select(float3(0.0f), float3(1.0f), v);
    }
    float3x3::float3x3(const bool3x3& v)
    {
        c0 = math::select(float3(0.0f), float3(1.0f), v.c0);
        c1 = math::select(float3(0.0f), float3(1.0f), v.c1);
        c2 = math::select(float3(0.0f), float3(1.0f), v.c2);
    }
    float3x3::float3x3(const uint3x3& v)    { c0 = v.c0;	        c1 = v.c1;	        c2 = v.c2; }
    float3x3::float3x3(const int3x3& v)     { c0 = v.c0;	        c1 = v.c1;	        c2 = v.c2; }
    float3x3::float3x3(const float3x3& v)   { c0 = v.c0;	        c1 = v.c1;	        c2 = v.c2; }
    float3x3::float3x3(const double3x3& v)  { c0 = (float3)v.c0;	c1 = (float3)v.c1;	c2 = (float3)v.c2; }

    //=========================================================
    // float3x3 matrix
    //=========================================================
    float3x3::float3x3(const float4x4& f4x4)
    {
        c0 = f4x4.c0.xyz();
        c1 = f4x4.c1.xyz();
        c2 = f4x4.c2.xyz();
    }
    float3x3::float3x3(const quaternion& q)
    {
        float4 v = q.value;
        float4 v2 = v + v;

        uint3 npn = uint3(0x80000000, 0x00000000, 0x80000000);
        uint3 nnp = uint3(0x80000000, 0x80000000, 0x00000000);
        uint3 pnn = uint3(0x00000000, 0x80000000, 0x80000000);
        c0 = v2.y * math::asfloat(math::asuint(v.yxw()) ^ npn) - v2.z * math::asfloat(math::asuint(v.zwx()) ^ pnn) + float3(1, 0, 0);
        c1 = v2.z * math::asfloat(math::asuint(v.wzy()) ^ nnp) - v2.x * math::asfloat(math::asuint(v.yxw()) ^ npn) + float3(0, 1, 0);
        c2 = v2.x * math::asfloat(math::asuint(v.zwx()) ^ pnn) - v2.y * math::asfloat(math::asuint(v.wzy()) ^ nnp) + float3(0, 0, 1);
    }
    float3x3 float3x3::AxisAngle(const float3& axis, float angle)
    {
        float sina, cosa;
        math::sincos(angle, OUT sina, OUT cosa);

        float3 u = axis;
        float3 u_yzx = u.yzx();
        float3 u_zxy = u.zxy();
        float3 u_inv_cosa = u - u * cosa;  // u * (1.0f - cosa);
        float4 t = float4(u * sina, cosa);

        uint3 ppn = uint3(0x00000000, 0x00000000, 0x80000000);
        uint3 npp = uint3(0x80000000, 0x00000000, 0x00000000);
        uint3 pnp = uint3(0x00000000, 0x80000000, 0x00000000);

        return float3x3(
            u.x * u_inv_cosa + math::asfloat(math::asuint(t.wzy()) ^ ppn),
            u.y * u_inv_cosa + math::asfloat(math::asuint(t.zwx()) ^ npp),
            u.z * u_inv_cosa + math::asfloat(math::asuint(t.yxw()) ^ pnp)
        );
        /*
        return float3x3(
            cosa + u.x * u.x * (1.0f - cosa),       u.y * u.x * (1.0f - cosa) - u.z * sina, u.z * u.x * (1.0f - cosa) + u.y * sina,
            u.x * u.y * (1.0f - cosa) + u.z * sina, cosa + u.y * u.y * (1.0f - cosa),       u.y * u.z * (1.0f - cosa) - u.x * sina,
            u.x * u.z * (1.0f - cosa) - u.y * sina, u.y * u.z * (1.0f - cosa) + u.x * sina, cosa + u.z * u.z * (1.0f - cosa)
            );
            */
    }
    float3x3 float3x3::EulerXYZ(const float3& xyz)
    {
        // return mul(rotateZ(xyz.z), mul(rotateY(xyz.y), rotateX(xyz.x)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float3x3(
            c.y * c.z, c.z * s.x * s.y - c.x * s.z, c.x * c.z * s.y + s.x * s.z,
            c.y * s.z, c.x * c.z + s.x * s.y * s.z, c.x * s.y * s.z - c.z * s.x,
            -s.y,      c.y * s.x,                   c.x * c.y
        );
    }
    float3x3 float3x3::EulerXZY(const float3& xyz)
    {
        // return mul(rotateY(xyz.y), mul(rotateZ(xyz.z), rotateX(xyz.x))); }
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float3x3(
            c.y * c.z,  s.x * s.y - c.x * c.y * s.z,    c.x * s.y + c.y * s.x * s.z,
            s.z,        c.x * c.z,                      -c.z * s.x,
            -c.z * s.y, c.y * s.x + c.x * s.y * s.z,    c.x * c.y - s.x * s.y * s.z
        );
    }
    float3x3 float3x3::EulerYXZ(const float3& xyz)
    {
        // return mul(rotateZ(xyz.z), mul(rotateX(xyz.x), rotateY(xyz.y)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float3x3(
            c.y * c.z - s.x * s.y * s.z,    -c.x * s.z,     c.z * s.y + c.y * s.x * s.z,
            c.z * s.x * s.y + c.y * s.z,    c.x * c.z,      s.y * s.z - c.y * c.z * s.x,
            -c.x * s.y,                     s.x,            c.x * c.y
        );
    }
    float3x3 float3x3::EulerYZX(const float3& xyz)
    {
        // return mul(rotateX(xyz.x), mul(rotateZ(xyz.z), rotateY(xyz.y)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float3x3(
            c.y * c.z, -s.z, c.z * s.y,
            s.x * s.y + c.x * c.y * s.z, c.x * c.z, c.x * s.y * s.z - c.y * s.x,
            c.y * s.x * s.z - c.x * s.y, c.z * s.x, c.x * c.y + s.x * s.y * s.z
        );
    }
    float3x3 float3x3::EulerZXY(const float3& xyz)
    {
        // return mul(rotateY(xyz.y), mul(rotateX(xyz.x), rotateZ(xyz.z)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float3x3(
            c.y * c.z + s.x * s.y * s.z, c.z * s.x * s.y - c.y * s.z, c.x * s.y,
            c.x * s.z,                   c.x * c.z, -s.x,
            c.y * s.x * s.z - c.z * s.y, c.y * c.z * s.x + s.y * s.z, c.x * c.y
        );
    }

    float3x3 float3x3::EulerZYX(const float3& xyz)
    {
        // return mul(rotateX(xyz.x), mul(rotateY(xyz.y), rotateZ(xyz.z)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float3x3(
            c.y * c.z,                  -c.y * s.z,                     s.y,
            c.z * s.x * s.y + c.x * s.z, c.x * c.z - s.x * s.y * s.z,  -c.y * s.x,
            s.x * s.z - c.x * c.z * s.y, c.z * s.x + c.x * s.y * s.z,   c.x * c.y
        );
    }
    float3x3 float3x3::RotateX(float angle)
    {
        // {{1, 0, 0}, {0, c_0, -s_0}, {0, s_0, c_0}}
        float s, c;
        math::sincos(angle, OUT s, OUT c);
        return float3x3(1.0f, 0.0f, 0.0f,
                        0.0f, c,    -s,
                        0.0f, s,    c);
    }
    float3x3 float3x3::RotateY(float angle)
    {
        // {{c_1, 0, s_1}, {0, 1, 0}, {-s_1, 0, c_1}}
        float s, c;
        math::sincos(angle, OUT s, OUT c);
        return float3x3(c,    0.0f, s,
                        0.0f, 1.0f, 0.0f,
                        -s,   0.0f, c);
    }
    float3x3 float3x3::RotateZ(float angle)
    {
        // {{c_2, -s_2, 0}, {s_2, c_2, 0}, {0, 0, 1}}
        float s, c;
        math::sincos(angle, OUT s, OUT c);
        return float3x3(c, -s, 0.0f,
                        s, c,  0.0f,
                        0.0f,  0.0f, 1.0f);
    }
    float3x3 float3x3::LookRotation(const float3& forward, const float3& up)
    {
        float3 t = math::normalize(math::cross(up, forward));
        return float3x3(t, math::cross(forward, t), forward);
    }
    float3x3 float3x3::LookRotationSafe(float3 forward, float3 up)
    {
        float forwardLengthSq = math::dot(forward, forward);
        float upLengthSq = math::dot(up, up);

        forward *= math::rsqrt(forwardLengthSq);
        up *= math::rsqrt(upLengthSq);

        float3 t = math::cross(up, forward);
        float tLengthSq = math::dot(t, t);
        t *= math::rsqrt(tLengthSq);

        float mn = math::min(math::min(forwardLengthSq, upLengthSq), tLengthSq);
        float mx = math::max(math::max(forwardLengthSq, upLengthSq), tLengthSq);

        bool accept = mn > 1e-35f && mx < 1e35f && math::isfinite(forwardLengthSq) && math::isfinite(upLengthSq) && math::isfinite(tLengthSq);
        return float3x3(
            math::select(float3(1, 0, 0), t, accept),
            math::select(float3(0, 1, 0), math::cross(forward, t), accept),
            math::select(float3(0, 0, 1), forward, accept));
    }

	//=========================================================
	// float3x4
	//=========================================================
	float3x4::float3x4(bool v)
	{
		c0 = math::select(float3(0.0f), float3(1.0f), v);
		c1 = math::select(float3(0.0f), float3(1.0f), v);
		c2 = math::select(float3(0.0f), float3(1.0f), v);
		c3 = math::select(float3(0.0f), float3(1.0f), v);
	}
	float3x4::float3x4(const bool3x4& v)
	{
		c0 = math::select(float3(0.0f), float3(1.0f), v.c0);
		c1 = math::select(float3(0.0f), float3(1.0f), v.c1);
		c2 = math::select(float3(0.0f), float3(1.0f), v.c2);
		c3 = math::select(float3(0.0f), float3(1.0f), v.c3);
	}
	float3x4::float3x4(const uint3x4& v)    {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;      }
    float3x4::float3x4(const int3x4& v)     {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;      }
    float3x4::float3x4(const float3x4& v)   {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;	    }
    float3x4::float3x4(const double3x4& v)  {   c0 = (float3)v.c0;  c1 = (float3)v.c1;  c2 = (float3)v.c2;  c3 = (float3)v.c3;  }

    namespace math
    {
        //=========================================================
        // math-float3
        //=========================================================
        float select_shuffle_component(const float3& a, const float3& b, ShuffleComponent component)
        {
            switch(component)
            {
                case ShuffleComponent::LeftX:
                    return a.x;
                case ShuffleComponent::LeftY:
                    return a.y;
                case ShuffleComponent::LeftZ:
                    return a.z;
                case ShuffleComponent::RightX:
                    return b.x;
                case ShuffleComponent::RightY:
                    return b.y;
                case ShuffleComponent::RightZ:
                    return b.z;
                default:
                    throw std::exception(std::format("Invalid shuffle component: {}",static_cast<int>(component)).c_str());
            }
        }
        uint hash(const float3& v)
        {
            return math::csum(math::asuint(v) * uint3(0x9B13B92Du, 0x4ABF0813u, 0x86068063u)) + 0xD75513F9u;
        }
        uint3 hashwide(const float3& v)
        {
            return (math::asuint(v) * uint3(0x5AB3E8CDu, 0x676E8407u, 0xB36DE767u)) + 0x6FCA387Du;
        }
        float shuffle(const float3& left, const float3& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        float2 shuffle(const float3& left, const float3& right, ShuffleComponent x, ShuffleComponent y)
        {
            return float2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        float3 shuffle(const float3& left, const float3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return float3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        float4 shuffle(const float3& left, const float3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return float4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }
        //=========================================================
	    // math-float3x2
	    //=========================================================
        float2x3 transpose(const float3x2& v)
        {
            return float2x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z);
        }
        uint hash(const float3x2& v)
        {
            return math::csum(math::asuint(v.c0) * uint3(0xE121E6ADu, 0xC9CA1249u, 0x69B60C81u) +
                              math::asuint(v.c1) * uint3(0xE0EB6C25u, 0xF648BEABu, 0x6BDB2B07u)) + 0xEF63C699u;
        }
        uint3 hashwide(const float3x2& v)
        {
            return (math::asuint(v.c0) * uint3(0x9001903Fu, 0xA895B9CDu, 0x9D23B201u) +
                    math::asuint(v.c1) * uint3(0x4B01D3E1u, 0x7461CA0Du, 0x79725379u)) + 0xD6258E5Bu;
        }
        //=========================================================
        // math-float3x3
        //=========================================================
        float3x3 transpose(const float3x3& v)
        {
            return float3x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z);
        }
        float3x3 inverse(const float3x3& m)
        {
            float3 c0 = m.c0;
            float3 c1 = m.c1;
            float3 c2 = m.c2;

            float3 t0 = float3(c1.x, c2.x, c0.x);
            float3 t1 = float3(c1.y, c2.y, c0.y);
            float3 t2 = float3(c1.z, c2.z, c0.z);

            float3 m0 = t1 * t2.yzx() - t1.yzx() * t2;
            float3 m1 = t0.yzx() * t2 - t0 * t2.yzx();
            float3 m2 = t0 * t1.yzx() - t0.yzx() * t1;

            float rcpDet = 1.0f / math::csum(t0.zxy() * m0);
            return float3x3(m0, m1, m2) * rcpDet;
        }
        float determinant(const float3x3& m)
        {
            float3 c0 = m.c0;
            float3 c1 = m.c1;
            float3 c2 = m.c2;

            float m00 = c1.y * c2.z - c1.z * c2.y;
            float m01 = c0.y * c2.z - c0.z * c2.y;
            float m02 = c0.y * c1.z - c0.z * c1.y;

            return c0.x * m00 - c1.x * m01 + c2.x * m02;
        }
        uint hash(const float3x3& v)
        {
            return math::csum(math::asuint(v.c0) * uint3(0x713BD06Fu, 0x753AD6ADu, 0xD19764C7u) +
                              math::asuint(v.c1) * uint3(0xB5D0BF63u, 0xF9102C5Fu, 0x9881FB9Fu) +
                              math::asuint(v.c2) * uint3(0x56A1530Du, 0x804B722Du, 0x738E50E5u)) + 0x4FC93C25u;
        }
        uint3 hashwide(const float3x3& v)
        {
            return (math::asuint(v.c0) * uint3(0xCD0445A5u, 0xD2B90D9Bu, 0xD35C9B2Du) +
                    math::asuint(v.c1) * uint3(0xA10D9E27u, 0x568DAAA9u, 0x7530254Fu) +
                    math::asuint(v.c2) * uint3(0x9F090439u, 0x5E9F85C9u, 0x8C4CA03Fu)) + 0xB8D969EDu;
        }
	    //=========================================================
	    // math-float3x4
	    //=========================================================
        float4x3 transpose(const float3x4& v)
        {
            return float4x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z,
                v.c3.x, v.c3.y, v.c3.z);
        }
        float3x4 fastinverse(const float3x4& m)
        {
            float3 c0 = m.c0;
            float3 c1 = m.c1;
            float3 c2 = m.c2;
            float3 pos = m.c3;

            float3 r0 = float3(c0.x, c1.x, c2.x);
            float3 r1 = float3(c0.y, c1.y, c2.y);
            float3 r2 = float3(c0.z, c1.z, c2.z);

            pos = -(r0 * pos.x + r1 * pos.y + r2 * pos.z);

            return float3x4(r0, r1, r2, pos);
        }
        uint hash(const float3x4& v)
        {
            return math::csum(math::asuint(v.c0) * uint3(0xF9EA92D5u, 0xC2FAFCB9u, 0x616E9CA1u) +
						      math::asuint(v.c1) * uint3(0xC5C5394Bu, 0xCAE78587u, 0x7A1541C9u) +
						      math::asuint(v.c2) * uint3(0xF83BD927u, 0x6A243BCBu, 0x509B84C9u) +
						      math::asuint(v.c3) * uint3(0x91D13847u, 0x52F7230Fu, 0xCF286E83u)) + 0xE121E6ADu;
        }
        uint3 hashwide(const float3x4& v)
        {
            return (math::asuint(v.c0) * uint3(0xC9CA1249u, 0x69B60C81u, 0xE0EB6C25u) +
                    math::asuint(v.c1) * uint3(0xF648BEABu, 0x6BDB2B07u, 0xEF63C699u) +
                    math::asuint(v.c2) * uint3(0x9001903Fu, 0xA895B9CDu, 0x9D23B201u) +
                    math::asuint(v.c3) * uint3(0x4B01D3E1u, 0x7461CA0Du, 0x79725379u)) + 0xD6258E5Bu;
        }
    }

} // namespace ecs