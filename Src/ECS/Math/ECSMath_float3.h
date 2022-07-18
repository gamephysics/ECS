#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float3.gen.cs
#pragma pack(push,1)
	struct float3
	{
	public:
		static const  float3	zero;
        static const  float3	one;
        union {
            struct { float x, y, z; };
            float        data[3];
        };


	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        float3() : x(0.f), y(0.f), z(0.f) {}
		float3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)  {}
        float3(float _x, float2 _yz)                {   x = _x;     y = _yz.x;  z = _yz.y;  }
        float3(float2 _xy, float _z)                {   x = _xy.x;  y = _xy.y;  z = _z;     }

        float3(bool v)                              {   x = v ? 1.0f : 0.0f;    y = v ? 1.0f : 0.0f;    z = v ? 1.0f : 0.0f;    }
        float3(uint v)                              {   x = (float)v;           y = (float)v;           z = (float)v;           }
        float3(int v)                               {   x = (float)v;           y = (float)v;           z = (float)v;           }
        //float3(half v)                            {   x = v;                  y = v;                  z = v;                  }
        float3(float v)                             {   x = v;      y = v;      z = v;      }
        float3(double v)                            {   x = (float)v;           y = (float)v;           z = (float)v;           }

        float3(const bool3& v);
        float3(const uint3& v);
        float3(const int3& v);
        //float3(const half3& v);
        float3(const float3& v);
        float3(const double3& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        float3& operator = (const float3& rhs) { this->x = rhs.x;  this->y = rhs.y;  this->z = rhs.z;  return (*this); }
		// addition assignment	            a += b	
        float3& operator +=(const float3& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; return (*this); }
		// subtraction assignment	        a -= b	
        float3& operator -=(const float3& rhs) { this->x -= rhs.x; this->y -= rhs.y; this->z -= rhs.z; return (*this); }
		// multiplication assignment	    a *= b	
        float3& operator *=(const float3& rhs) { this->x *= rhs.x; this->y *= rhs.y; this->z *= rhs.z; return (*this); }
		// division assignment	            a /= b	
        float3& operator /=(const float3& rhs) { this->x /= rhs.x; this->y /= rhs.y; this->z /= rhs.z; return (*this); }
		// modulo assignment	            a %= b	
        float3& operator %=(const float3& rhs) { this->x = std::fmod(this->x, rhs.x); this->y = std::fmod(this->y, rhs.y); this->z = std::fmod(this->z, rhs.z); return (*this); }

		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
        // pre-increment    : 	++a		T&
        float3& operator ++ ()                          { ++this->x; ++this->y; ++this->z; return (*this);     }
        // pre - decrement  : 	--a		T&
        float3& operator -- ()                          { --this->x; --this->y; --this->z; return (*this);     }
        // post-increment   : 	a++
        float3  operator ++ (int)                       { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        float3  operator -- (int)                       { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
        // unary plus       :   +a
        float3 operator + () const                      { return float3(+this->x, +this->y, +this->z); }

        // unary minus      :   -a
        float3 operator - () const                      { return float3(-this->x, -this->y, -this->z); }

		// addition         :   a + b
        float3 operator + (const float3& rhs)   const   { return float3(this->x + rhs.x,    this->y + rhs.y,    this->z + rhs.z); }
        float3 operator + (float rhs)           const   { return float3(this->x + rhs,      this->y + rhs,      this->z + rhs); }
        friend float3 operator + (float lhs, const float3& rhs) { return float3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z); }

		// subtraction      :   a - b
        float3 operator - (const float3& rhs)   const   { return float3(this->x - rhs.x,    this->y - rhs.y,    this->z - rhs.z); }
        float3 operator - (float rhs)           const   { return float3(this->x - rhs,      this->y - rhs,      this->z - rhs); }
        friend float3 operator - (float lhs, const float3& rhs) { return float3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z); }

		// multiplication   :   a * b
        float3 operator * (const float3& rhs)   const   { return float3(this->x * rhs.x,    this->y * rhs.y,    this->z * rhs.z); }
        float3 operator * (float rhs)           const   { return float3(this->x * rhs,      this->y * rhs,      this->z * rhs); }
        friend float3 operator * (float lhs, const float3& rhs) { return float3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }
        
		// division         :   a / b
        float3 operator / (const float3& rhs)   const   { return float3(this->x / rhs.x,    this->y / rhs.y,    this->z / rhs.z); }
        float3 operator / (float rhs)           const   { return float3(this->x / rhs,      this->y / rhs,      this->z / rhs); }
        friend float3 operator / (float lhs, const float3& rhs) { return float3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z); }

		// modulo           :   a % b
        float3 operator % (const float3& rhs)   const   { return float3(std::fmod(this->x, rhs.x),    std::fmod(this->y, rhs.y),    std::fmod(this->z, rhs.z)); }
        float3 operator % (float rhs)           const   { return float3(std::fmod(this->x, rhs),      std::fmod(this->y, rhs),      std::fmod(this->z, rhs)); }
        friend float3 operator % (float lhs, const float3& rhs) { return float3(std::fmod(lhs, rhs.x), std::fmod(lhs, rhs.y), std::fmod(lhs, rhs.z)); }

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
        bool3 operator == (const float3& rhs)   const   { return bool3(this->x == rhs.x,    this->y == rhs.y,   this->z == rhs.z); }
        bool3 operator == (float rhs)           const   { return bool3(this->x == rhs,      this->y == rhs,     this->z == rhs); }
        friend bool3  operator ==(float lhs, const float3& rhs) { return bool3(lhs == rhs.x, lhs == rhs.y, lhs == rhs.z); }

        // not equal to     :   a != b
        bool3 operator != (const float3& rhs)   const   { return bool3(this->x != rhs.x,    this->y != rhs.y,   this->z != rhs.z); }
        bool3 operator != (float rhs)           const   { return bool3(this->x != rhs,      this->y != rhs,     this->z != rhs); }
        friend bool3  operator !=(float lhs, const float3& rhs) { return bool3(lhs != rhs.x, lhs != rhs.y, lhs != rhs.z); }

        // less than        :   a < b
        bool3 operator < (const float3& rhs)    const   { return bool3(this->x < rhs.x,     this->y < rhs.y,    this->z < rhs.z); }
        bool3 operator < (float rhs)            const   { return bool3(this->x < rhs,       this->y < rhs,      this->z < rhs); }
        friend bool3  operator < (float lhs, const float3& rhs) { return bool3(lhs < rhs.x, lhs < rhs.y, lhs < rhs.z); }

		// greater than     :   a > b
        bool3 operator > (const float3& rhs)    const   { return bool3(this->x > rhs.x,     this->y > rhs.y,    this->z > rhs.z); }
        bool3 operator > (float rhs)            const   { return bool3(this->x > rhs,       this->y > rhs,      this->z > rhs); }
        friend bool3  operator > (float lhs, const float3& rhs) { return bool3(lhs > rhs.x, lhs > rhs.y, lhs > rhs.z); }

		// less than or equal to    : a <= b	
        bool3 operator <= (const float3& rhs)   const   { return bool3(this->x <= rhs.x,    this->y <= rhs.y,   this->z <= rhs.z); }
        bool3 operator <= (float rhs)           const   { return bool3(this->x <= rhs,      this->y <= rhs,     this->z <= rhs); }
        friend bool3  operator <=(float lhs, const float3& rhs) { return bool3(lhs <= rhs.x, lhs <= rhs.y, lhs <= rhs.z); }

        // greater than or equal to : a >= b
        bool3 operator >= (const float3& rhs)   const   { return bool3(this->x >= rhs.x,    this->y >= rhs.y,   this->z >= rhs.z); }
        bool3 operator >= (float rhs)           const   { return bool3(this->x >= rhs,      this->y >= rhs,     this->z >= rhs); }
        friend bool3  operator >=(float lhs, const float3& rhs) { return bool3(lhs >= rhs.x, lhs >= rhs.y, lhs >= rhs.z); }

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
			if (index >= 3)
				throw std::exception("index must be between[0...2]");
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
        float4 xxyx()   const;
        float4 xxyy()   const;
        float4 xxyz()   const;
        float4 xxzx()   const;
        float4 xxzy()   const;
        float4 xxzz()   const;
        float4 xyxx()   const;
        float4 xyxy()   const;
        float4 xyxz()   const;
        float4 xyyx()   const;
        float4 xyyy()   const;
        float4 xyyz()   const;
        float4 xyzx()   const;
        float4 xyzy()   const;
        float4 xyzz()   const;
        float4 xzxx()   const;
        float4 xzxy()   const;
        float4 xzxz()   const;
        float4 xzyx()   const;
        float4 xzyy()   const;
        float4 xzyz()   const;
        float4 xzzx()   const;
        float4 xzzy()   const;
        float4 xzzz()   const;
        float4 yxxx()   const;
        float4 yxxy()   const;
        float4 yxxz()   const;
        float4 yxyx()   const;
        float4 yxyy()   const;
        float4 yxyz()   const;
        float4 yxzx()   const;
        float4 yxzy()   const;
        float4 yxzz()   const;
        float4 yyxx()   const;
        float4 yyxy()   const;
        float4 yyxz()   const;
        float4 yyyx()   const;
        float4 yyyy()   const;
        float4 yyyz()   const;
        float4 yyzx()   const;
        float4 yyzy()   const;
        float4 yyzz()   const;
        float4 yzxx()   const;
        float4 yzxy()   const;
        float4 yzxz()   const;
        float4 yzyx()   const;
        float4 yzyy()   const;
        float4 yzyz()   const;
        float4 yzzx()   const;
        float4 yzzy()   const;
        float4 yzzz()   const;
        float4 zxxx()   const;
        float4 zxxy()   const;
        float4 zxxz()   const;
        float4 zxyx()   const;
        float4 zxyy()   const;
        float4 zxyz()   const;
        float4 zxzx()   const;
        float4 zxzy()   const;
        float4 zxzz()   const;
        float4 zyxx()   const;
        float4 zyxy()   const;
        float4 zyxz()   const;
        float4 zyyx()   const;
        float4 zyyy()   const;
        float4 zyyz()   const;
        float4 zyzx()   const;
        float4 zyzy()   const;
        float4 zyzz()   const;
        float4 zzxx()   const;
        float4 zzxy()   const;
        float4 zzxz()   const;
        float4 zzyx()   const;
        float4 zzyy()   const;
        float4 zzyz()   const;
        float4 zzzx()   const;
        float4 zzzy()   const;
        float4 zzzz()   const;
        float3 xxx()    const;
        float3 xxy()    const;
        float3 xxz()    const;
        float3 xyx()    const;
        float3 xyy()    const;
        float3 xyz()    const;
        void   xyz(const float3& v);
        float3 xzx()    const;
        float3 xzy()    const;
        void   xzy(const float3& v);
        float3 xzz()    const;
        float3 yxx()    const;
        float3 yxy()    const;
        float3 yxz()    const;
        void   yxz(const float3& v);
        float3 yyx()    const;
        float3 yyy()    const;
        float3 yyz()    const;
        float3 yzx()    const;
        void   yzx(const float3& v);
        float3 yzy()    const;
        float3 yzz()    const;
        float3 zxx()    const;
        float3 zxy()    const;
        void   zxy(const float3& v);
        float3 zxz()    const;
        float3 zyx()    const;
        void   zyx(const float3& v);
        float3 zyy()    const;
        float3 zyz()    const;
        float3 zzx()    const;
        float3 zzy()    const;
        float3 zzz()    const;
        float2 xx()     const;
        float2 xy()     const;
        void   xy(const float2& v);
        float2 xz()     const;
        void   xz(const float2& v);
        float2 yx()     const;
        void   yx(const float2& v);
        float2 yy()     const;
        float2 yz()     const;
        void   yz(const float2& v);
        float2 zx()     const;
        void   zx(const float2& v);
        float2 zy()     const;
        void   zy(const float2& v);
        float2 zz()     const;
        
		//=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the float3 is equal to a given float3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

        /// <summary>Returns true if the float3 is equal to a given float3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the float3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float3({0}f, {1}f, {2}f)", x, y, z);
        }
	};
    __declspec(selectany) const float3  float3::zero = float3(0, 0, 0);
    __declspec(selectany) const float3  float3::one  = float3(1, 1, 1);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-float3
        //=========================================================
        /// <summary>Returns a uint hash code of a float3 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const float3& v);

        /// <summary>
        /// Returns a uint3 vector hash code of a float3 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(const float3& v);

        /// <summary>Returns the result of specified shuffling of the components from two float3 vectors into a float value.</summary>
        /// <param name="left">float3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float.</param>
        /// <returns>float result of the shuffle operation.</returns>
        float shuffle(const float3& left, const float3& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two float3 vectors into a float2 vector.</summary>
        /// <param name="left">float3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float2 y component.</param>
        /// <returns>float2 result of the shuffle operation.</returns>
        float2 shuffle(const float3& left, const float3& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two float3 vectors into a float3 vector.</summary>
        /// <param name="left">float3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting float3 z component.</param>
        /// <returns>float3 result of the shuffle operation.</returns>
        float3 shuffle(const float3& left, const float3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two float3 vectors into a float4 vector.</summary>
        /// <param name="left">float3 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float3 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting float4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting float4 w component.</param>
        /// <returns>float4 result of the shuffle operation.</returns>
        float4 shuffle(const float3& left, const float3& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

