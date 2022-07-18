#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/double2.gen.cs
#pragma pack(push,1)
	struct double2
	{
	public:
		static const  double2	zero;
        union {
            struct { double x, y; };
            double        data[2];
        };

    public:
        //=========================================================
		// CONSTRUCTOR
		//=========================================================
        double2() : x(0), y(0)                          {}
		double2(double _x, double _y) : x(_x), y(_y)    {}

        double2(bool v)                                 {   x = v ? 1.0 : 0.0;  y = v ? 1.0 : 0.0;  }
        double2(int v)                                  {   x = (double)v;      y = (double)v;      }
        double2(uint v)                                 {   x = (double)v;      y = (double)v;      }
        //double2(const half& v)                        {   x = (double)v;      y = (double)v;      }
        double2(float v)                                {   x = (double)v;      y = (double)v;      }
        double2(double v)                               {   x = v;              y = v;              }

        double2(const bool2& v);
        double2(const uint2& v);
        double2(const int2& v);
        //double2(const half2& v);
        double2(const float2& v);
        double2(const double2& v);


		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        double2& operator = (const double2& rhs)        { this->x  = rhs.x; this->y  = rhs.y; return (*this); }
		// addition assignment	            a += b	
        double2& operator +=(const double2& rhs)        { this->x += rhs.x; this->y += rhs.y; return (*this); }
		// subtraction assignment	        a -= b	
        double2& operator -=(const double2& rhs)        { this->x -= rhs.x; this->y -= rhs.y; return (*this); }
		// multiplication assignment	    a *= b	
        double2& operator *=(const double2& rhs)        { this->x *= rhs.x; this->y *= rhs.y; return (*this); }
		// division assignment	            a /= b	
        double2& operator /=(const double2& rhs)        { this->x /= rhs.x; this->y /= rhs.y; return (*this); }
		// modulo assignment	            a %= b	
        double2& operator %=(const double2& rhs)        { this->x= std::fmod(this->x, rhs.x); this->y = std::fmod(this->y, rhs.y); return (*this); }
		
        // bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
        double2& operator ++ ()                         { ++this->x; ++this->y; return (*this); }
		// pre - decrement  : 	--a		T&
        double2& operator -- ()                         { --this->x; --this->y; return (*this); }
		// post-increment   : 	a++
        double2  operator ++ (int)                      { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
        double2  operator -- (int)                      { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		double2  operator + () const                    { return double2(+this->x, +this->y); }

		// unary minus      :   -a
        double2  operator - () const                    { return double2(-this->x, -this->y); }

		// addition         :   a + b
        double2  operator + (const double2& rhs)const   { return double2(this->x + rhs.x,   this->y + rhs.y); }
        double2  operator + (double rhs)        const   { return double2(this->x + rhs,     this->y + rhs); }
        friend double2 operator +  (double lhs, const double2& rhs) { return double2(lhs + rhs.x, lhs + rhs.y); }
        
		// subtraction      :   a - b
		double2  operator - (const double2& rhs)const   { return double2(this->x - rhs.x,   this->y - rhs.y); }
		double2  operator - (double rhs)        const   { return double2(this->x - rhs,     this->y - rhs); }
        friend double2 operator -  (double lhs, const double2& rhs) { return double2(lhs - rhs.x, lhs - rhs.y); }
        
		// multiplication   :   a * b
		double2  operator * (const double2& rhs)const   { return double2(this->x * rhs.x,   this->y * rhs.y); }
		double2  operator * (double rhs)        const   { return double2(this->x * rhs,     this->y * rhs); }
        friend double2 operator *  (double lhs, const double2& rhs) { return double2(lhs * rhs.x, lhs * rhs.y); }

        // division         :   a / b
        double2  operator / (const double2& rhs)const   { return double2(this->x / rhs.x,  this->y / rhs.y); }
        double2  operator / (double rhs)        const   { return double2(this->x / rhs,    this->y / rhs); }
        friend double2 operator /  (double lhs, const double2& rhs) { return double2(lhs / rhs.x, lhs / rhs.y); }

		// modulo           :   a % b
        double2  operator % (const double2& rhs)const   { return double2(std::fmod(this->x, rhs.x),   std::fmod(this->y, rhs.y)); }
        double2  operator % (double rhs)        const   { return double2(std::fmod(this->x, rhs),     std::fmod(this->y, rhs)); }
        friend double2 operator %  (double lhs, const double2& rhs) { return double2(std::fmod(lhs, rhs.x), std::fmod(lhs, rhs.y)); }

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
        bool2  operator == (const double2& rhs)     const   { return bool2(this->x == rhs.x,        this->y == rhs.y); }
        bool2  operator == (double rhs)             const   { return bool2(this->x == rhs,          this->y == rhs); }
        friend bool2   operator == (double lhs, const double2& rhs) { return bool2(lhs == rhs.x, lhs == rhs.y); }

		// not equal to     :   a != b
		bool2  operator != (const double2& rhs)     const   { return bool2(this->x != rhs.x,        this->y != rhs.y); }
		bool2  operator != (double rhs)             const   { return bool2(this->x != rhs,          this->y != rhs); }
        friend bool2   operator != (double lhs, const double2& rhs) { return bool2(lhs != rhs.x, lhs != rhs.y); }

		// less than        :   a < b
        bool2  operator < (const double2& rhs)      const   { return bool2(this->x < rhs.x,         this->y < rhs.y); }
        bool2  operator < (double rhs)              const   { return bool2(this->x < rhs,           this->y < rhs); }
        friend bool2   operator <  (double lhs, const double2& rhs) { return bool2(lhs < rhs.x, lhs < rhs.y); }

		// greater than     :   a > b
        bool2  operator > (const double2& rhs)      const   { return bool2(this->x > rhs.x,         this->y > rhs.y); }
        bool2  operator > (double rhs)              const   { return bool2(this->x > rhs,           this->y > rhs); }
        friend bool2   operator >  (double lhs, const double2& rhs) { return bool2(lhs > rhs.x, lhs > rhs.y); }

		// less than or equal to    : a <= b	
		bool2  operator <= (const double2& rhs)     const   { return bool2(this->x <= rhs.x,        this->y <= rhs.y); }
		bool2  operator <= (double rhs)             const   { return bool2(this->x <= rhs,          this->y <= rhs); }
        friend bool2   operator <= (double lhs, const double2& rhs) { return bool2(lhs <= rhs.x, lhs <= rhs.y); }

		// greater than or equal to : a >= b
        bool2  operator >= (const double2& rhs)     const   { return bool2(this->x >= rhs.x,        this->y >= rhs.y); }
        bool2  operator >= (double rhs)             const   { return bool2(this->x >= rhs,          this->y >= rhs); }
        friend bool2   operator >= (double lhs, const double2& rhs) { return bool2(lhs >= rhs.x, lhs >= rhs.y); }

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
			if (index >= 2)
				throw std::exception("index must be between[0...1]");
#endif
			return data[index];
		}

		//=========================================================
		// Getter/Setter
		//=========================================================
        /// <summary>Swizzles the vector.</summary>
        double4 xxxx() const;
        double4 xxxy() const;
        double4 xxyx() const;
        double4 xxyy() const;
        double4 xyxx() const;
        double4 xyxy() const;
        double4 xyyx() const;
        double4 xyyy() const;
        double4 yxxx() const;
        double4 yxxy() const;
        double4 yxyx() const;
        double4 yxyy() const;
        double4 yyxx() const;
        double4 yyxy() const;
        double4 yyyx() const;
        double4 yyyy() const;
        double3 xxx()  const;
        double3 xxy()  const;
        double3 xyx()  const;
        double3 xyy()  const;
        double3 yxx()  const;
        double3 yxy()  const;
        double3 yyx()  const;
        double3 yyy()  const;
        double2 xx()   const;
        double2 xy()   const;
        void    xy(const double2& v);
        double2 yx()   const;
        void    yx(const double2& v);
        double2 yy()   const;

        //=========================================================
        // 
        //=========================================================
        /// <summary>Returns true if the double2 is equal to a given double2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const double2& rhs) const { return x == rhs.x && y == rhs.y; }

        /// <summary>Returns true if the double2 is equal to a given double2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //bool Equals(object o) { return o is double2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the double2.</summary>
        /// <returns>The computed hash code.</returns>
        // int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the double2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("double2({0}, {1})", x, y);
        }
	};
    __declspec(selectany) const double2 double2::zero = double2(0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
	    // math-double2
	    //=========================================================
        /// <summary>Returns a uint hash code of a double2 vector.</summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const double2& v);

        /// <summary>
        /// Returns a uint2 vector hash code of a double2 vector.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Vector value to hash.</param>
        /// <returns>uint2 hash of the argument.</returns>
        uint2 hashwide(const double2& v);

        /// <summary>Returns the result of specified shuffling of the components from two double2 vectors into a double value.</summary>
        /// <param name="left">double2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double.</param>
        /// <returns>double result of the shuffle operation.</returns>
        double shuffle(const double2& left, const double2& right, ShuffleComponent x);

        /// <summary>Returns the result of specified shuffling of the components from two double2 vectors into a double2 vector.</summary>
        /// <param name="left">double2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double2 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double2 y component.</param>
        /// <returns>double2 result of the shuffle operation.</returns>
        double2 shuffle(const double2& left, const double2& right, ShuffleComponent x, ShuffleComponent y);

        /// <summary>Returns the result of specified shuffling of the components from two double2 vectors into a double3 vector.</summary>
        /// <param name="left">double2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double3 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double3 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting double3 z component.</param>
        /// <returns>double3 result of the shuffle operation.</returns>
        double3 shuffle(const double2& left, const double2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z);

        /// <summary>Returns the result of specified shuffling of the components from two double2 vectors into a double4 vector.</summary>
        /// <param name="left">double2 to use as the left argument of the shuffle operation.</param>
        /// <param name="right">double2 to use as the right argument of the shuffle operation.</param>
        /// <param name="x">The ShuffleComponent to use when setting the resulting double4 x component.</param>
        /// <param name="y">The ShuffleComponent to use when setting the resulting double4 y component.</param>
        /// <param name="z">The ShuffleComponent to use when setting the resulting double4 z component.</param>
        /// <param name="w">The ShuffleComponent to use when setting the resulting double4 w component.</param>
        /// <returns>double4 result of the shuffle operation.</returns>
        double4 shuffle(const double2& left, const double2& right, ShuffleComponent x, ShuffleComponent y, ShuffleComponent z, ShuffleComponent w);
    }

} // namespace ecs

