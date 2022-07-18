#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/double4.gen.cs
#pragma pack(push,1)
	struct double4
	{
	public:
		static const  double4	zero;
        union {
            struct { double x, y, z, w; };
            double        data[4];
        };

	public:
        //=========================================================
		// CONSTRUCTOR
		//=========================================================
        double4() : x(0), y(0), z(0), w(0) {}
		double4(double _x, double _y, double _z, double _w) : x(_x), y(_y), z(_z), w(_w){}
        double4(double _x, double _y, const double2& _zw)   {   x = _x;     y = _y;     z = _zw.x;  w = _zw.y;  }
        double4(double _x, const double2& _yz, double _w)   {   x = _x;     y = _yz.x;  z = _yz.y;  w = _w;     }
        double4(double _x, const double3& _yzw)             {   x = _x;     y = _yzw.x; z = _yzw.y; w = _yzw.z; }
        double4(const double2& _xy, double _z, double _w)   {   x = _xy.x;  y = _xy.y;  z = _z;     w = _w;     }
        double4(const double2& _xy, const double2& _zw)     {   x = _xy.x;  y = _xy.y;  z = _zw.x;  w = _zw.y;  }
        double4(const double3& _xyz, double _w)             {   x = _xyz.x; y = _xyz.y; z = _xyz.z; w = _w;     }

        double4(bool v)                                     {   x = v ? 1.0 : 0.0;  y = v ? 1.0 : 0.0;  z = v ? 1.0 : 0.0;  w = v ? 1.0 : 0.0;  }
        double4(uint v)                                     {   x = v;      y = v;      z = v;      w = v;      }
        double4(int v)                                      {   x = v;      y = v;      z = v;      w = v;      }
        //double4(half v)                                   {   x = v;      y = v;      z = v;      w = v;      }
        double4(float v)                                    {   x = v;      y = v;      z = v;      w = v;      }
        double4(double v)                                   {   x = v;      y = v;      z = v;      w = v;      }

        double4(const bool4& v);
        double4(const uint4& v);
        double4(const int4& v);
        //double4(const half4& v) ;
        double4(const float4& v);
        double4(const double4& v);
        //=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        double4& operator = (const double4& rhs) { this->x = rhs.x;  this->y = rhs.y;  this->z = rhs.z;  this->w = rhs.w;  return (*this); }
		// addition assignment	            a += b	
        double4& operator +=(const double4& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; this->w += rhs.w; return (*this); }
		// subtraction assignment	        a -= b	
        double4& operator -=(const double4& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; this->w -= rhs.w; return (*this); }
		// multiplication assignment	    a *= b	
        double4& operator *=(const double4& rhs) { this->x *= rhs.x; this->y *= rhs.y; this->z *= rhs.z; this->w *= rhs.w; return (*this); }
		// division assignment	            a /= b	
        double4& operator /=(const double4& rhs) { this->x /= rhs.x; this->y /= rhs.y; this->z /= rhs.z; this->w /= rhs.w; return (*this); }
		// modulo assignment	            a %= b	
		double4& operator %=(const double4& rhs) { this->x = std::fmod(this->x, rhs.x); this->y = std::fmod(this->y, rhs.y); this->z = std::fmod(this->z, rhs.z); this->w = std::fmod(this->w, rhs.w); return (*this); }
		
        // bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
        double4& operator ++ ()                         { ++this->x; ++this->y; ++this->z; ++this->w; return (*this); }
		// pre - decrement  : 	--a		T&
        double4& operator -- ()                         { --this->x; --this->y; --this->z; --this->w; return (*this); }
		// post-increment   : 	a++
        double4  operator ++ (int)                      { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
        double4  operator -- (int)                      { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
        double4  operator + () const                    { return double4(+this->x, +this->y, +this->z, +this->w); }

		// unary minus      :   -a
        double4  operator - () const                    { return double4(-this->x, -this->y, -this->z, -this->w); }

		// addition         :   a + b
        double4  operator + (const double4& rhs)const   { return double4(this->x + rhs.x,   this->y + rhs.y,    this->z + rhs.z,    this->w + rhs.w); }
        double4  operator + (double rhs)        const   { return double4(this->x + rhs,     this->y + rhs,      this->z + rhs,      this->w + rhs); }
        friend double4 operator + (double lhs, const double4& rhs) { return double4(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w); }

        // subtraction      :   a - b
        double4  operator - (const double4& rhs)const   { return double4(this->x - rhs.x,   this->y - rhs.y,    this->z - rhs.z,    this->w - rhs.w); }
        double4  operator - (double rhs)        const   { return double4(this->x - rhs,     this->y - rhs,      this->z - rhs,      this->w - rhs); }
        friend double4 operator - (double lhs, const double4& rhs) { return double4(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w); }

		// multiplication   :   a * b
        double4  operator * (const double4& rhs)const   { return double4(this->x * rhs.x,   this->y * rhs.y,    this->z * rhs.z,    this->w * rhs.w); }
        double4  operator * (double rhs)        const   { return double4(this->x * rhs,     this->y * rhs,      this->z * rhs,      this->w * rhs); }
        friend double4 operator * (double lhs, const double4& rhs) { return double4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w); }

		// division         :   a / b
        double4  operator / (const double4& rhs)const   { return double4(this->x / rhs.x,   this->y / rhs.y,    this->z / rhs.z,    this->w / rhs.w); }
        double4  operator / (double rhs)        const   { return double4(this->x / rhs,     this->y / rhs,      this->z / rhs,      this->w / rhs); }
        friend double4 operator / (double lhs, const double4& rhs) { return double4(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w); }

		// modulo           :   a % b
        double4  operator % (const double4& rhs)const   { return double4(std::fmod(this->x, rhs.x), std::fmod(this->y, rhs.y),  std::fmod(this->z, rhs.z),  std::fmod(this->w, rhs.w)); }
        double4  operator % (double rhs)        const   { return double4(std::fmod(this->x, rhs),   std::fmod(this->y, rhs),    std::fmod(this->z, rhs),    std::fmod(this->w, rhs)); }
        friend double4 operator % (double lhs, const double4& rhs) { return double4(std::fmod(lhs, rhs.x), std::fmod(lhs, rhs.y), std::fmod(lhs, rhs.z), std::fmod(lhs, rhs.w)); }

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
        bool4  operator == (const double4& rhs)     const   { return bool4(this->x == rhs.x,    this->y == rhs.y,   this->z == rhs.z,   this->w == rhs.w); }
        bool4  operator == (double rhs)             const   { return bool4(this->x == rhs,      this->y == rhs,     this->z == rhs,     this->w == rhs); }
        friend bool4   operator ==(double lhs, const double4& rhs) { return bool4(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z, lhs == rhs.w); }

        // not equal to     :   a != b
        bool4  operator != (const double4& rhs)     const   { return bool4(this->x != rhs.x,    this->y != rhs.y,   this->z != rhs.z,   this->w != rhs.w); }
        bool4  operator != (double rhs)             const   { return bool4(this->x != rhs,      this->y != rhs,     this->z != rhs,     this->w != rhs); }
        friend bool4   operator !=(double lhs, const double4& rhs) { return bool4(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z, lhs != rhs.w); }

		// less than        :   a < b
        bool4  operator < (const double4& rhs)      const   { return bool4(this->x < rhs.x,     this->y < rhs.y,    this->z < rhs.z,    this->w < rhs.w); }
        bool4  operator < (double rhs)              const   { return bool4(this->x < rhs,       this->y < rhs,      this->z < rhs,      this->w < rhs); }
        friend bool4   operator < (double lhs, const double4& rhs) { return bool4(lhs < rhs.x, lhs < rhs.y, lhs < rhs.z, lhs < rhs.w); }

		// greater than     :   a > b
        bool4  operator > (const double4& rhs)      const   { return bool4(this->x > rhs.x,     this->y > rhs.y,    this->z > rhs.z,    this->w > rhs.w); }
        bool4  operator > (double rhs)              const   { return bool4(this->x > rhs,       this->y > rhs,      this->z > rhs,      this->w > rhs); }
        friend bool4   operator > (double lhs, const double4& rhs) { return bool4(lhs > rhs.x, lhs > rhs.y, lhs > rhs.z, lhs > rhs.w); }


		// less than or equal to    : a <= b
        bool4  operator <= (const double4& rhs)     const   { return bool4(this->x <= rhs.x,    this->y <= rhs.y,   this->z <= rhs.z,   this->w <= rhs.w); }
        bool4  operator <= (double rhs)             const   { return bool4(this->x <= rhs,      this->y <= rhs,     this->z <= rhs,     this->w <= rhs); }
        friend bool4   operator <=(double lhs, const double4& rhs) { return bool4(lhs <= rhs.x, lhs <= rhs.y, lhs <= rhs.z, lhs <= rhs.w); }

		// greater than or equal to : a >= b
        bool4  operator >= (const double4& rhs)     const   { return bool4(this->x >= rhs.x,    this->y >= rhs.y,   this->z >= rhs.z,   this->w >= rhs.w); }
        bool4  operator >= (double rhs)             const   { return bool4(this->x >= rhs,      this->y >= rhs,     this->z >= rhs,     this->w >= rhs); }
        friend bool4   operator >=(double lhs, const double4& rhs) { return bool4(lhs >= rhs.x, lhs >= rhs.y, lhs >= rhs.z, lhs >= rhs.w); }

        //=========================================================
        // Conversion operators
        //=========================================================


		//=========================================================
		// member access
		//=========================================================
		/// <summary>Returns the double element at a specified index.</summary>
		double& operator[] (int index)
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
        double4 xxxx()  const;
        double4 xxxy()  const;
        double4 xxxz()  const;
        double4 xxxw()  const;
        double4 xxyx()  const;
        double4 xxyy()  const;
        double4 xxyz()  const;
        double4 xxyw()  const;
        double4 xxzx()  const;
        double4 xxzy()  const;
        double4 xxzz()  const;
        double4 xxzw()  const;
        double4 xxwx()  const;
        double4 xxwy()  const;
        double4 xxwz()  const;
        double4 xxww()  const;
        double4 xyxx()  const;
        double4 xyxy()  const;
        double4 xyxz()  const;
        double4 xyxw()  const;
        double4 xyyx()  const;
        double4 xyyy()  const;
        double4 xyyz()  const;
        double4 xyyw()  const;
        double4 xyzx()  const;
        double4 xyzy()  const;
        double4 xyzz()  const;
        double4 xyzw()  const;
        void    xyzw(const double4& v);
        double4 xywx()  const;
        double4 xywy()  const;
        double4 xywz()  const;
        void    xywz(const double4& v);
        double4 xyww()  const;
        double4 xzxx()  const;
        double4 xzxy()  const;
        double4 xzxz()  const;
        double4 xzxw()  const;
        double4 xzyx()  const;
        double4 xzyy()  const;
        double4 xzyz()  const;
        double4 xzyw()  const;
        void    xzyw(const double4& v);
        double4 xzzx()  const;
        double4 xzzy()  const;
        double4 xzzz()  const;
        double4 xzzw()  const;
        double4 xzwx()  const;
        double4 xzwy()  const;
        void    xzwy(const double4& v);
        double4 xzwz()  const;
        double4 xzww()  const;
        double4 xwxx()  const;
        double4 xwxy()  const;
        double4 xwxz()  const;
        double4 xwxw()  const;
        double4 xwyx()  const;
        double4 xwyy()  const;
        double4 xwyz()  const;
        void    xwyz(const double4& v);
        double4 xwyw()  const;
        double4 xwzx()  const;
        double4 xwzy()  const;
        void    xwzy(const double4& v);
        double4 xwzz()  const;
        double4 xwzw()  const;
        double4 xwwx()  const;
        double4 xwwy()  const;
        double4 xwwz()  const;
        double4 xwww()  const;
        double4 yxxx()  const;
        double4 yxxy()  const;
        double4 yxxz()  const;
        double4 yxxw()  const;
        double4 yxyx()  const;
        double4 yxyy()  const;
        double4 yxyz()  const;
        double4 yxyw()  const;
        double4 yxzx()  const;
        double4 yxzy()  const;
        double4 yxzz()  const;
        double4 yxzw()  const;
        void    yxzw(const double4& v);
        double4 yxwx()  const;
        double4 yxwy()  const;
        double4 yxwz()  const;
        void    yxwz(const double4& v);
        double4 yxww()  const;
        double4 yyxx()  const;
        double4 yyxy()  const;
        double4 yyxz()  const;
        double4 yyxw()  const;
        double4 yyyx()  const;
        double4 yyyy()  const;
        double4 yyyz()  const;
        double4 yyyw()  const;
        double4 yyzx()  const;
        double4 yyzy()  const;
        double4 yyzz()  const;
        double4 yyzw()  const;
        double4 yywx()  const;
        double4 yywy()  const;
        double4 yywz()  const;
        double4 yyww()  const;
        double4 yzxx()  const;
        double4 yzxy()  const;
        double4 yzxz()  const;
        double4 yzxw()  const;
        void    yzxw(const double4& v);
        double4 yzyx()  const;
        double4 yzyy()  const;
        double4 yzyz()  const;
        double4 yzyw()  const;
        double4 yzzx()  const;
        double4 yzzy()  const;
        double4 yzzz()  const;
        double4 yzzw()  const;
        double4 yzwx()  const;
        void    yzwx(const double4& v);
        double4 yzwy()  const;
        double4 yzwz()  const;
        double4 yzww()  const;
        double4 ywxx()  const;
        double4 ywxy()  const;
        double4 ywxz()  const;
        void    ywxz(const double4& v);
        double4 ywxw()  const;
        double4 ywyx()  const;
        double4 ywyy()  const;
        double4 ywyz()  const;
        double4 ywyw()  const;
        double4 ywzx()  const;
        void    ywzx(const double4& v);
        double4 ywzy()  const;
        double4 ywzz()  const;
        double4 ywzw()  const;
        double4 ywwx()  const;
        double4 ywwy()  const;
        double4 ywwz()  const;
        double4 ywww()  const;
        double4 zxxx()  const;
        double4 zxxy()  const;
        double4 zxxz()  const;
        double4 zxxw()  const;
        double4 zxyx()  const;
        double4 zxyy()  const;
        double4 zxyz()  const;
        double4 zxyw()  const;
        void    zxyw(const double4& v);
        double4 zxzx()  const;
        double4 zxzy()  const;
        double4 zxzz()  const;
        double4 zxzw()  const;
        double4 zxwx()  const;
        double4 zxwy()  const;
        void    zxwy(const double4& v);
        double4 zxwz()  const;
        double4 zxww()  const;
        double4 zyxx()  const;
        double4 zyxy()  const;
        double4 zyxz()  const;
        double4 zyxw()  const;
        void    zyxw(const double4& v);
        double4 zyyx()  const;
        double4 zyyy()  const;
        double4 zyyz()  const;
        double4 zyyw()  const;
        double4 zyzx()  const;
        double4 zyzy()  const;
        double4 zyzz()  const;
        double4 zyzw()  const;
        double4 zywx()  const;
        void    zywx(const double4& v);
        double4 zywy()  const;
        double4 zywz()  const;
        double4 zyww()  const;
        double4 zzxx()  const;
        double4 zzxy()  const;
        double4 zzxz()  const;
        double4 zzxw()  const;
        double4 zzyx()  const;
        double4 zzyy()  const;
        double4 zzyz()  const;
        double4 zzyw()  const;
        double4 zzzx()  const;
        double4 zzzy()  const;
        double4 zzzz()  const;
        double4 zzzw()  const;
        double4 zzwx()  const;
        double4 zzwy()  const;
        double4 zzwz()  const;
        double4 zzww()  const;
        double4 zwxx()  const;
        double4 zwxy()  const;
        void    zwxy(const double4& v);
        double4 zwxz()  const;
        double4 zwxw()  const;
        double4 zwyx()  const;
        void    zwyx(const double4& v);
        double4 zwyy()  const;
        double4 zwyz()  const;
        double4 zwyw()  const;
        double4 zwzx()  const;
        double4 zwzy()  const;
        double4 zwzz()  const;
        double4 zwzw()  const;
        double4 zwwx()  const;
        double4 zwwy()  const;
        double4 zwwz()  const;
        double4 zwww()  const;
        double4 wxxx()  const;
        double4 wxxy()  const;
        double4 wxxz()  const;
        double4 wxxw()  const;
        double4 wxyx()  const;
        double4 wxyy()  const;
        double4 wxyz()  const;
        void    wxyz(const double4& v);
        double4 wxyw()  const;
        double4 wxzx()  const;
        double4 wxzy()  const;
        void    wxzy(const double4& v);
        double4 wxzz()  const;
        double4 wxzw()  const;
        double4 wxwx()  const;
        double4 wxwy()  const;
        double4 wxwz()  const;
        double4 wxww()  const;
        double4 wyxx()  const;
        double4 wyxy()  const;
        double4 wyxz()  const;
        void    wyxz(const double4& v);
        double4 wyxw()  const;
        double4 wyyx()  const;
        double4 wyyy()  const;
        double4 wyyz()  const;
        double4 wyyw()  const;
        double4 wyzx()  const;
        void    wyzx(const double4& v);
        double4 wyzy()  const;
        double4 wyzz()  const;
        double4 wyzw()  const;
        double4 wywx()  const;
        double4 wywy()  const;
        double4 wywz()  const;
        double4 wyww()  const;
        double4 wzxx()  const;
        double4 wzxy()  const;
        void    wzxy(const double4& v);
        double4 wzxz()  const;
        double4 wzxw()  const;
        double4 wzyx()  const;
        void    wzyx(const double4& v);
        double4 wzyy()  const;
        double4 wzyz()  const;
        double4 wzyw()  const;
        double4 wzzx()  const;
        double4 wzzy()  const;
        double4 wzzz()  const;
        double4 wzzw()  const;
        double4 wzwx()  const;
        double4 wzwy()  const;
        double4 wzwz()  const;
        double4 wzww()  const;
        double4 wwxx()  const;
        double4 wwxy()  const;
        double4 wwxz()  const;
        double4 wwxw()  const;
        double4 wwyx()  const;
        double4 wwyy()  const;
        double4 wwyz()  const;
        double4 wwyw()  const;
        double4 wwzx()  const;
        double4 wwzy()  const;
        double4 wwzz()  const;
        double4 wwzw()  const;
        double4 wwwx()  const;
        double4 wwwy()  const;
        double4 wwwz()  const;
        double4 wwww()  const;
        double3 xxx()   const;
        double3 xxy()   const;
        double3 xxz()   const;
        double3 xxw()   const;
        double3 xyx()   const;
        double3 xyy()   const;
        double3 xyz()   const;
        void    xyz(const double3& v);
        double3 xyw()   const;
        void    xyw(const double3& v);
        double3 xzx()   const;
        double3 xzy()   const;
        void    xzy(const double3 &v);
        double3 xzz()   const;
        double3 xzw()   const;
        void    xzw(const double3& v);
        double3 xwx()   const;
        double3 xwy()   const;
        void    xwy(const double3& v);
        double3 xwz()   const;
        void    xwz(const double3& v);
        double3 xww()   const;
        double3 yxx()   const;
        double3 yxy()   const;
        double3 yxz()   const;
        void    yxz(const double3& v);
        double3 yxw()   const;
        void    yxw(const double3& v);
        double3 yyx()   const;
        double3 yyy()   const;
        double3 yyz()   const;
        double3 yyw()   const;
        double3 yzx()   const;
        void    yzx(const double3& v);
        double3 yzy()   const;
        double3 yzz()   const;
        double3 yzw()   const;
        void    yzw(const double3& v);
        double3 ywx()   const;
        void    ywx(const double3& v);
        double3 ywy()   const;
        double3 ywz()   const;
        void    ywz(const double3& v);
        double3 yww()   const;
        double3 zxx()   const;
        double3 zxy()   const;
        void    zxy(const double3& v);
        double3 zxz()   const;
        double3 zxw()   const;
        void    zxw(const double3& v);
        double3 zyx()   const;
        void    zyx(const double3& v);
        double3 zyy()   const;
        double3 zyz()   const;
        double3 zyw()   const;
        void    zyw(const double3& v);
        double3 zzx()   const;
        double3 zzy()   const;
        double3 zzz()   const;
        double3 zzw()   const;
        double3 zwx()   const;
        void    zwx(const double3& v);
        double3 zwy()   const;
        void    zwy(const double3& v);
        double3 zwz()   const;
        double3 zww()   const;
        double3 wxx()   const;
        double3 wxy()   const;
        void    wxy(const double3& v);
        double3 wxz()   const;
        void    wxz(const double3& v);
        double3 wxw()   const;
        double3 wyx()   const;
        void    wyx(const double3& v);
        double3 wyy()   const;
        double3 wyz()   const;
        void    wyz(const double3& v);
        double3 wyw()   const;
        double3 wzx()   const;
        void    wzx(const double3& v);
        double3 wzy()   const;
        void    wzy(const double3& v);
        double3 wzz()   const;
        double3 wzw()   const;
        double3 wwx()   const;
        double3 wwy()   const;
        double3 wwz()   const;
        double3 www()   const;
        double2 xx()    const;
        double2 xy()    const;
        void    xy(const double2& v);
        double2 xz()    const;
        void    xz(const double2& v);
        double2 xw()    const;
        void    xw(const double2& v);
        double2 yx()    const;
        void    yx(const double2& v);
        double2 yy()    const;
        double2 yz()    const;
        void    yz(const double2& v);
        double2 yw()    const;
        void    yw(const double2& v);
        double2 zx()    const;
        void    zx(const double2& v);
        double2 zy()    const;
        void    zy(const double2& v);
        double2 zz()    const;
        double2 zw()    const;
        void    zw(const double2& v);
        double2 wx()    const;
        void    wx(const double2& v);
        double2 wy()    const;
        void    wy(const double2& v);
        double2 wz()    const;
        void    wz(const double2& v);
        double2 ww()    const;
                                      

		//=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the double4 is equal to a given double4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const double4& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }

        /// <summary>Returns true if the double4 is equal to a given double4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is double4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the double4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the double4.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("double4({0}, {1}, {2}, {3})", x, y, z, w);
        }
	};
    __declspec(selectany) const double4 double4::zero = double4(0, 0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-double4
        //=========================================================
        /// <summary>Returns a uint hash code of a double4 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const double4& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a double4 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const double4& v);

        /// <summary>Returns the result of specified shuffling of the components from two double4 vectors into a double value.</summary>
        /// <param name="left">double4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double.</param>
        /// <returns>double result of the shuffle operation.</returns>
        double shuffle(const double4& left, const double4& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two double4 vectors into a double2 vector.</summary>
        /// <param name="left">double4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double2 y component.</param>
        /// <returns>double2 result of the shuffle operation.</returns>
        double2 shuffle(const double4& left, const double4& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two double4 vectors into a double3 vector.</summary>
        /// <param name="left">double4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting double3 z component.</param>
        /// <returns>double3 result of the shuffle operation.</returns>
        double3 shuffle(const double4& left, const double4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two double4 vectors into a double4 vector.</summary>
        /// <param name="left">double4 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double4 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting double4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting double4 w component.</param>
        /// <returns>double4 result of the shuffle operation.</returns>
        double4 shuffle(const double4& left, const double4& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

