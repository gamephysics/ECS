#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/uint4x2.gen.cs
#pragma pack(push,1)
	struct uint4x2
	{
	public:
		static const uint4x2		zero;       /// <summary>uint4x2 zero value.</summary>
		union {
			struct
			{
				uint4 c0;	/// <summary>Column 0 of the matrix.</summary>
				uint4 c1;	/// <summary>Column 1 of the matrix.</summary>
			};
			uint4		data[2];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
        uint4x2() : c0(0), c1(0) {}
		uint4x2(const uint4& _c0, const uint4& _c1) { c0 = _c0;	c1 = _c1; }

        /// <summary>Constructs a uint4x2 matrix from 8 uint values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        uint4x2(uint m00, uint m01,
                uint m10, uint m11,
                uint m20, uint m21,
                uint m30, uint m31)
        {
            c0 = uint4(m00, m10, m20, m30);
            c1 = uint4(m01, m11, m21, m31);
        }

        uint4x2(bool v);
		uint4x2(uint v)		            {   c0 = v;             c1 = v;		        }
		uint4x2(int v)		            {   c0 = (uint4)v;	    c1 = (uint4)v;      }
		uint4x2(float v)		        {   c0 = (uint4)v;      c1 = (uint4)v;      }
		uint4x2(double v)               {   c0 = (uint4)v;      c1 = (uint4)v;      }


        uint4x2(const bool4x2& v);
        uint4x2(const uint4x2& v);
        uint4x2(const int4x2& v);
        uint4x2(const float4x2& v);
        uint4x2(const double4x2& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		uint4x2& operator = (const uint4x2& rhs)            { this->c0 = rhs.c0;  this->c1 = rhs.c1; return (*this); }
		// addition assignment	            a += b	    
        uint4x2& operator +=(const uint4x2& rhs)            { this->c0 += rhs.c0; this->c1 += rhs.c1; return (*this); }
		// subtraction assignment	        a -= b	    
        uint4x2& operator -=(const uint4x2& rhs)            { this->c0 -= rhs.c0; this->c1 -= rhs.c1; return (*this); }
		// multiplication assignment	    a *= b	    
        uint4x2& operator *=(const uint4x2& rhs)            { this->c0 *= rhs.c0; this->c1 *= rhs.c1; return (*this); }
		// division assignment	            a /= b	    
        uint4x2& operator /=(const uint4x2& rhs)            { this->c0 /= rhs.c0; this->c1 /= rhs.c1; return (*this); }
		// modulo assignment	            a %= b	    
        uint4x2& operator %=(const uint4x2& rhs)            { this->c0 %= rhs.c0; this->c1 %= rhs.c1; return (*this); }

        // bitwise AND assignment	        a &= b	    
        uint4x2& operator &=(const uint4x2& rhs)            { this->c0 &= rhs.c0; this->c1 &= rhs.c1; return (*this); }
        // bitwise OR assignment	        a |= b	    
        uint4x2& operator |=(const uint4x2& rhs)            { this->c0 |= rhs.c0; this->c1 |= rhs.c1; return (*this); }
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b
        
        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
        uint4x2& operator ++ ()                             { ++this->c0; ++this->c1; return (*this);     }
        // pre - decrement  : 	--a		T&
        uint4x2& operator -- ()                             { --this->c0; --this->c1; return (*this);     }
        // post-increment   : 	a++
        uint4x2  operator ++ (int)                          { auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        uint4x2  operator -- (int)                          { auto temp = *this; --(*this); return (temp); }

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
        uint4x2 operator + () const                         { return uint4x2(+this->c0, +this->c1); }
        // unary minus      :   -a
        uint4x2 operator - () const                         { return uint4x2(-this->c0, -this->c1); }

		// addition         :   a + b
        uint4x2 operator + (const uint4x2& rhs)     const   { return uint4x2(this->c0 + rhs.c0,     this->c1 + rhs.c1); }
        uint4x2 operator + (uint rhs)               const   { return uint4x2(this->c0 + rhs,        this->c1 + rhs); }
        friend uint4x2 operator + (uint lhs, const uint4x2& rhs) { return uint4x2(lhs + rhs.c0, lhs + rhs.c1); }

        // subtraction      :   a - b
        uint4x2 operator - (const uint4x2& rhs)     const   { return uint4x2(this->c0 - rhs.c0,     this->c1 - rhs.c1); }
        uint4x2 operator - (uint rhs)               const   { return uint4x2(this->c0 - rhs,        this->c1 - rhs); }
        friend uint4x2 operator - (uint lhs, const uint4x2& rhs) { return uint4x2(lhs - rhs.c0, lhs - rhs.c1); }

        // multiplication   :   a * b
        uint4x2 operator * (const uint4x2& rhs)     const   { return uint4x2(this->c0 * rhs.c0,     this->c1 * rhs.c1); }
        uint4x2 operator * (uint rhs)               const   { return uint4x2(this->c0 * rhs,        this->c1 * rhs); }
        friend uint4x2 operator * (uint lhs, const uint4x2& rhs) { return uint4x2(lhs * rhs.c0, lhs * rhs.c1); }

        // division         :   a / b
        uint4x2 operator / (const uint4x2& rhs)     const   { return uint4x2(this->c0 / rhs.c0,     this->c1 / rhs.c1); }
        uint4x2 operator / (uint rhs)               const   { return uint4x2(this->c0 / rhs,        this->c1 / rhs); }
        friend uint4x2 operator / (uint lhs, const uint4x2& rhs) { return uint4x2(lhs / rhs.c0, lhs / rhs.c1); }

        // modulo           :   a % b
        uint4x2 operator % (const uint4x2& rhs)     const   { return uint4x2(this->c0 % rhs.c0,     this->c1 % rhs.c1); }
        uint4x2 operator % (uint rhs)               const   { return uint4x2(this->c0 % rhs,        this->c1 % rhs); }
        friend uint4x2 operator % (uint lhs, const uint4x2& rhs) { return uint4x2(lhs % rhs.c0, lhs % rhs.c1); }

		
		// bitwise NOT      :   ~a
        uint4x2 operator ~ () const							{ return uint4x2(~this->c0, ~this->c1); }

		// bitwise AND      :   a & b
		uint4x2 operator & (const uint4x2& rhs)     const	{ return uint4x2(this->c0 & rhs.c0, this->c1 & rhs.c1); }
		uint4x2 operator & (uint rhs)               const	{ return uint4x2(this->c0 & rhs, this->c1 & rhs); }
		friend uint4x2 operator & (uint lhs, const uint4x2& rhs) { return uint4x2(lhs & rhs.c0, lhs & rhs.c1); }

		// bitwise OR       :   a | b
		uint4x2 operator | (const uint4x2& rhs)     const	{ return uint4x2(this->c0 | rhs.c0, this->c1 | rhs.c1); }
		uint4x2 operator | (uint rhs)               const	{ return uint4x2(this->c0 | rhs, this->c1 | rhs); }
		friend uint4x2 operator | (uint lhs, const uint4x2& rhs) { return uint4x2(lhs | rhs.c0, lhs | rhs.c1); }

		// bitwise XOR      :   a ^ b
		uint4x2 operator ^ (const uint4x2& rhs)     const	{ return uint4x2(this->c0 ^ rhs.c0, this->c1 ^ rhs.c1); }
		uint4x2 operator ^ (uint rhs)               const	{ return uint4x2(this->c0 ^ rhs, this->c1 ^ rhs); }
		friend uint4x2 operator ^ (uint lhs, const uint4x2& rhs) { return uint4x2(lhs ^ rhs.c0, lhs ^ rhs.c1); }

		// bitwise left shift : a << b
		uint4x2 operator << (int n) const					{ return uint4x2(this->c0 << n, this->c1 << n); }

		// bitwise right shift: a >> b
		uint4x2 operator >> (int n) const					{ return uint4x2(this->c0 >> n, this->c1 >> n); }

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
		bool4x2 operator == (const uint4x2& rhs)    const   { return bool4x2(this->c0 == rhs.c0,    this->c1 == rhs.c1); }
        bool4x2 operator == (uint rhs)              const   { return bool4x2(this->c0 == rhs,       this->c1 == rhs); }
        friend bool4x2 operator == (uint lhs, const uint4x2& rhs) { return bool4x2(lhs == rhs.c0, lhs == rhs.c1); }

		// not equal to     :   a != b
        bool4x2 operator != (const uint4x2& rhs)    const   { return bool4x2(this->c0 != rhs.c0,    this->c1 != rhs.c1); }
        bool4x2 operator != (uint rhs)              const   { return bool4x2(this->c0 != rhs,       this->c1 != rhs); }
        friend bool4x2 operator != (uint lhs, const uint4x2& rhs) { return bool4x2(lhs != rhs.c0, lhs != rhs.c1); }

		// less than        :   a < b
        bool4x2 operator < (const uint4x2& rhs)     const   { return bool4x2(this->c0 < rhs.c0,     this->c1 < rhs.c1); }
        bool4x2 operator < (uint rhs)               const   { return bool4x2(this->c0 < rhs,        this->c1 < rhs); }
        friend bool4x2 operator < (uint lhs, const uint4x2& rhs) { return bool4x2(lhs < rhs.c0, lhs < rhs.c1); }

		// greater than     :   a > b
        bool4x2 operator > (const uint4x2& rhs)     const   { return bool4x2(this->c0 > rhs.c0,     this->c1 > rhs.c1); }
        bool4x2 operator > (uint rhs)               const   { return bool4x2(this->c0 > rhs,        this->c1 > rhs); }
        friend bool4x2 operator > (uint lhs, const uint4x2& rhs) { return bool4x2(lhs > rhs.c0, lhs > rhs.c1); }

		// less than or equal to    : a <= b	
        bool4x2 operator <= (const uint4x2& rhs)    const   { return bool4x2(this->c0 <= rhs.c0,    this->c1 <= rhs.c1); }
        bool4x2 operator <= (uint rhs)              const   { return bool4x2(this->c0 <= rhs,       this->c1 <= rhs); }
        friend bool4x2 operator <= (uint lhs, const uint4x2& rhs) { return bool4x2(lhs <= rhs.c0, lhs <= rhs.c1); }

		// greater than or equal to : a >= b
        bool4x2 operator >= (const uint4x2& rhs)    const   { return bool4x2(this->c0 >= rhs.c0,    this->c1 >= rhs.c1); }
        bool4x2 operator >= (uint rhs)              const   { return bool4x2(this->c0 >= rhs,       this->c1 >= rhs); }
        friend bool4x2 operator >= (uint lhs, const uint4x2& rhs) { return bool4x2(lhs >= rhs.c0, lhs >= rhs.c1); }

        //=========================================================
        // Conversion operators
        //=========================================================


		//=========================================================
		// member access
		//=========================================================
        /// <summary>Returns the uint4 element at a specified index.</summary>
		uint4& operator[] (int index)
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
        /// <summary>Returns true if the uint4x2 is equal to a given uint4x2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const uint4x2& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1); }

        /// <summary>Returns true if the uint4x2 is equal to a given uint4x2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is uint4x2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the uint4x2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the uint4x2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("uint4x2({0}, {1},  {2}, {3},  {4}, {5},  {6}, {7})", c0.x, c1.x, c0.y, c1.y, c0.z, c1.z, c0.w, c1.w);
        }
	};
    __declspec(selectany) const uint4x2 uint4x2::zero = uint4x2(0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-uint4x2
        //=========================================================
        /// <summary>Return the uint2x4 transpose of a uint4x2 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        uint2x4 transpose(const uint4x2& v);

        /// <summary>Returns a uint hash code of a uint4x2 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const uint4x2& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a uint4x2 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const uint4x2& v);
    }

} // namespace ecs

