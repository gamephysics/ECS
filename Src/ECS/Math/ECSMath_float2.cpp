#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// float2
	//=========================================================
    float2::float2(const bool2& v)          {   x = v.x ? 1.0f : 0.0f;  y = v.y ? 1.0f : 0.0f;    }
    float2::float2(const uint2& v)          {   x = (float)v.x;         y = (float)v.y; }
    float2::float2(const int2& v)           {   x = (float)v.x;         y = (float)v.y; }
    //float2::float2(const half2& v)        {   x = (float)v.x;         y = (float)v.y; }
    float2::float2(const float2& v)         {   x = v.x;                y = v.y;        }
    float2::float2(const double2& v)        {   x = (float)v.x;         y = (float)v.y; }

    float4 float2::xxxx() const             { return float4(x, x, x, x); }
    float4 float2::xxxy() const             { return float4(x, x, x, y); }
    float4 float2::xxyx() const             { return float4(x, x, y, x); }
    float4 float2::xxyy() const             { return float4(x, x, y, y); }
    float4 float2::xyxx() const             { return float4(x, y, x, x); }
    float4 float2::xyxy() const             { return float4(x, y, x, y); }
    float4 float2::xyyx() const             { return float4(x, y, y, x); }
    float4 float2::xyyy() const             { return float4(x, y, y, y); }
    float4 float2::yxxx() const             { return float4(y, x, x, x); }
    float4 float2::yxxy() const             { return float4(y, x, x, y); }
    float4 float2::yxyx() const             { return float4(y, x, y, x); }
    float4 float2::yxyy() const             { return float4(y, x, y, y); }
    float4 float2::yyxx() const             { return float4(y, y, x, x); }
    float4 float2::yyxy() const             { return float4(y, y, x, y); }
    float4 float2::yyyx() const             { return float4(y, y, y, x); }
    float4 float2::yyyy() const             { return float4(y, y, y, y); }
    float3 float2::xxx()  const             { return float3(x, x, x); }
    float3 float2::xxy()  const             { return float3(x, x, y); }
    float3 float2::xyx()  const             { return float3(x, y, x); }
    float3 float2::xyy()  const             { return float3(x, y, y); }
    float3 float2::yxx()  const             { return float3(y, x, x); }
    float3 float2::yxy()  const             { return float3(y, x, y); }
    float3 float2::yyx()  const             { return float3(y, y, x); }
    float3 float2::yyy()  const             { return float3(y, y, y); }
    float2 float2::xx()   const             { return float2(x, x); }
    float2 float2::xy()   const             { return float2(x, y); }
    void   float2::xy(const float2& v)      { x = v.x; y = v.y; }
    float2 float2::yx()   const             { return float2(y, x); }
    void   float2::yx(const float2& v)      { y = v.x; x = v.y; }
    float2 float2::yy()   const             { return float2(y, y); }

	//=========================================================
	// float2x2
	//=========================================================
    float2x2::float2x2(bool v)
	{
		c0 = math::select(float2(0.0f), float2(1.0f), v);
		c1 = math::select(float2(0.0f), float2(1.0f), v);
	}
    float2x2::float2x2(const bool2x2& v)
	{
		c0 = math::select(float2(0.0f), float2(1.0f), v.c0);
		c1 = math::select(float2(0.0f), float2(1.0f), v.c1);
	}
    float2x2::float2x2(const int2x2& v)       {   c0 = v.c0;          c1 = v.c1;          }
    float2x2::float2x2(const uint2x2& v)      {   c0 = v.c0;          c1 = v.c1;          }
    float2x2::float2x2(const float2x2& v)     {   c0 = v.c0;          c1 = v.c1;          }
    float2x2::float2x2(const double2x2& v)    {   c0 = (float2)v.c0;  c1 = (float2)v.c1;  }

	//=========================================================
	// float2x2 matrix
	//=========================================================
	float2x2 float2x2::Rotate(float angle)
	{
		float s, c;
		math::sincos(angle, OUT s, OUT c);
		return float2x2(c, -s,
						s, c);
	}
	float2x2 float2x2::Scale(float s)
	{
		return float2x2(s,	  0.0f,
						0.0f, s);
	}
	float2x2 float2x2::Scale(float x, float y)
	{
		return float2x2(x,	  0.0f,
						0.0f, y);
	}
	float2x2 float2x2::Scale(float2 v)
	{
		return Scale(v.x, v.y);
	}

	//=========================================================
	// float2x3
	//=========================================================
    float2x3::float2x3(bool v)
	{
		c0 = math::select(float2(0.0f), float2(1.0f), v);
		c1 = math::select(float2(0.0f), float2(1.0f), v);
		c2 = math::select(float2(0.0f), float2(1.0f), v);
	}
    float2x3::float2x3(const bool2x3& v)
	{
		c0 = math::select(float2(0.0f), float2(1.0f), v.c0);
		c1 = math::select(float2(0.0f), float2(1.0f), v.c1);
		c2 = math::select(float2(0.0f), float2(1.0f), v.c2);
	}
    float2x3::float2x3(const uint2x3& v)    { c0 = v.c0;          c1 = v.c1;          c2 = v.c2; }
    float2x3::float2x3(const int2x3& v)     { c0 = v.c0;          c1 = v.c1;          c2 = v.c2; }
    float2x3::float2x3(const float2x3& v)   { c0 = v.c0;          c1 = v.c1;          c2 = v.c2; }
    float2x3::float2x3(const double2x3& v)  { c0 = (float2)v.c0;  c1 = (float2)v.c1;  c2 = (float2)v.c2; }

    //=========================================================
	// float2x4
	//=========================================================
	float2x4::float2x4(bool v)
	{
		c0 = math::select(float2(0.0f), float2(1.0f), v);
		c1 = math::select(float2(0.0f), float2(1.0f), v);
		c2 = math::select(float2(0.0f), float2(1.0f), v);
		c3 = math::select(float2(0.0f), float2(1.0f), v);
	}
	float2x4::float2x4(const bool2x4& v)
	{
		c0 = math::select(float2(0.0f), float2(1.0f), v.c0);
		c1 = math::select(float2(0.0f), float2(1.0f), v.c1);
		c2 = math::select(float2(0.0f), float2(1.0f), v.c2);
		c3 = math::select(float2(0.0f), float2(1.0f), v.c3);
	}
	float2x4::float2x4(const uint2x4& v)    { c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3; }
	float2x4::float2x4(const int2x4& v)     { c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3; }
	float2x4::float2x4(const float2x4& v)   { c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3; }
	float2x4::float2x4(const double2x4& v)  { c0 = (float2)v.c0;  c1 = (float2)v.c1;  c2 = (float2)v.c2;  c3 = (float2)v.c3; }

    namespace math
    {
	    //=========================================================
        // math-float2
        //=========================================================
        float select_shuffle_component(const float2& a, const float2& b, ShuffleComponent component)
        {
            switch(component)
            {
                case ShuffleComponent::LeftX:
                    return a.x;
                case ShuffleComponent::LeftY:
                    return a.y;
                case ShuffleComponent::RightX:
                    return b.x;
                case ShuffleComponent::RightY:
                    return b.y;
                default:
                    throw std::exception(std::format("Invalid shuffle component: {}",static_cast<int>(component)).c_str());
            }
        }
        uint hash(const float2& v)
        {
            return math::csum(math::asuint(v) * uint2(0xFA3A3285u, 0xAD55999Du)) + 0xDCDD5341u;
        }
        uint2 hashwide(const float2& v)
        {
            return (math::asuint(v) * uint2(0x94DDD769u, 0xA1E92D39u)) + 0x4583C801u;
        }
        float shuffle(const float2& left, const float2& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        float2 shuffle(const float2& left, const float2& right, ShuffleComponent x, ShuffleComponent y)
        {
            return float2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        float3 shuffle(const float2& left, const float2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return float3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        float4 shuffle(const float2& left, const float2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return float4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }
	    //=========================================================
        // math-float2x2
        //=========================================================
        float2x2 transpose(const float2x2& v)
        {
            return float2x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y);
        }
        float2x2 inverse(const float2x2& m)
        {
            float a = m.c0.x;
            float b = m.c1.x;
            float c = m.c0.y;
            float d = m.c1.y;

            float det = a * d - b * c;

            return float2x2(d, -b, -c, a) * (1.0f / det);
        }
        float determinant(const float2x2& m)
        {
            float a = m.c0.x;
            float b = m.c1.x;
            float c = m.c0.y;
            float d = m.c1.y;

            return a * d - b * c;
        }
        uint hash(const float2x2& v)
        {
            return math::csum(math::asuint(v.c0) * uint2(0x9C9F0823u, 0x5A9CA13Bu) +
						      math::asuint(v.c1) * uint2(0xAFCDD5EFu, 0xA88D187Du)) + 0xCF6EBA1Du;
        }
        uint2 hashwide(const float2x2& v)
        {
            return (math::asuint(v.c0) * uint2(0x9D88E5A1u, 0xEADF0775u) +
                    math::asuint(v.c1) * uint2(0x747A9D7Bu, 0x4111F799u)) + 0xB5F05AF1u;
        }
        //=========================================================
        // math-float2x3
        //=========================================================
        float3x2 transpose(const float2x3& v)
        {
            return float3x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y);
        }
        uint hash(const float2x3& v)
        {
            return math::csum(math::asuint(v.c0) * uint2(0xE857DCE1u, 0xF62213C5u) +
                              math::asuint(v.c1) * uint2(0x9CDAA959u, 0xAA269ABFu) +
                              math::asuint(v.c2) * uint2(0xD54BA36Fu, 0xFD0847B9u)) + 0x8189A683u;
        }
        uint2 hashwide(const float2x3& v)
        {
            return (math::asuint(v.c0) * uint2(0xB139D651u, 0xE7579997u) +
                    math::asuint(v.c1) * uint2(0xEF7D56C7u, 0x66F38F0Bu) +
                    math::asuint(v.c2) * uint2(0x624256A3u, 0x5292ADE1u)) + 0xD2E590E5u;
        }
        //=========================================================
        // math-float2x4
        //=========================================================
        float4x2 transpose(const float2x4& v)
        {
            return float4x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y,
                v.c3.x, v.c3.y);
        }
        uint hash(const float2x4& v)
        {
            return math::csum(math::asuint(v.c0) * uint2(0xD35C9B2Du, 0xA10D9E27u) +
                              math::asuint(v.c1) * uint2(0x568DAAA9u, 0x7530254Fu) +
                              math::asuint(v.c2) * uint2(0x9F090439u, 0x5E9F85C9u) +
                              math::asuint(v.c3) * uint2(0x8C4CA03Fu, 0xB8D969EDu)) + 0xAC5DB57Bu;
        }
        uint2 hashwide(const float2x4& v)
        {
            return (math::asuint(v.c0) * uint2(0xA91A02EDu, 0xB3C49313u) +
                    math::asuint(v.c1) * uint2(0xF43A9ABBu, 0x84E7E01Bu) +
                    math::asuint(v.c2) * uint2(0x8E055BE5u, 0x6E624EB7u) +
                    math::asuint(v.c3) * uint2(0x7383ED49u, 0xDD49C23Bu)) + 0xEBD0D005u;
        }
    }

} // namespace ecs