#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/int4x3.gen.cs
#pragma pack(push,1)
	struct int4x3
	{
	public:
		static const int4x3		zero;       /// <summary>int4x3 zero value.</summary>
		union {
			struct
			{
				int4 c0;	/// <summary>Column 0 of the matrix.</summary>
				int4 c1;	/// <summary>Column 1 of the matrix.</summary>
				int4 c2;	/// <summary>Column 2 of the matrix.</summary>
			};
			int4		data[3];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		int4x3() : c0(0), c1(0), c2(0) {}
		int4x3(const int4& _c0, const int4& _c1, const int4& _c2) { c0 = _c0;	c1 = _c1;	c2 = _c2; }

        /// <summary>Constructs a int4x3 matrix from 12 int values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        int4x3( int m00, int m01, int m02,
                int m10, int m11, int m12,
                int m20, int m21, int m22,
                int m30, int m31, int m32)
        {
            c0 = int4(m00, m10, m20, m30);
            c1 = int4(m01, m11, m21, m31);
            c2 = int4(m02, m12, m22, m32);
        }


        int4x3(bool v);
		int4x3(uint v)		            {   c0 = (int4)v;       c1 = (int4)v;       c2 = (int4)v;		}
        int4x3(int v)		            {   c0 = v;			    c1 = v;			    c2 = v;		        }
		int4x3(float v)     		    {   c0 = (int4)v;       c1 = (int4)v;       c2 = (int4)v;		}
		int4x3(double v)		        {   c0 = (int4)v;       c1 = (int4)v;       c2 = (int4)v;       }

        int4x3(const bool4x3& v);
		int4x3(const int4x3& v);
        int4x3(const uint4x3& v);
        int4x3(const float4x3& v);
        int4x3(const double4x3& v);


		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		int4x3& operator = (const int4x3& rhs)          { this->c0 = rhs.c0;  this->c1 = rhs.c1;  this->c2 = rhs.c2;  return (*this); }
		// addition assignment	            a += b	    
		int4x3& operator +=(const int4x3& rhs)          { this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; return (*this); }
		// subtraction assignment	        a -= b	    
		int4x3& operator -=(const int4x3& rhs)          { this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; return (*this); }
		// multiplication assignment	    a *= b	    
		int4x3& operator *=(const int4x3& rhs)          { this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; return (*this); }
		// division assignment	            a /= b	    
		int4x3& operator /=(const int4x3& rhs)          { this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; return (*this); }
		// modulo assignment	            a %= b	    
		int4x3& operator %=(const int4x3& rhs)          { this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; return (*this); }

        // bitwise AND assignment	        a &= b	    
		int4x3& operator &=(const int4x3& rhs)          { this->c0 &= rhs.c0; this->c1 &= rhs.c1; this->c2 &= rhs.c2; return (*this); }
        // bitwise OR assignment	        a |= b	    
		int4x3& operator |=(const int4x3& rhs)          { this->c0 |= rhs.c0; this->c1 |= rhs.c1; this->c2 |= rhs.c2; return (*this); }
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b
        
        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
		int4x3& operator ++ ()                          { ++this->c0; ++this->c1; ++this->c2; return (*this);     }
        // pre - decrement  : 	--a		T&
		int4x3& operator -- ()                          { --this->c0; --this->c1; --this->c2; return (*this);     }
        // post-increment   : 	a++
		int4x3  operator ++ (int)                       { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
		int4x3  operator -- (int)                       { auto temp = *this; --(*this); return (temp); }

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
		int4x3 operator + () const                      { return int4x3(+this->c0, +this->c1, +this->c2); }
        // unary minus      :   -a
		int4x3 operator - () const                      { return int4x3(-this->c0, -this->c1, -this->c2); }

		// addition         :   a + b
        int4x3 operator + (const int4x3& rhs)	const	{ return int4x3(this->c0 + rhs.c0,		this->c1 + rhs.c1,		this->c2 + rhs.c2); }
        int4x3 operator + (int rhs)				const	{ return int4x3(this->c0 + rhs,			this->c1 + rhs,			this->c2 + rhs); }
		friend int4x3 operator + (int lhs, const int4x3& rhs) { return int4x3(lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2); }

		// subtraction      :   a - b
        int4x3 operator - (const int4x3& rhs)	const	{ return int4x3(this->c0 - rhs.c0,		this->c1 - rhs.c1,		this->c2 - rhs.c2); }
        int4x3 operator - (int rhs)				const	{ return int4x3(this->c0 - rhs,			this->c1 - rhs,			this->c2 - rhs); }
		friend int4x3 operator - (int lhs, const int4x3& rhs) { return int4x3(lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2); }

		// multiplication   :   a * b
        int4x3 operator * (const int4x3& rhs)	const	{ return int4x3(this->c0 * rhs.c0,		this->c1 * rhs.c1,		this->c2 * rhs.c2); }
        int4x3 operator * (int rhs)				const	{ return int4x3(this->c0 * rhs,			this->c1 * rhs,			this->c2 * rhs); }
        friend int4x3 operator * (int lhs, const int4x3& rhs) { return int4x3(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2); }

		// division         :   a / b
        int4x3 operator / (const int4x3& rhs)	const	{ return int4x3(this->c0 / rhs.c0,		this->c1 / rhs.c1,		this->c2 / rhs.c2); }
        int4x3 operator / (int rhs)				const	{ return int4x3(this->c0 / rhs,			this->c1 / rhs,			this->c2 / rhs); }
		friend int4x3 operator / (int lhs, const int4x3& rhs) { return int4x3(lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2); }

		// modulo           :   a % b
        int4x3 operator % (const int4x3& rhs)	const	{ return int4x3(this->c0 % rhs.c0,		this->c1 % rhs.c1,		this->c2 % rhs.c2); }
        int4x3 operator % (int rhs)				const	{ return int4x3(this->c0 % rhs,			this->c1 % rhs,			this->c2 % rhs); }
		friend int4x3 operator % (int lhs, const int4x3& rhs) { return int4x3(lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2); }
		
		// bitwise NOT      :   ~a
		int4x3 operator ~ () const                      { return int4x3(~this->c0, ~this->c1, ~this->c2); }

		// bitwise AND      :   a & b
        int4x3 operator & (const int4x3& rhs)	const	{ return int4x3(this->c0 & rhs.c0,		this->c1 & rhs.c1,		this->c2 & rhs.c2); }
        int4x3 operator & (int rhs)				const	{ return int4x3(this->c0 & rhs,			this->c1 & rhs,			this->c2 & rhs); }
		friend int4x3 operator & (int lhs, const int4x3& rhs) { return int4x3(lhs & rhs.c0, lhs & rhs.c1, lhs & rhs.c2); }

		// bitwise OR       :   a | b
        int4x3 operator | (const int4x3& rhs)	const	{ return int4x3(this->c0 | rhs.c0,		this->c1 | rhs.c1,		this->c2 | rhs.c2); }
        int4x3 operator | (int rhs)				const	{ return int4x3(this->c0 | rhs,			this->c1 | rhs,			this->c2 | rhs); }
		friend int4x3 operator | (int lhs, const int4x3& rhs) { return int4x3(lhs | rhs.c0, lhs | rhs.c1, lhs | rhs.c2); }

		// bitwise XOR      :   a ^ b
        int4x3 operator ^ (const int4x3& rhs)	const	{ return int4x3(this->c0 ^ rhs.c0,		this->c1 ^ rhs.c1,		this->c2 ^ rhs.c2); }
        int4x3 operator ^ (int rhs)				const	{ return int4x3(this->c0 ^ rhs,			this->c1 ^ rhs,			this->c2 ^ rhs); }
		friend int4x3 operator ^ (int lhs, const int4x3& rhs) { return int4x3(lhs ^ rhs.c0, lhs ^ rhs.c1, lhs ^ rhs.c2); }
		
		// bitwise left shift : a << b
		int4x3 operator << (int n) const                { return int4x3(this->c0 << n, this->c1 << n, this->c2 << n); }

		// bitwise right shift: a >> b
		int4x3 operator >> (int n) const                { return int4x3(this->c0 >> n, this->c1 >> n, this->c2 >> n); }

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
		bool4x3 operator == (const int4x3& rhs) const	{ return bool4x3(this->c0 == rhs.c0,	this->c1 == rhs.c1,		this->c2 == rhs.c2); }
        bool4x3 operator == (int rhs)			const	{ return bool4x3(this->c0 == rhs,		this->c1 == rhs,		this->c2 == rhs); }
		friend bool4x3 operator == (int lhs, const int4x3& rhs) { return bool4x3(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2); }

		// not equal to     :   a != b
        bool4x3 operator != (const int4x3& rhs)	const	{ return bool4x3(this->c0 != rhs.c0,	this->c1 != rhs.c1,		this->c2 != rhs.c2); }
        bool4x3 operator != (int rhs)			const	{ return bool4x3(this->c0 != rhs,		this->c1 != rhs,		this->c2 != rhs); }
		friend bool4x3 operator != (int lhs, const int4x3& rhs) { return bool4x3(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2); }

		// less than        :   a < b
		bool4x3 operator < (const int4x3& rhs)	const	{ return bool4x3(this->c0 < rhs.c0,		this->c1 < rhs.c1,		this->c2 < rhs.c2); }
        bool4x3 operator < (int rhs)			const	{ return bool4x3(this->c0 < rhs,		this->c1 < rhs,			this->c2 < rhs); }
		friend bool4x3 operator < (int lhs, const int4x3& rhs) { return bool4x3(lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2); }

		// greater than     :   a > b
        bool4x3 operator > (const int4x3& rhs)	const	{ return bool4x3(this->c0 > rhs.c0,		this->c1 > rhs.c1,		this->c2 > rhs.c2); }
        bool4x3 operator > (int rhs)			const	{ return bool4x3(this->c0 > rhs,		this->c1 > rhs,			this->c2 > rhs); }
		friend bool4x3 operator > (int lhs, const int4x3& rhs) { return bool4x3(lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2); }

		// less than or equal to    : a <= b	
        bool4x3 operator <= (const int4x3& rhs) const	{ return bool4x3(this->c0 <= rhs.c0,	this->c1 <= rhs.c1,		this->c2 <= rhs.c2); }
        bool4x3 operator <= (int rhs)			const	{ return bool4x3(this->c0 <= rhs,		this->c1 <= rhs,		this->c2 <= rhs); }
		friend bool4x3 operator <= (int lhs, const int4x3& rhs) { return bool4x3(lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2); }

		// greater than or equal to : a >= b
        bool4x3 operator >= (const int4x3& rhs) const	{ return bool4x3(this->c0 >= rhs.c0,	this->c1 >= rhs.c1,		this->c2 >= rhs.c2); }
        bool4x3 operator >= (int rhs)			const	{ return bool4x3(this->c0 >= rhs,		this->c1 >= rhs,		this->c2 >= rhs); }
		friend bool4x3 operator >= (int lhs, const int4x3& rhs) { return bool4x3(lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2); }

		//=========================================================
		// Conversion operators
		//=========================================================


		//=========================================================
		// member access
		//=========================================================
        /// <summary>Returns the int4 element at a specified index.</summary>
		int4& operator[] (int index)
		{
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
			if (index >= 3)
				throw std::exception("index must be between[0...2]");
#endif
			return data[index];
		}


		//=========================================================
		// METHOD
		//=========================================================
        /// <summary>Returns true if the int4x3 is equal to a given int4x3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const int4x3& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2); }

        /// <summary>Returns true if the int4x3 is equal to a given int4x3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is int4x3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the int4x3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the int4x3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("int4x3({0}, {1}, {2},  {3}, {4}, {5},  {6}, {7}, {8},  {9}, {10}, {11})", c0.x, c1.x, c2.x, c0.y, c1.y, c2.y, c0.z, c1.z, c2.z, c0.w, c1.w, c2.w);
        }
	};
	__declspec(selectany) const int4x3	int4x3::zero = int4x3(0, 0, 0);
#pragma pack(pop)

	namespace math
	{
		//=========================================================
		// math-int4x3
		//=========================================================
		/// <summary>Return the int3x4 transpose of a int4x3 matrix.</summary>
		/// <param name="v">Value to transpose.</param>
		/// <returns>Transposed value.</returns>
		int3x4 transpose(const int4x3& v);

		/// <summary>Returns a uint hash code of a int4x3 matrix.</summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint hash of the argument.</returns>
		uint hash(const int4x3& v);

		/// <summary>
		/// Returns a uint4 vector hash code of a int4x3 matrix.
		/// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
		/// that are only reduced to a narrow uint hash at the very end instead of at every step.
		/// </summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint4 hash of the argument.</returns>
		uint4 hashwide(const int4x3& v);
	}

} // namespace ecs

