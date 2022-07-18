#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// uint4
	//=========================================================
    uint4::uint4(const bool4& v)        { x = v.x ? 1u : 0u;  y = v.y ? 1u : 0u;  z = v.z ? 1u : 0u;  w = v.w ? 1u : 0u;  }
    uint4::uint4(const uint4& v)        { x = v.x;        y = v.y;        z = v.z;        w = v.w;        }
    uint4::uint4(const int4& v)         { x = (uint)v.x;  y = (uint)v.y;  z = (uint)v.z;  w = (uint)v.w;  }
    uint4::uint4(const float4& v)       { x = (uint)v.x;  y = (uint)v.y;  z = (uint)v.z;  w = (uint)v.w;  }
    uint4::uint4(const double4& v)      { x = (uint)v.x;  y = (uint)v.y;  z = (uint)v.z;  w = (uint)v.w;  }

    uint4 uint4::xxxx()    const        { return uint4(x, x, x, x); }
    uint4 uint4::xxxy()    const        { return uint4(x, x, x, y); }
    uint4 uint4::xxxz()    const        { return uint4(x, x, x, z); }
    uint4 uint4::xxxw()    const        { return uint4(x, x, x, w); }
    uint4 uint4::xxyx()    const        { return uint4(x, x, y, x); }
    uint4 uint4::xxyy()    const        { return uint4(x, x, y, y); }
    uint4 uint4::xxyz()    const        { return uint4(x, x, y, z); }
    uint4 uint4::xxyw()    const        { return uint4(x, x, y, w); }
    uint4 uint4::xxzx()    const        { return uint4(x, x, z, x); }
    uint4 uint4::xxzy()    const        { return uint4(x, x, z, y); }
    uint4 uint4::xxzz()    const        { return uint4(x, x, z, z); }
    uint4 uint4::xxzw()    const        { return uint4(x, x, z, w); }
    uint4 uint4::xxwx()    const        { return uint4(x, x, w, x); }
    uint4 uint4::xxwy()    const        { return uint4(x, x, w, y); }
    uint4 uint4::xxwz()    const        { return uint4(x, x, w, z); }
    uint4 uint4::xxww()    const        { return uint4(x, x, w, w); }
    uint4 uint4::xyxx()    const        { return uint4(x, y, x, x); }
    uint4 uint4::xyxy()    const        { return uint4(x, y, x, y); }
    uint4 uint4::xyxz()    const        { return uint4(x, y, x, z); }
    uint4 uint4::xyxw()    const        { return uint4(x, y, x, w); }
    uint4 uint4::xyyx()    const        { return uint4(x, y, y, x); }
    uint4 uint4::xyyy()    const        { return uint4(x, y, y, y); }
    uint4 uint4::xyyz()    const        { return uint4(x, y, y, z); }
    uint4 uint4::xyyw()    const        { return uint4(x, y, y, w); }
    uint4 uint4::xyzx()    const        { return uint4(x, y, z, x); }
    uint4 uint4::xyzy()    const        { return uint4(x, y, z, y); }
    uint4 uint4::xyzz()    const        { return uint4(x, y, z, z); }
    uint4 uint4::xyzw()    const        { return uint4(x, y, z, w); }
    void  uint4::xyzw(const uint4& v)   { x = v.x; y = v.y; z = v.z; w = v.w; }
    uint4 uint4::xywx()    const        { return uint4(x, y, w, x); }
    uint4 uint4::xywy()    const        { return uint4(x, y, w, y); }
    uint4 uint4::xywz()    const        { return uint4(x, y, w, z); }
    void  uint4::xywz(const uint4& v)   { x = v.x; y = v.y; w = v.z; z = v.w; }
    uint4 uint4::xyww()    const        { return uint4(x, y, w, w); }
    uint4 uint4::xzxx()    const        { return uint4(x, z, x, x); }
    uint4 uint4::xzxy()    const        { return uint4(x, z, x, y); }
    uint4 uint4::xzxz()    const        { return uint4(x, z, x, z); }
    uint4 uint4::xzxw()    const        { return uint4(x, z, x, w); }
    uint4 uint4::xzyx()    const        { return uint4(x, z, y, x); }
    uint4 uint4::xzyy()    const        { return uint4(x, z, y, y); }
    uint4 uint4::xzyz()    const        { return uint4(x, z, y, z); }
    uint4 uint4::xzyw()    const        { return uint4(x, z, y, w); }
    void  uint4::xzyw(const uint4& v)   { x = v.x; z = v.y; y = v.z; w = v.w; }
    uint4 uint4::xzzx()    const        { return uint4(x, z, z, x); }
    uint4 uint4::xzzy()    const        { return uint4(x, z, z, y); }
    uint4 uint4::xzzz()    const        { return uint4(x, z, z, z); }
    uint4 uint4::xzzw()    const        { return uint4(x, z, z, w); }
    uint4 uint4::xzwx()    const        { return uint4(x, z, w, x); }
    uint4 uint4::xzwy()    const        { return uint4(x, z, w, y); }
    void  uint4::xzwy(const uint4& v)   { x = v.x; z = v.y; w = v.z; y = v.w; }
    uint4 uint4::xzwz()    const        { return uint4(x, z, w, z); }
    uint4 uint4::xzww()    const        { return uint4(x, z, w, w); }
    uint4 uint4::xwxx()    const        { return uint4(x, w, x, x); }
    uint4 uint4::xwxy()    const        { return uint4(x, w, x, y); }
    uint4 uint4::xwxz()    const        { return uint4(x, w, x, z); }
    uint4 uint4::xwxw()    const        { return uint4(x, w, x, w); }
    uint4 uint4::xwyx()    const        { return uint4(x, w, y, x); }
    uint4 uint4::xwyy()    const        { return uint4(x, w, y, y); }
    uint4 uint4::xwyz()    const        { return uint4(x, w, y, z); }
    void  uint4::xwyz(const uint4& v)   { x = v.x; w = v.y; y = v.z; z = v.w; }
    uint4 uint4::xwyw()    const        { return uint4(x, w, y, w); }
    uint4 uint4::xwzx()    const        { return uint4(x, w, z, x); }
    uint4 uint4::xwzy()    const        { return uint4(x, w, z, y); }
    void  uint4::xwzy(const uint4& v)   { x = v.x; w = v.y; z = v.z; y = v.w; }
    uint4 uint4::xwzz()    const        { return uint4(x, w, z, z); }
    uint4 uint4::xwzw()    const        { return uint4(x, w, z, w); }
    uint4 uint4::xwwx()    const        { return uint4(x, w, w, x); }
    uint4 uint4::xwwy()    const        { return uint4(x, w, w, y); }
    uint4 uint4::xwwz()    const        { return uint4(x, w, w, z); }
    uint4 uint4::xwww()    const        { return uint4(x, w, w, w); }
    uint4 uint4::yxxx()    const        { return uint4(y, x, x, x); }
    uint4 uint4::yxxy()    const        { return uint4(y, x, x, y); }
    uint4 uint4::yxxz()    const        { return uint4(y, x, x, z); }
    uint4 uint4::yxxw()    const        { return uint4(y, x, x, w); }
    uint4 uint4::yxyx()    const        { return uint4(y, x, y, x); }
    uint4 uint4::yxyy()    const        { return uint4(y, x, y, y); }
    uint4 uint4::yxyz()    const        { return uint4(y, x, y, z); }
    uint4 uint4::yxyw()    const        { return uint4(y, x, y, w); }
    uint4 uint4::yxzx()    const        { return uint4(y, x, z, x); }
    uint4 uint4::yxzy()    const        { return uint4(y, x, z, y); }
    uint4 uint4::yxzz()    const        { return uint4(y, x, z, z); }
    uint4 uint4::yxzw()    const        { return uint4(y, x, z, w); }
    void  uint4::yxzw(const uint4& v)   { y = v.x; x = v.y; z = v.z; w = v.w; }
    uint4 uint4::yxwx()    const        { return uint4(y, x, w, x); }
    uint4 uint4::yxwy()    const        { return uint4(y, x, w, y); }
    uint4 uint4::yxwz()    const        { return uint4(y, x, w, z); }
    void  uint4::yxwz(const uint4& v)   { y = v.x; x = v.y; w = v.z; z = v.w; }
    uint4 uint4::yxww()    const        { return uint4(y, x, w, w); }
    uint4 uint4::yyxx()    const        { return uint4(y, y, x, x); }
    uint4 uint4::yyxy()    const        { return uint4(y, y, x, y); }
    uint4 uint4::yyxz()    const        { return uint4(y, y, x, z); }
    uint4 uint4::yyxw()    const        { return uint4(y, y, x, w); }
    uint4 uint4::yyyx()    const        { return uint4(y, y, y, x); }
    uint4 uint4::yyyy()    const        { return uint4(y, y, y, y); }
    uint4 uint4::yyyz()    const        { return uint4(y, y, y, z); }
    uint4 uint4::yyyw()    const        { return uint4(y, y, y, w); }
    uint4 uint4::yyzx()    const        { return uint4(y, y, z, x); }
    uint4 uint4::yyzy()    const        { return uint4(y, y, z, y); }
    uint4 uint4::yyzz()    const        { return uint4(y, y, z, z); }
    uint4 uint4::yyzw()    const        { return uint4(y, y, z, w); }
    uint4 uint4::yywx()    const        { return uint4(y, y, w, x); }
    uint4 uint4::yywy()    const        { return uint4(y, y, w, y); }
    uint4 uint4::yywz()    const        { return uint4(y, y, w, z); }
    uint4 uint4::yyww()    const        { return uint4(y, y, w, w); }
    uint4 uint4::yzxx()    const        { return uint4(y, z, x, x); }
    uint4 uint4::yzxy()    const        { return uint4(y, z, x, y); }
    uint4 uint4::yzxz()    const        { return uint4(y, z, x, z); }
    uint4 uint4::yzxw()    const        { return uint4(y, z, x, w); }
    void  uint4::yzxw(const uint4& v)   { y = v.x; z = v.y; x = v.z; w = v.w; }
    uint4 uint4::yzyx()    const        { return uint4(y, z, y, x); }
    uint4 uint4::yzyy()    const        { return uint4(y, z, y, y); }
    uint4 uint4::yzyz()    const        { return uint4(y, z, y, z); }
    uint4 uint4::yzyw()    const        { return uint4(y, z, y, w); }
    uint4 uint4::yzzx()    const        { return uint4(y, z, z, x); }
    uint4 uint4::yzzy()    const        { return uint4(y, z, z, y); }
    uint4 uint4::yzzz()    const        { return uint4(y, z, z, z); }
    uint4 uint4::yzzw()    const        { return uint4(y, z, z, w); }
    uint4 uint4::yzwx()    const        { return uint4(y, z, w, x); }
    void  uint4::yzwx(const uint4& v)   { y = v.x; z = v.y; w = v.z; x = v.w; }
    uint4 uint4::yzwy()    const        { return uint4(y, z, w, y); }
    uint4 uint4::yzwz()    const        { return uint4(y, z, w, z); }
    uint4 uint4::yzww()    const        { return uint4(y, z, w, w); }
    uint4 uint4::ywxx()    const        { return uint4(y, w, x, x); }
    uint4 uint4::ywxy()    const        { return uint4(y, w, x, y); }
    uint4 uint4::ywxz()    const        { return uint4(y, w, x, z); }
    void  uint4::ywxz(const uint4& v)   { y = v.x; w = v.y; x = v.z; z = v.w; }
    uint4 uint4::ywxw()    const        { return uint4(y, w, x, w); }
    uint4 uint4::ywyx()    const        { return uint4(y, w, y, x); }
    uint4 uint4::ywyy()    const        { return uint4(y, w, y, y); }
    uint4 uint4::ywyz()    const        { return uint4(y, w, y, z); }
    uint4 uint4::ywyw()    const        { return uint4(y, w, y, w); }
    uint4 uint4::ywzx()    const        { return uint4(y, w, z, x); }
    void  uint4::ywzx(const uint4& v)   { y = v.x; w = v.y; z = v.z; x = v.w; }
    uint4 uint4::ywzy()    const        { return uint4(y, w, z, y); }
    uint4 uint4::ywzz()    const        { return uint4(y, w, z, z); }
    uint4 uint4::ywzw()    const        { return uint4(y, w, z, w); }
    uint4 uint4::ywwx()    const        { return uint4(y, w, w, x); }
    uint4 uint4::ywwy()    const        { return uint4(y, w, w, y); }
    uint4 uint4::ywwz()    const        { return uint4(y, w, w, z); }
    uint4 uint4::ywww()    const        { return uint4(y, w, w, w); }
    uint4 uint4::zxxx()    const        { return uint4(z, x, x, x); }
    uint4 uint4::zxxy()    const        { return uint4(z, x, x, y); }
    uint4 uint4::zxxz()    const        { return uint4(z, x, x, z); }
    uint4 uint4::zxxw()    const        { return uint4(z, x, x, w); }
    uint4 uint4::zxyx()    const        { return uint4(z, x, y, x); }
    uint4 uint4::zxyy()    const        { return uint4(z, x, y, y); }
    uint4 uint4::zxyz()    const        { return uint4(z, x, y, z); }
    uint4 uint4::zxyw()    const        { return uint4(z, x, y, w); }
    void  uint4::zxyw(const uint4& v)   { z = v.x; x = v.y; y = v.z; w = v.w; }
    uint4 uint4::zxzx()    const        { return uint4(z, x, z, x); }
    uint4 uint4::zxzy()    const        { return uint4(z, x, z, y); }
    uint4 uint4::zxzz()    const        { return uint4(z, x, z, z); }
    uint4 uint4::zxzw()    const        { return uint4(z, x, z, w); }
    uint4 uint4::zxwx()    const        { return uint4(z, x, w, x); }
    uint4 uint4::zxwy()    const        { return uint4(z, x, w, y); }
    void  uint4::zxwy(const uint4& v)   { z = v.x; x = v.y; w = v.z; y = v.w; }
    uint4 uint4::zxwz()    const        { return uint4(z, x, w, z); }
    uint4 uint4::zxww()    const        { return uint4(z, x, w, w); }
    uint4 uint4::zyxx()    const        { return uint4(z, y, x, x); }
    uint4 uint4::zyxy()    const        { return uint4(z, y, x, y); }
    uint4 uint4::zyxz()    const        { return uint4(z, y, x, z); }
    uint4 uint4::zyxw()    const        { return uint4(z, y, x, w); }
    void  uint4::zyxw(const uint4& v)   { z = v.x; y = v.y; x = v.z; w = v.w; }
    uint4 uint4::zyyx()    const        { return uint4(z, y, y, x); }
    uint4 uint4::zyyy()    const        { return uint4(z, y, y, y); }
    uint4 uint4::zyyz()    const        { return uint4(z, y, y, z); }
    uint4 uint4::zyyw()    const        { return uint4(z, y, y, w); }
    uint4 uint4::zyzx()    const        { return uint4(z, y, z, x); }
    uint4 uint4::zyzy()    const        { return uint4(z, y, z, y); }
    uint4 uint4::zyzz()    const        { return uint4(z, y, z, z); }
    uint4 uint4::zyzw()    const        { return uint4(z, y, z, w); }
    uint4 uint4::zywx()    const        { return uint4(z, y, w, x); }
    void  uint4::zywx(const uint4& v)   { z = v.x; y = v.y; w = v.z; x = v.w; }
    uint4 uint4::zywy()    const        { return uint4(z, y, w, y); }
    uint4 uint4::zywz()    const        { return uint4(z, y, w, z); }
    uint4 uint4::zyww()    const        { return uint4(z, y, w, w); }
    uint4 uint4::zzxx()    const        { return uint4(z, z, x, x); }
    uint4 uint4::zzxy()    const        { return uint4(z, z, x, y); }
    uint4 uint4::zzxz()    const        { return uint4(z, z, x, z); }
    uint4 uint4::zzxw()    const        { return uint4(z, z, x, w); }
    uint4 uint4::zzyx()    const        { return uint4(z, z, y, x); }
    uint4 uint4::zzyy()    const        { return uint4(z, z, y, y); }
    uint4 uint4::zzyz()    const        { return uint4(z, z, y, z); }
    uint4 uint4::zzyw()    const        { return uint4(z, z, y, w); }
    uint4 uint4::zzzx()    const        { return uint4(z, z, z, x); }
    uint4 uint4::zzzy()    const        { return uint4(z, z, z, y); }
    uint4 uint4::zzzz()    const        { return uint4(z, z, z, z); }
    uint4 uint4::zzzw()    const        { return uint4(z, z, z, w); }
    uint4 uint4::zzwx()    const        { return uint4(z, z, w, x); }
    uint4 uint4::zzwy()    const        { return uint4(z, z, w, y); }
    uint4 uint4::zzwz()    const        { return uint4(z, z, w, z); }
    uint4 uint4::zzww()    const        { return uint4(z, z, w, w); }
    uint4 uint4::zwxx()    const        { return uint4(z, w, x, x); }
    uint4 uint4::zwxy()    const        { return uint4(z, w, x, y); }
    void  uint4::zwxy(const uint4& v)   { z = v.x; w = v.y; x = v.z; y = v.w; }
    uint4 uint4::zwxz()    const        { return uint4(z, w, x, z); }
    uint4 uint4::zwxw()    const        { return uint4(z, w, x, w); }
    uint4 uint4::zwyx()    const        { return uint4(z, w, y, x); }
    void  uint4::zwyx(const uint4& v)   { z = v.x; w = v.y; y = v.z; x = v.w; }
    uint4 uint4::zwyy()    const        { return uint4(z, w, y, y); }
    uint4 uint4::zwyz()    const        { return uint4(z, w, y, z); }
    uint4 uint4::zwyw()    const        { return uint4(z, w, y, w); }
    uint4 uint4::zwzx()    const        { return uint4(z, w, z, x); }
    uint4 uint4::zwzy()    const        { return uint4(z, w, z, y); }
    uint4 uint4::zwzz()    const        { return uint4(z, w, z, z); }
    uint4 uint4::zwzw()    const        { return uint4(z, w, z, w); }
    uint4 uint4::zwwx()    const        { return uint4(z, w, w, x); }
    uint4 uint4::zwwy()    const        { return uint4(z, w, w, y); }
    uint4 uint4::zwwz()    const        { return uint4(z, w, w, z); }
    uint4 uint4::zwww()    const        { return uint4(z, w, w, w); }
    uint4 uint4::wxxx()    const        { return uint4(w, x, x, x); }
    uint4 uint4::wxxy()    const        { return uint4(w, x, x, y); }
    uint4 uint4::wxxz()    const        { return uint4(w, x, x, z); }
    uint4 uint4::wxxw()    const        { return uint4(w, x, x, w); }
    uint4 uint4::wxyx()    const        { return uint4(w, x, y, x); }
    uint4 uint4::wxyy()    const        { return uint4(w, x, y, y); }
    uint4 uint4::wxyz()    const        { return uint4(w, x, y, z); }
    void  uint4::wxyz(const uint4& v)   { w = v.x; x = v.y; y = v.z; z = v.w; }
    uint4 uint4::wxyw()    const        { return uint4(w, x, y, w); }
    uint4 uint4::wxzx()    const        { return uint4(w, x, z, x); }
    uint4 uint4::wxzy()    const        { return uint4(w, x, z, y); }
    void  uint4::wxzy(const uint4& v)   { w = v.x; x = v.y; z = v.z; y = v.w; }
    uint4 uint4::wxzz()    const        { return uint4(w, x, z, z); }
    uint4 uint4::wxzw()    const        { return uint4(w, x, z, w); }
    uint4 uint4::wxwx()    const        { return uint4(w, x, w, x); }
    uint4 uint4::wxwy()    const        { return uint4(w, x, w, y); }
    uint4 uint4::wxwz()    const        { return uint4(w, x, w, z); }
    uint4 uint4::wxww()    const        { return uint4(w, x, w, w); }
    uint4 uint4::wyxx()    const        { return uint4(w, y, x, x); }
    uint4 uint4::wyxy()    const        { return uint4(w, y, x, y); }
    uint4 uint4::wyxz()    const        { return uint4(w, y, x, z); }
    void  uint4::wyxz(const uint4& v)   { w = v.x; y = v.y; x = v.z; z = v.w; }
    uint4 uint4::wyxw()    const        { return uint4(w, y, x, w); }
    uint4 uint4::wyyx()    const        { return uint4(w, y, y, x); }
    uint4 uint4::wyyy()    const        { return uint4(w, y, y, y); }
    uint4 uint4::wyyz()    const        { return uint4(w, y, y, z); }
    uint4 uint4::wyyw()    const        { return uint4(w, y, y, w); }
    uint4 uint4::wyzx()    const        { return uint4(w, y, z, x); }
    void  uint4::wyzx(const uint4& v)   { w = v.x; y = v.y; z = v.z; x = v.w; }
    uint4 uint4::wyzy()    const        { return uint4(w, y, z, y); }
    uint4 uint4::wyzz()    const        { return uint4(w, y, z, z); }
    uint4 uint4::wyzw()    const        { return uint4(w, y, z, w); }
    uint4 uint4::wywx()    const        { return uint4(w, y, w, x); }
    uint4 uint4::wywy()    const        { return uint4(w, y, w, y); }
    uint4 uint4::wywz()    const        { return uint4(w, y, w, z); }
    uint4 uint4::wyww()    const        { return uint4(w, y, w, w); }
    uint4 uint4::wzxx()    const        { return uint4(w, z, x, x); }
    uint4 uint4::wzxy()    const        { return uint4(w, z, x, y); }
    void  uint4::wzxy(const uint4& v)   { w = v.x; z = v.y; x = v.z; y = v.w; }
    uint4 uint4::wzxz()    const        { return uint4(w, z, x, z); }
    uint4 uint4::wzxw()    const        { return uint4(w, z, x, w); }
    uint4 uint4::wzyx()    const        { return uint4(w, z, y, x); }
    void  uint4::wzyx(const uint4& v)   { w = v.x; z = v.y; y = v.z; x = v.w; }
    uint4 uint4::wzyy()    const        { return uint4(w, z, y, y); }
    uint4 uint4::wzyz()    const        { return uint4(w, z, y, z); }
    uint4 uint4::wzyw()    const        { return uint4(w, z, y, w); }
    uint4 uint4::wzzx()    const        { return uint4(w, z, z, x); }
    uint4 uint4::wzzy()    const        { return uint4(w, z, z, y); }
    uint4 uint4::wzzz()    const        { return uint4(w, z, z, z); }
    uint4 uint4::wzzw()    const        { return uint4(w, z, z, w); }
    uint4 uint4::wzwx()    const        { return uint4(w, z, w, x); }
    uint4 uint4::wzwy()    const        { return uint4(w, z, w, y); }
    uint4 uint4::wzwz()    const        { return uint4(w, z, w, z); }
    uint4 uint4::wzww()    const        { return uint4(w, z, w, w); }
    uint4 uint4::wwxx()    const        { return uint4(w, w, x, x); }
    uint4 uint4::wwxy()    const        { return uint4(w, w, x, y); }
    uint4 uint4::wwxz()    const        { return uint4(w, w, x, z); }
    uint4 uint4::wwxw()    const        { return uint4(w, w, x, w); }
    uint4 uint4::wwyx()    const        { return uint4(w, w, y, x); }
    uint4 uint4::wwyy()    const        { return uint4(w, w, y, y); }
    uint4 uint4::wwyz()    const        { return uint4(w, w, y, z); }
    uint4 uint4::wwyw()    const        { return uint4(w, w, y, w); }
    uint4 uint4::wwzx()    const        { return uint4(w, w, z, x); }
    uint4 uint4::wwzy()    const        { return uint4(w, w, z, y); }
    uint4 uint4::wwzz()    const        { return uint4(w, w, z, z); }
    uint4 uint4::wwzw()    const        { return uint4(w, w, z, w); }
    uint4 uint4::wwwx()    const        { return uint4(w, w, w, x); }
    uint4 uint4::wwwy()    const        { return uint4(w, w, w, y); }
    uint4 uint4::wwwz()    const        { return uint4(w, w, w, z); }
    uint4 uint4::wwww()    const        { return uint4(w, w, w, w); }
    uint3 uint4::xxx()     const        { return uint3(x, x, x); }
    uint3 uint4::xxy()     const        { return uint3(x, x, y); }
    uint3 uint4::xxz()     const        { return uint3(x, x, z); }
    uint3 uint4::xxw()     const        { return uint3(x, x, w); }
    uint3 uint4::xyx()     const        { return uint3(x, y, x); }
    uint3 uint4::xyy()     const        { return uint3(x, y, y); }
    uint3 uint4::xyz()     const        { return uint3(x, y, z); }
    void  uint4::xyz(const uint3& v)    { x = v.x; y = v.y; z = v.z; }
    uint3 uint4::xyw()     const        { return uint3(x, y, w); }
    void  uint4::xyw(const uint3& v)    { x = v.x; y = v.y; w = v.z; }
    uint3 uint4::xzx()     const        { return uint3(x, z, x); }
    uint3 uint4::xzy()     const        { return uint3(x, z, y); }
    void  uint4::xzy(const uint3& v)    { x = v.x; z = v.y; y = v.z; }
    uint3 uint4::xzz()     const        { return uint3(x, z, z); }
    uint3 uint4::xzw()     const        { return uint3(x, z, w); }
    void  uint4::xzw(const uint3& v)    { x = v.x; z = v.y; w = v.z; }
    uint3 uint4::xwx()     const        { return uint3(x, w, x); }
    uint3 uint4::xwy()     const        { return uint3(x, w, y); }
    void  uint4::xwy(const uint3& v)    { x = v.x; w = v.y; y = v.z; }
    uint3 uint4::xwz()     const        { return uint3(x, w, z); }
    void  uint4::xwz(const uint3& v)    { x = v.x; w = v.y; z = v.z; }
    uint3 uint4::xww()     const        { return uint3(x, w, w); }
    uint3 uint4::yxx()     const        { return uint3(y, x, x); }
    uint3 uint4::yxy()     const        { return uint3(y, x, y); }
    uint3 uint4::yxz()     const        { return uint3(y, x, z); }
    void  uint4::yxz(const uint3& v)    { y = v.x; x = v.y; z = v.z; }
    uint3 uint4::yxw()     const        { return uint3(y, x, w); }
    void  uint4::yxw(const uint3& v)    { y = v.x; x = v.y; w = v.z; }
    uint3 uint4::yyx()     const        { return uint3(y, y, x); }
    uint3 uint4::yyy()     const        { return uint3(y, y, y); }
    uint3 uint4::yyz()     const        { return uint3(y, y, z); }
    uint3 uint4::yyw()     const        { return uint3(y, y, w); }
    uint3 uint4::yzx()     const        { return uint3(y, z, x); }
    void  uint4::yzx(const uint3& v)    { y = v.x; z = v.y; x = v.z; }
    uint3 uint4::yzy()     const        { return uint3(y, z, y); }
    uint3 uint4::yzz()     const        { return uint3(y, z, z); }
    uint3 uint4::yzw()     const        { return uint3(y, z, w); }
    void  uint4::yzw(const uint3& v)    { y = v.x; z = v.y; w = v.z; }
    uint3 uint4::ywx()     const        { return uint3(y, w, x); }
    void  uint4::ywx(const uint3& v)    { y = v.x; w = v.y; x = v.z; }
    uint3 uint4::ywy()     const        { return uint3(y, w, y); }
    uint3 uint4::ywz()     const        { return uint3(y, w, z); }
    void  uint4::ywz(const uint3& v)    { y = v.x; w = v.y; z = v.z; }
    uint3 uint4::yww()     const        { return uint3(y, w, w); }
    uint3 uint4::zxx()     const        { return uint3(z, x, x); }
    uint3 uint4::zxy()     const        { return uint3(z, x, y); }
    void  uint4::zxy(const uint3& v)    { z = v.x; x = v.y; y = v.z; }
    uint3 uint4::zxz()     const        { return uint3(z, x, z); }
    uint3 uint4::zxw()     const        { return uint3(z, x, w); }
    void  uint4::zxw(const uint3& v)    { z = v.x; x = v.y; w = v.z; }
    uint3 uint4::zyx()     const        { return uint3(z, y, x); }
    void  uint4::zyx(const uint3& v)    { z = v.x; y = v.y; x = v.z; }
    uint3 uint4::zyy()     const        { return uint3(z, y, y); }
    uint3 uint4::zyz()     const        { return uint3(z, y, z); }
    uint3 uint4::zyw()     const        { return uint3(z, y, w); }
    void  uint4::zyw(const uint3& v)    { z = v.x; y = v.y; w = v.z; }
    uint3 uint4::zzx()     const        { return uint3(z, z, x); }
    uint3 uint4::zzy()     const        { return uint3(z, z, y); }
    uint3 uint4::zzz()     const        { return uint3(z, z, z); }
    uint3 uint4::zzw()     const        { return uint3(z, z, w); }
    uint3 uint4::zwx()     const        { return uint3(z, w, x); }
    void  uint4::zwx(const uint3& v)    { z = v.x; w = v.y; x = v.z; }
    uint3 uint4::zwy()     const        { return uint3(z, w, y); }
    void  uint4::zwy(const uint3& v)    { z = v.x; w = v.y; y = v.z; }
    uint3 uint4::zwz()     const        { return uint3(z, w, z); }
    uint3 uint4::zww()     const        { return uint3(z, w, w); }
    uint3 uint4::wxx()     const        { return uint3(w, x, x); }
    uint3 uint4::wxy()     const        { return uint3(w, x, y); }
    void  uint4::wxy(const uint3& v)    { w = v.x; x = v.y; y = v.z; }
    uint3 uint4::wxz()     const        { return uint3(w, x, z); }
    void  uint4::wxz(const uint3& v)    { w = v.x; x = v.y; z = v.z; }
    uint3 uint4::wxw()     const        { return uint3(w, x, w); }
    uint3 uint4::wyx()     const        { return uint3(w, y, x); }
    void  uint4::wyx(const uint3& v)    { w = v.x; y = v.y; x = v.z; }
    uint3 uint4::wyy()     const        { return uint3(w, y, y); }
    uint3 uint4::wyz()     const        { return uint3(w, y, z); }
    void  uint4::wyz(const uint3& v)    { w = v.x; y = v.y; z = v.z; }
    uint3 uint4::wyw()     const        { return uint3(w, y, w); }
    uint3 uint4::wzx()     const        { return uint3(w, z, x); }
    void  uint4::wzx(const uint3& v)    { w = v.x; z = v.y; x = v.z; }
    uint3 uint4::wzy()     const        { return uint3(w, z, y); }
    void  uint4::wzy(const uint3& v)    { w = v.x; z = v.y; y = v.z; }
    uint3 uint4::wzz()     const        { return uint3(w, z, z); }
    uint3 uint4::wzw()     const        { return uint3(w, z, w); }
    uint3 uint4::wwx()     const        { return uint3(w, w, x); }
    uint3 uint4::wwy()     const        { return uint3(w, w, y); }
    uint3 uint4::wwz()     const        { return uint3(w, w, z); }
    uint3 uint4::www()     const        { return uint3(w, w, w); }
    uint2 uint4::xx()      const        { return uint2(x, x); }
    uint2 uint4::xy()      const        { return uint2(x, y); }
    void  uint4::xy(const uint2& v)     { x = v.x; y = v.y; }
    uint2 uint4::xz()      const        { return uint2(x, z); }
    void  uint4::xz(const uint2& v)     { x = v.x; z = v.y; }
    uint2 uint4::xw()      const        { return uint2(x, w); }
    void  uint4::xw(const uint2& v)     { x = v.x; w = v.y; }
    uint2 uint4::yx()      const        { return uint2(y, x); }
    void  uint4::yx(const uint2& v)     { y = v.x; x = v.y; }
    uint2 uint4::yy()      const        { return uint2(y, y); }
    uint2 uint4::yz()      const        { return uint2(y, z); }
    void  uint4::yz(const uint2& v)     { y = v.x; z = v.y; }
    uint2 uint4::yw()      const        { return uint2(y, w); }
    void  uint4::yw(const uint2& v)     { y = v.x; w = v.y; }
    uint2 uint4::zx()      const        { return uint2(z, x); }
    void  uint4::zx(const uint2& v)     { z = v.x; x = v.y; }
    uint2 uint4::zy()      const        { return uint2(z, y); }
    void  uint4::zy(const uint2& v)     { z = v.x; y = v.y; }
    uint2 uint4::zz()      const        { return uint2(z, z); }
    uint2 uint4::zw()      const        { return uint2(z, w); }
    void  uint4::zw(const uint2& v)     { z = v.x; w = v.y; }
    uint2 uint4::wx()      const        { return uint2(w, x); }
    void  uint4::wx(const uint2& v)     { w = v.x; x = v.y; }
    uint2 uint4::wy()      const        { return uint2(w, y); }
    void  uint4::wy(const uint2& v)     { w = v.x; y = v.y; }
    uint2 uint4::wz()      const        { return uint2(w, z); }
    void  uint4::wz(const uint2& v)     { w = v.x; z = v.y; }
    uint2 uint4::ww()      const        { return uint2(w, w); }

	//=========================================================
    // uint4x2
	//=========================================================
	uint4x2::uint4x2(bool v)
	{
		c0 = math::select(uint4(0u), uint4(1u), v);
		c1 = math::select(uint4(0u), uint4(1u), v);
	}

	uint4x2::uint4x2(const bool4x2& v)
	{
		c0 = math::select(uint4(0u), uint4(1u), v.c0);
		c1 = math::select(uint4(0u), uint4(1u), v.c1);
	}
    uint4x2::uint4x2(const uint4x2& v)       {   c0 = v.c0;          c1 = v.c1;          }
    uint4x2::uint4x2(const int4x2& v)        {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   }
    uint4x2::uint4x2(const float4x2& v)      {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   }
    uint4x2::uint4x2(const double4x2& v)     {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   }

    //=========================================================
	// uint4x3
	//=========================================================
	uint4x3::uint4x3(bool v)
	{
		c0 = math::select(uint4(0u), uint4(1u), v);
		c1 = math::select(uint4(0u), uint4(1u), v);
		c2 = math::select(uint4(0u), uint4(1u), v);
	}
	uint4x3::uint4x3(const bool4x3& v)
	{
		c0 = math::select(uint4(0u), uint4(1u), v.c0);
		c1 = math::select(uint4(0u), uint4(1u), v.c1);
		c2 = math::select(uint4(0u), uint4(1u), v.c2);
	}
    uint4x3::uint4x3(const uint4x3& v)       {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          }
    uint4x3::uint4x3(const int4x3& v)        {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   c2 = (uint4)v.c2;   }
    uint4x3::uint4x3(const float4x3& v)      {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   c2 = (uint4)v.c2;   }
    uint4x3::uint4x3(const double4x3& v)     {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   c2 = (uint4)v.c2;   }

    //=========================================================
	// uint4x4
	//=========================================================
	uint4x4::uint4x4(bool v)
	{
		c0 = math::select(uint4(0u), uint4(1u), v);
		c1 = math::select(uint4(0u), uint4(1u), v);
		c2 = math::select(uint4(0u), uint4(1u), v);
		c3 = math::select(uint4(0u), uint4(1u), v);
	}
	uint4x4::uint4x4(const bool4x4& v)
	{
		c0 = math::select(uint4(0u), uint4(1u), v.c0);
		c1 = math::select(uint4(0u), uint4(1u), v.c1);
		c2 = math::select(uint4(0u), uint4(1u), v.c2);
		c3 = math::select(uint4(0u), uint4(1u), v.c3);
	}
    uint4x4::uint4x4(const uint4x4& v)      {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;          }
    uint4x4::uint4x4(const int4x4& v)       {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   c2 = (uint4)v.c2;   c3 = (uint4)v.c3;   }
    uint4x4::uint4x4(const float4x4& v)     {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   c2 = (uint4)v.c2;   c3 = (uint4)v.c3;   }
    uint4x4::uint4x4(const double4x4& v)    {   c0 = (uint4)v.c0;   c1 = (uint4)v.c1;   c2 = (uint4)v.c2;   c3 = (uint4)v.c3;   }

    namespace math
    {
        //=========================================================
        // math-uint4
        //=========================================================
        uint select_shuffle_component(const uint4& a, const uint4& b, ShuffleComponent component)
        {
            switch(component)
            {
                case ShuffleComponent::LeftX:
                    return a.x;
                case ShuffleComponent::LeftY:
                    return a.y;
                case ShuffleComponent::LeftZ:
                    return a.z;
                case ShuffleComponent::LeftW:
                    return a.w;
                case ShuffleComponent::RightX:
                    return b.x;
                case ShuffleComponent::RightY:
                    return b.y;
                case ShuffleComponent::RightZ:
                    return b.z;
                case ShuffleComponent::RightW:
                    return b.w;
                default:
                    throw std::exception(std::format("Invalid shuffle component: {}",static_cast<int>(component)).c_str());
            }
        }
        uint hash(const uint4& v)
        {
            return csum(v * uint4(0xB492BF15u, 0xD37220E3u, 0x7AA2C2BDu, 0xE16BC89Du)) + 0x7AA07CD3u;
        }
        uint4 hashwide(const uint4& v)
        {
            return (v * uint4(0xAF642BA9u, 0xA8F2213Bu, 0x9F3FDC37u, 0xAC60D0C3u)) + 0x9263662Fu;
        }
        uint shuffle(const uint4& left, const uint4& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        uint2 shuffle(const uint4& left, const uint4& right, ShuffleComponent x, ShuffleComponent y)
        {
            return uint2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        uint3 shuffle(const uint4& left, const uint4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return uint3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        uint4 shuffle(const uint4& left, const uint4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return uint4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }

        //=========================================================
        // math-uint4x2
        //=========================================================
        uint2x4 transpose(const uint4x2& v)
        {
            return uint2x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w);
        }
        uint hash(const uint4x2& v)
        {
            return csum(v.c0 * uint4(0xFA3A3285u, 0xAD55999Du, 0xDCDD5341u, 0x94DDD769u) +
                        v.c1 * uint4(0xA1E92D39u, 0x4583C801u, 0x9536A0F5u, 0xAF816615u)) + 0x9AF8D62Du;
        }
        uint4 hashwide(const uint4x2& v)
        {
            return (v.c0 * uint4(0xE3600729u, 0x5F17300Du, 0x670D6809u, 0x7AF32C49u) +
                    v.c1 * uint4(0xAE131389u, 0x5D1B165Bu, 0x87096CD7u, 0x4C7F6DD1u)) + 0x4822A3E9u;
        }

        //=========================================================
        // math-uint4x3
        //=========================================================
        uint3x4 transpose(const uint4x3& v)
        {
            return uint3x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w);
        }
        uint hash(const uint4x3& v)
        {
            return csum(v.c0 * uint4(0xE7579997u, 0xEF7D56C7u, 0x66F38F0Bu, 0x624256A3u) +
                        v.c1 * uint4(0x5292ADE1u, 0xD2E590E5u, 0xF25BE857u, 0x9BC17CE7u) +
                        v.c2 * uint4(0xC8B86851u, 0x64095221u, 0xADF428FFu, 0xA3977109u)) + 0x745ED837u;
        }
        uint4 hashwide(const uint4x3& v)
        {
            return (v.c0 * uint4(0x9CDC88F5u, 0xFA62D721u, 0x7E4DB1CFu, 0x68EEE0F5u) +
                    v.c1 * uint4(0xBC3B0A59u, 0x816EFB5Du, 0xA24E82B7u, 0x45A22087u) +
                    v.c2 * uint4(0xFC104C3Bu, 0x5FFF6B19u, 0x5E6CBF3Bu, 0xB546F2A5u)) + 0xBBCF63E7u;
        }

        //=========================================================
        // math-uint4x4
        //=========================================================
        uint4x4 transpose(const uint4x4& v)
        {
            return uint4x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w,
                v.c3.x, v.c3.y, v.c3.z, v.c3.w);
        }
        uint hash(const uint4x4& v)
        {
            return csum(v.c0 * uint4(0x9C9F0823u, 0x5A9CA13Bu, 0xAFCDD5EFu, 0xA88D187Du) +
                        v.c1 * uint4(0xCF6EBA1Du, 0x9D88E5A1u, 0xEADF0775u, 0x747A9D7Bu) +
                        v.c2 * uint4(0x4111F799u, 0xB5F05AF1u, 0xFD80290Bu, 0x8B65ADB7u) +
                        v.c3 * uint4(0xDFF4F563u, 0x7069770Du, 0xD1224537u, 0xE99ED6F3u)) + 0x48125549u;
        }
        uint4 hashwide(const uint4x4& v)
        {
            return (v.c0 * uint4(0xEEE2123Bu, 0xE3AD9FE5u, 0xCE1CF8BFu, 0x7BE39F3Bu) +
                    v.c1 * uint4(0xFAB9913Fu, 0xB4501269u, 0xE04B89FDu, 0xDB3DE101u) +
                    v.c2 * uint4(0x7B6D1B4Bu, 0x58399E77u, 0x5EAC29C9u, 0xFC6014F9u) +
                    v.c3 * uint4(0x6BF6693Fu, 0x9D1B1D9Bu, 0xF842F5C1u, 0xA47EC335u)) + 0xA477DF57u;
        }
    }

} // namespace ecs

