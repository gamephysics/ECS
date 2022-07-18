#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// bool2
    //=========================================================
    bool4 bool2::xxxx() const           { return bool4(x, x, x, x); }	
	bool4 bool2::xxxy() const           { return bool4(x, x, x, y); }	
	bool4 bool2::xxyx() const           { return bool4(x, x, y, x); }	
	bool4 bool2::xxyy() const           { return bool4(x, x, y, y); }	
	bool4 bool2::xyxx() const           { return bool4(x, y, x, x); }	
    bool4 bool2::xyxy() const           { return bool4(x, y, x, y); }	
    bool4 bool2::xyyx() const           { return bool4(x, y, y, x); }	
    bool4 bool2::xyyy() const           { return bool4(x, y, y, y); }	
	bool4 bool2::yxxx() const           { return bool4(y, x, x, x); }	
    bool4 bool2::yxxy() const           { return bool4(y, x, x, y); }	
    bool4 bool2::yxyx() const           { return bool4(y, x, y, x); }	
    bool4 bool2::yxyy() const           { return bool4(y, x, y, y); }	
    bool4 bool2::yyxx() const           { return bool4(y, y, x, x); }	
    bool4 bool2::yyxy() const           { return bool4(y, y, x, y); }	
    bool4 bool2::yyyx() const           { return bool4(y, y, y, x); }	
    bool4 bool2::yyyy() const           { return bool4(y, y, y, y); }	
    bool3 bool2::xxx()  const           { return bool3(x, x, x); }		
	bool3 bool2::xxy()  const           { return bool3(x, x, y); }		
	bool3 bool2::xyx()  const           { return bool3(x, y, x); }		
    bool3 bool2::xyy()  const           { return bool3(x, y, y); }		
    bool3 bool2::yxx()  const           { return bool3(y, x, x); }		
    bool3 bool2::yxy()  const           { return bool3(y, x, y); }		
    bool3 bool2::yyx()  const           { return bool3(y, y, x); }		
    bool3 bool2::yyy()  const           { return bool3(y, y, y); }		
    bool2 bool2::xx()   const           { return bool2(x, x); }			
    bool2 bool2::xy()   const           { return bool2(x, y); }			
	void  bool2::xy(const bool2& v)     { x = v.x;  y = v.y; }	        
    bool2 bool2::yx()   const           { return bool2(y, x); }			
	void  bool2::yx(const bool2& v)     { y = v.x;  x = v.y; }	        
    bool2 bool2::yy()   const           { return bool2(y, y); }			

    //=========================================================
    // math-bool2
    //=========================================================
    bool select_shuffle_component(const bool2& a, const bool2& b, ShuffleComponent component)
    {
        switch (component)
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
    uint hash(const bool2& v)
    {
        return math::csum(math::select(uint2(0x90A285BBu, 0x5D19E1D5u), uint2(0xFAAF07DDu, 0x625C45BDu), v));
    }
    uint2 hashwide(const bool2& v)
    {
        return (math::select(uint2(0xC9F27FCBu, 0x6D2523B1u), uint2(0x6E2BF6A9u, 0xCC74B3B7u), v));
    }
    bool shuffle(const bool2& left, const bool2& right, ShuffleComponent x)
    {
        return select_shuffle_component(left, right, x);
    }
    bool2 shuffle(const bool2& left, const bool2& right, ShuffleComponent x, ShuffleComponent y)
    {
        return bool2(
            select_shuffle_component(left, right, x),
            select_shuffle_component(left, right, y));
    }
    bool3 shuffle(const bool2& left, const bool2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
    {
        return bool3(
            select_shuffle_component(left, right, x),
            select_shuffle_component(left, right, y),
            select_shuffle_component(left, right, z));
    }
    bool4 shuffle(const bool2& left, const bool2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
    {
        return bool4(
            select_shuffle_component(left, right, x),
            select_shuffle_component(left, right, y),
            select_shuffle_component(left, right, z),
            select_shuffle_component(left, right, w));
    }

    namespace math
    {
        //=========================================================
        // math-bool2x2
        //=========================================================
        bool2x2 transpose(const bool2x2& v)
        {
            return bool2x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y);
        }
        uint hash(const bool2x2& v)
        {
            return math::csum(math::select(uint2(0x7AF32C49u, 0xAE131389u), uint2(0x5D1B165Bu, 0x87096CD7u), v.c0) +
						      math::select(uint2(0x4C7F6DD1u, 0x4822A3E9u), uint2(0xAAC3C25Du, 0xD21D0945u), v.c1));
        }
        uint2 hashwide(const bool2x2& v)
        {
            return (math::select(uint2(0x88FCAB2Du, 0x614DA60Du), uint2(0x5BA2C50Bu, 0x8C455ACBu), v.c0) +
                    math::select(uint2(0xCD266C89u, 0xF1852A33u), uint2(0x77E35E77u, 0x863E3729u), v.c1));
        }

        //=========================================================
        // math-bool2x3
        //=========================================================
        bool3x2 transpose(const bool2x3& v)
        {
            return bool3x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y);
        }
        uint hash(const bool2x3& v)
        {
            return math::csum(math::select(uint2(0x7BE39F3Bu, 0xFAB9913Fu), uint2(0xB4501269u, 0xE04B89FDu), v.c0) +
                              math::select(uint2(0xDB3DE101u, 0x7B6D1B4Bu), uint2(0x58399E77u, 0x5EAC29C9u), v.c1) +
                              math::select(uint2(0xFC6014F9u, 0x6BF6693Fu), uint2(0x9D1B1D9Bu, 0xF842F5C1u), v.c2));
        }
        uint2 hashwide(const bool2x3& v)
        {
            return (math::select(uint2(0xA47EC335u, 0xA477DF57u), uint2(0xC4B1493Fu, 0xBA0966D3u), v.c0) +
                    math::select(uint2(0xAFBEE253u, 0x5B419C01u), uint2(0x515D90F5u, 0xEC9F68F3u), v.c1) +
                    math::select(uint2(0xF9EA92D5u, 0xC2FAFCB9u), uint2(0x616E9CA1u, 0xC5C5394Bu), v.c2));
        }

        //=========================================================
        // math-bool2x4
        //=========================================================
        bool4x2 transpose(const bool2x4& v)
        {
            return bool4x2(
                v.c0.x, v.c0.y,
                v.c1.x, v.c1.y,
                v.c2.x, v.c2.y,
                v.c3.x, v.c3.y);
        }
        uint hash(const bool2x4& v)
        {
            return math::csum(math::select(uint2(0x45A22087u, 0xFC104C3Bu), uint2(0x5FFF6B19u, 0x5E6CBF3Bu), v.c0) +
                              math::select(uint2(0xB546F2A5u, 0xBBCF63E7u), uint2(0xC53F4755u, 0x6985C229u), v.c1) +
                              math::select(uint2(0xE133B0B3u, 0xC3E0A3B9u), uint2(0xFE31134Fu, 0x712A34D7u), v.c2) +
                              math::select(uint2(0x9D77A59Bu, 0x4942CA39u), uint2(0xB40EC62Du, 0x565ED63Fu), v.c3));
        }
        uint2 hashwide(const bool2x4& v)
        {
            return (math::select(uint2(0x93C30C2Bu, 0xDCAF0351u), uint2(0x6E050B01u, 0x750FDBF5u), v.c0) +
                    math::select(uint2(0x7F3DD499u, 0x52EAAEBBu), uint2(0x4599C793u, 0x83B5E729u), v.c1) +
                    math::select(uint2(0xC267163Fu, 0x67BC9149u), uint2(0xAD7C5EC1u, 0x822A7D6Du), v.c2) +
                    math::select(uint2(0xB492BF15u, 0xD37220E3u), uint2(0x7AA2C2BDu, 0xE16BC89Du), v.c3));
        }
    }

} // namespace ecs