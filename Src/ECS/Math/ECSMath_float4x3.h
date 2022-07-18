#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float4x3.gen.cs
#pragma pack(push,1)
	struct float4x3
	{
	public:
		static const float4x3  zero;       /// <summary>float4x3 zero value.</summary>
		union {
			struct
			{
				float4 c0;	/// <summary>Column 0 of the matrix.</summary>
				float4 c1;	/// <summary>Column 1 of the matrix.</summary>
				float4 c2;	/// <summary>Column 2 of the matrix.</summary>
			};
			float4		data[3];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
        float4x3() : c0(0.f), c1(0.f), c2(0.f) {}
        float4x3(const float4& _c0, const float4& _c1, const float4& _c2) { c0 = _c0;	c1 = _c1;	c2 = _c2; }

        /// <summary>Constructs a float4x3 matrix from 12 float values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        float4x3(   float m00, float m01, float m02,
                    float m10, float m11, float m12,
                    float m20, float m21, float m22,
                    float m30, float m31, float m32)
        {
            c0 = float4(m00, m10, m20, m30);
            c1 = float4(m01, m11, m21, m31);
            c2 = float4(m02, m12, m22, m32);
        }

        float4x3(bool v);
		float4x3(uint v)            		{   c0 = v;     			c1 = v;         		c2 = v;         		}
        float4x3(int v)		                {   c0 = v;			        c1 = v;     			c2 = v;         		}
        float4x3(float v)       		    {   c0 = v;			        c1 = v;			        c2 = v;         		}
		float4x3(double v)                  {   c0 = (float4)v;			c1 = (float4)v;			c2 = (float4)v; 		}
                
        float4x3(const bool4x3& v);
        float4x3(const int4x3& v);
        float4x3(const uint4x3& v);
        float4x3(const float4x3& v);
        float4x3(const double4x3& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        float4x3& operator = (const float4x3& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1;  this->c2 = rhs.c2;  return (*this); }
		// addition assignment	            a += b	
        float4x3& operator +=(const float4x3& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; return (*this); }
		// subtraction assignment	        a -= b	
        float4x3& operator -=(const float4x3& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; return (*this); }
		// multiplication assignment	    a *= b	
        float4x3& operator *=(const float4x3& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; return (*this); }
		// division assignment	            a /= b	
        float4x3& operator /=(const float4x3& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; return (*this); }
		// modulo assignment	            a %= b	
        float4x3& operator %=(const float4x3& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; return (*this); }

        // bitwise AND assignment	        a &= b	
        // bitwise OR assignment	        a |= b	
        // bitwise XOR assignment	        a ^= b	
        // bitwise left shift assignment	a <<= b	
        // bitwise right shift assignment   a >>= b

        //=========================================================
        // Increment/decrement operators
        //=========================================================
        // pre-increment    : 	++a		T&
        float4x3& operator ++ ()                            { ++this->c0; ++this->c1; ++this->c2; return (*this);   }
		// pre - decrement  : 	--a		T&
        float4x3& operator -- ()                            { --this->c0; --this->c1; --this->c2; return (*this);   }
		// post-increment   : 	a++
        float4x3  operator ++ (int)                         { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
        float4x3  operator -- (int)							{ auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
        float4x3 operator + () const                        { return float4x3(+this->c0, +this->c1, +this->c2); }
		// unary minus      :   -a
        float4x3 operator - () const                        { return float4x3(-this->c0, -this->c1, -this->c2); }

		// addition         :   a + b
        float4x3 operator + (const float4x3& rhs)   const   { return float4x3(this->c0 + rhs.c0,    this->c1 + rhs.c1,      this->c2 + rhs.c2); }
        float4x3 operator + (float rhs)             const   { return float4x3(this->c0 + rhs,       this->c1 + rhs,         this->c2 + rhs); }
        friend float4x3 operator + (float lhs, const float4x3& rhs) { return float4x3(lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2); }

        // subtraction      :   a - b
        float4x3 operator - (const float4x3& rhs)   const   { return float4x3(this->c0 - rhs.c0,    this->c1 - rhs.c1,      this->c2 - rhs.c2); }
        float4x3 operator - (float rhs)             const   { return float4x3(this->c0 - rhs,       this->c1 - rhs,         this->c2 - rhs); }
        friend float4x3 operator - (float lhs, const float4x3& rhs) { return float4x3(lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2); }

        // multiplication   :   a * b
        float4x3 operator * (const float4x3& rhs)   const   { return float4x3(this->c0 * rhs.c0,    this->c1 * rhs.c1,      this->c2 * rhs.c2); }
        float4x3 operator * (float rhs)             const   { return float4x3(this->c0 * rhs,       this->c1 * rhs,         this->c2 * rhs); }
        friend float4x3 operator * (float lhs, const float4x3& rhs) { return float4x3(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2); }

        // division         :   a / b
        float4x3 operator / (const float4x3& rhs)   const   { return float4x3(this->c0 / rhs.c0,    this->c1 / rhs.c1,      this->c2 / rhs.c2); }
        float4x3 operator / (float rhs)             const   { return float4x3(this->c0 / rhs,       this->c1 / rhs,         this->c2 / rhs); }
        friend float4x3 operator / (float lhs, const float4x3& rhs) { return float4x3(lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2); }

        // modulo           :   a % b
        float4x3 operator % (const float4x3& rhs)   const   { return float4x3(this->c0 % rhs.c0,    this->c1 % rhs.c1,      this->c2 % rhs.c2); }
        float4x3 operator % (float rhs)             const   { return float4x3(this->c0 % rhs,       this->c1 % rhs,         this->c2 % rhs); }
        friend float4x3 operator % (float lhs, const float4x3& rhs) { return float4x3(lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2); }
		
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
        bool4x3 operator == (const float4x3& rhs)   const   { return bool4x3(this->c0 == rhs.c0,    this->c1 == rhs.c1,     this->c2 == rhs.c2); }
        bool4x3 operator == (float rhs)             const   { return bool4x3(this->c0 == rhs,       this->c1 == rhs,        this->c2 == rhs); }
        friend bool4x3 operator == (float lhs, const float4x3& rhs) { return bool4x3(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2); }

        // not equal to     :   a != b
        bool4x3 operator != (const float4x3& rhs)   const   { return bool4x3(this->c0 != rhs.c0,    this->c1 != rhs.c1,     this->c2 != rhs.c2); }
        bool4x3 operator != (float rhs)             const   { return bool4x3(this->c0 != rhs,       this->c1 != rhs,        this->c2 != rhs); }
        friend bool4x3 operator != (float lhs, const float4x3& rhs) { return bool4x3(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2); }

        // less than        :   a < b
        bool4x3 operator < (const float4x3& rhs)    const   { return bool4x3(this->c0 < rhs.c0,     this->c1 < rhs.c1,      this->c2 < rhs.c2); }
        bool4x3 operator < (float rhs)              const   { return bool4x3(this->c0 < rhs,        this->c1 < rhs,         this->c2 < rhs); }
        friend bool4x3 operator < (float lhs, const float4x3& rhs) { return bool4x3(lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2); }

        // greater than     :   a > b
        bool4x3 operator > (const float4x3& rhs)    const   { return bool4x3(this->c0 > rhs.c0,     this->c1 > rhs.c1,      this->c2 > rhs.c2); }
        bool4x3 operator > (float rhs)              const   { return bool4x3(this->c0 > rhs,        this->c1 > rhs,         this->c2 > rhs); }
        friend bool4x3 operator > (float lhs, const float4x3& rhs) { return bool4x3(lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2); }

        // less than or equal to    : a <= b	
        bool4x3 operator <= (const float4x3& rhs)   const   { return bool4x3(this->c0 <= rhs.c0,    this->c1 <= rhs.c1,     this->c2 <= rhs.c2); }
        bool4x3 operator <= (float rhs)             const   { return bool4x3(this->c0 <= rhs,       this->c1 <= rhs,        this->c2 <= rhs); }
        friend bool4x3 operator <= (float lhs, const float4x3& rhs) { return bool4x3(lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2); }

        // greater than or equal to : a >= b
        bool4x3 operator >= (const float4x3& rhs)   const   { return bool4x3(this->c0 >= rhs.c0,    this->c1 >= rhs.c1,     this->c2 >= rhs.c2); }
        bool4x3 operator >= (float rhs)             const   { return bool4x3(this->c0 >= rhs,       this->c1 >= rhs,        this->c2 >= rhs); }
        friend bool4x3 operator >= (float lhs, const float4x3& rhs) { return bool4x3(lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2); }

        //=========================================================
        // Conversion operators
        //=========================================================


		//=========================================================
		// member access
		//=========================================================
        /// <summary>Returns the float4 element at a specified index.</summary>
        float4& operator[] (int index)
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
        /// <summary>Returns true if the float4x3 is equal to a given float4x3, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float4x3& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2); }

        /// <summary>Returns true if the float4x3 is equal to a given float4x3, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float4x3 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float4x3.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }

        /// <summary>Returns a string representation of the float4x3.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float4x3({0}f, {1}f, {2}f,  {3}f, {4}f, {5}f,  {6}f, {7}f, {8}f,  {9}f, {10}f, {11}f)", c0.x, c1.x, c2.x, c0.y, c1.y, c2.y, c0.z, c1.z, c2.z, c0.w, c1.w, c2.w);
        }
	};
    __declspec(selectany) const float4x3    float4x3::zero = float4x3(0.f, 0.f, 0.f);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-float4x3
        //=========================================================
        /// <summary>Return the float3x4 transpose of a float4x3 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        float3x4 transpose(const float4x3& v);

        /// <summary>Returns a uint hash code of a float4x3 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const float4x3& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a float4x3 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const float4x3& v);
    }

} // namespace ecs


