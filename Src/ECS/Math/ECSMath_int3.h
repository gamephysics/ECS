#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/int3.gen.cs
#pragma pack(push,1)
	struct int3
	{
	public:
		static const  int3	zero;
        union {
            struct { int x, y, z; };
            int        data[3];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        int3() : x(0), y(0), z(0)                           {}
        int3(int _x, int _y, int _z) : x(_x), y(_y), z(_z)  {}
        int3(int _x, const int2& _yz)   {   x = _x;         y = _yz.x;      z = _yz.y;  }
        int3(const int2& _xy, int _z)   {   x = _xy.x;      y = _xy.y;      z = _z;     }

        int3(bool v)                    {   x = v ? 1 : 0;      y = v ? 1 : 0;      z = v ? 1 : 0;      }
        int3(uint v)                    {   x = (int)v;     y = (int)v;     z = (int)v;     }
        int3(int v)                     {   x = v;          y = v;          z = v;          }
        int3(float v)                   {   x = (int)v;     y = (int)v;     z = (int)v;     }
        int3(double v)                  {   x = (int)v;     y = (int)v;     z = (int)v;     }

        int3(const bool3& v);
        int3(const uint3& v);
        int3(const int3& v);
        int3(const float3& v);
        int3(const double3& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        int3& operator = (const int3& rhs) { this->x = rhs.x;  this->y = rhs.y;  this->z = rhs.z;  return (*this); }
		// addition assignment	            a += b	
        int3& operator +=(const int3& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; return (*this); }
		// subtraction assignment	        a -= b	
        int3& operator -=(const int3& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; return (*this); }
		// multiplication assignment	    a *= b	
        int3& operator *=(const int3& rhs) { this->x *= rhs.x; this->y *= rhs.y; this->z *= rhs.z; return (*this); }
		// division assignment	            a /= b	
        int3& operator /=(const int3& rhs) { this->x /= rhs.x; this->y /= rhs.y; this->z /= rhs.z; return (*this); }
		// modulo assignment	            a %= b	
        int3& operator %=(const int3& rhs) { this->x %= rhs.x; this->y %= rhs.y; this->z %= rhs.z; return (*this); }
		
        // bitwise AND assignment	        a &= b	
        int3& operator &=(const int3& rhs) { this->x &= rhs.x; this->y &= rhs.y; this->z &= rhs.z; return (*this); }
		// bitwise OR assignment	        a |= b	
        int3& operator |=(const int3& rhs) { this->x |= rhs.x; this->y |= rhs.y; this->z |= rhs.z; return (*this); }
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
        int3& operator ++ ()                        { ++this->x; ++this->y; ++this->z; return (*this);     }
        // pre - decrement  : 	--a		T&
        int3& operator -- ()                        { --this->x; --this->y; --this->z; return (*this);     }
        // post-increment   : 	a++
        int3  operator ++ (int)                     { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        int3  operator -- (int)                     { auto temp = *this; --(*this); return (temp); }

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
        int3 operator + () const                    { return int3(+this->x, +this->y, +this->z); }

        // unary minus      :   -a
        int3 operator - () const                    { return int3(-this->x, -this->y, -this->z); }

		// addition         :   a + b
        int3 operator + (const int3& rhs)   const   { return int3(this->x + rhs.x,  this->y + rhs.y,    this->z + rhs.z); }
        int3 operator + (int rhs)           const   { return int3(this->x + rhs,    this->y + rhs,      this->z + rhs); }
        friend int3  operator + (int lhs, const int3& rhs) { return int3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z); }
        
		// subtraction      :   a - b
        int3 operator - (const int3& rhs)   const   { return int3(this->x - rhs.x,  this->y - rhs.y,    this->z - rhs.z); }
        int3 operator - (int rhs)           const   { return int3(this->x - rhs,    this->y - rhs,      this->z - rhs); }
        friend int3  operator - (int lhs, const int3& rhs) { return int3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z); }

		// multiplication   :   a * b
        int3 operator * (const int3& rhs)   const   { return int3(this->x * rhs.x,  this->y * rhs.y,    this->z * rhs.z); }
        int3 operator * (int rhs)           const   { return int3(this->x * rhs,    this->y * rhs,      this->z * rhs); }
        friend int3  operator * (int lhs, const int3& rhs) { return int3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }

		// division         :   a / b
        int3 operator / (const int3& rhs)   const   { return int3(this->x / rhs.x,  this->y / rhs.y,    this->z / rhs.z); }
        int3 operator / (int rhs)           const   { return int3(this->x / rhs,    this->y / rhs,      this->z / rhs); }
        friend int3  operator / (int lhs, const int3& rhs) { return int3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z); }

		// modulo           :   a % b
        int3 operator % (const int3& rhs)   const   { return int3(this->x % rhs.x,  this->y % rhs.y,    this->z % rhs.z); }
        int3 operator % (int rhs)           const   { return int3(this->x % rhs,    this->y % rhs,      this->z % rhs); }
        friend int3  operator % (int lhs, const int3& rhs) { return int3(lhs % rhs.x, lhs % rhs.y, lhs % rhs.z); }

		// bitwise NOT      :   ~a
        int3 operator ~ ()                  const   { return int3(~this->x, ~this->y, ~this->z); }

		// bitwise AND      :   a & b
        int3 operator & (const int3& rhs)   const   { return int3(this->x & rhs.x,  this->y & rhs.y,    this->z & rhs.z); }
        int3 operator & (int rhs)           const   { return int3(this->x & rhs,    this->y & rhs,      this->z & rhs); }
        friend int3  operator & (int lhs, const int3& rhs) { return int3(lhs & rhs.x, lhs & rhs.y, lhs & rhs.z); }

		// bitwise OR       :   a | b
        int3 operator | (const int3& rhs)   const   { return int3(this->x | rhs.x,  this->y | rhs.y,    this->z | rhs.z); }
        int3 operator | (int rhs)           const   { return int3(this->x | rhs,    this->y | rhs,      this->z | rhs); }
        friend int3  operator | (int lhs, const int3& rhs) { return int3(lhs | rhs.x, lhs | rhs.y, lhs | rhs.z); }

		// bitwise XOR      :   a ^ b
        int3 operator ^ (const int3& rhs)   const   { return int3(this->x ^ rhs.x,  this->y ^ rhs.y,    this->z ^ rhs.z); }
        int3 operator ^ (int rhs)           const   { return int3(this->x ^ rhs,    this->y ^ rhs,      this->z ^ rhs); }
        friend int3  operator ^ (int lhs, const int3& rhs) { return int3(lhs ^ rhs.x, lhs ^ rhs.y, lhs ^ rhs.z); }

        // bitwise left shift : a << b
        int3 operator << (int n) const              { return int3(this->x << n, this->y << n, this->z << n); }

        // bitwise right shift: a >> b
        int3 operator >> (int n) const              { return int3(this->x >> n, this->y >> n, this->z >> n); }


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
        bool3 operator == (const int3& rhs) const   { return bool3(this->x == rhs.x,this->y == rhs.y,   this->z == rhs.z); }
        bool3 operator == (int rhs)         const   { return bool3(this->x == rhs,  this->y == rhs,     this->z == rhs); }
        friend bool3 operator ==(int lhs, const int3& rhs) { return bool3(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z); }

		// not equal to     :   a != b
        bool3 operator != (const int3& rhs) const   { return bool3(this->x != rhs.x,this->y != rhs.y,   this->z != rhs.z); }
        bool3 operator != (int rhs)         const   { return bool3(this->x != rhs,  this->y != rhs,     this->z != rhs); }
        friend bool3 operator !=(int lhs, const int3& rhs) { return bool3(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z); }

		// less than        :   a < b
        bool3 operator < (const int3& rhs)  const   { return bool3(this->x < rhs.x, this->y < rhs.y,    this->z < rhs.z); }
        bool3 operator < (int rhs)          const   { return bool3(this->x < rhs,   this->y < rhs,      this->z < rhs); }
        friend bool3 operator < (int lhs, const int3& rhs) { return bool3(lhs < rhs.x, lhs < rhs.y, lhs < rhs.z); }
        
		// greater than     :   a > b
        bool3 operator > (const int3& rhs)  const   { return bool3(this->x > rhs.x, this->y > rhs.y,    this->z > rhs.z); }
        bool3 operator > (int rhs)          const   { return bool3(this->x > rhs,   this->y > rhs,      this->z > rhs); }
        friend bool3 operator > (int lhs, const int3& rhs) { return bool3(lhs > rhs.x, lhs > rhs.y, lhs > rhs.z); }

		// less than or equal to    : a <= b	
        bool3 operator <= (const int3& rhs) const   { return bool3(this->x <= rhs.x,this->y <= rhs.y,   this->z <= rhs.z); }
        bool3 operator <= (int rhs)         const   { return bool3(this->x <= rhs,  this->y <= rhs,     this->z <= rhs); }
        friend bool3 operator <=(int lhs, const int3& rhs) { return bool3(lhs <= rhs.x, lhs <= rhs.y, lhs <= rhs.z); }

        // greater than or equal to : a >= b
        bool3 operator >= (const int3& rhs) const   { return bool3(this->x >= rhs.x,this->y >= rhs.y,   this->z >= rhs.z); }
        bool3 operator >= (int rhs)         const   { return bool3(this->x >= rhs,  this->y >= rhs,     this->z >= rhs); }
        friend bool3 operator >=(int lhs, const int3& rhs) { return bool3(lhs >= rhs.x, lhs >= rhs.y, lhs >= rhs.z); }

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
            if (index >= 3)
                throw std::exception("index must be between[0...2]");
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
        int4 xxyx() const;
        int4 xxyy() const;
        int4 xxyz() const;
        int4 xxzx() const;
        int4 xxzy() const;
        int4 xxzz() const;
        int4 xyxx() const;
        int4 xyxy() const;
        int4 xyxz() const;
        int4 xyyx() const;
        int4 xyyy() const;
        int4 xyyz() const;
        int4 xyzx() const;
        int4 xyzy() const;
        int4 xyzz() const;
        int4 xzxx() const;
        int4 xzxy() const;
        int4 xzxz() const;
        int4 xzyx() const;
        int4 xzyy() const;
        int4 xzyz() const;
        int4 xzzx() const;
        int4 xzzy() const;
        int4 xzzz() const;
        int4 yxxx() const;
        int4 yxxy() const;
        int4 yxxz() const;
        int4 yxyx() const;
        int4 yxyy() const;
        int4 yxyz() const;
        int4 yxzx() const;
        int4 yxzy() const;
        int4 yxzz() const;
        int4 yyxx() const;
        int4 yyxy() const;
        int4 yyxz() const;
        int4 yyyx() const;
        int4 yyyy() const;
        int4 yyyz() const;
        int4 yyzx() const;
        int4 yyzy() const;
        int4 yyzz() const;
        int4 yzxx() const;
        int4 yzxy() const;
        int4 yzxz() const;
        int4 yzyx() const;
        int4 yzyy() const;
        int4 yzyz() const;
        int4 yzzx() const;
        int4 yzzy() const;
        int4 yzzz() const;
        int4 zxxx() const;
        int4 zxxy() const;
        int4 zxxz() const;
        int4 zxyx() const;
        int4 zxyy() const;
        int4 zxyz() const;
        int4 zxzx() const;
        int4 zxzy() const;
        int4 zxzz() const;
        int4 zyxx() const;
        int4 zyxy() const;
        int4 zyxz() const;
        int4 zyyx() const;
        int4 zyyy() const;
        int4 zyyz() const;
        int4 zyzx() const;
        int4 zyzy() const;
        int4 zyzz() const;
        int4 zzxx() const;
        int4 zzxy() const;
        int4 zzxz() const;
        int4 zzyx() const;
        int4 zzyy() const;
        int4 zzyz() const;
        int4 zzzx() const;
        int4 zzzy() const;
        int4 zzzz() const;
        int3 xxx()  const;
        int3 xxy()  const;
        int3 xxz()  const;
        int3 xyx()  const;
        int3 xyy()  const;
        int3 xyz()  const;
		void xyz(const int3& v);
        int3 xzx()  const;
        int3 xzy()  const;
		void xzy(const int3& v);
        int3 xzz()  const;
        int3 yxx()  const;
        int3 yxy()  const;
        int3 yxz()  const;
		void yxz(const int3& v);
        int3 yyx()  const;
        int3 yyy()  const;
        int3 yyz()  const;
        int3 yzx()  const;
		void yzx(const int3& v);
        int3 yzy()  const;
        int3 yzz()  const;
        int3 zxx()  const;
        int3 zxy()  const;
		void zxy(const int3& v);
        int3 zxz()  const;
        int3 zyx()  const;
		void zyx(const int3& v);
        int3 zyy()  const;
        int3 zyz()  const;
        int3 zzx()  const;
        int3 zzy()  const;
        int3 zzz()  const;
        int2 xx()   const;
        int2 xy()   const;
		void xy(const int2& v)  ;
        int2 xz()   const;
		void xz(const int2& v);
        int2 yx()   const;
		void yx(const int2& v);
        int2 yy()   const;
        int2 yz()   const;
		void yz(const int2& v);
        int2 zx()   const;
		void zx(const int2& v);
        int2 zy()   const;
		void zy(const int2& v);
        int2 zz()   const;
        

        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the int3 is equal to a given int3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const int3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

        /// <summary>Returns true if the int3 is equal to a given int3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is int3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the int3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the int3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("int3({0}, {1}, {2})", x, y, z);
        }
	};
    __declspec(selectany) const int3    int3::zero = int3(0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-int3
        //=========================================================
        /// <summary>Returns a uint hash code of a int3 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const int3& v);

        /// <summary>
        /// Returns a uint3 vector hash code of a int3 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(const int3& v);

        /// <summary>Returns the result of specified shuffling of the components from two int3 vectors into an int value.</summary>
        /// <param name="left">int3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int.</param>
        /// <returns>int result of the shuffle operation.</returns>
        int shuffle(const int3& left, const int3& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two int3 vectors into an int2 vector.</summary>
        /// <param name="left">int3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int2 y component.</param>
        /// <returns>int2 result of the shuffle operation.</returns>
        int2 shuffle(const int3& left, const int3& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two int3 vectors into an int3 vector.</summary>
        /// <param name="left">int3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting int3 z component.</param>
        /// <returns>int3 result of the shuffle operation.</returns>
        int3 shuffle(const int3& left, const int3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two int3 vectors into an int4 vector.</summary>
        /// <param name="left">int3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting int4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting int4 w component.</param>
        /// <returns>int4 result of the shuffle operation.</returns>
        int4 shuffle(const int3& left, const int3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

