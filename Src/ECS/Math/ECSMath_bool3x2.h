#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/bool3x2.gen.cs
#pragma pack(push,1)
	struct bool3x2
	{
	public:
		union {
			struct
			{
				bool3 c0;	/// <summary>Column 0 of the matrix.</summary>
				bool3 c1;	/// <summary>Column 1 of the matrix.</summary>
			};
			bool3		data[2];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		bool3x2() : c0(false), c1(false) {}
		bool3x2(const bool3& _c0, const bool3& _c1)		{ c0 = _c0;	c1 = _c1; }

        /// <summary>Constructs a bool3x2 matrix from 6 bool values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        bool3x2(bool m00, bool m01,
                bool m10, bool m11,
                bool m20, bool m21)
        {
            c0 = bool3(m00, m10, m20);
            c1 = bool3(m01, m11, m21);
        }

        /// <summary>Constructs a bool3x2 matrix from a single bool value by assigning it to every component.</summary>
        /// <param name="v">bool to convert to bool3x2</param>
        bool3x2(bool v)             {       c0 = v;     c1 = v;     }

        //=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		// addition assignment	            a += b	
		// subtraction assignment	        a -= b	
		// multiplication assignment	    a *= b	
		// division assignment	            a /= b	
		// modulo assignment	            a %= b	

		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
		// pre - decrement  : 	--a		T&
		// post-increment   : 	a++
		// post-decrement   :	a--

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		// unary minus      :   -a
		// addition         :   a + b
		// subtraction      :   a - b
		// multiplication   :   a * b
		// division         :   a / b
		// modulo           :   a % b

		// bitwise NOT      :   ~a
		// bitwise AND      :   a & b
        bool3x2 operator & (const bool3x2& rhs)		const	{ return bool3x2(this->c0 & rhs.c0,		this->c1 & rhs.c1); }
        bool3x2 operator & (bool rhs)				const	{ return bool3x2(this->c0 & rhs,		this->c1 & rhs); }
        friend bool3x2 operator & (bool lhs, const bool3x2& rhs) { return bool3x2(lhs & rhs.c0, lhs & rhs.c1); }

		// bitwise OR       :   a | b
        bool3x2 operator | (const bool3x2& rhs)		const	{ return bool3x2(this->c0 | rhs.c0,		this->c1 | rhs.c1); }
        bool3x2 operator | (bool rhs)				const	{ return bool3x2(this->c0 | rhs,		this->c1 | rhs); }
        friend bool3x2 operator | (bool lhs, const bool3x2& rhs) { return bool3x2(lhs | rhs.c0, lhs | rhs.c1); }

		// bitwise XOR      :   a ^ b
        bool3x2 operator ^ (const bool3x2& rhs)		const	{ return bool3x2(this->c0 ^ rhs.c0,		this->c1 ^ rhs.c1); }
        bool3x2 operator ^ (bool rhs)				const	{ return bool3x2(this->c0 ^ rhs,		this->c1 ^ rhs); }
		friend bool3x2 operator ^ (bool lhs, const bool3x2& rhs) { return bool3x2(lhs ^ rhs.c0, lhs ^ rhs.c1); }
		
		// bitwise left shift : a << b
		// bitwise right shift: a >> b

		//=========================================================
		// Logical operators
		//=========================================================
		// negation	        :   not a, !a
        bool3x2 operator ! ()	const						{ return bool3x2(!this->c0, !this->c1); }
		// AND	            :   a and b, a && b
		// inclusive OR	    :   a or b,  a || b

		//=========================================================
		// Comparison operators
		//=========================================================
		// equal to         :   a == 
        bool3x2 operator == (const bool3x2& rhs)	const	{ return bool3x2(this->c0 == rhs.c0,	this->c1 == rhs.c1); }
        bool3x2 operator == (bool rhs)				const	{ return bool3x2(this->c0 == rhs,		this->c1 == rhs); }
        friend bool3x2 operator == (bool lhs, const bool3x2& rhs) { return bool3x2(lhs == rhs.c0, lhs == rhs.c1); }

		// not equal to     :   a != b
        bool3x2 operator != (const bool3x2& rhs)	const	{ return bool3x2(this->c0 != rhs.c0,	this->c1 != rhs.c1); }
        bool3x2 operator != (bool rhs)				const	{ return bool3x2(this->c0 != rhs,		this->c1 != rhs); }
        friend bool3x2 operator != (bool lhs, const bool3x2& rhs) { return bool3x2(lhs != rhs.c0, lhs != rhs.c1); }

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
		/// <summary>Returns the bool3 element at a specified index.</summary>
		bool3& operator[] (int index)
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
        /// <summary>Returns true if the bool3x2 is equal to a given bool3x2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const bool3x2& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1); }

        /// <summary>Returns true if the bool3x2 is equal to a given bool3x2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o)			{ return o is bool3x2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the bool3x2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode()						{ return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the bool3x2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("bool3x2({0}, {1},  {2}, {3},  {4}, {5})", c0.x, c1.x, c0.y, c1.y, c0.z, c1.z);
        }
	};
#pragma pack(pop)

	namespace math
	{
		//=========================================================
		// math-bool3x2
		//=========================================================
		/// <summary>Return the bool2x3 transpose of a bool3x2 matrix.</summary>
		/// <param name="v">Value to transpose.</param>
		/// <returns>Transposed value.</returns>
		bool2x3 transpose(const bool3x2& v);

		/// <summary>Returns a uint hash code of a bool3x2 matrix.</summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint hash of the argument.</returns>
		uint hash(const bool3x2& v);

		/// <summary>
		/// Returns a uint3 vector hash code of a bool3x2 matrix.
		/// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
		/// that are only reduced to a narrow uint hash at the very end instead of at every step.
		/// </summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint3 hash of the argument.</returns>
		uint3 hashwide(const bool3x2& v);
	}

} // namespace ecs
