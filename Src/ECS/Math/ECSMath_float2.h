#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float2.gen.cs
#pragma pack(push,1)
	struct float2
	{
	public:
		static const  float2	zero;
        static const  float2    max;
        union {
            struct { float x, y; };
            float        data[2];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        float2() : x(0.f), y(0.f)                   {}
		float2(float _x, float _y) : x(_x), y(_y)   {}

        float2(bool v)                              { x = v ? 1.0f : 0.0f;  y = v ? 1.0f : 0.0f;    }
        float2(uint v)                              { x = (float)v;         y = (float)v;   }
        float2(int v)                               { x = (float)v;         y = (float)v;   }
        //float2(half v)                            { x = (float)v;         y = (float)v;   }
        float2(float v)                             { x = v;                y = v;  }
        float2(double v)                            { x = (float)v;         y = (float)v;   }

        float2(const bool2& v);
        float2(const uint2& v);
        float2(const int2& v);
        //float2(const half2& v);
        float2(const float2& v);
        float2(const double2& v);

        //=========================================================
        // OPERATORS
        //=========================================================
        //=========================================================
        // Assignment operators : T&
        //=========================================================
        // simple assignment	            a = b	
        float2& operator = (const float2& rhs) { this->x = rhs.x; this->y = rhs.y; return (*this); }
		// addition assignment	            a += b	
        float2& operator +=(const float2& rhs) { this->x += rhs.x; this->y += rhs.y; return (*this); }
		// subtraction assignment	        a -= b	
        float2& operator -=(const float2& rhs) { this->x -= rhs.x; this->y -= rhs.y; return (*this); }
		// multiplication assignment	    a *= b	
        float2& operator *=(const float2& rhs) { this->x *= rhs.x; this->y *= rhs.y; return (*this); }
		// division assignment	            a /= b	
        float2& operator /=(const float2& rhs) { this->x /= rhs.x; this->y /= rhs.y; return (*this); }
		// modulo assignment	            a %= b	
        float2& operator %=(const float2& rhs) { this->x = std::fmod(this->x, rhs.x); this->y = std::fmod(this->y, rhs.y); return (*this); }
        
        // bitwise AND assignment	        a &= b	
        // bitwise OR assignment	        a |= b	
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b

        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
        float2& operator ++ ()                          { ++this->x; ++this->y; return (*this);     }
        // pre - decrement  : 	--a		T&
        float2& operator -- ()                          { --this->x; --this->y; return (*this);     }
        // post-increment   : 	a++
        float2  operator ++ (int)                       { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        float2  operator -- (int)                       { auto temp = *this; --(*this); return (temp); }

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
        float2 operator + () const                      { return float2(+this->x, +this->y); }

        // unary minus      :   -a
        float2 operator - () const                      { return float2(-this->x, -this->y); }

        // addition         :   a + b
        float2  operator + (const float2& rhs)  const   { return float2(this->x + rhs.x,    this->y + rhs.y); }
        float2  operator + (float rhs)          const   { return float2(this->x + rhs,      this->y + rhs); }
        friend float2 operator + (float lhs, const float2& rhs) { return float2(lhs + rhs.x, lhs + rhs.y); }
        

        // subtraction      :   a - b
        float2  operator - (const float2& rhs)  const   { return float2(this->x - rhs.x,    this->y - rhs.y); }
        float2  operator - (float rhs)          const   { return float2(this->x - rhs,      this->y - rhs); }
        friend float2 operator - (float lhs, const float2& rhs) { return float2(lhs - rhs.x, lhs - rhs.y); }
        

        // multiplication   :   a * b
        float2  operator * (const float2& rhs)  const   { return float2(this->x * rhs.x,    this->y * rhs.y); }
        float2  operator * (float rhs)          const   { return float2(this->x * rhs,      this->y * rhs); }
        friend float2 operator * (float lhs, const float2& rhs) { return float2(lhs * rhs.x, lhs * rhs.y); }
        

        // division         :   a / b
        float2  operator / (const float2& rhs)  const   { return float2(this->x / rhs.x,    this->y / rhs.y); }
        float2  operator / (float rhs)          const   { return float2(this->x / rhs,      this->y / rhs); }
        friend float2 operator / (float lhs, const float2& rhs) { return float2(lhs / rhs.x, lhs / rhs.y); }
        

        // modulo           :   a % b
        float2  operator % (const float2& rhs)  const   { return float2(std::fmod(this->x,rhs.x),    std::fmod(this->y,rhs.y)); }
        float2  operator % (float rhs)          const   { return float2(std::fmod(this->x,rhs),      std::fmod(this->y,rhs)); }
        friend float2 operator % (float lhs, const float2& rhs) { return float2(std::fmod(lhs, rhs.x), std::fmod(lhs, rhs.y)); }
        
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
        bool2  operator == (const float2& rhs)  const   { return bool2(this->x == rhs.x,    this->y == rhs.y); }
        bool2  operator == (float rhs)          const   { return bool2(this->x == rhs,      this->y == rhs); }
        friend bool2 operator == (float lhs, const float2& rhs) { return bool2(lhs == rhs.x, lhs == rhs.y); }
        
        // not equal to     :   a != b
        bool2  operator != (const float2& rhs)  const   { return bool2(this->x != rhs.x,    this->y != rhs.y); }
        bool2  operator != (float rhs)          const   { return bool2(this->x != rhs,      this->y != rhs); }
        friend bool2 operator != (float lhs, const float2& rhs) { return bool2(lhs != rhs.x, lhs != rhs.y); }
        
        // less than        :   a < b
        bool2  operator < (const float2& rhs)   const   { return bool2(this->x < rhs.x,     this->y < rhs.y); }
        bool2  operator < (float rhs)           const   { return bool2(this->x < rhs,       this->y < rhs); }
        friend bool2 operator <  (float lhs, const float2& rhs) { return bool2(lhs < rhs.x, lhs < rhs.y); }
        
        // greater than     :   a > b
        bool2  operator > (const float2& rhs)   const   { return bool2(this->x > rhs.x,     this->y > rhs.y); }
        bool2  operator > (float rhs)           const   { return bool2(this->x > rhs,       this->y > rhs); }
        friend bool2 operator >  (float lhs, const float2& rhs) { return bool2(lhs > rhs.x, lhs > rhs.y); }
        
        // less than or equal to    : a <= b	
        bool2  operator <= (const float2& rhs)  const   { return bool2(this->x <= rhs.x,    this->y <= rhs.y); }
        bool2  operator <= (float rhs)          const   { return bool2(this->x <= rhs,      this->y <= rhs); }
        friend bool2 operator <= (float lhs, const float2& rhs) { return bool2(lhs <= rhs.x, lhs <= rhs.y); }

        // greater than or equal to : a >= b
        bool2  operator >= (const float2& rhs)  const   { return bool2(this->x >= rhs.x,   this->y >= rhs.y); }
        bool2  operator >= (float rhs)          const   { return bool2(this->x >= rhs,     this->y >= rhs); }
        friend bool2 operator >= (float lhs, const float2& rhs) { return bool2(lhs >= rhs.x, lhs >= rhs.y); }

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
            if (index >= 2)
                throw std::exception("index must be between[0...1]");
#endif
            return data[index];
        }

        //=========================================================
        // Getter/Setter
        //=========================================================
        /// <summary>Swizzles the vector.</summary>
        float4 xxxx() const;
        float4 xxxy() const;
        float4 xxyx() const;
        float4 xxyy() const;
        float4 xyxx() const;
        float4 xyxy() const;
        float4 xyyx() const;
        float4 xyyy() const;
        float4 yxxx() const;
        float4 yxxy() const;
        float4 yxyx() const;
        float4 yxyy() const;
        float4 yyxx() const;
        float4 yyxy() const;
        float4 yyyx() const;
        float4 yyyy() const;
        float3 xxx()  const;
        float3 xxy()  const;
        float3 xyx()  const;
        float3 xyy()  const;
        float3 yxx()  const;
        float3 yxy()  const;
        float3 yyx()  const;
        float3 yyy()  const;
        float2 xx()   const;
        float2 xy()   const;
        void   xy(const float2& v);
        float2 yx()   const;
        void   yx(const float2& v);
        float2 yy()   const;

        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the float2 is equal to a given float2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float2& rhs) const { return x == rhs.x && y == rhs.y; }

        /// <summary>Returns true if the float2 is equal to a given float2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode()       { return (int)math.hash(this); }


        /// <summary>Returns a string representation of the float2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float2({0}f, {1}f)", x, y);
        }
	};
    __declspec(selectany) const float2  float2::zero = float2(0, 0);
    __declspec(selectany) const float2  float2::max  = float2(FLT_MAX, FLT_MAX);
    
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-float2
        //=========================================================
        /// <summary>Returns a uint hash code of a float2 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const float2& v);

        /// <summary>
        /// Returns a uint2 vector hash code of a float2 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint2 hash of the argument.</returns>
        uint2 hashwide(const float2& v);

        /// <summary>Returns the result of specified shuffling of the components from two float2 vectors into a float value.</summary>
        /// <param name="left">float2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float.</param>
        /// <returns>float result of the shuffle operation.</returns>
        float shuffle(const float2& left, const float2& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two float2 vectors into a float2 vector.</summary>
        /// <param name="left">float2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float2 y component.</param>
        /// <returns>float2 result of the shuffle operation.</returns>
        float2 shuffle(const float2& left, const float2& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two float2 vectors into a float3 vector.</summary>
        /// <param name="left">float2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting float3 z component.</param>
        /// <returns>float3 result of the shuffle operation.</returns>
        float3 shuffle(const float2& left, const float2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two float2 vectors into a float4 vector.</summary>
        /// <param name="left">float2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">float2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting float4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting float4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting float4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting float4 w component.</param>
        /// <returns>float4 result of the shuffle operation.</returns>
        float4 shuffle(const float2& left, const float2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

