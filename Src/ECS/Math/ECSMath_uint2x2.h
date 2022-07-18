#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/uint2x2.gen.cs
#pragma pack(push,1)
	struct uint2x2
	{
	public:
		static const uint2x2		identity;   /// <summary>uint2x2 identity transform.</summary>
		static const uint2x2		zero;       /// <summary>uint2x2 zero value.</summary>
		union {
			struct
			{
				uint2 c0;	/// <summary>Column 0 of the matrix.</summary>
				uint2 c1;	/// <summary>Column 1 of the matrix.</summary>
			};
			uint2		data[2];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		uint2x2() : c0(0), c1(0) {}
		uint2x2(const uint2& _c0, const uint2& _c1) { c0 = _c0;	c1 = _c1; }

        /// <summary>Constructs a uint2x2 matrix from 4 uint values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        uint2x2(uint m00, uint m01,
                uint m10, uint m11)
        {
            c0 = uint2(m00, m10);
            c1 = uint2(m01, m11);
        }

        uint2x2(bool v);
        uint2x2(uint v)                 {   c0 = v;             c1 = v;             }
		uint2x2(int v)  		        {   c0 = (uint2)v;      c1 = (uint2)v;      }
		uint2x2(float v)		        {   c0 = (uint2)v;      c1 = (uint2)v;		}
		uint2x2(double v)		        {   c0 = (uint2)v;      c1 = (uint2)v;      }

        uint2x2(const bool2x2& v);
		uint2x2(const uint2x2& v);
        uint2x2(const int2x2& v);
        uint2x2(const float2x2& v);
        uint2x2(const double2x2& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        uint2x2& operator = (const uint2x2& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1; return (*this); }
		// addition assignment	            a += b	    
        uint2x2& operator +=(const uint2x2& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; return (*this); }
		// subtraction assignment	        a -= b	    
        uint2x2& operator -=(const uint2x2& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; return (*this); }
		// multiplication assignment	    a *= b	    
        uint2x2& operator *=(const uint2x2& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; return (*this); }
		// division assignment	            a /= b	    
        uint2x2& operator /=(const uint2x2& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; return (*this); }
		// modulo assignment	            a %= b	    
        uint2x2& operator %=(const uint2x2& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; return (*this); }

        // bitwise AND assignment	        a &= b	    
        uint2x2& operator &=(const uint2x2& rhs)			{ this->c0 &= rhs.c0; this->c1 &= rhs.c1; return (*this); }
        // bitwise OR assignment	        a |= b	    
        uint2x2& operator |=(const uint2x2& rhs)			{ this->c0 |= rhs.c0; this->c1 |= rhs.c1; return (*this); }
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b
        
        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
        uint2x2& operator ++ ()								{ ++this->c0; ++this->c1; return (*this);     }
        // pre - decrement  : 	--a		T&
        uint2x2& operator -- ()								{ --this->c0; --this->c1; return (*this);     }
        // post-increment   : 	a++
        uint2x2  operator ++ (int)							{ auto temp = *this; ++(*this); return (temp); }
        // post-decrement   :	a--
        uint2x2  operator -- (int)							{ auto temp = *this; --(*this); return (temp); }

        //=========================================================
        // Arithmetic operators
        //=========================================================
        // unary plus       :   +a
        uint2x2 operator + () const							{ return uint2x2(+this->c0, +this->c1); }
        // unary minus      :   -a
        uint2x2 operator - () const							{ return uint2x2(-this->c0, -this->c1); }

		// addition         :   a + b
        uint2x2 operator + (const uint2x2& rhs)		const	{ return uint2x2(this->c0 + rhs.c0,		this->c1 + rhs.c1); }
        uint2x2 operator + (uint rhs)				const	{ return uint2x2(this->c0 + rhs,		this->c1 + rhs); }
        friend uint2x2 operator + (uint lhs, const uint2x2& rhs) { return uint2x2(lhs + rhs.c0, lhs + rhs.c1); }

		// subtraction      :   a - b
        uint2x2 operator - (const uint2x2& rhs)		const	{ return uint2x2(this->c0 - rhs.c0,		this->c1 - rhs.c1); }
        uint2x2 operator - (uint rhs)				const	{ return uint2x2(this->c0 - rhs,		this->c1 - rhs); }
		friend uint2x2 operator - (uint lhs, const uint2x2& rhs) { return uint2x2(lhs - rhs.c0, lhs - rhs.c1); }

		// multiplication   :   a * b
		uint2x2 operator * (const uint2x2& rhs)		const	{ return uint2x2(this->c0 * rhs.c0,		this->c1 * rhs.c1); }
        uint2x2 operator * (uint rhs)				const	{ return uint2x2(this->c0 * rhs,		this->c1 * rhs); }
		friend uint2x2 operator * (uint lhs, const uint2x2& rhs) { return uint2x2(lhs * rhs.c0, lhs * rhs.c1); }

		// division         :   a / b
		uint2x2 operator / (const uint2x2& rhs)		const	{ return uint2x2(this->c0 / rhs.c0,		this->c1 / rhs.c1); }
        uint2x2 operator / (uint rhs)				const	{ return uint2x2(this->c0 / rhs,		this->c1 / rhs); }
		friend uint2x2 operator / (uint lhs, const uint2x2& rhs) { return uint2x2(lhs / rhs.c0, lhs / rhs.c1); }

		// modulo           :   a % b
        uint2x2 operator % (const uint2x2& rhs)		const	{ return uint2x2(this->c0 % rhs.c0,		this->c1 % rhs.c1); }
        uint2x2 operator % (uint rhs)				const	{ return uint2x2(this->c0 % rhs,		this->c1 % rhs); }
		friend uint2x2 operator % (uint lhs, const uint2x2& rhs) { return uint2x2(lhs % rhs.c0, lhs % rhs.c1); }
		
		// bitwise NOT      :   ~a
		uint2x2 operator ~ () const							{ return uint2x2(~this->c0, ~this->c1); }

		// bitwise AND      :   a & b
		uint2x2 operator & (const uint2x2& rhs)		const	{ return uint2x2(this->c0 & rhs.c0,		this->c1 & rhs.c1); }
        uint2x2 operator & (uint rhs)				const	{ return uint2x2(this->c0 & rhs,		this->c1 & rhs); }
		friend uint2x2 operator & (uint lhs, const uint2x2& rhs) { return uint2x2(lhs & rhs.c0, lhs & rhs.c1); }

		// bitwise OR       :   a | b
        uint2x2 operator | (const uint2x2& rhs)		const	{ return uint2x2(this->c0 | rhs.c0,		this->c1 | rhs.c1); }
        uint2x2 operator | (uint rhs)				const	{ return uint2x2(this->c0 | rhs,		this->c1 | rhs); }
		friend uint2x2 operator | (uint lhs, const uint2x2& rhs) { return uint2x2(lhs | rhs.c0, lhs | rhs.c1); }

		// bitwise XOR      :   a ^ b
        uint2x2 operator ^ (const uint2x2& rhs)		const	{ return uint2x2(this->c0 ^ rhs.c0,		this->c1 ^ rhs.c1); }
        uint2x2 operator ^ (uint rhs)				const	{ return uint2x2(this->c0 ^ rhs,		this->c1 ^ rhs); }
		friend uint2x2 operator ^ (uint lhs, const uint2x2& rhs) { return uint2x2(lhs ^ rhs.c0, lhs ^ rhs.c1); }
		
		// bitwise left shift : a << b
        uint2x2 operator << (int n) const					{ return uint2x2(this->c0 << n, this->c1 << n); }
		// bitwise right shift: a >> b
        uint2x2 operator >> (int n) const					{ return uint2x2(this->c0 >> n, this->c1 >> n); }

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
		bool2x2 operator == (const uint2x2& rhs)	const	{ return bool2x2(this->c0 == rhs.c0,	this->c1 == rhs.c1); }
        bool2x2 operator == (uint rhs)				const	{ return bool2x2(this->c0 == rhs,		this->c1 == rhs); }
		friend bool2x2 operator == (uint lhs, const uint2x2& rhs) { return bool2x2(lhs == rhs.c0, lhs == rhs.c1); }

		// not equal to     :   a != b
        bool2x2 operator != (const uint2x2& rhs)	const	{ return bool2x2(this->c0 != rhs.c0,	this->c1 != rhs.c1); }
        bool2x2 operator != (uint rhs)				const	{ return bool2x2(this->c0 != rhs,		this->c1 != rhs); }
		friend bool2x2 operator != (uint lhs, const uint2x2& rhs) { return bool2x2(lhs != rhs.c0, lhs != rhs.c1); }

		// less than        :   a < b
        bool2x2 operator < (const uint2x2& rhs)		const	{ return bool2x2(this->c0 < rhs.c0,		this->c1 < rhs.c1); }
        bool2x2 operator < (uint rhs)				const	{ return bool2x2(this->c0 < rhs,		this->c1 < rhs); }
		friend bool2x2 operator < (uint lhs, const uint2x2& rhs) { return bool2x2(lhs < rhs.c0, lhs < rhs.c1); }

		// greater than     :   a > b
        bool2x2 operator > (const uint2x2& rhs)		const	{ return bool2x2(this->c0 > rhs.c0,		this->c1 > rhs.c1); }
        bool2x2 operator > (uint rhs)				const	{ return bool2x2(this->c0 > rhs,		this->c1 > rhs); }
		friend bool2x2 operator > (uint lhs, const uint2x2& rhs) { return bool2x2(lhs > rhs.c0, lhs > rhs.c1); }

		// less than or equal to    : a <= b	
        bool2x2 operator <= (const uint2x2& rhs)	const	{ return bool2x2(this->c0 <= rhs.c0,	this->c1 <= rhs.c1); }
        bool2x2 operator <= (uint rhs)				const	{ return bool2x2(this->c0 <= rhs,		this->c1 <= rhs); }
		friend bool2x2 operator <= (uint lhs, const uint2x2& rhs) { return bool2x2(lhs <= rhs.c0, lhs <= rhs.c1); }

		// greater than or equal to : a >= b
        bool2x2 operator >= (const uint2x2& rhs)	const	{ return bool2x2(this->c0 >= rhs.c0,	this->c1 >= rhs.c1); }
        bool2x2 operator >= (uint rhs)				const	{ return bool2x2(this->c0 >= rhs,		this->c1 >= rhs); }
		friend bool2x2 operator >= (uint lhs, const uint2x2& rhs) { return bool2x2(lhs >= rhs.c0, lhs >= rhs.c1); }

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
			if (index >= 2)
				throw std::exception("index must be between[0...1]");
#endif
			return data[index];
		}

		//=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the uint2x2 is equal to a given uint2x2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const uint2x2& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1); }

        /// <summary>Returns true if the uint2x2 is equal to a given uint2x2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is uint2x2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the uint2x2.</summary>
        /// <returns>The computed hash code.</returns>
        // int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the uint2x2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("uint2x2({0}, {1},  {2}, {3})", c0.x, c1.x, c0.y, c1.y);
        }
	};
    __declspec(selectany) const uint2x2 uint2x2::identity = uint2x2(1, 0, 0, 1);
    __declspec(selectany) const uint2x2	uint2x2::zero     = uint2x2(0, 0);
#pragma pack(pop)

    namespace math
    {
	    //=========================================================
	    // math-uint2x2
	    //=========================================================
        /// <summary>Return the uint2x2 transpose of a uint2x2 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        uint2x2 transpose(const uint2x2& v);

        /// <summary>Returns a uint hash code of a uint2x2 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const uint2x2& v); 

        /// <summary>
        /// Returns a uint2 vector hash code of a uint2x2 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint2 hash of the argument.</returns>
        uint2 hashwide(const uint2x2& v);
    }

} // namespace ecs

