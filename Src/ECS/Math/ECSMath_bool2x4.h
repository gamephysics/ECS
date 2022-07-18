#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/bool2x4.gen.cs
#pragma pack(push,1)
	struct bool2x4
	{
    public:
        union {
            struct
            {
                bool2 c0;	/// <summary>Column 0 of the matrix.</summary>
                bool2 c1;	/// <summary>Column 1 of the matrix.</summary>
                bool2 c2;	/// <summary>Column 2 of the matrix.</summary>
                bool2 c3;	/// <summary>Column 2 of the matrix.</summary>
            };
            bool2		data[4];
        };

    public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        bool2x4() : c0(false), c1(false), c2(false), c3(false) {}
        bool2x4(const bool2& _c0, const bool2& _c1, const bool2& _c2, const bool2& _c3)     { c0 = _c0;	c1 = _c1; c2 = _c2; c3 = _c3; }
        
        /// <summary>Constructs a bool2x4 matrix from 8 bool values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        bool2x4(bool m00, bool m01, bool m02, bool m03, 
                bool m10, bool m11, bool m12, bool m13)
        {
            c0 = new bool2(m00, m10);
            c1 = new bool2(m01, m11);
            c2 = new bool2(m02, m12);
            c3 = new bool2(m03, m13);
        }

        /// <summary>Constructs a bool2x4 matrix from a single bool value by assigning it to every component.</summary>
        /// <param name="v">bool to convert to bool2x4</param>
        bool2x4(bool v)         {   c0 = v; c1 = v; c2 = v; c3 = v;     }

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
        bool2x4 operator & (const bool2x4& rhs)     const   { return bool2x4(this->c0 & rhs.c0,     this->c1 & rhs.c1,      this->c2 & rhs.c2,      this->c3 & rhs.c3); }
        bool2x4 operator & (bool rhs)               const   { return bool2x4(this->c0 & rhs,        this->c1 & rhs,         this->c2 & rhs,         this->c3 & rhs); }
        friend bool2x4 operator & (bool lhs, const bool2x4& rhs) { return bool2x4(lhs & rhs.c0, lhs & rhs.c1, lhs & rhs.c2, lhs & rhs.c3); }

        // bitwise OR       :   a | b
        bool2x4 operator | (const bool2x4& rhs)     const   { return bool2x4(this->c0 | rhs.c0,     this->c1 | rhs.c1,      this->c2 | rhs.c2,      this->c3 | rhs.c3); }
        bool2x4 operator | (bool rhs)               const   { return bool2x4(this->c0 | rhs,        this->c1 | rhs,         this->c2 | rhs,         this->c3 | rhs); }
        friend bool2x4 operator | (bool lhs, const bool2x4& rhs) { return bool2x4(lhs | rhs.c0, lhs | rhs.c1, lhs | rhs.c2, lhs | rhs.c3); }

        // bitwise XOR      :   a ^ b
        bool2x4 operator ^ (const bool2x4& rhs)     const   { return bool2x4(this->c0 ^ rhs.c0,     this->c1 ^ rhs.c1,      this->c2 ^ rhs.c2,      this->c3 ^ rhs.c3); }
        bool2x4 operator ^ (bool rhs)               const   { return bool2x4(this->c0 ^ rhs,        this->c1 ^ rhs,         this->c2 ^ rhs,         this->c3 ^ rhs); }
        friend bool2x4 operator ^ (bool lhs, const bool2x4& rhs) { return bool2x4(lhs ^ rhs.c0, lhs ^ rhs.c1, lhs ^ rhs.c2, lhs ^ rhs.c3); }

        // bitwise left shift : a << b
        // bitwise right shift: a >> b

        //=========================================================
        // Logical operators
        //=========================================================
        // negation	        :   not a, !a
        bool2x4 operator ! ()   const                       { return bool2x4(!this->c0, !this->c1, !this->c2, !this->c3); }
        // AND	            :   a and b, a && b
        // inclusive OR	    :   a or b,  a || b

        //=========================================================
        // Comparison operators
        //=========================================================
        // equal to         :   a == 
        bool2x4 operator == (const bool2x4& rhs)    const   { return bool2x4(this->c0 == rhs.c0,    this->c1 == rhs.c1,     this->c2 == rhs.c2,     this->c3 == rhs.c3); }
        bool2x4 operator == (bool rhs)              const   { return bool2x4(this->c0 == rhs,       this->c1 == rhs,        this->c2 == rhs,        this->c3 == rhs); }
        friend bool2x4 operator ==(bool lhs, const bool2x4& rhs) { return bool2x4(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2, lhs == rhs.c3); }

        // not equal to     :   a != b
        bool2x4 operator != (const bool2x4& rhs)    const   { return bool2x4(this->c0 != rhs.c0,    this->c1 != rhs.c1,     this->c2 != rhs.c2,     this->c3 != rhs.c3); }
        bool2x4 operator != (bool rhs)              const   { return bool2x4(this->c0 != rhs,       this->c1 != rhs,        this->c2 != rhs,        this->c3 != rhs); }
        friend bool2x4 operator !=(bool lhs, const bool2x4& rhs) { return bool2x4(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2, lhs != rhs.c3); }

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
		/// <summary>Returns the bool2 element at a specified index.</summary>
		bool2& operator[] (int index)
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
        /// <summary>Returns true if the bool2x4 is equal to a given bool2x4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const bool2x4& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2) && c3.Equals(rhs.c3); }

        /// <summary>Returns true if the bool2x4 is equal to a given bool2x4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o)          { return o is bool2x4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the bool2x4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the bool2x4.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("bool2x4({0}, {1}, {2}, {3},  {4}, {5}, {6}, {7})", c0.x, c1.x, c2.x, c3.x, c0.y, c1.y, c2.y, c3.y);
        }
	};
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-bool2x4
        //=========================================================
        /// <summary>Return the bool4x2 transpose of a bool2x4 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        bool4x2 transpose(const bool2x4& v);

        /// <summary>Returns a uint hash code of a bool2x4 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const bool2x4& v);

        /// <summary>
        /// Returns a uint2 vector hash code of a bool2x4 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint2 hash of the argument.</returns>
        uint2 hashwide(const bool2x4& v);
    }

} // namespace ecs