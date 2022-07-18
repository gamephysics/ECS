#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/uint2x4.gen.cs
#pragma pack(push,1)
	struct uint2x4
	{
	public:
		static const uint2x4		zero;       /// <summary>uint2x4 zero value.</summary>
		union {
			struct
			{
				uint2 c0;	/// <summary>Column 0 of the matrix.</summary>
				uint2 c1;	/// <summary>Column 1 of the matrix.</summary>
				uint2 c2;	/// <summary>Column 2 of the matrix.</summary>
				uint2 c3;	/// <summary>Column 2 of the matrix.</summary>
			};
			uint2		data[4];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		uint2x4() : c0(0), c1(0), c2(0), c3(0) {}
		uint2x4(const uint2& _c0, const uint2& _c1, const uint2& _c2, const uint2& _c3) { c0 = _c0;	c1 = _c1;	c2 = _c2;	c3 = _c3; }

        /// <summary>Constructs a uint2x4 matrix from 8 uint values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        uint2x4(uint m00, uint m01, uint m02, uint m03,
                       uint m10, uint m11, uint m12, uint m13)
        {
            c0 = uint2(m00, m10);
            c1 = uint2(m01, m11);
            c2 = uint2(m02, m12);
            c3 = uint2(m03, m13);
        }

		uint2x4(bool v);
        uint2x4(uint v)					{	c0 = v;				c1 = v;				c2 = v;				c3 = v;				}
		uint2x4(int v)					{	c0 = (uint2)v;		c1 = (uint2)v;		c2 = (uint2)v;		c3 = (uint2)v;		}
		uint2x4(float v)				{	c0 = (uint2)v;		c1 = (uint2)v;		c2 = (uint2)v;		c3 = (uint2)v;		}
		uint2x4(double v)				{	c0 = (uint2)v;		c1 = (uint2)v;		c2 = (uint2)v;		c3 = (uint2)v;		}

        uint2x4(const bool2x4& v);
		uint2x4(const uint2x4& v);
        uint2x4(const int2x4& v);
        uint2x4(const float2x4& v);
        uint2x4(const double2x4& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		uint2x4& operator = (const uint2x4& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1;  this->c2 = rhs.c2;  this->c3 = rhs.c3;  return (*this); }
		// addition assignment	            a += b	    
		uint2x4& operator +=(const uint2x4& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; this->c3 += rhs.c3; return (*this); }
		// subtraction assignment	        a -= b	    
		uint2x4& operator -=(const uint2x4& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; this->c3 -= rhs.c3; return (*this); }
		// multiplication assignment	    a *= b	    
		uint2x4& operator *=(const uint2x4& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; this->c3 *= rhs.c3; return (*this); }
		// division assignment	            a /= b	    
		uint2x4& operator /=(const uint2x4& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; this->c3 /= rhs.c3; return (*this); }
		// modulo assignment	            a %= b	    
		uint2x4& operator %=(const uint2x4& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; this->c3 %= rhs.c3; return (*this); }

        // bitwise AND assignment	        a &= b	    
		uint2x4& operator &=(const uint2x4& rhs)			{ this->c0 &= rhs.c0; this->c1 &= rhs.c1; this->c2 &= rhs.c2; this->c3 &= rhs.c3; return (*this); }
        // bitwise OR assignment	        a |= b	    
		uint2x4& operator |=(const uint2x4& rhs)			{ this->c0 |= rhs.c0; this->c1 |= rhs.c1; this->c2 |= rhs.c2; this->c3 |= rhs.c3; return (*this); }
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b
        
        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
		uint2x4& operator ++ ()								{ ++this->c0; ++this->c1; ++this->c2; ++this->c3; return (*this);     }
        // pre - decrement  : 	--a		T&
		uint2x4& operator -- ()								{ --this->c0; --this->c1; --this->c2; --this->c3; return (*this);     }
        // post-increment   : 	a++
		uint2x4  operator ++ (int)							{ auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
		uint2x4  operator -- (int)							{ auto temp = *this; --(*this); return (temp); }

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
		uint2x4 operator + () const							{ return uint2x4(+this->c0, +this->c1, +this->c2, +this->c3); }
        // unary minus      :   -a
		uint2x4 operator - () const							{ return uint2x4(-this->c0, -this->c1, -this->c2, -this->c3); }

		// addition         :   a + b
        uint2x4 operator + (const uint2x4& rhs)     const   { return uint2x4(this->c0 + rhs.c0,     this->c1 + rhs.c1,      this->c2 + rhs.c2,      this->c3 + rhs.c3); }
        uint2x4 operator + (uint rhs)               const   { return uint2x4(this->c0 + rhs,        this->c1 + rhs,         this->c2 + rhs,         this->c3 + rhs); }
		friend uint2x4 operator + (uint lhs, const uint2x4& rhs) { return uint2x4(lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2, lhs + rhs.c3); }

		// subtraction      :   a - b
        uint2x4 operator - (const uint2x4& rhs)     const   { return uint2x4(this->c0 - rhs.c0, this->c1 - rhs.c1, this->c2 - rhs.c2, this->c3 - rhs.c3); }
        uint2x4 operator - (uint rhs)               const   { return uint2x4(this->c0 - rhs, this->c1 - rhs, this->c2 - rhs, this->c3 - rhs); }
		friend uint2x4 operator - (uint lhs, const uint2x4& rhs) { return uint2x4(lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2, lhs - rhs.c3); }

		// multiplication   :   a * b
		uint2x4 operator * (const uint2x4& rhs)     const   { return uint2x4(this->c0 * rhs.c0,     this->c1 * rhs.c1,      this->c2 * rhs.c2,      this->c3 * rhs.c3); }
        uint2x4 operator * (uint rhs)               const   { return uint2x4(this->c0 * rhs,        this->c1 * rhs,         this->c2 * rhs,         this->c3 * rhs); }
		friend uint2x4 operator * (uint lhs, const uint2x4& rhs) { return uint2x4(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2, lhs * rhs.c3); }

		// division         :   a / b
		uint2x4 operator / (const uint2x4& rhs)     const   { return uint2x4(this->c0 / rhs.c0,     this->c1 / rhs.c1,      this->c2 / rhs.c2,      this->c3 / rhs.c3); }
        uint2x4 operator / (uint rhs)               const   { return uint2x4(this->c0 / rhs,        this->c1 / rhs,         this->c2 / rhs,         this->c3 / rhs); }
		friend uint2x4 operator / (uint lhs, const uint2x4& rhs) { return uint2x4(lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2, lhs / rhs.c3); }

		// modulo           :   a % b
        uint2x4 operator % (const uint2x4& rhs)     const   { return uint2x4(this->c0 % rhs.c0,     this->c1 % rhs.c1,      this->c2 % rhs.c2,      this->c3 % rhs.c3); }
        uint2x4 operator % (uint rhs)               const   { return uint2x4(this->c0 % rhs,        this->c1 % rhs,         this->c2 % rhs,         this->c3 % rhs); }
        friend uint2x4 operator % (uint lhs, const uint2x4& rhs) { return uint2x4(lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2, lhs % rhs.c3); }
		
		// bitwise NOT      :   ~a
		uint2x4 operator ~ ()   const                       { return uint2x4(~this->c0, ~this->c1, ~this->c2, ~this->c3); }

		// bitwise AND      :   a & b
        uint2x4 operator & (const uint2x4& rhs)     const   { return uint2x4(this->c0 & rhs.c0,     this->c1 & rhs.c1,      this->c2 & rhs.c2,      this->c3 & rhs.c3); }
        uint2x4 operator & (uint rhs)               const   { return uint2x4(this->c0 & rhs,        this->c1 & rhs,         this->c2 & rhs,         this->c3 & rhs); }
		friend uint2x4 operator & (uint lhs, const uint2x4& rhs) { return uint2x4(lhs & rhs.c0, lhs & rhs.c1, lhs & rhs.c2, lhs & rhs.c3); }

		// bitwise OR       :   a | b
        uint2x4 operator | (const uint2x4& rhs)     const   { return uint2x4(this->c0 | rhs.c0,     this->c1 | rhs.c1,      this->c2 | rhs.c2,      this->c3 | rhs.c3); }
        uint2x4 operator | (uint rhs)               const   { return uint2x4(this->c0 | rhs,        this->c1 | rhs,         this->c2 | rhs,         this->c3 | rhs); }
		friend uint2x4 operator | (uint lhs, const uint2x4& rhs) { return uint2x4(lhs | rhs.c0, lhs | rhs.c1, lhs | rhs.c2, lhs | rhs.c3); }

		// bitwise XOR      :   a ^ b
        uint2x4 operator ^ (const uint2x4& rhs)     const   { return uint2x4(this->c0 ^ rhs.c0,     this->c1 ^ rhs.c1,      this->c2 ^ rhs.c2,      this->c3 ^ rhs.c3); }
        uint2x4 operator ^ (uint rhs)               const   { return uint2x4(this->c0 ^ rhs,        this->c1 ^ rhs,         this->c2 ^ rhs,         this->c3 ^ rhs); }
        friend uint2x4 operator ^ (uint lhs, const uint2x4& rhs) { return uint2x4(lhs ^ rhs.c0, lhs ^ rhs.c1, lhs ^ rhs.c2, lhs ^ rhs.c3); }

		// bitwise left shift : a << b
		uint2x4 operator << (int n) const                   { return uint2x4(this->c0 << n, this->c1 << n, this->c2 << n, this->c3 << n); }

		// bitwise right shift: a >> b
        uint2x4 operator >> (int n) const                   { return uint2x4(this->c0 >> n, this->c1 >> n, this->c2 >> n, this->c3 >> n); }

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
		bool2x4 operator == (const uint2x4& rhs)	const	{ return bool2x4(this->c0 == rhs.c0,	this->c1 == rhs.c1,		this->c2 == rhs.c2,		this->c3 == rhs.c3); }
		bool2x4 operator == (uint rhs)              const	{ return bool2x4(this->c0 == rhs,		this->c1 == rhs,		this->c2 == rhs,		this->c3 == rhs); }
		friend bool2x4 operator == (uint lhs, const uint2x4& rhs) { return bool2x4(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2, lhs == rhs.c3); }

		bool2x4 operator != (const uint2x4& rhs)    const	{ return bool2x4(this->c0 != rhs.c0,	this->c1 != rhs.c1,		this->c2 != rhs.c2,		this->c3 != rhs.c3); }
		bool2x4 operator != (uint rhs)              const	{ return bool2x4(this->c0 != rhs,		this->c1 != rhs,		this->c2 != rhs,		this->c3 != rhs); }
		friend bool2x4 operator != (uint lhs, const uint2x4& rhs) { return bool2x4(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2, lhs != rhs.c3); }

		bool2x4 operator < (const uint2x4& rhs)     const	{ return bool2x4(this->c0 < rhs.c0,		this->c1 < rhs.c1,		this->c2 < rhs.c2,		this->c3 < rhs.c3); }
		bool2x4 operator < (uint rhs)               const	{ return bool2x4(this->c0 < rhs,		this->c1 < rhs,			this->c2 < rhs,			this->c3 < rhs); }
		friend bool2x4 operator < (uint lhs, const uint2x4& rhs) { return bool2x4(lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2, lhs < rhs.c3); }

		bool2x4 operator > (const uint2x4& rhs)     const	{ return bool2x4(this->c0 > rhs.c0,		this->c1 > rhs.c1,		this->c2 > rhs.c2,		this->c3 > rhs.c3); }
		bool2x4 operator > (uint rhs)               const	{ return bool2x4(this->c0 > rhs,		this->c1 > rhs,			this->c2 > rhs,			this->c3 > rhs); }
		friend bool2x4 operator > (uint lhs, const uint2x4& rhs) { return bool2x4(lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2, lhs > rhs.c3); }

		bool2x4 operator <= (const uint2x4& rhs)    const	{ return bool2x4(this->c0 <= rhs.c0,	this->c1 <= rhs.c1,		this->c2 <= rhs.c2,		this->c3 <= rhs.c3); }
		bool2x4 operator <= (uint rhs)              const	{ return bool2x4(this->c0 <= rhs,		this->c1 <= rhs,		this->c2 <= rhs,		this->c3 <= rhs); }
		friend bool2x4 operator <= (uint lhs, const uint2x4& rhs) { return bool2x4(lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2, lhs <= rhs.c3); }

		bool2x4 operator >= (const uint2x4& rhs)    const	{ return bool2x4(this->c0 >= rhs.c0,	this->c1 >= rhs.c1,		this->c2 >= rhs.c2,		this->c3 >= rhs.c3); }
		bool2x4 operator >= (uint rhs)              const	{ return bool2x4(this->c0 >= rhs,		this->c1 >= rhs,		this->c2 >= rhs,		this->c3 >= rhs); }
		friend bool2x4 operator >= (uint lhs, const uint2x4& rhs) { return bool2x4(lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2, lhs >= rhs.c3); }

		// not equal to     :   a != b
		// less than        :   a < b
		// greater than     :   a > b
		// less than or equal to    : a <= b	
		// greater than or equal to : a >= b

		//=========================================================
		// Conversion operators
		//=========================================================


		//=========================================================
		// member access
		//=========================================================
        /// <summary>Returns the uint2 element at a specified index.</summary>
		uint2& operator[] (int index)
		{
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
			if (index >= 4)
				throw std::exception("index must be between[0...3]");
#endif
			return data[index];
		}

		//=========================================================
		// METHOD
		//=========================================================
        /// <summary>Returns true if the uint2x4 is equal to a given uint2x4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const uint2x4& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2) && c3.Equals(rhs.c3); }

        /// <summary>Returns true if the uint2x4 is equal to a given uint2x4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is uint2x4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the uint2x4.</summary>
        /// <returns>The computed hash code.</returns>
        // int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the uint2x4.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("uint2x4({0}, {1}, {2}, {3},  {4}, {5}, {6}, {7})", c0.x, c1.x, c2.x, c3.x, c0.y, c1.y, c2.y, c3.y);
        }
	};
	__declspec(selectany) const uint2x4	uint2x4::zero = uint2x4(0, 0, 0, 0);
#pragma pack(pop)

	namespace math
	{
		//=========================================================
		// math-uint2x4
		//=========================================================
		/// <summary>Return the uint4x2 transpose of a uint2x4 matrix.</summary>
		/// <param name="v">Value to transpose.</param>
		/// <returns>Transposed value.</returns>
		uint4x2 transpose(const uint2x4& v);

		/// <summary>Returns a uint hash code of a uint2x4 matrix.</summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint hash of the argument.</returns>
		uint hash(const uint2x4& v);

		/// <summary>
		/// Returns a uint2 vector hash code of a uint2x4 matrix.
		/// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
		/// that are only reduced to a narrow uint hash at the very end instead of at every step.
		/// </summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint2 hash of the argument.</returns>
		uint2 hashwide(const uint2x4& v);
	}

} // namespace ecs

