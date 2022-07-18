#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float4.gen.cs
#pragma pack(push,1)
	struct float4
	{
	public:
		static const  float4	zero;
        union {
            struct { float x, y, z, w; };
            float        data[4];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        float4() : x(0.f), y(0.f), z(0.f), w(0.f) {}
		float4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

        float4(float _x, float _y, const float2& _zw)   {   x = _x;     y = _y;     z = _zw.x;  w = _zw.y;  }
        float4(float _x, const float2& _yz, float _w)   {   x = _x;     y = _yz.x;  z = _yz.y;  w = _w;     }
        float4(float _x, const float3& _yzw)            {   x = _x;     y = _yzw.x; z = _yzw.y; w = _yzw.z; }
        float4(const float2& _xy, float _z, float _w)   {   x = _xy.x;  y = _xy.y;  z = _z;     w = _w;     }
        float4(const float2& _xy, const float2& _zw)    {   x = _xy.x;  y = _xy.y;  z = _zw.x;  w = _zw.y;  }
        float4(const float3& _xyz, float _w)            {   x = _xyz.x; y = _xyz.y; z = _xyz.z; w = _w;     }

        float4(bool v)                                  {   x = v ? 1.0f : 0.0f;    y = v ? 1.0f : 0.0f;    z = v ? 1.0f : 0.0f;    w = v ? 1.0f : 0.0f;    }
        float4(uint v)                                  {   x = (float)v;   y = (float)v;   z = (float)v;   w = (float)v;   }
        float4(int v)                                   {   x = (float)v;   y = (float)v;   z = (float)v;   w = (float)v;   }
        //float4(half v)                                {   x = (float)v;   y = (float)v;   z = (float)v;   w = (float)v;   }
        float4(float v)                                 {   x = v;          y = v;          z = v;          w = (float)v;   }
        float4(double v)                                {   x = (float)v;   y = (float)v;   z = (float)v;   w = (float)v;   }

        float4(const bool4& v);
        float4(const uint4& v);
        float4(const int4& v);
        //float4(const half4& v);
        float4(const float4& v);
        float4(const double4& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        float4& operator = (const float4& rhs) { this->x = rhs.x;  this->y = rhs.y;  this->z = rhs.z;  this->w = rhs.w;  return (*this); }
		// addition assignment	            a += b	
        float4& operator +=(const float4& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; this->w += rhs.w; return (*this); }
		// subtraction assignment	        a -= b	
        float4& operator -=(const float4& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; this->w -= rhs.w; return (*this); }
		// multiplication assignment	    a *= b	
        float4& operator *=(const float4& rhs) { this->x *= rhs.x; this->y *= rhs.y; this->z *= rhs.z; this->w *= rhs.w; return (*this); }
		// division assignment	            a /= b	
        float4& operator /=(const float4& rhs) { this->x /= rhs.x; this->y /= rhs.y; this->z /= rhs.z; this->w /= rhs.w; return (*this); }
		// modulo assignment	            a %= b	
        float4& operator %=(const float4& rhs) { this->x = std::fmod(this->x, rhs.x); this->y = std::fmod(this->y, rhs.y); this->z = std::fmod(this->z, rhs.z); this->w = std::fmod(this->w, rhs.w); return (*this); }
		
        // bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
        float4& operator ++ ()                          { ++this->x; ++this->y; ++this->z; ++this->w; return (*this);     }
        // pre - decrement  : 	--a		T&
        float4& operator -- ()                          { --this->x; --this->y; --this->z; --this->w; return (*this);     }
        // post-increment   : 	a++
        float4  operator ++ (int)                       { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        float4  operator -- (int)                       { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
        // unary plus       :   +a
        float4 operator + () const                      { return float4(+this->x, +this->y, +this->z, +this->w); }

        // unary minus      :   -a
        float4 operator - () const                      { return float4(-this->x, -this->y, -this->z, -this->w); }

		// addition         :   a + b
        float4 operator + (const float4& rhs)   const   { return float4(this->x + rhs.x,    this->y + rhs.y,    this->z + rhs.z,    this->w + rhs.w); }
        float4 operator + (float rhs)           const   { return float4(this->x + rhs,      this->y + rhs,      this->z + rhs,      this->w + rhs); }
        friend float4 operator + (float lhs, const float4& rhs) { return float4(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w); }

		// subtraction      :   a - b
        float4 operator - (const float4& rhs)   const   { return float4(this->x - rhs.x,    this->y - rhs.y,    this->z - rhs.z,    this->w - rhs.w); }
        float4 operator - (float rhs)           const   { return float4(this->x - rhs,      this->y - rhs,      this->z - rhs,      this->w - rhs); }
        friend float4 operator - (float lhs, const float4& rhs) { return float4(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w); }

		// multiplication   :   a * b
        float4 operator * (const float4& rhs)   const   { return float4(this->x * rhs.x,    this->y * rhs.y,    this->z * rhs.z,    this->w * rhs.w); }
        float4 operator * (float rhs)           const   { return float4(this->x * rhs,      this->y * rhs,      this->z * rhs,      this->w * rhs); }
        friend float4 operator * (float lhs, const float4& rhs) { return float4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w); }

		// division         :   a / b
        float4 operator / (const float4& rhs)   const   { return float4(this->x / rhs.x,    this->y / rhs.y,    this->z / rhs.z,    this->w / rhs.w); }
        float4 operator / (float rhs)           const   { return float4(this->x / rhs,      this->y / rhs,      this->z / rhs,      this->w / rhs); }
        friend float4 operator / (float lhs, const float4& rhs) { return float4(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w); }

        // modulo           :   a % b
        float4 operator % (const float4& rhs)   const   { return float4(std::fmod(this->x, rhs.x), std::fmod(this->y, rhs.y),  std::fmod(this->z, rhs.z),  std::fmod(this->w, rhs.w)); }
        float4 operator % (float rhs)           const   { return float4(std::fmod(this->x, rhs),   std::fmod(this->y, rhs),    std::fmod(this->z, rhs),    std::fmod(this->w, rhs)); }
        friend float4 operator % (float lhs, const float4& rhs) { return float4(std::fmod(lhs, rhs.x), std::fmod(lhs, rhs.y), std::fmod(lhs, rhs.z), std::fmod(lhs, rhs.w)); }
        
		// bitwise NOT      :   ~a
		// bitwise AND      :   a & b
		// bitwise OR       :   a | b
		// bitwise XOR      :   a ^ b
		// bitwise left shift : a << b
		// bitwise right shift: a >> b

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
        bool4 operator == (const float4& rhs)   const   { return bool4(this->x == rhs.x,    this->y == rhs.y,   this->z == rhs.z,   this->w == rhs.w); }
        bool4 operator == (float rhs)           const   { return bool4(this->x == rhs,      this->y == rhs,     this->z == rhs,     this->w == rhs); }
        friend bool4  operator ==(float lhs, const float4& rhs) { return bool4(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z, lhs == rhs.w); }

        // not equal to     :   a != b
        bool4 operator != (const float4& rhs)   const   { return bool4(this->x != rhs.x,    this->y != rhs.y,   this->z != rhs.z,   this->w != rhs.w); }
        bool4 operator != (float rhs)           const   { return bool4(this->x != rhs,      this->y != rhs,     this->z != rhs,     this->w != rhs); }
        friend bool4  operator !=(float lhs, const float4& rhs) { return bool4(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z, lhs != rhs.w); }

    	// less than        :   a < b
        bool4 operator < (const float4& rhs)    const   { return bool4(this->x < rhs.x,     this->y < rhs.y,    this->z < rhs.z,    this->w < rhs.w); }
        bool4 operator < (float rhs)            const   { return bool4(this->x < rhs,       this->y < rhs,      this->z < rhs,      this->w < rhs); }
        friend bool4  operator < (float lhs, const float4& rhs) { return bool4(lhs < rhs.x, lhs < rhs.y, lhs < rhs.z, lhs < rhs.w); }

		// greater than     :   a > b
        bool4 operator > (const float4& rhs)    const   { return bool4(this->x > rhs.x,     this->y > rhs.y,    this->z > rhs.z,    this->w > rhs.w); }
        bool4 operator > (float rhs)            const   { return bool4(this->x > rhs,       this->y > rhs,      this->z > rhs,      this->w > rhs); }
        friend bool4  operator > (float lhs, const float4& rhs) { return bool4(lhs > rhs.x, lhs > rhs.y, lhs > rhs.z, lhs > rhs.w); }

		// less than or equal to    : a <= b	
        bool4 operator <= (const float4& rhs)   const   { return bool4(this->x <= rhs.x,    this->y <= rhs.y,   this->z <= rhs.z,   this->w <= rhs.w); }
        bool4 operator <= (float rhs)           const   { return bool4(this->x <= rhs,      this->y <= rhs,     this->z <= rhs,     this->w <= rhs); }
        friend bool4  operator <=(float lhs, const float4& rhs) { return bool4(lhs <= rhs.x, lhs <= rhs.y, lhs <= rhs.z, lhs <= rhs.w); }

		// greater than or equal to : a >= b
        bool4 operator >= (const float4& rhs)   const   { return bool4(this->x >= rhs.x,    this->y >= rhs.y,   this->z >= rhs.z,   this->w >= rhs.w); }
        bool4 operator >= (float rhs)           const   { return bool4(this->x >= rhs,      this->y >= rhs,     this->z >= rhs,     this->w >= rhs); }
        friend bool4  operator >=(float lhs, const float4& rhs) { return bool4(lhs >= rhs.x, lhs >= rhs.y, lhs >= rhs.z, lhs >= rhs.w); }

        //=========================================================
        // Conversion operators
        //=========================================================


		//=========================================================
		// member access
		//=========================================================
		/// <summary>Returns the float element at a specified index.</summary>
		float& operator[] (int index)
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
        float4 xxxx()   const;
        float4 xxxy()   const;
        float4 xxxz()   const;
        float4 xxxw()   const;
        float4 xxyx()   const;
        float4 xxyy()   const;
        float4 xxyz()   const;
        float4 xxyw()   const;
        float4 xxzx()   const;
        float4 xxzy()   const;
        float4 xxzz()   const;
        float4 xxzw()   const;
        float4 xxwx()   const;
        float4 xxwy()   const;
        float4 xxwz()   const;
        float4 xxww()   const;
        float4 xyxx()   const;
        float4 xyxy()   const;
        float4 xyxz()   const;
        float4 xyxw()   const;
        float4 xyyx()   const;
        float4 xyyy()   const;
        float4 xyyz()   const;
        float4 xyyw()   const;
        float4 xyzx()   const;
        float4 xyzy()   const;
        float4 xyzz()   const;
        float4 xyzw()   const;
        void   xyzw(const float4& v);
        float4 xywx()   const;
        float4 xywy()   const;
        float4 xywz()   const;
        void   xywz(const float4& v);
        float4 xyww()   const;
        float4 xzxx()   const;
        float4 xzxy()   const;
        float4 xzxz()   const;
        float4 xzxw()   const;
        float4 xzyx()   const;
        float4 xzyy()   const;
        float4 xzyz()   const;
        float4 xzyw()   const;
        void   xzyw(const float4& v);
		float4 xzzx()   const;
		float4 xzzy()   const;
		float4 xzzz()   const;
		float4 xzzw()   const;
		float4 xzwx()   const;
		float4 xzwy()   const;
        void   xzwy(const float4& v);
        float4 xzwz()   const;
        float4 xzww()   const;
        float4 xwxx()   const;
        float4 xwxy()   const;
        float4 xwxz()   const;
        float4 xwxw()   const;
        float4 xwyx()   const;
        float4 xwyy()   const;
        float4 xwyz()   const;
        void   xwyz(const float4& v);
        float4 xwyw()   const;
        float4 xwzx()   const;
        float4 xwzy()   const;
        void   xwzy(const float4& v);
        float4 xwzz()   const;
        float4 xwzw()   const;
        float4 xwwx()   const;
        float4 xwwy()   const;
        float4 xwwz()   const;
        float4 xwww()   const;
        float4 yxxx()   const;
        float4 yxxy()   const;
        float4 yxxz()   const;
        float4 yxxw()   const;
        float4 yxyx()   const;
        float4 yxyy()   const;
        float4 yxyz()   const;
        float4 yxyw()   const;
        float4 yxzx()   const;
        float4 yxzy()   const;
        float4 yxzz()   const;
        float4 yxzw()   const;
        void   yxzw(const float4& v);
        float4 yxwx()   const;
        float4 yxwy()   const;
        float4 yxwz()   const;
        void   yxwz(const float4& v);
        float4 yxww()   const;
        float4 yyxx()   const;
        float4 yyxy()   const;
        float4 yyxz()   const;
        float4 yyxw()   const;
        float4 yyyx()   const;
        float4 yyyy()   const;
        float4 yyyz()   const;
        float4 yyyw()   const;
        float4 yyzx()   const;
        float4 yyzy()   const;
        float4 yyzz()   const;
        float4 yyzw()   const;
        float4 yywx()   const;
        float4 yywy()   const;
        float4 yywz()   const;
        float4 yyww()   const;
        float4 yzxx()   const;
        float4 yzxy()   const;
        float4 yzxz()   const;
        float4 yzxw()   const;
        void   yzxw(const float4& v);
        float4 yzyx()   const;
        float4 yzyy()   const;
        float4 yzyz()   const;
        float4 yzyw()   const;
        float4 yzzx()   const;
        float4 yzzy()   const;
        float4 yzzz()   const;
        float4 yzzw()   const;
        float4 yzwx()   const;
        void   yzwx(const float4& v);
        float4 yzwy()   const;
        float4 yzwz()   const;
        float4 yzww()   const;
        float4 ywxx()   const;
        float4 ywxy()   const;
        float4 ywxz()   const;
        void   ywxz(const float4& v);
        float4 ywxw()   const;
        float4 ywyx()   const;
        float4 ywyy()   const;
        float4 ywyz()   const;
        float4 ywyw()   const;
        float4 ywzx()   const;
        void   ywzx(const float4& v);
        float4 ywzy()   const;
        float4 ywzz()   const;
        float4 ywzw()   const;
        float4 ywwx()   const;
        float4 ywwy()   const;
        float4 ywwz()   const;
        float4 ywww()   const;
        float4 zxxx()   const;
        float4 zxxy()   const;
        float4 zxxz()   const;
        float4 zxxw()   const;
        float4 zxyx()   const;
        float4 zxyy()   const;
        float4 zxyz()   const;
        float4 zxyw()   const;
        void   zxyw(const float4& v);
        float4 zxzx()   const;
        float4 zxzy()   const;
        float4 zxzz()   const;
        float4 zxzw()   const;
        float4 zxwx()   const;
        float4 zxwy()   const;
        void   zxwy(const float4& v);
        float4 zxwz()   const;
        float4 zxww()   const;
        float4 zyxx()   const;
        float4 zyxy()   const;
        float4 zyxz()   const;
        float4 zyxw()   const;
        void   zyxw(const float4& v);
        float4 zyyx()   const;
        float4 zyyy()   const;
        float4 zyyz()   const;
        float4 zyyw()   const;
        float4 zyzx()   const;
        float4 zyzy()   const;
        float4 zyzz()   const;
        float4 zyzw()   const;
        float4 zywx()   const;
        void   zywx(const float4& v);
        float4 zywy()   const;
        float4 zywz()   const;
        float4 zyww()   const;
        float4 zzxx()   const;
        float4 zzxy()   const;
        float4 zzxz()   const;
        float4 zzxw()   const;
        float4 zzyx()   const;
        float4 zzyy()   const;
        float4 zzyz()   const;
        float4 zzyw()   const;
        float4 zzzx()   const;
        float4 zzzy()   const;
        float4 zzzz()   const;
        float4 zzzw()   const;
        float4 zzwx()   const;
        float4 zzwy()   const;
        float4 zzwz()   const;
        float4 zzww()   const;
        float4 zwxx()   const;
        float4 zwxy()   const;
        void   zwxy(const float4& v);
        float4 zwxz()   const;
        float4 zwxw()   const;
        float4 zwyx()   const;
        void   zwyx(const float4& v);
        float4 zwyy()   const;
        float4 zwyz()   const;
        float4 zwyw()   const;
        float4 zwzx()   const;
        float4 zwzy()   const;
        float4 zwzz()   const;
        float4 zwzw()   const;
        float4 zwwx()   const;
        float4 zwwy()   const;
        float4 zwwz()   const;
        float4 zwww()   const;
        float4 wxxx()   const;
        float4 wxxy()   const;
        float4 wxxz()   const;
        float4 wxxw()   const;
        float4 wxyx()   const;
        float4 wxyy()   const;
        float4 wxyz()   const;
        void   wxyz(const float4& v);
        float4 wxyw()   const;
        float4 wxzx()   const;
        float4 wxzy()   const;
        void   wxzy(const float4& v);
        float4 wxzz()   const;
        float4 wxzw()   const;
        float4 wxwx()   const;
        float4 wxwy()   const;
        float4 wxwz()   const;
        float4 wxww()   const;
        float4 wyxx()   const;
        float4 wyxy()   const;
        float4 wyxz()   const;
        void   wyxz(const float4& v);
        float4 wyxw()   const;
        float4 wyyx()   const;
        float4 wyyy()   const;
        float4 wyyz()   const;
        float4 wyyw()   const;
        float4 wyzx()   const;
        void   wyzx(const float4& v);
        float4 wyzy()   const;
        float4 wyzz()   const;
        float4 wyzw()   const;
        float4 wywx()   const;
        float4 wywy()   const;
        float4 wywz()   const;
        float4 wyww()   const;
        float4 wzxx()   const;
        float4 wzxy()   const;
        void   wzxy(const float4& v);
        float4 wzxz()   const;
        float4 wzxw()   const;
        float4 wzyx()   const;
        void   wzyx(const float4& v);
        float4 wzyy()   const;
        float4 wzyz()   const;
        float4 wzyw()   const;
        float4 wzzx()   const;
        float4 wzzy()   const;
        float4 wzzz()   const;
        float4 wzzw()   const;
        float4 wzwx()   const;
        float4 wzwy()   const;
        float4 wzwz()   const;
        float4 wzww()   const;
        float4 wwxx()   const;
        float4 wwxy()   const;
        float4 wwxz()   const;
        float4 wwxw()   const;
        float4 wwyx()   const;
        float4 wwyy()   const;
        float4 wwyz()   const;
        float4 wwyw()   const;
        float4 wwzx()   const;
        float4 wwzy()   const;
        float4 wwzz()   const;
        float4 wwzw()   const;
        float4 wwwx()   const;
        float4 wwwy()   const;
        float4 wwwz()   const;
        float4 wwww()   const;
        float3 xxx()    const;
        float3 xxy()    const;
        float3 xxz()    const;
        float3 xxw()    const;
        float3 xyx()    const;
        float3 xyy()    const;
        float3 xyz()    const;
        void   xyz(const float3& v);
        float3 xyw()    const;
        void   xyw(const float3& v);
        float3 xzx()    const;
        float3 xzy()    const;
        void   xzy(const float3& v);
        float3 xzz()    const;
        float3 xzw()    const;
        void   xzw(const float3& v);
        float3 xwx()    const;
        float3 xwy()    const;
        void   xwy(const float3& v);
        float3 xwz()    const;
        void   xwz(const float3& v);
        float3 xww()    const;
        float3 yxx()    const;
        float3 yxy()    const;
        float3 yxz()    const;
        void   yxz(const float3& v);
        float3 yxw()    const;
        void   yxw(const float3& v);
        float3 yyx()    const;
        float3 yyy()    const;
        float3 yyz()    const;
        float3 yyw()    const;
        float3 yzx()    const;
        void   yzx(const float3& v);
        float3 yzy()    const;
        float3 yzz()    const;
        float3 yzw()    const;
        void   yzw(const float3& v);
        float3 ywx()    const;
        void   ywx(const float3& v);
        float3 ywy()    const;
        float3 ywz()    const;
        void   ywz(const float3& v);
        float3 yww()    const;
        float3 zxx()    const;
        float3 zxy()    const;
        void   zxy(const float3& v);
        float3 zxz()    const;
        float3 zxw()    const;
        void   zxw(const float3& v);
        float3 zyx()    const;
        void   zyx(const float3& v);
        float3 zyy()    const;
        float3 zyz()    const;
        float3 zyw()    const;
        void   zyw(const float3& v);
        float3 zzx()    const;
        float3 zzy()    const;
        float3 zzz()    const;
        float3 zzw()    const;
        float3 zwx()    const;
        void   zwx(const float3& v);
        float3 zwy()    const;
        void   zwy(const float3& v);
        float3 zwz()    const;
        float3 zww()    const;
        float3 wxx()    const;
        float3 wxy()    const;
        void   wxy(const float3& v);
        float3 wxz()    const;
        void   wxz(const float3& v);
        float3 wxw()    const;
        float3 wyx()    const;
        void   wyx(const float3& v);
        float3 wyy()    const;
        float3 wyz()    const;
        void   wyz(const float3& v);
        float3 wyw()    const;
        float3 wzx()    const;
        void   wzx(const float3& v);
        float3 wzy()    const;
        void   wzy(const float3& v);
        float3 wzz()    const;
        float3 wzw()    const;
        float3 wwx()    const;
        float3 wwy()    const;
        float3 wwz()    const;
        float3 www()    const;
        float2 xx()     const;
        float2 xy()     const;
        void   xy(const float2& v);
        float2 xz()     const;
        void   xz(const float2& v);
        float2 xw()     const;
        void   xw(const float2& v);
        float2 yx()     const;
        void   yx(const float2& v);
        float2 yy()     const;
        float2 yz()     const;
        void   yz(const float2& v);
        float2 yw()     const;
        void   yw(const float2& v);
        float2 zx()     const;
        void   zx(const float2& v);
        float2 zy()     const;
        void   zy(const float2& v);
        float2 zz()     const;
        float2 zw()     const;
        void   zw(const float2& v);
        float2 wx()     const;
        void   wx(const float2& v);
        float2 wy()     const;
        void   wy(const float2& v);
        float2 wz()     const;
        void   wz(const float2& v);
        float2 ww()     const;

		//=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the float4 is equal to a given float4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float4& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

        /// <summary>Returns true if the float4 is equal to a given float4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the float4.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float4({0}f, {1}f, {2}f, {3}f)", x, y, z, w);
        }
	};
    __declspec(selectany) const float4  float4::zero = float4(0, 0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
	    // math-float4
	    //=========================================================
        /// <summary>Returns a uint hash code of a float4 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const float4& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a float4 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const float4& v);

        /// <summary>Returns the result of specified shuffling of the components from two float4 vectors into a float value.</summary>
        /// <param name="left">float4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float.</param>
        /// <returns>float result of the shuffle operation.</returns>
        float shuffle(const float4& left, const float4& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two float4 vectors into a float2 vector.</summary>
        /// <param name="left">float4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float2 y component.</param>
        /// <returns>float2 result of the shuffle operation.</returns>
        float2 shuffle(const float4& left, const float4& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two float4 vectors into a float3 vector.</summary>
        /// <param name="left">float4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting float3 z component.</param>
        /// <returns>float3 result of the shuffle operation.</returns>
        float3 shuffle(const float4& left, const float4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two float4 vectors into a float4 vector.</summary>
        /// <param name="left">float4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting float4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting float4 w component.</param>
        /// <returns>float4 result of the shuffle operation.</returns>
        float4 shuffle(const float4& left, const float4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

