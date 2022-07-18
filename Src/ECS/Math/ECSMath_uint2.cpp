#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    //=========================================================
	// uint2
	//=========================================================
    uint2::uint2(const bool2& v)        { x = v.x ? 1u : 0u;    y = v.y ? 1u : 0u; }
    uint2::uint2(const uint2& v)        { x = v.x;              y = v.y;        }
    uint2::uint2(const int2& v)         { x = (uint)v.x;        y = (uint)v.y;  }
    uint2::uint2(const float2& v)       { x = (uint)v.x;        y = (uint)v.y;  }
    uint2::uint2(const double2& v)      { x = (uint)v.x;        y = (uint)v.y;  }

    uint4 uint2::xxxx() const           { return uint4(x, x, x, x); }   
    uint4 uint2::xxxy() const           { return uint4(x, x, x, y); }   
    uint4 uint2::xxyx() const           { return uint4(x, x, y, x); }   
    uint4 uint2::xxyy() const           { return uint4(x, x, y, y); }   
    uint4 uint2::xyxx() const           { return uint4(x, y, x, x); }   
    uint4 uint2::xyxy() const           { return uint4(x, y, x, y); }   
    uint4 uint2::xyyx() const           { return uint4(x, y, y, x); }   
    uint4 uint2::xyyy() const           { return uint4(x, y, y, y); }   
    uint4 uint2::yxxx() const           { return uint4(y, x, x, x); }
    uint4 uint2::yxxy() const           { return uint4(y, x, x, y); }
    uint4 uint2::yxyx() const           { return uint4(y, x, y, x); }
    uint4 uint2::yxyy() const           { return uint4(y, x, y, y); }
    uint4 uint2::yyxx() const           { return uint4(y, y, x, x); }
    uint4 uint2::yyxy() const           { return uint4(y, y, x, y); }
    uint4 uint2::yyyx() const           { return uint4(y, y, y, x); }
    uint4 uint2::yyyy() const           { return uint4(y, y, y, y); }
    uint3 uint2::xxx()  const           { return uint3(x, x, x); }
    uint3 uint2::xxy()  const           { return uint3(x, x, y); }
    uint3 uint2::xyx()  const           { return uint3(x, y, x); }
    uint3 uint2::xyy()  const           { return uint3(x, y, y); }
    uint3 uint2::yxx()  const           { return uint3(y, x, x); }
    uint3 uint2::yxy()  const           { return uint3(y, x, y); }
    uint3 uint2::yyx()  const           { return uint3(y, y, x); }
    uint3 uint2::yyy()  const           { return uint3(y, y, y); }
    uint2 uint2::xx()   const           { return uint2(x, x); }
    uint2 uint2::xy()   const           { return uint2(x, y); }
    void  uint2::xy(const uint2& v)     { x = v.x;  y = v.y; }
    uint2 uint2::yx()   const           { return uint2(y, x); }
    void  uint2::yx(const uint2& v)     { y = v.x;  x = v.y; }
    uint2 uint2::yy()   const           { return uint2(y, y); }

	//=========================================================
	// uint2x2
	//=========================================================
	uint2x2::uint2x2(bool v)
	{
		c0 = math::select(uint2(0u), uint2(1u), v);
		c1 = math::select(uint2(0u), uint2(1u), v);
	}

	uint2x2::uint2x2(const bool2x2& v)
	{
		c0 = math::select(uint2(0u), uint2(1u), v.c0);
		c1 = math::select(uint2(0u), uint2(1u), v.c1);
	}
    uint2x2::uint2x2(const uint2x2& v)  {   c0 = v.c0;          c1 = v.c1;          }
    uint2x2::uint2x2(const int2x2& v)   {   c0 = (uint2)v.c0;   c1 = (uint2)v.c1;   }
    uint2x2::uint2x2(const float2x2& v) {   c0 = (uint2)v.c0;   c1 = (uint2)v.c1;   }
    uint2x2::uint2x2(const double2x2& v){   c0 = (uint2)v.c0;   c1 = (uint2)v.c1;   }

	//=========================================================
	// uint2x3
	//=========================================================
    uint2x3::uint2x3(bool v)
	{
		c0 = math::select(uint2(0u), uint2(1u), v);
		c1 = math::select(uint2(0u), uint2(1u), v);
		c2 = math::select(uint2(0u), uint2(1u), v);
	}
    uint2x3::uint2x3(const bool2x3& v)
	{
		c0 = math::select(uint2(0u), uint2(1u), v.c0);
		c1 = math::select(uint2(0u), uint2(1u), v.c1);
		c2 = math::select(uint2(0u), uint2(1u), v.c2);
	}
    uint2x3::uint2x3(const uint2x3& v)  { c0 = v.c0;          c1 = v.c1;          c2 = v.c2; }
    uint2x3::uint2x3(const int2x3& v)   { c0 = (uint2)v.c0;   c1 = (uint2)v.c1;   c2 = (uint2)v.c2; }
    uint2x3::uint2x3(const float2x3& v) { c0 = (uint2)v.c0;   c1 = (uint2)v.c1;   c2 = (uint2)v.c2; }
    uint2x3::uint2x3(const double2x3& v){ c0 = (uint2)v.c0;   c1 = (uint2)v.c1;   c2 = (uint2)v.c2; }


    //=========================================================
	// uint2x4
	//=========================================================
    uint2x4::uint2x4(bool v)
	{
		c0 = math::select(uint2(0u), uint2(1u), v);
		c1 = math::select(uint2(0u), uint2(1u), v);
		c2 = math::select(uint2(0u), uint2(1u), v);
		c3 = math::select(uint2(0u), uint2(1u), v);
	}

	uint2x4::uint2x4(const bool2x4 & v)
	{
		c0 = math::select(uint2(0u), uint2(1u), v.c0);
		c1 = math::select(uint2(0u), uint2(1u), v.c1);
		c2 = math::select(uint2(0u), uint2(1u), v.c2);
		c3 = math::select(uint2(0u), uint2(1u), v.c3);
	}
    uint2x4::uint2x4(const uint2x4& v)		{	c0 = v.c0;			c1 = v.c1;			c2 = v.c2;			c3 = v.c3;			}
    uint2x4::uint2x4(const int2x4& v)		{	c0 = (uint2)v.c0;	c1 = (uint2)v.c1;	c2 = (uint2)v.c2;	c3 = (uint2)v.c3;	}
    uint2x4::uint2x4(const float2x4& v)		{	c0 = (uint2)v.c0;	c1 = (uint2)v.c1;	c2 = (uint2)v.c2;	c3 = (uint2)v.c3;	}
    uint2x4::uint2x4(const double2x4& v)    {	c0 = (uint2)v.c0;	c1 = (uint2)v.c1;	c2 = (uint2)v.c2;	c3 = (uint2)v.c3;	}

    namespace math
    {
        //=========================================================
        // math-uint2
        //=========================================================
        uint select_shuffle_component(const uint2& a, const uint2& b, ShuffleComponent component)
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
        uint hash(const uint2& v)
        {
            return math::csum(v * uint2(0x4473BBB1u, 0xCBA11D5Fu)) + 0x685835CFu;
        }
        uint2 hashwide(const uint2& v)
        {
            return (v * uint2(0xC3D32AE1u, 0xB966942Fu)) + 0xFE9856B3u;
        }
        uint shuffle(const uint2& left, const uint2& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        uint2 shuffle(const uint2& left, const uint2& right, ShuffleComponent x, ShuffleComponent y)
        {
            return uint2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        uint3 shuffle(const uint2& left, const uint2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return uint3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        uint4 shuffle(const uint2& left, const uint2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return uint4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }

        //=========================================================
	    // math-uint2x2
	    //=========================================================
        uint2x2 transpose(const uint2x2& v)
        {
            return uint2x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y);
        }
        uint hash(const uint2x2& v)
        {
            return csum(v.c0 * uint2(0xB36DE767u, 0x6FCA387Du) +
                        v.c1 * uint2(0xAF0F3103u, 0xE4A056C7u)) + 0x841D8225u;
        }
        uint2 hashwide(const uint2x2& v)
        {
            return (v.c0 * uint2(0xC9393C7Du, 0xD42EAFA3u) +
                    v.c1 * uint2(0xD9AFD06Du, 0x97A65421u)) + 0x7809205Fu;
        }

        //=========================================================
	    // math-uint2x3
	    //=========================================================
        uint3x2 transpose(const uint2x3& v)
        {
            return uint3x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y);
        }
        uint hash(const uint2x3& v)
        {
            return csum(v.c0 * uint2(0xEF63C699u, 0x9001903Fu) +
                        v.c1 * uint2(0xA895B9CDu, 0x9D23B201u) +
                        v.c2 * uint2(0x4B01D3E1u, 0x7461CA0Du)) + 0x79725379u;
        }
        uint2 hashwide(const uint2x3& v)
        {
            return (v.c0 * uint2(0xD6258E5Bu, 0xEE390C97u) +
                    v.c1 * uint2(0x9C8A2F05u, 0x4DDC6509u) +
                    v.c2 * uint2(0x7CF083CBu, 0x5C4D6CEDu)) + 0xF9137117u;
        }

        //=========================================================
	    // math-uint2x4
	    //=========================================================
        uint4x2 transpose(const uint2x4& v)
        {
            return uint4x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y,
                v.c3.x, v.c3.y);
        }
        uint hash(const uint2x4& v)
        {
            return csum(v.c0 * uint2(0x9DF50593u, 0xF18EEB85u) +
                        v.c1 * uint2(0x9E19BFC3u, 0x8196B06Fu) +
                        v.c2 * uint2(0xD24EFA19u, 0x7D8048BBu) +
                        v.c3 * uint2(0x713BD06Fu, 0x753AD6ADu)) + 0xD19764C7u;
        }
        uint2 hashwide(const uint2x4& v)
        {
            return (v.c0 * uint2(0xB5D0BF63u, 0xF9102C5Fu) +
                    v.c1 * uint2(0x9881FB9Fu, 0x56A1530Du) +
                    v.c2 * uint2(0x804B722Du, 0x738E50E5u) +
                    v.c3 * uint2(0x4FC93C25u, 0xCD0445A5u)) + 0xD2B90D9Bu;
        }
    }

} // namespace ecs

