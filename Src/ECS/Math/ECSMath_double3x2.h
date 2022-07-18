#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/double3x2.gen.cs
#pragma pack(push,1)
	struct double3x2
	{
	public:
		static const double3x2		zero;       /// <summary>double3x2 zero value.</summary>
		union {
			struct
			{
				double3 c0;	/// <summary>Column 0 of the matrix.</summary>
				double3 c1;	/// <summary>Column 1 of the matrix.</summary>
			};
			double3		data[2];
		};
	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		double3x2() : c0(0), c1(0) {}
		double3x2(const double3& _c0, const double3& _c1) { c0 = _c0;	c1 = _c1; }
			
        /// <summary>Constructs a double3x2 matrix from 6 double values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        double3x2(  double m00, double m01,
                    double m10, double m11,
                    double m20, double m21)
        {
            c0 = double3(m00, m10, m20);
            c1 = double3(m01, m11, m21);
        }

        double3x2(bool v);
		double3x2(uint v)               {   c0 = v;     c1 = v;     }
        double3x2(int v)                {   c0 = v;     c1 = v;     }
        double3x2(float v)              {   c0 = v;     c1 = v;     }
        double3x2(double v)             {   c0 = v;     c1 = v;     }

        double3x2(const bool3x2& v);
		double3x2(const uint3x2& v);
        double3x2(const int3x2& v);
        double3x2(const float3x2& v);
        double3x2(const double3x2& v);


		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		double3x2& operator = (const double3x2& rhs)            { this->c0 =  rhs.c0; this->c1 =  rhs.c1;  return (*this); }
		// addition assignment	            a += b	
		double3x2& operator +=(const double3x2& rhs)            { this->c0 += rhs.c0; this->c1 += rhs.c1;  return (*this); }
		// subtraction assignment	        a -= b	
		double3x2& operator -=(const double3x2& rhs)            { this->c0 -= rhs.c0; this->c1 -= rhs.c1;  return (*this); }
		// multiplication assignment	    a *= b	
		double3x2& operator *=(const double3x2& rhs)            { this->c0 *= rhs.c0; this->c1 *= rhs.c1;  return (*this); }
		// division assignment	            a /= b	
		double3x2& operator /=(const double3x2& rhs)            { this->c0 /= rhs.c0; this->c1 /= rhs.c1;  return (*this); }
		// modulo assignment	            a %= b	
		double3x2& operator %=(const double3x2& rhs)            { this->c0 %= rhs.c0; this->c1 %= rhs.c1;  return (*this); }
		
		
		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
		double3x2& operator ++ ()                               { ++this->c0; ++this->c1; return (*this);   }
		// pre - decrement  : 	--a		T&
		double3x2& operator -- ()                               { --this->c0; --this->c1; return (*this);   }
		// post-increment   : 	a++
		double3x2 operator ++ (int)                             { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
		double3x2 operator -- (int)                             { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		double3x2 operator + () const                           { return double3x2(+this->c0, +this->c1); }
		// unary minus      :   -a
		double3x2 operator - () const                           { return double3x2(-this->c0, -this->c1); }

		// addition         :   a + b
		double3x2 operator + (const double3x2& rhs)		const	{ return double3x2(this->c0 + rhs.c0,	this->c1 + rhs.c1); }
        double3x2 operator + (double rhs)				const	{ return double3x2(this->c0 + rhs,		this->c1 + rhs); }
        friend double3x2 operator + (double lhs, const double3x2& rhs) { return double3x2(lhs + rhs.c0, lhs + rhs.c1); }

		// subtraction      :   a - b
        double3x2 operator - (const double3x2& rhs)		const	{ return double3x2(this->c0 - rhs.c0,	this->c1 - rhs.c1); }
        double3x2 operator - (double rhs)				const	{ return double3x2(this->c0 - rhs,		this->c1 - rhs); }
        friend double3x2 operator - (double lhs, const double3x2& rhs) { return double3x2(lhs - rhs.c0, lhs - rhs.c1); }

		// multiplication   :   a * b
        double3x2 operator * (const double3x2& rhs)		const	{ return double3x2(this->c0 * rhs.c0,	this->c1 * rhs.c1); }
        double3x2 operator * (double rhs)				const	{ return double3x2(this->c0 * rhs,		this->c1 * rhs); }
        friend double3x2 operator * (double lhs, const double3x2& rhs) { return double3x2(lhs * rhs.c0, lhs * rhs.c1); }

		// division         :   a / b
        double3x2 operator / (const double3x2& rhs)		const	{ return double3x2(this->c0 / rhs.c0,	this->c1 / rhs.c1); }
        double3x2 operator / (double rhs)				const	{ return double3x2(this->c0 / rhs,		this->c1 / rhs); }
        friend double3x2 operator / (double lhs, const double3x2& rhs) { return double3x2(lhs / rhs.c0, lhs / rhs.c1); }

		// modulo           :   a % b
        double3x2 operator % (const double3x2& rhs)		const	{ return double3x2(this->c0 % rhs.c0,	this->c1 % rhs.c1); }
        double3x2 operator % (double rhs)				const	{ return double3x2(this->c0 % rhs,		this->c1 % rhs); }
        friend double3x2 operator % (double lhs, const double3x2& rhs) { return double3x2(lhs % rhs.c0, lhs % rhs.c1); }
		
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
        bool3x2 operator == (const double3x2& rhs)		const	{ return bool3x2(this->c0 == rhs.c0,	this->c1 == rhs.c1); }
        bool3x2 operator == (double rhs)				const	{ return bool3x2(this->c0 == rhs,		this->c1 == rhs); }
		friend bool3x2 operator == (double lhs, const double3x2& rhs) { return bool3x2(lhs == rhs.c0, lhs == rhs.c1); }

		// not equal to     :   a != b
        bool3x2 operator != (const double3x2& rhs)		const	{ return bool3x2(this->c0 != rhs.c0,	this->c1 != rhs.c1); }
        bool3x2 operator != (double rhs)				const	{ return bool3x2(this->c0 != rhs,		this->c1 != rhs); }
		friend bool3x2 operator != (double lhs, const double3x2& rhs) { return bool3x2(lhs != rhs.c0, lhs != rhs.c1); }

		// less than        :   a < b
        bool3x2 operator < (const double3x2& rhs)		const	{ return bool3x2(this->c0 < rhs.c0,		this->c1 < rhs.c1); }
        bool3x2 operator < (double rhs)					const	{ return bool3x2(this->c0 < rhs,		this->c1 < rhs); }
        friend bool3x2 operator < (double lhs, const double3x2& rhs) { return bool3x2(lhs < rhs.c0, lhs < rhs.c1); }

		// greater than     :   a > b
        bool3x2 operator > (const double3x2& rhs)		const	{ return bool3x2(this->c0 > rhs.c0,		this->c1 > rhs.c1); }
        bool3x2 operator > (double rhs)					const	{ return bool3x2(this->c0 > rhs,		this->c1 > rhs); }
        friend bool3x2 operator > (double lhs, const double3x2& rhs) { return bool3x2(lhs > rhs.c0, lhs > rhs.c1); }

		// less than or equal to    : a <= b	
		bool3x2 operator <= (const double3x2& rhs)		const	{ return bool3x2(this->c0 <= rhs.c0,	this->c1 <= rhs.c1); }
        bool3x2 operator <= (double rhs)				const	{ return bool3x2(this->c0 <= rhs,		this->c1 <= rhs); }
        friend bool3x2 operator <= (double lhs, const double3x2& rhs) { return bool3x2(lhs <= rhs.c0, lhs <= rhs.c1); }

		// greater than or equal to : a >= b
        bool3x2 operator >= (const double3x2& rhs)		const	{ return bool3x2(this->c0 >= rhs.c0,	this->c1 >= rhs.c1); }
        bool3x2 operator >= (double rhs)				const	{ return bool3x2(this->c0 >= rhs,		this->c1 >= rhs); }
        friend bool3x2 operator >= (double lhs, const double3x2& rhs) { return bool3x2(lhs >= rhs.c0, lhs >= rhs.c1); }

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
			if (index >= 2)
				throw std::exception("index must be between[0...1]");
#endif
			return data[index];
		}

    	//=========================================================
		// METHOD
		//=========================================================
        /// <summary>Returns true if the double3x2 is equal to a given double3x2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const double3x2& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1); }

        /// <summary>Returns true if the double3x2 is equal to a given double3x2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is double3x2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the double3x2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the double3x2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("double3x2({0}, {1},  {2}, {3},  {4}, {5})", c0.x, c1.x, c0.y, c1.y, c0.z, c1.z);
        }
	};
	__declspec(selectany) const double3x2	double3x2::zero = double3x2(0, 0);
#pragma pack(pop)

	namespace math
	{
		//=========================================================
		// math-double3x2
		//=========================================================
		/// <summary>Return the double2x3 transpose of a double3x2 matrix.</summary>
		/// <param name="v">Value to transpose.</param>
		/// <returns>Transposed value.</returns>
		double2x3 transpose(const double3x2& v);

		/// <summary>Returns a uint hash code of a double3x2 matrix.</summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint hash of the argument.</returns>
		uint hash(const double3x2& v);

		/// <summary>
		/// Returns a uint3 vector hash code of a double3x2 matrix.
		/// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
		/// that are only reduced to a narrow uint hash at the very end instead of at every step.
		/// </summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint3 hash of the argument.</returns>
		uint3 hashwide(const double3x2& v);
	}

} // namespace ecs
