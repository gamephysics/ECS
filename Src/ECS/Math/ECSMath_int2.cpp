#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// int2
	//=========================================================
    int2::int2(const bool2& v)      { x = v.x ? 1 : 0;    y = v.y ? 1 : 0; }
    int2::int2(const uint2& v)      { x = (int)v.x;       y = (int)v.y;   }
    int2::int2(const int2& xy)      { x = xy.x;           y = xy.y;       }
    int2::int2(const float2& v)     { x = (int)v.x;       y = (int)v.y;   }
    int2::int2(const double2& v)    { x = (int)v.x;       y = (int)v.y;   }


    int4 int2::xxxx() const         { return int4(x, x, x, x); }
    int4 int2::xxxy() const         { return int4(x, x, x, y); }
    int4 int2::xxyx() const         { return int4(x, x, y, x); }
    int4 int2::xxyy() const         { return int4(x, x, y, y); }
    int4 int2::xyxx() const         { return int4(x, y, x, x); }
    int4 int2::xyxy() const         { return int4(x, y, x, y); }
    int4 int2::xyyx() const         { return int4(x, y, y, x); }
    int4 int2::xyyy() const         { return int4(x, y, y, y); }
    int4 int2::yxxx() const         { return int4(y, x, x, x); }
    int4 int2::yxxy() const         { return int4(y, x, x, y); }
    int4 int2::yxyx() const         { return int4(y, x, y, x); }
    int4 int2::yxyy() const         { return int4(y, x, y, y); }
    int4 int2::yyxx() const         { return int4(y, y, x, x); }
    int4 int2::yyxy() const         { return int4(y, y, x, y); }
    int4 int2::yyyx() const         { return int4(y, y, y, x); }
    int4 int2::yyyy() const         { return int4(y, y, y, y); }
    int3 int2::xxx()  const         { return int3(x, x, x); }
    int3 int2::xxy()  const         { return int3(x, x, y); }
    int3 int2::xyx()  const         { return int3(x, y, x); }
    int3 int2::xyy()  const         { return int3(x, y, y); }
    int3 int2::yxx()  const         { return int3(y, x, x); }
    int3 int2::yxy()  const         { return int3(y, x, y); }
    int3 int2::yyx()  const         { return int3(y, y, x); }
    int3 int2::yyy()  const         { return int3(y, y, y); }
    int2 int2::xx()   const         { return int2(x, x); }
    int2 int2::xy()   const         { return int2(x, y); }
    void int2::xy(const int2& v)    { x = v.x; y = v.y;  }
    int2 int2::yx()   const         { return int2(y, x); }
    void int2::yx(const int2& v)    { y = v.x; x = v.y;  }
    int2 int2::yy()   const         { return int2(y, y); }


	//=========================================================
	// int2x2
	//=========================================================
    int2x2::int2x2(bool v)
	{
		c0 = math::select(int2(0), int2(1), v);
		c1 = math::select(int2(0), int2(1), v);
	}
    int2x2::int2x2(const bool2x2& v)
	{
		c0 = math::select(int2(0), int2(1), v.c0);
		c1 = math::select(int2(0), int2(1), v.c1);
	}
    int2x2::int2x2(const uint2x2& v)    { c0 = (int2)v.c0;    c1 = (int2)v.c1;  }
    int2x2::int2x2(const int2x2& v)     { c0 = v.c0;          c1 = v.c1;        }
    int2x2::int2x2(const float2x2& v)   { c0 = (int2)v.c0;    c1 = (int2)v.c1;  }
    int2x2::int2x2(const double2x2& v)  { c0 = (int2)v.c0;    c1 = (int2)v.c1;  }



	//=========================================================
    // int2x3
    //=========================================================
    int2x3::int2x3(bool v)
	{
		c0 = math::select(int2(0), int2(1), v);
		c1 = math::select(int2(0), int2(1), v);
		c2 = math::select(int2(0), int2(1), v);
	}
    int2x3::int2x3(const bool2x3& v)
	{
		c0 = math::select(int2(0), int2(1), v.c0);
		c1 = math::select(int2(0), int2(1), v.c1);
		c2 = math::select(int2(0), int2(1), v.c2);
	}
    int2x3::int2x3(const uint2x3& v)    { c0 = (int2)v.c0;    c1 = (int2)v.c1;    c2 = (int2)v.c2;  }
    int2x3::int2x3(const int2x3& v)     { c0 = v.c0;          c1 = v.c1;          c2 = v.c2;        }
    int2x3::int2x3(const float2x3& v)   { c0 = (int2)v.c0;    c1 = (int2)v.c1;    c2 = (int2)v.c2;  }
    int2x3::int2x3(const double2x3& v)  { c0 = (int2)v.c0;    c1 = (int2)v.c1;    c2 = (int2)v.c2;  }

	//=========================================================
	// int2x4
	//=========================================================
	int2x4::int2x4(bool v)
	{
		c0 = math::select(int2(0), int2(1), v);
		c1 = math::select(int2(0), int2(1), v);
		c2 = math::select(int2(0), int2(1), v);
		c3 = math::select(int2(0), int2(1), v);
	}

	int2x4::int2x4(const bool2x4& v)
	{
		c0 = math::select(int2(0), int2(1), v.c0);
		c1 = math::select(int2(0), int2(1), v.c1);
		c2 = math::select(int2(0), int2(1), v.c2);
		c3 = math::select(int2(0), int2(1), v.c3);
	}
    int2x4::int2x4(const uint2x4& v)    {   c0 = (int2)v.c0;    c1 = (int2)v.c1;    c2 = (int2)v.c2;    c3 = (int2)v.c3;    }
    int2x4::int2x4(const int2x4& v)		{   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;          }
    int2x4::int2x4(const float2x4& v)   {   c0 = (int2)v.c0;    c1 = (int2)v.c1;    c2 = (int2)v.c2;    c3 = (int2)v.c3;    }
    int2x4::int2x4(const double2x4& v)  {   c0 = (int2)v.c0;    c1 = (int2)v.c1;    c2 = (int2)v.c2;    c3 = (int2)v.c3;    }

    namespace math
    {
        //=========================================================
        // math-int2
        //=========================================================
        int select_shuffle_component(const int2& a, const int2& b, ShuffleComponent component)
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
        uint hash(const int2& v)
        {
            return math::csum(asuint(v) * uint2(0x83B58237u, 0x833E3E29u)) + 0xA9D919BFu;
        }
        uint2 hashwide(const int2& v)
        {
            return (math::asuint(v) * uint2(0xC3EC1D97u, 0xB8B208C7u)) + 0x5D3ED947u;
        }
        int shuffle(const int2& left, const int2& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        int2 shuffle(const int2& left, const int2& right, ShuffleComponent x, ShuffleComponent y)
        {
            return int2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        int3 shuffle(const int2& left, const int2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return int3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        int4 shuffle(const int2& left, const int2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return int4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }
        //=========================================================
        // math-int2x2
        //=========================================================
        int2x2 transpose(const int2x2& v)
        {
            return int2x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y);
        }
        int determinant(const int2x2& m)
        {
            int a = m.c0.x;
            int b = m.c1.x;
            int c = m.c0.y;
            int d = m.c1.y;

            return a * d - b * c;
        }
        uint hash(const int2x2& v)
        {
            return math::csum(math::asuint(v.c0) * uint2(0xE191B035u, 0x68586FAFu) +
                              math::asuint(v.c1) * uint2(0xD4DFF6D3u, 0xCB634F4Du)) + 0x9B13B92Du;
        }
        uint2 hashwide(const int2x2& v)
        {
            return (math::asuint(v.c0) * uint2(0x4ABF0813u, 0x86068063u) +
                    math::asuint(v.c1) * uint2(0xD75513F9u, 0x5AB3E8CDu)) + 0x676E8407u;
        }
        //=========================================================
        // math-int2x3
        //=========================================================
        int3x2 transpose(const int2x3& v)
        {
            return int3x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y);
        }
        uint hash(const int2x3& v)
        {
            return math::csum(math::asuint(v.c0) * uint2(0xCAE78587u, 0x7A1541C9u) +
                              math::asuint(v.c1) * uint2(0xF83BD927u, 0x6A243BCBu) +
                              math::asuint(v.c2) * uint2(0x509B84C9u, 0x91D13847u)) + 0x52F7230Fu;
        }
        uint2 hashwide(const int2x3& v)
        {
            return (math::asuint(v.c0) * uint2(0xCF286E83u, 0xE121E6ADu) +
                    math::asuint(v.c1) * uint2(0xC9CA1249u, 0x69B60C81u) +
                    math::asuint(v.c2) * uint2(0xE0EB6C25u, 0xF648BEABu)) + 0x6BDB2B07u;
        }
        //=========================================================
	    // math-int2x4
	    //=========================================================
        int4x2 transpose(const int2x4& v)
        {
            return int4x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y,
                v.c3.x, v.c3.y);
        }
        uint hash(const int2x4& v)
        {
            return math::csum(math::asuint(v.c0) * uint2(0x7AA07CD3u, 0xAF642BA9u) +
						      math::asuint(v.c1) * uint2(0xA8F2213Bu, 0x9F3FDC37u) +
						      math::asuint(v.c2) * uint2(0xAC60D0C3u, 0x9263662Fu) +
						      math::asuint(v.c3) * uint2(0xE69626FFu, 0xBD010EEBu)) + 0x9CEDE1D1u;
        }
        uint2 hashwide(const int2x4& v)
        {
            return (math::asuint(v.c0) * uint2(0x43BE0B51u, 0xAF836EE1u) +
                    math::asuint(v.c1) * uint2(0xB130C137u, 0x54834775u) +
                    math::asuint(v.c2) * uint2(0x7C022221u, 0xA2D00EDFu) +
                    math::asuint(v.c3) * uint2(0xA8977779u, 0x9F1C739Bu)) + 0x4B1BD187u;
        }
    }

} // namespace ecs