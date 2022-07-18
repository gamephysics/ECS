#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/int2.gen.cs
#pragma pack(push,1)
	struct int2
	{
	public:
		static const  int2	    zero;
        static const  int2	    max;
        union {
            struct { int x, y; };
            int        data[2];
        };

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        int2() : x(0), y(0)                         {}
        int2(int _x, int _y) : x(_x), y(_y)         {}

        int2(bool v)                                { x = v ? 1 : 0;    y = v ? 1 : 0;  }
        int2(uint v)                                { x = (int)v;       y = (int)v;     }
        int2(int v)                                 { x = (int)v;       y = (int)v;     }
        int2(float v)                               { x = (int)v;       y = (int)v;     }
        int2(double v)                              { x = (int)v;       y = (int)v;     }

        int2(const bool2& v);
        int2(const uint2& v);
        int2(const int2& xy);
        int2(const float2& v);
        int2(const double2& v);

        //=========================================================
        // OPERATORS
        //=========================================================
        //=========================================================
        // Assignment operators : T&
        //=========================================================
        // simple assignment	            a = b	
        int2& operator = (const int2& rhs) { this->x = rhs.x; this->y = rhs.y; return (*this); }
		// addition assignment	            a += b	
        int2& operator +=(const int2& rhs) { this->x += rhs.x; this->y += rhs.y; return (*this); }
		// subtraction assignment	        a -= b	
        int2& operator -=(const int2& rhs) { this->x -= rhs.x; this->y -= rhs.y; return (*this); }
		// multiplication assignment	    a *= b	
        int2& operator *=(const int2& rhs) { this->x *= rhs.x; this->y *= rhs.y; return (*this); }
		// division assignment	            a /= b	
        int2& operator /=(const int2& rhs) { this->x /= rhs.x; this->y /= rhs.y; return (*this); }
		// modulo assignment	            a %= b	
        int2& operator %=(const int2& rhs) { this->x %= rhs.x; this->y %= rhs.y; return (*this); }

        // bitwise AND assignment	        a &= b	
        int2& operator &=(const int2& rhs) { this->x &= rhs.x; this->y &= rhs.y; return (*this); }
        // bitwise OR assignment	        a |= b	
        int2& operator |=(const int2& rhs) { this->x |= rhs.x; this->y |= rhs.y; return (*this); }
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b
        
        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
        int2& operator ++ ()                        { ++this->x; ++this->y; return (*this);     }                 
        // pre - decrement  : 	--a		T&
        int2& operator -- ()                        { --this->x; --this->y; return (*this);     }                 
        // post-increment   : 	a++
        int2  operator ++ (int)                     { auto temp = *this; ++(*this); return (temp); }       
        // post-decrement   :	a--
        int2  operator -- (int)                     { auto temp = *this; --(*this); return (temp); }       

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
        int2 operator + () const                    { return int2(+this->x, +this->y); }

        // unary minus      :   -a
        int2 operator - () const                    { return int2(-this->x, -this->y); }

        // addition         :   a + b
        int2 operator + (const int2& rhs)   const   { return int2(this->x + rhs.x,      this->y + rhs.y); }
        int2 operator + (int rhs)           const   { return int2(this->x + rhs,        this->y + rhs); }
        friend int2  operator + (int lhs, const int2& rhs) { return int2(lhs + rhs.x, lhs + rhs.y); }
        
        // subtraction      :   a - b
        int2 operator - (const int2& rhs)   const   { return int2(this->x - rhs.x,      this->y - rhs.y); }
        int2 operator - (int rhs)           const   { return int2(this->x - rhs,        this->y - rhs); }
        friend int2  operator - (int lhs, const int2& rhs) { return int2(lhs - rhs.x, lhs - rhs.y); }
        
        // multiplication   :   a * b
        int2 operator * (const int2& rhs)   const   { return int2(this->x * rhs.x,      this->y * rhs.y); }
        int2 operator * (int rhs)           const   { return int2(this->x * rhs,        this->y * rhs); }
        friend int2  operator * (int lhs, const int2& rhs) { return int2(lhs * rhs.x, lhs * rhs.y); }
        
        // division         :   a / b
        int2 operator / (const int2& rhs)   const   { return int2(this->x / rhs.x,     this->y / rhs.y); }
        int2 operator / (int rhs)           const   { return int2(this->x / rhs,       this->y / rhs); }
        friend int2  operator / (int lhs, const int2& rhs) { return int2(lhs / rhs.x, lhs / rhs.y); }
        
        // modulo           :   a % b
        int2 operator % (const int2& rhs)   const   { return int2(this->x % rhs.x,      this->y % rhs.y); }
        int2 operator % (int rhs)           const   { return int2(this->x % rhs,        this->y % rhs); }
        friend int2  operator % (int lhs, const int2& rhs) { return int2(lhs % rhs.x, lhs % rhs.y); }

        // bitwise NOT      :   ~a
        int2 operator ~ () const                   { return int2(~this->x, ~this->y); }

        // bitwise AND      :   a & b
        int2 operator & (const int2& rhs)   const   { return int2(this->x & rhs.x,      this->y & rhs.y); }
        int2 operator & (int rhs)           const   { return int2(this->x & rhs,        this->y & rhs); }
        friend int2  operator & (int lhs, const int2& rhs) { return int2(lhs & rhs.x, lhs & rhs.y); }

        // bitwise OR       :   a | b
        int2 operator | (const int2& rhs)   const   { return int2(this->x | rhs.x,      this->y | rhs.y); }
        int2 operator | (int rhs)           const   { return int2(this->x | rhs,        this->y | rhs); }
        friend int2  operator | (int lhs, const int2& rhs) { return int2(lhs | rhs.x, lhs | rhs.y); }

        // bitwise XOR      :   a ^ b
        int2 operator ^ (const int2& rhs)   const   { return int2(this->x ^ rhs.x,      this->y ^ rhs.y); }
        int2 operator ^ (int rhs)           const   { return int2(this->x ^ rhs,        this->y ^ rhs); }
        friend int2  operator ^ (int lhs, const int2& rhs) { return int2(lhs ^ rhs.x, lhs ^ rhs.y); }

        // bitwise left shift : a << b
        int2 operator << (int n) const              { return int2(this->x << n, this->y << n); }

        // bitwise right shift: a >> b
        int2 operator >> (int n) const              { return int2(this->x >> n, this->y >> n); }

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
        bool2 operator == (const int2& rhs) const   { return bool2(this->x == rhs.x,    this->y == rhs.y); }
        bool2 operator == (int rhs)         const   { return bool2(this->x == rhs,      this->y == rhs); }
        friend bool2 operator ==(int lhs, const int2& rhs) { return bool2(lhs == rhs.x, lhs == rhs.y); }

        // not equal to     :   a != b
        bool2 operator != (const int2& rhs) const   { return bool2(this->x != rhs.x,    this->y != rhs.y); }
        bool2 operator != (int rhs)         const   { return bool2(this->x != rhs,      this->y != rhs); }
        friend bool2 operator !=(int lhs, const int2& rhs) { return bool2(lhs != rhs.x, lhs != rhs.y); }

        // less than        :   a < b
        bool2 operator < (const int2& rhs)  const    { return bool2(this->x < rhs.x,    this->y < rhs.y); }
        bool2 operator < (int rhs)          const    { return bool2(this->x < rhs,      this->y < rhs); }
        friend bool2 operator < (int lhs, const int2& rhs) { return bool2(lhs < rhs.x, lhs < rhs.y); }

        // greater than     :   a > b
        bool2 operator > (const int2& rhs)  const    { return bool2(this->x > rhs.x,     this->y > rhs.y); }
        bool2 operator > (int rhs)          const    { return bool2(this->x > rhs,       this->y > rhs); }
        friend bool2 operator > (int lhs, const int2& rhs) { return bool2(lhs > rhs.x, lhs > rhs.y); }

        // less than or equal to    : a <= b	
        bool2 operator <= (const int2& rhs) const   { return bool2(this->x <= rhs.x,   this->y <= rhs.y); }
        bool2 operator <= (int rhs)         const   { return bool2(this->x <= rhs,     this->y <= rhs); }
        friend bool2 operator <=(int lhs, const int2& rhs) { return bool2(lhs <= rhs.x, lhs <= rhs.y); }

        // greater than or equal to : a >= b
        bool2 operator >= (const int2& rhs) const   { return bool2(this->x >= rhs.x,   this->y >= rhs.y); }
        bool2 operator >= (int rhs)         const   { return bool2(this->x >= rhs,     this->y >= rhs); }
        friend bool2 operator >=(int lhs, const int2& rhs) { return bool2(lhs >= rhs.x, lhs >= rhs.y); }

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
            if (index >= 2)
                throw std::exception("index must be between[0...1]");
#endif
            return data[index];
        }

        //=========================================================
        // Getter/Setter
        //=========================================================
        /// <summary>Swizzles the vector.</summary>
        int4 xxxx() const;
        int4 xxxy() const;
        int4 xxyx() const;
        int4 xxyy() const;
        int4 xyxx() const;
        int4 xyxy() const;
        int4 xyyx() const;
        int4 xyyy() const;
        int4 yxxx() const;
        int4 yxxy() const;
        int4 yxyx() const;
        int4 yxyy() const;
        int4 yyxx() const;
        int4 yyxy() const;
        int4 yyyx() const;
        int4 yyyy() const;
        int3 xxx()  const;
        int3 xxy()  const;
        int3 xyx()  const;
        int3 xyy()  const;
        int3 yxx()  const;
        int3 yxy()  const;
        int3 yyx()  const;
        int3 yyy()  const;
        int2 xx()   const;
        int2 xy()   const;
        void xy(const int2& v);
        int2 yx()   const;
        void yx(const int2& v);
        int2 yy()   const;

        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the int2 is equal to a given int2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const int2& rhs) const { return x == rhs.x && y == rhs.y; }

        /// <summary>Returns true if the int2 is equal to a given int2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is int2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the int2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode()               { return (int)math::hash(*this); }

        /// <summary>Returns a string representation of the int2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("int2({0}, {1})", x, y);
        }
	};
    __declspec(selectany) const int2    int2::zero  = int2(0, 0);
    __declspec(selectany) const int2    int2::max   = int2(INT_MAX, INT_MAX);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-int2
        //=========================================================
        /// <summary>Returns a uint hash code of a int2 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const int2& v);

        /// <summary>
        /// Returns a uint2 vector hash code of a int2 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint2 hash of the argument.</returns>
        uint2 hashwide(const int2& v);

        /// <summary>Returns the result of specified shuffling of the components from two int2 vectors into an int value.</summary>
        /// <param name="left">int2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int.</param>
        /// <returns>int result of the shuffle operation.</returns>
        int shuffle(const int2& left, const int2& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two int2 vectors into an int2 vector.</summary>
        /// <param name="left">int2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int2 y component.</param>
        /// <returns>int2 result of the shuffle operation.</returns>
        int2 shuffle(const int2& left, const int2& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two int2 vectors into an int3 vector.</summary>
        /// <param name="left">int2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting int3 z component.</param>
        /// <returns>int3 result of the shuffle operation.</returns>
        int3 shuffle(const int2& left, const int2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two int2 vectors into an int4 vector.</summary>
        /// <param name="left">int2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">int2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting int4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting int4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting int4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting int4 w component.</param>
        /// <returns>int4 result of the shuffle operation.</returns>
        int4 shuffle(const int2& left, const int2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

