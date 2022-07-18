#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/uint3.gen.cs
#pragma pack(push,1)
	struct uint3
	{
	public:
		static const  uint3	zero;
        union {
            struct { uint x, y, z; };
            uint        data[3];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        uint3() : x(0), y(0), z(0)                              {}
		uint3(uint _x, uint _y, uint _z) : x(_x), y(_y), z(_z)  {}
        uint3(uint _x, const uint2& _yz)            { x = x;                y = _yz.x;          z = _yz.y;          }
        uint3(const uint2& _xy, uint _z)            { x = _xy.x;            y = _xy.y;          z = _z;             }

        uint3(bool v)                               { x = v ? 1u : 0u;      y = v ? 1u : 0u;    z = v ? 1u : 0u;    }
        uint3(uint v)                               { x = v;                y = v;              z = v;              }
        uint3(int v)                                { x = (uint)v;          y = (uint)v;        z = (uint)v;        }
        uint3(float v)                              { x = (uint)v;          y = (uint)v;        z = (uint)v;        }
        uint3(double v)                             { x = (uint)v;          y = (uint)v;        z = (uint)v;        }

        uint3(const bool3& v);
        uint3(const uint3& _xyz);
        uint3(const int3& v);
        uint3(const float3& v);
        uint3(const double3& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        uint3& operator = (const uint3& rhs) { this->x = rhs.x;  this->y = rhs.y;  this->z = rhs.z;  return (*this); }
		// addition assignment	            a += b	
        uint3& operator +=(const uint3& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; return (*this); }
		// subtraction assignment	        a -= b	
        uint3& operator -=(const uint3& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; return (*this); }
		// multiplication assignment	    a *= b	
        uint3& operator *=(const uint3& rhs) { this->x *= rhs.x; this->y *= rhs.y; this->z *= rhs.z; return (*this); }
		// division assignment	            a /= b	
        uint3& operator /=(const uint3& rhs) { this->x /= rhs.x; this->y /= rhs.y; this->z /= rhs.z; return (*this); }
		// modulo assignment	            a %= b	
        uint3& operator %=(const uint3& rhs) { this->x %= rhs.x; this->y %= rhs.y; this->z %= rhs.z; return (*this); }
		
        // bitwise AND assignment	        a &= b	
        uint3& operator &=(const uint3& rhs) { this->x &= rhs.x; this->y &= rhs.y; this->z &= rhs.z; return (*this); }
		// bitwise OR assignment	        a |= b	
        uint3& operator |=(const uint3& rhs) { this->x |= rhs.x; this->y |= rhs.y; this->z |= rhs.z; return (*this); }
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
        // pre-increment    : 	++a		T&
        uint3& operator ++ ()                       { ++this->x; ++this->y; ++this->z; return (*this);     }
        // pre - decrement  : 	--a		T&
        uint3& operator -- ()                       { --this->x; --this->y; --this->z; return (*this);     }
        // post-increment   : 	a++
        uint3  operator ++ (int)                    { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        uint3  operator -- (int)                    { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
        uint3 operator + () const                   { return uint3(+this->x, +this->y, +this->z); }

		// unary minus      :   -a
        uint3 operator - () const                   { throw std::runtime_error("unsigned cannot convert minus value"); }//{ return uint3(-this->x, -this->y, -this->z); }

		// addition         :   a + b
        uint3 operator + (const uint3& rhs) const   { return uint3(this->x + rhs.x,     this->y + rhs.y,    this->z + rhs.z); }
        uint3 operator + (uint rhs)         const   { return uint3(this->x + rhs,       this->y + rhs,      this->z + rhs); }
        friend uint3 operator +  (uint lhs, const uint3& rhs) { return uint3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z); }

		// subtraction      :   a - b
		uint3 operator - (const uint3& rhs) const   { return uint3(this->x - rhs.x,     this->y - rhs.y,    this->z - rhs.z); }
		uint3 operator - (uint rhs)         const   { return uint3(this->x - rhs,       this->y - rhs,      this->z - rhs); }
        friend uint3 operator -  (uint lhs, const uint3& rhs) { return uint3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z); }

		// multiplication   :   a * b
		uint3 operator * (const uint3& rhs) const   { return uint3(this->x * rhs.x,     this->y * rhs.y,    this->z * rhs.z); }
		uint3 operator * (uint rhs)         const   { return uint3(this->x * rhs,       this->y * rhs,      this->z * rhs); }
        friend uint3 operator *  (uint lhs, const uint3& rhs) { return uint3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }

		// division         :   a / b
        uint3 operator / (const uint3& rhs) const   { return uint3(this->x / rhs.x,     this->y / rhs.y,    this->z / rhs.z); }
        uint3 operator / (uint rhs)         const   { return uint3(this->x / rhs,       this->y / rhs,      this->z / rhs); }
        friend uint3 operator /  (uint lhs, const uint3& rhs) { return uint3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z); }

		// modulo           :   a % b
        uint3 operator % (const uint3& rhs) const   { return uint3(this->x % rhs.x,     this->y % rhs.y,    this->z % rhs.z); }
        uint3 operator % (uint rhs)         const   { return uint3(this->x % rhs,       this->y % rhs,      this->z % rhs); }
        friend uint3 operator %  (uint lhs, const uint3& rhs) { return uint3(lhs % rhs.x, lhs % rhs.y, lhs % rhs.z); }

		// bitwise NOT      :   ~a
        uint3 operator ~ ()    const                { return uint3(~this->x, ~this->y, ~this->z); }

		// bitwise AND      :   a & b
		uint3 operator & (const uint3& rhs) const   { return uint3(this->x & rhs.x,     this->y & rhs.y,    this->z & rhs.z); }
		uint3 operator & (uint rhs)         const   { return uint3(this->x & rhs,       this->y & rhs,      this->z & rhs); }
        friend uint3 operator &  (uint lhs, const uint3& rhs) { return uint3(lhs & rhs.x, lhs & rhs.y, lhs & rhs.z); }

		// bitwise OR       :   a | b
		uint3 operator | (const uint3& rhs) const   { return uint3(this->x | rhs.x,     this->y | rhs.y,    this->z | rhs.z); }
		uint3 operator | (uint rhs)         const   { return uint3(this->x | rhs,       this->y | rhs,      this->z | rhs); }
        friend uint3 operator |  (uint lhs, const uint3& rhs) { return uint3(lhs | rhs.x, lhs | rhs.y, lhs | rhs.z); }

		// bitwise XOR      :   a ^ b
		uint3 operator ^ (const uint3& rhs) const   { return uint3(this->x ^ rhs.x,     this->y ^ rhs.y,    this->z ^ rhs.z); }
		uint3 operator ^ (uint rhs)         const   { return uint3(this->x ^ rhs,       this->y ^ rhs,      this->z ^ rhs); }
        friend uint3 operator ^  (uint lhs, const uint3& rhs) { return uint3(lhs ^ rhs.x, lhs ^ rhs.y, lhs ^ rhs.z); }

		// bitwise left shift : a << b
        uint3 operator << (int n) const { return uint3(this->x << n, this->y << n, this->z << n); }

		// bitwise right shift: a >> b
        uint3 operator >> (int n) const { return uint3(this->x >> n, this->y >> n, this->z >> n); }

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
        bool3 operator == (const uint3& rhs)const   { return bool3(this->x == rhs.x,    this->y == rhs.y,   this->z == rhs.z); }
        bool3 operator == (uint rhs)        const   { return bool3(this->x == rhs,      this->y == rhs,     this->z == rhs); }
        friend bool3 operator == (uint lhs, const uint3& rhs) { return bool3(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z); }

		// not equal to     :   a != b
		bool3 operator != (const uint3& rhs)const   { return bool3(this->x != rhs.x,    this->y != rhs.y,   this->z != rhs.z); }
		bool3 operator != (uint rhs)        const   { return bool3(this->x != rhs,      this->y != rhs,     this->z != rhs); }
        friend bool3 operator != (uint lhs, const uint3& rhs) { return bool3(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z); }

		// less than        :   a < b
        bool3 operator < (const uint3& rhs)const    { return bool3(this->x < rhs.x,     this->y < rhs.y,    this->z < rhs.z); }
        bool3 operator < (uint rhs)        const    { return bool3(this->x < rhs,       this->y < rhs,      this->z < rhs); }
        friend bool3 operator <  (uint lhs, const uint3& rhs) { return bool3(lhs < rhs.x, lhs < rhs.y, lhs < rhs.z); }

		// greater than     :   a > b
		bool3 operator > (const uint3& rhs) const   { return bool3(this->x > rhs.x,     this->y > rhs.y,    this->z > rhs.z); }
		bool3 operator > (uint rhs)         const   { return bool3(this->x > rhs,       this->y > rhs,      this->z > rhs); }
        friend bool3 operator >  (uint lhs, const uint3& rhs) { return bool3(lhs > rhs.x, lhs > rhs.y, lhs > rhs.z); }

        // less than or equal to    : a <= b	
		bool3 operator <= (const uint3& rhs)const   { return bool3(this->x <= rhs.x,    this->y <= rhs.y,   this->z <= rhs.z); }
		bool3 operator <= (uint rhs)        const   { return bool3(this->x <= rhs,      this->y <= rhs,     this->z <= rhs); }
        friend bool3 operator <= (uint lhs, const uint3& rhs) { return bool3(lhs <= rhs.x, lhs <= rhs.y, lhs <= rhs.z); }

		// greater than or equal to : a >= b
		bool3 operator >= (const uint3& rhs)const   { return bool3(this->x >= rhs.x,    this->y >= rhs.y,   this->z >= rhs.z); }
		bool3 operator >= (uint rhs)        const   { return bool3(this->x >= rhs,      this->y >= rhs,     this->z >= rhs); }
        friend bool3 operator >= (uint lhs, const uint3& rhs) { return bool3(lhs >= rhs.x, lhs >= rhs.y, lhs >= rhs.z); }

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
            if (index >= 3)
                throw std::exception("index must be between[0...2]");
#endif
            return data[index];
        }

        //=========================================================
        // Getter/Setter
        //=========================================================
        /// <summary>Swizzles the vector.</summary>
        uint4 xxxx() const;
        uint4 xxxy() const;
        uint4 xxxz() const;
        uint4 xxyx() const;
        uint4 xxyy() const;
        uint4 xxyz() const;
        uint4 xxzx() const;
        uint4 xxzy() const;
        uint4 xxzz() const;
        uint4 xyxx() const;
        uint4 xyxy() const;
        uint4 xyxz() const;
        uint4 xyyx() const;
        uint4 xyyy() const;
        uint4 xyyz() const;
        uint4 xyzx() const;
        uint4 xyzy() const;
        uint4 xyzz() const;
        uint4 xzxx() const;
        uint4 xzxy() const;
        uint4 xzxz() const;
        uint4 xzyx() const;
        uint4 xzyy() const;
        uint4 xzyz() const;
        uint4 xzzx() const;
        uint4 xzzy() const;
        uint4 xzzz() const;
        uint4 yxxx() const;
        uint4 yxxy() const;
        uint4 yxxz() const;
        uint4 yxyx() const;
        uint4 yxyy() const;
        uint4 yxyz() const;
        uint4 yxzx() const;
        uint4 yxzy() const;
        uint4 yxzz() const;
        uint4 yyxx() const;
        uint4 yyxy() const;
        uint4 yyxz() const;
        uint4 yyyx() const;
        uint4 yyyy() const;
        uint4 yyyz() const;
        uint4 yyzx() const;
        uint4 yyzy() const;
        uint4 yyzz() const;
        uint4 yzxx() const;
        uint4 yzxy() const;
        uint4 yzxz() const;
        uint4 yzyx() const;
        uint4 yzyy() const;
        uint4 yzyz() const;
        uint4 yzzx() const;
        uint4 yzzy() const;
        uint4 yzzz() const;
        uint4 zxxx() const;
        uint4 zxxy() const;
        uint4 zxxz() const;
        uint4 zxyx() const;
        uint4 zxyy() const;
        uint4 zxyz() const;
        uint4 zxzx() const;
        uint4 zxzy() const;
        uint4 zxzz() const;
        uint4 zyxx() const;
        uint4 zyxy() const;
        uint4 zyxz() const;
        uint4 zyyx() const;
        uint4 zyyy() const;
        uint4 zyyz() const;
        uint4 zyzx() const;
        uint4 zyzy() const;
        uint4 zyzz() const;
        uint4 zzxx() const;
        uint4 zzxy() const;
        uint4 zzxz() const;
        uint4 zzyx() const;
        uint4 zzyy() const;
        uint4 zzyz() const;
        uint4 zzzx() const;
        uint4 zzzy() const;
        uint4 zzzz() const;
        uint3 xxx()  const;
        uint3 xxy()  const;
        uint3 xxz()  const;
        uint3 xyx()  const;
        uint3 xyy()  const;
        uint3 xyz()  const;
        void  xyz(const uint3& v);
        uint3 xzx()  const;
        uint3 xzy()  const;
        void  xzy(const uint3& v);
        uint3 xzz()  const;
        uint3 yxx()  const;
        uint3 yxy()  const;
        uint3 yxz()  const;
        void  yxz(const uint3& v);
        uint3 yyx()  const;
        uint3 yyy()  const;
        uint3 yyz()  const;
        uint3 yzx()  const;
        void  yzx(const uint3& v);
        uint3 yzy()  const;
        uint3 yzz()  const;
        uint3 zxx()  const;
        uint3 zxy()  const;
        void  zxy(const uint3& v);
        uint3 zxz()  const;
        uint3 zyx()  const;
        void  zyx(const uint3& v);
        uint3 zyy()  const;
        uint3 zyz()  const;
        uint3 zzx()  const;
        uint3 zzy()  const;
        uint3 zzz()  const;
		uint2 xx()   const;
        uint2 xy()   const;
        void  xy(const uint2& v);
        uint2 xz()   const;
        void  xz(const uint2& v);
        uint2 yx()   const;
        void  yx(const uint2& v);
        uint2 yy()   const;
        uint2 yz()   const;
        void  yz(const uint2& v);
        uint2 zx()   const;
        void  zx(const uint2& v);
        uint2 zy()   const;
        void  zy(const uint2& v);
        uint2 zz()   const;

        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the uint3 is equal to a given uint3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const uint3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

        /// <summary>Returns true if the uint3 is equal to a given uint3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //bool Equals(object o) { return o is uint3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the uint3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the uint3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("uint3({0}, {1}, {2})", x, y, z);
        }
	};
    __declspec(selectany) const uint3   uint3::zero = uint3(0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-uint3
        //=========================================================
        /// <summary>Returns a uint hash code of a uint3 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(uint3 v);

        /// <summary>
        /// Returns a uint3 vector hash code of a uint3 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(uint3 v);

        /// <summary>Returns the result of specified shuffling of the components from two uint3 vectors into a uint value.</summary>
        /// <param name="left">uint3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint.</param>
        /// <returns>uint result of the shuffle operation.</returns>
        uint shuffle(const uint3& left, const uint3& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two uint3 vectors into a uint2 vector.</summary>
        /// <param name="left">uint3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint2 y component.</param>
        /// <returns>uint2 result of the shuffle operation.</returns>
        uint2 shuffle(const uint3& left, const uint3& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two uint3 vectors into a uint3 vector.</summary>
        /// <param name="left">uint3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting uint3 z component.</param>
        /// <returns>uint3 result of the shuffle operation.</returns>
        uint3 shuffle(const uint3& left, const uint3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two uint3 vectors into a uint4 vector.</summary>
        /// <param name="left">uint3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting uint4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting uint4 w component.</param>
        /// <returns>uint4 result of the shuffle operation.</returns>
        uint4 shuffle(const uint3& left, const uint3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

