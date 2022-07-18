#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/int4.gen.cs
#pragma pack(push,1)
	struct int4
	{
	public:
		static const  int4	zero;
        union {
            struct { int x, y, z, w; };
            int        data[4];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        int4() : x(0), y(0), z(0), w(0)                                     {}
        int4(int _x, int _y, int _z, int _w) : x(_x), y(_y), z(_z), w(_w)   {}

        
        int4(int _x, int _y, const int2& _zw)   {   x = _x;     y = _y;     z = _zw.x;  w = _zw.y;      }
        int4(int _x, const int2& _yz, int _w)   {   x = _x;     y = _yz.x;  z = _yz.y;  w = _w;         }
        int4(int _x, const int3& _yzw)          {   x = _x;     y = _yzw.x; z = _yzw.y; w = _yzw.z;     }
        int4(const int2& _xy, int _z, int _w)   {   x = _xy.x;  y = _xy.y;  z = _z;     w = _w;         }
        int4(const int2& _xy, const int2& _zw)  {   x = _xy.x;  y = _xy.y;  z = _zw.x;  w = _zw.y;      }
        int4(const int3& _xyz, int _w)          {   x = _xyz.x; y = _xyz.y; z = _xyz.z; w = _w;         }

        int4(bool v)                            {   x = v ? 1 : 0;  y = v ? 1 : 0;  z = v ? 1 : 0;  w = v ? 1 : 0;  }
        int4(uint v)                            {   x = (int)v;     y = (int)v;     z = (int)v;     w = (int)v;     }
        int4(int v)                             {   x = v;          y = v;          z = v;          w = v;          }
        int4(float v)                           {   x = (int)v;     y = (int)v;     z = (int)v;     w = (int)v;     }
        int4(double v)                          {   x = (int)v;     y = (int)v;     z = (int)v;     w = (int)v;     }

        int4(const bool4& v);
        int4(const uint4& v);
        int4(const int4& v);
        int4(const float4& v);
        int4(const double4& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        int4& operator = (const int4& rhs) { this->x = rhs.x;  this->y = rhs.y;  this->z = rhs.z;  this->w = rhs.w;  return (*this); }
		// addition assignment	            a += b	
        int4& operator +=(const int4& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; this->w += rhs.w; return (*this); }
		// subtraction assignment	        a -= b	
        int4& operator -=(const int4& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; this->w -= rhs.w; return (*this); }
		// multiplication assignment	    a *= b	
        int4& operator *=(const int4& rhs) { this->x *= rhs.x; this->y *= rhs.y; this->z *= rhs.z; this->w *= rhs.w; return (*this); }
		// division assignment	            a /= b	
        int4& operator /=(const int4& rhs) { this->x /= rhs.x; this->y /= rhs.y; this->z /= rhs.z; this->w /= rhs.w; return (*this); }
		// modulo assignment	            a %= b	
        int4& operator %=(const int4& rhs) { this->x %= rhs.x; this->y %= rhs.y; this->z %= rhs.z; this->w %= rhs.w; return (*this); }
		
        // bitwise AND assignment	        a &= b	
        int4& operator &=(const int4& rhs) { this->x &= rhs.x; this->y &= rhs.y; this->z &= rhs.z; this->w &= rhs.w; return (*this); }
		// bitwise OR assignment	        a |= b	
        int4& operator |=(const int4& rhs) { this->x |= rhs.x; this->y |= rhs.y; this->z |= rhs.z; this->w |= rhs.w; return (*this); }
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
        int4& operator ++ ()                        { ++this->x; ++this->y; ++this->z; ++this->w; return (*this);     }
        // pre - decrement  : 	--a		T&
        int4& operator -- ()                        { --this->x; --this->y; --this->z; --this->w; return (*this);     }
        // post-increment   : 	a++
        int4  operator ++ (int)                     { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        int4  operator -- (int)                     { auto temp = *this; --(*this); return (temp); }

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
        int4 operator + () const                    { return int4(+this->x, +this->y, +this->z, +this->w); }

        // unary minus      :   -a
        int4 operator - () const                    { return int4(-this->x, -this->y, -this->z, -this->w); }

		// addition         :   a + b
        int4 operator + (const int4& rhs)   const   { return int4(this->x + rhs.x,  this->y + rhs.y,    this->z + rhs.z,    this->w + rhs.w); }
        int4 operator + (int rhs)           const   { return int4(this->x + rhs,    this->y + rhs,      this->z + rhs,      this->w + rhs); }
        friend int4  operator + (int lhs, const int4& rhs) { return int4(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w); }

		// subtraction      :   a - b
        int4 operator - (const int4& rhs)   const   { return int4(this->x - rhs.x,  this->y - rhs.y,    this->z - rhs.z,    this->w - rhs.w); }
        int4 operator - (int rhs)           const   { return int4(this->x - rhs,    this->y - rhs,      this->z - rhs,      this->w - rhs); }
        friend int4  operator - (int lhs, const int4& rhs) { return int4(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w); }

		// multiplication   :   a * b
        int4 operator * (const int4& rhs)   const   { return int4(this->x * rhs.x,  this->y * rhs.y,    this->z * rhs.z,    this->w * rhs.w); }
        int4 operator * (int rhs)           const   { return int4(this->x * rhs,    this->y * rhs,      this->z * rhs,      this->w * rhs); }
        friend int4  operator * (int lhs, const int4& rhs) { return int4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w); }

		// division         :   a / b
        int4 operator / (const int4& rhs)   const   { return int4(this->x / rhs.x,  this->y / rhs.y,    this->z / rhs.z,    this->w / rhs.w); }
        int4 operator / (int rhs)           const   { return int4(this->x / rhs,    this->y / rhs,      this->z / rhs,      this->w / rhs); }
        friend int4  operator / (int lhs, const int4& rhs) { return int4(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w); }

		// modulo           :   a % b
        int4 operator % (const int4& rhs)   const   { return int4(this->x % rhs.x,  this->y % rhs.y,    this->z % rhs.z,    this->w % rhs.w); }
        int4 operator % (int rhs)           const   { return int4(this->x % rhs,    this->y % rhs,      this->z % rhs,      this->w % rhs); }
        friend int4  operator % (int lhs, const int4& rhs) { return int4(lhs % rhs.x, lhs % rhs.y, lhs % rhs.z, lhs % rhs.w); }

		// bitwise NOT      :   ~a
        int4 operator ~ ()                  const   { return int4(~this->x, ~this->y, ~this->z, ~this->w); }

		// bitwise AND      :   a & b
        int4 operator & (const int4& rhs)   const   { return int4(this->x & rhs.x,  this->y & rhs.y,    this->z & rhs.z,    this->w & rhs.w); }
        int4 operator & (int rhs)           const   { return int4(this->x & rhs,    this->y & rhs,      this->z & rhs,      this->w & rhs); }
        friend int4  operator & (int lhs, const int4& rhs) { return int4(lhs & rhs.x, lhs & rhs.y, lhs & rhs.z, lhs & rhs.w); }

		// bitwise OR       :   a | b
        int4 operator | (const int4& rhs)   const   { return int4(this->x | rhs.x,  this->y | rhs.y,    this->z | rhs.z,    this->w | rhs.w); }
        int4 operator | (int rhs)           const   { return int4(this->x | rhs,    this->y | rhs,      this->z | rhs,      this->w | rhs); }
        friend int4  operator | (int lhs, const int4& rhs) { return int4(lhs | rhs.x, lhs | rhs.y, lhs | rhs.z, lhs | rhs.w); }

        // bitwise XOR      :   a ^ b
        int4 operator ^ (const int4& rhs)   const   { return int4(this->x ^ rhs.x,  this->y ^ rhs.y,    this->z ^ rhs.z,    this->w ^ rhs.w); }
        int4 operator ^ (int rhs)           const   { return int4(this->x ^ rhs,    this->y ^ rhs,      this->z ^ rhs,      this->w ^ rhs); }
        friend int4  operator ^ (int lhs, const int4& rhs) { return int4(lhs ^ rhs.x, lhs ^ rhs.y, lhs ^ rhs.z, lhs ^ rhs.w); }

        // bitwise left shift : a << b
        int4 operator << (int n) const              { return int4(this->x << n, this->y << n, this->z << n, this->w << n); }

        // bitwise right shift: a >> b
        int4 operator >> (int n) const              { return int4(this->x >> n, this->y >> n, this->z >> n, this->w >> n); }

		//=========================================================
		// Logical operators
		//=========================================================
		// negation	        :   not a, !a
		// AND	            :   a and b, a && b
		// inclusive OR	    :   a or b,  a || b

		//=========================================================
		// Comparison operators
		//=========================================================
		// equal to         :   a == 
        bool4 operator == (const int4& rhs) const   { return bool4(this->x == rhs.x,this->y == rhs.y,   this->z == rhs.z,   this->w == rhs.w); }
        bool4 operator == (int rhs)         const   { return bool4(this->x == rhs,  this->y == rhs,     this->z == rhs,     this->w == rhs); }
        friend bool4 operator ==(int lhs, const int4& rhs) { return bool4(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z, lhs == rhs.w); }

		// not equal to     :   a != b
        bool4 operator != (const int4& rhs) const   { return bool4(this->x != rhs.x,this->y != rhs.y,   this->z != rhs.z,   this->w != rhs.w); }
        bool4 operator != (int rhs)         const   { return bool4(this->x != rhs,  this->y != rhs,     this->z != rhs,     this->w != rhs); }
        friend bool4 operator !=(int lhs, const int4& rhs) { return bool4(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z, lhs != rhs.w); }

		// less than        :   a < b
        bool4 operator < (const int4& rhs)  const   { return bool4(this->x < rhs.x, this->y < rhs.y,    this->z < rhs.z,    this->w < rhs.w); }
        bool4 operator < (int rhs)          const   { return bool4(this->x < rhs,   this->y < rhs,      this->z < rhs,      this->w < rhs); }
        friend bool4 operator < (int lhs, const int4& rhs) { return bool4(lhs < rhs.x, lhs < rhs.y, lhs < rhs.z, lhs < rhs.w); }

		// greater than     :   a > b
        bool4 operator > (const int4& rhs)  const   { return bool4(this->x > rhs.x, this->y > rhs.y,    this->z > rhs.z,    this->w > rhs.w); }
        bool4 operator > (int rhs)          const   { return bool4(this->x > rhs,   this->y > rhs,      this->z > rhs,      this->w > rhs); }
        friend bool4 operator > (int lhs, const int4& rhs) { return bool4(lhs > rhs.x, lhs > rhs.y, lhs > rhs.z, lhs > rhs.w); }

		// less than or equal to    : a <= b	
        bool4 operator <= (const int4& rhs) const   { return bool4(this->x <= rhs.x,this->y <= rhs.y,   this->z <= rhs.z,   this->w <= rhs.w); }
        bool4 operator <= (int rhs)         const   { return bool4(this->x <= rhs,  this->y <= rhs,     this->z <= rhs,     this->w <= rhs); }
        friend bool4 operator <=(int lhs, const int4& rhs) { return bool4(lhs <= rhs.x, lhs <= rhs.y, lhs <= rhs.z, lhs <= rhs.w); }

		// greater than or equal to : a >= b
        bool4 operator >= (const int4& rhs) const   { return bool4(this->x >= rhs.x,this->y >= rhs.y,   this->z >= rhs.z,   this->w >= rhs.w); }
        bool4 operator >= (int rhs)         const   { return bool4(this->x >= rhs,  this->y >= rhs,     this->z >= rhs,     this->w >= rhs); }
        friend bool4 operator >=(int lhs, const int4& rhs) { return bool4(lhs >= rhs.x, lhs >= rhs.y, lhs >= rhs.z, lhs >= rhs.w); }

        //=========================================================
        // Conversion operators
        //=========================================================


		//=========================================================
		// member access
		//=========================================================
		/// <summary>Returns the int element at a specified index.</summary>
		int& operator[] (int index)
		{
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
			if (index >= 4)
				throw std::exception("index must be between[0...3]");
#endif
			return data[index];
		}

        //=========================================================
        // Getter/Setter
        //=========================================================
        /// <summary>Swizzles the vector.</summary>
        int4 xxxx() const;
        int4 xxxy() const;
        int4 xxxz() const;
        int4 xxxw() const;
        int4 xxyx() const;
        int4 xxyy() const;
        int4 xxyz() const;
        int4 xxyw() const;
        int4 xxzx() const;
        int4 xxzy() const;
        int4 xxzz() const;
        int4 xxzw() const;
        int4 xxwx() const;
        int4 xxwy() const;
        int4 xxwz() const;
        int4 xxww() const;
        int4 xyxx() const;
        int4 xyxy() const;
        int4 xyxz() const;
        int4 xyxw() const;
        int4 xyyx() const;
        int4 xyyy() const;
        int4 xyyz() const;
        int4 xyyw() const;
        int4 xyzx() const;
        int4 xyzy() const;
        int4 xyzz() const;
        int4 xyzw() const;
        void xyzw(const int4& v);
        int4 xywx() const;
        int4 xywy() const;
        int4 xywz() const;
        void xywz(const int4& v);
        int4 xyww() const;
        int4 xzxx() const;
        int4 xzxy() const;
        int4 xzxz() const;
        int4 xzxw() const;
        int4 xzyx() const;
        int4 xzyy() const;
        int4 xzyz() const;
        int4 xzyw() const;
        void xzyw(const int4& v);
        int4 xzzx() const;
        int4 xzzy() const;
        int4 xzzz() const;
        int4 xzzw() const;
        int4 xzwx() const;
        int4 xzwy() const;
        void xzwy(const int4& v);
        int4 xzwz() const;
        int4 xzww() const;
        int4 xwxx() const;
        int4 xwxy() const;
        int4 xwxz() const;
        int4 xwxw() const;
        int4 xwyx() const;
        int4 xwyy() const;
        int4 xwyz() const;
        void xwyz(const int4& v);
        int4 xwyw() const;
        int4 xwzx() const;
        int4 xwzy() const;
        void xwzy(const int4& v);
        int4 xwzz() const;
        int4 xwzw() const;
        int4 xwwx() const;
        int4 xwwy() const;
        int4 xwwz() const;
        int4 xwww() const;
        int4 yxxx() const;
        int4 yxxy() const;
        int4 yxxz() const;
        int4 yxxw() const;
        int4 yxyx() const;
        int4 yxyy() const;
        int4 yxyz() const;
        int4 yxyw() const;
        int4 yxzx() const;
        int4 yxzy() const;
        int4 yxzz() const;
        int4 yxzw() const;
        void yxzw(const int4& v);
        int4 yxwx() const;
        int4 yxwy() const;
        int4 yxwz() const;
        void yxwz(const int4& v);
        int4 yxww() const;
        int4 yyxx() const;
        int4 yyxy() const;
        int4 yyxz() const;
        int4 yyxw() const;
        int4 yyyx() const;
        int4 yyyy() const;
        int4 yyyz() const;
        int4 yyyw() const;
        int4 yyzx() const;
        int4 yyzy() const;
        int4 yyzz() const;
        int4 yyzw() const;
        int4 yywx() const;
        int4 yywy() const;
        int4 yywz() const;
        int4 yyww() const;
        int4 yzxx() const;
        int4 yzxy() const;
        int4 yzxz() const;
        int4 yzxw() const;
        void yzxw(const int4& v);
        int4 yzyx() const;
        int4 yzyy() const;
        int4 yzyz() const;
        int4 yzyw() const;
        int4 yzzx() const;
        int4 yzzy() const;
        int4 yzzz() const;
        int4 yzzw() const;
        int4 yzwx() const;
        void yzwx(const int4& v);
        int4 yzwy() const;
        int4 yzwz() const;
        int4 yzww() const;
        int4 ywxx() const;
        int4 ywxy() const;
        int4 ywxz() const;
        void ywxz(const int4& v);
        int4 ywxw() const;
        int4 ywyx() const;
        int4 ywyy() const;
        int4 ywyz() const;
        int4 ywyw() const;
        int4 ywzx() const;
        void ywzx(const int4& v);
        int4 ywzy() const;
        int4 ywzz() const;
        int4 ywzw() const;
        int4 ywwx() const;
        int4 ywwy() const;
        int4 ywwz() const;
        int4 ywww() const;
        int4 zxxx() const;
        int4 zxxy() const;
        int4 zxxz() const;
        int4 zxxw() const;
        int4 zxyx() const;
        int4 zxyy() const;
        int4 zxyz() const;
        int4 zxyw() const;
        void zxyw(const int4& v);
        int4 zxzx() const;
        int4 zxzy() const;
        int4 zxzz() const;
        int4 zxzw() const;
        int4 zxwx() const;
        int4 zxwy() const;
        void zxwy(const int4& v);
        int4 zxwz() const;
        int4 zxww() const;
        int4 zyxx() const;
        int4 zyxy() const;
        int4 zyxz() const;
        int4 zyxw() const;
        void zyxw(const int4& v);
        int4 zyyx() const;
        int4 zyyy() const;
        int4 zyyz() const;
        int4 zyyw() const;
        int4 zyzx() const;
        int4 zyzy() const;
        int4 zyzz() const;
        int4 zyzw() const;
        int4 zywx() const;
        void zywx(const int4& v);
        int4 zywy() const;
        int4 zywz() const;
        int4 zyww() const;
        int4 zzxx() const;
        int4 zzxy() const;
        int4 zzxz() const;
        int4 zzxw() const;
        int4 zzyx() const;
        int4 zzyy() const;
        int4 zzyz() const;
        int4 zzyw() const;
        int4 zzzx() const;
        int4 zzzy() const;
        int4 zzzz() const;
        int4 zzzw() const;
        int4 zzwx() const;
        int4 zzwy() const;
        int4 zzwz() const;
        int4 zzww() const;
        int4 zwxx() const;
        int4 zwxy() const;
        void zwxy(const int4& v);
        int4 zwxz() const;
        int4 zwxw() const;
        int4 zwyx() const;
        void zwyx(const int4& v);
        int4 zwyy() const;
        int4 zwyz() const;
        int4 zwyw() const;
        int4 zwzx() const;
        int4 zwzy() const;
        int4 zwzz() const;
        int4 zwzw() const;
        int4 zwwx() const;
        int4 zwwy() const;
        int4 zwwz() const;
        int4 zwww() const;
        int4 wxxx() const;
        int4 wxxy() const;
        int4 wxxz() const;
        int4 wxxw() const;
        int4 wxyx() const;
        int4 wxyy() const;
        int4 wxyz() const;
        void wxyz(const int4& v);
        int4 wxyw() const;
        int4 wxzx() const;
        int4 wxzy() const;
        void wxzy(const int4& v);
        int4 wxzz() const;
        int4 wxzw() const;
        int4 wxwx() const;
        int4 wxwy() const;
        int4 wxwz() const;
        int4 wxww() const;
        int4 wyxx() const;
        int4 wyxy() const;
        int4 wyxz() const;
        void wyxz(const int4& v);
        int4 wyxw() const;
        int4 wyyx() const;
        int4 wyyy() const;
        int4 wyyz() const;
        int4 wyyw() const;
        int4 wyzx() const;
        void wyzx(const int4& v);
        int4 wyzy() const;
        int4 wyzz() const;
        int4 wyzw() const;
        int4 wywx() const;
        int4 wywy() const;
        int4 wywz() const;
        int4 wyww() const;
        int4 wzxx() const;
        int4 wzxy() const;
        void wzxy(const int4& v);
        int4 wzxz() const;
        int4 wzxw() const;
        int4 wzyx() const;
        void wzyx(const int4& v);
        int4 wzyy() const;
        int4 wzyz() const;
        int4 wzyw() const;
        int4 wzzx() const;
        int4 wzzy() const;
        int4 wzzz() const;
        int4 wzzw() const;
        int4 wzwx() const;
        int4 wzwy() const;
        int4 wzwz() const;
        int4 wzww() const;
        int4 wwxx() const;
        int4 wwxy() const;
        int4 wwxz() const;
        int4 wwxw() const;
        int4 wwyx() const;
        int4 wwyy() const;
        int4 wwyz() const;
        int4 wwyw() const;
        int4 wwzx() const;
        int4 wwzy() const;
        int4 wwzz() const;
        int4 wwzw() const;
        int4 wwwx() const;
        int4 wwwy() const;
        int4 wwwz() const;
        int4 wwww() const;
        int3 xxx()  const;
        int3 xxy()  const;
        int3 xxz()  const;
        int3 xxw()  const;
        int3 xyx()  const;
        int3 xyy()  const;
        int3 xyz()  const;
        void xyz(const int3& v);
        int3 xyw()  const;
        void xyw(const int3& v);
        int3 xzx()  const;
        int3 xzy()  const;
        void xzy(const int3& v);
        int3 xzz()  const;
        int3 xzw()  const;
        void xzw(const int3& v);
        int3 xwx()  const;
        int3 xwy()  const;
        void xwy(const int3& v);
        int3 xwz()  const;
        void xwz(const int3& v);
        int3 xww()  const;
        int3 yxx()  const;
        int3 yxy()  const;
        int3 yxz()  const;
        void yxz(const int3& v);
        int3 yxw()  const;
        void yxw(const int3& v);
        int3 yyx()  const;
        int3 yyy()  const;
        int3 yyz()  const;
        int3 yyw()  const;
        int3 yzx()  const;
        void yzx(const int3& v);
        int3 yzy()  const;
        int3 yzz()  const;
        int3 yzw()  const;
        void yzw(const int3& v);
        int3 ywx()  const;
        void ywx(const int3& v);
        int3 ywy()  const;
        int3 ywz()  const;
        void ywz(const int3& v);
        int3 yww()  const;
        int3 zxx()  const;
        int3 zxy()  const;
        void zxy(const int3& v);
        int3 zxz()  const;
        int3 zxw()  const;
        void zxw(const int3& v);
        int3 zyx()  const;
        void zyx(const int3& v);
        int3 zyy()  const;
        int3 zyz()  const;
        int3 zyw()  const;
        void zyw(const int3& v);
        int3 zzx()  const;
        int3 zzy()  const;
        int3 zzz()  const;
        int3 zzw()  const;
        int3 zwx()  const;
        void zwx(const int3& v);
        int3 zwy()  const;
        void zwy(const int3& v);
        int3 zwz()  const;
        int3 zww()  const;
        int3 wxx()  const;
        int3 wxy()  const;
        void wxy(const int3& v);
        int3 wxz()  const;
        void wxz(const int3& v);
        int3 wxw()  const;
        int3 wyx()  const;
        void wyx(const int3& v);
        int3 wyy()  const;
        int3 wyz()  const;
        void wyz(const int3& v);
        int3 wyw()  const;
        int3 wzx()  const;
        void wzx(const int3& v);
        int3 wzy()  const;
        void wzy(const int3& v);
        int3 wzz()  const;
        int3 wzw()  const;
        int3 wwx()  const;
        int3 wwy()  const;
        int3 wwz()  const;
        int3 www()  const;
        int2 xx()   const;
        int2 xy()   const;
        void xy(const int2& v);
        int2 xz()   const;
        void xz(const int2& v);
        int2 xw()   const;
        void xw(const int2& v);
        int2 yx()   const;
        void yx(const int2& v);
        int2 yy()   const;
        int2 yz()   const;
        void yz(const int2& v);
        int2 yw()   const;
        void yw(const int2& v);
        int2 zx()   const;
        void zx(const int2& v);
        int2 zy()   const;
        void zy(const int2& v);
        int2 zz()   const;
        int2 zw()   const;
        void zw(const int2& v);
        int2 wx()   const;
        void wx(const int2& v);
        int2 wy()   const;
        void wy(const int2& v);
        int2 wz()   const;
        void wz(const int2& v);
        int2 ww()   const;

        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the int4 is equal to a given int4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const int4& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

        /// <summary>Returns true if the int4 is equal to a given int4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is int4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the int4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the int4.</summary>
        /// <returns>String representation of the v.</returns>
        std::string ToString()
        {
            return std::format("int4({0}, {1}, {2}, {3})", x, y, z, w);
        }
	};
    __declspec(selectany) const int4    int4::zero = int4(0, 0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-int4
        //=========================================================
        /// <summary>Returns a uint hash code of a int4 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const int4& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a int4 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const int4& v);

        /// <summary>Returns the result of specified shuffling of the components from two int4 vectors into an int value.</summary>
        /// <param name="left">int4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int.</param>
        /// <returns>int result of the shuffle operation.</returns>
        int shuffle(const int4& left, const int4& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two int4 vectors into an int2 vector.</summary>
        /// <param name="left">int4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int2 y component.</param>
        /// <returns>int2 result of the shuffle operation.</returns>
        int2 shuffle(const int4& left, const int4& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two int4 vectors into an int3 vector.</summary>
        /// <param name="left">int4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting int3 z component.</param>
        /// <returns>int3 result of the shuffle operation.</returns>
        int3 shuffle(const int4& left, const int4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two int4 vectors into an int4 vector.</summary>
        /// <param name="left">int4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting int4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting int4 w component.</param>
        /// <returns>int4 result of the shuffle operation.</returns>
        int4 shuffle(const int4& left, const int4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

