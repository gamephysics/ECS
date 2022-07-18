#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/double3x4.gen.cs
#pragma pack(push,1)
	struct double3x4
	{
	public:
		static const double3x4		zero;       /// <summary>double2x3 zero value.</summary>
		union {
			struct
			{
				double3	c0;	/// <summary>Column 0 of the matrix.</summary>
				double3 c1;	/// <summary>Column 1 of the matrix.</summary>
				double3 c2;	/// <summary>Column 2 of the matrix.</summary>
				double3 c3;	/// <summary>Column 3 of the matrix.</summary>
			};
			double3		data[4];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
        double3x4() : c0(0), c1(0), c2(0), c3(0) {}
		double3x4(const double3& _c0, const double3& _c1, const double3& _c2, const double3& _c3) { c0 = _c0;	c1 = _c1;	c2 = _c2;	c3 = _c3;	}

        /// <summary>Constructs a double3x4 matrix from 12 double values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        double3x4(  double m00, double m01, double m02, double m03,
                    double m10, double m11, double m12, double m13,
                    double m20, double m21, double m22, double m23)
        {
            c0 = double3(m00, m10, m20);
            c1 = double3(m01, m11, m21);
            c2 = double3(m02, m12, m22);
            c3 = double3(m03, m13, m23);
        }

        double3x4(bool v);
        double3x4(uint v)               {   c0 = v;     c1 = v;     c2 = v;     c3 = v;     }
        double3x4(int v)                {   c0 = v;     c1 = v;     c2 = v;     c3 = v;     }
        double3x4(float v)              {   c0 = v;     c1 = v;     c2 = v;     c3 = v;     }
        double3x4(double v)             {   c0 = v;     c1 = v;     c2 = v;     c3 = v;     }

        double3x4(const bool3x4& v);
        double3x4(const uint3x4& v);
        double3x4(const int3x4& v);
        double3x4(const float3x4& v);
        double3x4(const double3x4& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		double3x4& operator = (const double3x4& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1;  this->c2 = rhs.c2;  this->c3 = rhs.c3;  return (*this); }
		// addition assignment	            a += b	
		double3x4& operator +=(const double3x4& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; this->c3 += rhs.c3; return (*this); }
		// subtraction assignment	        a -= b	
		double3x4& operator -=(const double3x4& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; this->c3 -= rhs.c3; return (*this); }
		// multiplication assignment	    a *= b	
		double3x4& operator *=(const double3x4& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; this->c3 *= rhs.c3; return (*this); }
		// division assignment	            a /= b	
		double3x4& operator /=(const double3x4& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; this->c3 /= rhs.c3; return (*this); }
		// modulo assignment	            a %= b	
		double3x4& operator %=(const double3x4& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; this->c3 %= rhs.c3; return (*this); }

		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
		double3x4& operator ++ ()                               { ++this->c0; ++this->c1; ++this->c2; ++this->c3; return (*this);   }
		// pre - decrement  : 	--a		T&
		double3x4& operator -- ()                               { --this->c0; --this->c1; --this->c2; --this->c3; return (*this);   }
		// post-increment   : 	a++
		double3x4  operator ++ (int)                            { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
		double3x4  operator -- (int)							{ auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		double3x4 operator + () const                           { return double3x4(+this->c0, +this->c1, +this->c2, +this->c3); }
		// unary minus      :   -a
		double3x4 operator - () const                           { return double3x4(-this->c0, -this->c1, -this->c2, -this->c3); }

		// addition         :   a + b
        double3x4 operator + (const double3x4& rhs)     const   { return double3x4(this->c0 + rhs.c0,   this->c1 + rhs.c1,      this->c2 + rhs.c2,      this->c3 + rhs.c3); }
        double3x4 operator + (double rhs)               const   { return double3x4(this->c0 + rhs,      this->c1 + rhs,         this->c2 + rhs,         this->c3 + rhs); }
        friend double3x4 operator + (double lhs, const double3x4& rhs) { return double3x4(lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2, lhs + rhs.c3); }

        // subtraction      :   a - b
        double3x4 operator - (const double3x4& rhs)     const   { return double3x4(this->c0 - rhs.c0,   this->c1 - rhs.c1,      this->c2 - rhs.c2,      this->c3 - rhs.c3); }
        double3x4 operator - (double rhs)               const   { return double3x4(this->c0 - rhs,      this->c1 - rhs,         this->c2 - rhs,         this->c3 - rhs); }
        friend double3x4 operator - (double lhs, const double3x4& rhs) { return double3x4(lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2, lhs - rhs.c3); }

        // multiplication   :   a * b
        double3x4 operator * (const double3x4& rhs)     const   { return double3x4(this->c0 * rhs.c0,   this->c1 * rhs.c1,      this->c2 * rhs.c2,      this->c3 * rhs.c3); }
        double3x4 operator * (double rhs)               const   { return double3x4(this->c0 * rhs,      this->c1 * rhs,         this->c2 * rhs,         this->c3 * rhs); }
        friend double3x4 operator * (double lhs, const double3x4& rhs) { return double3x4(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2, lhs * rhs.c3); }
        
        // division         :   a / b
        double3x4 operator / (const double3x4& rhs)     const   { return double3x4(this->c0 / rhs.c0,   this->c1 / rhs.c1,      this->c2 / rhs.c2,      this->c3 / rhs.c3); }
        double3x4 operator / (double rhs)               const   { return double3x4(this->c0 / rhs,      this->c1 / rhs,         this->c2 / rhs,         this->c3 / rhs); }
        friend double3x4 operator / (double lhs, const double3x4& rhs) { return double3x4(lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2, lhs / rhs.c3); }

        // modulo           :   a % b
        double3x4 operator % (const double3x4& rhs)     const   { return double3x4(this->c0 % rhs.c0,   this->c1 % rhs.c1,      this->c2 % rhs.c2,      this->c3 % rhs.c3); }
        double3x4 operator % (double rhs)               const   { return double3x4(this->c0 % rhs,      this->c1 % rhs,         this->c2 % rhs,         this->c3 % rhs); }
        friend double3x4 operator % (double lhs, const double3x4& rhs) { return double3x4(lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2, lhs % rhs.c3); }
		
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
        bool3x4 operator == (const double3x4& rhs)      const   { return bool3x4(this->c0 == rhs.c0,    this->c1 == rhs.c1,     this->c2 == rhs.c2,     this->c3 == rhs.c3); }
        bool3x4 operator == (double rhs)                const   { return bool3x4(this->c0 == rhs,       this->c1 == rhs,        this->c2 == rhs,        this->c3 == rhs); }
        friend bool3x4 operator == (double lhs, const double3x4& rhs) { return bool3x4(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2, lhs == rhs.c3); }

        // not equal to     :   a != b
        bool3x4 operator != (const double3x4& rhs)      const   { return bool3x4(this->c0 != rhs.c0,    this->c1 != rhs.c1,     this->c2 != rhs.c2,     this->c3 != rhs.c3); }
        bool3x4 operator != (double rhs)                const   { return bool3x4(this->c0 != rhs,       this->c1 != rhs,        this->c2 != rhs,        this->c3 != rhs); }
        friend bool3x4 operator != (double lhs, const double3x4& rhs) { return bool3x4(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2, lhs != rhs.c3); }

        // less than        :   a < b
        bool3x4 operator < (const double3x4& rhs)       const   { return bool3x4(this->c0 < rhs.c0,     this->c1 < rhs.c1,      this->c2 < rhs.c2,      this->c3 < rhs.c3); }
        bool3x4 operator < (double rhs)                 const   { return bool3x4(this->c0 < rhs,        this->c1 < rhs,         this->c2 < rhs,         this->c3 < rhs); }
        friend bool3x4 operator < (double lhs, const double3x4& rhs) { return bool3x4(lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2, lhs < rhs.c3); }

        // greater than     :   a > b
        bool3x4 operator > (const double3x4& rhs)       const   { return bool3x4(this->c0 > rhs.c0,     this->c1 > rhs.c1,      this->c2 > rhs.c2,      this->c3 > rhs.c3); }
        bool3x4 operator > (double rhs)                 const   { return bool3x4(this->c0 > rhs,        this->c1 > rhs,         this->c2 > rhs,         this->c3 > rhs); }
        friend bool3x4 operator > (double lhs, const double3x4& rhs) { return bool3x4(lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2, lhs > rhs.c3); }

        // less than or equal to    : a <= b	
        bool3x4 operator <= (const double3x4& rhs)      const   { return bool3x4(this->c0 <= rhs.c0,    this->c1 <= rhs.c1,     this->c2 <= rhs.c2,     this->c3 <= rhs.c3); }
        bool3x4 operator <= (double rhs)                const   { return bool3x4(this->c0 <= rhs,       this->c1 <= rhs,        this->c2 <= rhs,        this->c3 <= rhs); }
        friend bool3x4 operator <= (double lhs, const double3x4& rhs) { return bool3x4(lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2, lhs <= rhs.c3); }

        // greater than or equal to : a >= b
        bool3x4 operator >= (const double3x4& rhs)      const   { return bool3x4(this->c0 >= rhs.c0,    this->c1 >= rhs.c1,     this->c2 >= rhs.c2,     this->c3 >= rhs.c3); }
        bool3x4 operator >= (double rhs)                const   { return bool3x4(this->c0 >= rhs,       this->c1 >= rhs,        this->c2 >= rhs,        this->c3 >= rhs); }
        friend bool3x4 operator >= (double lhs, const double3x4& rhs) { return bool3x4(lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2, lhs >= rhs.c3); }

        //=========================================================
        // Conversion operators
        //=========================================================


        //=========================================================
		// member access
		//=========================================================
		/// <summary>Returns the double3 element at a specified index.</summary>
		double3& operator[] (int index)
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
        /// <summary>Returns true if the double3x4 is equal to a given double3x4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const double3x4& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2) && c3.Equals(rhs.c3); }

        /// <summary>Returns true if the double3x4 is equal to a given double3x4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is double3x4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the double3x4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the double3x4.</summary>
        /// <returns>String representation of the value.</returns>
		std::string ToString()
        {
            return std::format("double3x4({0}, {1}, {2}, {3},  {4}, {5}, {6}, {7},  {8}, {9}, {10}, {11})", c0.x, c1.x, c2.x, c3.x, c0.y, c1.y, c2.y, c3.y, c0.z, c1.z, c2.z, c3.z);
        }
	};
    __declspec(selectany) const double3x4   double3x4::zero = double3x4(0, 0, 0, 0);
#pragma pack(pop)

    namespace math
    {
	    //=========================================================
	    // math-double3x4
	    //=========================================================
        /// <summary>Return the double4x3 transpose of a double3x4 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        double4x3 transpose(const double3x4& v);

        /// <summary>Fast matrix inverse for rigid transforms (orthonormal basis and translation)</summary>
        /// <param name="m">Matrix to invert.</param>
        /// <returns>The inverted matrix.</returns>
        double3x4 fastinverse(const double3x4& m);

        /// <summary>Returns a uint hash code of a double3x4 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const double3x4& v);

        /// <summary>
        /// Returns a uint3 vector hash code of a double3x4 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(const double3x4& v);
    }

} // namespace ecs
