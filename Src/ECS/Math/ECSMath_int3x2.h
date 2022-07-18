#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/int3x2.gen.cs
#pragma pack(push,1)
	struct int3x2
	{
	public:
		static const int3x2		zero;       /// <summary>int3x2 zero value.</summary>
		union {
			struct
			{
				int3 c0;	/// <summary>Column 0 of the matrix.</summary>
				int3 c1;	/// <summary>Column 1 of the matrix.</summary>
			};
			int3		data[2];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
        int3x2() : c0(0), c1(0) {}
		int3x2(const int3& _c0, const int3& _c1) { c0 = _c0;	c1 = _c1; }

        /// <summary>Constructs a int3x2 matrix from 6 int values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        int3x2( int m00, int m01,
                int m10, int m11,
                int m20, int m21)
        {
            c0 = int3(m00, m10, m20);
            c1 = int3(m01, m11, m21);
        }

        int3x2(bool v);
		int3x2(uint v)		            {   c0 = (int3)v;       c1 = (int3)v;       }
		int3x2(int v)		            {   c0 = v;             c1 = v;             }
		int3x2(float v)		            {   c0 = (int3)v;       c1 = (int3)v;		}
		int3x2(double v)                {   c0 = (int3)v;       c1 = (int3)v;       }


        int3x2(const bool3x2& v);
        int3x2(const uint3x2& v);
		int3x2(const int3x2& v);
        int3x2(const float3x2& v);
        int3x2(const double3x2& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        int3x2& operator = (const int3x2& rhs)          { this->c0 = rhs.c0;  this->c1 = rhs.c1; return (*this); }
		// addition assignment	            a += b	    
        int3x2& operator +=(const int3x2& rhs)          { this->c0 += rhs.c0; this->c1 += rhs.c1; return (*this); }
		// subtraction assignment	        a -= b	    
        int3x2& operator -=(const int3x2& rhs)          { this->c0 -= rhs.c0; this->c1 -= rhs.c1; return (*this); }
		// multiplication assignment	    a *= b	    
        int3x2& operator *=(const int3x2& rhs)          { this->c0 *= rhs.c0; this->c1 *= rhs.c1; return (*this); }
		// division assignment	            a /= b	    
        int3x2& operator /=(const int3x2& rhs)          { this->c0 /= rhs.c0; this->c1 /= rhs.c1; return (*this); }
		// modulo assignment	            a %= b	    
        int3x2& operator %=(const int3x2& rhs)          { this->c0 %= rhs.c0; this->c1 %= rhs.c1; return (*this); }

        // bitwise AND assignment	        a &= b	    
        int3x2& operator &=(const int3x2& rhs)          { this->c0 &= rhs.c0; this->c1 &= rhs.c1; return (*this); }
        // bitwise OR assignment	        a |= b	    
        int3x2& operator |=(const int3x2& rhs)          { this->c0 |= rhs.c0; this->c1 |= rhs.c1; return (*this); }
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b
        
        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
        int3x2& operator ++ ()                          { ++this->c0; ++this->c1; return (*this);     }
        // pre - decrement  : 	--a		T&
        int3x2& operator -- ()                          { --this->c0; --this->c1; return (*this);     }
        // post-increment   : 	a++
        int3x2  operator ++ (int)                       { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        int3x2  operator -- (int)                       { auto temp = *this; --(*this); return (temp); }

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
        int3x2 operator + () const                      { return int3x2(+this->c0, +this->c1); }
        // unary minus      :   -a
        int3x2 operator - () const                      { return int3x2(-this->c0, -this->c1); }

		// addition         :   a + b
        int3x2 operator + (const int3x2& rhs)   const   { return int3x2(this->c0 + rhs.c0,      this->c1 + rhs.c1); }
        int3x2 operator + (int rhs)             const   { return int3x2(this->c0 + rhs,         this->c1 + rhs); }
        friend int3x2 operator + (int lhs, const int3x2& rhs) { return int3x2(lhs + rhs.c0, lhs + rhs.c1); }

        // subtraction      :   a - b
        int3x2 operator - (const int3x2& rhs)   const   { return int3x2(this->c0 - rhs.c0,      this->c1 - rhs.c1); }
        int3x2 operator - (int rhs)             const   { return int3x2(this->c0 - rhs,         this->c1 - rhs); }
        friend int3x2 operator - (int lhs, const int3x2& rhs) { return int3x2(lhs - rhs.c0, lhs - rhs.c1); }

        // multiplication   :   a * b
        int3x2 operator * (const int3x2& rhs)   const   { return int3x2(this->c0 * rhs.c0,      this->c1 * rhs.c1); }
        int3x2 operator * (int rhs)             const   { return int3x2(this->c0 * rhs,         this->c1 * rhs); }
        friend int3x2 operator * (int lhs, const int3x2& rhs) { return int3x2(lhs * rhs.c0, lhs * rhs.c1); }

        // division         :   a / b
        int3x2 operator / (const int3x2& rhs)   const   { return int3x2(this->c0 / rhs.c0,      this->c1 / rhs.c1); }
        int3x2 operator / (int rhs)             const   { return int3x2(this->c0 / rhs,         this->c1 / rhs); }
        friend int3x2 operator / (int lhs, const int3x2& rhs) { return int3x2(lhs / rhs.c0, lhs / rhs.c1); }

        // modulo           :   a % b
        int3x2 operator % (const int3x2& rhs)   const   { return int3x2(this->c0 % rhs.c0,      this->c1 % rhs.c1); }
        int3x2 operator % (int rhs)             const   { return int3x2(this->c0 % rhs,         this->c1 % rhs); }
        friend int3x2 operator % (int lhs, const int3x2& rhs) { return int3x2(lhs % rhs.c0, lhs % rhs.c1); }
		
		// bitwise NOT      :   ~a
        int3x2 operator ~ () const                      { return int3x2(~this->c0, ~this->c1); }

		// bitwise AND      :   a & b
        int3x2 operator & (const int3x2& rhs)   const   { return int3x2(this->c0 & rhs.c0,      this->c1 & rhs.c1); }
        int3x2 operator & (int rhs)             const   { return int3x2(this->c0 & rhs,         this->c1 & rhs); }
        friend int3x2 operator & (int lhs, const int3x2& rhs) { return int3x2(lhs & rhs.c0, lhs & rhs.c1); }

        // bitwise OR       :   a | b
        int3x2 operator | (const int3x2& rhs)   const   { return int3x2(this->c0 | rhs.c0,      this->c1 | rhs.c1); }
        int3x2 operator | (int rhs)             const   { return int3x2(this->c0 | rhs,         this->c1 | rhs); }
        friend int3x2 operator | (int lhs, const int3x2& rhs) { return int3x2(lhs | rhs.c0, lhs | rhs.c1); }

        // bitwise XOR      :   a ^ b
        int3x2 operator ^ (const int3x2& rhs)   const   { return int3x2(this->c0 ^ rhs.c0,      this->c1 ^ rhs.c1); }
        int3x2 operator ^ (int rhs)             const   { return int3x2(this->c0 ^ rhs,         this->c1 ^ rhs); }
        friend int3x2 operator ^ (int lhs, const int3x2& rhs) { return int3x2(lhs ^ rhs.c0, lhs ^ rhs.c1); }
		
        // bitwise left shift : a << b
        int3x2 operator << (int n) const                { return int3x2(this->c0 << n, this->c1 << n); }

		// bitwise right shift: a >> b
        int3x2 operator >> (int n) const                { return int3x2(this->c0 >> n, this->c1 >> n); }

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
        bool3x2 operator == (const int3x2& rhs) const   { return bool3x2(this->c0 == rhs.c0,    this->c1 == rhs.c1); }
        bool3x2 operator == (int rhs)           const   { return bool3x2(this->c0 == rhs,       this->c1 == rhs); }
        friend bool3x2 operator == (int lhs, const int3x2& rhs) { return bool3x2(lhs == rhs.c0, lhs == rhs.c1); }

        // not equal to     :   a != b
        bool3x2 operator != (const int3x2& rhs) const   { return bool3x2(this->c0 != rhs.c0,    this->c1 != rhs.c1); }
        bool3x2 operator != (int rhs)           const   { return bool3x2(this->c0 != rhs,       this->c1 != rhs); }
        friend bool3x2 operator != (int lhs, const int3x2& rhs) { return bool3x2(lhs != rhs.c0, lhs != rhs.c1); }

        // less than        :   a < b
        bool3x2 operator < (const int3x2& rhs)  const   { return bool3x2(this->c0 < rhs.c0,     this->c1 < rhs.c1); }
        bool3x2 operator < (int rhs)            const   { return bool3x2(this->c0 < rhs,        this->c1 < rhs); }
        friend bool3x2 operator < (int lhs, const int3x2& rhs) { return bool3x2(lhs < rhs.c0, lhs < rhs.c1); }

        // greater than     :   a > b
        bool3x2 operator > (const int3x2& rhs)  const   { return bool3x2(this->c0 > rhs.c0,     this->c1 > rhs.c1); }
        bool3x2 operator > (int rhs)            const   { return bool3x2(this->c0 > rhs,        this->c1 > rhs); }
        friend bool3x2 operator > (int lhs, const int3x2& rhs) { return bool3x2(lhs > rhs.c0, lhs > rhs.c1); }

        // less than or equal to    : a <= b	
        bool3x2 operator <= (const int3x2& rhs) const   { return bool3x2(this->c0 <= rhs.c0,    this->c1 <= rhs.c1); }
        bool3x2 operator <= (int rhs)           const   { return bool3x2(this->c0 <= rhs,       this->c1 <= rhs); }
        friend bool3x2 operator <= (int lhs, const int3x2& rhs) { return bool3x2(lhs <= rhs.c0, lhs <= rhs.c1); }

        // greater than or equal to : a >= b
        bool3x2 operator >= (const int3x2& rhs) const   { return bool3x2(this->c0 >= rhs.c0,    this->c1 >= rhs.c1); }
        bool3x2 operator >= (int rhs)           const   { return bool3x2(this->c0 >= rhs,       this->c1 >= rhs); }
        friend bool3x2 operator >= (int lhs, const int3x2& rhs) { return bool3x2(lhs >= rhs.c0, lhs >= rhs.c1); }

        //=========================================================
        // Conversion operators
        //=========================================================


		//=========================================================
		// member access
		//=========================================================
        /// <summary>Returns the int3 element at a specified index.</summary>
        int3& operator[] (int index)
		{
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
			if (index >= 2)
				throw std::exception("index must be between[0...1]");
#endif
			return data[index];
		}

		//=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the int3x2 is equal to a given int3x2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const int3x2& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1); }

        /// <summary>Returns true if the int3x2 is equal to a given int3x2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is int3x2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the int3x2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the int3x2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("int3x2({0}, {1},  {2}, {3},  {4}, {5})", c0.x, c1.x, c0.y, c1.y, c0.z, c1.z);
        }
	};
    __declspec(selectany) const int3x2  int3x2::zero = int3x2(0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-int3x2
        //=========================================================
        /// <summary>Return the int2x3 transpose of a int3x2 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        int2x3 transpose(const int3x2& v);

        /// <summary>Returns a uint hash code of a int3x2 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const int3x2& v);

        /// <summary>
        /// Returns a uint3 vector hash code of a int3x2 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(const int3x2& v);
    }

} // namespace ecs

