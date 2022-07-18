#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/double4x3.gen.cs
#pragma pack(push,1)
	struct double4x3
	{
	public:
        static const double4x3  zero;       /// <summary>double4x3 zero value.</summary>
		union {
			struct
			{
				double4	c0;	/// <summary>Column 0 of the matrix.</summary>
				double4 c1;	/// <summary>Column 1 of the matrix.</summary>
				double4 c2;	/// <summary>Column 2 of the matrix.</summary>
			};
			double4		data[3];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
        double4x3() : c0(0), c1(0), c2(0) {}
		double4x3(const double4& _c0, const double4& _c1, const double4& _c2) { c0 = _c0;	c1 = _c1;	c2 = _c2; }

        /// <summary>Constructs a double4x3 matrix from 12 double values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        double4x3(  double m00, double m01, double m02,
                    double m10, double m11, double m12,
                    double m20, double m21, double m22,
                    double m30, double m31, double m32)
        {
            c0 = double4(m00, m10, m20, m30);
            c1 = double4(m01, m11, m21, m31);
            c2 = double4(m02, m12, m22, m32);
        }

        double4x3(bool v);
        double4x3(uint v)           {   c0 = v;     c1 = v;     c2 = v;     }
		double4x3(int v)    		{   c0 = v;     c1 = v;     c2 = v;		}
        double4x3(float v)          {   c0 = v;     c1 = v;     c2 = v;     }
        double4x3(double v)         {   c0 = v;     c1 = v;     c2 = v;     }


        double4x3(const bool4x3 v);
        double4x3(const uint4x3& v);
        double4x3(const int4x3& v);
        double4x3(const float4x3& v);
        double4x3(const double4x3& v);

        //=========================================================
        // OPERATORS
        //=========================================================
        //=========================================================
        // Assignment operators : T&
        //=========================================================
        // simple assignment	            a = b	
        double4x3& operator = (const double4x3& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1;  this->c2 = rhs.c2;  return (*this); }
		// addition assignment	            a += b	
        double4x3& operator +=(const double4x3& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; return (*this); }
		// subtraction assignment	        a -= b	
        double4x3& operator -=(const double4x3& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; return (*this); }
		// multiplication assignment	    a *= b	
        double4x3& operator *=(const double4x3& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; return (*this); }
		// division assignment	            a /= b	
        double4x3& operator /=(const double4x3& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; return (*this); }
		// modulo assignment	            a %= b	
        double4x3& operator %=(const double4x3& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; return (*this); }

        // bitwise AND assignment	        a &= b	
        // bitwise OR assignment	        a |= b	
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b

        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
        double4x3& operator ++ ()                               { ++this->c0; ++this->c1; ++this->c2; return (*this);   }
		// pre - decrement  : 	--a		T&
        double4x3& operator -- ()                               { --this->c0; --this->c1; --this->c2; return (*this);   }
		// post-increment   : 	a++
        double4x3  operator ++ (int)                            { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
        double4x3  operator -- (int)							{ auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
        double4x3 operator + () const                           { return double4x3(+this->c0, +this->c1, +this->c2); }
		// unary minus      :   -a
        double4x3 operator - () const                           { return double4x3(-this->c0, -this->c1, -this->c2); }

        // addition         :   a + b
        double4x3 operator + (const double4x3& rhs)     const   { return double4x3(this->c0 + rhs.c0, this->c1 + rhs.c1, this->c2 + rhs.c2); }
        double4x3 operator + (double rhs)               const   { return double4x3(this->c0 + rhs, this->c1 + rhs, this->c2 + rhs); }
        friend double4x3 operator + (double lhs, const double4x3& rhs) { return double4x3(lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2); }

        // subtraction      :   a - b
        double4x3 operator - (const double4x3& rhs)     const   { return double4x3(this->c0 - rhs.c0, this->c1 - rhs.c1, this->c2 - rhs.c2); }
        double4x3 operator - (double rhs)               const   { return double4x3(this->c0 - rhs, this->c1 - rhs, this->c2 - rhs); }
        friend double4x3 operator - (double lhs, const double4x3& rhs) { return double4x3(lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2); }

        // multiplication   :   a * b
        double4x3 operator * (const double4x3& rhs)     const   { return double4x3(this->c0 * rhs.c0, this->c1 * rhs.c1, this->c2 * rhs.c2); }
        double4x3 operator * (double rhs)               const   { return double4x3(this->c0 * rhs, this->c1 * rhs, this->c2 * rhs); }
        friend double4x3 operator * (double lhs, const double4x3& rhs) { return double4x3(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2); }

        // division         :   a / b
        double4x3 operator / (const double4x3& rhs)     const   { return double4x3(this->c0 / rhs.c0, this->c1 / rhs.c1, this->c2 / rhs.c2); }
        double4x3 operator / (double rhs)               const   { return double4x3(this->c0 / rhs, this->c1 / rhs, this->c2 / rhs); }
        friend double4x3 operator / (double lhs, const double4x3& rhs) { return double4x3(lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2); }

        // modulo           :   a % b
        double4x3 operator % (const double4x3& rhs)     const   { return double4x3(this->c0 % rhs.c0, this->c1 % rhs.c1, this->c2 % rhs.c2); }
        double4x3 operator % (double rhs)               const   { return double4x3(this->c0 % rhs, this->c1 % rhs, this->c2 % rhs); }
        friend double4x3 operator % (double lhs, const double4x3& rhs) { return double4x3(lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2); }
        
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
        bool4x3 operator == (const double4x3& rhs)      const   { return bool4x3 (this->c0 == rhs.c0, this->c1 == rhs.c1, this->c2 == rhs.c2); }
        bool4x3 operator == (double rhs)                const   { return bool4x3 (this->c0 == rhs, this->c1 == rhs, this->c2 == rhs); }
        friend bool4x3 operator == (double lhs, const double4x3& rhs) { return bool4x3 (lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2); }

        // not equal to     :   a != b
        bool4x3 operator != (const double4x3& rhs)      const   { return bool4x3 (this->c0 != rhs.c0, this->c1 != rhs.c1, this->c2 != rhs.c2); }
        bool4x3 operator != (double rhs)                const   { return bool4x3 (this->c0 != rhs, this->c1 != rhs, this->c2 != rhs); }
        friend bool4x3 operator != (double lhs, const double4x3& rhs) { return bool4x3 (lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2); }

        // less than        :   a < b
        bool4x3 operator < (const double4x3& rhs)       const   { return bool4x3 (this->c0 < rhs.c0, this->c1 < rhs.c1, this->c2 < rhs.c2); }
        bool4x3 operator < (double rhs)                 const   { return bool4x3 (this->c0 < rhs, this->c1 < rhs, this->c2 < rhs); }
        friend bool4x3 operator < (double lhs, const double4x3& rhs) { return bool4x3 (lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2); }

        // greater than     :   a > b
        bool4x3 operator > (const double4x3& rhs)       const   { return bool4x3 (this->c0 > rhs.c0, this->c1 > rhs.c1, this->c2 > rhs.c2); }
        bool4x3 operator > (double rhs)                 const   { return bool4x3 (this->c0 > rhs, this->c1 > rhs, this->c2 > rhs); }
        friend bool4x3 operator > (double lhs, const double4x3& rhs) { return bool4x3 (lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2); }

        // less than or equal to    : a <= b	
        bool4x3 operator <= (const double4x3& rhs)      const   { return bool4x3 (this->c0 <= rhs.c0, this->c1 <= rhs.c1, this->c2 <= rhs.c2); }
        bool4x3 operator <= (double rhs)                const   { return bool4x3 (this->c0 <= rhs, this->c1 <= rhs, this->c2 <= rhs); }
        friend bool4x3 operator <= (double lhs, const double4x3& rhs) { return bool4x3 (lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2); }

        // greater than or equal to : a >= b
        bool4x3 operator >= (const double4x3& rhs)      const   { return bool4x3 (this->c0 >= rhs.c0, this->c1 >= rhs.c1, this->c2 >= rhs.c2); }
        bool4x3 operator >= (double rhs)                const   { return bool4x3 (this->c0 >= rhs, this->c1 >= rhs, this->c2 >= rhs); }
        friend bool4x3 operator >= (double lhs, const double4x3& rhs) { return bool4x3 (lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2); }

        //=========================================================
        // Conversion operators
        //=========================================================

        //=========================================================
        // member access
        //=========================================================
        /// <summary>Returns the double4 element at a specified index.</summary>
        double4& operator[] (int index)
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
        /// <summary>Returns true if the double4x3 is equal to a given double4x3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const double4x3& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2); }

        /// <summary>Returns true if the double4x3 is equal to a given double4x3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is double4x3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the double4x3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the double4x3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("double4x3({0}, {1}, {2},  {3}, {4}, {5},  {6}, {7}, {8},  {9}, {10}, {11})", c0.x, c1.x, c2.x, c0.y, c1.y, c2.y, c0.z, c1.z, c2.z, c0.w, c1.w, c2.w);
        }
	};
    __declspec(selectany) const double4x3   double4x3::zero = double4x3(0, 0, 0);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-double4x3
        //=========================================================
        /// <summary>Return the double3x4 transpose of a double4x3 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        double3x4 transpose(const double4x3& v);

        /// <summary>Returns a uint hash code of a double4x3 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const double4x3& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a double4x3 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const double4x3& v);
    }

} // namespace ecs

