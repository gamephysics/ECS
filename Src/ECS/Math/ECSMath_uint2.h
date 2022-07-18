#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/uint2.gen.cs
#pragma pack(push,1)
	struct uint2
	{
	public:
		static const  uint2	zero;
        union {
            struct { uint x, y; };
            uint        data[2];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        uint2() : x(0), y(0)                        {}
		uint2(uint _x, uint _y) : x(_x), y(_y)      {}

        uint2(bool v)                               { x = v ? 1u : 0u;      y = v ? 1u : 0u;    }
        uint2(uint v)                               { x = v;                y = v;              }
        uint2(int v)                                { x = (uint)v;          y = (uint)v;        }
        uint2(float v)                              { x = (uint)v;          y = (uint)v;        }
        uint2(double v)                             { x = (uint)v;          y = (uint)v;        }

        uint2(const bool2& v);
        uint2(const uint2& v);
        uint2(const int2& v);
        uint2(const float2& v);
        uint2(const double2& v);

        //=========================================================
        // OPERATORS
        //=========================================================
        //=========================================================
        // Assignment operators : T&
        //=========================================================
        // simple assignment	            a = b	
        uint2& operator = (const uint2& rhs) { this->x = rhs.x; this->y = rhs.y; return (*this); }
		// addition assignment	            a += b	
        uint2& operator +=(const uint2& rhs) { this->x += rhs.x; this->y += rhs.y; return (*this); }
		// subtraction assignment	        a -= b	
        uint2& operator -=(const uint2& rhs) { this->x -= rhs.x; this->y -= rhs.y; return (*this); }
		// multiplication assignment	    a *= b	
        uint2& operator *=(const uint2& rhs) { this->x *= rhs.x; this->y *= rhs.y; return (*this); }
		// division assignment	            a /= b	
        uint2& operator /=(const uint2& rhs) { this->x /= rhs.x; this->y /= rhs.y; return (*this); }
		// modulo assignment	            a %= b	
        uint2& operator %=(const uint2& rhs) { this->x %= rhs.x; this->y %= rhs.y; return (*this); }
        
        // bitwise AND assignment	        a &= b	
        uint2& operator &=(const uint2& rhs) { this->x &= rhs.x; this->y &= rhs.y; return (*this); }
        // bitwise OR assignment	        a |= b	
        uint2& operator |=(const uint2& rhs) { this->x |= rhs.x; this->y |= rhs.y; return (*this); }
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b
        
        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
        uint2& operator ++ ()                       { ++this->x; ++this->y; return (*this);     }                 
        // pre - decrement  : 	--a		T&
        uint2& operator -- ()                       { --this->x; --this->y; return (*this);     }                 
        // post-increment   : 	a++
        uint2  operator ++ (int)                    { auto temp = *this; ++(*this); return (temp); }       
        // post-decrement   :	a--
        uint2  operator -- (int)                    { auto temp = *this; --(*this); return (temp); }       
        
        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
        uint2  operator + () const                  { return uint2(+this->x, +this->y); }
        // unary minus      :   -a
        uint2  operator - () const                  { return uint2(unary_minus_operator(this->x), unary_minus_operator(this->y)); } //return uint2((uint)-this->x, (uint)-this->y); 

        // addition         :   a + b
        uint2 operator + (const uint2& rhs) const   { return uint2(this->x + rhs.x,    this->y + rhs.y); }
        uint2 operator + (uint rhs)         const   { return uint2(this->x + rhs,      this->y + rhs); }
        friend uint2 operator + (uint lhs, const uint2& rhs) { return uint2(lhs + rhs.x, lhs + rhs.y); }

        // subtraction      :   a - b
        uint2 operator - (const uint2& rhs) const   { return uint2(this->x - rhs.x,    this->y - rhs.y); }
        uint2 operator - (uint rhs)         const   { return uint2(this->x - rhs,      this->y - rhs); }
        friend uint2 operator - (uint lhs, const uint2& rhs) { return uint2(lhs - rhs.x, lhs - rhs.y); }
            
        // multiplication   :   a * b
        uint2 operator * (const uint2& rhs) const   { return uint2(this->x * rhs.x,    this->y * rhs.y); }
        uint2 operator * (uint rhs)         const   { return uint2(this->x * rhs,      this->y * rhs); }
        friend uint2 operator * (uint lhs, const uint2& rhs) { return uint2(lhs * rhs.x, lhs * rhs.y); }

        // division         :   a / b
        uint2 operator / (const uint2& rhs) const   { return uint2(this->x / rhs.x,    this->y / rhs.y); }
        uint2 operator / (uint rhs)         const   { return uint2(this->x / rhs,      this->y / rhs); }
        friend uint2 operator / (uint lhs, const uint2& rhs) { return uint2(lhs / rhs.x, lhs / rhs.y); }

        // modulo           :   a % b
        uint2 operator % (const uint2& rhs) const   { return uint2(this->x % rhs.x,    this->y % rhs.y); }
        uint2 operator % (uint rhs)         const   { return uint2(this->x % rhs,      this->y % rhs); }
        friend uint2 operator % (uint lhs, const uint2& rhs) { return uint2(lhs % rhs.x, lhs % rhs.y); }

        // bitwise NOT      :   ~a
        uint2  operator ~ () const                  { return uint2(~this->x, ~this->y); }

        // bitwise AND      :   a & b
        uint2  operator & (const uint2& rhs) const  { return uint2(this->x & rhs.x, this->y & rhs.y); }
        uint2  operator & (uint rhs)         const  { return uint2(this->x & rhs,   this->y & rhs); }
        friend uint2 operator & (uint lhs, const uint2& rhs) { return uint2(lhs & rhs.x, lhs & rhs.y); }

        // bitwise OR       :   a | b
        uint2  operator | (const uint2& rhs) const  { return uint2(this->x | rhs.x, this->y | rhs.y); }
        uint2  operator | (uint rhs)         const  { return uint2(this->x | rhs,   this->y | rhs); }
        friend uint2 operator | (uint lhs, const uint2& rhs) { return uint2(lhs | rhs.x, lhs | rhs.y); }

        // bitwise XOR      :   a ^ b
        uint2  operator ^ (const uint2& rhs) const  { return uint2(this->x ^ rhs.x, this->y ^ rhs.y); }
        uint2  operator ^ (uint rhs)         const  { return uint2(this->x ^ rhs,   this->y ^ rhs); }
        friend uint2 operator ^ (uint lhs, const uint2& rhs) { return uint2(lhs ^ rhs.x, lhs ^ rhs.y); }

        // bitwise left shift : a << b
        uint2  operator <<(int n) const             { return uint2(this->x << n, this->y << n); }
        // bitwise right shift: a >> b
        uint2  operator >>(int n) const             { return uint2(this->x >> n, this->y >> n); }

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
        bool2  operator ==(const uint2& rhs) const  { return bool2(this->x == rhs.x, this->y == rhs.y); }
        bool2  operator ==(uint rhs)         const  { return bool2(this->x == rhs,   this->y == rhs); }
        friend bool2 operator ==(uint lhs, const uint2& rhs) { return bool2(lhs == rhs.x, lhs == rhs.y); }

        // not equal to     :   a != b
        bool2  operator !=(const uint2& rhs) const  { return bool2(this->x != rhs.x, this->y != rhs.y); }
        bool2  operator !=(uint rhs)         const  { return bool2(this->x != rhs,   this->y != rhs); }
        friend bool2 operator !=(uint lhs, const uint2& rhs) { return bool2(lhs != rhs.x, lhs != rhs.y); }

        // less than        :   a < b
        bool2  operator < (const uint2& rhs) const  { return bool2(this->x < rhs.x,    this->y < rhs.y); }
        bool2  operator < (uint rhs)         const  { return bool2(this->x < rhs,      this->y < rhs); }
        friend bool2 operator < (uint lhs, const uint2& rhs) { return bool2(lhs < rhs.x, lhs < rhs.y); }

        // greater than     :   a > b
        bool2  operator > (const uint2& rhs) const  { return bool2(this->x > rhs.x,    this->y > rhs.y); }
        bool2  operator > (uint rhs)         const  { return bool2(this->x > rhs,      this->y > rhs); }
        friend bool2 operator > (uint lhs, const uint2& rhs) { return bool2(lhs > rhs.x, lhs > rhs.y); }

        // less than or equal to    : a <= b	
        bool2  operator <=(const uint2& rhs) const  { return bool2(this->x <= rhs.x,   this->y <= rhs.y); }
        bool2  operator <=(uint rhs)         const  { return bool2(this->x <= rhs,     this->y <= rhs); }
        friend bool2 operator <=(uint lhs, const uint2& rhs) { return bool2(lhs <= rhs.x, lhs <= rhs.y); }

        // greater than or equal to : a >= b
        bool2  operator >=(const uint2& rhs) const  { return bool2(this->x >= rhs.x,   this->y >= rhs.y); }
        bool2  operator >=(uint rhs)         const  { return bool2(this->x >= rhs,     this->y >= rhs); }
        friend bool2 operator >=(uint lhs, const uint2& rhs) { return bool2(lhs >= rhs.x, lhs >= rhs.y); }

        // three-way comparision (C++ 20) : a <=> b
        // (a <=> b) < 0 if lhs < rhs
        // (a <=> b) > 0 if lhs > rhs
        // (a <=> b) == 0 if lhsand rhs are equal / equivalent.
        //bool2  operator <=>(const uint2& rhs) const  { return bool2(this->x >= rhs.x,   this->y >= rhs.y); }
        //bool2  operator <=>(uint rhs)         const  { return bool2(this->x >= rhs,     this->y >= rhs); }
        //friend bool2 operator >=(uint lhs, const uint2& rhs) { return bool2(lhs >= rhs.x, lhs >= rhs.y); }

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
            if (index >= 2)
                throw std::exception("index must be between[0...1]");
#endif
            return data[index];
        }

        //=========================================================
        // Getter/Setter
        //=========================================================
        /// <summary>Swizzles the vector.</summary>
        uint4 xxxx() const;
        uint4 xxxy() const;
        uint4 xxyx() const;
        uint4 xxyy() const;
        uint4 xyxx() const;
        uint4 xyxy() const;
        uint4 xyyx() const;
        uint4 xyyy() const;
        uint4 yxxx() const;
        uint4 yxxy() const;
        uint4 yxyx() const;
        uint4 yxyy() const;
        uint4 yyxx() const;
        uint4 yyxy() const;
        uint4 yyyx() const;
        uint4 yyyy() const;
        uint3 xxx()  const;
        uint3 xxy()  const;
        uint3 xyx()  const;
        uint3 xyy()  const;
        uint3 yxx()  const;
        uint3 yxy()  const;
        uint3 yyx()  const;
        uint3 yyy()  const;
        uint2 xx()   const;
        uint2 xy()   const;
        void  xy(const uint2& v);
        uint2 yx()   const;
        void  yx(const uint2& v);
        uint2 yy()   const;


        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the uint2 is equal to a given uint2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const uint2& rhs) const { return x == rhs.x && y == rhs.y; }

        /// <summary>Returns true if the uint2 is equal to a given uint2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is uint2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the uint2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode()               { return (int)math::hash(*this); }

        /// <summary>Returns a string representation of the uint2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("uint2({0}, {1})", x, y);
        }
	};
    __declspec(selectany) const uint2   uint2::zero = uint2(0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-uint2
        //=========================================================
        /// <summary>Returns a uint hash code of a uint2 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const uint2& v);

        /// <summary>
        /// Returns a uint2 vector hash code of a uint2 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint2 hash of the argument.</returns>
        uint2 hashwide(const uint2& v);

        /// <summary>Returns the result of specified shuffling of the components from two uint2 vectors into a uint value.</summary>
        /// <param name="left">uint2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint.</param>
        /// <returns>uint result of the shuffle operation.</returns>
        uint shuffle(const uint2& left, const uint2& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two uint2 vectors into a uint2 vector.</summary>
        /// <param name="left">uint2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint2 y component.</param>
        /// <returns>uint2 result of the shuffle operation.</returns>
        uint2 shuffle(const uint2& left, const uint2& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two uint2 vectors into a uint3 vector.</summary>
        /// <param name="left">uint2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting uint3 z component.</param>
        /// <returns>uint3 result of the shuffle operation.</returns>
        uint3 shuffle(const uint2& left, const uint2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two uint2 vectors into a uint4 vector.</summary>
        /// <param name="left">uint2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">uint2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting uint4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting uint4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting uint4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting uint4 w component.</param>
        /// <returns>uint4 result of the shuffle operation.</returns>
        uint4 shuffle(const uint2& left, const uint2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

