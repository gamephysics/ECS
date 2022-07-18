#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/uint4.gen.cs
#pragma pack(push,1)
	struct uint4
	{
	public:
		static const  uint4	zero;
        union {
            struct { uint x, y, z, w; };
            uint        data[4];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        uint4() : x(0), y(0), z(0), w(0)                                        {}
		uint4(uint _x, uint _y, uint _z, uint _w) : x(_x), y(_y), z(_z), w(_w)  {}

        uint4(uint _x, uint _y, const uint2& _zw)   {   x = _x;         y = _y;         z = _zw.x;      w = _zw.y;      }
        uint4(uint _x, const uint2& _yz, uint _w)   {   x = _x;         y = _yz.x;      z = _yz.y;      w = _w;         }
        uint4(uint _x, const uint3& _yzw)           {   x = _x;         y = _yzw.x;     z = _yzw.y;     w = _yzw.z;     }
        uint4(const uint2& _xy, uint _z, uint _w)   {   x = _xy.x;      y = _xy.y;      z = _z;         w = _w;         }
        uint4(const uint2& _xy, const uint2& _zw)   {   x = _xy.x;      y = _xy.y;      z = _zw.x;      w = _zw.y;      }
        uint4(const uint3& _xyz, uint _w)           {   x = _xyz.x;     y = _xyz.y;     z = _xyz.z;     w = _w;         }

        uint4(bool v)                               {   x = v ? 1u : 0u;    y = v ? 1u : 0u;    z = v ? 1u : 0u;    w = v ? 1u : 0u;    }
        uint4(uint v)                               {   x = v;          y = v;          z = v;          w = v;          }
        uint4(int v)                                {   x = (uint)v;    y = (uint)v;    z = (uint)v;    w = (uint)v;    }
        uint4(float v)                              {   x = (uint)v;    y = (uint)v;    z = (uint)v;    w = (uint)v;    }
        uint4(double v)                             {   x = (uint)v;    y = (uint)v;    z = (uint)v;    w = (uint)v;    }
        
        uint4(const bool4& v);
        uint4(const uint4& v);
        uint4(const int4& v);
        uint4(const float4& v);
        uint4(const double4& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        uint4& operator = (const uint4& rhs) { this->x = rhs.x;  this->y = rhs.y;  this->z = rhs.z;  this->w = rhs.w;  return (*this); }
		// addition assignment	            a += b	
        uint4& operator +=(const uint4& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; this->w += rhs.w; return (*this); }
		// subtraction assignment	        a -= b	
        uint4& operator -=(const uint4& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; this->w -= rhs.w; return (*this); }
		// multiplication assignment	    a *= b	
        uint4& operator *=(const uint4& rhs) { this->x *= rhs.x; this->y *= rhs.y; this->z *= rhs.z; this->w *= rhs.w; return (*this); }
		// division assignment	            a /= b	
        uint4& operator /=(const uint4& rhs) { this->x /= rhs.x; this->y /= rhs.y; this->z /= rhs.z; this->w /= rhs.w; return (*this); }
		// modulo assignment	            a %= b	
        uint4& operator %=(const uint4& rhs) { this->x %= rhs.x; this->y %= rhs.y; this->z %= rhs.z; this->w %= rhs.w; return (*this); }
		
        // bitwise AND assignment	        a &= b	
        uint4& operator &=(const uint4& rhs) { this->x &= rhs.x; this->y &= rhs.y; this->z &= rhs.z; this->w &= rhs.w; return (*this); }
		// bitwise OR assignment	        a |= b	
        uint4& operator |=(const uint4& rhs) { this->x |= rhs.x; this->y |= rhs.y; this->z |= rhs.z; this->w |= rhs.w; return (*this); }
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
        uint4& operator ++ ()                       { ++this->x; ++this->y; ++this->z; ++this->w; return (*this);     }
        // pre - decrement  : 	--a		T&
        uint4& operator -- ()                       { --this->x; --this->y; --this->z; --this->w; return (*this);     }
        // post-increment   : 	a++
        uint4  operator ++ (int)                    { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        uint4  operator -- (int)                    { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
        uint4 operator + () const                   { return uint4(+this->x, +this->y, +this->z, +this->w); }

		// unary minus      :   -a
        uint4 operator - () const                   { throw std::runtime_error("unsigned cannot convert minus value"); }//{ return uint3(-this->x, -this->y, -this->z); }

		// addition         :   a + b
        uint4 operator + (const uint4& rhs) const   { return uint4(this->x + rhs.x,     this->y + rhs.y,    this->z + rhs.z,    this->w + rhs.w); }
        uint4 operator + (uint rhs)         const   { return uint4(this->x + rhs,       this->y + rhs,      this->z + rhs,      this->w + rhs); }
        friend uint4 operator + (uint lhs, const uint4& rhs) { return uint4(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w); }

		// subtraction      :   a - b
        uint4 operator - (const uint4& rhs) const   { return uint4(this->x - rhs.x,     this->y - rhs.y,    this->z - rhs.z,    this->w - rhs.w); }
        uint4 operator - (uint rhs)         const   { return uint4(this->x - rhs,       this->y - rhs,      this->z - rhs,      this->w - rhs); }

        friend uint4 operator - (uint lhs, const uint4& rhs) { return uint4(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w); }

		// multiplication   :   a * b
        uint4 operator * (const uint4& rhs) const   { return uint4(this->x * rhs.x,     this->y * rhs.y,    this->z * rhs.z,    this->w * rhs.w); }
        uint4 operator * (uint rhs)         const   { return uint4(this->x * rhs,       this->y * rhs,      this->z * rhs,      this->w * rhs); }
        friend uint4 operator * (uint lhs, const uint4& rhs) { return uint4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w); }

		// division         :   a / b
        uint4 operator / (const uint4& rhs) const   { return uint4(this->x / rhs.x,     this->y / rhs.y,    this->z / rhs.z,    this->w / rhs.w); }
        uint4 operator / (uint rhs)         const   { return uint4(this->x / rhs,       this->y / rhs,      this->z / rhs,      this->w / rhs); }
        friend uint4 operator / (uint lhs, const uint4& rhs) { return uint4(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w); }

		// modulo           :   a % b
        uint4 operator % (const uint4& rhs) const   { return uint4(this->x % rhs.x,     this->y % rhs.y,    this->z % rhs.z,    this->w % rhs.w); }
        uint4 operator % (uint rhs)         const   { return uint4(this->x % rhs,       this->y % rhs,      this->z % rhs,      this->w % rhs); }
        friend uint4 operator % (uint lhs, const uint4& rhs) { return uint4(lhs % rhs.x, lhs % rhs.y, lhs % rhs.z, lhs % rhs.w); }

		// bitwise NOT      :   ~a
        uint4 operator ~ ()    const                { return uint4(~this->x, ~this->y, ~this->z, ~this->w); }

		// bitwise AND      :   a & b
        uint4 operator & (const uint4& rhs) const   { return uint4(this->x & rhs.x,     this->y & rhs.y,    this->z & rhs.z,    this->w & rhs.w); }
        uint4 operator & (uint rhs)         const   { return uint4(this->x & rhs,       this->y & rhs,      this->z & rhs,      this->w & rhs); }
        friend uint4 operator & (uint lhs, const uint4& rhs) { return uint4(lhs & rhs.x, lhs & rhs.y, lhs & rhs.z, lhs & rhs.w); }

        // bitwise OR       :   a | b
        uint4 operator | (const uint4& rhs) const   { return uint4(this->x | rhs.x,     this->y | rhs.y,    this->z | rhs.z,    this->w | rhs.w); }
        uint4 operator | (uint rhs)         const   { return uint4(this->x | rhs,       this->y | rhs,      this->z | rhs,      this->w | rhs); }
        friend uint4 operator | (uint lhs, const uint4& rhs) { return uint4(lhs | rhs.x, lhs | rhs.y, lhs | rhs.z, lhs | rhs.w); }

        // bitwise XOR      :   a ^ b
        uint4 operator ^ (const uint4& rhs) const   { return uint4(this->x ^ rhs.x,     this->y ^ rhs.y,    this->z ^ rhs.z,    this->w ^ rhs.w); }
        uint4 operator ^ (uint rhs)         const   { return uint4(this->x ^ rhs,       this->y ^ rhs,      this->z ^ rhs,      this->w ^ rhs); }
        friend uint4 operator ^ (uint lhs, const uint4& rhs) { return uint4(lhs ^ rhs.x, lhs ^ rhs.y, lhs ^ rhs.z, lhs ^ rhs.w); }
		
		// bitwise left shift : a << b
        uint4 operator << (int n) const { return uint4(this->x << n, this->y << n, this->z << n, this->w << n); }

		// bitwise right shift: a >> b
        uint4 operator >> (int n) const { return uint4(this->x >> n, this->y >> n, this->z >> n, this->w >> n); }

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
        bool4 operator == (const uint4& rhs)const   { return bool4(this->x == rhs.x,    this->y == rhs.y,   this->z == rhs.z,   this->w == rhs.w); }
        bool4 operator == (uint rhs)        const   { return bool4(this->x == rhs,      this->y == rhs,     this->z == rhs,     this->w == rhs); }
        friend bool4 operator ==(uint lhs, const uint4& rhs) { return bool4(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z, lhs == rhs.w); }

        // not equal to     :   a != b
        bool4 operator != (const uint4& rhs)const   { return bool4(this->x != rhs.x,    this->y != rhs.y,   this->z != rhs.z,   this->w != rhs.w); }
        bool4 operator != (uint rhs)        const   { return bool4(this->x != rhs,      this->y != rhs,     this->z != rhs,     this->w != rhs); }
        friend bool4 operator !=(uint lhs, const uint4& rhs) { return bool4(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z, lhs != rhs.w); }

		// less than        :   a < b
        bool4 operator < (const uint4& rhs) const   { return bool4(this->x < rhs.x,     this->y < rhs.y,    this->z < rhs.z,    this->w < rhs.w); }
        bool4 operator < (uint rhs)         const   { return bool4(this->x < rhs,       this->y < rhs,      this->z < rhs,      this->w < rhs); }
        friend bool4 operator < (uint lhs, const uint4& rhs) { return bool4(lhs < rhs.x, lhs < rhs.y, lhs < rhs.z, lhs < rhs.w); }

		// greater than     :   a > b
        bool4 operator > (const uint4& rhs) const   { return bool4(this->x > rhs.x,     this->y > rhs.y,    this->z > rhs.z,    this->w > rhs.w); }
        bool4 operator > (uint rhs)         const   { return bool4(this->x > rhs,       this->y > rhs,      this->z > rhs,      this->w > rhs); }
        friend bool4 operator > (uint lhs, const uint4& rhs) { return bool4(lhs > rhs.x, lhs > rhs.y, lhs > rhs.z, lhs > rhs.w); }

		// less than or equal to    : a <= b	
        bool4 operator <= (const uint4& rhs)const   { return bool4(this->x <= rhs.x,    this->y <= rhs.y,   this->z <= rhs.z,   this->w <= rhs.w); }
        bool4 operator <= (uint rhs)        const   { return bool4(this->x <= rhs,      this->y <= rhs,     this->z <= rhs,     this->w <= rhs); }
        friend bool4 operator <=(uint lhs, const uint4& rhs) { return bool4(lhs <= rhs.x, lhs <= rhs.y, lhs <= rhs.z, lhs <= rhs.w); }

		// greater than or equal to : a >= b
        bool4 operator >= (const uint4& rhs)const   { return bool4(this->x >= rhs.x,    this->y >= rhs.y,   this->z >= rhs.z,   this->w >= rhs.w); }
        bool4 operator >= (uint rhs)        const   { return bool4(this->x >= rhs,      this->y >= rhs,     this->z >= rhs,     this->w >= rhs); }
        friend bool4 operator >=(uint lhs, const uint4& rhs) { return bool4(lhs >= rhs.x, lhs >= rhs.y, lhs >= rhs.z, lhs >= rhs.w); }

        //=========================================================
        // Conversion operators
        //=========================================================


		//=========================================================
		// member access
		//=========================================================
		/// <summary>Returns the uint element at a specified index.</summary>
		uint& operator[] (int index)
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
        uint4 xxxx()    const;
        uint4 xxxy()    const;
        uint4 xxxz()    const;
        uint4 xxxw()    const;
        uint4 xxyx()    const;
        uint4 xxyy()    const;
        uint4 xxyz()    const;
        uint4 xxyw()    const;
        uint4 xxzx()    const;
        uint4 xxzy()    const;
        uint4 xxzz()    const;
        uint4 xxzw()    const;
        uint4 xxwx()    const;
        uint4 xxwy()    const;
        uint4 xxwz()    const;
        uint4 xxww()    const;
        uint4 xyxx()    const;
        uint4 xyxy()    const;
        uint4 xyxz()    const;
        uint4 xyxw()    const;
        uint4 xyyx()    const;
        uint4 xyyy()    const;
        uint4 xyyz()    const;
        uint4 xyyw()    const;
        uint4 xyzx()    const;
        uint4 xyzy()    const;
        uint4 xyzz()    const;
        uint4 xyzw()    const;
        void  xyzw(const uint4& v);
        uint4 xywx()    const;
        uint4 xywy()    const;
        uint4 xywz()    const;
        void  xywz(const uint4& v);
        uint4 xyww()    const;
        uint4 xzxx()    const;
        uint4 xzxy()    const;
        uint4 xzxz()    const;
        uint4 xzxw()    const;
        uint4 xzyx()    const;
        uint4 xzyy()    const;
        uint4 xzyz()    const;
        uint4 xzyw()    const;
        void  xzyw(const uint4& v);
        uint4 xzzx()    const;
        uint4 xzzy()    const;
        uint4 xzzz()    const;
        uint4 xzzw()    const;
        uint4 xzwx()    const;
        uint4 xzwy()    const;
        void  xzwy(const uint4& v);
        uint4 xzwz()    const;
        uint4 xzww()    const;
        uint4 xwxx()    const;
        uint4 xwxy()    const;
        uint4 xwxz()    const;
        uint4 xwxw()    const;
        uint4 xwyx()    const;
        uint4 xwyy()    const;
        uint4 xwyz()    const;
        void  xwyz(const uint4& v);
        uint4 xwyw()    const;
        uint4 xwzx()    const;
        uint4 xwzy()    const;
        void  xwzy(const uint4& v);
        uint4 xwzz()    const;
        uint4 xwzw()    const;
        uint4 xwwx()    const;
        uint4 xwwy()    const;
        uint4 xwwz()    const;
        uint4 xwww()    const;
        uint4 yxxx()    const;
        uint4 yxxy()    const;
        uint4 yxxz()    const;
        uint4 yxxw()    const;
        uint4 yxyx()    const;
        uint4 yxyy()    const;
        uint4 yxyz()    const;
        uint4 yxyw()    const;
        uint4 yxzx()    const;
        uint4 yxzy()    const;
        uint4 yxzz()    const;
        uint4 yxzw()    const;
        void  yxzw(const uint4& v);
        uint4 yxwx()    const;
        uint4 yxwy()    const;
        uint4 yxwz()    const;
        void  yxwz(const uint4& v);
        uint4 yxww()    const;
        uint4 yyxx()    const;
        uint4 yyxy()    const;
        uint4 yyxz()    const;
        uint4 yyxw()    const;
        uint4 yyyx()    const;
        uint4 yyyy()    const;
        uint4 yyyz()    const;
        uint4 yyyw()    const;
        uint4 yyzx()    const;
        uint4 yyzy()    const;
        uint4 yyzz()    const;
        uint4 yyzw()    const;
        uint4 yywx()    const;
        uint4 yywy()    const;
        uint4 yywz()    const;
        uint4 yyww()    const;
        uint4 yzxx()    const;
        uint4 yzxy()    const;
        uint4 yzxz()    const;
        uint4 yzxw()    const;
        void  yzxw(const uint4& v);
        uint4 yzyx()    const;
        uint4 yzyy()    const;
        uint4 yzyz()    const;
        uint4 yzyw()    const;
        uint4 yzzx()    const;
        uint4 yzzy()    const;
        uint4 yzzz()    const;
        uint4 yzzw()    const;
        uint4 yzwx()    const;
        void  yzwx(const uint4& v);
        uint4 yzwy()    const;
        uint4 yzwz()    const;
        uint4 yzww()    const;
        uint4 ywxx()    const;
        uint4 ywxy()    const;
        uint4 ywxz()    const;
        void  ywxz(const uint4& v);
        uint4 ywxw()    const;
        uint4 ywyx()    const;
        uint4 ywyy()    const;
        uint4 ywyz()    const;
        uint4 ywyw()    const;
        uint4 ywzx()    const;
        void  ywzx(const uint4& v);
        uint4 ywzy()    const;
        uint4 ywzz()    const;
        uint4 ywzw()    const;
        uint4 ywwx()    const;
        uint4 ywwy()    const;
        uint4 ywwz()    const;
        uint4 ywww()    const;
        uint4 zxxx()    const;
        uint4 zxxy()    const;
        uint4 zxxz()    const;
        uint4 zxxw()    const;
        uint4 zxyx()    const;
        uint4 zxyy()    const;
        uint4 zxyz()    const;
        uint4 zxyw()    const;
        void  zxyw(const uint4& v);
        uint4 zxzx()    const;
        uint4 zxzy()    const;
        uint4 zxzz()    const;
        uint4 zxzw()    const;
        uint4 zxwx()    const;
        uint4 zxwy()    const;
        void zxwy(const uint4& v);
        uint4 zxwz()    const;
        uint4 zxww()    const;
        uint4 zyxx()    const;
        uint4 zyxy()    const;
        uint4 zyxz()    const;
        uint4 zyxw()    const;
        void  zyxw(const uint4& v);
        uint4 zyyx()    const;
        uint4 zyyy()    const;
        uint4 zyyz()    const;
        uint4 zyyw()    const;
        uint4 zyzx()    const;
        uint4 zyzy()    const;
        uint4 zyzz()    const;
        uint4 zyzw()    const;
        uint4 zywx()    const;
        void  zywx(const uint4& v);
        uint4 zywy()    const;
        uint4 zywz()    const;
        uint4 zyww()    const;
        uint4 zzxx()    const;
        uint4 zzxy()    const;
        uint4 zzxz()    const;
        uint4 zzxw()    const;
        uint4 zzyx()    const;
        uint4 zzyy()    const;
        uint4 zzyz()    const;
        uint4 zzyw()    const;
        uint4 zzzx()    const;
        uint4 zzzy()    const;
        uint4 zzzz()    const;
        uint4 zzzw()    const;
        uint4 zzwx()    const;
        uint4 zzwy()    const;
        uint4 zzwz()    const;
        uint4 zzww()    const;
        uint4 zwxx()    const;
        uint4 zwxy()    const;
        void  zwxy(const uint4& v);
        uint4 zwxz()    const;
        uint4 zwxw()    const;
        uint4 zwyx()    const;
        void  zwyx(const uint4& v);
        uint4 zwyy()    const;
        uint4 zwyz()    const;
        uint4 zwyw()    const;
        uint4 zwzx()    const;
        uint4 zwzy()    const;
        uint4 zwzz()    const;
        uint4 zwzw()    const;
        uint4 zwwx()    const;
        uint4 zwwy()    const;
        uint4 zwwz()    const;
        uint4 zwww()    const;
        uint4 wxxx()    const;
        uint4 wxxy()    const;
        uint4 wxxz()    const;
        uint4 wxxw()    const;
        uint4 wxyx()    const;
        uint4 wxyy()    const;
        uint4 wxyz()    const;
        void  wxyz(const uint4& v);
        uint4 wxyw()    const;
        uint4 wxzx()    const;
        uint4 wxzy()    const;
        void  wxzy(const uint4& v);
        uint4 wxzz()    const;
        uint4 wxzw()    const;
        uint4 wxwx()    const;
        uint4 wxwy()    const;
        uint4 wxwz()    const;
        uint4 wxww()    const;
        uint4 wyxx()    const;
        uint4 wyxy()    const;
        uint4 wyxz()    const;
        void  wyxz(const uint4& v);
        uint4 wyxw()    const;
        uint4 wyyx()    const;
        uint4 wyyy()    const;
        uint4 wyyz()    const;
        uint4 wyyw()    const;
        uint4 wyzx()    const;
        void  wyzx(const uint4& v);
        uint4 wyzy()    const;
        uint4 wyzz()    const;
        uint4 wyzw()    const;
        uint4 wywx()    const;
        uint4 wywy()    const;
        uint4 wywz()    const;
        uint4 wyww()    const;
        uint4 wzxx()    const;
        uint4 wzxy()    const;
        void  wzxy(const uint4& v);
        uint4 wzxz()    const;
        uint4 wzxw()    const;
        uint4 wzyx()    const;
        void  wzyx(const uint4& v);
        uint4 wzyy()    const;
        uint4 wzyz()    const;
        uint4 wzyw()    const;
        uint4 wzzx()    const;
        uint4 wzzy()    const;
        uint4 wzzz()    const;
        uint4 wzzw()    const;
        uint4 wzwx()    const;
        uint4 wzwy()    const;
        uint4 wzwz()    const;
        uint4 wzww()    const;
        uint4 wwxx()    const;
        uint4 wwxy()    const;
        uint4 wwxz()    const;
        uint4 wwxw()    const;
        uint4 wwyx()    const;
        uint4 wwyy()    const;
        uint4 wwyz()    const;
        uint4 wwyw()    const;
        uint4 wwzx()    const;
        uint4 wwzy()    const;
        uint4 wwzz()    const;
        uint4 wwzw()    const;
        uint4 wwwx()    const;
        uint4 wwwy()    const;
        uint4 wwwz()    const;
        uint4 wwww()    const;
        uint3 xxx()     const;
        uint3 xxy()     const;
        uint3 xxz()     const;
        uint3 xxw()     const;
        uint3 xyx()     const;
        uint3 xyy()     const;
        uint3 xyz()     const;
        void  xyz(const uint3& v);
        uint3 xyw()     const;
        void  xyw(const uint3& v);
        uint3 xzx()     const;
        uint3 xzy()     const;
        void  xzy(const uint3& v);
        uint3 xzz()     const;
        uint3 xzw()     const;
        void  xzw(const uint3& v);
        uint3 xwx()     const;
        uint3 xwy()     const;
        void  xwy(const uint3& v);
        uint3 xwz()     const;
        void  xwz(const uint3& v);
        uint3 xww()     const;
        uint3 yxx()     const;
        uint3 yxy()     const;
        uint3 yxz()     const;
        void  yxz(const uint3& v);
        uint3 yxw()     const;
        void  yxw(const uint3& v);
        uint3 yyx()     const;
        uint3 yyy()     const;
        uint3 yyz()     const;
        uint3 yyw()     const;
        uint3 yzx()     const;
        void  yzx(const uint3& v);
        uint3 yzy()     const;
        uint3 yzz()     const;
        uint3 yzw()     const;
        void  yzw(const uint3& v);
        uint3 ywx()     const;
        void  ywx(const uint3& v);
        uint3 ywy()     const;
        uint3 ywz()     const;
        void  ywz(const uint3& v);
        uint3 yww()     const;
        uint3 zxx()     const;
        uint3 zxy()     const;
        void  zxy(const uint3& v);
        uint3 zxz()     const;
        uint3 zxw()     const;
        void  zxw(const uint3& v);
        uint3 zyx()     const;
        void  zyx(const uint3& v);
        uint3 zyy()     const;
        uint3 zyz()     const;
        uint3 zyw()     const;
        void  zyw(const uint3& v);
        uint3 zzx()     const;
        uint3 zzy()     const;
        uint3 zzz()     const;
        uint3 zzw()     const;
        uint3 zwx()     const;
        void  zwx(const uint3& v);
        uint3 zwy()     const;
        void  zwy(const uint3& v);
        uint3 zwz()     const;
        uint3 zww()     const;
        uint3 wxx()     const;
        uint3 wxy()     const;
        void  wxy(const uint3& v);
        uint3 wxz()     const;
        void  wxz(const uint3& v);
        uint3 wxw()     const;
        uint3 wyx()     const;
        void  wyx(const uint3& v);
        uint3 wyy()     const;
        uint3 wyz()     const;
        void  wyz(const uint3& v);
        uint3 wyw()     const;
        uint3 wzx()     const;
        void  wzx(const uint3& v);
        uint3 wzy()     const;
        void  wzy(const uint3& v);
        uint3 wzz()     const;
        uint3 wzw()     const;
        uint3 wwx()     const;
        uint3 wwy()     const;
        uint3 wwz()     const;
        uint3 www()     const;
        uint2 xx()      const;
        uint2 xy()      const;
        void  xy(const uint2& v);
        uint2 xz()      const;
        void  xz(const uint2& v);
        uint2 xw()      const;
        void  xw(const uint2& v);
        uint2 yx()      const;
        void  yx(const uint2& v);
        uint2 yy()      const;
        uint2 yz()      const;
        void  yz(const uint2& v);
        uint2 yw()      const;
        void  yw(const uint2& v);
        uint2 zx()      const;
        void  zx(const uint2& v);
        uint2 zy()      const;
        void  zy(const uint2& v);
        uint2 zz()      const;
        uint2 zw()      const;
        void  zw(const uint2& v);
        uint2 wx()      const;
        void  wx(const uint2& v);
        uint2 wy()      const;
        void  wy(const uint2& v);
        uint2 wz()      const;
        void  wz(const uint2& v);
        uint2 ww()      const;
        
        
        //=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the uint4 is equal to a given uint4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const uint4& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

        /// <summary>Returns true if the uint4 is equal to a given uint4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is uint4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the uint4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the uint4.</summary>
        /// <returns>String representation of the v.</returns>
        std::string ToString()
        {
            return std::format("uint4({0}, {1}, {2}, {3})", x, y, z, w);
        }
	};
    __declspec(selectany) const uint4   uint4::zero = uint4(0, 0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-uint4
        //=========================================================
        /// <summary>Returns a uint hash code of a uint4 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const uint4& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a uint4 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const uint4& v);

        /// <summary>Returns the result of specified shuffling of the components from two uint4 vectors into a uint value.</summary>
        /// <param name="left">uint4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint.</param>
        /// <returns>uint result of the shuffle operation.</returns>
        uint shuffle(const uint4& left, const uint4& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two uint4 vectors into a uint2 vector.</summary>
        /// <param name="left">uint4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint2 y component.</param>
        /// <returns>uint2 result of the shuffle operation.</returns>
        uint2 shuffle(const uint4& left, const uint4& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two uint4 vectors into a uint3 vector.</summary>
        /// <param name="left">uint4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting uint3 z component.</param>
        /// <returns>uint3 result of the shuffle operation.</returns>
        uint3 shuffle(const uint4& left, const uint4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two uint4 vectors into a uint4 vector.</summary>
        /// <param name="left">uint4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting uint4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting uint4 w component.</param>
        /// <returns>uint4 result of the shuffle operation.</returns>
        uint4 shuffle(const uint4& left, const uint4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

