#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float2x3.gen.cs
#pragma pack(push,1)
	struct float2x3
	{
	public:
		static const float2x3		zero;       /// <summary>float2x3 zero value.</summary>
		union {
			struct
			{
				float2 c0;	/// <summary>Column 0 of the matrix.</summary>
				float2 c1;	/// <summary>Column 1 of the matrix.</summary>
				float2 c2;	/// <summary>Column 2 of the matrix.</summary>
			};
			float2		data[3];
		};
	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
        float2x3() : c0(0.f), c1(0.f), c2(0.f) {}
		float2x3(const float2& _c0, const float2& _c1, const float2& _c2) { c0 = _c0;	c1 = _c1;	c2 = _c2; }

        /// <summary>Constructs a float2x3 matrix from 6 float values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        float2x3(   float m00, float m01, float m02,
                    float m10, float m11, float m12)
        {
            c0 = float2(m00, m10);
            c1 = float2(m01, m11);
            c2 = float2(m02, m12);
        }

        float2x3(bool v);
		float2x3(uint v)		        {	c0 = v;     		c1 = v;     		c2 = v;         	}
        float2x3(int v)         		{	c0 = v;     		c1 = v;     		c2 = v;     		}
        float2x3(float v)               {   c0 = v;             c1 = v;             c2 = v;             }
        float2x3(double v)		        {   c0 = (float2)v;     c1 = (float2)v;     c2 = (float2)v;		}

        float2x3(const bool2x3& v);
        float2x3(const uint2x3& v);
		float2x3(const int2x3& v);
        float2x3(const float2x3& v);
        float2x3(const double2x3& v);

        //=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        float2x3& operator = (const float2x3& rhs)          { this->c0 =  rhs.c0; this->c1 =  rhs.c1; this->c2  = rhs.c2; return (*this); }
		// addition assignment	            a += b	
        float2x3& operator +=(const float2x3& rhs)          { this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; return (*this); }
		// subtraction assignment	        a -= b	
        float2x3& operator -=(const float2x3& rhs)          { this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; return (*this); }
		// multiplication assignment	    a *= b	
        float2x3& operator *=(const float2x3& rhs)          { this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; return (*this); }
		// division assignment	            a /= b	
        float2x3& operator /=(const float2x3& rhs)          { this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; return (*this); }
		// modulo assignment	            a %= b	
        float2x3& operator %=(const float2x3& rhs)          { this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; return (*this); }
		
		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
        float2x3& operator ++ ()                            { ++this->c0; ++this->c1; ++this->c2; return (*this);   }
		// pre - decrement  : 	--a		T&
        float2x3& operator -- ()                            { --this->c0; --this->c1; --this->c2; return (*this);   }
		// post-increment   : 	a++
        float2x3  operator ++ (int)                         { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
        float2x3  operator -- (int)							{ auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
        float2x3 operator + () const                        { return float2x3(+this->c0, +this->c1, +this->c2); }
		// unary minus      :   -a
        float2x3 operator - () const                        { return float2x3(-this->c0, -this->c1, -this->c2); }

		// addition         :   a + b
        float2x3 operator + (const float2x3& rhs)   const   { return float2x3 (this->c0 + rhs.c0,   this->c1 + rhs.c1,  this->c2 + rhs.c2); }
        float2x3 operator + (float rhs)             const   { return float2x3 (this->c0 + rhs,      this->c1 + rhs,     this->c2 + rhs); }
        friend float2x3 operator + (float lhs, const float2x3& rhs) { return float2x3 (lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2); }

        // subtraction      :   a - b
        float2x3 operator - (const float2x3& rhs)   const   { return float2x3 (this->c0 - rhs.c0,   this->c1 - rhs.c1,  this->c2 - rhs.c2); }
        float2x3 operator - (float rhs)             const   { return float2x3 (this->c0 - rhs,      this->c1 - rhs,     this->c2 - rhs); }
        friend float2x3 operator - (float lhs, const float2x3& rhs) { return float2x3 (lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2); }

        // multiplication   :   a * b
        float2x3 operator * (const float2x3& rhs)   const   { return float2x3 (this->c0 * rhs.c0,   this->c1 * rhs.c1,  this->c2 * rhs.c2); }
        float2x3 operator * (float rhs)             const   { return float2x3 (this->c0 * rhs,      this->c1 * rhs,     this->c2 * rhs); }
        friend float2x3 operator * (float lhs, const float2x3& rhs) { return float2x3 (lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2); }

        // division         :   a / b
        float2x3 operator / (const float2x3& rhs)   const   { return float2x3 (this->c0 / rhs.c0,   this->c1 / rhs.c1,  this->c2 / rhs.c2); }
        float2x3 operator / (float rhs)             const   { return float2x3 (this->c0 / rhs,      this->c1 / rhs,     this->c2 / rhs); }
        friend float2x3 operator / (float lhs, const float2x3& rhs) { return float2x3 (lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2); }

        // modulo           :   a % b
        float2x3 operator % (const float2x3& rhs)   const   { return float2x3 (this->c0 % rhs.c0,   this->c1 % rhs.c1,  this->c2 % rhs.c2); }
        float2x3 operator % (float rhs)             const   { return float2x3 (this->c0 % rhs,      this->c1 % rhs,     this->c2 % rhs); }
        friend float2x3 operator % (float lhs, const float2x3& rhs) { return float2x3 (lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2); }
		
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
        bool2x3 operator == (const float2x3& rhs)   const   { return bool2x3(this->c0 == rhs.c0,    this->c1 == rhs.c1, this->c2 == rhs.c2); }
        bool2x3 operator == (float rhs)             const   { return bool2x3(this->c0 == rhs,       this->c1 == rhs,    this->c2 == rhs); }
        friend bool2x3 operator == (float lhs, const float2x3& rhs) { return bool2x3(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2); }

        // not equal to     :   a != b
        bool2x3 operator != (const float2x3& rhs)   const   { return bool2x3(this->c0 != rhs.c0,    this->c1 != rhs.c1, this->c2 != rhs.c2); }
        bool2x3 operator != (float rhs)             const   { return bool2x3(this->c0 != rhs,       this->c1 != rhs,    this->c2 != rhs); }
        friend bool2x3 operator != (float lhs, const float2x3& rhs) { return bool2x3(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2); }

        // less than        :   a < b
        bool2x3 operator < (const float2x3& rhs)    const   { return bool2x3(this->c0 < rhs.c0,     this->c1 < rhs.c1,  this->c2 < rhs.c2); }
        bool2x3 operator < (float rhs)              const   { return bool2x3(this->c0 < rhs,        this->c1 < rhs,     this->c2 < rhs); }
        friend bool2x3 operator < (float lhs, const float2x3& rhs) { return bool2x3(lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2); }

        // greater than     :   a > b
        bool2x3 operator > (const float2x3& rhs)    const   { return bool2x3(this->c0 > rhs.c0,     this->c1 > rhs.c1,  this->c2 > rhs.c2); }
        bool2x3 operator > (float rhs)              const   { return bool2x3(this->c0 > rhs,        this->c1 > rhs,     this->c2 > rhs); }
        friend bool2x3 operator > (float lhs, const float2x3& rhs) { return bool2x3(lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2); }

        // less than or equal to    : a <= b	
        bool2x3 operator <= (const float2x3& rhs)   const   { return bool2x3(this->c0 <= rhs.c0,    this->c1 <= rhs.c1, this->c2 <= rhs.c2); }
        bool2x3 operator <= (float rhs)             const   { return bool2x3(this->c0 <= rhs,       this->c1 <= rhs,    this->c2 <= rhs); }
        friend bool2x3 operator <= (float lhs, const float2x3& rhs) { return bool2x3(lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2); }

        // greater than or equal to : a >= b
        bool2x3 operator >= (const float2x3& rhs)   const   { return bool2x3(this->c0 >= rhs.c0,    this->c1 >= rhs.c1, this->c2 >= rhs.c2); }
        bool2x3 operator >= (float rhs)             const   { return bool2x3(this->c0 >= rhs,       this->c1 >= rhs,    this->c2 >= rhs); }
        friend bool2x3 operator >= (float lhs, const float2x3& rhs) { return bool2x3(lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2); }

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
			if (index >= 3)
				throw std::exception("index must be between[0...2]");
#endif
			return data[index];
		}

        //=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the float2x3 is equal to a given float2x3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float2x3& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2); }

        /// <summary>Returns true if the float2x3 is equal to a given float2x3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float2x3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float2x3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the float2x3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float2x3({0}f, {1}f, {2}f,  {3}f, {4}f, {5}f)", c0.x, c1.x, c2.x, c0.y, c1.y, c2.y);
        }
	};
    __declspec(selectany) const float2x3    float2x3::zero = float2x3(0.f, 0.f, 0.f);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-float2x3
        //=========================================================
        /// <summary>Return the float3x2 transpose of a float2x3 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        float3x2 transpose(const float2x3& v);

        /// <summary>Returns a uint hash code of a float2x3 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const float2x3& v);

        /// <summary>
        /// Returns a uint2 vector hash code of a float2x3 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint2 hash of the argument.</returns>
        uint2 hashwide(const float2x3& v);
    }

} // namespace ecs
