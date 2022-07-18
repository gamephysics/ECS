#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// bool4
	//=========================================================
    bool4 bool4::xxxx() const           { return bool4(x, x, x, x); }
    bool4 bool4::xxxy() const           { return bool4(x, x, x, y); }
    bool4 bool4::xxxz() const           { return bool4(x, x, x, z); }
    bool4 bool4::xxxw() const           { return bool4(x, x, x, w); }
    bool4 bool4::xxyx() const           { return bool4(x, x, y, x); }
    bool4 bool4::xxyy() const           { return bool4(x, x, y, y); }
    bool4 bool4::xxyz() const           { return bool4(x, x, y, z); }
    bool4 bool4::xxyw() const           { return bool4(x, x, y, w); }
    bool4 bool4::xxzx() const           { return bool4(x, x, z, x); }
    bool4 bool4::xxzy() const           { return bool4(x, x, z, y); }
    bool4 bool4::xxzz() const           { return bool4(x, x, z, z); }
    bool4 bool4::xxzw() const           { return bool4(x, x, z, w); }
    bool4 bool4::xxwx() const           { return bool4(x, x, w, x); }
    bool4 bool4::xxwy() const           { return bool4(x, x, w, y); }
    bool4 bool4::xxwz() const           { return bool4(x, x, w, z); }
    bool4 bool4::xxww() const           { return bool4(x, x, w, w); }
    bool4 bool4::xyxx() const           { return bool4(x, y, x, x); }
    bool4 bool4::xyxy() const           { return bool4(x, y, x, y); }
    bool4 bool4::xyxz() const           { return bool4(x, y, x, z); }
    bool4 bool4::xyxw() const           { return bool4(x, y, x, w); }
    bool4 bool4::xyyx() const           { return bool4(x, y, y, x); }
    bool4 bool4::xyyy() const           { return bool4(x, y, y, y); }
    bool4 bool4::xyyz() const           { return bool4(x, y, y, z); }
    bool4 bool4::xyyw() const           { return bool4(x, y, y, w); }
    bool4 bool4::xyzx() const           { return bool4(x, y, z, x); }
    bool4 bool4::xyzy() const           { return bool4(x, y, z, y); }
    bool4 bool4::xyzz() const           { return bool4(x, y, z, z); }
    bool4 bool4::xyzw() const           { return bool4(x, y, z, w); }
    void  bool4::xyzw(const bool4& v)   { x = v.x; y = v.y; z = v.z; w = v.w; }
    bool4 bool4::xywx() const           { return bool4(x, y, w, x); }
    bool4 bool4::xywy() const           { return bool4(x, y, w, y); }
    bool4 bool4::xywz() const           { return bool4(x, y, w, z); }
    void  bool4::xywz(const bool4 &v)   { x = v.x; y = v.y; w = v.z; z = v.w; }
    bool4 bool4::xyww() const           { return bool4(x, y, w, w); }
    bool4 bool4::xzxx() const           { return bool4(x, z, x, x); }
    bool4 bool4::xzxy() const           { return bool4(x, z, x, y); }
    bool4 bool4::xzxz() const           { return bool4(x, z, x, z); }
    bool4 bool4::xzxw() const           { return bool4(x, z, x, w); }
    bool4 bool4::xzyx() const           { return bool4(x, z, y, x); }
    bool4 bool4::xzyy() const           { return bool4(x, z, y, y); }
    bool4 bool4::xzyz() const           { return bool4(x, z, y, z); }
    bool4 bool4::xzyw() const           { return bool4(x, z, y, w); }
    void  bool4::xzyw(const bool4& v)   { x = v.x; z = v.y; y = v.z; w = v.w; }
    bool4 bool4::xzzx() const           { return bool4(x, z, z, x); }
    bool4 bool4::xzzy() const           { return bool4(x, z, z, y); }
    bool4 bool4::xzzz() const           { return bool4(x, z, z, z); }
    bool4 bool4::xzzw() const           { return bool4(x, z, z, w); }
    bool4 bool4::xzwx() const           { return bool4(x, z, w, x); }
    bool4 bool4::xzwy() const           { return bool4(x, z, w, y); }
    void  bool4::xzwy(const bool4& v)   { x = v.x; z = v.y; w = v.z; y = v.w; }
    bool4 bool4::xzwz() const           { return bool4(x, z, w, z); }
    bool4 bool4::xzww() const           { return bool4(x, z, w, w); }
    bool4 bool4::xwxx() const           { return bool4(x, w, x, x); }
    bool4 bool4::xwxy() const           { return bool4(x, w, x, y); }
    bool4 bool4::xwxz() const           { return bool4(x, w, x, z); }
    bool4 bool4::xwxw() const           { return bool4(x, w, x, w); }
    bool4 bool4::xwyx() const           { return bool4(x, w, y, x); }
    bool4 bool4::xwyy() const           { return bool4(x, w, y, y); }
    bool4 bool4::xwyz() const           { return bool4(x, w, y, z); }
    void  bool4::xwyz(const bool4& v)   { x = v.x; w = v.y; y = v.z; z = v.w; }
    bool4 bool4::xwyw() const           { return bool4(x, w, y, w); }
    bool4 bool4::xwzx() const           { return bool4(x, w, z, x); }
    bool4 bool4::xwzy() const           { return bool4(x, w, z, y); }
    void  bool4::xwzy(const bool4& v)   { x = v.x; w = v.y; z = v.z; y = v.w; }
    bool4 bool4::xwzz() const           { return bool4(x, w, z, z); }
    bool4 bool4::xwzw() const           { return bool4(x, w, z, w); }
    bool4 bool4::xwwx() const           { return bool4(x, w, w, x); }
    bool4 bool4::xwwy() const           { return bool4(x, w, w, y); }
    bool4 bool4::xwwz() const           { return bool4(x, w, w, z); }
    bool4 bool4::xwww() const           { return bool4(x, w, w, w); }
    bool4 bool4::yxxx() const           { return bool4(y, x, x, x); }
    bool4 bool4::yxxy() const           { return bool4(y, x, x, y); }
    bool4 bool4::yxxz() const           { return bool4(y, x, x, z); }
    bool4 bool4::yxxw() const           { return bool4(y, x, x, w); }
    bool4 bool4::yxyx() const           { return bool4(y, x, y, x); }
    bool4 bool4::yxyy() const           { return bool4(y, x, y, y); }
    bool4 bool4::yxyz() const           { return bool4(y, x, y, z); }
    bool4 bool4::yxyw() const           { return bool4(y, x, y, w); }
    bool4 bool4::yxzx() const           { return bool4(y, x, z, x); }
    bool4 bool4::yxzy() const           { return bool4(y, x, z, y); }
    bool4 bool4::yxzz() const           { return bool4(y, x, z, z); }
    bool4 bool4::yxzw() const           { return bool4(y, x, z, w); }
    void  bool4::yxzw(const bool4& v)   { y = v.x; x = v.y; z = v.z; w = v.w; }
    bool4 bool4::yxwx() const           { return bool4(y, x, w, x); }
    bool4 bool4::yxwy() const           { return bool4(y, x, w, y); }
    bool4 bool4::yxwz() const           { return bool4(y, x, w, z); }
    void  bool4::yxwz(const bool4& v)   { y = v.x; x = v.y; w = v.z; z = v.w; }
    bool4 bool4::yxww() const           { return bool4(y, x, w, w); }
    bool4 bool4::yyxx() const           { return bool4(y, y, x, x); }
    bool4 bool4::yyxy() const           { return bool4(y, y, x, y); }
    bool4 bool4::yyxz() const           { return bool4(y, y, x, z); }
    bool4 bool4::yyxw() const           { return bool4(y, y, x, w); }
    bool4 bool4::yyyx() const           { return bool4(y, y, y, x); }
    bool4 bool4::yyyy() const           { return bool4(y, y, y, y); }
    bool4 bool4::yyyz() const           { return bool4(y, y, y, z); }
    bool4 bool4::yyyw() const           { return bool4(y, y, y, w); }
    bool4 bool4::yyzx() const           { return bool4(y, y, z, x); }
    bool4 bool4::yyzy() const           { return bool4(y, y, z, y); }
    bool4 bool4::yyzz() const           { return bool4(y, y, z, z); }
    bool4 bool4::yyzw() const           { return bool4(y, y, z, w); }
    bool4 bool4::yywx() const           { return bool4(y, y, w, x); }
    bool4 bool4::yywy() const           { return bool4(y, y, w, y); }
    bool4 bool4::yywz() const           { return bool4(y, y, w, z); }
    bool4 bool4::yyww() const           { return bool4(y, y, w, w); }
    bool4 bool4::yzxx() const           { return bool4(y, z, x, x); }
    bool4 bool4::yzxy() const           { return bool4(y, z, x, y); }
    bool4 bool4::yzxz() const           { return bool4(y, z, x, z); }
    bool4 bool4::yzxw() const           { return bool4(y, z, x, w); }
    void  bool4::yzxw(const bool4& v)   { y = v.x; z = v.y; x = v.z; w = v.w; }
    bool4 bool4::yzyx() const           { return bool4(y, z, y, x); }
    bool4 bool4::yzyy() const           { return bool4(y, z, y, y); }
    bool4 bool4::yzyz() const           { return bool4(y, z, y, z); }
    bool4 bool4::yzyw() const           { return bool4(y, z, y, w); }
    bool4 bool4::yzzx() const           { return bool4(y, z, z, x); }
    bool4 bool4::yzzy() const           { return bool4(y, z, z, y); }
    bool4 bool4::yzzz() const           { return bool4(y, z, z, z); }
    bool4 bool4::yzzw() const           { return bool4(y, z, z, w); }
    bool4 bool4::yzwx() const           { return bool4(y, z, w, x); }
    void  bool4::yzwx(const bool4& v)   { y = v.x; z = v.y; w = v.z; x = v.w; }
    bool4 bool4::yzwy() const           { return bool4(y, z, w, y); }
    bool4 bool4::yzwz() const           { return bool4(y, z, w, z); }
    bool4 bool4::yzww() const           { return bool4(y, z, w, w); }
    bool4 bool4::ywxx() const           { return bool4(y, w, x, x); }
    bool4 bool4::ywxy() const           { return bool4(y, w, x, y); }
    bool4 bool4::ywxz() const           { return bool4(y, w, x, z); }
    void  bool4::ywxz(const bool4& v)   { y = v.x; w = v.y; x = v.z; z = v.w; }
    bool4 bool4::ywxw() const           { return bool4(y, w, x, w); }
    bool4 bool4::ywyx() const           { return bool4(y, w, y, x); }
    bool4 bool4::ywyy() const           { return bool4(y, w, y, y); }
    bool4 bool4::ywyz() const           { return bool4(y, w, y, z); }
    bool4 bool4::ywyw() const           { return bool4(y, w, y, w); }
    bool4 bool4::ywzx() const           { return bool4(y, w, z, x); }
    void  bool4::ywzx(const bool4& v)   { y = v.x; w = v.y; z = v.z; x = v.w; }
    bool4 bool4::ywzy() const           { return bool4(y, w, z, y); }
    bool4 bool4::ywzz() const           { return bool4(y, w, z, z); }
    bool4 bool4::ywzw() const           { return bool4(y, w, z, w); }
    bool4 bool4::ywwx() const           { return bool4(y, w, w, x); }
    bool4 bool4::ywwy() const           { return bool4(y, w, w, y); }
    bool4 bool4::ywwz() const           { return bool4(y, w, w, z); }
    bool4 bool4::ywww() const           { return bool4(y, w, w, w); }
    bool4 bool4::zxxx() const           { return bool4(z, x, x, x); }
    bool4 bool4::zxxy() const           { return bool4(z, x, x, y); }
    bool4 bool4::zxxz() const           { return bool4(z, x, x, z); }
    bool4 bool4::zxxw() const           { return bool4(z, x, x, w); }
    bool4 bool4::zxyx() const           { return bool4(z, x, y, x); }
    bool4 bool4::zxyy() const           { return bool4(z, x, y, y); }
    bool4 bool4::zxyz() const           { return bool4(z, x, y, z); }
    bool4 bool4::zxyw() const           { return bool4(z, x, y, w); }
    void  bool4::zxyw(const bool4& v)   { z = v.x; x = v.y; y = v.z; w = v.w; }
    bool4 bool4::zxzx() const           { return bool4(z, x, z, x); }
    bool4 bool4::zxzy() const           { return bool4(z, x, z, y); }
    bool4 bool4::zxzz() const           { return bool4(z, x, z, z); }
    bool4 bool4::zxzw() const           { return bool4(z, x, z, w); }
    bool4 bool4::zxwx() const           { return bool4(z, x, w, x); }
    bool4 bool4::zxwy() const           { return bool4(z, x, w, y); }
    void  bool4::zxwy(const bool4& v)   { z = v.x; x = v.y; w = v.z; y = v.w; }
    bool4 bool4::zxwz() const           { return bool4(z, x, w, z); }
    bool4 bool4::zxww() const           { return bool4(z, x, w, w); }
    bool4 bool4::zyxx() const           { return bool4(z, y, x, x); }
    bool4 bool4::zyxy() const           { return bool4(z, y, x, y); }
    bool4 bool4::zyxz() const           { return bool4(z, y, x, z); }
    bool4 bool4::zyxw() const           { return bool4(z, y, x, w); }
    void  bool4::zyxw(const bool4& v)   { z = v.x; y = v.y; x = v.z; w = v.w; }
    bool4 bool4::zyyx() const           { return bool4(z, y, y, x); }
    bool4 bool4::zyyy() const           { return bool4(z, y, y, y); }
    bool4 bool4::zyyz() const           { return bool4(z, y, y, z); }
    bool4 bool4::zyyw() const           { return bool4(z, y, y, w); }
    bool4 bool4::zyzx() const           { return bool4(z, y, z, x); }
    bool4 bool4::zyzy() const           { return bool4(z, y, z, y); }
    bool4 bool4::zyzz() const           { return bool4(z, y, z, z); }
    bool4 bool4::zyzw() const           { return bool4(z, y, z, w); }
    bool4 bool4::zywx() const           { return bool4(z, y, w, x); }
    void  bool4::zywx(const bool4& v)   { z = v.x; y = v.y; w = v.z; x = v.w; }
    bool4 bool4::zywy() const           { return bool4(z, y, w, y); }
    bool4 bool4::zywz() const           { return bool4(z, y, w, z); }
    bool4 bool4::zyww() const           { return bool4(z, y, w, w); }
    bool4 bool4::zzxx() const           { return bool4(z, z, x, x); }
    bool4 bool4::zzxy() const           { return bool4(z, z, x, y); }
    bool4 bool4::zzxz() const           { return bool4(z, z, x, z); }
    bool4 bool4::zzxw() const           { return bool4(z, z, x, w); }
    bool4 bool4::zzyx() const           { return bool4(z, z, y, x); }
    bool4 bool4::zzyy() const           { return bool4(z, z, y, y); }
    bool4 bool4::zzyz() const           { return bool4(z, z, y, z); }
    bool4 bool4::zzyw() const           { return bool4(z, z, y, w); }
    bool4 bool4::zzzx() const           { return bool4(z, z, z, x); }
    bool4 bool4::zzzy() const           { return bool4(z, z, z, y); }
    bool4 bool4::zzzz() const           { return bool4(z, z, z, z); }
    bool4 bool4::zzzw() const           { return bool4(z, z, z, w); }
    bool4 bool4::zzwx() const           { return bool4(z, z, w, x); }
    bool4 bool4::zzwy() const           { return bool4(z, z, w, y); }
    bool4 bool4::zzwz() const           { return bool4(z, z, w, z); }
    bool4 bool4::zzww() const           { return bool4(z, z, w, w); }
    bool4 bool4::zwxx() const           { return bool4(z, w, x, x); }
    bool4 bool4::zwxy() const           { return bool4(z, w, x, y); }
    void  bool4::zwxy(const bool4& v)   { z = v.x; w = v.y; x = v.z; y = v.w; }
    bool4 bool4::zwxz() const           { return bool4(z, w, x, z); }
    bool4 bool4::zwxw() const           { return bool4(z, w, x, w); }
    bool4 bool4::zwyx() const           { return bool4(z, w, y, x); }
    void  bool4::zwyx(const bool4& v)   { z = v.x; w = v.y; y = v.z; x = v.w; }
    bool4 bool4::zwyy() const           { return bool4(z, w, y, y); }
    bool4 bool4::zwyz() const           { return bool4(z, w, y, z); }
    bool4 bool4::zwyw() const           { return bool4(z, w, y, w); }
    bool4 bool4::zwzx() const           { return bool4(z, w, z, x); }
    bool4 bool4::zwzy() const           { return bool4(z, w, z, y); }
    bool4 bool4::zwzz() const           { return bool4(z, w, z, z); }
    bool4 bool4::zwzw() const           { return bool4(z, w, z, w); }
    bool4 bool4::zwwx() const           { return bool4(z, w, w, x); }
    bool4 bool4::zwwy() const           { return bool4(z, w, w, y); }
    bool4 bool4::zwwz() const           { return bool4(z, w, w, z); }
    bool4 bool4::zwww() const           { return bool4(z, w, w, w); }
    bool4 bool4::wxxx() const           { return bool4(w, x, x, x); }
    bool4 bool4::wxxy() const           { return bool4(w, x, x, y); }
    bool4 bool4::wxxz() const           { return bool4(w, x, x, z); }
    bool4 bool4::wxxw() const           { return bool4(w, x, x, w); }
    bool4 bool4::wxyx() const           { return bool4(w, x, y, x); }
    bool4 bool4::wxyy() const           { return bool4(w, x, y, y); }
    bool4 bool4::wxyz() const           { return bool4(w, x, y, z); }
    void  bool4::wxyz(const bool4& v)   { w = v.x; x = v.y; y = v.z; z = v.w; }
    bool4 bool4::wxyw() const           { return bool4(w, x, y, w); }
    bool4 bool4::wxzx() const           { return bool4(w, x, z, x); }
    bool4 bool4::wxzy() const           { return bool4(w, x, z, y); }
    void  bool4::wxzy(const bool4& v)   { w = v.x; x = v.y; z = v.z; y = v.w; }
    bool4 bool4::wxzz() const           { return bool4(w, x, z, z); }
    bool4 bool4::wxzw() const           { return bool4(w, x, z, w); }
    bool4 bool4::wxwx() const           { return bool4(w, x, w, x); }
    bool4 bool4::wxwy() const           { return bool4(w, x, w, y); }
    bool4 bool4::wxwz() const           { return bool4(w, x, w, z); }
    bool4 bool4::wxww() const           { return bool4(w, x, w, w); }
    bool4 bool4::wyxx() const           { return bool4(w, y, x, x); }
    bool4 bool4::wyxy() const           { return bool4(w, y, x, y); }
    bool4 bool4::wyxz() const           { return bool4(w, y, x, z); }
    void  bool4::wyxz(const bool4& v)   { w = v.x; y = v.y; x = v.z; z = v.w; }
    bool4 bool4::wyxw() const           { return bool4(w, y, x, w); }
    bool4 bool4::wyyx() const           { return bool4(w, y, y, x); }
    bool4 bool4::wyyy() const           { return bool4(w, y, y, y); }
    bool4 bool4::wyyz() const           { return bool4(w, y, y, z); }
    bool4 bool4::wyyw() const           { return bool4(w, y, y, w); }
    bool4 bool4::wyzx() const           { return bool4(w, y, z, x); }
    void  bool4::wyzx(const bool4& v)   { w = v.x; y = v.y; z = v.z; x = v.w; }
    bool4 bool4::wyzy() const           { return bool4(w, y, z, y); }
    bool4 bool4::wyzz() const           { return bool4(w, y, z, z); }
    bool4 bool4::wyzw() const           { return bool4(w, y, z, w); }
    bool4 bool4::wywx() const           { return bool4(w, y, w, x); }
    bool4 bool4::wywy() const           { return bool4(w, y, w, y); }
    bool4 bool4::wywz() const           { return bool4(w, y, w, z); }
    bool4 bool4::wyww() const           { return bool4(w, y, w, w); }
    bool4 bool4::wzxx() const           { return bool4(w, z, x, x); }
    bool4 bool4::wzxy() const           { return bool4(w, z, x, y); }
    void  bool4::wzxy(const bool4& v)   { w = v.x; z = v.y; x = v.z; y = v.w; }
    bool4 bool4::wzxz() const           { return bool4(w, z, x, z); }
    bool4 bool4::wzxw() const           { return bool4(w, z, x, w); }
    bool4 bool4::wzyx() const           { return bool4(w, z, y, x); }
    void  bool4::wzyx(const bool4& v)   { w = v.x; z = v.y; y = v.z; x = v.w; }
    bool4 bool4::wzyy() const           { return bool4(w, z, y, y); }
    bool4 bool4::wzyz() const           { return bool4(w, z, y, z); }
    bool4 bool4::wzyw() const           { return bool4(w, z, y, w); }
    bool4 bool4::wzzx() const           { return bool4(w, z, z, x); }
    bool4 bool4::wzzy() const           { return bool4(w, z, z, y); }
    bool4 bool4::wzzz() const           { return bool4(w, z, z, z); }
    bool4 bool4::wzzw() const           { return bool4(w, z, z, w); }
    bool4 bool4::wzwx() const           { return bool4(w, z, w, x); }
    bool4 bool4::wzwy() const           { return bool4(w, z, w, y); }
    bool4 bool4::wzwz() const           { return bool4(w, z, w, z); }
    bool4 bool4::wzww() const           { return bool4(w, z, w, w); }
    bool4 bool4::wwxx() const           { return bool4(w, w, x, x); }
    bool4 bool4::wwxy() const           { return bool4(w, w, x, y); }
    bool4 bool4::wwxz() const           { return bool4(w, w, x, z); }
    bool4 bool4::wwxw() const           { return bool4(w, w, x, w); }
    bool4 bool4::wwyx() const           { return bool4(w, w, y, x); }
    bool4 bool4::wwyy() const           { return bool4(w, w, y, y); }
    bool4 bool4::wwyz() const           { return bool4(w, w, y, z); }
    bool4 bool4::wwyw() const           { return bool4(w, w, y, w); }
    bool4 bool4::wwzx() const           { return bool4(w, w, z, x); }
    bool4 bool4::wwzy() const           { return bool4(w, w, z, y); }
    bool4 bool4::wwzz() const           { return bool4(w, w, z, z); }
    bool4 bool4::wwzw() const           { return bool4(w, w, z, w); }
    bool4 bool4::wwwx() const           { return bool4(w, w, w, x); }
    bool4 bool4::wwwy() const           { return bool4(w, w, w, y); }
    bool4 bool4::wwwz() const           { return bool4(w, w, w, z); }
    bool4 bool4::wwww() const           { return bool4(w, w, w, w); }
    bool3 bool4::xxx()  const           { return bool3(x, x, x); }
    bool3 bool4::xxy()  const           { return bool3(x, x, y); }
    bool3 bool4::xxz()  const           { return bool3(x, x, z); }
    bool3 bool4::xxw()  const           { return bool3(x, x, w); }
    bool3 bool4::xyx()  const           { return bool3(x, y, x); }
    bool3 bool4::xyy()  const           { return bool3(x, y, y); }
    bool3 bool4::xyz()  const           { return bool3(x, y, z); }
    void  bool4::xyz(const bool3& v)    { x = v.x; y = v.y; z = v.z; }
    bool3 bool4::xyw()  const           { return bool3(x, y, w); }
    void  bool4::xyw(const bool3& v)    { x = v.x; y = v.y; w = v.z; }
    bool3 bool4::xzx()  const           { return bool3(x, z, x); }
    bool3 bool4::xzy()  const           { return bool3(x, z, y); }
    void  bool4::xzy(const bool3& v)    { x = v.x; z = v.y; y = v.z; }
    bool3 bool4::xzz()  const           { return bool3(x, z, z); }
    bool3 bool4::xzw()  const           { return bool3(x, z, w); }
    void  bool4::xzw(const bool3& v)    { x = v.x; z = v.y; w = v.z; }
    bool3 bool4::xwx()  const           { return bool3(x, w, x); }
    bool3 bool4::xwy()  const           { return bool3(x, w, y); }
    void  bool4::xwy(const bool3& v)    { x = v.x; w = v.y; y = v.z; }
    bool3 bool4::xwz()  const           { return bool3(x, w, z); }
    void  bool4::xwz(const bool3& v)    { x = v.x; w = v.y; z = v.z; }
    bool3 bool4::xww()  const           { return bool3(x, w, w); }
    bool3 bool4::yxx()  const           { return bool3(y, x, x); }
    bool3 bool4::yxy()  const           { return bool3(y, x, y); }
    bool3 bool4::yxz()  const           { return bool3(y, x, z); }
    void  bool4::yxz(const bool3& v)    { y = v.x; x = v.y; z = v.z; }
    bool3 bool4::yxw()  const           { return bool3(y, x, w); }
    void  bool4::yxw(const bool3& v)    { y = v.x; x = v.y; w = v.z; }
    bool3 bool4::yyx()  const           { return bool3(y, y, x); }
    bool3 bool4::yyy()  const           { return bool3(y, y, y); }
    bool3 bool4::yyz()  const           { return bool3(y, y, z); }
    bool3 bool4::yyw()  const           { return bool3(y, y, w); }
    bool3 bool4::yzx()  const           { return bool3(y, z, x); }
    void  bool4::yzx(const bool3& v)    { y = v.x; z = v.y; x = v.z; }
    bool3 bool4::yzy()  const           { return bool3(y, z, y); }
    bool3 bool4::yzz()  const           { return bool3(y, z, z); }
    bool3 bool4::yzw()  const           { return bool3(y, z, w); }
    void  bool4::yzw(const bool3& v)    { y = v.x; z = v.y; w = v.z; }
    bool3 bool4::ywx()  const           { return bool3(y, w, x); }
    void  bool4::ywx(const bool3& v)    { y = v.x; w = v.y; x = v.z; }
    bool3 bool4::ywy()  const           { return bool3(y, w, y); }
    bool3 bool4::ywz()  const           { return bool3(y, w, z); }
    void  bool4::ywz(const bool3& v)    { y = v.x; w = v.y; z = v.z; }
    bool3 bool4::yww()  const           { return bool3(y, w, w); }
    bool3 bool4::zxx()  const           { return bool3(z, x, x); }
    bool3 bool4::zxy()  const           { return bool3(z, x, y); }
    void  bool4::zxy(const bool3& v)    { z = v.x; x = v.y; y = v.z; }
    bool3 bool4::zxz()  const           { return bool3(z, x, z); }
    bool3 bool4::zxw()  const           { return bool3(z, x, w); }
    void  bool4::zxw(const bool3& v)    { z = v.x; x = v.y; w = v.z; }
    bool3 bool4::zyx()  const           { return bool3(z, y, x); }
    void  bool4::zyx(const bool3& v)    { z = v.x; y = v.y; x = v.z; }
    bool3 bool4::zyy()  const           { return bool3(z, y, y); }
    bool3 bool4::zyz()  const           { return bool3(z, y, z); }
    bool3 bool4::zyw()  const           { return bool3(z, y, w); }
    void  bool4::zyw(const bool3& v)    { z = v.x; y = v.y; w = v.z; }
    bool3 bool4::zzx()  const           { return bool3(z, z, x); }
    bool3 bool4::zzy()  const           { return bool3(z, z, y); }
    bool3 bool4::zzz()  const           { return bool3(z, z, z); }
    bool3 bool4::zzw()  const           { return bool3(z, z, w); }
    bool3 bool4::zwx()  const           { return bool3(z, w, x); }
    void  bool4::zwx(const bool3& v)    { z = v.x; w = v.y; x = v.z; }
    bool3 bool4::zwy()  const           { return bool3(z, w, y); }
    void  bool4::zwy(const bool3& v)    { z = v.x; w = v.y; y = v.z; }
    bool3 bool4::zwz()  const           { return bool3(z, w, z); }
    bool3 bool4::zww()  const           { return bool3(z, w, w); }
    bool3 bool4::wxx()  const           { return bool3(w, x, x); }
    bool3 bool4::wxy()  const           { return bool3(w, x, y); }
    void  bool4::wxy(const bool3& v)    { w = v.x; x = v.y; y = v.z; }
    bool3 bool4::wxz()  const           { return bool3(w, x, z); }
    void  bool4::wxz(const bool3& v)    { w = v.x; x = v.y; z = v.z; }  
    bool3 bool4::wxw()  const           { return bool3(w, x, w); }
    bool3 bool4::wyx()  const           { return bool3(w, y, x); }
    void  bool4::wyx(const bool3& v)    { w = v.x; y = v.y; x = v.z; }
    bool3 bool4::wyy()  const           { return bool3(w, y, y); }
    bool3 bool4::wyz()  const           { return bool3(w, y, z); }
    void  bool4::wyz(const bool3& v)    { w = v.x; y = v.y; z = v.z; }
    bool3 bool4::wyw()  const           { return bool3(w, y, w); }
    bool3 bool4::wzx()  const           { return bool3(w, z, x); }
    void  bool4::wzx(const bool3& v)    { w = v.x; z = v.y; x = v.z; }
    bool3 bool4::wzy()  const           { return bool3(w, z, y); }
    void  bool4::wzy(const bool3& v)    { w = v.x; z = v.y; y = v.z; }
    bool3 bool4::wzz()  const           { return bool3(w, z, z); }
    bool3 bool4::wzw()  const           { return bool3(w, z, w); }
    bool3 bool4::wwx()  const           { return bool3(w, w, x); }
    bool3 bool4::wwy()  const           { return bool3(w, w, y); }
    bool3 bool4::wwz()  const           { return bool3(w, w, z); }
    bool3 bool4::www()  const           { return bool3(w, w, w); }
    bool2 bool4::xx()   const           { return bool2(x, x); }        
    bool2 bool4::xy()   const           { return bool2(x, y); }
    void  bool4::xy(const bool2& v)     { x = v.x; y = v.y; }
    bool2 bool4::xz()   const           { return bool2(x, z); }
    void  bool4::xz(const bool2& v)     { x = v.x; z = v.y; }
    bool2 bool4::xw()   const           { return bool2(x, w); }
    void  bool4::xw(const bool2& v)     { x = v.x; w = v.y; }
    bool2 bool4::yx()   const           { return bool2(y, x); }
    void  bool4::yx(const bool2& v)     { y = v.x; x = v.y; }
    bool2 bool4::yy()   const           { return bool2(y, y); }
    bool2 bool4::yz()   const           { return bool2(y, z); }
    void  bool4::yz(const bool2& v)     { y = v.x; z = v.y; }
    bool2 bool4::yw()   const           { return bool2(y, w); }
    void  bool4::yw(const bool2& v)     { y = v.x; w = v.y; }
    bool2 bool4::zx()   const           { return bool2(z, x); }
    void  bool4::zx(const bool2& v)     { z = v.x; x = v.y; }
    bool2 bool4::zy()   const           { return bool2(z, y); }
    void  bool4::zy(const bool2& v)     { z = v.x; y = v.y; }
    bool2 bool4::zz()   const           { return bool2(z, z); }
    bool2 bool4::zw()   const           { return bool2(z, w); }
    void  bool4::zw(const bool2& v)     { z = v.x; w = v.y; }
    bool2 bool4::wx()   const           { return bool2(w, x); }
    void  bool4::wx(const bool2& v)     { w = v.x; x = v.y; }
    bool2 bool4::wy()   const           { return bool2(w, y); }
    void  bool4::wy(const bool2& v)     { w = v.x; y = v.y; }
    bool2 bool4::wz()   const           { return bool2(w, z); }
    void  bool4::wz(const bool2& v)     { w = v.x; z = v.y; }
    bool2 bool4::ww()   const           { return bool2(w, w); }

    namespace math
    {
        //=========================================================
        // math-bool4
        //=========================================================
        bool select_shuffle_component(const bool4& a, const bool4& b, ShuffleComponent component)
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
        uint hash(const bool4& v)
        {
            return math::csum(math::select(uint4(0x5FFF6B19u, 0x5E6CBF3Bu, 0xB546F2A5u, 0xBBCF63E7u), uint4(0xC53F4755u, 0x6985C229u, 0xE133B0B3u, 0xC3E0A3B9u), v));
        }
        uint4 hashwide(const bool4& v)
        {
            return (math::select(uint4(0xFE31134Fu, 0x712A34D7u, 0x9D77A59Bu, 0x4942CA39u), uint4(0xB40EC62Du, 0x565ED63Fu, 0x93C30C2Bu, 0xDCAF0351u), v));
        }
        bool shuffle(const bool4& left, const bool4& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        bool2 shuffle(const bool4& left, const bool4& right, ShuffleComponent x, ShuffleComponent y)
        {
            return bool2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        bool3 shuffle(const bool4& left, const bool4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return bool3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        bool4 shuffle(const bool4& left, const bool4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return bool4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }

        //=========================================================
        // math-bool4x2
        //=========================================================
        bool2x4 transpose(const bool4x2& v)
        {
            return bool2x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w);
        }
        uint hash(const bool4x2& v)
        {
            return math::csum(math::select(uint4(0xD19764C7u, 0xB5D0BF63u, 0xF9102C5Fu, 0x9881FB9Fu), uint4(0x56A1530Du, 0x804B722Du, 0x738E50E5u, 0x4FC93C25u), v.c0) +
						      math::select(uint4(0xCD0445A5u, 0xD2B90D9Bu, 0xD35C9B2Du, 0xA10D9E27u), uint4(0x568DAAA9u, 0x7530254Fu, 0x9F090439u, 0x5E9F85C9u), v.c1));
        }
        uint4 hashwide(const bool4x2& v)
        {
            return (math::select(uint4(0x8C4CA03Fu, 0xB8D969EDu, 0xAC5DB57Bu, 0xA91A02EDu), uint4(0xB3C49313u, 0xF43A9ABBu, 0x84E7E01Bu, 0x8E055BE5u), v.c0) +
                    math::select(uint4(0x6E624EB7u, 0x7383ED49u, 0xDD49C23Bu, 0xEBD0D005u), uint4(0x91475DF7u, 0x55E84827u, 0x90A285BBu, 0x5D19E1D5u), v.c1));
        }

        //=========================================================
        // math-bool4x3
        //=========================================================
        bool3x4 transpose(const bool4x3& v)
        {
            return bool3x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w);
        }
        uint hash(const bool4x3& v)
        {
            return math::csum(math::select(uint4(0xEADF0775u, 0x747A9D7Bu, 0x4111F799u, 0xB5F05AF1u), uint4(0xFD80290Bu, 0x8B65ADB7u, 0xDFF4F563u, 0x7069770Du), v.c0) +
                              math::select(uint4(0xD1224537u, 0xE99ED6F3u, 0x48125549u, 0xEEE2123Bu), uint4(0xE3AD9FE5u, 0xCE1CF8BFu, 0x7BE39F3Bu, 0xFAB9913Fu), v.c1) +
                              math::select(uint4(0xB4501269u, 0xE04B89FDu, 0xDB3DE101u, 0x7B6D1B4Bu), uint4(0x58399E77u, 0x5EAC29C9u, 0xFC6014F9u, 0x6BF6693Fu), v.c2));
        }
        uint4 hashwide(const bool4x3& v)
        {
            return (math::select(uint4(0x9D1B1D9Bu, 0xF842F5C1u, 0xA47EC335u, 0xA477DF57u), uint4(0xC4B1493Fu, 0xBA0966D3u, 0xAFBEE253u, 0x5B419C01u), v.c0) +
                    math::select(uint4(0x515D90F5u, 0xEC9F68F3u, 0xF9EA92D5u, 0xC2FAFCB9u), uint4(0x616E9CA1u, 0xC5C5394Bu, 0xCAE78587u, 0x7A1541C9u), v.c1) +
                    math::select(uint4(0xF83BD927u, 0x6A243BCBu, 0x509B84C9u, 0x91D13847u), uint4(0x52F7230Fu, 0xCF286E83u, 0xE121E6ADu, 0xC9CA1249u), v.c2));
        }

        //=========================================================
	    // math-bool4x4
	    //=========================================================
        bool4x4 transpose(const bool4x4& v)
        {
            return bool4x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w,
                v.c3.x, v.c3.y, v.c3.z, v.c3.w);
        }
        uint hash(const bool4x4& v)
        {
            return math::csum(math::select(uint4(0xD19764C7u, 0xB5D0BF63u, 0xF9102C5Fu, 0x9881FB9Fu), uint4(0x56A1530Du, 0x804B722Du, 0x738E50E5u, 0x4FC93C25u), v.c0) +
						      math::select(uint4(0xCD0445A5u, 0xD2B90D9Bu, 0xD35C9B2Du, 0xA10D9E27u), uint4(0x568DAAA9u, 0x7530254Fu, 0x9F090439u, 0x5E9F85C9u), v.c1) +
						      math::select(uint4(0x8C4CA03Fu, 0xB8D969EDu, 0xAC5DB57Bu, 0xA91A02EDu), uint4(0xB3C49313u, 0xF43A9ABBu, 0x84E7E01Bu, 0x8E055BE5u), v.c2) +
						      math::select(uint4(0x6E624EB7u, 0x7383ED49u, 0xDD49C23Bu, 0xEBD0D005u), uint4(0x91475DF7u, 0x55E84827u, 0x90A285BBu, 0x5D19E1D5u), v.c3));
        }					  
        uint4 hashwide(const bool4x4& v)
        {
            return (math::select(uint4(0xFAAF07DDu, 0x625C45BDu, 0xC9F27FCBu, 0x6D2523B1u), uint4(0x6E2BF6A9u, 0xCC74B3B7u, 0x83B58237u, 0x833E3E29u), v.c0) +
                    math::select(uint4(0xA9D919BFu, 0xC3EC1D97u, 0xB8B208C7u, 0x5D3ED947u), uint4(0x4473BBB1u, 0xCBA11D5Fu, 0x685835CFu, 0xC3D32AE1u), v.c1) +
                    math::select(uint4(0xB966942Fu, 0xFE9856B3u, 0xFA3A3285u, 0xAD55999Du), uint4(0xDCDD5341u, 0x94DDD769u, 0xA1E92D39u, 0x4583C801u), v.c2) +
                    math::select(uint4(0x9536A0F5u, 0xAF816615u, 0x9AF8D62Du, 0xE3600729u), uint4(0x5F17300Du, 0x670D6809u, 0x7AF32C49u, 0xAE131389u), v.c3));
        }
    }

} // namespace ecs