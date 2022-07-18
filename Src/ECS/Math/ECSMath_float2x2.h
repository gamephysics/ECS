#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float2x2.gen.cs
#pragma pack(push,1)
    struct float2x2
	{
	public:
		static const float2x2		identity;   /// <summary>float2x2 identity transform.</summary>
		static const float2x2		zero;       /// <summary>float2x2 zero value.</summary>
		union {
			struct
			{
				float2 c0;	/// <summary>Column 0 of the matrix.</summary>
				float2 c1;	/// <summary>Column 1 of the matrix.</summary>
			};
			float2		data[2];
		};
	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		float2x2() : c0(0.f), c1(0.f) {}
		float2x2(const float2& _c0, const float2& _c1) { c0 = _c0;	c1 = _c1; }

        /// <summary>Constructs a float2x2 matrix from 4 float values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        float2x2(   float m00, float m01,
                    float m10, float m11)
        {
            c0 = float2(m00, m10);
            c1 = float2(m01, m11);
        }


        float2x2(bool v);
        float2x2(uint v)                {   c0 = v;         c1 = v;         }
        float2x2(int v)                 {   c0 = v;         c1 = v;         }
        float2x2(float v)               {   c0 = v;         c1 = v;         }
        float2x2(double v)              {   c0 = (float2)v; c1 = (float2)v; }

        float2x2(const bool2x2& v);
        float2x2(const int2x2& v);
        float2x2(const uint2x2& v);
        float2x2(const float2x2& v);
        float2x2(const double2x2& v);

        //=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		float2x2& operator = (const float2x2& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1; return (*this); }
		// addition assignment	            a += b	
		float2x2& operator +=(const float2x2& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; return (*this); }
		// subtraction assignment	        a -= b	
		float2x2& operator -=(const float2x2& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; return (*this); }
		// multiplication assignment	    a *= b	
		float2x2& operator *=(const float2x2& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; return (*this); }
		// division assignment	            a /= b	
		float2x2& operator /=(const float2x2& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; return (*this); }
		// modulo assignment	            a %= b	
		float2x2& operator %=(const float2x2& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; return (*this); }
        
        // bitwise AND assignment	        a &= b	
        // bitwise OR assignment	        a |= b	
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b

        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
		float2x2& operator ++ ()                            { ++this->c0; ++this->c1; return (*this);   }
		// pre - decrement  : 	--a		T&
		float2x2& operator -- ()                            { --this->c0; --this->c1; return (*this);   }
		// post-increment   : 	a++
		float2x2 operator ++ (int)                          { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
		float2x2 operator -- (int)                          { auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		float2x2 operator + () const                        { return float2x2(+this->c0, +this->c1); }
		// unary minus      :   -a
		float2x2 operator - () const                        { return float2x2(-this->c0, -this->c1); }

		// addition         :   a + b
		float2x2 operator + (const float2x2& rhs)	const	{ return float2x2(this->c0 + rhs.c0,	this->c1 + rhs.c1); }
		float2x2 operator + (float rhs)				const	{ return float2x2(this->c0 + rhs,		this->c1 + rhs); }
		friend float2x2 operator + (float lhs, const float2x2& rhs) { return float2x2(lhs + rhs.c0, lhs + rhs.c1); }

		// subtraction      :   a - b
		float2x2 operator - (const float2x2& rhs)	const	{ return float2x2(this->c0 - rhs.c0,	this->c1 - rhs.c1); }
		float2x2 operator - (float rhs)				const	{ return float2x2(this->c0 - rhs,		this->c1 - rhs); }
		friend float2x2 operator - (float lhs, const float2x2& rhs) { return float2x2(lhs - rhs.c0, lhs - rhs.c1); }

		// multiplication   :   a * b
		float2x2 operator * (const float2x2& rhs)	const	{ return float2x2(this->c0 * rhs.c0,	this->c1 * rhs.c1); }
		float2x2 operator * (float rhs)				const	{ return float2x2(this->c0 * rhs,		this->c1 * rhs); }
		friend float2x2 operator * (float lhs, const float2x2& rhs) { return float2x2(lhs * rhs.c0, lhs * rhs.c1); }

		// division         :   a / b
		float2x2 operator / (const float2x2& rhs)	const	{ return float2x2(this->c0 / rhs.c0,	this->c1 / rhs.c1); }
		float2x2 operator / (float rhs)				const	{ return float2x2(this->c0 / rhs,		this->c1 / rhs); }
		friend float2x2 operator / (float lhs, const float2x2& rhs) { return float2x2(lhs / rhs.c0, lhs / rhs.c1); }

		// modulo           :   a % b
		float2x2 operator % (const float2x2& rhs)	const	{ return float2x2(this->c0 % rhs.c0,	this->c1 % rhs.c1); }
		float2x2 operator % (float rhs)				const	{ return float2x2(this->c0 % rhs,		this->c1 % rhs); }
		friend float2x2 operator % (float lhs, const float2x2& rhs) { return float2x2(lhs % rhs.c0, lhs % rhs.c1); }
		
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
		bool2x2 operator == (const float2x2& rhs)	const	{ return bool2x2(this->c0 == rhs.c0, this->c1 == rhs.c1); }
		bool2x2 operator == (float rhs)				const	{ return bool2x2(this->c0 == rhs, this->c1 == rhs); }
		friend bool2x2 operator == (float lhs, const float2x2& rhs) { return bool2x2(lhs == rhs.c0, lhs == rhs.c1); }

		// not equal to     :   a != b
		bool2x2 operator != (const float2x2& rhs)	const	{ return bool2x2(this->c0 != rhs.c0, this->c1 != rhs.c1); }
		bool2x2 operator != (float rhs)				const	{ return bool2x2(this->c0 != rhs, this->c1 != rhs); }
		friend bool2x2 operator != (float lhs, const float2x2& rhs) { return bool2x2(lhs != rhs.c0, lhs != rhs.c1); }

		// less than        :   a < b
		bool2x2 operator < (const float2x2& rhs)	const	{ return bool2x2(this->c0 < rhs.c0,		this->c1 < rhs.c1); }
		bool2x2 operator < (float rhs)				const	{ return bool2x2(this->c0 < rhs,		this->c1 < rhs); }
		friend bool2x2 operator < (float lhs, const float2x2& rhs) { return bool2x2(lhs < rhs.c0, lhs < rhs.c1); }

		// greater than     :   a > b
		bool2x2 operator > (const float2x2& rhs)	const	{ return bool2x2(this->c0 > rhs.c0,		this->c1 > rhs.c1); }
		bool2x2 operator > (float rhs)				const	{ return bool2x2(this->c0 > rhs,		this->c1 > rhs); }
		friend bool2x2 operator > (float lhs, const float2x2& rhs) { return bool2x2(lhs > rhs.c0, lhs > rhs.c1); }

		// less than or equal to    : a <= b	
		bool2x2 operator <= (const float2x2& rhs)	const	{ return bool2x2(this->c0 <= rhs.c0,	this->c1 <= rhs.c1); }
		bool2x2 operator <= (float rhs)				const	{ return bool2x2(this->c0 <= rhs,		this->c1 <= rhs); }
		friend bool2x2 operator <= (float lhs, const float2x2& rhs) { return bool2x2(lhs <= rhs.c0, lhs <= rhs.c1); }

		// greater than or equal to : a >= b
		bool2x2 operator >= (const float2x2& rhs)	const	{ return bool2x2(this->c0 >= rhs.c0,	this->c1 >= rhs.c1); }
		bool2x2 operator >= (float rhs)				const	{ return bool2x2(this->c0 >= rhs,		this->c1 >= rhs); }
		friend bool2x2 operator >= (float lhs, const float2x2& rhs) { return bool2x2(lhs >= rhs.c0, lhs >= rhs.c1); }

		//=========================================================
		// Conversion operators
		//=========================================================


		//=========================================================
		// member access
		//=========================================================
		/// <summary>Returns the float2 element at a specified index.</summary>
		float2& operator[] (int index)
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
        /// <summary>Returns true if the float2x2 is equal to a given float2x2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float2x2& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1); }

        /// <summary>Returns true if the float2x2 is equal to a given float2x2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float2x2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float2x2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the float2x2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float2x2({0}f, {1}f,  {2}f, {3}f)", c0.x, c1.x, c0.y, c1.y);
        }

		//=========================================================
		// matrix
		//=========================================================
	public:
		/// <summary>
		/// Computes a float2x2 matrix representing a counter-clockwise rotation by an angle in radians.
		/// </summary>
		/// <remarks>
		/// A positive rotation angle will produce a counter-clockwise rotation and a negative rotation angle will
		/// produce a clockwise rotation.
		/// </remarks>
		/// <param name="angle">Rotation angle in radians.</param>
		/// <returns>Returns the 2x2 rotation matrix.</returns>
		static float2x2 Rotate(float angle);

		/// <summary>Returns a float2x2 matrix representing a uniform scaling of both axes by s.</summary>
		/// <param name="s">The scaling factor.</param>
		/// <returns>The float2x2 matrix representing uniform scale by s.</returns>
		static float2x2 Scale(float s);

		/// <summary>Returns a float2x2 matrix representing a non-uniform axis scaling by x and y.</summary>
		/// <param name="x">The x-axis scaling factor.</param>
		/// <param name="y">The y-axis scaling factor.</param>
		/// <returns>The float2x2 matrix representing a non-uniform scale.</returns>
		static float2x2 Scale(float x, float y);

		/// <summary>Returns a float2x2 matrix representing a non-uniform axis scaling by the components of the float2 vector v.</summary>
		/// <param name="v">The float2 containing the x and y axis scaling factors.</param>
		/// <returns>The float2x2 matrix representing a non-uniform scale.</returns>
		static float2x2 Scale(float2 v);
	};
	__declspec(selectany) const float2x2	float2x2::identity	= float2x2(1.f, 0.f, 0.f, 1.f);
	__declspec(selectany) const float2x2	float2x2::zero		= float2x2(0.f, 0.f);
#pragma pack(pop)

	namespace math
	{
		//=========================================================
		// math-float2x2
		//=========================================================
		/// <summary>Return the float2x2 transpose of a float2x2 matrix.</summary>
		/// <param name="v">Value to transpose.</param>
		/// <returns>Transposed value.</returns>
		float2x2 transpose(const float2x2& v);

		/// <summary>Returns the float2x2 full inverse of a float2x2 matrix.</summary>
		/// <param name="m">Matrix to invert.</param>
		/// <returns>The inverted matrix.</returns>
		float2x2 inverse(const float2x2& m);

		/// <summary>Returns the determinant of a float2x2 matrix.</summary>
		/// <param name="m">Matrix to use when computing determinant.</param>
		/// <returns>The determinant of the matrix.</returns>
		float determinant(const float2x2& m);

		/// <summary>Returns a uint hash code of a float2x2 matrix.</summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint hash of the argument.</returns>
		uint hash(const float2x2& v);

		/// <summary>
		/// Returns a uint2 vector hash code of a float2x2 matrix.
		/// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
		/// that are only reduced to a narrow uint hash at the very end instead of at every step.
		/// </summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint2 hash of the argument.</returns>
		uint2 hashwide(const float2x2& v);
	}

} // namespace ecs
