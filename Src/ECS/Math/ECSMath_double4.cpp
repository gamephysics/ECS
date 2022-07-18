#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// double4
	//=========================================================
    double4::double4(const bool4& v)        {   x = v.x ? 1.0 : 0.0;y = v.y ? 1.0 : 0.0;z = v.z ? 1.0 : 0.0;w = v.w ? 1.0 : 0.0;}
    double4::double4(const uint4& v)        {   x = (double)v.x;    y = (double)v.y;    z = (double)v.z;    w = (double)v.w;    }
    double4::double4(const int4& v)         {   x = (double)v.x;    y = (double)v.y;    z = (double)v.z;    w = (double)v.w;    }
    //double4::double4(const half4& v)      {   x = (double)v.x;    y = (double)v.y;    z = (double)v.z;    w = (double)v.w;    }
    double4::double4(const float4& v)       {   x = (double)v.x;    y = (double)v.y;    z = (double)v.z;    w = (double)v.w;    }
    double4::double4(const double4& v)      {   x = v.x;            y = v.y;            z = v.z;            w = v.w;            }


    double4 double4::xxxx()  const          { return double4(x, x, x, x); }
    double4 double4::xxxy()  const          { return double4(x, x, x, y); }
    double4 double4::xxxz()  const          { return double4(x, x, x, z); }
    double4 double4::xxxw()  const          { return double4(x, x, x, w); }
    double4 double4::xxyx()  const          { return double4(x, x, y, x); }
    double4 double4::xxyy()  const          { return double4(x, x, y, y); }
    double4 double4::xxyz()  const          { return double4(x, x, y, z); }
    double4 double4::xxyw()  const          { return double4(x, x, y, w); }
    double4 double4::xxzx()  const          { return double4(x, x, z, x); }
    double4 double4::xxzy()  const          { return double4(x, x, z, y); }
    double4 double4::xxzz()  const          { return double4(x, x, z, z); }
    double4 double4::xxzw()  const          { return double4(x, x, z, w); }
    double4 double4::xxwx()  const          { return double4(x, x, w, x); }
    double4 double4::xxwy()  const          { return double4(x, x, w, y); }
    double4 double4::xxwz()  const          { return double4(x, x, w, z); }
    double4 double4::xxww()  const          { return double4(x, x, w, w); }
    double4 double4::xyxx()  const          { return double4(x, y, x, x); }
    double4 double4::xyxy()  const          { return double4(x, y, x, y); }
    double4 double4::xyxz()  const          { return double4(x, y, x, z); }
    double4 double4::xyxw()  const          { return double4(x, y, x, w); }
    double4 double4::xyyx()  const          { return double4(x, y, y, x); }
    double4 double4::xyyy()  const          { return double4(x, y, y, y); }
    double4 double4::xyyz()  const          { return double4(x, y, y, z); }
    double4 double4::xyyw()  const          { return double4(x, y, y, w); }
    double4 double4::xyzx()  const          { return double4(x, y, z, x); }
    double4 double4::xyzy()  const          { return double4(x, y, z, y); }
    double4 double4::xyzz()  const          { return double4(x, y, z, z); }
    double4 double4::xyzw()  const          { return double4(x, y, z, w); }
    void    double4::xyzw(const double4& v) { x = v.x; y = v.y; z = v.z; w = v.w; }
    double4 double4::xywx()  const          { return double4(x, y, w, x); }
    double4 double4::xywy()  const          { return double4(x, y, w, y); }
    double4 double4::xywz()  const          { return double4(x, y, w, z); }
    void    double4::xywz(const double4& v) { x = v.x; y = v.y; w = v.z; z = v.w; }
    double4 double4::xyww()  const          { return double4(x, y, w, w); }
    double4 double4::xzxx()  const          { return double4(x, z, x, x); }
    double4 double4::xzxy()  const          { return double4(x, z, x, y); }
    double4 double4::xzxz()  const          { return double4(x, z, x, z); }
    double4 double4::xzxw()  const          { return double4(x, z, x, w); }
    double4 double4::xzyx()  const          { return double4(x, z, y, x); }
    double4 double4::xzyy()  const          { return double4(x, z, y, y); }
    double4 double4::xzyz()  const          { return double4(x, z, y, z); }
    double4 double4::xzyw()  const          { return double4(x, z, y, w); }
    void    double4::xzyw(const double4& v) { x = v.x; z = v.y; y = v.z; w = v.w; }
    double4 double4::xzzx()  const          { return double4(x, z, z, x); }
    double4 double4::xzzy()  const          { return double4(x, z, z, y); }
    double4 double4::xzzz()  const          { return double4(x, z, z, z); }
    double4 double4::xzzw()  const          { return double4(x, z, z, w); }
    double4 double4::xzwx()  const          { return double4(x, z, w, x); }
    double4 double4::xzwy()  const          { return double4(x, z, w, y); }
    void    double4::xzwy(const double4& v) { x = v.x; z = v.y; w = v.z; y = v.w; }
    double4 double4::xzwz()  const          { return double4(x, z, w, z); }
    double4 double4::xzww()  const          { return double4(x, z, w, w); }
    double4 double4::xwxx()  const          { return double4(x, w, x, x); }
    double4 double4::xwxy()  const          { return double4(x, w, x, y); }
    double4 double4::xwxz()  const          { return double4(x, w, x, z); }
    double4 double4::xwxw()  const          { return double4(x, w, x, w); }
    double4 double4::xwyx()  const          { return double4(x, w, y, x); }
    double4 double4::xwyy()  const          { return double4(x, w, y, y); }
    double4 double4::xwyz()  const          { return double4(x, w, y, z); }
    void    double4::xwyz(const double4& v) { x = v.x; w = v.y; y = v.z; z = v.w; }
    double4 double4::xwyw()  const          { return double4(x, w, y, w); }
    double4 double4::xwzx()  const          { return double4(x, w, z, x); }
    double4 double4::xwzy()  const          { return double4(x, w, z, y); }
    void    double4::xwzy(const double4& v) { x = v.x; w = v.y; z = v.z; y = v.w; }
    double4 double4::xwzz()  const          { return double4(x, w, z, z); }
    double4 double4::xwzw()  const          { return double4(x, w, z, w); }
    double4 double4::xwwx()  const          { return double4(x, w, w, x); }
    double4 double4::xwwy()  const          { return double4(x, w, w, y); }
    double4 double4::xwwz()  const          { return double4(x, w, w, z); }
    double4 double4::xwww()  const          { return double4(x, w, w, w); }
    double4 double4::yxxx()  const          { return double4(y, x, x, x); }
    double4 double4::yxxy()  const          { return double4(y, x, x, y); }
    double4 double4::yxxz()  const          { return double4(y, x, x, z); }
    double4 double4::yxxw()  const          { return double4(y, x, x, w); }
    double4 double4::yxyx()  const          { return double4(y, x, y, x); }
    double4 double4::yxyy()  const          { return double4(y, x, y, y); }
    double4 double4::yxyz()  const          { return double4(y, x, y, z); }
    double4 double4::yxyw()  const          { return double4(y, x, y, w); }
    double4 double4::yxzx()  const          { return double4(y, x, z, x); }
    double4 double4::yxzy()  const          { return double4(y, x, z, y); }
    double4 double4::yxzz()  const          { return double4(y, x, z, z); }
    double4 double4::yxzw()  const          { return double4(y, x, z, w); }
    void    double4::yxzw(const double4& v) { y = v.x; x = v.y; z = v.z; w = v.w; }
    double4 double4::yxwx()  const          { return double4(y, x, w, x); }
    double4 double4::yxwy()  const          { return double4(y, x, w, y); }
    double4 double4::yxwz()  const          { return double4(y, x, w, z); }
    void    double4::yxwz(const double4& v) { y = v.x; x = v.y; w = v.z; z = v.w; }
    double4 double4::yxww()  const          { return double4(y, x, w, w); }
    double4 double4::yyxx()  const          { return double4(y, y, x, x); }
    double4 double4::yyxy()  const          { return double4(y, y, x, y); }
    double4 double4::yyxz()  const          { return double4(y, y, x, z); }
    double4 double4::yyxw()  const          { return double4(y, y, x, w); }
    double4 double4::yyyx()  const          { return double4(y, y, y, x); }
    double4 double4::yyyy()  const          { return double4(y, y, y, y); }
    double4 double4::yyyz()  const          { return double4(y, y, y, z); }
    double4 double4::yyyw()  const          { return double4(y, y, y, w); }
    double4 double4::yyzx()  const          { return double4(y, y, z, x); }
    double4 double4::yyzy()  const          { return double4(y, y, z, y); }
    double4 double4::yyzz()  const          { return double4(y, y, z, z); }
    double4 double4::yyzw()  const          { return double4(y, y, z, w); }
    double4 double4::yywx()  const          { return double4(y, y, w, x); }
    double4 double4::yywy()  const          { return double4(y, y, w, y); }
    double4 double4::yywz()  const          { return double4(y, y, w, z); }
    double4 double4::yyww()  const          { return double4(y, y, w, w); }
    double4 double4::yzxx()  const          { return double4(y, z, x, x); }
    double4 double4::yzxy()  const          { return double4(y, z, x, y); }
    double4 double4::yzxz()  const          { return double4(y, z, x, z); }
    double4 double4::yzxw()  const          { return double4(y, z, x, w); }
    void    double4::yzxw(const double4& v) { y = v.x; z = v.y; x = v.z; w = v.w; }
    double4 double4::yzyx()  const          { return double4(y, z, y, x); }
    double4 double4::yzyy()  const          { return double4(y, z, y, y); }
    double4 double4::yzyz()  const          { return double4(y, z, y, z); }
    double4 double4::yzyw()  const          { return double4(y, z, y, w); }
    double4 double4::yzzx()  const          { return double4(y, z, z, x); }
    double4 double4::yzzy()  const          { return double4(y, z, z, y); }
    double4 double4::yzzz()  const          { return double4(y, z, z, z); }
    double4 double4::yzzw()  const          { return double4(y, z, z, w); }
    double4 double4::yzwx()  const          { return double4(y, z, w, x); }
    void    double4::yzwx(const double4& v) { y = v.x; z = v.y; w = v.z; x = v.w; }
    double4 double4::yzwy()  const          { return double4(y, z, w, y); }
    double4 double4::yzwz()  const          { return double4(y, z, w, z); }
    double4 double4::yzww()  const          { return double4(y, z, w, w); }
    double4 double4::ywxx()  const          { return double4(y, w, x, x); }
    double4 double4::ywxy()  const          { return double4(y, w, x, y); }
    double4 double4::ywxz()  const          { return double4(y, w, x, z); }
    void    double4::ywxz(const double4& v) { y = v.x; w = v.y; x = v.z; z = v.w; }
    double4 double4::ywxw()  const          { return double4(y, w, x, w); }
    double4 double4::ywyx()  const          { return double4(y, w, y, x); }
    double4 double4::ywyy()  const          { return double4(y, w, y, y); }
    double4 double4::ywyz()  const          { return double4(y, w, y, z); }
    double4 double4::ywyw()  const          { return double4(y, w, y, w); }
    double4 double4::ywzx()  const          { return double4(y, w, z, x); }
    void    double4::ywzx(const double4& v) { y = v.x; w = v.y; z = v.z; x = v.w; }
    double4 double4::ywzy()  const          { return double4(y, w, z, y); }
    double4 double4::ywzz()  const          { return double4(y, w, z, z); }
    double4 double4::ywzw()  const          { return double4(y, w, z, w); }
    double4 double4::ywwx()  const          { return double4(y, w, w, x); }
    double4 double4::ywwy()  const          { return double4(y, w, w, y); }
    double4 double4::ywwz()  const          { return double4(y, w, w, z); }
    double4 double4::ywww()  const          { return double4(y, w, w, w); }
    double4 double4::zxxx()  const          { return double4(z, x, x, x); }
    double4 double4::zxxy()  const          { return double4(z, x, x, y); }
    double4 double4::zxxz()  const          { return double4(z, x, x, z); }
    double4 double4::zxxw()  const          { return double4(z, x, x, w); }
    double4 double4::zxyx()  const          { return double4(z, x, y, x); }
    double4 double4::zxyy()  const          { return double4(z, x, y, y); }
    double4 double4::zxyz()  const          { return double4(z, x, y, z); }
    double4 double4::zxyw()  const          { return double4(z, x, y, w); }
    void    double4::zxyw(const double4& v) { z = v.x; x = v.y; y = v.z; w = v.w; }
    double4 double4::zxzx()  const          { return double4(z, x, z, x); }
    double4 double4::zxzy()  const          { return double4(z, x, z, y); }
    double4 double4::zxzz()  const          { return double4(z, x, z, z); }
    double4 double4::zxzw()  const          { return double4(z, x, z, w); }
    double4 double4::zxwx()  const          { return double4(z, x, w, x); }
    double4 double4::zxwy()  const          { return double4(z, x, w, y); }
    void    double4::zxwy(const double4& v) { z = v.x; x = v.y; w = v.z; y = v.w; }
    double4 double4::zxwz()  const          { return double4(z, x, w, z); }
    double4 double4::zxww()  const          { return double4(z, x, w, w); }
    double4 double4::zyxx()  const          { return double4(z, y, x, x); }
    double4 double4::zyxy()  const          { return double4(z, y, x, y); }
    double4 double4::zyxz()  const          { return double4(z, y, x, z); }
    double4 double4::zyxw()  const          { return double4(z, y, x, w); }
    void    double4::zyxw(const double4& v) { z = v.x; y = v.y; x = v.z; w = v.w; }
    double4 double4::zyyx()  const          { return double4(z, y, y, x); }
    double4 double4::zyyy()  const          { return double4(z, y, y, y); }
    double4 double4::zyyz()  const          { return double4(z, y, y, z); }
    double4 double4::zyyw()  const          { return double4(z, y, y, w); }
    double4 double4::zyzx()  const          { return double4(z, y, z, x); }
    double4 double4::zyzy()  const          { return double4(z, y, z, y); }
    double4 double4::zyzz()  const          { return double4(z, y, z, z); }
    double4 double4::zyzw()  const          { return double4(z, y, z, w); }
    double4 double4::zywx()  const          { return double4(z, y, w, x); }
    void    double4::zywx(const double4& v) { z = v.x; y = v.y; w = v.z; x = v.w; }
    double4 double4::zywy()  const          { return double4(z, y, w, y); }
    double4 double4::zywz()  const          { return double4(z, y, w, z); }
    double4 double4::zyww()  const          { return double4(z, y, w, w); }
    double4 double4::zzxx()  const          { return double4(z, z, x, x); }
    double4 double4::zzxy()  const          { return double4(z, z, x, y); }
    double4 double4::zzxz()  const          { return double4(z, z, x, z); }
    double4 double4::zzxw()  const          { return double4(z, z, x, w); }
    double4 double4::zzyx()  const          { return double4(z, z, y, x); }
    double4 double4::zzyy()  const          { return double4(z, z, y, y); }
    double4 double4::zzyz()  const          { return double4(z, z, y, z); }
    double4 double4::zzyw()  const          { return double4(z, z, y, w); }
    double4 double4::zzzx()  const          { return double4(z, z, z, x); }
    double4 double4::zzzy()  const          { return double4(z, z, z, y); }
    double4 double4::zzzz()  const          { return double4(z, z, z, z); }
    double4 double4::zzzw()  const          { return double4(z, z, z, w); }
    double4 double4::zzwx()  const          { return double4(z, z, w, x); }
    double4 double4::zzwy()  const          { return double4(z, z, w, y); }
    double4 double4::zzwz()  const          { return double4(z, z, w, z); }
    double4 double4::zzww()  const          { return double4(z, z, w, w); }
    double4 double4::zwxx()  const          { return double4(z, w, x, x); }
    double4 double4::zwxy()  const          { return double4(z, w, x, y); }
    void    double4::zwxy(const double4& v) { z = v.x; w = v.y; x = v.z; y = v.w; }
    double4 double4::zwxz()  const          { return double4(z, w, x, z); }
    double4 double4::zwxw()  const          { return double4(z, w, x, w); }
    double4 double4::zwyx()  const          { return double4(z, w, y, x); }
    void    double4::zwyx(const double4& v) { z = v.x; w = v.y; y = v.z; x = v.w; }
    double4 double4::zwyy()  const          { return double4(z, w, y, y); }
    double4 double4::zwyz()  const          { return double4(z, w, y, z); }
    double4 double4::zwyw()  const          { return double4(z, w, y, w); }
    double4 double4::zwzx()  const          { return double4(z, w, z, x); }
    double4 double4::zwzy()  const          { return double4(z, w, z, y); }
    double4 double4::zwzz()  const          { return double4(z, w, z, z); }
    double4 double4::zwzw()  const          { return double4(z, w, z, w); }
    double4 double4::zwwx()  const          { return double4(z, w, w, x); }
    double4 double4::zwwy()  const          { return double4(z, w, w, y); }
    double4 double4::zwwz()  const          { return double4(z, w, w, z); }
    double4 double4::zwww()  const          { return double4(z, w, w, w); }
    double4 double4::wxxx()  const          { return double4(w, x, x, x); }
    double4 double4::wxxy()  const          { return double4(w, x, x, y); }
    double4 double4::wxxz()  const          { return double4(w, x, x, z); }
    double4 double4::wxxw()  const          { return double4(w, x, x, w); }
    double4 double4::wxyx()  const          { return double4(w, x, y, x); }
    double4 double4::wxyy()  const          { return double4(w, x, y, y); }
    double4 double4::wxyz()  const          { return double4(w, x, y, z); }
    void    double4::wxyz(const double4& v) { w = v.x; x = v.y; y = v.z; z = v.w; }
    double4 double4::wxyw()  const          { return double4(w, x, y, w); }
    double4 double4::wxzx()  const          { return double4(w, x, z, x); }
    double4 double4::wxzy()  const          { return double4(w, x, z, y); }
    void    double4::wxzy(const double4& v) { w = v.x; x = v.y; z = v.z; y = v.w; }
    double4 double4::wxzz()  const          { return double4(w, x, z, z); }
    double4 double4::wxzw()  const          { return double4(w, x, z, w); }
    double4 double4::wxwx()  const          { return double4(w, x, w, x); }
    double4 double4::wxwy()  const          { return double4(w, x, w, y); }
    double4 double4::wxwz()  const          { return double4(w, x, w, z); }
    double4 double4::wxww()  const          { return double4(w, x, w, w); }
    double4 double4::wyxx()  const          { return double4(w, y, x, x); }
    double4 double4::wyxy()  const          { return double4(w, y, x, y); }
    double4 double4::wyxz()  const          { return double4(w, y, x, z); }
    void    double4::wyxz(const double4& v) { w = v.x; y = v.y; x = v.z; z = v.w; }
    double4 double4::wyxw()  const          { return double4(w, y, x, w); }
    double4 double4::wyyx()  const          { return double4(w, y, y, x); }
    double4 double4::wyyy()  const          { return double4(w, y, y, y); }
    double4 double4::wyyz()  const          { return double4(w, y, y, z); }
    double4 double4::wyyw()  const          { return double4(w, y, y, w); }
    double4 double4::wyzx()  const          { return double4(w, y, z, x); }
    void    double4::wyzx(const double4& v) { w = v.x; y = v.y; z = v.z; x = v.w; }
    double4 double4::wyzy()  const          { return double4(w, y, z, y); }
    double4 double4::wyzz()  const          { return double4(w, y, z, z); }
    double4 double4::wyzw()  const          { return double4(w, y, z, w); }
    double4 double4::wywx()  const          { return double4(w, y, w, x); }
    double4 double4::wywy()  const          { return double4(w, y, w, y); }
    double4 double4::wywz()  const          { return double4(w, y, w, z); }
    double4 double4::wyww()  const          { return double4(w, y, w, w); }
    double4 double4::wzxx()  const          { return double4(w, z, x, x); }
    double4 double4::wzxy()  const          { return double4(w, z, x, y); }
    void    double4::wzxy(const double4& v) { w = v.x; z = v.y; x = v.z; y = v.w; }
    double4 double4::wzxz()  const          { return double4(w, z, x, z); }
    double4 double4::wzxw()  const          { return double4(w, z, x, w); }
    double4 double4::wzyx()  const          { return double4(w, z, y, x); }
    void    double4::wzyx(const double4& v) { w = v.x; z = v.y; y = v.z; x = v.w; }
    double4 double4::wzyy()  const          { return double4(w, z, y, y); }
    double4 double4::wzyz()  const          { return double4(w, z, y, z); }
    double4 double4::wzyw()  const          { return double4(w, z, y, w); }
    double4 double4::wzzx()  const          { return double4(w, z, z, x); }
    double4 double4::wzzy()  const          { return double4(w, z, z, y); }
    double4 double4::wzzz()  const          { return double4(w, z, z, z); }
    double4 double4::wzzw()  const          { return double4(w, z, z, w); }
    double4 double4::wzwx()  const          { return double4(w, z, w, x); }
    double4 double4::wzwy()  const          { return double4(w, z, w, y); }
    double4 double4::wzwz()  const          { return double4(w, z, w, z); }
    double4 double4::wzww()  const          { return double4(w, z, w, w); }
    double4 double4::wwxx()  const          { return double4(w, w, x, x); }
    double4 double4::wwxy()  const          { return double4(w, w, x, y); }
    double4 double4::wwxz()  const          { return double4(w, w, x, z); }
    double4 double4::wwxw()  const          { return double4(w, w, x, w); }
    double4 double4::wwyx()  const          { return double4(w, w, y, x); }
    double4 double4::wwyy()  const          { return double4(w, w, y, y); }
    double4 double4::wwyz()  const          { return double4(w, w, y, z); }
    double4 double4::wwyw()  const          { return double4(w, w, y, w); }
    double4 double4::wwzx()  const          { return double4(w, w, z, x); }
    double4 double4::wwzy()  const          { return double4(w, w, z, y); }
    double4 double4::wwzz()  const          { return double4(w, w, z, z); }
    double4 double4::wwzw()  const          { return double4(w, w, z, w); }
    double4 double4::wwwx()  const          { return double4(w, w, w, x); }
    double4 double4::wwwy()  const          { return double4(w, w, w, y); }
    double4 double4::wwwz()  const          { return double4(w, w, w, z); }
    double4 double4::wwww()  const          { return double4(w, w, w, w); }
    double3 double4::xxx()   const          { return double3(x, x, x); }
    double3 double4::xxy()   const          { return double3(x, x, y); }
    double3 double4::xxz()   const          { return double3(x, x, z); }
    double3 double4::xxw()   const          { return double3(x, x, w); }
    double3 double4::xyx()   const          { return double3(x, y, x); }
    double3 double4::xyy()   const          { return double3(x, y, y); }
    double3 double4::xyz()   const          { return double3(x, y, z); }
    void    double4::xyz(const double3& v)  { x = v.x; y = v.y; z = v.z; }
    double3 double4::xyw()   const          { return double3(x, y, w); }
    void    double4::xyw(const double3& v)  { x = v.x; y = v.y; w = v.z; }
    double3 double4::xzx()   const          { return double3(x, z, x); }
    double3 double4::xzy()   const          { return double3(x, z, y); }
    void    double4::xzy(const double3 &v)  { x = v.x; z = v.y; y = v.z; }
    double3 double4::xzz()   const          { return double3(x, z, z); }
    double3 double4::xzw()   const          { return double3(x, z, w); }
    void    double4::xzw(const double3& v)  { x = v.x; z = v.y; w = v.z; }
    double3 double4::xwx()   const          { return double3(x, w, x); }
    double3 double4::xwy()   const          { return double3(x, w, y); }
    void    double4::xwy(const double3& v)  { x = v.x; w = v.y; y = v.z; }
    double3 double4::xwz()   const          { return double3(x, w, z); }
    void    double4::xwz(const double3& v)  { x = v.x; w = v.y; z = v.z; }
    double3 double4::xww()   const          { return double3(x, w, w); }
    double3 double4::yxx()   const          { return double3(y, x, x); }
    double3 double4::yxy()   const          { return double3(y, x, y); }
    double3 double4::yxz()   const          { return double3(y, x, z); }
    void    double4::yxz(const double3& v)  { y = v.x; x = v.y; z = v.z; }
    double3 double4::yxw()   const          { return double3(y, x, w); }
    void    double4::yxw(const double3& v)  { y = v.x; x = v.y; w = v.z; }
    double3 double4::yyx()   const          { return double3(y, y, x); }
    double3 double4::yyy()   const          { return double3(y, y, y); }
    double3 double4::yyz()   const          { return double3(y, y, z); }
    double3 double4::yyw()   const          { return double3(y, y, w); }
    double3 double4::yzx()   const          { return double3(y, z, x); }
    void    double4::yzx(const double3& v)  { y = v.x; z = v.y; x = v.z; }
    double3 double4::yzy()   const          { return double3(y, z, y); }
    double3 double4::yzz()   const          { return double3(y, z, z); }
    double3 double4::yzw()   const          { return double3(y, z, w); }
    void    double4::yzw(const double3& v)  { y = v.x; z = v.y; w = v.z; }
    double3 double4::ywx()   const          { return double3(y, w, x); }
    void    double4::ywx(const double3& v)  { y = v.x; w = v.y; x = v.z; }
    double3 double4::ywy()   const          { return double3(y, w, y); }
    double3 double4::ywz()   const          { return double3(y, w, z); }
    void    double4::ywz(const double3& v)  { y = v.x; w = v.y; z = v.z; }
    double3 double4::yww()   const          { return double3(y, w, w); }
    double3 double4::zxx()   const          { return double3(z, x, x); }
    double3 double4::zxy()   const          { return double3(z, x, y); }
    void    double4::zxy(const double3& v)  { z = v.x; x = v.y; y = v.z; }
    double3 double4::zxz()   const          { return double3(z, x, z); }
    double3 double4::zxw()   const          { return double3(z, x, w); }
    void    double4::zxw(const double3& v)  { z = v.x; x = v.y; w = v.z; }
    double3 double4::zyx()   const          { return double3(z, y, x); }
    void    double4::zyx(const double3& v)  { z = v.x; y = v.y; x = v.z; }
    double3 double4::zyy()   const          { return double3(z, y, y); }
    double3 double4::zyz()   const          { return double3(z, y, z); }
    double3 double4::zyw()   const          { return double3(z, y, w); }
    void    double4::zyw(const double3& v)  { z = v.x; y = v.y; w = v.z; }
    double3 double4::zzx()   const          { return double3(z, z, x); }
    double3 double4::zzy()   const          { return double3(z, z, y); }
    double3 double4::zzz()   const          { return double3(z, z, z); }
    double3 double4::zzw()   const          { return double3(z, z, w); }
    double3 double4::zwx()   const          { return double3(z, w, x); }
    void    double4::zwx(const double3& v)  { z = v.x; w = v.y; x = v.z; }
    double3 double4::zwy()   const          { return double3(z, w, y); }
    void    double4::zwy(const double3& v)  { z = v.x; w = v.y; y = v.z; }
    double3 double4::zwz()   const          { return double3(z, w, z); }
    double3 double4::zww()   const          { return double3(z, w, w); }
    double3 double4::wxx()   const          { return double3(w, x, x); }
    double3 double4::wxy()   const          { return double3(w, x, y); }
    void    double4::wxy(const double3& v)  { w = v.x; x = v.y; y = v.z; }
    double3 double4::wxz()   const          { return double3(w, x, z); }
    void    double4::wxz(const double3& v)  { w = v.x; x = v.y; z = v.z; }
    double3 double4::wxw()   const          { return double3(w, x, w); }
    double3 double4::wyx()   const          { return double3(w, y, x); }
    void    double4::wyx(const double3& v)  { w = v.x; y = v.y; x = v.z; }
    double3 double4::wyy()   const          { return double3(w, y, y); }
    double3 double4::wyz()   const          { return double3(w, y, z); }
    void    double4::wyz(const double3& v)  { w = v.x; y = v.y; z = v.z; }
    double3 double4::wyw()   const          { return double3(w, y, w); }
    double3 double4::wzx()   const          { return double3(w, z, x); }
    void    double4::wzx(const double3& v)  { w = v.x; z = v.y; x = v.z; }
    double3 double4::wzy()   const          { return double3(w, z, y); }
    void    double4::wzy(const double3& v)  { w = v.x; z = v.y; y = v.z; }
    double3 double4::wzz()   const          { return double3(w, z, z); }
    double3 double4::wzw()   const          { return double3(w, z, w); }
    double3 double4::wwx()   const          { return double3(w, w, x); }
    double3 double4::wwy()   const          { return double3(w, w, y); }
    double3 double4::wwz()   const          { return double3(w, w, z); }
    double3 double4::www()   const          { return double3(w, w, w); }
    double2 double4::xx()    const          { return double2(x, x); }
    double2 double4::xy()    const          { return double2(x, y); }
    void    double4::xy(const double2& v)   { x = v.x; y = v.y; }
    double2 double4::xz()    const          { return double2(x, z); }
    void    double4::xz(const double2& v)   { x = v.x; z = v.y; }
    double2 double4::xw()    const          { return double2(x, w); }
    void    double4::xw(const double2& v)   { x = v.x; w = v.y; }
    double2 double4::yx()    const          { return double2(y, x); }
    void    double4::yx(const double2& v)   { y = v.x; x = v.y; }
    double2 double4::yy()    const          { return double2(y, y); }
    double2 double4::yz()    const          { return double2(y, z); }
    void    double4::yz(const double2& v)   { y = v.x; z = v.y; }
    double2 double4::yw()    const          { return double2(y, w); }
    void    double4::yw(const double2& v)   { y = v.x; w = v.y; }
    double2 double4::zx()    const          { return double2(z, x); }
    void    double4::zx(const double2& v)   { z = v.x; x = v.y; }
    double2 double4::zy()    const          { return double2(z, y); }
    void    double4::zy(const double2& v)   { z = v.x; y = v.y; }
    double2 double4::zz()    const          { return double2(z, z); }
    double2 double4::zw()    const          { return double2(z, w); }
    void    double4::zw(const double2& v)   { z = v.x; w = v.y; }
    double2 double4::wx()    const          { return double2(w, x); }
    void    double4::wx(const double2& v)   { w = v.x; x = v.y; }
    double2 double4::wy()    const          { return double2(w, y); }
    void    double4::wy(const double2& v)   { w = v.x; y = v.y; }
    double2 double4::wz()    const          { return double2(w, z); }
    void    double4::wz(const double2& v)   { w = v.x; z = v.y; }
    double2 double4::ww()    const          { return double2(w, w); }



	//=========================================================
	// double4x2
	//=========================================================
    double4x2::double4x2(bool v)
	{
		c0 = math::select(double4(0.0), double4(1.0), v);
		c1 = math::select(double4(0.0), double4(1.0), v);
	}
    double4x2::double4x2(const bool4x2& v)
	{
		c0 = math::select(double4(0.0), double4(1.0), v.c0);
		c1 = math::select(double4(0.0), double4(1.0), v.c1);
	}
    double4x2::double4x2(const uint4x2& v)      { c0 = v.c0;  c1 = v.c1; }
    double4x2::double4x2(const int4x2& v)       { c0 = v.c0;  c1 = v.c1; }
	double4x2::double4x2(const float4x2& v)     { c0 = v.c0;  c1 = v.c1; }
    double4x2::double4x2(const double4x2& v)    { c0 = v.c0;  c1 = v.c1; }

	//=========================================================
	// double4x3
	//=========================================================
    double4x3::double4x3(bool v)
	{
		c0 = math::select(double4(0.0), double4(1.0), v);
		c1 = math::select(double4(0.0), double4(1.0), v);
		c2 = math::select(double4(0.0), double4(1.0), v);
	}
    double4x3::double4x3(const bool4x3 v)
	{
		c0 = math::select(double4(0.0), double4(1.0), v.c0);
		c1 = math::select(double4(0.0), double4(1.0), v.c1);
		c2 = math::select(double4(0.0), double4(1.0), v.c2);
	}
    double4x3::double4x3(const uint4x3& v)      { c0 = v.c0;  c1 = v.c1;  c2 = v.c2; }
    double4x3::double4x3(const int4x3& v)       { c0 = v.c0;  c1 = v.c1;  c2 = v.c2; }
    double4x3::double4x3(const float4x3& v)     { c0 = v.c0;  c1 = v.c1;  c2 = v.c2; }
    double4x3::double4x3(const double4x3& v)    { c0 = v.c0;  c1 = v.c1;  c2 = v.c2; }

	//=========================================================
	// double4x4
	//=========================================================
    double4x4::double4x4(bool v)
	{
		c0 = math::select(double4(0.0), double4(1.0), v);
		c1 = math::select(double4(0.0), double4(1.0), v);
		c2 = math::select(double4(0.0), double4(1.0), v);
		c3 = math::select(double4(0.0), double4(1.0), v);
	}
    double4x4::double4x4(const bool4x4& v)
	{
		c0 = math::select(double4(0.0), double4(1.0), v.c0);
		c1 = math::select(double4(0.0), double4(1.0), v.c1);
		c2 = math::select(double4(0.0), double4(1.0), v.c2);
		c3 = math::select(double4(0.0), double4(1.0), v.c3);
	}
    double4x4::double4x4(const uint4x4& v)      { c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3; }
    double4x4::double4x4(const int4x4& v)       { c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3; }
    double4x4::double4x4(const float4x4& v)     { c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3; }
    double4x4::double4x4(const double4x4& v)    { c0 = v.c0;  c1 = v.c1;  c2 = v.c2;  c3 = v.c3; }

    namespace math
    {
        //=========================================================
        // math-double4
        //=========================================================
        double select_shuffle_component(const double4& a, const double4& b, ShuffleComponent component)
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
        uint hash(const double4& v)
        {
            return math::csum(math::fold_to_uint(v) * uint4(0x9F1C739Bu, 0x4B1BD187u, 0x9DF50593u, 0xF18EEB85u)) + 0x9E19BFC3u;
        }
        uint4 hashwide(const double4& v)
        {
            return (math::fold_to_uint(v) * uint4(0x8196B06Fu, 0xD24EFA19u, 0x7D8048BBu, 0x713BD06Fu)) + 0x753AD6ADu;
        }
        double shuffle(const double4& left, const double4& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        double2 shuffle(const double4& left, const double4& right, ShuffleComponent x, ShuffleComponent y)
        {
            return double2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        double3 shuffle(const double4& left, const double4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return double3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        double4 shuffle(const double4& left, const double4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return double4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }
        //=========================================================
        // math-double4x2
        //=========================================================
        double2x4 transpose(const double4x2& v)
        {
            return double2x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w);
        }
        uint hash(const double4x2& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint4(0x5AB3E8CDu, 0x676E8407u, 0xB36DE767u, 0x6FCA387Du) +
                              math::fold_to_uint(v.c1) * uint4(0xAF0F3103u, 0xE4A056C7u, 0x841D8225u, 0xC9393C7Du)) + 0xD42EAFA3u;
        }
        uint4 hashwide(const double4x2& v)
        {
            return (math::fold_to_uint(v.c0) * uint4(0xD9AFD06Du, 0x97A65421u, 0x7809205Fu, 0x9C9F0823u) +
                    math::fold_to_uint(v.c1) * uint4(0x5A9CA13Bu, 0xAFCDD5EFu, 0xA88D187Du, 0xCF6EBA1Du)) + 0x9D88E5A1u;
        }
        //=========================================================
        // math-double4x3
        //=========================================================
        double3x4 transpose(const double4x3& v)
        {
            return double3x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w);
        }
        uint hash(const double4x3& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint4(0x7AA07CD3u, 0xAF642BA9u, 0xA8F2213Bu, 0x9F3FDC37u) +
                              math::fold_to_uint(v.c1) * uint4(0xAC60D0C3u, 0x9263662Fu, 0xE69626FFu, 0xBD010EEBu) +
                              math::fold_to_uint(v.c2) * uint4(0x9CEDE1D1u, 0x43BE0B51u, 0xAF836EE1u, 0xB130C137u)) + 0x54834775u;
        }
        uint4 hashwide(const double4x3& v)
        {
            return (math::fold_to_uint(v.c0) * uint4(0x7C022221u, 0xA2D00EDFu, 0xA8977779u, 0x9F1C739Bu) +
                    math::fold_to_uint(v.c1) * uint4(0x4B1BD187u, 0x9DF50593u, 0xF18EEB85u, 0x9E19BFC3u) +
                    math::fold_to_uint(v.c2) * uint4(0x8196B06Fu, 0xD24EFA19u, 0x7D8048BBu, 0x713BD06Fu)) + 0x753AD6ADu;
        }
	    //=========================================================
        // math-double4x4
        //=========================================================
        double3 rotate(const double4x4& a, const double3& b)
        {
            return (a.c0 * b.x + a.c1 * b.y + a.c2 * b.z).xyz();
        }
        double3 transform(const double4x4& a, const double3& b)
        {
            return (a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3).xyz();
        }
        double4x4 transpose(const double4x4& v)
        {
            return double4x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w,
                v.c3.x, v.c3.y, v.c3.z, v.c3.w);
        }
        double4x4 inverse(const double4x4& m)
        {
            double4 c0 = m.c0;
            double4 c1 = m.c1;
            double4 c2 = m.c2;
            double4 c3 = m.c3;

            double4 r0y_r1y_r0x_r1x = movelh(c1, c0);
            double4 r0z_r1z_r0w_r1w = movelh(c2, c3);
            double4 r2y_r3y_r2x_r3x = movehl(c0, c1);
            double4 r2z_r3z_r2w_r3w = movehl(c3, c2);

            double4 r1y_r2y_r1x_r2x = shuffle(c1, c0, ShuffleComponent::LeftY, ShuffleComponent::LeftZ, ShuffleComponent::RightY, ShuffleComponent::RightZ);
            double4 r1z_r2z_r1w_r2w = shuffle(c2, c3, ShuffleComponent::LeftY, ShuffleComponent::LeftZ, ShuffleComponent::RightY, ShuffleComponent::RightZ);
            double4 r3y_r0y_r3x_r0x = shuffle(c1, c0, ShuffleComponent::LeftW, ShuffleComponent::LeftX, ShuffleComponent::RightW, ShuffleComponent::RightX);
            double4 r3z_r0z_r3w_r0w = shuffle(c2, c3, ShuffleComponent::LeftW, ShuffleComponent::LeftX, ShuffleComponent::RightW, ShuffleComponent::RightX);

            double4 r0_wzyx = shuffle(r0z_r1z_r0w_r1w, r0y_r1y_r0x_r1x, ShuffleComponent::LeftZ, ShuffleComponent::LeftX, ShuffleComponent::RightX, ShuffleComponent::RightZ);
            double4 r1_wzyx = shuffle(r0z_r1z_r0w_r1w, r0y_r1y_r0x_r1x, ShuffleComponent::LeftW, ShuffleComponent::LeftY, ShuffleComponent::RightY, ShuffleComponent::RightW);
            double4 r2_wzyx = shuffle(r2z_r3z_r2w_r3w, r2y_r3y_r2x_r3x, ShuffleComponent::LeftZ, ShuffleComponent::LeftX, ShuffleComponent::RightX, ShuffleComponent::RightZ);
            double4 r3_wzyx = shuffle(r2z_r3z_r2w_r3w, r2y_r3y_r2x_r3x, ShuffleComponent::LeftW, ShuffleComponent::LeftY, ShuffleComponent::RightY, ShuffleComponent::RightW);
            double4 r0_xyzw = shuffle(r0y_r1y_r0x_r1x, r0z_r1z_r0w_r1w, ShuffleComponent::LeftZ, ShuffleComponent::LeftX, ShuffleComponent::RightX, ShuffleComponent::RightZ);

            // Calculate remaining inner term pairs. inner terms have zw=-xy, so we only have to calculate xy and can pack two pairs per vector.
            double4 inner12_23 = r1y_r2y_r1x_r2x * r2z_r3z_r2w_r3w - r1z_r2z_r1w_r2w * r2y_r3y_r2x_r3x;
            double4 inner02_13 = r0y_r1y_r0x_r1x * r2z_r3z_r2w_r3w - r0z_r1z_r0w_r1w * r2y_r3y_r2x_r3x;
            double4 inner30_01 = r3z_r0z_r3w_r0w * r0y_r1y_r0x_r1x - r3y_r0y_r3x_r0x * r0z_r1z_r0w_r1w;

            // Expand inner terms back to 4 components. zw signs still need to be flipped
            double4 inner12 = shuffle(inner12_23, inner12_23, ShuffleComponent::LeftX, ShuffleComponent::LeftZ, ShuffleComponent::RightZ, ShuffleComponent::RightX);
            double4 inner23 = shuffle(inner12_23, inner12_23, ShuffleComponent::LeftY, ShuffleComponent::LeftW, ShuffleComponent::RightW, ShuffleComponent::RightY);

            double4 inner02 = shuffle(inner02_13, inner02_13, ShuffleComponent::LeftX, ShuffleComponent::LeftZ, ShuffleComponent::RightZ, ShuffleComponent::RightX);
            double4 inner13 = shuffle(inner02_13, inner02_13, ShuffleComponent::LeftY, ShuffleComponent::LeftW, ShuffleComponent::RightW, ShuffleComponent::RightY);

            // Calculate minors
            double4 minors0 = r3_wzyx * inner12 - r2_wzyx * inner13 + r1_wzyx * inner23;

            double4 denom = r0_xyzw * minors0;

            // Horizontal sum of denominator. Free sign flip of z and w compensates for missing flip in inner terms.
            denom = denom + shuffle(denom, denom, ShuffleComponent::LeftY, ShuffleComponent::LeftX, ShuffleComponent::RightW, ShuffleComponent::RightZ);   // x+y        x+y            z+w            z+w
            denom = denom - shuffle(denom, denom, ShuffleComponent::LeftZ, ShuffleComponent::LeftZ, ShuffleComponent::RightX, ShuffleComponent::RightX);   // x+y-z-w  x+y-z-w        z+w-x-y        z+w-x-y

            double4 rcp_denom_ppnn = double4(1.0) / denom;
            double4x4 res;
            res.c0 = minors0 * rcp_denom_ppnn;

            double4 inner30 = shuffle(inner30_01, inner30_01, ShuffleComponent::LeftX, ShuffleComponent::LeftZ, ShuffleComponent::RightZ, ShuffleComponent::RightX);
            double4 inner01 = shuffle(inner30_01, inner30_01, ShuffleComponent::LeftY, ShuffleComponent::LeftW, ShuffleComponent::RightW, ShuffleComponent::RightY);

            double4 minors1 = r2_wzyx * inner30 - r0_wzyx * inner23 - r3_wzyx * inner02;
            res.c1 = minors1 * rcp_denom_ppnn;

            double4 minors2 = r0_wzyx * inner13 - r1_wzyx * inner30 - r3_wzyx * inner01;
            res.c2 = minors2 * rcp_denom_ppnn;

            double4 minors3 = r1_wzyx * inner02 - r0_wzyx * inner12 + r2_wzyx * inner01;
            res.c3 = minors3 * rcp_denom_ppnn;
            return res;
        }
        double4x4 fastinverse(const double4x4& m)
        {
            double4 c0 = m.c0;
            double4 c1 = m.c1;
            double4 c2 = m.c2;
            double4 pos = m.c3;

            double4 zero = double4(0);

            double4 t0 = unpacklo(c0, c2);
            double4 t1 = unpacklo(c1, zero);
            double4 t2 = unpackhi(c0, c2);
            double4 t3 = unpackhi(c1, zero);

            double4 r0 = unpacklo(t0, t1);
            double4 r1 = unpackhi(t0, t1);
            double4 r2 = unpacklo(t2, t3);

            pos = -(r0 * pos.x + r1 * pos.y + r2 * pos.z);
            pos.w = 1.0f;

            return double4x4(r0, r1, r2, pos);
        }
        double determinant(const double4x4& m)
        {
            double4 c0 = m.c0;
            double4 c1 = m.c1;
            double4 c2 = m.c2;
            double4 c3 = m.c3;

            double m00 = c1.y * (c2.z * c3.w - c2.w * c3.z) - c2.y * (c1.z * c3.w - c1.w * c3.z) + c3.y * (c1.z * c2.w - c1.w * c2.z);
            double m01 = c0.y * (c2.z * c3.w - c2.w * c3.z) - c2.y * (c0.z * c3.w - c0.w * c3.z) + c3.y * (c0.z * c2.w - c0.w * c2.z);
            double m02 = c0.y * (c1.z * c3.w - c1.w * c3.z) - c1.y * (c0.z * c3.w - c0.w * c3.z) + c3.y * (c0.z * c1.w - c0.w * c1.z);
            double m03 = c0.y * (c1.z * c2.w - c1.w * c2.z) - c1.y * (c0.z * c2.w - c0.w * c2.z) + c2.y * (c0.z * c1.w - c0.w * c1.z);

            return c0.x * m00 - c1.x * m01 + c2.x * m02 - c3.x * m03;
        }
        uint hash(const double4x4& v)
        {
            return math::csum(math::fold_to_uint(v.c0) * uint4(0x4DDC6509u, 0x7CF083CBu, 0x5C4D6CEDu, 0xF9137117u) +
                              math::fold_to_uint(v.c1) * uint4(0xE857DCE1u, 0xF62213C5u, 0x9CDAA959u, 0xAA269ABFu) +
                              math::fold_to_uint(v.c2) * uint4(0xD54BA36Fu, 0xFD0847B9u, 0x8189A683u, 0xB139D651u) +
                              math::fold_to_uint(v.c3) * uint4(0xE7579997u, 0xEF7D56C7u, 0x66F38F0Bu, 0x624256A3u)) + 0x5292ADE1u;
        }
        uint4 hashwide(const double4x4& v)
        {
            return (math::fold_to_uint(v.c0) * uint4(0xD2E590E5u, 0xF25BE857u, 0x9BC17CE7u, 0xC8B86851u) +
                    math::fold_to_uint(v.c1) * uint4(0x64095221u, 0xADF428FFu, 0xA3977109u, 0x745ED837u) +
                    math::fold_to_uint(v.c2) * uint4(0x9CDC88F5u, 0xFA62D721u, 0x7E4DB1CFu, 0x68EEE0F5u) +
                    math::fold_to_uint(v.c3) * uint4(0xBC3B0A59u, 0x816EFB5Du, 0xA24E82B7u, 0x45A22087u)) + 0xFC104C3Bu;
        }
    }

} // namespace ecs

