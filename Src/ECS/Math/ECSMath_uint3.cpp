#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// uint3
	//=========================================================
    uint3::uint3(const bool3& v)        { x = v.x ? 1u : 0u;    y = v.y ? 1u : 0u;  z = v.z ? 1u : 0u;  }
    uint3::uint3(const uint3& _xyz)     { x = _xyz.x;           y = _xyz.y;         z = _xyz.z;         }
    uint3::uint3(const int3& v)         { x = (uint)v.x;        y = (uint)v.y;      z = (uint)v.z;      }
    uint3::uint3(const float3& v)       { x = (uint)v.x;        y = (uint)v.y;      z = (uint)v.z;      }
    uint3::uint3(const double3& v)      { x = (uint)v.x;        y = (uint)v.y;      z = (uint)v.z;      }


    uint4 uint3::xxxx() const           { return uint4(x, x, x, x); }
    uint4 uint3::xxxy() const           { return uint4(x, x, x, y); }
    uint4 uint3::xxxz() const           { return uint4(x, x, x, z); }
    uint4 uint3::xxyx() const           { return uint4(x, x, y, x); }
    uint4 uint3::xxyy() const           { return uint4(x, x, y, y); }
    uint4 uint3::xxyz() const           { return uint4(x, x, y, z); }
    uint4 uint3::xxzx() const           { return uint4(x, x, z, x); }
    uint4 uint3::xxzy() const           { return uint4(x, x, z, y); }
    uint4 uint3::xxzz() const           { return uint4(x, x, z, z); }
    uint4 uint3::xyxx() const           { return uint4(x, y, x, x); }
    uint4 uint3::xyxy() const           { return uint4(x, y, x, y); }
    uint4 uint3::xyxz() const           { return uint4(x, y, x, z); }
    uint4 uint3::xyyx() const           { return uint4(x, y, y, x); }
    uint4 uint3::xyyy() const           { return uint4(x, y, y, y); }
    uint4 uint3::xyyz() const           { return uint4(x, y, y, z); }
    uint4 uint3::xyzx() const           { return uint4(x, y, z, x); }
    uint4 uint3::xyzy() const           { return uint4(x, y, z, y); }
    uint4 uint3::xyzz() const           { return uint4(x, y, z, z); }
    uint4 uint3::xzxx() const           { return uint4(x, z, x, x); }
    uint4 uint3::xzxy() const           { return uint4(x, z, x, y); }
    uint4 uint3::xzxz() const           { return uint4(x, z, x, z); }
    uint4 uint3::xzyx() const           { return uint4(x, z, y, x); }
    uint4 uint3::xzyy() const           { return uint4(x, z, y, y); }
    uint4 uint3::xzyz() const           { return uint4(x, z, y, z); }
    uint4 uint3::xzzx() const           { return uint4(x, z, z, x); }
    uint4 uint3::xzzy() const           { return uint4(x, z, z, y); }
    uint4 uint3::xzzz() const           { return uint4(x, z, z, z); }
    uint4 uint3::yxxx() const           { return uint4(y, x, x, x); }
    uint4 uint3::yxxy() const           { return uint4(y, x, x, y); }
    uint4 uint3::yxxz() const           { return uint4(y, x, x, z); }
    uint4 uint3::yxyx() const           { return uint4(y, x, y, x); }
    uint4 uint3::yxyy() const           { return uint4(y, x, y, y); }
    uint4 uint3::yxyz() const           { return uint4(y, x, y, z); }
    uint4 uint3::yxzx() const           { return uint4(y, x, z, x); }
    uint4 uint3::yxzy() const           { return uint4(y, x, z, y); }
    uint4 uint3::yxzz() const           { return uint4(y, x, z, z); }
    uint4 uint3::yyxx() const           { return uint4(y, y, x, x); }
    uint4 uint3::yyxy() const           { return uint4(y, y, x, y); }
    uint4 uint3::yyxz() const           { return uint4(y, y, x, z); }
    uint4 uint3::yyyx() const           { return uint4(y, y, y, x); }
    uint4 uint3::yyyy() const           { return uint4(y, y, y, y); }
    uint4 uint3::yyyz() const           { return uint4(y, y, y, z); }
    uint4 uint3::yyzx() const           { return uint4(y, y, z, x); }
    uint4 uint3::yyzy() const           { return uint4(y, y, z, y); }
    uint4 uint3::yyzz() const           { return uint4(y, y, z, z); }
    uint4 uint3::yzxx() const           { return uint4(y, z, x, x); }
    uint4 uint3::yzxy() const           { return uint4(y, z, x, y); }
    uint4 uint3::yzxz() const           { return uint4(y, z, x, z); }
    uint4 uint3::yzyx() const           { return uint4(y, z, y, x); }
    uint4 uint3::yzyy() const           { return uint4(y, z, y, y); }
    uint4 uint3::yzyz() const           { return uint4(y, z, y, z); }
    uint4 uint3::yzzx() const           { return uint4(y, z, z, x); }
    uint4 uint3::yzzy() const           { return uint4(y, z, z, y); }
    uint4 uint3::yzzz() const           { return uint4(y, z, z, z); }
    uint4 uint3::zxxx() const           { return uint4(z, x, x, x); }
    uint4 uint3::zxxy() const           { return uint4(z, x, x, y); }
    uint4 uint3::zxxz() const           { return uint4(z, x, x, z); }
    uint4 uint3::zxyx() const           { return uint4(z, x, y, x); }
    uint4 uint3::zxyy() const           { return uint4(z, x, y, y); }
    uint4 uint3::zxyz() const           { return uint4(z, x, y, z); }
    uint4 uint3::zxzx() const           { return uint4(z, x, z, x); }
    uint4 uint3::zxzy() const           { return uint4(z, x, z, y); }
    uint4 uint3::zxzz() const           { return uint4(z, x, z, z); }
    uint4 uint3::zyxx() const           { return uint4(z, y, x, x); }
    uint4 uint3::zyxy() const           { return uint4(z, y, x, y); }
    uint4 uint3::zyxz() const           { return uint4(z, y, x, z); }
    uint4 uint3::zyyx() const           { return uint4(z, y, y, x); }
    uint4 uint3::zyyy() const           { return uint4(z, y, y, y); }
    uint4 uint3::zyyz() const           { return uint4(z, y, y, z); }
    uint4 uint3::zyzx() const           { return uint4(z, y, z, x); }
    uint4 uint3::zyzy() const           { return uint4(z, y, z, y); }
    uint4 uint3::zyzz() const           { return uint4(z, y, z, z); }
    uint4 uint3::zzxx() const           { return uint4(z, z, x, x); }
    uint4 uint3::zzxy() const           { return uint4(z, z, x, y); }
    uint4 uint3::zzxz() const           { return uint4(z, z, x, z); }
    uint4 uint3::zzyx() const           { return uint4(z, z, y, x); }
    uint4 uint3::zzyy() const           { return uint4(z, z, y, y); }
    uint4 uint3::zzyz() const           { return uint4(z, z, y, z); }
    uint4 uint3::zzzx() const           { return uint4(z, z, z, x); }
    uint4 uint3::zzzy() const           { return uint4(z, z, z, y); }
    uint4 uint3::zzzz() const           { return uint4(z, z, z, z); }
    uint3 uint3::xxx()  const           { return uint3(x, x, x); }
    uint3 uint3::xxy()  const           { return uint3(x, x, y); }
    uint3 uint3::xxz()  const           { return uint3(x, x, z); }
    uint3 uint3::xyx()  const           { return uint3(x, y, x); }
    uint3 uint3::xyy()  const           { return uint3(x, y, y); }
    uint3 uint3::xyz()  const           { return uint3(x, y, z); }
    void  uint3::xyz(const uint3& v)    { x = v.x; y = v.y; z = v.z; }
    uint3 uint3::xzx()  const           { return uint3(x, z, x); }
    uint3 uint3::xzy()  const           { return uint3(x, z, y); }
    void  uint3::xzy(const uint3& v)    { x = v.x; z = v.y; y = v.z; }
    uint3 uint3::xzz()  const           { return uint3(x, z, z); }
    uint3 uint3::yxx()  const           { return uint3(y, x, x); }
    uint3 uint3::yxy()  const           { return uint3(y, x, y); }
    uint3 uint3::yxz()  const           { return uint3(y, x, z); }
    void  uint3::yxz(const uint3& v)    { y = v.x; x = v.y; z = v.z; }
    uint3 uint3::yyx()  const           { return uint3(y, y, x); }
    uint3 uint3::yyy()  const           { return uint3(y, y, y); }
    uint3 uint3::yyz()  const           { return uint3(y, y, z); }
    uint3 uint3::yzx()  const           { return uint3(y, z, x); }
    void  uint3::yzx(const uint3& v)    { y = v.x; z = v.y; x = v.z; }
    uint3 uint3::yzy()  const           { return uint3(y, z, y); }
    uint3 uint3::yzz()  const           { return uint3(y, z, z); }
    uint3 uint3::zxx()  const           { return uint3(z, x, x); }
    uint3 uint3::zxy()  const           { return uint3(z, x, y); }
    void  uint3::zxy(const uint3& v)    { z = v.x; x = v.y; y = v.z; }
    uint3 uint3::zxz()  const           { return uint3(z, x, z); }
    uint3 uint3::zyx()  const           { return uint3(z, y, x); }
    void  uint3::zyx(const uint3& v)    { z = v.x; y = v.y; x = v.z; }
    uint3 uint3::zyy()  const           { return uint3(z, y, y); }
    uint3 uint3::zyz()  const           { return uint3(z, y, z); }
    uint3 uint3::zzx()  const           { return uint3(z, z, x); }
    uint3 uint3::zzy()  const           { return uint3(z, z, y); }
    uint3 uint3::zzz()  const           { return uint3(z, z, z); }
	uint2 uint3::xx()   const           { return uint2(x, x); }
    uint2 uint3::xy()   const           { return uint2(x, y); }
    void  uint3::xy(const uint2& v)     { x = v.x; y = v.y; }
    uint2 uint3::xz()   const           { return uint2(x, z); }
    void  uint3::xz(const uint2& v)     { x = v.x; z = v.y; }
    uint2 uint3::yx()   const           { return uint2(y, x); }
    void  uint3::yx(const uint2& v)     { y = v.x; x = v.y; }
    uint2 uint3::yy()   const           { return uint2(y, y); }
    uint2 uint3::yz()   const           { return uint2(y, z); }
    void  uint3::yz(const uint2& v)     { y = v.x; z = v.y; }
    uint2 uint3::zx()   const           { return uint2(z, x); }
    void  uint3::zx(const uint2& v)     { z = v.x; x = v.y; }
    uint2 uint3::zy()   const           { return uint2(z, y); }
    void  uint3::zy(const uint2& v)     { z = v.x; y = v.y; }
    uint2 uint3::zz()   const           { return uint2(z, z); }


	//=========================================================
    // uint3x2
    //=========================================================
	uint3x2::uint3x2(bool v)
	{
		c0 = math::select(uint3(0u), uint3(1u), v);
		c1 = math::select(uint3(0u), uint3(1u), v);
	}

	uint3x2::uint3x2(const bool3x2& v)
	{
		c0 = math::select(uint3(0u), uint3(1u), v.c0);
		c1 = math::select(uint3(0u), uint3(1u), v.c1);
	}
    uint3x2::uint3x2(const uint3x2& v)       {   c0 = v.c0;          c1 = v.c1;          }
    uint3x2::uint3x2(const int3x2& v)        {   c0 = (uint3)v.c0;   c1 = (uint3)v.c1;   }
    uint3x2::uint3x2(const float3x2& v)      {   c0 = (uint3)v.c0;   c1 = (uint3)v.c1;   }
    uint3x2::uint3x2(const double3x2& v)     {   c0 = (uint3)v.c0;   c1 = (uint3)v.c1;   }


	//=========================================================
	// uint3x3
	//=========================================================
	uint3x3::uint3x3(bool v)
	{
		c0 = math::select(uint3(0u), uint3(1u), v);
		c1 = math::select(uint3(0u), uint3(1u), v);
		c2 = math::select(uint3(0u), uint3(1u), v);
	}

	uint3x3::uint3x3(const bool3x3& v)
	{
		c0 = math::select(uint3(0u), uint3(1u), v.c0);
		c1 = math::select(uint3(0u), uint3(1u), v.c1);
		c2 = math::select(uint3(0u), uint3(1u), v.c2);
	}
    uint3x3::uint3x3(const uint3x3& v)       {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          }
    uint3x3::uint3x3(const int3x3& v)        {   c0 = (uint3)v.c0;   c1 = (uint3)v.c1;   c2 = (uint3)v.c2;   }
    uint3x3::uint3x3(const float3x3& v)      {   c0 = (uint3)v.c0;   c1 = (uint3)v.c1;   c2 = (uint3)v.c2;   }
    uint3x3::uint3x3(const double3x3& v)     {   c0 = (uint3)v.c0;   c1 = (uint3)v.c1;   c2 = (uint3)v.c2;   }


	//=========================================================
	// uint3x4
	//=========================================================
	uint3x4::uint3x4(bool v)
	{
		c0 = math::select(uint3(0u), uint3(1u), v);
		c1 = math::select(uint3(0u), uint3(1u), v);
		c2 = math::select(uint3(0u), uint3(1u), v);
		c3 = math::select(uint3(0u), uint3(1u), v);
	}
	uint3x4::uint3x4(const bool3x4& v)
	{
		c0 = math::select(uint3(0u), uint3(1u), v.c0);
		c1 = math::select(uint3(0u), uint3(1u), v.c1);
		c2 = math::select(uint3(0u), uint3(1u), v.c2);
		c3 = math::select(uint3(0u), uint3(1u), v.c3);
	}
    uint3x4::uint3x4(const uint3x4& v)		{	c0 = v.c0;			c1 = v.c1;			c2 = v.c2;			c3 = v.c3;			}
    uint3x4::uint3x4(const int3x4& v)       {	c0 = (uint3)v.c0;	c1 = (uint3)v.c1;	c2 = (uint3)v.c2;	c3 = (uint3)v.c3;	}
    uint3x4::uint3x4(const float3x4& v)		{	c0 = (uint3)v.c0;	c1 = (uint3)v.c1;	c2 = (uint3)v.c2;	c3 = (uint3)v.c3;	}
    uint3x4::uint3x4(const double3x4& v)    {   c0 = (uint3)v.c0;   c1 = (uint3)v.c1;	c2 = (uint3)v.c2;	c3 = (uint3)v.c3;	}

    namespace math
    {
        //=========================================================
        // math-uint3
        //=========================================================
        uint select_shuffle_component(const int3& a, const uint3& b, ShuffleComponent component)
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
        uint hash(uint3 v)
        {
            return csum(v * uint3(0xCD266C89u, 0xF1852A33u, 0x77E35E77u)) + 0x863E3729u;
        }
        uint3 hashwide(uint3 v)
        {
            return (v * uint3(0xE191B035u, 0x68586FAFu, 0xD4DFF6D3u)) + 0xCB634F4Du;
        }
        uint shuffle(const uint3& left, const uint3& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        uint2 shuffle(const uint3& left, const uint3& right, ShuffleComponent x, ShuffleComponent y)
        {
            return uint2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        uint3 shuffle(const uint3& left, const uint3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return uint3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        uint4 shuffle(const uint3& left, const uint3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return uint4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }

        //=========================================================
        // math-uint3x2
        //=========================================================
        uint2x3 transpose(const uint3x2& v)
        {
            return uint2x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z);
        }
        uint hash(const uint3x2& v)
        {
            return csum(v.c0 * uint3(0x515D90F5u, 0xEC9F68F3u, 0xF9EA92D5u) +
                        v.c1 * uint3(0xC2FAFCB9u, 0x616E9CA1u, 0xC5C5394Bu)) + 0xCAE78587u;
        }
        uint3 hashwide(const uint3x2& v)
        {
            return (v.c0 * uint3(0x7A1541C9u, 0xF83BD927u, 0x6A243BCBu) +
                    v.c1 * uint3(0x509B84C9u, 0x91D13847u, 0x52F7230Fu)) + 0xCF286E83u;
        }

        //=========================================================
        // math-uint3x3
        //=========================================================
        uint3x3 transpose(const uint3x3& v)
        {
            return uint3x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z);
        }
        uint hash(const uint3x3& v)
        {
            return csum(v.c0 * uint3(0xAC60D0C3u, 0x9263662Fu, 0xE69626FFu) +
                        v.c1 * uint3(0xBD010EEBu, 0x9CEDE1D1u, 0x43BE0B51u) +
                        v.c2 * uint3(0xAF836EE1u, 0xB130C137u, 0x54834775u)) + 0x7C022221u;
        }
        uint3 hashwide(const uint3x3& v)
        {
            return (v.c0 * uint3(0xA2D00EDFu, 0xA8977779u, 0x9F1C739Bu) +
                    v.c1 * uint3(0x4B1BD187u, 0x9DF50593u, 0xF18EEB85u) +
                    v.c2 * uint3(0x9E19BFC3u, 0x8196B06Fu, 0xD24EFA19u)) + 0x7D8048BBu;
        }

        //=========================================================
        // math-uint3x4
        //=========================================================
        uint4x3 transpose(const uint3x4& v)
        {
            return uint4x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z,
                v.c3.x, v.c3.y, v.c3.z);
        }
        uint hash(const uint3x4& v)
        {
            return csum(v.c0 * uint3(0xD1224537u, 0xE99ED6F3u, 0x48125549u) +
                        v.c1 * uint3(0xEEE2123Bu, 0xE3AD9FE5u, 0xCE1CF8BFu) +
                        v.c2 * uint3(0x7BE39F3Bu, 0xFAB9913Fu, 0xB4501269u) +
                        v.c3 * uint3(0xE04B89FDu, 0xDB3DE101u, 0x7B6D1B4Bu)) + 0x58399E77u;
        }
        uint3 hashwide(const uint3x4& v)
        {
            return (v.c0 * uint3(0x5EAC29C9u, 0xFC6014F9u, 0x6BF6693Fu) +
                    v.c1 * uint3(0x9D1B1D9Bu, 0xF842F5C1u, 0xA47EC335u) +
                    v.c2 * uint3(0xA477DF57u, 0xC4B1493Fu, 0xBA0966D3u) +
                    v.c3 * uint3(0xAFBEE253u, 0x5B419C01u, 0x515D90F5u)) + 0xEC9F68F3u;
        }
    }

} // namespace ecs