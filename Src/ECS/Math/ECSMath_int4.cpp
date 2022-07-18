#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// int4
	//=========================================================
    int4::int4(const bool4& v)      {   x = v.x ? 1 : 0;y = v.y ? 1 : 0;z = v.z ? 1 : 0;w = v.w ? 1 : 0;    }
    int4::int4(const uint4& v)      {   x = (int)v.x;   y = (int)v.y;   z = (int)v.z;   w = (int)v.w;   }
    int4::int4(const int4& v)       {   x = v.x;        y = v.y;        z = v.z;        w = v.w;        }
    int4::int4(const float4& v)     {   x = (int)v.x;   y = (int)v.y;   z = (int)v.z;   w = (int)v.w;   }
    int4::int4(const double4& v)    {   x = (int)v.x;   y = (int)v.y;   z = (int)v.z;   w = (int)v.w;   }

    int4 int4::xxxx() const         { return int4(x, x, x, x); }
    int4 int4::xxxy() const         { return int4(x, x, x, y); }
    int4 int4::xxxz() const         { return int4(x, x, x, z); }
    int4 int4::xxxw() const         { return int4(x, x, x, w); }
    int4 int4::xxyx() const         { return int4(x, x, y, x); }
    int4 int4::xxyy() const         { return int4(x, x, y, y); }
    int4 int4::xxyz() const         { return int4(x, x, y, z); }
    int4 int4::xxyw() const         { return int4(x, x, y, w); }
    int4 int4::xxzx() const         { return int4(x, x, z, x); }
    int4 int4::xxzy() const         { return int4(x, x, z, y); }
    int4 int4::xxzz() const         { return int4(x, x, z, z); }
    int4 int4::xxzw() const         { return int4(x, x, z, w); }
    int4 int4::xxwx() const         { return int4(x, x, w, x); }
    int4 int4::xxwy() const         { return int4(x, x, w, y); }
    int4 int4::xxwz() const         { return int4(x, x, w, z); }
    int4 int4::xxww() const         { return int4(x, x, w, w); }
    int4 int4::xyxx() const         { return int4(x, y, x, x); }
    int4 int4::xyxy() const         { return int4(x, y, x, y); }
    int4 int4::xyxz() const         { return int4(x, y, x, z); }
    int4 int4::xyxw() const         { return int4(x, y, x, w); }
    int4 int4::xyyx() const         { return int4(x, y, y, x); }
    int4 int4::xyyy() const         { return int4(x, y, y, y); }
    int4 int4::xyyz() const         { return int4(x, y, y, z); }
    int4 int4::xyyw() const         { return int4(x, y, y, w); }
    int4 int4::xyzx() const         { return int4(x, y, z, x); }
    int4 int4::xyzy() const         { return int4(x, y, z, y); }
    int4 int4::xyzz() const         { return int4(x, y, z, z); }
    int4 int4::xyzw() const         { return int4(x, y, z, w); }
    void int4::xyzw(const int4& v)  { x = v.x; y = v.y; z = v.z; w = v.w; }
    int4 int4::xywx() const         { return int4(x, y, w, x); }
    int4 int4::xywy() const         { return int4(x, y, w, y); }
    int4 int4::xywz() const         { return int4(x, y, w, z); }
    void int4::xywz(const int4& v)  { x = v.x; y = v.y; w = v.z; z = v.w; }
    int4 int4::xyww() const         { return int4(x, y, w, w); }
    int4 int4::xzxx() const         { return int4(x, z, x, x); }
    int4 int4::xzxy() const         { return int4(x, z, x, y); }
    int4 int4::xzxz() const         { return int4(x, z, x, z); }
    int4 int4::xzxw() const         { return int4(x, z, x, w); }
    int4 int4::xzyx() const         { return int4(x, z, y, x); }
    int4 int4::xzyy() const         { return int4(x, z, y, y); }
    int4 int4::xzyz() const         { return int4(x, z, y, z); }
    int4 int4::xzyw() const         { return int4(x, z, y, w); }
    void int4::xzyw(const int4& v)  { x = v.x; z = v.y; y = v.z; w = v.w; }
    int4 int4::xzzx() const         { return int4(x, z, z, x); }
    int4 int4::xzzy() const         { return int4(x, z, z, y); }
    int4 int4::xzzz() const         { return int4(x, z, z, z); }
    int4 int4::xzzw() const         { return int4(x, z, z, w); }
    int4 int4::xzwx() const         { return int4(x, z, w, x); }
    int4 int4::xzwy() const         { return int4(x, z, w, y); }
    void int4::xzwy(const int4& v)  { x = v.x; z = v.y; w = v.z; y = v.w; }
    int4 int4::xzwz() const         { return int4(x, z, w, z); }
    int4 int4::xzww() const         { return int4(x, z, w, w); }
    int4 int4::xwxx() const         { return int4(x, w, x, x); }
    int4 int4::xwxy() const         { return int4(x, w, x, y); }
    int4 int4::xwxz() const         { return int4(x, w, x, z); }
    int4 int4::xwxw() const         { return int4(x, w, x, w); }
    int4 int4::xwyx() const         { return int4(x, w, y, x); }
    int4 int4::xwyy() const         { return int4(x, w, y, y); }
    int4 int4::xwyz() const         { return int4(x, w, y, z); }
    void int4::xwyz(const int4& v)  { x = v.x; w = v.y; y = v.z; z = v.w; }
    int4 int4::xwyw() const         { return int4(x, w, y, w); }
    int4 int4::xwzx() const         { return int4(x, w, z, x); }
    int4 int4::xwzy() const         { return int4(x, w, z, y); }
    void int4::xwzy(const int4& v)  { x = v.x; w = v.y; z = v.z; y = v.w; }
    int4 int4::xwzz() const         { return int4(x, w, z, z); }
    int4 int4::xwzw() const         { return int4(x, w, z, w); }
    int4 int4::xwwx() const         { return int4(x, w, w, x); }
    int4 int4::xwwy() const         { return int4(x, w, w, y); }
    int4 int4::xwwz() const         { return int4(x, w, w, z); }
    int4 int4::xwww() const         { return int4(x, w, w, w); }
    int4 int4::yxxx() const         { return int4(y, x, x, x); }
    int4 int4::yxxy() const         { return int4(y, x, x, y); }
    int4 int4::yxxz() const         { return int4(y, x, x, z); }
    int4 int4::yxxw() const         { return int4(y, x, x, w); }
    int4 int4::yxyx() const         { return int4(y, x, y, x); }
    int4 int4::yxyy() const         { return int4(y, x, y, y); }
    int4 int4::yxyz() const         { return int4(y, x, y, z); }
    int4 int4::yxyw() const         { return int4(y, x, y, w); }
    int4 int4::yxzx() const         { return int4(y, x, z, x); }
    int4 int4::yxzy() const         { return int4(y, x, z, y); }
    int4 int4::yxzz() const         { return int4(y, x, z, z); }
    int4 int4::yxzw() const         { return int4(y, x, z, w); }
    void int4::yxzw(const int4& v)  { y = v.x; x = v.y; z = v.z; w = v.w; }
    int4 int4::yxwx() const         { return int4(y, x, w, x); }
    int4 int4::yxwy() const         { return int4(y, x, w, y); }
    int4 int4::yxwz() const         { return int4(y, x, w, z); }
    void int4::yxwz(const int4& v)  { y = v.x; x = v.y; w = v.z; z = v.w; }
    int4 int4::yxww() const         { return int4(y, x, w, w); }
    int4 int4::yyxx() const         { return int4(y, y, x, x); }
    int4 int4::yyxy() const         { return int4(y, y, x, y); }
    int4 int4::yyxz() const         { return int4(y, y, x, z); }
    int4 int4::yyxw() const         { return int4(y, y, x, w); }
    int4 int4::yyyx() const         { return int4(y, y, y, x); }
    int4 int4::yyyy() const         { return int4(y, y, y, y); }
    int4 int4::yyyz() const         { return int4(y, y, y, z); }
    int4 int4::yyyw() const         { return int4(y, y, y, w); }
    int4 int4::yyzx() const         { return int4(y, y, z, x); }
    int4 int4::yyzy() const         { return int4(y, y, z, y); }
    int4 int4::yyzz() const         { return int4(y, y, z, z); }
    int4 int4::yyzw() const         { return int4(y, y, z, w); }
    int4 int4::yywx() const         { return int4(y, y, w, x); }
    int4 int4::yywy() const         { return int4(y, y, w, y); }
    int4 int4::yywz() const         { return int4(y, y, w, z); }
    int4 int4::yyww() const         { return int4(y, y, w, w); }
    int4 int4::yzxx() const         { return int4(y, z, x, x); }
    int4 int4::yzxy() const         { return int4(y, z, x, y); }
    int4 int4::yzxz() const         { return int4(y, z, x, z); }
    int4 int4::yzxw() const         { return int4(y, z, x, w); }
    void int4::yzxw(const int4& v)  { y = v.x; z = v.y; x = v.z; w = v.w; }
    int4 int4::yzyx() const         { return int4(y, z, y, x); }
    int4 int4::yzyy() const         { return int4(y, z, y, y); }
    int4 int4::yzyz() const         { return int4(y, z, y, z); }
    int4 int4::yzyw() const         { return int4(y, z, y, w); }
    int4 int4::yzzx() const         { return int4(y, z, z, x); }
    int4 int4::yzzy() const         { return int4(y, z, z, y); }
    int4 int4::yzzz() const         { return int4(y, z, z, z); }
    int4 int4::yzzw() const         { return int4(y, z, z, w); }
    int4 int4::yzwx() const         { return int4(y, z, w, x); }
    void int4::yzwx(const int4& v)  { y = v.x; z = v.y; w = v.z; x = v.w; }
    int4 int4::yzwy() const         { return int4(y, z, w, y); }
    int4 int4::yzwz() const         { return int4(y, z, w, z); }
    int4 int4::yzww() const         { return int4(y, z, w, w); }
    int4 int4::ywxx() const         { return int4(y, w, x, x); }
    int4 int4::ywxy() const         { return int4(y, w, x, y); }
    int4 int4::ywxz() const         { return int4(y, w, x, z); }
    void int4::ywxz(const int4& v)  { y = v.x; w = v.y; x = v.z; z = v.w; }
    int4 int4::ywxw() const         { return int4(y, w, x, w); }
    int4 int4::ywyx() const         { return int4(y, w, y, x); }
    int4 int4::ywyy() const         { return int4(y, w, y, y); }
    int4 int4::ywyz() const         { return int4(y, w, y, z); }
    int4 int4::ywyw() const         { return int4(y, w, y, w); }
    int4 int4::ywzx() const         { return int4(y, w, z, x); }
    void int4::ywzx(const int4& v)  { y = v.x; w = v.y; z = v.z; x = v.w; }
    int4 int4::ywzy() const         { return int4(y, w, z, y); }
    int4 int4::ywzz() const         { return int4(y, w, z, z); }
    int4 int4::ywzw() const         { return int4(y, w, z, w); }
    int4 int4::ywwx() const         { return int4(y, w, w, x); }
    int4 int4::ywwy() const         { return int4(y, w, w, y); }
    int4 int4::ywwz() const         { return int4(y, w, w, z); }
    int4 int4::ywww() const         { return int4(y, w, w, w); }
    int4 int4::zxxx() const         { return int4(z, x, x, x); }
    int4 int4::zxxy() const         { return int4(z, x, x, y); }
    int4 int4::zxxz() const         { return int4(z, x, x, z); }
    int4 int4::zxxw() const         { return int4(z, x, x, w); }
    int4 int4::zxyx() const         { return int4(z, x, y, x); }
    int4 int4::zxyy() const         { return int4(z, x, y, y); }
    int4 int4::zxyz() const         { return int4(z, x, y, z); }
    int4 int4::zxyw() const         { return int4(z, x, y, w); }
    void int4::zxyw(const int4& v)  { z = v.x; x = v.y; y = v.z; w = v.w; }
    int4 int4::zxzx() const         { return int4(z, x, z, x); }
    int4 int4::zxzy() const         { return int4(z, x, z, y); }
    int4 int4::zxzz() const         { return int4(z, x, z, z); }
    int4 int4::zxzw() const         { return int4(z, x, z, w); }
    int4 int4::zxwx() const         { return int4(z, x, w, x); }
    int4 int4::zxwy() const         { return int4(z, x, w, y); }
    void int4::zxwy(const int4& v)  { z = v.x; x = v.y; w = v.z; y = v.w; }
    int4 int4::zxwz() const         { return int4(z, x, w, z); }
    int4 int4::zxww() const         { return int4(z, x, w, w); }
    int4 int4::zyxx() const         { return int4(z, y, x, x); }
    int4 int4::zyxy() const         { return int4(z, y, x, y); }
    int4 int4::zyxz() const         { return int4(z, y, x, z); }
    int4 int4::zyxw() const         { return int4(z, y, x, w); }
    void int4::zyxw(const int4& v)  { z = v.x; y = v.y; x = v.z; w = v.w; }
    int4 int4::zyyx() const         { return int4(z, y, y, x); }
    int4 int4::zyyy() const         { return int4(z, y, y, y); }
    int4 int4::zyyz() const         { return int4(z, y, y, z); }
    int4 int4::zyyw() const         { return int4(z, y, y, w); }
    int4 int4::zyzx() const         { return int4(z, y, z, x); }
    int4 int4::zyzy() const         { return int4(z, y, z, y); }
    int4 int4::zyzz() const         { return int4(z, y, z, z); }
    int4 int4::zyzw() const         { return int4(z, y, z, w); }
    int4 int4::zywx() const         { return int4(z, y, w, x); }
    void int4::zywx(const int4& v)  { z = v.x; y = v.y; w = v.z; x = v.w; }
    int4 int4::zywy() const         { return int4(z, y, w, y); }
    int4 int4::zywz() const         { return int4(z, y, w, z); }
    int4 int4::zyww() const         { return int4(z, y, w, w); }
    int4 int4::zzxx() const         { return int4(z, z, x, x); }
    int4 int4::zzxy() const         { return int4(z, z, x, y); }
    int4 int4::zzxz() const         { return int4(z, z, x, z); }
    int4 int4::zzxw() const         { return int4(z, z, x, w); }
    int4 int4::zzyx() const         { return int4(z, z, y, x); }
    int4 int4::zzyy() const         { return int4(z, z, y, y); }
    int4 int4::zzyz() const         { return int4(z, z, y, z); }
    int4 int4::zzyw() const         { return int4(z, z, y, w); }
    int4 int4::zzzx() const         { return int4(z, z, z, x); }
    int4 int4::zzzy() const         { return int4(z, z, z, y); }
    int4 int4::zzzz() const         { return int4(z, z, z, z); }
    int4 int4::zzzw() const         { return int4(z, z, z, w); }
    int4 int4::zzwx() const         { return int4(z, z, w, x); }
    int4 int4::zzwy() const         { return int4(z, z, w, y); }
    int4 int4::zzwz() const         { return int4(z, z, w, z); }
    int4 int4::zzww() const         { return int4(z, z, w, w); }
    int4 int4::zwxx() const         { return int4(z, w, x, x); }
    int4 int4::zwxy() const         { return int4(z, w, x, y); }
    void int4::zwxy(const int4& v)  { z = v.x; w = v.y; x = v.z; y = v.w; }
    int4 int4::zwxz() const         { return int4(z, w, x, z); }
    int4 int4::zwxw() const         { return int4(z, w, x, w); }
    int4 int4::zwyx() const         { return int4(z, w, y, x); }
    void int4::zwyx(const int4& v)  { z = v.x; w = v.y; y = v.z; x = v.w; }
    int4 int4::zwyy() const         { return int4(z, w, y, y); }
    int4 int4::zwyz() const         { return int4(z, w, y, z); }
    int4 int4::zwyw() const         { return int4(z, w, y, w); }
    int4 int4::zwzx() const         { return int4(z, w, z, x); }
    int4 int4::zwzy() const         { return int4(z, w, z, y); }
    int4 int4::zwzz() const         { return int4(z, w, z, z); }
    int4 int4::zwzw() const         { return int4(z, w, z, w); }
    int4 int4::zwwx() const         { return int4(z, w, w, x); }
    int4 int4::zwwy() const         { return int4(z, w, w, y); }
    int4 int4::zwwz() const         { return int4(z, w, w, z); }
    int4 int4::zwww() const         { return int4(z, w, w, w); }
    int4 int4::wxxx() const         { return int4(w, x, x, x); }
    int4 int4::wxxy() const         { return int4(w, x, x, y); }
    int4 int4::wxxz() const         { return int4(w, x, x, z); }
    int4 int4::wxxw() const         { return int4(w, x, x, w); }
    int4 int4::wxyx() const         { return int4(w, x, y, x); }
    int4 int4::wxyy() const         { return int4(w, x, y, y); }
    int4 int4::wxyz() const         { return int4(w, x, y, z); }
    void int4::wxyz(const int4& v)  { w = v.x; x = v.y; y = v.z; z = v.w; }
    int4 int4::wxyw() const         { return int4(w, x, y, w); }
    int4 int4::wxzx() const         { return int4(w, x, z, x); }
    int4 int4::wxzy() const         { return int4(w, x, z, y); }
    void int4::wxzy(const int4& v)  { w = v.x; x = v.y; z = v.z; y = v.w; }
    int4 int4::wxzz() const         { return int4(w, x, z, z); }
    int4 int4::wxzw() const         { return int4(w, x, z, w); }
    int4 int4::wxwx() const         { return int4(w, x, w, x); }
    int4 int4::wxwy() const         { return int4(w, x, w, y); }
    int4 int4::wxwz() const         { return int4(w, x, w, z); }
    int4 int4::wxww() const         { return int4(w, x, w, w); }
    int4 int4::wyxx() const         { return int4(w, y, x, x); }
    int4 int4::wyxy() const         { return int4(w, y, x, y); }
    int4 int4::wyxz() const         { return int4(w, y, x, z); }
    void int4::wyxz(const int4& v)  { w = v.x; y = v.y; x = v.z; z = v.w; }
    int4 int4::wyxw() const         { return int4(w, y, x, w); }
    int4 int4::wyyx() const         { return int4(w, y, y, x); }
    int4 int4::wyyy() const         { return int4(w, y, y, y); }
    int4 int4::wyyz() const         { return int4(w, y, y, z); }
    int4 int4::wyyw() const         { return int4(w, y, y, w); }
    int4 int4::wyzx() const         { return int4(w, y, z, x); }
    void int4::wyzx(const int4& v)  { w = v.x; y = v.y; z = v.z; x = v.w; }
    int4 int4::wyzy() const         { return int4(w, y, z, y); }
    int4 int4::wyzz() const         { return int4(w, y, z, z); }
    int4 int4::wyzw() const         { return int4(w, y, z, w); }
    int4 int4::wywx() const         { return int4(w, y, w, x); }
    int4 int4::wywy() const         { return int4(w, y, w, y); }
    int4 int4::wywz() const         { return int4(w, y, w, z); }
    int4 int4::wyww() const         { return int4(w, y, w, w); }
    int4 int4::wzxx() const         { return int4(w, z, x, x); }
    int4 int4::wzxy() const         { return int4(w, z, x, y); }
    void int4::wzxy(const int4& v)  { w = v.x; z = v.y; x = v.z; y = v.w; }
    int4 int4::wzxz() const         { return int4(w, z, x, z); }
    int4 int4::wzxw() const         { return int4(w, z, x, w); }
    int4 int4::wzyx() const         { return int4(w, z, y, x); }
    void int4::wzyx(const int4& v)  { w = v.x; z = v.y; y = v.z; x = v.w; }
    int4 int4::wzyy() const         { return int4(w, z, y, y); }
    int4 int4::wzyz() const         { return int4(w, z, y, z); }
    int4 int4::wzyw() const         { return int4(w, z, y, w); }
    int4 int4::wzzx() const         { return int4(w, z, z, x); }
    int4 int4::wzzy() const         { return int4(w, z, z, y); }
    int4 int4::wzzz() const         { return int4(w, z, z, z); }
    int4 int4::wzzw() const         { return int4(w, z, z, w); }
    int4 int4::wzwx() const         { return int4(w, z, w, x); }
    int4 int4::wzwy() const         { return int4(w, z, w, y); }
    int4 int4::wzwz() const         { return int4(w, z, w, z); }
    int4 int4::wzww() const         { return int4(w, z, w, w); }
    int4 int4::wwxx() const         { return int4(w, w, x, x); }
    int4 int4::wwxy() const         { return int4(w, w, x, y); }
    int4 int4::wwxz() const         { return int4(w, w, x, z); }
    int4 int4::wwxw() const         { return int4(w, w, x, w); }
    int4 int4::wwyx() const         { return int4(w, w, y, x); }
    int4 int4::wwyy() const         { return int4(w, w, y, y); }
    int4 int4::wwyz() const         { return int4(w, w, y, z); }
    int4 int4::wwyw() const         { return int4(w, w, y, w); }
    int4 int4::wwzx() const         { return int4(w, w, z, x); }
    int4 int4::wwzy() const         { return int4(w, w, z, y); }
    int4 int4::wwzz() const         { return int4(w, w, z, z); }
    int4 int4::wwzw() const         { return int4(w, w, z, w); }
    int4 int4::wwwx() const         { return int4(w, w, w, x); }
    int4 int4::wwwy() const         { return int4(w, w, w, y); }
    int4 int4::wwwz() const         { return int4(w, w, w, z); }
    int4 int4::wwww() const         { return int4(w, w, w, w); }
    int3 int4::xxx()  const         { return int3(x, x, x); }
    int3 int4::xxy()  const         { return int3(x, x, y); }
    int3 int4::xxz()  const         { return int3(x, x, z); }
    int3 int4::xxw()  const         { return int3(x, x, w); }
    int3 int4::xyx()  const         { return int3(x, y, x); }
    int3 int4::xyy()  const         { return int3(x, y, y); }
    int3 int4::xyz()  const         { return int3(x, y, z); }
    void int4::xyz(const int3& v)   { x = v.x; y = v.y; z = v.z; }
    int3 int4::xyw()  const         { return int3(x, y, w); }
    void int4::xyw(const int3& v)   { x = v.x; y = v.y; w = v.z; }
    int3 int4::xzx()  const         { return int3(x, z, x); }
    int3 int4::xzy()  const         { return int3(x, z, y); }
    void int4::xzy(const int3& v)   { x = v.x; z = v.y; y = v.z; }
    int3 int4::xzz()  const         { return int3(x, z, z); }
    int3 int4::xzw()  const         { return int3(x, z, w); }
    void int4::xzw(const int3& v)   { x = v.x; z = v.y; w = v.z; }
    int3 int4::xwx()  const         { return int3(x, w, x); }
    int3 int4::xwy()  const         { return int3(x, w, y); }
    void int4::xwy(const int3& v)   { x = v.x; w = v.y; y = v.z; }
    int3 int4::xwz()  const         { return int3(x, w, z); }
    void int4::xwz(const int3& v)   { x = v.x; w = v.y; z = v.z; }
    int3 int4::xww()  const         { return int3(x, w, w); }
    int3 int4::yxx()  const         { return int3(y, x, x); }
    int3 int4::yxy()  const         { return int3(y, x, y); }
    int3 int4::yxz()  const         { return int3(y, x, z); }
    void int4::yxz(const int3& v)   { y = v.x; x = v.y; z = v.z; }
    int3 int4::yxw()  const         { return int3(y, x, w); }
    void int4::yxw(const int3& v)   { y = v.x; x = v.y; w = v.z; }
    int3 int4::yyx()  const         { return int3(y, y, x); }
    int3 int4::yyy()  const         { return int3(y, y, y); }
    int3 int4::yyz()  const         { return int3(y, y, z); }
    int3 int4::yyw()  const         { return int3(y, y, w); }
    int3 int4::yzx()  const         { return int3(y, z, x); }
    void int4::yzx(const int3& v)   { y = v.x; z = v.y; x = v.z; }
    int3 int4::yzy()  const         { return int3(y, z, y); }
    int3 int4::yzz()  const         { return int3(y, z, z); }
    int3 int4::yzw()  const         { return int3(y, z, w); }
    void int4::yzw(const int3& v)   { y = v.x; z = v.y; w = v.z; }
    int3 int4::ywx()  const         { return int3(y, w, x); }
    void int4::ywx(const int3& v)   { y = v.x; w = v.y; x = v.z; }
    int3 int4::ywy()  const         { return int3(y, w, y); }
    int3 int4::ywz()  const         { return int3(y, w, z); }
    void int4::ywz(const int3& v)   { y = v.x; w = v.y; z = v.z; }
    int3 int4::yww()  const         { return int3(y, w, w); }
    int3 int4::zxx()  const         { return int3(z, x, x); }
    int3 int4::zxy()  const         { return int3(z, x, y); }
    void int4::zxy(const int3& v)   { z = v.x; x = v.y; y = v.z; }
    int3 int4::zxz()  const         { return int3(z, x, z); }
    int3 int4::zxw()  const         { return int3(z, x, w); }
    void int4::zxw(const int3& v)   { z = v.x; x = v.y; w = v.z; }
    int3 int4::zyx()  const         { return int3(z, y, x); }
    void int4::zyx(const int3& v)   { z = v.x; y = v.y; x = v.z; }
    int3 int4::zyy()  const         { return int3(z, y, y); }
    int3 int4::zyz()  const         { return int3(z, y, z); }
    int3 int4::zyw()  const         { return int3(z, y, w); }
    void int4::zyw(const int3& v)   { z = v.x; y = v.y; w = v.z; }
    int3 int4::zzx()  const         { return int3(z, z, x); }
    int3 int4::zzy()  const         { return int3(z, z, y); }
    int3 int4::zzz()  const         { return int3(z, z, z); }
    int3 int4::zzw()  const         { return int3(z, z, w); }
    int3 int4::zwx()  const         { return int3(z, w, x); }
    void int4::zwx(const int3& v)   { z = v.x; w = v.y; x = v.z; }
    int3 int4::zwy()  const         { return int3(z, w, y); }
    void int4::zwy(const int3& v)   { z = v.x; w = v.y; y = v.z; }
    int3 int4::zwz()  const         { return int3(z, w, z); }
    int3 int4::zww()  const         { return int3(z, w, w); }
    int3 int4::wxx()  const         { return int3(w, x, x); }
    int3 int4::wxy()  const         { return int3(w, x, y); }
    void int4::wxy(const int3& v)   { w = v.x; x = v.y; y = v.z; }
    int3 int4::wxz()  const         { return int3(w, x, z); }
    void int4::wxz(const int3& v)   { w = v.x; x = v.y; z = v.z; }
    int3 int4::wxw()  const         { return int3(w, x, w); }
    int3 int4::wyx()  const         { return int3(w, y, x); }
    void int4::wyx(const int3& v)   { w = v.x; y = v.y; x = v.z; }
    int3 int4::wyy()  const         { return int3(w, y, y); }
    int3 int4::wyz()  const         { return int3(w, y, z); }
    void int4::wyz(const int3& v)   { w = v.x; y = v.y; z = v.z; }
    int3 int4::wyw()  const         { return int3(w, y, w); }
    int3 int4::wzx()  const         { return int3(w, z, x); }
    void int4::wzx(const int3& v)   { w = v.x; z = v.y; x = v.z; }
    int3 int4::wzy()  const         { return int3(w, z, y); }
    void int4::wzy(const int3& v)   { w = v.x; z = v.y; y = v.z; }
    int3 int4::wzz()  const         { return int3(w, z, z); }
    int3 int4::wzw()  const         { return int3(w, z, w); }
    int3 int4::wwx()  const         { return int3(w, w, x); }
    int3 int4::wwy()  const         { return int3(w, w, y); }
    int3 int4::wwz()  const         { return int3(w, w, z); }
    int3 int4::www()  const         { return int3(w, w, w); }
    int2 int4::xx()   const         { return int2(x, x); }
    int2 int4::xy()   const         { return int2(x, y); }
    void int4::xy(const int2& v)    { x = v.x; y = v.y; }
    int2 int4::xz()   const         { return int2(x, z); }
    void int4::xz(const int2& v)    { x = v.x; z = v.y; }
    int2 int4::xw()   const         { return int2(x, w); }
    void int4::xw(const int2& v)    { x = v.x; w = v.y; }
    int2 int4::yx()   const         { return int2(y, x); }
    void int4::yx(const int2& v)    { y = v.x; x = v.y; }
    int2 int4::yy()   const         { return int2(y, y); }
    int2 int4::yz()   const         { return int2(y, z); }
    void int4::yz(const int2& v)    { y = v.x; z = v.y; }
    int2 int4::yw()   const         { return int2(y, w); }
    void int4::yw(const int2& v)    { y = v.x; w = v.y; }
    int2 int4::zx()   const         { return int2(z, x); }
    void int4::zx(const int2& v)    { z = v.x; x = v.y; }
    int2 int4::zy()   const         { return int2(z, y); }
    void int4::zy(const int2& v)    { z = v.x; y = v.y; }
    int2 int4::zz()   const         { return int2(z, z); }
    int2 int4::zw()   const         { return int2(z, w); }
    void int4::zw(const int2& v)    { z = v.x; w = v.y; }
    int2 int4::wx()   const         { return int2(w, x); }
    void int4::wx(const int2& v)    { w = v.x; x = v.y; }
    int2 int4::wy()   const         { return int2(w, y); }
    void int4::wy(const int2& v)    { w = v.x; y = v.y; }
    int2 int4::wz()   const         { return int2(w, z); }
    void int4::wz(const int2& v)    { w = v.x; z = v.y; }
    int2 int4::ww()   const         { return int2(w, w); }



	//=========================================================
	// int4x2
	//=========================================================
    int4x2::int4x2(bool v)
	{
		c0 = math::select(int4(0), int4(1), v);
		c1 = math::select(int4(0), int4(1), v);
	}
    int4x2::int4x2(const bool4x2& v)
	{
		c0 = math::select(int4(0), int4(1), v.c0);
		c1 = math::select(int4(0), int4(1), v.c1);
	}
    int4x2::int4x2(const uint4x2& v)    { c0 = (int4)v.c0;    c1 = (int4)v.c1;  }
    int4x2::int4x2(const int4x2& v)     { c0 = v.c0;          c1 = v.c1;        }
    int4x2::int4x2(const float4x2& v)   { c0 = (int4)v.c0;    c1 = (int4)v.c1;  }
    int4x2::int4x2(const double4x2& v)  { c0 = (int4)v.c0;    c1 = (int4)v.c1;  }

	//=========================================================
	// int4x3
	//=========================================================
	int4x3::int4x3(bool v)
	{
		c0 = math::select(int4(0), int4(1), v);
		c1 = math::select(int4(0), int4(1), v);
		c2 = math::select(int4(0), int4(1), v);
	}
	int4x3::int4x3(const bool4x3& v)
	{
		c0 = math::select(int4(0), int4(1), v.c0);
		c1 = math::select(int4(0), int4(1), v.c1);
		c2 = math::select(int4(0), int4(1), v.c2);
	}
    int4x3::int4x3(const int4x3& v)         {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          }
    int4x3::int4x3(const uint4x3& v)        {   c0 = (int4)v.c0;    c1 = (int4)v.c1;    c2 = (int4)v.c2;    }
    int4x3::int4x3(const float4x3& v)       {   c0 = (int4)v.c0;    c1 = (int4)v.c1;    c2 = (int4)v.c2;    }
    int4x3::int4x3(const double4x3& v)      {   c0 = (int4)v.c0;    c1 = (int4)v.c1;    c2 = (int4)v.c2;    }

	//=========================================================
	// int4x4
	//=========================================================
	int4x4::int4x4(bool v)
	{
		c0 = math::select(int4(0), int4(1), v);
		c1 = math::select(int4(0), int4(1), v);
		c2 = math::select(int4(0), int4(1), v);
		c3 = math::select(int4(0), int4(1), v);
	}
	int4x4::int4x4(const bool4x4& v)
	{
		c0 = math::select(int4(0), int4(1), v.c0);
		c1 = math::select(int4(0), int4(1), v.c1);
		c2 = math::select(int4(0), int4(1), v.c2);
		c3 = math::select(int4(0), int4(1), v.c3);
	}
    int4x4::int4x4(const uint4x4& v)	{	c0 = (int4)v.c0;	c1 = (int4)v.c1;	c2 = (int4)v.c2;	c3 = (int4)v.c3;	}
    int4x4::int4x4(const int4x4& v)		{	c0 = v.c0;			c1 = v.c1;			c2 = v.c2;			c3 = v.c3;			}
    int4x4::int4x4(const float4x4& v)	{	c0 = (int4)v.c0;	c1 = (int4)v.c1;	c2 = (int4)v.c2;	c3 = (int4)v.c3;	}
    int4x4::int4x4(const double4x4& v)	{	c0 = (int4)v.c0;	c1 = (int4)v.c1;	c2 = (int4)v.c2;	c3 = (int4)v.c3;	}

    namespace math
    {
        //=========================================================
        // math-int4
        //=========================================================
        int select_shuffle_component(const int4& a, const int4& b, ShuffleComponent component)
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
        uint hash(const int4& v)
        {
            return math::csum(math::asuint(v) * uint4(0x6E050B01u, 0x750FDBF5u, 0x7F3DD499u, 0x52EAAEBBu)) + 0x4599C793u;
        }
        uint4 hashwide(const int4& v)
        {
            return (math::asuint(v) * uint4(0x83B5E729u, 0xC267163Fu, 0x67BC9149u, 0xAD7C5EC1u)) + 0x822A7D6Du;
        }
        int shuffle(const int4& left, const int4& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        int2 shuffle(const int4& left, const int4& right, ShuffleComponent x, ShuffleComponent y)
        {
            return int2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        int3 shuffle(const int4& left, const int4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return int3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        int4 shuffle(const int4& left, const int4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return int4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }
        //=========================================================
        // math-int4x2
        //=========================================================
        int2x4 transpose(const int4x2& v)
        {
            return int2x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w);
        }
        uint hash(const int4x2& v)
        {
            return math::csum(math::asuint(v.c0) * uint4(0xFAAF07DDu, 0x625C45BDu, 0xC9F27FCBu, 0x6D2523B1u) +
                              math::asuint(v.c1) * uint4(0x6E2BF6A9u, 0xCC74B3B7u, 0x83B58237u, 0x833E3E29u)) + 0xA9D919BFu;
        }
        uint4 hashwide(const int4x2& v)
        {
            return (math::asuint(v.c0) * uint4(0xC3EC1D97u, 0xB8B208C7u, 0x5D3ED947u, 0x4473BBB1u) +
                    math::asuint(v.c1) * uint4(0xCBA11D5Fu, 0x685835CFu, 0xC3D32AE1u, 0xB966942Fu)) + 0xFE9856B3u;
        }

        //=========================================================
	    // math-int4x3
	    //=========================================================
        int3x4 transpose(const int4x3& v)
        {
            return int3x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w);
        }
        uint hash(const int4x3& v)
        {
            return math::csum(math::asuint(v.c0) * uint4(0x69B60C81u, 0xE0EB6C25u, 0xF648BEABu, 0x6BDB2B07u) +
						      math::asuint(v.c1) * uint4(0xEF63C699u, 0x9001903Fu, 0xA895B9CDu, 0x9D23B201u) +
						      math::asuint(v.c2) * uint4(0x4B01D3E1u, 0x7461CA0Du, 0x79725379u, 0xD6258E5Bu)) + 0xEE390C97u;
        }
        uint4 hashwide(const int4x3& v)
        {
            return (math::asuint(v.c0) * uint4(0x9C8A2F05u, 0x4DDC6509u, 0x7CF083CBu, 0x5C4D6CEDu) +
                    math::asuint(v.c1) * uint4(0xF9137117u, 0xE857DCE1u, 0xF62213C5u, 0x9CDAA959u) +
                    math::asuint(v.c2) * uint4(0xAA269ABFu, 0xD54BA36Fu, 0xFD0847B9u, 0x8189A683u)) + 0xB139D651u;
        }

        //=========================================================
	    // math-int4x4
	    //=========================================================
        int4x4 transpose(const int4x4& v)
        {
            return int4x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w,
                v.c3.x, v.c3.y, v.c3.z, v.c3.w);
        }
        int determinant(const int4x4& m)
        {
            int4 c0 = m.c0;
            int4 c1 = m.c1;
            int4 c2 = m.c2;
            int4 c3 = m.c3;

            int m00 = c1.y * (c2.z * c3.w - c2.w * c3.z) - c2.y * (c1.z * c3.w - c1.w * c3.z) + c3.y * (c1.z * c2.w - c1.w * c2.z);
            int m01 = c0.y * (c2.z * c3.w - c2.w * c3.z) - c2.y * (c0.z * c3.w - c0.w * c3.z) + c3.y * (c0.z * c2.w - c0.w * c2.z);
            int m02 = c0.y * (c1.z * c3.w - c1.w * c3.z) - c1.y * (c0.z * c3.w - c0.w * c3.z) + c3.y * (c0.z * c1.w - c0.w * c1.z);
            int m03 = c0.y * (c1.z * c2.w - c1.w * c2.z) - c1.y * (c0.z * c2.w - c0.w * c2.z) + c2.y * (c0.z * c1.w - c0.w * c1.z);

            return c0.x * m00 - c1.x * m01 + c2.x * m02 - c3.x * m03;
        }
        uint hash(const int4x4& v)
        {
            return math::csum(math::asuint(v.c0) * uint4(0x5D1B165Bu, 0x87096CD7u, 0x4C7F6DD1u, 0x4822A3E9u) +
                              math::asuint(v.c1) * uint4(0xAAC3C25Du, 0xD21D0945u, 0x88FCAB2Du, 0x614DA60Du) +
                              math::asuint(v.c2) * uint4(0x5BA2C50Bu, 0x8C455ACBu, 0xCD266C89u, 0xF1852A33u) +
                              math::asuint(v.c3) * uint4(0x77E35E77u, 0x863E3729u, 0xE191B035u, 0x68586FAFu)) + 0xD4DFF6D3u;
        }
        uint4 hashwide(const int4x4& v)
        {
            return (math::asuint(v.c0) * uint4(0xCB634F4Du, 0x9B13B92Du, 0x4ABF0813u, 0x86068063u) +
                    math::asuint(v.c1) * uint4(0xD75513F9u, 0x5AB3E8CDu, 0x676E8407u, 0xB36DE767u) +
                    math::asuint(v.c2) * uint4(0x6FCA387Du, 0xAF0F3103u, 0xE4A056C7u, 0x841D8225u) +
                    math::asuint(v.c3) * uint4(0xC9393C7Du, 0xD42EAFA3u, 0xD9AFD06Du, 0x97A65421u)) + 0x7809205Fu;
        }
    }

} // namespace ecs

