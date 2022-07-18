#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// float4
	//=========================================================
    float4::float4(const bool4& v)          {   x = v.x ? 1.0f : 0.0f;  y = v.y ? 1.0f : 0.0f;  z = v.z ? 1.0f : 0.0f;  w = v.w ? 1.0f : 0.0f;  }
    float4::float4(const uint4& v)          {   x = (float)v.x; y = (float)v.y; z = (float)v.z; w = (float)v.w; }
    float4::float4(const int4& v)           {   x = (float)v.x; y = (float)v.y; z = (float)v.z; w = (float)v.w; }
    //float4::float4(const half4& v)        {   x = (float)v.x; y = (float)v.y; z = (float)v.z; w = (float)v.w; }
    float4::float4(const float4& v)         {   x = v.x;        y = v.y;        z = v.z;        w = v.w;        }
    float4::float4(const double4& v)        {   x = (float)v.x; y = (float)v.y; z = (float)v.z; w = (float)v.w; }


    float4 float4::xxxx()   const           { return float4(x, x, x, x); }
    float4 float4::xxxy()   const           { return float4(x, x, x, y); }
    float4 float4::xxxz()   const           { return float4(x, x, x, z); }
    float4 float4::xxxw()   const           { return float4(x, x, x, w); }
    float4 float4::xxyx()   const           { return float4(x, x, y, x); }
    float4 float4::xxyy()   const           { return float4(x, x, y, y); }
    float4 float4::xxyz()   const           { return float4(x, x, y, z); }
    float4 float4::xxyw()   const           { return float4(x, x, y, w); }
    float4 float4::xxzx()   const           { return float4(x, x, z, x); }
    float4 float4::xxzy()   const           { return float4(x, x, z, y); }
    float4 float4::xxzz()   const           { return float4(x, x, z, z); }
    float4 float4::xxzw()   const           { return float4(x, x, z, w); }
    float4 float4::xxwx()   const           { return float4(x, x, w, x); }
    float4 float4::xxwy()   const           { return float4(x, x, w, y); }
    float4 float4::xxwz()   const           { return float4(x, x, w, z); }
    float4 float4::xxww()   const           { return float4(x, x, w, w); }
    float4 float4::xyxx()   const           { return float4(x, y, x, x); }
    float4 float4::xyxy()   const           { return float4(x, y, x, y); }
    float4 float4::xyxz()   const           { return float4(x, y, x, z); }
    float4 float4::xyxw()   const           { return float4(x, y, x, w); }
    float4 float4::xyyx()   const           { return float4(x, y, y, x); }
    float4 float4::xyyy()   const           { return float4(x, y, y, y); }
    float4 float4::xyyz()   const           { return float4(x, y, y, z); }
    float4 float4::xyyw()   const           { return float4(x, y, y, w); }
    float4 float4::xyzx()   const           { return float4(x, y, z, x); }
    float4 float4::xyzy()   const           { return float4(x, y, z, y); }
    float4 float4::xyzz()   const           { return float4(x, y, z, z); }
    float4 float4::xyzw()   const           { return float4(x, y, z, w); }
    void   float4::xyzw(const float4& v)    { x = v.x; y = v.y; z = v.z; w = v.w; }
    float4 float4::xywx()   const           { return float4(x, y, w, x); }
    float4 float4::xywy()   const           { return float4(x, y, w, y); }
    float4 float4::xywz()   const           { return float4(x, y, w, z); }
    void   float4::xywz(const float4& v)    { x = v.x; y = v.y; w = v.z; z = v.w; }
    float4 float4::xyww()   const           { return float4(x, y, w, w); }
    float4 float4::xzxx()   const           { return float4(x, z, x, x); }
    float4 float4::xzxy()   const           { return float4(x, z, x, y); }
    float4 float4::xzxz()   const           { return float4(x, z, x, z); }
    float4 float4::xzxw()   const           { return float4(x, z, x, w); }
    float4 float4::xzyx()   const           { return float4(x, z, y, x); }
    float4 float4::xzyy()   const           { return float4(x, z, y, y); }
    float4 float4::xzyz()   const           { return float4(x, z, y, z); }
    float4 float4::xzyw()   const           { return float4(x, z, y, w); }
    void   float4::xzyw(const float4& v)    { x = v.x; z = v.y; y = v.z; w = v.w; }
	float4 float4::xzzx()   const           { return float4(x, z, z, x); }
	float4 float4::xzzy()   const           { return float4(x, z, z, y); }
	float4 float4::xzzz()   const           { return float4(x, z, z, z); }
	float4 float4::xzzw()   const           { return float4(x, z, z, w); }
	float4 float4::xzwx()   const           { return float4(x, z, w, x); }
	float4 float4::xzwy()   const           { return float4(x, z, w, y); }
    void   float4::xzwy(const float4& v)    { x = v.x; z = v.y; w = v.z; y = v.w; }
    float4 float4::xzwz()   const           { return float4(x, z, w, z); }
    float4 float4::xzww()   const           { return float4(x, z, w, w); }
    float4 float4::xwxx()   const           { return float4(x, w, x, x); }
    float4 float4::xwxy()   const           { return float4(x, w, x, y); }
    float4 float4::xwxz()   const           { return float4(x, w, x, z); }
    float4 float4::xwxw()   const           { return float4(x, w, x, w); }
    float4 float4::xwyx()   const           { return float4(x, w, y, x); }
    float4 float4::xwyy()   const           { return float4(x, w, y, y); }
    float4 float4::xwyz()   const           { return float4(x, w, y, z); }
    void   float4::xwyz(const float4& v)    { x = v.x; w = v.y; y = v.z; z = v.w; }
    float4 float4::xwyw()   const           { return float4(x, w, y, w); }
    float4 float4::xwzx()   const           { return float4(x, w, z, x); }
    float4 float4::xwzy()   const           { return float4(x, w, z, y); }
    void   float4::xwzy(const float4& v)    { x = v.x; w = v.y; z = v.z; y = v.w; }
    float4 float4::xwzz()   const           { return float4(x, w, z, z); }
    float4 float4::xwzw()   const           { return float4(x, w, z, w); }
    float4 float4::xwwx()   const           { return float4(x, w, w, x); }
    float4 float4::xwwy()   const           { return float4(x, w, w, y); }
    float4 float4::xwwz()   const           { return float4(x, w, w, z); }
    float4 float4::xwww()   const           { return float4(x, w, w, w); }
    float4 float4::yxxx()   const           { return float4(y, x, x, x); }
    float4 float4::yxxy()   const           { return float4(y, x, x, y); }
    float4 float4::yxxz()   const           { return float4(y, x, x, z); }
    float4 float4::yxxw()   const           { return float4(y, x, x, w); }
    float4 float4::yxyx()   const           { return float4(y, x, y, x); }
    float4 float4::yxyy()   const           { return float4(y, x, y, y); }
    float4 float4::yxyz()   const           { return float4(y, x, y, z); }
    float4 float4::yxyw()   const           { return float4(y, x, y, w); }
    float4 float4::yxzx()   const           { return float4(y, x, z, x); }
    float4 float4::yxzy()   const           { return float4(y, x, z, y); }
    float4 float4::yxzz()   const           { return float4(y, x, z, z); }
    float4 float4::yxzw()   const           { return float4(y, x, z, w); }
    void   float4::yxzw(const float4& v)    { y = v.x; x = v.y; z = v.z; w = v.w; }
    float4 float4::yxwx()   const           { return float4(y, x, w, x); }
    float4 float4::yxwy()   const           { return float4(y, x, w, y); }
    float4 float4::yxwz()   const           { return float4(y, x, w, z); }
    void   float4::yxwz(const float4& v)    { y = v.x; x = v.y; w = v.z; z = v.w; }
    float4 float4::yxww()   const           { return float4(y, x, w, w); }
    float4 float4::yyxx()   const           { return float4(y, y, x, x); }
    float4 float4::yyxy()   const           { return float4(y, y, x, y); }
    float4 float4::yyxz()   const           { return float4(y, y, x, z); }
    float4 float4::yyxw()   const           { return float4(y, y, x, w); }
    float4 float4::yyyx()   const           { return float4(y, y, y, x); }
    float4 float4::yyyy()   const           { return float4(y, y, y, y); }
    float4 float4::yyyz()   const           { return float4(y, y, y, z); }
    float4 float4::yyyw()   const           { return float4(y, y, y, w); }
    float4 float4::yyzx()   const           { return float4(y, y, z, x); }
    float4 float4::yyzy()   const           { return float4(y, y, z, y); }
    float4 float4::yyzz()   const           { return float4(y, y, z, z); }
    float4 float4::yyzw()   const           { return float4(y, y, z, w); }
    float4 float4::yywx()   const           { return float4(y, y, w, x); }
    float4 float4::yywy()   const           { return float4(y, y, w, y); }
    float4 float4::yywz()   const           { return float4(y, y, w, z); }
    float4 float4::yyww()   const           { return float4(y, y, w, w); }
    float4 float4::yzxx()   const           { return float4(y, z, x, x); }
    float4 float4::yzxy()   const           { return float4(y, z, x, y); }
    float4 float4::yzxz()   const           { return float4(y, z, x, z); }
    float4 float4::yzxw()   const           { return float4(y, z, x, w); }
    void   float4::yzxw(const float4& v)    { y = v.x; z = v.y; x = v.z; w = v.w; }
    float4 float4::yzyx()   const           { return float4(y, z, y, x); }
    float4 float4::yzyy()   const           { return float4(y, z, y, y); }
    float4 float4::yzyz()   const           { return float4(y, z, y, z); }
    float4 float4::yzyw()   const           { return float4(y, z, y, w); }
    float4 float4::yzzx()   const           { return float4(y, z, z, x); }
    float4 float4::yzzy()   const           { return float4(y, z, z, y); }
    float4 float4::yzzz()   const           { return float4(y, z, z, z); }
    float4 float4::yzzw()   const           { return float4(y, z, z, w); }
    float4 float4::yzwx()   const           { return float4(y, z, w, x); }
    void   float4::yzwx(const float4& v)    { y = v.x; z = v.y; w = v.z; x = v.w; }
    float4 float4::yzwy()   const           { return float4(y, z, w, y); }
    float4 float4::yzwz()   const           { return float4(y, z, w, z); }
    float4 float4::yzww()   const           { return float4(y, z, w, w); }
    float4 float4::ywxx()   const           { return float4(y, w, x, x); }
    float4 float4::ywxy()   const           { return float4(y, w, x, y); }
    float4 float4::ywxz()   const           { return float4(y, w, x, z); }
    void   float4::ywxz(const float4& v)    { y = v.x; w = v.y; x = v.z; z = v.w; }
    float4 float4::ywxw()   const           { return float4(y, w, x, w); }
    float4 float4::ywyx()   const           { return float4(y, w, y, x); }
    float4 float4::ywyy()   const           { return float4(y, w, y, y); }
    float4 float4::ywyz()   const           { return float4(y, w, y, z); }
    float4 float4::ywyw()   const           { return float4(y, w, y, w); }
    float4 float4::ywzx()   const           { return float4(y, w, z, x); }
    void   float4::ywzx(const float4& v)   	{ y = v.x; w = v.y; z = v.z; x = v.w; }
    float4 float4::ywzy()   const           { return float4(y, w, z, y); }
    float4 float4::ywzz()   const           { return float4(y, w, z, z); }
    float4 float4::ywzw()   const           { return float4(y, w, z, w); }
    float4 float4::ywwx()   const           { return float4(y, w, w, x); }
    float4 float4::ywwy()   const           { return float4(y, w, w, y); }
    float4 float4::ywwz()   const           { return float4(y, w, w, z); }
    float4 float4::ywww()   const           { return float4(y, w, w, w); }
    float4 float4::zxxx()   const           { return float4(z, x, x, x); }
    float4 float4::zxxy()   const           { return float4(z, x, x, y); }
    float4 float4::zxxz()   const           { return float4(z, x, x, z); }
    float4 float4::zxxw()   const           { return float4(z, x, x, w); }
    float4 float4::zxyx()   const           { return float4(z, x, y, x); }
    float4 float4::zxyy()   const           { return float4(z, x, y, y); }
    float4 float4::zxyz()   const           { return float4(z, x, y, z); }
    float4 float4::zxyw()   const           { return float4(z, x, y, w); }
    void   float4::zxyw(const float4& v)    { z = v.x; x = v.y; y = v.z; w = v.w; }
    float4 float4::zxzx()   const           { return float4(z, x, z, x); }
    float4 float4::zxzy()   const           { return float4(z, x, z, y); }
    float4 float4::zxzz()   const           { return float4(z, x, z, z); }
    float4 float4::zxzw()   const           { return float4(z, x, z, w); }
    float4 float4::zxwx()   const           { return float4(z, x, w, x); }
    float4 float4::zxwy()   const           { return float4(z, x, w, y); }
    void   float4::zxwy(const float4& v)    { z = v.x; x = v.y; w = v.z; y = v.w; }
    float4 float4::zxwz()   const           { return float4(z, x, w, z); }
    float4 float4::zxww()   const           { return float4(z, x, w, w); }
    float4 float4::zyxx()   const           { return float4(z, y, x, x); }
    float4 float4::zyxy()   const           { return float4(z, y, x, y); }
    float4 float4::zyxz()   const           { return float4(z, y, x, z); }
    float4 float4::zyxw()   const           { return float4(z, y, x, w); }
    void   float4::zyxw(const float4& v)    { z = v.x; y = v.y; x = v.z; w = v.w; }
    float4 float4::zyyx()   const           { return float4(z, y, y, x); }
    float4 float4::zyyy()   const           { return float4(z, y, y, y); }
    float4 float4::zyyz()   const           { return float4(z, y, y, z); }
    float4 float4::zyyw()   const           { return float4(z, y, y, w); }
    float4 float4::zyzx()   const           { return float4(z, y, z, x); }
    float4 float4::zyzy()   const           { return float4(z, y, z, y); }
    float4 float4::zyzz()   const           { return float4(z, y, z, z); }
    float4 float4::zyzw()   const           { return float4(z, y, z, w); }
    float4 float4::zywx()   const           { return float4(z, y, w, x); }
    void   float4::zywx(const float4& v)    { z = v.x; y = v.y; w = v.z; x = v.w; }
    float4 float4::zywy()   const           { return float4(z, y, w, y); }
    float4 float4::zywz()   const           { return float4(z, y, w, z); }
    float4 float4::zyww()   const           { return float4(z, y, w, w); }
    float4 float4::zzxx()   const           { return float4(z, z, x, x); }
    float4 float4::zzxy()   const           { return float4(z, z, x, y); }
    float4 float4::zzxz()   const           { return float4(z, z, x, z); }
    float4 float4::zzxw()   const           { return float4(z, z, x, w); }
    float4 float4::zzyx()   const           { return float4(z, z, y, x); }
    float4 float4::zzyy()   const           { return float4(z, z, y, y); }
    float4 float4::zzyz()   const           { return float4(z, z, y, z); }
    float4 float4::zzyw()   const           { return float4(z, z, y, w); }
    float4 float4::zzzx()   const           { return float4(z, z, z, x); }
    float4 float4::zzzy()   const           { return float4(z, z, z, y); }
    float4 float4::zzzz()   const           { return float4(z, z, z, z); }
    float4 float4::zzzw()   const           { return float4(z, z, z, w); }
    float4 float4::zzwx()   const           { return float4(z, z, w, x); }
    float4 float4::zzwy()   const           { return float4(z, z, w, y); }
    float4 float4::zzwz()   const           { return float4(z, z, w, z); }
    float4 float4::zzww()   const           { return float4(z, z, w, w); }
    float4 float4::zwxx()   const           { return float4(z, w, x, x); }
    float4 float4::zwxy()   const           { return float4(z, w, x, y); }
    void   float4::zwxy(const float4& v)    { z = v.x; w = v.y; x = v.z; y = v.w; }
    float4 float4::zwxz()   const           { return float4(z, w, x, z); }
    float4 float4::zwxw()   const           { return float4(z, w, x, w); }
    float4 float4::zwyx()   const           { return float4(z, w, y, x); }
    void   float4::zwyx(const float4& v)    { z = v.x; w = v.y; y = v.z; x = v.w; }
    float4 float4::zwyy()   const           { return float4(z, w, y, y); }
    float4 float4::zwyz()   const           { return float4(z, w, y, z); }
    float4 float4::zwyw()   const           { return float4(z, w, y, w); }
    float4 float4::zwzx()   const           { return float4(z, w, z, x); }
    float4 float4::zwzy()   const           { return float4(z, w, z, y); }
    float4 float4::zwzz()   const           { return float4(z, w, z, z); }
    float4 float4::zwzw()   const           { return float4(z, w, z, w); }
    float4 float4::zwwx()   const           { return float4(z, w, w, x); }
    float4 float4::zwwy()   const           { return float4(z, w, w, y); }
    float4 float4::zwwz()   const           { return float4(z, w, w, z); }
    float4 float4::zwww()   const           { return float4(z, w, w, w); }
    float4 float4::wxxx()   const           { return float4(w, x, x, x); }
    float4 float4::wxxy()   const           { return float4(w, x, x, y); }
    float4 float4::wxxz()   const           { return float4(w, x, x, z); }
    float4 float4::wxxw()   const           { return float4(w, x, x, w); }
    float4 float4::wxyx()   const           { return float4(w, x, y, x); }
    float4 float4::wxyy()   const           { return float4(w, x, y, y); }
    float4 float4::wxyz()   const           { return float4(w, x, y, z); }
    void   float4::wxyz(const float4& v)    { w = v.x; x = v.y; y = v.z; z = v.w; }
    float4 float4::wxyw()   const           { return float4(w, x, y, w); }
    float4 float4::wxzx()   const           { return float4(w, x, z, x); }
    float4 float4::wxzy()   const           { return float4(w, x, z, y); }
    void   float4::wxzy(const float4& v)    { w = v.x; x = v.y; z = v.z; y = v.w; }
    float4 float4::wxzz()   const           { return float4(w, x, z, z); }
    float4 float4::wxzw()   const           { return float4(w, x, z, w); }
    float4 float4::wxwx()   const           { return float4(w, x, w, x); }
    float4 float4::wxwy()   const           { return float4(w, x, w, y); }
    float4 float4::wxwz()   const           { return float4(w, x, w, z); }
    float4 float4::wxww()   const           { return float4(w, x, w, w); }
    float4 float4::wyxx()   const           { return float4(w, y, x, x); }
    float4 float4::wyxy()   const           { return float4(w, y, x, y); }
    float4 float4::wyxz()   const           { return float4(w, y, x, z); }
    void   float4::wyxz(const float4& v)    { w = v.x; y = v.y; x = v.z; z = v.w; }
    float4 float4::wyxw()   const           { return float4(w, y, x, w); }
    float4 float4::wyyx()   const           { return float4(w, y, y, x); }
    float4 float4::wyyy()   const           { return float4(w, y, y, y); }
    float4 float4::wyyz()   const           { return float4(w, y, y, z); }
    float4 float4::wyyw()   const           { return float4(w, y, y, w); }
    float4 float4::wyzx()   const           { return float4(w, y, z, x); }
    void   float4::wyzx(const float4& v)    { w = v.x; y = v.y; z = v.z; x = v.w; }
    float4 float4::wyzy()   const           { return float4(w, y, z, y); }
    float4 float4::wyzz()   const           { return float4(w, y, z, z); }
    float4 float4::wyzw()   const           { return float4(w, y, z, w); }
    float4 float4::wywx()   const           { return float4(w, y, w, x); }
    float4 float4::wywy()   const           { return float4(w, y, w, y); }
    float4 float4::wywz()   const           { return float4(w, y, w, z); }
    float4 float4::wyww()   const           { return float4(w, y, w, w); }
    float4 float4::wzxx()   const           { return float4(w, z, x, x); }
    float4 float4::wzxy()   const           { return float4(w, z, x, y); }
    void   float4::wzxy(const float4& v)    { w = v.x; z = v.y; x = v.z; y = v.w; }
    float4 float4::wzxz()   const           { return float4(w, z, x, z); }
    float4 float4::wzxw()   const           { return float4(w, z, x, w); }
    float4 float4::wzyx()   const           { return float4(w, z, y, x); }
    void   float4::wzyx(const float4& v)    { w = v.x; z = v.y; y = v.z; x = v.w; }
    float4 float4::wzyy()   const           { return float4(w, z, y, y); }
    float4 float4::wzyz()   const           { return float4(w, z, y, z); }
    float4 float4::wzyw()   const           { return float4(w, z, y, w); }
    float4 float4::wzzx()   const           { return float4(w, z, z, x); }
    float4 float4::wzzy()   const           { return float4(w, z, z, y); }
    float4 float4::wzzz()   const           { return float4(w, z, z, z); }
    float4 float4::wzzw()   const           { return float4(w, z, z, w); }
    float4 float4::wzwx()   const           { return float4(w, z, w, x); }
    float4 float4::wzwy()   const           { return float4(w, z, w, y); }
    float4 float4::wzwz()   const           { return float4(w, z, w, z); }
    float4 float4::wzww()   const           { return float4(w, z, w, w); }
    float4 float4::wwxx()   const           { return float4(w, w, x, x); }
    float4 float4::wwxy()   const           { return float4(w, w, x, y); }
    float4 float4::wwxz()   const           { return float4(w, w, x, z); }
    float4 float4::wwxw()   const           { return float4(w, w, x, w); }
    float4 float4::wwyx()   const           { return float4(w, w, y, x); }
    float4 float4::wwyy()   const           { return float4(w, w, y, y); }
    float4 float4::wwyz()   const           { return float4(w, w, y, z); }
    float4 float4::wwyw()   const           { return float4(w, w, y, w); }
    float4 float4::wwzx()   const           { return float4(w, w, z, x); }
    float4 float4::wwzy()   const           { return float4(w, w, z, y); }
    float4 float4::wwzz()   const           { return float4(w, w, z, z); }
    float4 float4::wwzw()   const           { return float4(w, w, z, w); }
    float4 float4::wwwx()   const           { return float4(w, w, w, x); }
    float4 float4::wwwy()   const           { return float4(w, w, w, y); }
    float4 float4::wwwz()   const           { return float4(w, w, w, z); }
    float4 float4::wwww()   const           { return float4(w, w, w, w); }
    float3 float4::xxx()    const           { return float3(x, x, x); }
    float3 float4::xxy()    const           { return float3(x, x, y); }
    float3 float4::xxz()    const           { return float3(x, x, z); }
    float3 float4::xxw()    const           { return float3(x, x, w); }
    float3 float4::xyx()    const           { return float3(x, y, x); }
    float3 float4::xyy()    const           { return float3(x, y, y); }
    float3 float4::xyz()    const           { return float3(x, y, z); }
    void   float4::xyz(const float3& v)     { x = v.x; y = v.y; z = v.z; }
    float3 float4::xyw()    const           { return float3(x, y, w); }
    void   float4::xyw(const float3& v)     { x = v.x; y = v.y; w = v.z; }
    float3 float4::xzx()    const           { return float3(x, z, x); }
    float3 float4::xzy()    const           { return float3(x, z, y); }
    void   float4::xzy(const float3& v)     { x = v.x; z = v.y; y = v.z; }
    float3 float4::xzz()    const           { return float3(x, z, z); }
    float3 float4::xzw()    const           { return float3(x, z, w); }
    void   float4::xzw(const float3& v)     { x = v.x; z = v.y; w = v.z; }
    float3 float4::xwx()    const           { return float3(x, w, x); }
    float3 float4::xwy()    const           { return float3(x, w, y); }
    void   float4::xwy(const float3& v)     { x = v.x; w = v.y; y = v.z; }
    float3 float4::xwz()    const           { return float3(x, w, z); }
    void   float4::xwz(const float3& v)     { x = v.x; w = v.y; z = v.z; }
    float3 float4::xww()    const           { return float3(x, w, w); }
    float3 float4::yxx()    const           { return float3(y, x, x); }
    float3 float4::yxy()    const           { return float3(y, x, y); }
    float3 float4::yxz()    const           { return float3(y, x, z); }
    void   float4::yxz(const float3& v)     { y = v.x; x = v.y; z = v.z; }
    float3 float4::yxw()    const           { return float3(y, x, w); }
    void   float4::yxw(const float3& v)     { y = v.x; x = v.y; w = v.z; }
    float3 float4::yyx()    const           { return float3(y, y, x); }
    float3 float4::yyy()    const           { return float3(y, y, y); }
    float3 float4::yyz()    const           { return float3(y, y, z); }
    float3 float4::yyw()    const           { return float3(y, y, w); }
    float3 float4::yzx()    const           { return float3(y, z, x); }
    void   float4::yzx(const float3& v)     { y = v.x; z = v.y; x = v.z; }
    float3 float4::yzy()    const           { return float3(y, z, y); }
    float3 float4::yzz()    const           { return float3(y, z, z); }
    float3 float4::yzw()    const           { return float3(y, z, w); }
    void   float4::yzw(const float3& v)     { y = v.x; z = v.y; w = v.z; }
    float3 float4::ywx()    const           { return float3(y, w, x); }
    void   float4::ywx(const float3& v)     { y = v.x; w = v.y; x = v.z; }
    float3 float4::ywy()    const           { return float3(y, w, y); }
    float3 float4::ywz()    const           { return float3(y, w, z); }
    void   float4::ywz(const float3& v)     { y = v.x; w = v.y; z = v.z; }
    float3 float4::yww()    const           { return float3(y, w, w); }
    float3 float4::zxx()    const           { return float3(z, x, x); }
    float3 float4::zxy()    const           { return float3(z, x, y); }
    void   float4::zxy(const float3& v)     { z = v.x; x = v.y; y = v.z; }
    float3 float4::zxz()    const           { return float3(z, x, z); }
    float3 float4::zxw()    const           { return float3(z, x, w); }
    void   float4::zxw(const float3& v)     { z = v.x; x = v.y; w = v.z; }
    float3 float4::zyx()    const           { return float3(z, y, x); }
    void   float4::zyx(const float3& v)     { z = v.x; y = v.y; x = v.z; }
    float3 float4::zyy()    const           { return float3(z, y, y); }
    float3 float4::zyz()    const           { return float3(z, y, z); }
    float3 float4::zyw()    const           { return float3(z, y, w); }
    void   float4::zyw(const float3& v)     { z = v.x; y = v.y; w = v.z; }
    float3 float4::zzx()    const           { return float3(z, z, x); }
    float3 float4::zzy()    const           { return float3(z, z, y); }
    float3 float4::zzz()    const           { return float3(z, z, z); }
    float3 float4::zzw()    const           { return float3(z, z, w); }
    float3 float4::zwx()    const           { return float3(z, w, x); }
    void   float4::zwx(const float3& v)     { z = v.x; w = v.y; x = v.z; }
    float3 float4::zwy()    const           { return float3(z, w, y); }
    void   float4::zwy(const float3& v)     { z = v.x; w = v.y; y = v.z; }
    float3 float4::zwz()    const           { return float3(z, w, z); }
    float3 float4::zww()    const           { return float3(z, w, w); }
    float3 float4::wxx()    const           { return float3(w, x, x); }
    float3 float4::wxy()    const           { return float3(w, x, y); }
    void   float4::wxy(const float3& v)     { w = v.x; x = v.y; y = v.z; }
    float3 float4::wxz()    const           { return float3(w, x, z); }
    void   float4::wxz(const float3& v)     { w = v.x; x = v.y; z = v.z; }
    float3 float4::wxw()    const           { return float3(w, x, w); }
    float3 float4::wyx()    const           { return float3(w, y, x); }
    void   float4::wyx(const float3& v)     { w = v.x; y = v.y; x = v.z; }
    float3 float4::wyy()    const           { return float3(w, y, y); }
    float3 float4::wyz()    const           { return float3(w, y, z); }
    void   float4::wyz(const float3& v)     { w = v.x; y = v.y; z = v.z; }
    float3 float4::wyw()    const           { return float3(w, y, w); }
    float3 float4::wzx()    const           { return float3(w, z, x); }
    void   float4::wzx(const float3& v)     { w = v.x; z = v.y; x = v.z; }
    float3 float4::wzy()    const           { return float3(w, z, y); }
    void   float4::wzy(const float3& v)     { w = v.x; z = v.y; y = v.z; }
    float3 float4::wzz()    const           { return float3(w, z, z); }
    float3 float4::wzw()    const           { return float3(w, z, w); }
    float3 float4::wwx()    const           { return float3(w, w, x); }
    float3 float4::wwy()    const           { return float3(w, w, y); }
    float3 float4::wwz()    const           { return float3(w, w, z); }
    float3 float4::www()    const           { return float3(w, w, w); }
    float2 float4::xx()     const           { return float2(x, x); }
    float2 float4::xy()     const           { return float2(x, y); }
    void   float4::xy(const float2& v)      { x = v.x; y = v.y; }
    float2 float4::xz()     const           { return float2(x, z); }
    void   float4::xz(const float2& v)      { x = v.x; z = v.y; }
    float2 float4::xw()     const           { return float2(x, w); }
    void   float4::xw(const float2& v)      { x = v.x; w = v.y; }
    float2 float4::yx()     const           { return float2(y, x); }
    void   float4::yx(const float2& v)      { y = v.x; x = v.y; }
    float2 float4::yy()     const           { return float2(y, y); }
    float2 float4::yz()     const           { return float2(y, z); }
    void   float4::yz(const float2& v)      { y = v.x; z = v.y; }
    float2 float4::yw()     const           { return float2(y, w); }
    void   float4::yw(const float2& v)      { y = v.x; w = v.y; }
    float2 float4::zx()     const           { return float2(z, x); }
    void   float4::zx(const float2& v)      { z = v.x; x = v.y; }
    float2 float4::zy()     const           { return float2(z, y); }
    void   float4::zy(const float2& v)      { z = v.x; y = v.y; }
    float2 float4::zz()     const           { return float2(z, z); }
    float2 float4::zw()     const           { return float2(z, w); }
    void   float4::zw(const float2& v)      { z = v.x; w = v.y; }
    float2 float4::wx()     const           { return float2(w, x); }
    void   float4::wx(const float2& v)      { w = v.x; x = v.y; }
    float2 float4::wy()     const           { return float2(w, y); }
    void   float4::wy(const float2& v)      { w = v.x; y = v.y; }
    float2 float4::wz()     const           { return float2(w, z); }
    void   float4::wz(const float2& v)      { w = v.x; z = v.y; }
    float2 float4::ww()     const           { return float2(w, w); }

	//=========================================================
	// float4x2
	//=========================================================
    float4x2::float4x2(bool v)
	{
		c0 = math::select(float4(0.0f), float4(1.0f), v);
		c1 = math::select(float4(0.0f), float4(1.0f), v);
	}
    float4x2::float4x2(const bool4x2& v)
	{
		c0 = math::select(float4(0.0f), float4(1.0f), v.c0);
		c1 = math::select(float4(0.0f), float4(1.0f), v.c1);
	}
    float4x2::float4x2(const uint4x2& v)    { c0 = v.c0;		    c1 = v.c1; }
    float4x2::float4x2(const int4x2& v)     { c0 = v.c0;            c1 = v.c1; }
    float4x2::float4x2(const float4x2& v)   { c0 = v.c0;            c1 = v.c1; }
    float4x2::float4x2(const double4x2& v)  { c0 = (float4)v.c0;    c1 = (float4)v.c1; }

	//=========================================================
    // float4x3
    //=========================================================
	float4x3::float4x3(bool v)
	{
		c0 = math::select(float4(0.0f), float4(1.0f), v);
		c1 = math::select(float4(0.0f), float4(1.0f), v);
		c2 = math::select(float4(0.0f), float4(1.0f), v);
	}
	float4x3::float4x3(const bool4x3& v)
	{
		c0 = math::select(float4(0.0f), float4(1.0f), v.c0);
		c1 = math::select(float4(0.0f), float4(1.0f), v.c1);
		c2 = math::select(float4(0.0f), float4(1.0f), v.c2);
	}
	float4x3::float4x3(const int4x3& v)     {   c0 = v.c0;              c1 = v.c1;              c2 = v.c2;              }
    float4x3::float4x3(const uint4x3& v)    {   c0 = v.c0;              c1 = v.c1;              c2 = v.c2;              }
    float4x3::float4x3(const float4x3& v)   {   c0 = v.c0;              c1 = v.c1;              c2 = v.c2;              }
    float4x3::float4x3(const double4x3& v)  {   c0 = (float4)v.c0;      c1 = (float4)v.c1;      c2 = (float4)v.c2;      }

	//=========================================================
	// float4x4
	//=========================================================
	float4x4::float4x4(bool v)
	{
		c0 = math::select(float4(0.0f), float4(1.0f), v);
		c1 = math::select(float4(0.0f), float4(1.0f), v);
		c2 = math::select(float4(0.0f), float4(1.0f), v);
		c3 = math::select(float4(0.0f), float4(1.0f), v);
	}
	float4x4::float4x4(const bool4x4& v)
	{
		c0 = math::select(float4(0.0f), float4(1.0f), v.c0);
		c1 = math::select(float4(0.0f), float4(1.0f), v.c1);
		c2 = math::select(float4(0.0f), float4(1.0f), v.c2);
		c3 = math::select(float4(0.0f), float4(1.0f), v.c3);
	}
    float4x4::float4x4(const int4x4& v)     {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;          }
    float4x4::float4x4(const uint4x4& v)    {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;          }
    float4x4::float4x4(const float4x4& v)   {   c0 = v.c0;          c1 = v.c1;          c2 = v.c2;          c3 = v.c3;	        }
    float4x4::float4x4(const double4x4& v)  {   c0 = (float4)v.c0;  c1 = (float4)v.c1;  c2 = (float4)v.c2;  c3 = (float4)v.c3;  }

    //=========================================================
    // float4x4 matrix
    //=========================================================
    float4x4 float4x4::AxisAngle(const float3& axis, float angle)
    {
        float sina, cosa;
        math::sincos(angle, OUT sina, OUT cosa);

        float4 u = float4(axis, 0.0f);
        float4 u_yzx = u.yzxx();
        float4 u_zxy = u.zxyx();
        float4 u_inv_cosa = u - u * cosa;  // u * (1.0f - cosa);
        float4 t = float4(u.xyz() * sina, cosa);

        uint4 ppnp = uint4(0x00000000, 0x00000000, 0x80000000, 0x00000000);
        uint4 nppp = uint4(0x80000000, 0x00000000, 0x00000000, 0x00000000);
        uint4 pnpp = uint4(0x00000000, 0x80000000, 0x00000000, 0x00000000);
        uint4 mask = uint4(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000);

        return float4x4(
            u.x * u_inv_cosa + math::asfloat((math::asuint(t.wzyx()) ^ ppnp) & mask),
            u.y * u_inv_cosa + math::asfloat((math::asuint(t.zwxx()) ^ nppp) & mask),
            u.z * u_inv_cosa + math::asfloat((math::asuint(t.yxwx()) ^ pnpp) & mask),
            float4(0.0f, 0.0f, 0.0f, 1.0f)
        );
    }

    float4x4 float4x4::EulerXYZ(const float3& xyz)
    {
        // return mul(rotateZ(xyz.z), mul(rotateY(xyz.y), rotateX(xyz.x)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float4x4(
            c.y * c.z,  c.z * s.x * s.y - c.x * s.z,    c.x * c.z * s.y + s.x * s.z,    0.0f,
            c.y * s.z,  c.x * c.z + s.x * s.y * s.z,    c.x * s.y * s.z - c.z * s.x,    0.0f,
            -s.y,       c.y * s.x,                      c.x * c.y,                      0.0f,
            0.0f,       0.0f,                           0.0f,                           1.0f
            );
    }

    float4x4 float4x4::EulerXZY(const float3& xyz)
    {
        // return mul(rotateY(xyz.y), mul(rotateZ(xyz.z), rotateX(xyz.x))); }
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float4x4(
            c.y * c.z,  s.x * s.y - c.x * c.y * s.z,    c.x * s.y + c.y * s.x * s.z,    0.0f,
            s.z,        c.x * c.z,                      -c.z * s.x,                     0.0f,
            -c.z * s.y, c.y * s.x + c.x * s.y * s.z,    c.x * c.y - s.x * s.y * s.z,    0.0f,
            0.0f,       0.0f,                           0.0f,                           1.0f
            );
    }
    float4x4 float4x4::EulerYXZ(const float3& xyz)
    {
        // return mul(rotateZ(xyz.z), mul(rotateX(xyz.x), rotateY(xyz.y)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float4x4(
            c.y * c.z - s.x * s.y * s.z,    -c.x * s.z, c.z * s.y + c.y * s.x * s.z,    0.0f,
            c.z * s.x * s.y + c.y * s.z,    c.x * c.z,  s.y * s.z - c.y * c.z * s.x,    0.0f,
            -c.x * s.y,                     s.x,        c.x * c.y,                      0.0f,
            0.0f,                           0.0f,       0.0f,                           1.0f
            );
    }
    float4x4 float4x4::EulerYZX(const float3& xyz)
    {
        // return mul(rotateX(xyz.x), mul(rotateZ(xyz.z), rotateY(xyz.y)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float4x4(
            c.y * c.z,                      -s.z,       c.z * s.y,                      0.0f,
            s.x * s.y + c.x * c.y * s.z,    c.x * c.z,  c.x * s.y * s.z - c.y * s.x,    0.0f,
            c.y * s.x * s.z - c.x * s.y,    c.z * s.x,  c.x * c.y + s.x * s.y * s.z,    0.0f,
            0.0f,                           0.0f,       0.0f,                           1.0f
            );
    }
    float4x4 float4x4::EulerZXY(const float3& xyz)
    {
        // return mul(rotateY(xyz.y), mul(rotateX(xyz.x), rotateZ(xyz.z)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float4x4(
            c.y * c.z + s.x * s.y * s.z,    c.z * s.x * s.y - c.y * s.z,    c.x * s.y,  0.0f,
            c.x * s.z,                      c.x * c.z,                      -s.x,       0.0f,
            c.y * s.x * s.z - c.z * s.y,    c.y * c.z * s.x + s.y * s.z,    c.x * c.y,  0.0f,
            0.0f,                           0.0f,                           0.0f,       1.0f
            );
    }
    float4x4 float4x4::EulerZYX(const float3& xyz)
    {
        // return mul(rotateX(xyz.x), mul(rotateY(xyz.y), rotateZ(xyz.z)));
        float3 s, c;
        math::sincos(xyz, OUT s, OUT c);
        return float4x4(
            c.y * c.z,                      -c.y * s.z,                     s.y,        0.0f,
            c.z * s.x * s.y + c.x * s.z,    c.x * c.z - s.x * s.y * s.z,    -c.y * s.x, 0.0f,
            s.x * s.z - c.x * c.z * s.y,    c.z * s.x + c.x * s.y * s.z,    c.x * c.y,  0.0f,
            0.0f,                           0.0f,                           0.0f,       1.0f
            );
    }
    float4x4 float4x4::RotateX(float angle)
    {
        // {{1, 0, 0}, {0, c_0, -s_0}, {0, s_0, c_0}}
        float s, c;
        math::sincos(angle, OUT s, OUT c);
        return float4x4(1.0f, 0.0f, 0.0f, 0.0f,
                        0.0f, c,    -s,   0.0f,
                        0.0f, s,    c,    0.0f,
                        0.0f, 0.0f, 0.0f, 1.0f);

    }
    float4x4 float4x4::RotateY(float angle)
    {
        // {{c_1, 0, s_1}, {0, 1, 0}, {-s_1, 0, c_1}}
        float s, c;
        math::sincos(angle, OUT s, OUT c);
        return float4x4(c,    0.0f, s,    0.0f,
                        0.0f, 1.0f, 0.0f, 0.0f,
                        -s,   0.0f, c,    0.0f,
                        0.0f, 0.0f, 0.0f, 1.0f);

    }
    float4x4 float4x4::RotateZ(float angle)
    {
        // {{c_2, -s_2, 0}, {s_2, c_2, 0}, {0, 0, 1}}
        float s, c;
        math::sincos(angle, OUT s, OUT c);
        return float4x4(c,    -s,   0.0f, 0.0f,
                        s,    c,    0.0f, 0.0f,
                        0.0f, 0.0f, 1.0f, 0.0f,
                        0.0f, 0.0f, 0.0f, 1.0f);

    }
    float4x4 float4x4::LookAt(const float3& eye, const float3& target, const float3& up)
    {
        float3x3 rot = float3x3::LookRotation(math::normalize(target - eye), up);

        float4x4 matrix;
        matrix.c0 = float4(rot.c0, 0.0F);
        matrix.c1 = float4(rot.c1, 0.0F);
        matrix.c2 = float4(rot.c2, 0.0F);
        matrix.c3 = float4(eye, 1.0F);
        return matrix;
    }
    float4x4 float4x4::Ortho(float width, float height, float _near, float _far)
    {
        float rcpdx = 1.0f / width;
        float rcpdy = 1.0f / height;
        float rcpdz = 1.0f / (_far - _near);

        return float4x4(
            2.0f * rcpdx,   0.0f,            0.0f,           0.0f,
            0.0f,           2.0f * rcpdy,    0.0f,           0.0f,
            0.0f,           0.0f,           -2.0f * rcpdz,  -(_far + _near) * rcpdz,
            0.0f,           0.0f,            0.0f,           1.0f
            );
    }
    float4x4 float4x4::OrthoOffCenter(float left, float right, float bottom, float top, float _near, float _far)
    {
        float rcpdx = 1.0f / (right - left);
        float rcpdy = 1.0f / (top - bottom);
        float rcpdz = 1.0f / (_far - _near);

        return float4x4(
            2.0f * rcpdx,   0.0f,           0.0f,               -(right + left) * rcpdx,
            0.0f,           2.0f * rcpdy,   0.0f,               -(top + bottom) * rcpdy,
            0.0f,           0.0f,          -2.0f * rcpdz,       -(_far + _near) * rcpdz,
            0.0f,           0.0f,           0.0f,                1.0f
            );
    }
    float4x4 float4x4::PerspectiveFov(float verticalFov, float aspect, float _near, float _far)
    {
        float cotangent = 1.0f / tan(verticalFov * 0.5f);
        float rcpdz     = 1.0f / (_near - _far);

        return float4x4(
            cotangent / aspect, 0.0f,       0.0f,                   0.0f,
            0.0f,               cotangent,  0.0f,                   0.0f,
            0.0f,               0.0f,       (_far + _near) * rcpdz,   2.0f * _near * _far * rcpdz,
            0.0f,               0.0f,      -1.0f,                   0.0f
            );
    }
    float4x4 float4x4::PerspectiveOffCenter(float left, float right, float bottom, float top, float _near, float _far)
    {
        float rcpdz     = 1.0f / (_near - _far);
        float rcpWidth  = 1.0f / (right - left);
        float rcpHeight = 1.0f / (top - bottom);

        return float4x4(
            2.0f * _near * rcpWidth,     0.0f,                       (left + right) * rcpWidth,     0.0f,
            0.0f,                       2.0f * _near * rcpHeight,    (bottom + top) * rcpHeight,    0.0f,
            0.0f,                       0.0f,                        (_far + _near) * rcpdz,        2.0f * _near * _far * rcpdz,
            0.0f,                       0.0f,                       -1.0f,                          0.0f
            );
    }
    float4x4 float4x4::TRS(const float3& translation, const quaternion& rotation, const float3& scale)
    {
        float3x3 r = float3x3(rotation);
        return float4x4(  float4(r.c0 * scale.x, 0.0f),
                          float4(r.c1 * scale.y, 0.0f),
                          float4(r.c2 * scale.z, 0.0f),
                          float4(translation, 1.0f));
    }

    namespace math
    {
        //=========================================================
	    // math-float4
	    //=========================================================
        float select_shuffle_component(const float4& a, const float4& b, ShuffleComponent component)
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
        uint hash(const float4& v)
        {
            return csum(asuint(v) * uint4(0xE69626FFu, 0xBD010EEBu, 0x9CEDE1D1u, 0x43BE0B51u)) + 0xAF836EE1u;
        }
        uint4 hashwide(const float4& v)
        {
            return (asuint(v) * uint4(0xB130C137u, 0x54834775u, 0x7C022221u, 0xA2D00EDFu)) + 0xA8977779u;
        }
        float shuffle(const float4& left, const float4& right, ShuffleComponent x)
        {
            return select_shuffle_component(left, right, x);
        }
        float2 shuffle(const float4& left, const float4& right, ShuffleComponent x, ShuffleComponent y)
        {
            return float2(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y));
        }
        float3 shuffle(const float4& left, const float4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z)
        {
            return float3(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z));
        }
        float4 shuffle(const float4& left, const float4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w)
        {
            return float4(
                select_shuffle_component(left, right, x),
                select_shuffle_component(left, right, y),
                select_shuffle_component(left, right, z),
                select_shuffle_component(left, right, w));
        }
        //=========================================================
	    // math-float4x2
	    //=========================================================
        float2x4 transpose(const float4x2& v)
        {
            return float2x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w);
        }
        uint hash(const float4x2& v)
        {
            return math::csum(math::asuint(v.c0) * uint4(0xAAC3C25Du, 0xD21D0945u, 0x88FCAB2Du, 0x614DA60Du) +
						      math::asuint(v.c1) * uint4(0x5BA2C50Bu, 0x8C455ACBu, 0xCD266C89u, 0xF1852A33u)) + 0x77E35E77u;
        }
        uint4 hashwide(const float4x2& v)
        {
            return (math::asuint(v.c0) * uint4(0x863E3729u, 0xE191B035u, 0x68586FAFu, 0xD4DFF6D3u) +
                    math::asuint(v.c1) * uint4(0xCB634F4Du, 0x9B13B92Du, 0x4ABF0813u, 0x86068063u)) + 0xD75513F9u;
        }
        //=========================================================
        // math-float4x3
        //=========================================================
        float3x4 transpose(const float4x3& v)
        {
            return float3x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w);
        }
        uint hash(const float4x3& v)
        {
            return math::csum(math::asuint(v.c0) * uint4(0xC53F4755u, 0x6985C229u, 0xE133B0B3u, 0xC3E0A3B9u) +
                              math::asuint(v.c1) * uint4(0xFE31134Fu, 0x712A34D7u, 0x9D77A59Bu, 0x4942CA39u) +
                              math::asuint(v.c2) * uint4(0xB40EC62Du, 0x565ED63Fu, 0x93C30C2Bu, 0xDCAF0351u)) + 0x6E050B01u;
        }
        uint4 hashwide(const float4x3& v)
        {
            return (math::asuint(v.c0) * uint4(0x750FDBF5u, 0x7F3DD499u, 0x52EAAEBBu, 0x4599C793u) +
                    math::asuint(v.c1) * uint4(0x83B5E729u, 0xC267163Fu, 0x67BC9149u, 0xAD7C5EC1u) +
                    math::asuint(v.c2) * uint4(0x822A7D6Du, 0xB492BF15u, 0xD37220E3u, 0x7AA2C2BDu)) + 0xE16BC89Du;
        }
        //=========================================================
        // math-float4x4
        //=========================================================
        float3 rotate(const float4x4& a, const float3& b)
        {
            return (a.c0 * b.x + a.c1 * b.y + a.c2 * b.z).xyz();
        }
        float3 transform(const float4x4& a, const float3& b)
        {
            return (a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3).xyz();
        }
        float4x4 transpose(const float4x4& v)
        {
            return float4x4(
                v.c0.x, v.c0.y, v.c0.z, v.c0.w,
                v.c1.x, v.c1.y, v.c1.z, v.c1.w,
                v.c2.x, v.c2.y, v.c2.z, v.c2.w,
                v.c3.x, v.c3.y, v.c3.z, v.c3.w);
        }
        float4x4 inverse(const float4x4& m)
        {
            float4 c0 = m.c0;
            float4 c1 = m.c1;
            float4 c2 = m.c2;
            float4 c3 = m.c3;

            float4 r0y_r1y_r0x_r1x = movelh(c1, c0);
            float4 r0z_r1z_r0w_r1w = movelh(c2, c3);
            float4 r2y_r3y_r2x_r3x = movehl(c0, c1);
            float4 r2z_r3z_r2w_r3w = movehl(c3, c2);

            float4 r1y_r2y_r1x_r2x = shuffle(c1, c0, ShuffleComponent::LeftY, ShuffleComponent::LeftZ, ShuffleComponent::RightY, ShuffleComponent::RightZ);
            float4 r1z_r2z_r1w_r2w = shuffle(c2, c3, ShuffleComponent::LeftY, ShuffleComponent::LeftZ, ShuffleComponent::RightY, ShuffleComponent::RightZ);
            float4 r3y_r0y_r3x_r0x = shuffle(c1, c0, ShuffleComponent::LeftW, ShuffleComponent::LeftX, ShuffleComponent::RightW, ShuffleComponent::RightX);
            float4 r3z_r0z_r3w_r0w = shuffle(c2, c3, ShuffleComponent::LeftW, ShuffleComponent::LeftX, ShuffleComponent::RightW, ShuffleComponent::RightX);

            float4 r0_wzyx = shuffle(r0z_r1z_r0w_r1w, r0y_r1y_r0x_r1x, ShuffleComponent::LeftZ, ShuffleComponent::LeftX, ShuffleComponent::RightX, ShuffleComponent::RightZ);
            float4 r1_wzyx = shuffle(r0z_r1z_r0w_r1w, r0y_r1y_r0x_r1x, ShuffleComponent::LeftW, ShuffleComponent::LeftY, ShuffleComponent::RightY, ShuffleComponent::RightW);
            float4 r2_wzyx = shuffle(r2z_r3z_r2w_r3w, r2y_r3y_r2x_r3x, ShuffleComponent::LeftZ, ShuffleComponent::LeftX, ShuffleComponent::RightX, ShuffleComponent::RightZ);
            float4 r3_wzyx = shuffle(r2z_r3z_r2w_r3w, r2y_r3y_r2x_r3x, ShuffleComponent::LeftW, ShuffleComponent::LeftY, ShuffleComponent::RightY, ShuffleComponent::RightW);
            float4 r0_xyzw = shuffle(r0y_r1y_r0x_r1x, r0z_r1z_r0w_r1w, ShuffleComponent::LeftZ, ShuffleComponent::LeftX, ShuffleComponent::RightX, ShuffleComponent::RightZ);

            // Calculate remaining inner term pairs. inner terms have zw=-xy, so we only have to calculate xy and can pack two pairs per vector.
            float4 inner12_23 = r1y_r2y_r1x_r2x * r2z_r3z_r2w_r3w - r1z_r2z_r1w_r2w * r2y_r3y_r2x_r3x;
            float4 inner02_13 = r0y_r1y_r0x_r1x * r2z_r3z_r2w_r3w - r0z_r1z_r0w_r1w * r2y_r3y_r2x_r3x;
            float4 inner30_01 = r3z_r0z_r3w_r0w * r0y_r1y_r0x_r1x - r3y_r0y_r3x_r0x * r0z_r1z_r0w_r1w;

            // Expand inner terms back to 4 components. zw signs still need to be flipped
            float4 inner12 = shuffle(inner12_23, inner12_23, ShuffleComponent::LeftX, ShuffleComponent::LeftZ, ShuffleComponent::RightZ, ShuffleComponent::RightX);
            float4 inner23 = shuffle(inner12_23, inner12_23, ShuffleComponent::LeftY, ShuffleComponent::LeftW, ShuffleComponent::RightW, ShuffleComponent::RightY);

            float4 inner02 = shuffle(inner02_13, inner02_13, ShuffleComponent::LeftX, ShuffleComponent::LeftZ, ShuffleComponent::RightZ, ShuffleComponent::RightX);
            float4 inner13 = shuffle(inner02_13, inner02_13, ShuffleComponent::LeftY, ShuffleComponent::LeftW, ShuffleComponent::RightW, ShuffleComponent::RightY);

            // Calculate minors
            float4 minors0 = r3_wzyx * inner12 - r2_wzyx * inner13 + r1_wzyx * inner23;

            float4 denom = r0_xyzw * minors0;

            // Horizontal sum of denominator. Free sign flip of z and w compensates for missing flip in inner terms.
            denom = denom + shuffle(denom, denom, ShuffleComponent::LeftY, ShuffleComponent::LeftX, ShuffleComponent::RightW, ShuffleComponent::RightZ);   // x+y        x+y            z+w            z+w
            denom = denom - shuffle(denom, denom, ShuffleComponent::LeftZ, ShuffleComponent::LeftZ, ShuffleComponent::RightX, ShuffleComponent::RightX);   // x+y-z-w  x+y-z-w        z+w-x-y        z+w-x-y

            float4 rcp_denom_ppnn = float4(1.0f) / denom;
            float4x4 res;
            res.c0 = minors0 * rcp_denom_ppnn;

            float4 inner30 = shuffle(inner30_01, inner30_01, ShuffleComponent::LeftX, ShuffleComponent::LeftZ, ShuffleComponent::RightZ, ShuffleComponent::RightX);
            float4 inner01 = shuffle(inner30_01, inner30_01, ShuffleComponent::LeftY, ShuffleComponent::LeftW, ShuffleComponent::RightW, ShuffleComponent::RightY);

            float4 minors1 = r2_wzyx * inner30 - r0_wzyx * inner23 - r3_wzyx * inner02;
            res.c1 = minors1 * rcp_denom_ppnn;

            float4 minors2 = r0_wzyx * inner13 - r1_wzyx * inner30 - r3_wzyx * inner01;
            res.c2 = minors2 * rcp_denom_ppnn;

            float4 minors3 = r1_wzyx * inner02 - r0_wzyx * inner12 + r2_wzyx * inner01;
            res.c3 = minors3 * rcp_denom_ppnn;
            return res;
        }
        float4x4 fastinverse(const float4x4& m)
        {
            float4 c0 = m.c0;
            float4 c1 = m.c1;
            float4 c2 = m.c2;
            float4 pos = m.c3;

            float4 zero = float4(0);

            float4 t0 = unpacklo(c0, c2);
            float4 t1 = unpacklo(c1, zero);
            float4 t2 = unpackhi(c0, c2);
            float4 t3 = unpackhi(c1, zero);

            float4 r0 = unpacklo(t0, t1);
            float4 r1 = unpackhi(t0, t1);
            float4 r2 = unpacklo(t2, t3);

            pos = -(r0 * pos.x + r1 * pos.y + r2 * pos.z);
            pos.w = 1.0f;

            return float4x4(r0, r1, r2, pos);
        }
        float determinant(const float4x4& m)
        {
            float4 c0 = m.c0;
            float4 c1 = m.c1;
            float4 c2 = m.c2;
            float4 c3 = m.c3;

            float m00 = c1.y * (c2.z * c3.w - c2.w * c3.z) - c2.y * (c1.z * c3.w - c1.w * c3.z) + c3.y * (c1.z * c2.w - c1.w * c2.z);
            float m01 = c0.y * (c2.z * c3.w - c2.w * c3.z) - c2.y * (c0.z * c3.w - c0.w * c3.z) + c3.y * (c0.z * c2.w - c0.w * c2.z);
            float m02 = c0.y * (c1.z * c3.w - c1.w * c3.z) - c1.y * (c0.z * c3.w - c0.w * c3.z) + c3.y * (c0.z * c1.w - c0.w * c1.z);
            float m03 = c0.y * (c1.z * c2.w - c1.w * c2.z) - c1.y * (c0.z * c2.w - c0.w * c2.z) + c2.y * (c0.z * c1.w - c0.w * c1.z);

            return c0.x * m00 - c1.x * m01 + c2.x * m02 - c3.x * m03;
        }
        uint hash(const float4x4& v)
        {
            return math::csum(math::asuint(v.c0) * uint4(0xC4B1493Fu, 0xBA0966D3u, 0xAFBEE253u, 0x5B419C01u) +
                              math::asuint(v.c1) * uint4(0x515D90F5u, 0xEC9F68F3u, 0xF9EA92D5u, 0xC2FAFCB9u) +
                              math::asuint(v.c2) * uint4(0x616E9CA1u, 0xC5C5394Bu, 0xCAE78587u, 0x7A1541C9u) +
                              math::asuint(v.c3) * uint4(0xF83BD927u, 0x6A243BCBu, 0x509B84C9u, 0x91D13847u)) + 0x52F7230Fu;
        }
        uint4 hashwide(const float4x4& v)
        {
            return (math::asuint(v.c0) * uint4(0xCF286E83u, 0xE121E6ADu, 0xC9CA1249u, 0x69B60C81u) +
                    math::asuint(v.c1) * uint4(0xE0EB6C25u, 0xF648BEABu, 0x6BDB2B07u, 0xEF63C699u) +
                    math::asuint(v.c2) * uint4(0x9001903Fu, 0xA895B9CDu, 0x9D23B201u, 0x4B01D3E1u) +
                    math::asuint(v.c3) * uint4(0x7461CA0Du, 0x79725379u, 0xD6258E5Bu, 0xEE390C97u)) + 0x9C8A2F05u;
        }
    }

} // namespace ecs