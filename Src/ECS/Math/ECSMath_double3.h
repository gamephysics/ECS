#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/double3.gen.cs
#pragma pack(push,1)
	struct double3
	{
	public:
		static const  double3	zero;
        union {
            struct { double x, y, z; };
            double        data[3];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        double3() : x(0), y(0), z(0)                                    {}
		double3(double _x, double _y, double _z) : x(_x), y(_y), z(_z)  {}
        double3(double _x, const double2& _yz)             {   x = _x;         y = _yz.x;      z = _yz.y;  }
        double3(const double2& _xy, double _z)             {   x = _xy.x;      y = _xy.y;      z = _z;     }

        double3(bool v)                             {   x = v ? 1.0 : 0.0;  y = v ? 1.0 : 0.0;  z = v ? 1.0 : 0.0;  }
        double3(uint v)                             {   x = v;          y = v;          z = v;      }
        double3(int v)                              {   x = v;          y = v;          z = v;      }
        //double3(half v)                           {   x = v;          y = v;          z = v;      }
        double3(float v)                            {   x = v;          y = v;          z = v;      }
        double3(double v)                           {   x = v;          y = v;          z = v;      }

        double3(const bool3& v);
        double3(const uint3& v);
        double3(const int3& v);
        //double3(const half3& v);
        double3(const float3& v);
        double3(const double3& v);
        		
        //=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        double3& operator = (const double3& rhs) { this->x = rhs.x;  this->y = rhs.y;  this->z = rhs.z;  return (*this); }
		// addition assignment	            a += b	
        double3& operator +=(const double3& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; return (*this); }
		// subtraction assignment	        a -= b	
        double3& operator -=(const double3& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; return (*this); }
		// multiplication assignment	    a *= b	
        double3& operator *=(const double3& rhs) { this->x *= rhs.x; this->y *= rhs.y; this->z *= rhs.z; return (*this); }
		// division assignment	            a /= b	
        double3& operator /=(const double3& rhs) { this->x /= rhs.x; this->y /= rhs.y; this->z /= rhs.z; return (*this); }
		// modulo assignment	            a %= b	
		double3& operator %=(const double3& rhs) { this->x = std::fmod(this->x, rhs.x); this->y = std::fmod(this->y, rhs.y); this->z = std::fmod(this->z, rhs.z); return (*this); }
		
        // bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
        double3& operator ++ ()                         { ++this->x; ++this->y; ++this->z; return (*this); }
		// pre - decrement  : 	--a		T&
        double3& operator -- ()                         { --this->x; --this->y; --this->z; return (*this); }
		// post-increment   : 	a++
        double3  operator ++ (int)                      { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
        double3  operator -- (int)                      { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
        double3  operator + () const                    { return double3(+this->x, +this->y, +this->z); }

		// unary minus      :   -a
        double3  operator - () const                    { return double3(-this->x, -this->y, -this->z); }

		// addition         :   a + b
        double3  operator + (const double3& rhs)const   { return double3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z); }
        double3  operator + (double rhs)        const   { return double3(this->x + rhs, this->y + rhs, this->z + rhs); }
        friend double3 operator + (double lhs, const double3& rhs) { return double3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z); }

        // subtraction      :   a - b
        double3  operator - (const double3& rhs)const   { return double3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z); }
        double3  operator - (double rhs)        const   { return double3(this->x - rhs, this->y - rhs, this->z - rhs); }
        friend double3 operator - (double lhs, const double3& rhs) { return double3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z); }

		// multiplication   :   a * b
        double3  operator * (const double3& rhs)const   { return double3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z); }
        double3  operator * (double rhs)        const   { return double3(this->x * rhs, this->y * rhs, this->z * rhs); }
        friend double3 operator * (double lhs, const double3& rhs) { return double3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }

		// division         :   a / b
        double3  operator / (const double3& rhs)const   { return double3(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z); }
        double3  operator / (double rhs)        const   { return double3(this->x / rhs, this->y / rhs, this->z / rhs); }
        friend double3 operator / (double lhs, const double3& rhs) { return double3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z); }

		// modulo           :   a % b
        double3  operator % (const double3& rhs)const   { return double3(std::fmod(this->x, rhs.x), std::fmod(this->y, rhs.y),  std::fmod(this->z, rhs.z)); }
        double3  operator % (double rhs)        const   { return double3(std::fmod(this->x, rhs),   std::fmod(this->y, rhs),    std::fmod(this->z, rhs)); }
        friend double3 operator % (double lhs, const double3& rhs) { return double3(std::fmod(lhs, rhs.x), std::fmod(lhs, rhs.y), std::fmod(lhs, rhs.z)); }

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
        bool3  operator == (const double3& rhs) const   { return bool3(this->x == rhs.x, this->y == rhs.y, this->z == rhs.z); }
        bool3  operator == (double rhs)         const   { return bool3(this->x == rhs, this->y == rhs, this->z == rhs); }
        friend bool3 operator == (double lhs, const double3& rhs) { return bool3(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z); }

        // not equal to     :   a != b
        bool3  operator != (const double3& rhs) const   { return bool3(this->x != rhs.x, this->y != rhs.y, this->z != rhs.z); }
        bool3  operator != (double rhs)         const   { return bool3(this->x != rhs, this->y != rhs, this->z != rhs); }
        friend bool3 operator != (double lhs, const double3& rhs) { return bool3(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z); }

		// less than        :   a < b
        bool3  operator < (const double3& rhs)  const   { return bool3(this->x < rhs.x, this->y < rhs.y, this->z < rhs.z); }
        bool3  operator < (double rhs)          const   { return bool3(this->x < rhs, this->y < rhs, this->z < rhs); }
        friend bool3 operator < (double lhs, const double3& rhs) { return bool3(lhs < rhs.x, lhs < rhs.y, lhs < rhs.z); }

		// greater than     :   a > b
        bool3  operator > (const double3& rhs)  const   { return bool3(this->x > rhs.x, this->y > rhs.y, this->z > rhs.z); }
        bool3  operator > (double rhs)          const   { return bool3(this->x > rhs, this->y > rhs, this->z > rhs); }
        friend bool3 operator > (double lhs, const double3& rhs) { return bool3(lhs > rhs.x, lhs > rhs.y, lhs > rhs.z); }

		// less than or equal to    : a <= b	
        bool3  operator <= (const double3& rhs) const   { return bool3(this->x <= rhs.x, this->y <= rhs.y, this->z <= rhs.z); }
        bool3  operator <= (double rhs)         const   { return bool3(this->x <= rhs, this->y <= rhs, this->z <= rhs); }
        friend bool3 operator <= (double lhs, const double3& rhs) { return bool3(lhs <= rhs.x, lhs <= rhs.y, lhs <= rhs.z); }

        // greater than or equal to : a >= b
        bool3  operator >= (const double3& rhs) const   { return bool3(this->x >= rhs.x, this->y >= rhs.y, this->z >= rhs.z); }
        bool3  operator >= (double rhs)         const   { return bool3(this->x >= rhs, this->y >= rhs, this->z >= rhs); }
        friend bool3 operator >= (double lhs, const double3& rhs) { return bool3(lhs >= rhs.x, lhs >= rhs.y, lhs >= rhs.z); }

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
			if (index >= 3)
				throw std::exception("index must be between[0...2]");
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
        double4 xxyx()  const;
        double4 xxyy()  const;
        double4 xxyz()  const;
        double4 xxzx()  const;
        double4 xxzy()  const;
        double4 xxzz()  const;
        double4 xyxx()  const;
        double4 xyxy()  const;
        double4 xyxz()  const;
        double4 xyyx()  const;
        double4 xyyy()  const;
        double4 xyyz()  const;
        double4 xyzx()  const;
        double4 xyzy()  const;
        double4 xyzz()  const;
        double4 xzxx()  const;
        double4 xzxy()  const;
        double4 xzxz()  const;
        double4 xzyx()  const;
        double4 xzyy()  const;
        double4 xzyz()  const;
        double4 xzzx()  const;
        double4 xzzy()  const;
        double4 xzzz()  const;
        double4 yxxx()  const;
        double4 yxxy()  const;
        double4 yxxz()  const;
        double4 yxyx()  const;
        double4 yxyy()  const;
        double4 yxyz()  const;
        double4 yxzx()  const;
        double4 yxzy()  const;
        double4 yxzz()  const;
        double4 yyxx()  const;
        double4 yyxy()  const;
        double4 yyxz()  const;
        double4 yyyx()  const;
        double4 yyyy()  const;
        double4 yyyz()  const;
        double4 yyzx()  const;
        double4 yyzy()  const;
        double4 yyzz()  const;
        double4 yzxx()  const;
        double4 yzxy()  const;
        double4 yzxz()  const;
        double4 yzyx()  const;
        double4 yzyy()  const;
        double4 yzyz()  const;
        double4 yzzx()  const;
        double4 yzzy()  const;
        double4 yzzz()  const;
        double4 zxxx()  const;
        double4 zxxy()  const;
        double4 zxxz()  const;
        double4 zxyx()  const;
        double4 zxyy()  const;
        double4 zxyz()  const;
        double4 zxzx()  const;
        double4 zxzy()  const;
        double4 zxzz()  const;
        double4 zyxx()  const;
        double4 zyxy()  const;
        double4 zyxz()  const;
        double4 zyyx()  const;
        double4 zyyy()  const;
        double4 zyyz()  const;
        double4 zyzx()  const;
        double4 zyzy()  const;
        double4 zyzz()  const;
        double4 zzxx()  const;
        double4 zzxy()  const;
        double4 zzxz()  const;
        double4 zzyx()  const;
        double4 zzyy()  const;
        double4 zzyz()  const;
        double4 zzzx()  const;
        double4 zzzy()  const;
        double4 zzzz()  const;
        double3 xxx()   const;
        double3 xxy()   const;
        double3 xxz()   const;
        double3 xyx()   const;
        double3 xyy()   const;
        double3 xyz()   const;
        void    xyz(const double3& v);
        double3 xzx()   const;
        double3 xzy()   const;
        void    xzy(const double3& v);
        double3 xzz()   const;
        double3 yxx()   const;
        double3 yxy()   const;
        double3 yxz()   const;
        void    yxz(const double3& v);
        double3 yyx()   const;
        double3 yyy()   const;
        double3 yyz()   const;
        double3 yzx()   const;
        void    yzx(const double3& v);
        double3 yzy()   const;
        double3 yzz()   const;
        double3 zxx()   const;
        double3 zxy()   const;
        void    zxy(const double3& v);
        double3 zxz()   const;
        double3 zyx()   const;
        void    zyx(const double3& v);
        double3 zyy()   const;
        double3 zyz()   const;
        double3 zzx()   const;
        double3 zzy()   const;
        double3 zzz()   const;
        double2 xx()    const;
        double2 xy()    const;
        void    xy(const double2& v);
        double2 xz()    const;
        void    xz(const double2& v);
        double2 yx()    const;
        void    yx(const double2& v);
        double2 yy()    const;
        double2 yz()    const;
        void    yz(const double2& v);
        double2 zx()    const;
        void    zx(const double2& v);
        double2 zy()    const;
        void    zy(const double2& v);
        double2 zz()    const;

		//=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the double3 is equal to a given double3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const double3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

        /// <summary>Returns true if the double3 is equal to a given double3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is double3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the double3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the double3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("double3({0}, {1}, {2})", x, y, z);
        }
	};
    __declspec(selectany) const double3 double3::zero = double3(0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-double3
        //=========================================================
        /// <summary>Returns a uint hash code of a double3 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const double3& v);

        /// <summary>
        /// Returns a uint3 vector hash code of a double3 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(const double3& v);

        /// <summary>Returns the result of specified shuffling of the components from two double3 vectors into a double value.</summary>
        /// <param name="left">double3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double.</param>
        /// <returns>double result of the shuffle operation.</returns>
        double shuffle(const double3& left, const double3& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two double3 vectors into a double2 vector.</summary>
        /// <param name="left">double3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double2 y component.</param>
        /// <returns>double2 result of the shuffle operation.</returns>
        double2 shuffle(const double3& left, const double3& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two double3 vectors into a double3 vector.</summary>
        /// <param name="left">double3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting double3 z component.</param>
        /// <returns>double3 result of the shuffle operation.</returns>
        double3 shuffle(const double3& left, const double3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two double3 vectors into a double4 vector.</summary>
        /// <param name="left">double3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting double4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting double4 w component.</param>
        /// <returns>double4 result of the shuffle operation.</returns>
        double4 shuffle(const double3& left, const double3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

