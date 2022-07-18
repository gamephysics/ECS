#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float3x4.gen.cs
#pragma pack(push,1)
	struct float3x4
	{
	public:
		static const float3x4		zero;       /// <summary>float3x4 zero value.</summary>
		union {
			struct
			{
				float3 c0;	/// <summary>Column 0 of the matrix.</summary>
				float3 c1;	/// <summary>Column 1 of the matrix.</summary>
				float3 c2;	/// <summary>Column 2 of the matrix.</summary>
				float3 c3;	/// <summary>Column 3 of the matrix.</summary>
			};
			float3		data[4];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		float3x4() : c0(0.f), c1(0.f), c2(0.f), c3(0.f) {}
		float3x4(const float3& _c0, const float3& _c1, const float3& _c2, const float3& _c3) { c0 = _c0;	c1 = _c1;	c2 = _c2;	c3 = _c3;	}

        /// <summary>Constructs a float3x4 matrix from 12 float values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        float3x4(   float m00, float m01, float m02, float m03,
                    float m10, float m11, float m12, float m13,
                    float m20, float m21, float m22, float m23)
        {
            c0 = float3(m00, m10, m20);
            c1 = float3(m01, m11, m21);
            c2 = float3(m02, m12, m22);
            c3 = float3(m03, m13, m23);
        }
        float3x4(bool v);
		float3x4(uint v)            {   c0 = v;         c1 = v;         c2 = v;         c3 = v;     }
        float3x4(int v)             {   c0 = v;         c1 = v;         c2 = v;         c3 = v;     }
        float3x4(float v)           {   c0 = v;         c1 = v;         c2 = v;         c3 = v;     }
		float3x4(double v)		    {   c0 = (float3)v; c1 = (float3)v; c2 = (float3)v; c3 = (float3)v; }

        float3x4(const bool3x4& v);
        float3x4(const uint3x4& v);
        float3x4(const int3x4& v);
		float3x4(const float3x4& v);
        float3x4(const double3x4& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		float3x4& operator = (const float3x4& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1;  this->c2 = rhs.c2;  this->c3 = rhs.c3;  return (*this); }
		// addition assignment	            a += b	
		float3x4& operator +=(const float3x4& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; this->c3 += rhs.c3; return (*this); }
		// subtraction assignment	        a -= b	
		float3x4& operator -=(const float3x4& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; this->c3 -= rhs.c3; return (*this); }
		// multiplication assignment	    a *= b	
		float3x4& operator *=(const float3x4& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; this->c3 *= rhs.c3; return (*this); }
		// division assignment	            a /= b	
		float3x4& operator /=(const float3x4& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; this->c3 /= rhs.c3; return (*this); }
		// modulo assignment	            a %= b	
		float3x4& operator %=(const float3x4& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; this->c3 %= rhs.c3; return (*this); }

		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
		float3x4& operator ++ ()                            { ++this->c0; ++this->c1; ++this->c2; ++this->c3; return (*this);   }
		// pre - decrement  : 	--a		T&
		float3x4& operator -- ()                            { --this->c0; --this->c1; --this->c2; --this->c3; return (*this);   }
		// post-increment   : 	a++
		float3x4  operator ++ (int)                         { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
		float3x4  operator -- (int)							{ auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		float3x4 operator + () const						{ return float3x4(+this->c0, +this->c1, +this->c2, +this->c3); }
		// unary minus      :   -a
		float3x4 operator - () const                        { return float3x4(-this->c0, -this->c1, -this->c2, -this->c3); }

		// addition         :   a + b
		float3x4 operator + (const float3x4& rhs)	const	{ return float3x4(this->c0 + rhs.c0,	this->c1 + rhs.c1,		this->c2 + rhs.c2,		this->c3 + rhs.c3); }
		float3x4 operator + (float rhs)				const	{ return float3x4(this->c0 + rhs,		this->c1 + rhs,			this->c2 + rhs,			this->c3 + rhs); }
		friend float3x4 operator + (float lhs, const float3x4& rhs) { return float3x4(lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2, lhs + rhs.c3); }

		// subtraction      :   a - b
		float3x4 operator - (const float3x4& rhs)	const	{ return float3x4(this->c0 - rhs.c0,	this->c1 - rhs.c1,		this->c2 - rhs.c2,		this->c3 - rhs.c3); }
		float3x4 operator - (float rhs)				const	{ return float3x4(this->c0 - rhs,		this->c1 - rhs,			this->c2 - rhs,			this->c3 - rhs); }
		friend float3x4 operator - (float lhs, const float3x4& rhs) { return float3x4(lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2, lhs - rhs.c3); }

		// multiplication   :   a * b
		float3x4 operator * (const float3x4& rhs)	const	{ return float3x4(this->c0 * rhs.c0,	this->c1 * rhs.c1,		this->c2 * rhs.c2,		this->c3 * rhs.c3); }
		float3x4 operator * (float rhs)				const	{ return float3x4(this->c0 * rhs,		this->c1 * rhs,			this->c2 * rhs,			this->c3 * rhs); }
		friend float3x4 operator * (float lhs, const float3x4& rhs) { return float3x4(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2, lhs * rhs.c3); }

		// division         :   a / b
		float3x4 operator / (const float3x4& rhs)	const	{ return float3x4(this->c0 / rhs.c0,	this->c1 / rhs.c1,		this->c2 / rhs.c2,		this->c3 / rhs.c3); }
		float3x4 operator / (float rhs)				const	{ return float3x4(this->c0 / rhs,		this->c1 / rhs,			this->c2 / rhs,			this->c3 / rhs); }
		friend float3x4 operator / (float lhs, const float3x4& rhs) { return float3x4(lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2, lhs / rhs.c3); }

		// modulo           :   a % b
		float3x4 operator % (const float3x4& rhs)	const	{ return float3x4(this->c0 % rhs.c0,	this->c1 % rhs.c1,		this->c2 % rhs.c2,		this->c3 % rhs.c3); }
		float3x4 operator % (float rhs)				const	{ return float3x4(this->c0 % rhs,		this->c1 % rhs,			this->c2 % rhs,			this->c3 % rhs); }
		friend float3x4 operator % (float lhs, const float3x4& rhs) { return float3x4(lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2, lhs % rhs.c3); }
		
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
		bool3x4 operator == (const float3x4& rhs)	const	{ return bool3x4(this->c0 == rhs.c0,	this->c1 == rhs.c1,		this->c2 == rhs.c2,		this->c3 == rhs.c3); }
		bool3x4 operator == (float rhs)				const	{ return bool3x4(this->c0 == rhs,		this->c1 == rhs,		this->c2 == rhs,		this->c3 == rhs); }
		friend bool3x4 operator == (float lhs, const float3x4& rhs) { return bool3x4(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2, lhs == rhs.c3); }

		// not equal to     :   a != b
		bool3x4 operator != (const float3x4& rhs)	const	{ return bool3x4(this->c0 != rhs.c0,	this->c1 != rhs.c1,		this->c2 != rhs.c2,		this->c3 != rhs.c3); }
		bool3x4 operator != (float rhs)				const	{ return bool3x4(this->c0 != rhs,		this->c1 != rhs,		this->c2 != rhs,		this->c3 != rhs); }
		friend bool3x4 operator != (float lhs, const float3x4& rhs) { return bool3x4(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2, lhs != rhs.c3); }

		// less than        :   a < b
		bool3x4 operator < (const float3x4& rhs)	const	{ return bool3x4(this->c0 < rhs.c0,		this->c1 < rhs.c1,		this->c2 < rhs.c2,		this->c3 < rhs.c3); }
		bool3x4 operator < (float rhs)				const	{ return bool3x4(this->c0 < rhs,		this->c1 < rhs,			this->c2 < rhs,			this->c3 < rhs); }
		friend bool3x4 operator < (float lhs, const float3x4& rhs) { return bool3x4(lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2, lhs < rhs.c3); }

		// greater than     :   a > b
		bool3x4 operator > (const float3x4& rhs)	const	{ return bool3x4(this->c0 > rhs.c0,		this->c1 > rhs.c1,		this->c2 > rhs.c2,		this->c3 > rhs.c3); }
		bool3x4 operator > (float rhs)				const	{ return bool3x4(this->c0 > rhs,		this->c1 > rhs,			this->c2 > rhs,			this->c3 > rhs); }
		friend bool3x4 operator > (float lhs, const float3x4& rhs) { return bool3x4(lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2, lhs > rhs.c3); }

		// less than or equal to    : a <= b	
		bool3x4 operator <= (const float3x4& rhs)	const	{ return bool3x4(this->c0 <= rhs.c0,	this->c1 <= rhs.c1,		this->c2 <= rhs.c2,		this->c3 <= rhs.c3); }
		bool3x4 operator <= (float rhs)				const	{ return bool3x4(this->c0 <= rhs,		this->c1 <= rhs,		this->c2 <= rhs,		this->c3 <= rhs); }
		friend bool3x4 operator <= (float lhs, const float3x4& rhs) { return bool3x4(lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2, lhs <= rhs.c3); }

		// greater than or equal to : a >= b
		bool3x4 operator >= (const float3x4& rhs)	const	{ return bool3x4(this->c0 >= rhs.c0,	this->c1 >= rhs.c1,		this->c2 >= rhs.c2,		this->c3 >= rhs.c3); }
		bool3x4 operator >= (float rhs)				const	{ return bool3x4(this->c0 >= rhs,		this->c1 >= rhs,		this->c2 >= rhs,		this->c3 >= rhs); }
		friend bool3x4 operator >= (float lhs, const float3x4& rhs) { return bool3x4(lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2, lhs >= rhs.c3); }

		//=========================================================
		// Conversion operators
		//=========================================================


		//=========================================================
		// member access
		//=========================================================
        /// <summary>Returns the float3 element at a specified index.</summary>
		float3& operator[] (int index)
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
        /// <summary>Returns true if the float3x4 is equal to a given float3x4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float3x4& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2) && c3.Equals(rhs.c3); }

        /// <summary>Returns true if the float3x4 is equal to a given float3x4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float3x4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float3x4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the float3x4.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float3x4({0}f, {1}f, {2}f, {3}f,  {4}f, {5}f, {6}f, {7}f,  {8}f, {9}f, {10}f, {11}f)", c0.x, c1.x, c2.x, c3.x, c0.y, c1.y, c2.y, c3.y, c0.z, c1.z, c2.z, c3.z);
        }
	};
#pragma pack(pop)

	namespace math
	{
		//=========================================================
		// math-float3x4
		//=========================================================
		/// <summary>Return the float4x3 transpose of a float3x4 matrix.</summary>
		/// <param name="v">Value to transpose.</param>
		/// <returns>Transposed value.</returns>
		float4x3 transpose(const float3x4& v);

		/// <summary>Fast matrix inverse for rigid transforms (orthonormal basis and translation)</summary>
		/// <param name="m">Matrix to invert.</param>
		/// <returns>The inverted matrix.</returns>
		float3x4 fastinverse(const float3x4& m);

		/// <summary>Returns a uint hash code of a float3x4 matrix.</summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint hash of the argument.</returns>
		uint hash(const float3x4& v);

		/// <summary>
		/// Returns a uint3 vector hash code of a float3x4 matrix.
		/// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
		/// that are only reduced to a narrow uint hash at the very end instead of at every step.
		/// </summary>
		/// <param name="v">Matrix value to hash.</param>
		/// <returns>uint3 hash of the argument.</returns>
		uint3 hashwide(const float3x4& v);
	}

} // namespace ecs