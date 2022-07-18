#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// double3
	//=========================================================
    double3::double3(const bool3& v)        { x = v.x ? 1.0 : 0.0; y = v.y ? 1.0 : 0.0; z = v.z ? 1.0 : 0.0; }
    double3::double3(const uint3& v)        { x = (double)v.x;      y = (double)v.y;    z = (double)v.z;    }
    double3::double3(const int3& v)         { x = (double)v.x;      y = (double)v.y;    z = (double)v.z;    }
	//double3::double3(const half3& v)      { x = (double)v.x;      y = (double)v.y;    z = (double)v.z;    }
    double3::double3(const float3& v)       { x = (double)v.x;      y = (double)v.y;    z = (double)v.z;    }
    double3::double3(const double3& v)      { x = v.x;              y = v.y;            z = v.z;            }

    double4 double3::xxxx()  const          { return double4(x, x, x, x); }
    double4 double3::xxxy()  const          { return double4(x, x, x, y); }
    double4 double3::xxxz()  const          { return double4(x, x, x, z); }
    double4 double3::xxyx()  const          { return double4(x, x, y, x); }
    double4 double3::xxyy()  const          { return double4(x, x, y, y); }
    double4 double3::xxyz()  const          { return double4(x, x, y, z); }
    double4 double3::xxzx()  const          { return double4(x, x, z, x); }
    double4 double3::xxzy()  const          { return double4(x, x, z, y); }
    double4 double3::xxzz()  const          { return double4(x, x, z, z); }
    double4 double3::xyxx()  const          { return double4(x, y, x, x); }
    double4 double3::xyxy()  const          { return double4(x, y, x, y); }
    double4 double3::xyxz()  const          { return double4(x, y, x, z); }
    double4 double3::xyyx()  const          { return double4(x, y, y, x); }
    double4 double3::xyyy()  const          { return double4(x, y, y, y); }
    double4 double3::xyyz()  const          { return double4(x, y, y, z); }
    double4 double3::xyzx()  const          { return double4(x, y, z, x); }
    double4 double3::xyzy()  const          { return double4(x, y, z, y); }
    double4 double3::xyzz()  const          { return double4(x, y, z, z); }
    double4 double3::xzxx()  const          { return double4(x, z, x, x); }
    double4 double3::xzxy()  const          { return double4(x, z, x, y); }
    double4 double3::xzxz()  const          { return double4(x, z, x, z); }
    double4 double3::xzyx()  const          { return double4(x, z, y, x); }
    double4 double3::xzyy()  const          { return double4(x, z, y, y); }
    double4 double3::xzyz()  const          { return double4(x, z, y, z); }
    double4 double3::xzzx()  const          { return double4(x, z, z, x); }
    double4 double3::xzzy()  const          { return double4(x, z, z, y); }
    double4 double3::xzzz()  const          { return double4(x, z, z, z); }
    double4 double3::yxxx()  const          { return double4(y, x, x, x); }
    double4 double3::yxxy()  const          { return double4(y, x, x, y); }
    double4 double3::yxxz()  const          { return double4(y, x, x, z); }
    double4 double3::yxyx()  const          { return double4(y, x, y, x); }
    double4 double3::yxyy()  const          { return double4(y, x, y, y); }
    double4 double3::yxyz()  const          { return double4(y, x, y, z); }
    double4 double3::yxzx()  const          { return double4(y, x, z, x); }
    double4 double3::yxzy()  const          { return double4(y, x, z, y); }
    double4 double3::yxzz()  const          { return double4(y, x, z, z); }
    double4 double3::yyxx()  const          { return double4(y, y, x, x); }
    double4 double3::yyxy()  const          { return double4(y, y, x, y); }
    double4 double3::yyxz()  const          { return double4(y, y, x, z); }
    double4 double3::yyyx()  const          { return double4(y, y, y, x); }
    double4 double3::yyyy()  const          { return double4(y, y, y, y); }
    double4 double3::yyyz()  const          { return double4(y, y, y, z); }
    double4 double3::yyzx()  const          { return double4(y, y, z, x); }
    double4 double3::yyzy()  const          { return double4(y, y, z, y); }
    double4 double3::yyzz()  const          { return double4(y, y, z, z); }
    double4 double3::yzxx()  const          { return double4(y, z, x, x); }
    double4 double3::yzxy()  const          { return double4(y, z, x, y); }
    double4 double3::yzxz()  const          { return double4(y, z, x, z); }
    double4 double3::yzyx()  const          { return double4(y, z, y, x); }
    double4 double3::yzyy()  const          { return double4(y, z, y, y); }
    double4 double3::yzyz()  const          { return double4(y, z, y, z); }
    double4 double3::yzzx()  const          { return double4(y, z, z, x); }
    double4 double3::yzzy()  const          { return double4(y, z, z, y); }
    double4 double3::yzzz()  const          { return double4(y, z, z, z); }
    double4 double3::zxxx()  const          { return double4(z, x, x, x); }
    double4 double3::zxxy()  const          { return double4(z, x, x, y); }
    double4 double3::zxxz()  const          { return double4(z, x, x, z); }
    double4 double3::zxyx()  const          { return double4(z, x, y, x); }
    double4 double3::zxyy()  const          { return double4(z, x, y, y); }
    double4 double3::zxyz()  const          { return double4(z, x, y, z); }
    double4 double3::zxzx()  const          { return double4(z, x, z, x); }
    double4 double3::zxzy()  const          { return double4(z, x, z, y); }
    double4 double3::zxzz()  const          { return double4(z, x, z, z); }
    double4 double3::zyxx()  const          { return double4(z, y, x, x); }
    double4 double3::zyxy()  const          { return double4(z, y, x, y); }
    double4 double3::zyxz()  const          { return double4(z, y, x, z); }
    double4 double3::zyyx()  const          { return double4(z, y, y, x); }
    double4 double3::zyyy()  const          { return double4(z, y, y, y); }
    double4 double3::zyyz()  const          { return double4(z, y, y, z); }
    double4 double3::zyzx()  const          { return double4(z, y, z, x); }
    double4 double3::zyzy()  const          { return double4(z, y, z, y); }
    double4 double3::zyzz()  const          { return double4(z, y, z, z); }
    double4 double3::zzxx()  const          { return double4(z, z, x, x); }
    double4 double3::zzxy()  const          { return double4(z, z, x, y); }
    double4 double3::zzxz()  const          { return double4(z, z, x, z); }
    double4 double3::zzyx()  const          { return double4(z, z, y, x); }
    double4 double3::zzyy()  const          { return double4(z, z, y, y); }
    double4 double3::zzyz()  const          { return double4(z, z, y, z); }
    double4 double3::zzzx()  const          { return double4(z, z, z, x); }
    double4 double3::zzzy()  const          { return double4(z, z, z, y); }
    double4 double3::zzzz()  const          { return double4(z, z, z, z); }
    double3 double3::xxx()   const          { return double3(x, x, x); }
    double3 double3::xxy()   const          { return double3(x, x, y); }
    double3 double3::xxz()   const          { return double3(x, x, z); }
    double3 double3::xyx()   const          { return double3(x, y, x); }
    double3 double3::xyy()   const          { return double3(x, y, y); }
    double3 double3::xyz()   const          { return double3(x, y, z); }
    void    double3::xyz(const double3& v)  { x = v.x; y = v.y; z = v.z; }
    double3 double3::xzx()   const          { return double3(x, z, x); }
    double3 double3::xzy()   const          { return double3(x, z, y); }
    void    double3::xzy(const double3& v)  { x = v.x; z = v.y; y = v.z; }
    double3 double3::xzz()   const          { return double3(x, z, z); }
    double3 double3::yxx()   const          { return double3(y, x, x); }
    double3 double3::yxy()   const          { return double3(y, x, y); }
    double3 double3::yxz()   const          { return double3(y, x, z); }
    void    double3::yxz(const double3& v)  { y = v.x; x = v.y; z = v.z; }
    double3 double3::yyx()   const          { return double3(y, y, x); }
    double3 double3::yyy()   const          { return double3(y, y, y); }
    double3 double3::yyz()   const          { return double3(y, y, z); }
    double3 double3::yzx()   const          { return double3(y, z, x); }
    void    double3::yzx(const double3& v)  { y = v.x; z = v.y; x = v.z; }
    double3 double3::yzy()   const          { return double3(y, z, y); }
    double3 double3::yzz()   const          { return double3(y, z, z); }
    double3 double3::zxx()   const          { return double3(z, x, x); }
    double3 double3::zxy()   const          { return double3(z, x, y); }
    void    double3::zxy(const double3& v)  { z = v.x; x = v.y; y = v.z; }
    double3 double3::zxz()   const          { return double3(z, x, z); }
    double3 double3::zyx()   const          { return double3(z, y, x); }
    void    double3::zyx(const double3& v)  { z = v.x; y = v.y; x = v.z; }
    double3 double3::zyy()   const          { return double3(z, y, y); }
    double3 double3::zyz()   const          { return double3(z, y, z); }
    double3 double3::zzx()   const          { return double3(z, z, x); }
    double3 double3::zzy()   const          { return double3(z, z, y); }
    double3 double3::zzz()   const          { return double3(z, z, z); }
    double2 double3::xx()    const          { return double2(x, x); }
    double2 double3::xy()    const          { return double2(x, y); }
    void    double3::xy(const double2& v)   { x = v.x; y = v.y; }
    double2 double3::xz()    const          { return double2(x, z); }
    void    double3::xz(const double2& v)   { x = v.x; z = v.y; }
    double2 double3::yx()    const          { return double2(y, x); }
    void    double3::yx(const double2& v)   { y = v.x; x = v.y; }
    double2 double3::yy()    const          { return double2(y, y); }
    double2 double3::yz()    const          { return double2(y, z); }
    void    double3::yz(const double2& v)   { y = v.x; z = v.y; }
    double2 double3::zx()    const          { return double2(z, x); }
    void    double3::zx(const double2& v)   { z = v.x; x = v.y; }
    double2 double3::zy()    const          { return double2(z, y); }
    void    double3::zy(const double2& v)   { z = v.x; y = v.y; }
    double2 double3::zz()    const          { return double2(z, z); }

	//=========================================================
	// double3x2
	//=========================================================
    double3x2::double3x2(bool v)
	{
		c0 = math::select(double3(0.0), double3(1.0), v);
		c1 = math::select(double3(0.0), double3(1.0), v);
	}
    double3x2::double3x2(const bool3x2& v)
	{
		c0 = math::select(double3(0.0), double3(1.0), v.c0);
		c1 = math::select(double3(0.0), double3(1.0), v.c1);
	}
    double3x2::double3x2(const uint3x2& v)      { c0 = v.c0;  c1 = v.c1; }
    double3x2::double3x2(const int3x2& v)       { c0 = v.c0;  c1 = v.c1; }
    double3x2::double3x2(const float3x2& v)     { c0 = v.c0;  c1 = v.c1; }
    double3x2::double3x2(const double3x2& v)    { c0 = v.c0;  c1 = v.c1; }


	//=========================================================
	// double3x3
	//=========================================================
    double3x3::double3x3(bool v)
	{
		c0 = math::select(double3(0.0), double3(1.0), v);
		c1 = math::select(double3(0.0), double3(1.0), v);
		c2 = math::select(double3(0.0), double3(1.0), v);
	}
    double3x3::double3x3(const bool3x3& v)
	{
		c0 = math::select(double3(0.0), double3(1.0), v.c0);
		c1 = math::select(double3(0.0), double3(1.0), v.c1);
		c2 = math::select(double3(0.0), double3(1.0), v.c2);
	}
    double3x3::double3x3(const uint3x3& v)      { c0 = v.c0;  c1 = v.c1;  c2 = v.c2; }
    double3x3::double3x3(const int3x3& v)       { c0 = v.c0;  c1 = v.c1;  c2 = v.c2; }
    double3x3::double3x3(const float3x3& v)     { c0 = v.c0;  c1 = v.c1;  c2 = v.c2; }
    double3x3::double3x3(const double3x3& v)    { c0 = v.c0;  c1 = v.c1;  c2 = v.c2; }



	//=========================================================
	// double3x4
	//=========================================================
    double3x4::double3x4(bool v)
	{
		c0 = math::select(double3(0.0), double3(1.0), v);
		c1 = math::select(double3(0.0), double3(1.0), v);
		c2 = math::select(double3(0.0), double3(1.0), v);
		c3 = math::select(double3(0.0), double3(1.0), v);
	}

    double3x4::double3x4(const bool3x4& v)
    {
        c0 = math::select(double3(0.0), double3(1.0), v.c0);
        c1 = math::select(double3(0.0), double3(1.0), v.c1);
        c2 = math::select(double3(0.0), double3(1.0), v.c2);
        c3 = math::select(double3(0.0), double3(1.0), v.c3);
    }
    double3x4::double3x4(const uint3x4& v)     {   c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3;  }
    double3x4::double3x4(const int3x4& v)      {   c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3;  }
    double3x4::double3x4(const float3x4& v)    {   c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3;  }
    double3x4::double3x4(const double3x4& v)   {   c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3;  }

    namespace math
    {
        //=========================================================
        // math-double3
        //=========================================================
        double select_shuffle_component(const double3& a, const double3& b, ShuffleComponent component)
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
        uint hash(const double3& v)
        {
            return csum(fold_to_uint(v) * uint3(0xAF0F3103u, 0xE4A056C7u, 0x841D8225u)) + 0xC9393C7Du;
        }
        uint3 hashwide(const double3& v)
        {
            return (fold_to_uint(v) * uint3(0xD42EAFA3u, 0xD9AFD06Du, 0x97A65421u)) + 0x7809205Fu;
        }
        double shuffle(const double3& left, const double3& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        double2 shuffle(const double3& left, const double3& right, ShuffleComponent x, ShuffleComponent y)
        {
            return double2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        double3 shuffle(const double3& left, const double3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return double3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        double4 shuffle(const double3& left, const double3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return double4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }
        //=========================================================
	    // math-double3x2
	    //=========================================================
        double2x3 transpose(const double3x2& v)
        {
            return double2x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z);
        }
        uint hash(const double3x2& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint3(0xEE390C97u, 0x9C8A2F05u, 0x4DDC6509u) +
						      math::fold_to_uint(v.c1) * uint3(0x7CF083CBu, 0x5C4D6CEDu, 0xF9137117u)) + 0xE857DCE1u;
        }
        uint3 hashwide(const double3x2& v)
        {
            return (math::fold_to_uint(v.c0) * uint3(0xF62213C5u, 0x9CDAA959u, 0xAA269ABFu) +
                    math::fold_to_uint(v.c1) * uint3(0xD54BA36Fu, 0xFD0847B9u, 0x8189A683u)) + 0xB139D651u;
        }
        //=========================================================
	    // math-double3x3
	    //=========================================================
        double3x3 transpose(const double3x3& v)
        {
            return double3x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z);
        }
        double3x3 inverse(double3x3 m)
        {
            double3 c0 = m.c0;
            double3 c1 = m.c1;
            double3 c2 = m.c2;

            double3 t0 = double3(c1.x, c2.x, c0.x);
            double3 t1 = double3(c1.y, c2.y, c0.y);
            double3 t2 = double3(c1.z, c2.z, c0.z);

            double3 m0 = t1 * t2.yzx() - t1.yzx() * t2;
            double3 m1 = t0.yzx() * t2 - t0 * t2.yzx();
            double3 m2 = t0 * t1.yzx() - t0.yzx() * t1;

            double rcpDet = 1.0 / csum(t0.zxy() * m0);
            return double3x3(m0, m1, m2) * rcpDet;
        }
        double determinant(double3x3 m)
        {
            double3 c0 = m.c0;
            double3 c1 = m.c1;
            double3 c2 = m.c2;

            double m00 = c1.y * c2.z - c1.z * c2.y;
            double m01 = c0.y * c2.z - c0.z * c2.y;
            double m02 = c0.y * c1.z - c0.z * c1.y;

            return c0.x * m00 - c1.x * m01 + c2.x * m02;
        }
        uint hash(const double3x3& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint3(0xAC5DB57Bu, 0xA91A02EDu, 0xB3C49313u) +
                              math::fold_to_uint(v.c1) * uint3(0xF43A9ABBu, 0x84E7E01Bu, 0x8E055BE5u) +
                              math::fold_to_uint(v.c2) * uint3(0x6E624EB7u, 0x7383ED49u, 0xDD49C23Bu)) + 0xEBD0D005u;
        }
        uint3 hashwide(const double3x3& v)
        {
            return (math::fold_to_uint(v.c0) * uint3(0x91475DF7u, 0x55E84827u, 0x90A285BBu) +
                    math::fold_to_uint(v.c1) * uint3(0x5D19E1D5u, 0xFAAF07DDu, 0x625C45BDu) +
                    math::fold_to_uint(v.c2) * uint3(0xC9F27FCBu, 0x6D2523B1u, 0x6E2BF6A9u)) + 0xCC74B3B7u;
        }
        //=========================================================
	    // math-double3x4
	    //=========================================================
        double4x3 transpose(const double3x4& v)
        {
            return double4x3(
                v.c0.x, v.c0.y, v.c0.z,
                v.c1.x, v.c1.y, v.c1.z,
                v.c2.x, v.c2.y, v.c2.z,
                v.c3.x, v.c3.y, v.c3.z);
        }
        double3x4 fastinverse(const double3x4& m)
        {
            double3 c0 = m.c0;
            double3 c1 = m.c1;
            double3 c2 = m.c2;
            double3 pos = m.c3;

            double3 r0 = double3(c0.x, c1.x, c2.x);
            double3 r1 = double3(c0.y, c1.y, c2.y);
            double3 r2 = double3(c0.z, c1.z, c2.z);

            pos = -(r0 * pos.x + r1 * pos.y + r2 * pos.z);

            return double3x4(r0, r1, r2, pos);
        }
        uint hash(const double3x4& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint3(0xEE390C97u, 0x9C8A2F05u, 0x4DDC6509u) +
                              math::fold_to_uint(v.c1) * uint3(0x7CF083CBu, 0x5C4D6CEDu, 0xF9137117u) +
                              math::fold_to_uint(v.c2) * uint3(0xE857DCE1u, 0xF62213C5u, 0x9CDAA959u) +
                              math::fold_to_uint(v.c3) * uint3(0xAA269ABFu, 0xD54BA36Fu, 0xFD0847B9u)) + 0x8189A683u;
        }
        uint3 hashwide(const double3x4& v)
        {
            return (math::fold_to_uint(v.c0) * uint3(0xB139D651u, 0xE7579997u, 0xEF7D56C7u) +
                    math::fold_to_uint(v.c1) * uint3(0x66F38F0Bu, 0x624256A3u, 0x5292ADE1u) +
                    math::fold_to_uint(v.c2) * uint3(0xD2E590E5u, 0xF25BE857u, 0x9BC17CE7u) +
                    math::fold_to_uint(v.c3) * uint3(0xC8B86851u, 0x64095221u, 0xADF428FFu)) + 0xA3977109u;
        }
    }

} // namespace ecs