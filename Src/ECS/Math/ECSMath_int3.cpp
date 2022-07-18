#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// int3
	//=========================================================
    int3::int3(const bool3& v)      {   x = v.x ? 1 : 0;    y = v.y ? 1 : 0;    z = v.z ? 1 : 0;    }
    int3::int3(const uint3& v)      {   x = (int)v.x;   y = (int)v.y;   z = (int)v.z;   }
    int3::int3(const int3& v)       {   x = v.x;        y = v.y;        z = v.z;        }
    int3::int3(const float3& v)     {   x = (int)v.x;   y = (int)v.y;   z = (int)v.z;   }
    int3::int3(const double3& v)    {   x = (int)v.x;   y = (int)v.y;   z = (int)v.z;   }


     
    int4 int3::xxxx() const         { return int4(x, x, x, x); }
    int4 int3::xxxy() const         { return int4(x, x, x, y); }
    int4 int3::xxxz() const         { return int4(x, x, x, z); }
    int4 int3::xxyx() const         { return int4(x, x, y, x); }
    int4 int3::xxyy() const         { return int4(x, x, y, y); }
    int4 int3::xxyz() const         { return int4(x, x, y, z); }
    int4 int3::xxzx() const         { return int4(x, x, z, x); }
    int4 int3::xxzy() const         { return int4(x, x, z, y); }
    int4 int3::xxzz() const         { return int4(x, x, z, z); }
    int4 int3::xyxx() const         { return int4(x, y, x, x); }
    int4 int3::xyxy() const         { return int4(x, y, x, y); }
    int4 int3::xyxz() const         { return int4(x, y, x, z); }
    int4 int3::xyyx() const         { return int4(x, y, y, x); }
    int4 int3::xyyy() const         { return int4(x, y, y, y); }
    int4 int3::xyyz() const         { return int4(x, y, y, z); }
    int4 int3::xyzx() const         { return int4(x, y, z, x); }
    int4 int3::xyzy() const         { return int4(x, y, z, y); }
    int4 int3::xyzz() const         { return int4(x, y, z, z); }
    int4 int3::xzxx() const         { return int4(x, z, x, x); }
    int4 int3::xzxy() const         { return int4(x, z, x, y); }
    int4 int3::xzxz() const         { return int4(x, z, x, z); }
    int4 int3::xzyx() const         { return int4(x, z, y, x); }
    int4 int3::xzyy() const         { return int4(x, z, y, y); }
    int4 int3::xzyz() const         { return int4(x, z, y, z); }
    int4 int3::xzzx() const         { return int4(x, z, z, x); }
    int4 int3::xzzy() const         { return int4(x, z, z, y); }
    int4 int3::xzzz() const         { return int4(x, z, z, z); }
    int4 int3::yxxx() const         { return int4(y, x, x, x); }
    int4 int3::yxxy() const         { return int4(y, x, x, y); }
    int4 int3::yxxz() const         { return int4(y, x, x, z); }
    int4 int3::yxyx() const         { return int4(y, x, y, x); }
    int4 int3::yxyy() const         { return int4(y, x, y, y); }
    int4 int3::yxyz() const         { return int4(y, x, y, z); }
    int4 int3::yxzx() const         { return int4(y, x, z, x); }
    int4 int3::yxzy() const         { return int4(y, x, z, y); }
    int4 int3::yxzz() const         { return int4(y, x, z, z); }
    int4 int3::yyxx() const         { return int4(y, y, x, x); }
    int4 int3::yyxy() const         { return int4(y, y, x, y); }
    int4 int3::yyxz() const         { return int4(y, y, x, z); }
    int4 int3::yyyx() const         { return int4(y, y, y, x); }
    int4 int3::yyyy() const         { return int4(y, y, y, y); }
    int4 int3::yyyz() const         { return int4(y, y, y, z); }
    int4 int3::yyzx() const         { return int4(y, y, z, x); }
    int4 int3::yyzy() const         { return int4(y, y, z, y); }
    int4 int3::yyzz() const         { return int4(y, y, z, z); }
    int4 int3::yzxx() const         { return int4(y, z, x, x); }
    int4 int3::yzxy() const         { return int4(y, z, x, y); }
    int4 int3::yzxz() const         { return int4(y, z, x, z); }
    int4 int3::yzyx() const         { return int4(y, z, y, x); }
    int4 int3::yzyy() const         { return int4(y, z, y, y); }
    int4 int3::yzyz() const         { return int4(y, z, y, z); }
    int4 int3::yzzx() const         { return int4(y, z, z, x); }
    int4 int3::yzzy() const         { return int4(y, z, z, y); }
    int4 int3::yzzz() const         { return int4(y, z, z, z); }
    int4 int3::zxxx() const         { return int4(z, x, x, x); }
    int4 int3::zxxy() const         { return int4(z, x, x, y); }
    int4 int3::zxxz() const         { return int4(z, x, x, z); }
    int4 int3::zxyx() const         { return int4(z, x, y, x); }
    int4 int3::zxyy() const         { return int4(z, x, y, y); }
    int4 int3::zxyz() const         { return int4(z, x, y, z); }
    int4 int3::zxzx() const         { return int4(z, x, z, x); }
    int4 int3::zxzy() const         { return int4(z, x, z, y); }
    int4 int3::zxzz() const         { return int4(z, x, z, z); }
    int4 int3::zyxx() const         { return int4(z, y, x, x); }
    int4 int3::zyxy() const         { return int4(z, y, x, y); }
    int4 int3::zyxz() const         { return int4(z, y, x, z); }
    int4 int3::zyyx() const         { return int4(z, y, y, x); }
    int4 int3::zyyy() const         { return int4(z, y, y, y); }
    int4 int3::zyyz() const         { return int4(z, y, y, z); }
    int4 int3::zyzx() const         { return int4(z, y, z, x); }
    int4 int3::zyzy() const         { return int4(z, y, z, y); }
    int4 int3::zyzz() const         { return int4(z, y, z, z); }
    int4 int3::zzxx() const         { return int4(z, z, x, x); }
    int4 int3::zzxy() const         { return int4(z, z, x, y); }
    int4 int3::zzxz() const         { return int4(z, z, x, z); }
    int4 int3::zzyx() const         { return int4(z, z, y, x); }
    int4 int3::zzyy() const         { return int4(z, z, y, y); }
    int4 int3::zzyz() const         { return int4(z, z, y, z); }
    int4 int3::zzzx() const         { return int4(z, z, z, x); }
    int4 int3::zzzy() const         { return int4(z, z, z, y); }
    int4 int3::zzzz() const         { return int4(z, z, z, z); }
    int3 int3::xxx()  const         { return int3(x, x, x); }
    int3 int3::xxy()  const         { return int3(x, x, y); }
    int3 int3::xxz()  const         { return int3(x, x, z); }
    int3 int3::xyx()  const         { return int3(x, y, x); }
    int3 int3::xyy()  const         { return int3(x, y, y); }
    int3 int3::xyz()  const         { return int3(x, y, z); }
	void int3::xyz(const int3& v)	{ x = v.x; y = v.y; z = v.z; }
    int3 int3::xzx()  const         { return int3(x, z, x); }
    int3 int3::xzy()  const         { return int3(x, z, y); }
	void int3::xzy(const int3& v)   { x = v.x; z = v.y; y = v.z; }
    int3 int3::xzz()  const         { return int3(x, z, z); }
    int3 int3::yxx()  const         { return int3(y, x, x); }
    int3 int3::yxy()  const         { return int3(y, x, y); }
    int3 int3::yxz()  const         { return int3(y, x, z); }
	void int3::yxz(const int3& v)	{ y = v.x; x = v.y; z = v.z; }
    int3 int3::yyx()  const         { return int3(y, y, x); }
    int3 int3::yyy()  const         { return int3(y, y, y); }
    int3 int3::yyz()  const         { return int3(y, y, z); }
    int3 int3::yzx()  const         { return int3(y, z, x); }
	void int3::yzx(const int3& v)   { y = v.x; z = v.y; x = v.z; }
    int3 int3::yzy()  const         { return int3(y, z, y); }
    int3 int3::yzz()  const         { return int3(y, z, z); }
    int3 int3::zxx()  const         { return int3(z, x, x); }
    int3 int3::zxy()  const         { return int3(z, x, y); }
	void int3::zxy(const int3& v)	{ z = v.x; x = v.y; y = v.z; }
    int3 int3::zxz()  const         { return int3(z, x, z); }
    int3 int3::zyx()  const         { return int3(z, y, x); }
	void int3::zyx(const int3& v)   { z = v.x; y = v.y; x = v.z; }
    int3 int3::zyy()  const         { return int3(z, y, y); }
    int3 int3::zyz()  const         { return int3(z, y, z); }
    int3 int3::zzx()  const         { return int3(z, z, x); }
    int3 int3::zzy()  const         { return int3(z, z, y); }
    int3 int3::zzz()  const         { return int3(z, z, z); }
    int2 int3::xx()   const         { return int2(x, x); }
    int2 int3::xy()   const         { return int2(x, y); }
	void int3::xy(const int2& v)    { x = v.x; y = v.y; }
    int2 int3::xz()   const         { return int2(x, z); }
	void int3::xz(const int2& v)	{ x = v.x; z = v.y; }
    int2 int3::yx()   const         { return int2(y, x); }
	void int3::yx(const int2& v)	{ y = v.x; x = v.y; }
    int2 int3::yy()   const         { return int2(y, y); }
    int2 int3::yz()   const         { return int2(y, z); }
	void int3::yz(const int2& v)	{ y = v.x; z = v.y; }
    int2 int3::zx()   const         { return int2(z, x); }
	void int3::zx(const int2& v)	{ z = v.x; x = v.y; }
    int2 int3::zy()   const         { return int2(z, y); }
	void int3::zy(const int2& v)	{ z = v.x; y = v.y; }
    int2 int3::zz()   const         { return int2(z, z); }

	//=========================================================
    // int3x2
    //=========================================================
    int3x2::int3x2(bool v)
	{
		c0 = math::select(int3(0), int3(1), v);
		c1 = math::select(int3(0), int3(1), v);
	}
    int3x2::int3x2(const bool3x2& v)
	{
		c0 = math::select(int3(0), int3(1), v.c0);
		c1 = math::select(int3(0), int3(1), v.c1);
	}
    int3x2::int3x2(const uint3x2& v)    { c0 = (int3)v.c0;    c1 = (int3)v.c1;  }
    int3x2::int3x2(const int3x2& v)     { c0 = v.c0;          c1 = v.c1;        }
    int3x2::int3x2(const float3x2& v)   { c0 = (int3)v.c0;    c1 = (int3)v.c1;  }
    int3x2::int3x2(const double3x2& v)  { c0 = (int3)v.c0;    c1 = (int3)v.c1;  }


	//=========================================================
	// int3x3
	//=========================================================
	int3x3::int3x3(bool v)
	{
		c0 = math::select(int3(0), int3(1), v);
		c1 = math::select(int3(0), int3(1), v);
		c2 = math::select(int3(0), int3(1), v);
	}
	int3x3::int3x3(const bool3x3& v)
	{
		c0 = math::select(int3(0), int3(1), v.c0);
		c1 = math::select(int3(0), int3(1), v.c1);
		c2 = math::select(int3(0), int3(1), v.c2);
	}
	int3x3::int3x3(const uint3x3& v)    { c0 = (int3)v.c0;	c1 = (int3)v.c1;	c2 = (int3)v.c2; }
	int3x3::int3x3(const int3x3& v)     { c0 = v.c0;		c1 = v.c1;			c2 = v.c2;       }
	int3x3::int3x3(const float3x3& v)   { c0 = (int3)v.c0;	c1 = (int3)v.c1;	c2 = (int3)v.c2; }
	int3x3::int3x3(const double3x3& v)  { c0 = (int3)v.c0;	c1 = (int3)v.c1;	c2 = (int3)v.c2; }

    //=========================================================
    // int3x4
    //=========================================================
	int3x4::int3x4(bool v)
	{
		c0 = math::select(int3(0), int3(1), v);
		c1 = math::select(int3(0), int3(1), v);
		c2 = math::select(int3(0), int3(1), v);
		c3 = math::select(int3(0), int3(1), v);
	}
	int3x4::int3x4(const bool3x4& v)
	{
		c0 = math::select(int3(0), int3(1), v.c0);
		c1 = math::select(int3(0), int3(1), v.c1);
		c2 = math::select(int3(0), int3(1), v.c2);
		c3 = math::select(int3(0), int3(1), v.c3);
	}
    int3x4::int3x4(const int3x4& v)		{   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;          }
    int3x4::int3x4(const uint3x4& v)    {   c0 = (int3)v.c0;    c1 = (int3)v.c1;    c2 = (int3)v.c2;    c3 = (int3)v.c3;    }
    int3x4::int3x4(const float3x4& v)   {   c0 = (int3)v.c0;    c1 = (int3)v.c1;    c2 = (int3)v.c2;    c3 = (int3)v.c3;    }
    int3x4::int3x4(const double3x4& v)  {   c0 = (int3)v.c0;    c1 = (int3)v.c1;    c2 = (int3)v.c2;    c3 = (int3)v.c3;    }

    namespace math
    {
        //=========================================================
        // math-int3
        //=========================================================
        int select_shuffle_component(const int3& a, const int3& b, ShuffleComponent component)
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
        uint hash(const int3& v)
        {
            return math::csum(math::asuint(v) * uint3(0x4C7F6DD1u, 0x4822A3E9u, 0xAAC3C25Du)) + 0xD21D0945u;
        }
        uint3 hashwide(const int3& v)
        {
            return (math::asuint(v) * uint3(0x88FCAB2Du, 0x614DA60Du, 0x5BA2C50Bu)) + 0x8C455ACBu;
        }
        int shuffle(const int3& left, const int3& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        int2 shuffle(const int3& left, const int3& right, ShuffleComponent x, ShuffleComponent y)
        {
            return int2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        int3 shuffle(const int3& left, const int3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return int3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        int4 shuffle(const int3& left, const int3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return int4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }

        //=========================================================
        // math-int3x2
        //=========================================================
        /// <returns>Transposed value.</returns>
        int2x3 transpose(const int3x2& v)
        {
            return int2x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z);
        }
        uint hash(const int3x2& v)
        {
            return math::csum(math::asuint(v.c0) * uint3(0xDB3DE101u, 0x7B6D1B4Bu, 0x58399E77u) +
                              math::asuint(v.c1) * uint3(0x5EAC29C9u, 0xFC6014F9u, 0x6BF6693Fu)) + 0x9D1B1D9Bu;
        }
        uint3 hashwide(const int3x2& v)
        {
            return (math::asuint(v.c0) * uint3(0xF842F5C1u, 0xA47EC335u, 0xA477DF57u) +
                    math::asuint(v.c1) * uint3(0xC4B1493Fu, 0xBA0966D3u, 0xAFBEE253u)) + 0x5B419C01u;
        }

        //=========================================================
	    // math-int3x3
	    //=========================================================
        int3x3 transpose(const int3x3& v)
        {
            return int3x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z);
        }
        int determinant(const int3x3& m)
        {
            int3 c0 = m.c0;
            int3 c1 = m.c1;
            int3 c2 = m.c2;

            int m00 = c1.y * c2.z - c1.z * c2.y;
            int m01 = c0.y * c2.z - c0.z * c2.y;
            int m02 = c0.y * c1.z - c0.z * c1.y;

            return c0.x * m00 - c1.x * m01 + c2.x * m02;
        }
        uint hash(const int3x3& v)
        {
            return math::csum(math::asuint(v.c0) * uint3(0x93C30C2Bu, 0xDCAF0351u, 0x6E050B01u) +
                              math::asuint(v.c1) * uint3(0x750FDBF5u, 0x7F3DD499u, 0x52EAAEBBu) +
                              math::asuint(v.c2) * uint3(0x4599C793u, 0x83B5E729u, 0xC267163Fu)) + 0x67BC9149u;
        }
        uint3 hashwide(const int3x3& v)
        {
            return (math::asuint(v.c0) * uint3(0xAD7C5EC1u, 0x822A7D6Du, 0xB492BF15u) +
                    math::asuint(v.c1) * uint3(0xD37220E3u, 0x7AA2C2BDu, 0xE16BC89Du) +
                    math::asuint(v.c2) * uint3(0x7AA07CD3u, 0xAF642BA9u, 0xA8F2213Bu)) + 0x9F3FDC37u;
        }

        //=========================================================
        // math-int3x4
        //=========================================================
        int4x3 transpose(const int3x4& v)
        {
            return int4x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z,
                v.c3.x, v.c3.y, v.c3.z);
        }
        uint hash(const int3x4& v)
        {
            return math::csum(math::asuint(v.c0) * uint3(0x5AB3E8CDu, 0x676E8407u, 0xB36DE767u) +
                              math::asuint(v.c1) * uint3(0x6FCA387Du, 0xAF0F3103u, 0xE4A056C7u) +
                              math::asuint(v.c2) * uint3(0x841D8225u, 0xC9393C7Du, 0xD42EAFA3u) +
                              math::asuint(v.c3) * uint3(0xD9AFD06Du, 0x97A65421u, 0x7809205Fu)) + 0x9C9F0823u;
        }
        uint3 hashwide(const int3x4& v)
        {
            return (math::asuint(v.c0) * uint3(0x5A9CA13Bu, 0xAFCDD5EFu, 0xA88D187Du) +
                    math::asuint(v.c1) * uint3(0xCF6EBA1Du, 0x9D88E5A1u, 0xEADF0775u) +
                    math::asuint(v.c2) * uint3(0x747A9D7Bu, 0x4111F799u, 0xB5F05AF1u) +
                    math::asuint(v.c3) * uint3(0xFD80290Bu, 0x8B65ADB7u, 0xDFF4F563u)) + 0x7069770Du;
        }
    }

} // namespace ecs

