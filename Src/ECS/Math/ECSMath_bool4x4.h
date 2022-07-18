#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/bool4x4.gen.cs
#pragma pack(push,1)
	struct bool4x4
	{
	public:
		union {
			struct
			{
				bool4 c0;	/// <summary>Column 0 of the matrix.</summary>
				bool4 c1;	/// <summary>Column 1 of the matrix.</summary>
				bool4 c2;	/// <summary>Column 2 of the matrix.</summary>
				bool4 c3;	/// <summary>Column 3 of the matrix.</summary>
			};
			bool4		data[4];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		bool4x4() : c0(false), c1(false), c2(false), c3(false) {}
		bool4x4(const bool4& _c0, const bool4& _c1, const bool4& _c2, const bool4& _c3) { c0 = _c0;	c1 = _c1;	c2 = _c2;	c3 = _c3;  }

        /// <summary>Constructs a bool4x4 matrix from 16 bool values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        bool4x4(bool m00, bool m01, bool m02, bool m03,
                bool m10, bool m11, bool m12, bool m13,
                bool m20, bool m21, bool m22, bool m23,
                bool m30, bool m31, bool m32, bool m33)
        {
            c0 = bool4(m00, m10, m20, m30);
            c1 = bool4(m01, m11, m21, m31);
            c2 = bool4(m02, m12, m22, m32);
            c3 = bool4(m03, m13, m23, m33);
        }

        /// <summary>Constructs a bool4x4 matrix from a single bool value by assigning it to every component.</summary>
        /// <param name="v">bool to convert to bool4x4</param>
        bool4x4(bool v)             {   c0 = v;     c1 = v;     c2 = v;     c3 = v;     }


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
        bool4x4 operator & (const bool4x4& rhs)		const	{ return bool4x4(this->c0 & rhs.c0,		this->c1 & rhs.c1,		this->c2 & rhs.c2,		this->c3 & rhs.c3); }
        bool4x4 operator & (bool rhs)				const	{ return bool4x4(this->c0 & rhs,		this->c1 & rhs,			this->c2 & rhs,			this->c3 & rhs); }
		friend bool4x4 operator & (bool lhs, const bool4x4& rhs) { return bool4x4(lhs & rhs.c0, lhs & rhs.c1, lhs & rhs.c2, lhs & rhs.c3); }

		// bitwise OR       :   a | b
        bool4x4 operator | (const bool4x4& rhs)		const	{ return bool4x4(this->c0 | rhs.c0,		this->c1 | rhs.c1,		this->c2 | rhs.c2,		this->c3 | rhs.c3); }
        bool4x4 operator | (bool rhs)				const	{ return bool4x4(this->c0 | rhs,		this->c1 | rhs,			this->c2 | rhs,			this->c3 | rhs); }
		friend bool4x4 operator | (bool lhs, const bool4x4& rhs) { return bool4x4(lhs | rhs.c0, lhs | rhs.c1, lhs | rhs.c2, lhs | rhs.c3); }

		// bitwise XOR      :   a ^ b
        bool4x4 operator ^ (const bool4x4& rhs)		const	{ return bool4x4(this->c0 ^ rhs.c0,		this->c1 ^ rhs.c1,		this->c2 ^ rhs.c2,		this->c3 ^ rhs.c3); }
        bool4x4 operator ^ (bool rhs)				const	{ return bool4x4(this->c0 ^ rhs,		this->c1 ^ rhs,			this->c2 ^ rhs,			this->c3 ^ rhs); }
		friend bool4x4 operator ^ (bool lhs, const bool4x4& rhs) { return bool4x4(lhs ^ rhs.c0, lhs ^ rhs.c1, lhs ^ rhs.c2, lhs ^ rhs.c3); }
		
		// bitwise left shift : a << b
		// bitwise right shift: a >> b

		//=========================================================
		// Logical operators
		//=========================================================
		// negation	        :   not a, !a
		bool4x4 operator ! ()   const						{ return bool4x4(!this->c0, !this->c1, !this->c2, !this->c3); }
		// AND	            :   a and b, a && b
		// inclusive OR	    :   a or b,  a || b

		//=========================================================
		// Comparison operators
		//=========================================================
		// equal to         :   a == 
        bool4x4 operator == (const bool4x4& rhs)	const	{ return bool4x4(this->c0 == rhs.c0,	this->c1 == rhs.c1,		this->c2 == rhs.c2,		this->c3 == rhs.c3); }
        bool4x4 operator == (bool rhs)				const	{ return bool4x4(this->c0 == rhs,		this->c1 == rhs,		this->c2 == rhs,		this->c3 == rhs); }
		friend bool4x4 operator ==(bool lhs, const bool4x4& rhs) { return bool4x4(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2, lhs == rhs.c3); }

		// not equal to     :   a != b
        bool4x4 operator != (const bool4x4& rhs)	const	{ return bool4x4(this->c0 != rhs.c0,	this->c1 != rhs.c1,		this->c2 != rhs.c2,		this->c3 != rhs.c3); }
        bool4x4 operator != (bool rhs)				const	{ return bool4x4(this->c0 != rhs,		this->c1 != rhs,		this->c2 != rhs,		this->c3 != rhs); }
		friend bool4x4 operator !=(bool lhs, const bool4x4& rhs) { return bool4x4(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2, lhs != rhs.c3); }

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
        /// <summary>Returns the bool4 element at a specified index.</summary>
		bool4& operator[] (int index)
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
        /// <summary>Returns true if the bool4x4 is equal to a given bool4x4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const bool4x4& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2) && c3.Equals(rhs.c3); }

        /// <summary>Returns true if the bool4x4 is equal to a given bool4x4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is bool4x4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the bool4x4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the bool4x4.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("bool4x4({0}, {1}, {2}, {3},  {4}, {5}, {6}, {7},  {8}, {9}, {10}, {11},  {12}, {13}, {14}, {15})", c0.x, c1.x, c2.x, c3.x, c0.y, c1.y, c2.y, c3.y, c0.z, c1.z, c2.z, c3.z, c0.w, c1.w, c2.w, c3.w);
        }
	};
#pragma pack(pop)

	namespace math
	{
		//=========================================================
		// math-bool4x4
		//=========================================================
		/// <summary>Return the bool4x4 transpose of a bool4x4 matrix.</summary>
		/// <param name="v">Value to transpose.</param>
		/// <returns>Transposed value.</returns>
		bool4x4 transpose(const bool4x4& v);

		/// <summary>Returns a uint hash code of a bool4x4 matrix.</summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint hash of the argument.</returns>
		uint hash(const bool4x4& v);

		/// <summary>
		/// Returns a uint4 vector hash code of a bool4x4 matrix.
		/// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
		/// that are only reduced to a narrow uint hash at the very end instead of at every step.
		/// </summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint4 hash of the argument.</returns>
		uint4 hashwide(const bool4x4& v);
	}

} // namespace ecs