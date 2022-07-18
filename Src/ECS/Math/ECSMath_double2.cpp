#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// double2
	//=========================================================
    double2::double2(const bool2& v)        { x = v.x ? 1.0 : 0.0;  y = v.y ? 1.0 : 0.0; }
    double2::double2(const uint2& v)        { x = (double)v.x;      y = (double)v.y;    }
    double2::double2(const int2& v)         { x = (double)v.x;      y = (double)v.y;    }
    //double2::double2(const half2& v)      { x = (double)v.x;      y = (double)v.y;    }
    double2::double2(const float2& v)       { x = (double)v.x;      y = (double)v.y;    }
    double2::double2(const double2& v)      { x = v.x;              y = v.y;            }


    double4 double2::xxxx() const           { return double4(x, x, x, x); }
    double4 double2::xxxy() const           { return double4(x, x, x, y); }
    double4 double2::xxyx() const           { return double4(x, x, y, x); }
    double4 double2::xxyy() const           { return double4(x, x, y, y); }
    double4 double2::xyxx() const           { return double4(x, y, x, x); }
    double4 double2::xyxy() const           { return double4(x, y, x, y); }
    double4 double2::xyyx() const           { return double4(x, y, y, x); }
    double4 double2::xyyy() const           { return double4(x, y, y, y); }
    double4 double2::yxxx() const           { return double4(y, x, x, x); }
    double4 double2::yxxy() const           { return double4(y, x, x, y); }
    double4 double2::yxyx() const           { return double4(y, x, y, x); }
    double4 double2::yxyy() const           { return double4(y, x, y, y); }
    double4 double2::yyxx() const           { return double4(y, y, x, x); }
    double4 double2::yyxy() const           { return double4(y, y, x, y); }
    double4 double2::yyyx() const           { return double4(y, y, y, x); }
    double4 double2::yyyy() const           { return double4(y, y, y, y); }
    double3 double2::xxx()  const           { return double3(x, x, x); }
    double3 double2::xxy()  const           { return double3(x, x, y); }
    double3 double2::xyx()  const           { return double3(x, y, x); }
    double3 double2::xyy()  const           { return double3(x, y, y); }
    double3 double2::yxx()  const           { return double3(y, x, x); }
    double3 double2::yxy()  const           { return double3(y, x, y); }
    double3 double2::yyx()  const           { return double3(y, y, x); }
    double3 double2::yyy()  const           { return double3(y, y, y); }
    double2 double2::xx()   const           { return double2(x, x); }
    double2 double2::xy()   const           { return double2(x, y); }
    void    double2::xy(const double2& v)   { x = v.x; y = v.y; }
    double2 double2::yx()   const           { return double2(y, x); }
    void    double2::yx(const double2& v)   { y = v.x; x = v.y; }
    double2 double2::yy()   const           { return double2(y, y); }


	//=========================================================
	// double2x2
	//=========================================================
    double2x2::double2x2(bool v)
	{
		c0 = math::select(double2(0.0), double2(1.0), v);
		c1 = math::select(double2(0.0), double2(1.0), v);
	}
    double2x2::double2x2(const bool2x2& v)
	{
		c0 = math::select(double2(0.0), double2(1.0), v.c0);
		c1 = math::select(double2(0.0), double2(1.0), v.c1);
	}
    double2x2::double2x2(const uint2x2& v)            {   c0 = v.c0;  c1 = v.c1;  }
    double2x2::double2x2(const int2x2& v)             {   c0 = v.c0;  c1 = v.c1;  }
    double2x2::double2x2(const float2x2& v)           {   c0 = v.c0;  c1 = v.c1;  }
    double2x2::double2x2(const double2x2& v)          {   c0 = v.c0;  c1 = v.c1;  }


	//=========================================================
	// double2x3
	//=========================================================
    double2x3::double2x3(bool v)
    {
        c0 = math::select(double2(0.0), double2(1.0), v);
        c1 = math::select(double2(0.0), double2(1.0), v);
        c2 = math::select(double2(0.0), double2(1.0), v);
    }
    double2x3::double2x3(const bool2x3& v)
	{
		c0 = math::select(double2(0.0), double2(1.0), v.c0);
		c1 = math::select(double2(0.0), double2(1.0), v.c1);
		c2 = math::select(double2(0.0), double2(1.0), v.c2);
	}
    double2x3::double2x3(const uint2x3& v)     {   c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  }
    double2x3::double2x3(const int2x3& v)      {   c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  }
    double2x3::double2x3(const float2x3& v)    {   c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  }
    double2x3::double2x3(const double2x3& v)   {   c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  }

	//=========================================================
    // double2x4
    //=========================================================
    double2x4::double2x4(bool v)
	{
		c0 = math::select(double2(0.0), double2(1.0), v);
		c1 = math::select(double2(0.0), double2(1.0), v);
		c2 = math::select(double2(0.0), double2(1.0), v);
		c3 = math::select(double2(0.0), double2(1.0), v);
	}
    double2x4::double2x4(const bool2x4& v)
	{
		c0 = math::select(double2(0.0), double2(1.0), v.c0);
		c1 = math::select(double2(0.0), double2(1.0), v.c1);
		c2 = math::select(double2(0.0), double2(1.0), v.c2);
		c3 = math::select(double2(0.0), double2(1.0), v.c3);
	}
    double2x4::double2x4(const uint2x4& v)      { c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3; }
    double2x4::double2x4(const int2x4& v)       { c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3; }
    double2x4::double2x4(const float2x4& v)     { c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3; }
    double2x4::double2x4(const double2x4& v)    { c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3; }

    namespace math
    {
        //=========================================================
	    // math-double2
	    //=========================================================
        double select_shuffle_component(const double2& a, const double2& b, ShuffleComponent component)
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
        uint hash(const double2& v)
        {
            return math::csum(math::fold_to_uint(v) * uint2(0x9536A0F5u, 0xAF816615u)) + 0x9AF8D62Du;
        }
        uint2 hashwide(const double2& v)
        {
            return (math::fold_to_uint(v) * uint2(0xE3600729u, 0x5F17300Du)) + 0x670D6809u;
        }
        double shuffle(const double2& left, const double2& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        double2 shuffle(const double2& left, const double2& right, ShuffleComponent x, ShuffleComponent y)
        {
            return double2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        double3 shuffle(const double2& left, const double2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return double3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        double4 shuffle(const double2& left, const double2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return double4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }
    
        //=========================================================
        // math-double2x2
        //=========================================================
        double2x2 transpose(const double2x2& v)
        {
            return double2x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y);
        }
        double2x2 inverse(const double2x2& m)
        {
            double a = m.c0.x;
            double b = m.c1.x;
            double c = m.c0.y;
            double d = m.c1.y;

            double det = a * d - b * c;

            return double2x2(d, -b, -c, a) * (1.0 / det);
        }
        double determinant(const double2x2& m)
        {
            double a = m.c0.x;
            double b = m.c1.x;
            double c = m.c0.y;
            double d = m.c1.y;

            return a * d - b * c;
        }
        uint hash(const double2x2& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint2(0xFD80290Bu, 0x8B65ADB7u) +
                              math::fold_to_uint(v.c1) * uint2(0xDFF4F563u, 0x7069770Du)) + 0xD1224537u;
        }
        uint2 hashwide(const double2x2& v)
        {
            return (math::fold_to_uint(v.c0) * uint2(0xE99ED6F3u, 0x48125549u) +
                    math::fold_to_uint(v.c1) * uint2(0xEEE2123Bu, 0xE3AD9FE5u)) + 0xCE1CF8BFu;
        }
        //=========================================================
        // math-double2x3
        //=========================================================
        double3x2 transpose(const double2x3& v)
        {
            return double3x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y);
        }
        uint hash(const double2x3& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint2(0xF25BE857u, 0x9BC17CE7u) +
						      math::fold_to_uint(v.c1) * uint2(0xC8B86851u, 0x64095221u) +
						      math::fold_to_uint(v.c2) * uint2(0xADF428FFu, 0xA3977109u)) + 0x745ED837u;
        }
        uint2 hashwide(const double2x3& v)
        {
            return (math::fold_to_uint(v.c0) * uint2(0x9CDC88F5u, 0xFA62D721u) +
                    math::fold_to_uint(v.c1) * uint2(0x7E4DB1CFu, 0x68EEE0F5u) +
                    math::fold_to_uint(v.c2) * uint2(0xBC3B0A59u, 0x816EFB5Du)) + 0xA24E82B7u;
        }

        //=========================================================
        // math-double2x4
        //=========================================================
        double4x2 transpose(const double2x4& v)
        {
            return double4x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y,
                v.c3.x, v.c3.y);
        }
        uint hash(const double2x4& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint2(0x91475DF7u, 0x55E84827u) +
						      math::fold_to_uint(v.c1) * uint2(0x90A285BBu, 0x5D19E1D5u) +
						      math::fold_to_uint(v.c2) * uint2(0xFAAF07DDu, 0x625C45BDu) +
						      math::fold_to_uint(v.c3) * uint2(0xC9F27FCBu, 0x6D2523B1u)) + 0x6E2BF6A9u;
        }
        uint2 hashwide(const double2x4& v)
        {
            return (math::fold_to_uint(v.c0) * uint2(0xCC74B3B7u, 0x83B58237u) +
                    math::fold_to_uint(v.c1) * uint2(0x833E3E29u, 0xA9D919BFu) +
                    math::fold_to_uint(v.c2) * uint2(0xC3EC1D97u, 0xB8B208C7u) +
                    math::fold_to_uint(v.c3) * uint2(0x5D3ED947u, 0x4473BBB1u)) + 0xCBA11D5Fu;
        }
    }

} // namespace ecs

