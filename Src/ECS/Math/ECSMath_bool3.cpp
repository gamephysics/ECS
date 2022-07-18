#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// bool3
    //=========================================================
    bool4 bool3::xxxx() const           { return bool4(x, x, x, x); }
    bool4 bool3::xxxy() const           { return bool4(x, x, x, y); }
    bool4 bool3::xxxz() const           { return bool4(x, x, x, z); }
    bool4 bool3::xxyx() const           { return bool4(x, x, y, x); }
    bool4 bool3::xxyy() const           { return bool4(x, x, y, y); }
    bool4 bool3::xxyz() const           { return bool4(x, x, y, z); }
    bool4 bool3::xxzx() const           { return bool4(x, x, z, x); }
    bool4 bool3::xxzy() const           { return bool4(x, x, z, y); }
    bool4 bool3::xxzz() const           { return bool4(x, x, z, z); }
    bool4 bool3::xyxx() const           { return bool4(x, y, x, x); }
    bool4 bool3::xyxy() const           { return bool4(x, y, x, y); }
    bool4 bool3::xyxz() const           { return bool4(x, y, x, z); }
    bool4 bool3::xyyx() const           { return bool4(x, y, y, x); }
    bool4 bool3::xyyy() const           { return bool4(x, y, y, y); }
    bool4 bool3::xyyz() const           { return bool4(x, y, y, z); }
    bool4 bool3::xyzx() const           { return bool4(x, y, z, x); }
    bool4 bool3::xyzy() const           { return bool4(x, y, z, y); }
    bool4 bool3::xyzz() const           { return bool4(x, y, z, z); }
    bool4 bool3::xzxx() const           { return bool4(x, z, x, x); }
    bool4 bool3::xzxy() const           { return bool4(x, z, x, y); }
    bool4 bool3::xzxz() const           { return bool4(x, z, x, z); }
    bool4 bool3::xzyx() const           { return bool4(x, z, y, x); }
    bool4 bool3::xzyy() const           { return bool4(x, z, y, y); }
    bool4 bool3::xzyz() const           { return bool4(x, z, y, z); }
    bool4 bool3::xzzx() const           { return bool4(x, z, z, x); }
    bool4 bool3::xzzy() const           { return bool4(x, z, z, y); }
    bool4 bool3::xzzz() const           { return bool4(x, z, z, z); }
    bool4 bool3::yxxx() const           { return bool4(y, x, x, x); }
    bool4 bool3::yxxy() const           { return bool4(y, x, x, y); }
    bool4 bool3::yxxz() const           { return bool4(y, x, x, z); }
    bool4 bool3::yxyx() const           { return bool4(y, x, y, x); }
    bool4 bool3::yxyy() const           { return bool4(y, x, y, y); }
    bool4 bool3::yxyz() const           { return bool4(y, x, y, z); }
    bool4 bool3::yxzx() const           { return bool4(y, x, z, x); }
    bool4 bool3::yxzy() const           { return bool4(y, x, z, y); }
    bool4 bool3::yxzz() const           { return bool4(y, x, z, z); }
    bool4 bool3::yyxx() const           { return bool4(y, y, x, x); }
    bool4 bool3::yyxy() const           { return bool4(y, y, x, y); }
    bool4 bool3::yyxz() const           { return bool4(y, y, x, z); }
    bool4 bool3::yyyx() const           { return bool4(y, y, y, x); }
    bool4 bool3::yyyy() const           { return bool4(y, y, y, y); }
    bool4 bool3::yyyz() const           { return bool4(y, y, y, z); }
    bool4 bool3::yyzx() const           { return bool4(y, y, z, x); }
    bool4 bool3::yyzy() const           { return bool4(y, y, z, y); }
    bool4 bool3::yyzz() const           { return bool4(y, y, z, z); }
    bool4 bool3::yzxx() const           { return bool4(y, z, x, x); }
    bool4 bool3::yzxy() const           { return bool4(y, z, x, y); }
    bool4 bool3::yzxz() const           { return bool4(y, z, x, z); }
    bool4 bool3::yzyx() const           { return bool4(y, z, y, x); }
    bool4 bool3::yzyy() const           { return bool4(y, z, y, y); }
    bool4 bool3::yzyz() const           { return bool4(y, z, y, z); }
    bool4 bool3::yzzx() const           { return bool4(y, z, z, x); }
    bool4 bool3::yzzy() const           { return bool4(y, z, z, y); }
    bool4 bool3::yzzz() const           { return bool4(y, z, z, z); }
    bool4 bool3::zxxx() const           { return bool4(z, x, x, x); }
    bool4 bool3::zxxy() const           { return bool4(z, x, x, y); }
    bool4 bool3::zxxz() const           { return bool4(z, x, x, z); }
    bool4 bool3::zxyx() const           { return bool4(z, x, y, x); }
    bool4 bool3::zxyy() const           { return bool4(z, x, y, y); }
    bool4 bool3::zxyz() const           { return bool4(z, x, y, z); }
    bool4 bool3::zxzx() const           { return bool4(z, x, z, x); }
    bool4 bool3::zxzy() const           { return bool4(z, x, z, y); }
    bool4 bool3::zxzz() const           { return bool4(z, x, z, z); }
    bool4 bool3::zyxx() const           { return bool4(z, y, x, x); }
    bool4 bool3::zyxy() const           { return bool4(z, y, x, y); }
    bool4 bool3::zyxz() const           { return bool4(z, y, x, z); }
    bool4 bool3::zyyx() const           { return bool4(z, y, y, x); }
    bool4 bool3::zyyy() const           { return bool4(z, y, y, y); }
    bool4 bool3::zyyz() const           { return bool4(z, y, y, z); }
    bool4 bool3::zyzx() const           { return bool4(z, y, z, x); }
    bool4 bool3::zyzy() const           { return bool4(z, y, z, y); }
    bool4 bool3::zyzz() const           { return bool4(z, y, z, z); }
    bool4 bool3::zzxx() const           { return bool4(z, z, x, x); }
    bool4 bool3::zzxy() const           { return bool4(z, z, x, y); }
    bool4 bool3::zzxz() const           { return bool4(z, z, x, z); }
    bool4 bool3::zzyx() const           { return bool4(z, z, y, x); }
    bool4 bool3::zzyy() const           { return bool4(z, z, y, y); }
    bool4 bool3::zzyz() const           { return bool4(z, z, y, z); }
    bool4 bool3::zzzx() const           { return bool4(z, z, z, x); }
    bool4 bool3::zzzy() const           { return bool4(z, z, z, y); }
    bool4 bool3::zzzz() const           { return bool4(z, z, z, z); }
    bool3 bool3::xxx()  const           { return bool3(x, x, x); }
    bool3 bool3::xxy()  const           { return bool3(x, x, y); }
    bool3 bool3::xxz()  const           { return bool3(x, x, z); }
    bool3 bool3::xyx()  const           { return bool3(x, y, x); }
    bool3 bool3::xyy()  const           { return bool3(x, y, y); }
    bool3 bool3::xyz()  const           { return bool3(x, y, z); }
    void  bool3::xyz(const bool3& v)    { x = v.x; y = v.y; z = v.z; }
    bool3 bool3::xzx()  const           { return bool3(x, z, x); }
    bool3 bool3::xzy()  const           { return bool3(x, z, y); }
    void  bool3::xzy(const bool3& v)    { x = v.x; z = v.y; y = v.z; }
    bool3 bool3::xzz()  const           { return bool3(x, z, z); }
    bool3 bool3::yxx()  const           { return bool3(y, x, x); }
    bool3 bool3::yxy()  const           { return bool3(y, x, y); }
    bool3 bool3::yxz()  const           { return bool3(y, x, z); }
    void  bool3::yxz(const bool3& v)    { y = v.x; x = v.y; z = v.z; }
    bool3 bool3::yyx()  const           { return bool3(y, y, x); }
    bool3 bool3::yyy()  const           { return bool3(y, y, y); }
    bool3 bool3::yyz()  const           { return bool3(y, y, z); }
    bool3 bool3::yzx()  const           { return bool3(y, z, x); }
    void  bool3::yzx(const bool3& v)    { y = v.x; z = v.y; x = v.z; }
    bool3 bool3::yzy()  const           { return bool3(y, z, y); }
    bool3 bool3::yzz()  const           { return bool3(y, z, z); }
    bool3 bool3::zxx()  const           { return bool3(z, x, x); }
    bool3 bool3::zxy()  const           { return bool3(z, x, y); }
    void  bool3::zxy(const bool3& v)    { z = v.x; x = v.y; y = v.z; }
    bool3 bool3::zxz()  const           { return bool3(z, x, z); }
    bool3 bool3::zyx()  const           { return bool3(z, y, x); }
    void  bool3::zyx(const bool3& v)    { z = v.x; y = v.y; x = v.z; }
    bool3 bool3::zyy()  const           { return bool3(z, y, y); }
    bool3 bool3::zyz()  const           { return bool3(z, y, z); }
    bool3 bool3::zzx()  const           { return bool3(z, z, x); }
    bool3 bool3::zzy()  const           { return bool3(z, z, y); }
    bool3 bool3::zzz()  const           { return bool3(z, z, z); }
    bool2 bool3::xx()   const           { return bool2(x, x); }
    bool2 bool3::xy()   const           { return bool2(x, y); }
    void  bool3::xy(const bool2& v)     { x = v.x; y = v.y; }
    bool2 bool3::xz()   const           { return bool2(x, z); }
    void  bool3::xz(const bool2& v)     { x = v.x; z = v.y; }
    bool2 bool3::yx()   const           { return bool2(y, x); }
    void  bool3::yx(const bool2& v)     { y = v.x; x = v.y; }
    bool2 bool3::yy()   const           { return bool2(y, y); }
    bool2 bool3::yz()   const           { return bool2(y, z); }
    void  bool3::yz(const bool2& v)     { y = v.x; z = v.y; }
    bool2 bool3::zx()   const           { return bool2(z, x); }
    void  bool3::zx(const bool2& v)     { z = v.x; x = v.y; }
    bool2 bool3::zy()   const           { return bool2(z, y); }
    void  bool3::zy(const bool2& v)     { z = v.x; y = v.y; }
    bool2 bool3::zz()   const           { return bool2(z, z); }

    namespace math
    {
        //=========================================================
        // math-bool3
        //=========================================================
        bool select_shuffle_component(const bool3& a, const bool3& b, ShuffleComponent component)
        {
            switch (component)
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
        uint hash(const bool3& v)
        {
            return math::csum(math::select(uint3(0xA1E92D39u, 0x4583C801u, 0x9536A0F5u), uint3(0xAF816615u, 0x9AF8D62Du, 0xE3600729u), v));
        }
        uint3 hashwide(const bool3& v)
        {
            return (math::select(uint3(0x5F17300Du, 0x670D6809u, 0x7AF32C49u), uint3(0xAE131389u, 0x5D1B165Bu, 0x87096CD7u), v));
        }
        bool shuffle(const bool3& left, const bool3& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        bool2 shuffle(const bool3& left, const bool3& right, ShuffleComponent x, ShuffleComponent y)
        {
            return bool2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        bool3 shuffle(const bool3& left, const bool3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return bool3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        bool4 shuffle(const bool3& left, const bool3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return bool4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }

        //=========================================================
	    // math-bool3x2
	    //=========================================================
        bool2x3 transpose(const bool3x2& v)
        {
            return bool2x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z);
        }
        uint hash(const bool3x2& v)
        {
            return math::csum(math::select(uint3(0x9C9F0823u, 0x5A9CA13Bu, 0xAFCDD5EFu), uint3(0xA88D187Du, 0xCF6EBA1Du, 0x9D88E5A1u), v.c0) +
						      math::select(uint3(0xEADF0775u, 0x747A9D7Bu, 0x4111F799u), uint3(0xB5F05AF1u, 0xFD80290Bu, 0x8B65ADB7u), v.c1));
        }
        uint3 hashwide(const bool3x2& v)
        {
            return (math::select(uint3(0xDFF4F563u, 0x7069770Du, 0xD1224537u), uint3(0xE99ED6F3u, 0x48125549u, 0xEEE2123Bu), v.c0) +
                    math::select(uint3(0xE3AD9FE5u, 0xCE1CF8BFu, 0x7BE39F3Bu), uint3(0xFAB9913Fu, 0xB4501269u, 0xE04B89FDu), v.c1));
        }

        //=========================================================
	    // math-bool3x3
	    //=========================================================
        bool3x3 transpose(const bool3x3& v)
        {
            return bool3x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z);
        }
        uint hash(const bool3x3& v)
        {
            return math::csum(math::select(uint3(0xE7579997u, 0xEF7D56C7u, 0x66F38F0Bu), uint3(0x624256A3u, 0x5292ADE1u, 0xD2E590E5u), v.c0) +
                              math::select(uint3(0xF25BE857u, 0x9BC17CE7u, 0xC8B86851u), uint3(0x64095221u, 0xADF428FFu, 0xA3977109u), v.c1) +
                              math::select(uint3(0x745ED837u, 0x9CDC88F5u, 0xFA62D721u), uint3(0x7E4DB1CFu, 0x68EEE0F5u, 0xBC3B0A59u), v.c2));
        }
        uint3 hashwide(const bool3x3& v)
        {
            return (math::select(uint3(0x816EFB5Du, 0xA24E82B7u, 0x45A22087u), uint3(0xFC104C3Bu, 0x5FFF6B19u, 0x5E6CBF3Bu), v.c0) +
                    math::select(uint3(0xB546F2A5u, 0xBBCF63E7u, 0xC53F4755u), uint3(0x6985C229u, 0xE133B0B3u, 0xC3E0A3B9u), v.c1) +
                    math::select(uint3(0xFE31134Fu, 0x712A34D7u, 0x9D77A59Bu), uint3(0x4942CA39u, 0xB40EC62Du, 0x565ED63Fu), v.c2));
        }

        //=========================================================
	    // math-bool3x4
	    //=========================================================
        bool4x3 transpose(const bool3x4& v)
        {
            return bool4x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z,
                v.c3.x, v.c3.y, v.c3.z);
        }
        uint hash(const bool3x4& v)
        {
            return math::csum(math::select(uint3(0x83B58237u, 0x833E3E29u, 0xA9D919BFu), uint3(0xC3EC1D97u, 0xB8B208C7u, 0x5D3ED947u), v.c0) +
						      math::select(uint3(0x4473BBB1u, 0xCBA11D5Fu, 0x685835CFu), uint3(0xC3D32AE1u, 0xB966942Fu, 0xFE9856B3u), v.c1) +
						      math::select(uint3(0xFA3A3285u, 0xAD55999Du, 0xDCDD5341u), uint3(0x94DDD769u, 0xA1E92D39u, 0x4583C801u), v.c2) +
						      math::select(uint3(0x9536A0F5u, 0xAF816615u, 0x9AF8D62Du), uint3(0xE3600729u, 0x5F17300Du, 0x670D6809u), v.c3));
        }
        uint3 hashwide(const bool3x4& v)
        {
            return (math::select(uint3(0x7AF32C49u, 0xAE131389u, 0x5D1B165Bu), uint3(0x87096CD7u, 0x4C7F6DD1u, 0x4822A3E9u), v.c0) +
                    math::select(uint3(0xAAC3C25Du, 0xD21D0945u, 0x88FCAB2Du), uint3(0x614DA60Du, 0x5BA2C50Bu, 0x8C455ACBu), v.c1) +
                    math::select(uint3(0xCD266C89u, 0xF1852A33u, 0x77E35E77u), uint3(0x863E3729u, 0xE191B035u, 0x68586FAFu), v.c2) +
                    math::select(uint3(0xD4DFF6D3u, 0xCB634F4Du, 0x9B13B92Du), uint3(0x4ABF0813u, 0x86068063u, 0xD75513F9u), v.c3));
        }
    }

} // namespace ecs

