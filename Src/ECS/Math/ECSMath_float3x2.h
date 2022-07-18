#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float3x2.gen.cs
#pragma pack(push,1)
	struct float3x2
	{
	public:
		static const float3x2		zero;       /// <summary>float3x2 zero value.</summary>
		union {
			struct
			{
				float3 c0;	/// <summary>Column 0 of the matrix.</summary>
				float3 c1;	/// <summary>Column 1 of the matrix.</summary>
			};
			float3		data[2];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		float3x2() : c0(0.f), c1(0.f) {}
		float3x2(const float3& _c0, const float3& _c1) { c0 = _c0;	c1 = _c1; }

        /// <summary>Constructs a float3x2 matrix from 6 float values given in row-major order.</summary>
        float3x2(   float m00, float m01,
                    float m10, float m11,
                    float m20, float m21)
        {
            c0 = float3(m00, m10, m20);
            c1 = float3(m01, m11, m21);
        }

        float3x2(bool v);
		float3x2(uint v)        		{   c0 = v;             c1 = v;             }
        float3x2(int v) 		        {   c0 = v;             c1 = v;             }
        float3x2(float v)               {   c0 = v;             c1 = v;             }
		float3x2(double v)      		{   c0 = (float3)v;	    c1 = (float3)v;     }

        float3x2(const bool3x2& v);
		float3x2(const uint3x2& v);
        float3x2(const int3x2& v);
		float3x2(const float3x2& v);
        float3x2(const double3x2& v);

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
        float3x2 operator + (const float3x2& rhs)   const   { return float3x2(this->c0 + rhs.c0,    this->c1 + rhs.c1); }
        float3x2 operator + (float rhs)             const   { return float3x2(this->c0 + rhs,       this->c1 + rhs); }
        friend float3x2 operator + (float lhs, const float3x2& rhs) { return float3x2(lhs + rhs.c0, lhs + rhs.c1); }

        // subtraction      :   a - b
        float3x2 operator - (const float3x2& rhs)   const   { return float3x2(this->c0 - rhs.c0,    this->c1 - rhs.c1); }
        float3x2 operator - (float rhs)             const   { return float3x2(this->c0 - rhs,       this->c1 - rhs); }
        friend float3x2 operator - (float lhs, const float3x2& rhs) { return float3x2(lhs - rhs.c0, lhs - rhs.c1); }

        // multiplication   :   a * b
        float3x2 operator * (const float3x2& rhs)   const   { return float3x2(this->c0 * rhs.c0,    this->c1 * rhs.c1); }
        float3x2 operator * (float rhs)             const   { return float3x2(this->c0 * rhs,       this->c1 * rhs); }
        friend float3x2 operator * (float lhs, const float3x2& rhs) { return float3x2(lhs * rhs.c0, lhs * rhs.c1); }

        // division         :   a / b
        float3x2 operator / (const float3x2& rhs)   const   { return float3x2(this->c0 / rhs.c0,    this->c1 / rhs.c1); }
        float3x2 operator / (float rhs)             const   { return float3x2(this->c0 / rhs,       this->c1 / rhs); }
        friend float3x2 operator / (float lhs, const float3x2& rhs) { return float3x2(lhs / rhs.c0, lhs / rhs.c1); }

        // modulo           :   a % b
        float3x2 operator % (const float3x2& rhs)   const   { return float3x2(this->c0 % rhs.c0,    this->c1 % rhs.c1); }
        float3x2 operator % (float rhs)             const   { return float3x2(this->c0 % rhs,       this->c1 % rhs); }
        friend float3x2 operator % (float lhs, const float3x2& rhs) { return float3x2(lhs % rhs.c0, lhs % rhs.c1); }

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
        bool3x2 operator == (const float3x2& rhs)   const   { return bool3x2(this->c0 == rhs.c0,    this->c1 == rhs.c1); }
        bool3x2 operator == (float rhs)             const   { return bool3x2(this->c0 == rhs,       this->c1 == rhs); }
        friend bool3x2 operator == (float lhs, const float3x2& rhs) { return bool3x2(lhs == rhs.c0, lhs == rhs.c1); }

        // not equal to     :   a != b
        bool3x2 operator != (const float3x2& rhs)   const   { return bool3x2(this->c0 != rhs.c0,    this->c1 != rhs.c1); }
        bool3x2 operator != (float rhs)             const   { return bool3x2(this->c0 != rhs,       this->c1 != rhs); }
        friend bool3x2 operator != (float lhs, const float3x2& rhs) { return bool3x2(lhs != rhs.c0, lhs != rhs.c1); }

        // less than        :   a < b
        bool3x2 operator < (const float3x2& rhs)    const   { return bool3x2(this->c0 < rhs.c0,     this->c1 < rhs.c1); }
        bool3x2 operator < (float rhs)              const   { return bool3x2(this->c0 < rhs,        this->c1 < rhs); }
        friend bool3x2 operator < (float lhs, const float3x2& rhs) { return bool3x2(lhs < rhs.c0, lhs < rhs.c1); }

        // greater than     :   a > b
        bool3x2 operator > (const float3x2& rhs)    const   { return bool3x2(this->c0 > rhs.c0,     this->c1 > rhs.c1); }
        bool3x2 operator > (float rhs)              const   { return bool3x2(this->c0 > rhs,        this->c1 > rhs); }
        friend bool3x2 operator > (float lhs, const float3x2& rhs) { return bool3x2(lhs > rhs.c0, lhs > rhs.c1); }

        // less than or equal to    : a <= b	
        bool3x2 operator <= (const float3x2& rhs)   const   { return bool3x2(this->c0 <= rhs.c0,    this->c1 <= rhs.c1); }
        bool3x2 operator <= (float rhs)             const   { return bool3x2(this->c0 <= rhs,       this->c1 <= rhs); }
        friend bool3x2 operator <= (float lhs, const float3x2& rhs) { return bool3x2(lhs <= rhs.c0, lhs <= rhs.c1); }

        // greater than or equal to : a >= b
        bool3x2 operator >= (const float3x2& rhs)   const   { return bool3x2(this->c0 >= rhs.c0,    this->c1 >= rhs.c1); }
        bool3x2 operator >= (float rhs)             const   { return bool3x2(this->c0 >= rhs,       this->c1 >= rhs); }
        friend bool3x2 operator >= (float lhs, const float3x2& rhs) { return bool3x2(lhs >= rhs.c0, lhs >= rhs.c1); }

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
			if (index >= 2)
				throw std::exception("index must be between[0...1]");
#endif
			return data[index];
		}

		//=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the float3x2 is equal to a given float3x2, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float3x2& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1); }

        /// <summary>Returns true if the float3x2 is equal to a given float3x2, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float3x2 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float3x2.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the float3x2.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float3x2({0}f, {1}f,  {2}f, {3}f,  {4}f, {5}f)", c0.x, c1.x, c0.y, c1.y, c0.z, c1.z);
        }
	};
    __declspec(selectany) const float3x2    float3x2::zero = float3x2(0.f, 0.f);
#pragma pack(pop)

    namespace math
    {
	    //=========================================================
	    // math-float3x2
	    //=========================================================
        /// <summary>Return the float2x3 transpose of a float3x2 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        float2x3 transpose(const float3x2& v);

        /// <summary>Returns a uint hash code of a float3x2 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const float3x2& v);

        /// <summary>
        /// Returns a uint3 vector hash code of a float3x2 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(const float3x2& v);
    }

} // namespace ecs
