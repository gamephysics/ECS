#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float4x4.gen.cs
#pragma pack(push,1)
	struct float4x4
	{
	public:
		static const float4x4		identity;
		static const float4x4		zero;       /// <summary>float4x4 zero value.</summary>
		union {
			struct
			{
				float4 c0;	/// <summary>Column 0 of the matrix.</summary>
				float4 c1;	/// <summary>Column 1 of the matrix.</summary>
				float4 c2;	/// <summary>Column 2 of the matrix.</summary>
				float4 c3;	/// <summary>Column 3 of the matrix.</summary>
			};
			float4		data[4];
		};

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
        float4x4() : c0(0.f), c1(0.f), c2(0.f), c3(0.f) {}
		float4x4(const float4& _c0, const float4& _c1, const float4& _c2, const float4& _c3) { c0 = _c0;	c1 = _c1;	c2 = _c2;	c3 = _c3; }

        /// <summary>Constructs a float4x4 matrix from 16 float values given in row-major order.</summary>
        /// mXY : The matrix at row X, column Y will be set to this value		
        float4x4(   float m00, float m01, float m02, float m03,
                    float m10, float m11, float m12, float m13,
                    float m20, float m21, float m22, float m23,
                    float m30, float m31, float m32, float m33)
        {
            c0 = float4(m00, m10, m20, m30);
            c1 = float4(m01, m11, m21, m31);
            c2 = float4(m02, m12, m22, m32);
            c3 = float4(m03, m13, m23, m33);
        }

		float4x4(bool v);
		float4x4(uint v)		        {   c0 = v;			    c1 = v; 			c2 = v; 			c3 = v;     		}
		float4x4(int v)		            {   c0 = v;			    c1 = v;			    c2 = v;			    c3 = v;     		}
        float4x4(float v)               {   c0 = v;             c1 = v;             c2 = v;             c3 = v;             }
		float4x4(double v)		        {   c0 = (float4)v;	    c1 = (float4)v;     c2 = (float4)v;     c3 = (float4)v;	    }
        
        float4x4(const bool4x4& v);
        float4x4(const int4x4& v);
        float4x4(const uint4x4& v);
		float4x4(const float4x4& v);
        float4x4(const double4x4& v);


		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		float4x4& operator = (const float4x4& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1;  this->c2 = rhs.c2;  this->c3 = rhs.c3;  return (*this); }
		// addition assignment	            a += b	
		float4x4& operator +=(const float4x4& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; this->c3 += rhs.c3; return (*this); }
		// subtraction assignment	        a -= b	
		float4x4& operator -=(const float4x4& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; this->c3 -= rhs.c3; return (*this); }
		// multiplication assignment	    a *= b	
		float4x4& operator *=(const float4x4& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; this->c3 *= rhs.c3; return (*this); }
		// division assignment	            a /= b	
		float4x4& operator /=(const float4x4& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; this->c3 /= rhs.c3; return (*this); }
		// modulo assignment	            a %= b	
		float4x4& operator %=(const float4x4& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; this->c3 %= rhs.c3; return (*this); }

		
		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b
		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
		float4x4& operator ++ ()                            { ++this->c0; ++this->c1; ++this->c2; ++this->c3; return (*this);   }
		// pre - decrement  : 	--a		T&
		float4x4& operator -- ()                            { --this->c0; --this->c1; --this->c2; --this->c3; return (*this);   }
		// post-increment   : 	a++
		float4x4  operator ++ (int)                         { auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
		float4x4  operator -- (int)							{ auto temp = *this; --(*this); return (temp); }

		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		float4x4 operator + () const                        { return float4x4(+this->c0, +this->c1, +this->c2, +this->c3); }
		// unary minus      :   -a
		float4x4 operator - () const						{ return float4x4(-this->c0, -this->c1, -this->c2, -this->c3); }

		// addition         :   a + b
		float4x4 operator + (const float4x4& rhs)	const	{ return float4x4(this->c0 + rhs.c0,	this->c1 + rhs.c1,		this->c2 + rhs.c2,		this->c3 + rhs.c3); }
		float4x4 operator + (float rhs)				const	{ return float4x4(this->c0 + rhs,		this->c1 + rhs,			this->c2 + rhs,			this->c3 + rhs); }
		friend float4x4 operator + (float lhs, const float4x4& rhs) { return float4x4(lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2, lhs + rhs.c3); }

		// subtraction      :   a - b
		float4x4 operator - (const float4x4& rhs)	const	{ return float4x4(this->c0 - rhs.c0,	this->c1 - rhs.c1,		this->c2 - rhs.c2,		this->c3 - rhs.c3); }
		float4x4 operator - (float rhs)				const	{ return float4x4(this->c0 - rhs,		this->c1 - rhs,			this->c2 - rhs,			this->c3 - rhs); }
		friend float4x4 operator - (float lhs, const float4x4& rhs) { return float4x4(lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2, lhs - rhs.c3); }

		// multiplication   :   a * b
		float4x4 operator * (const float4x4& rhs)	const	{ return float4x4(this->c0 * rhs.c0,	this->c1 * rhs.c1,		this->c2 * rhs.c2,		this->c3 * rhs.c3); }
		float4x4 operator * (float rhs)				const	{ return float4x4(this->c0 * rhs,		this->c1 * rhs,			this->c2 * rhs,			this->c3 * rhs); }
		friend float4x4 operator * (float lhs, const float4x4& rhs) { return float4x4(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2, lhs * rhs.c3); }

		// division         :   a / b
		float4x4 operator / (const float4x4& rhs)	const	{ return float4x4(this->c0 / rhs.c0,	this->c1 / rhs.c1,		this->c2 / rhs.c2,		this->c3 / rhs.c3); }
		float4x4 operator / (float rhs)				const	{ return float4x4(this->c0 / rhs,		this->c1 / rhs,			this->c2 / rhs,			this->c3 / rhs); }
		friend float4x4 operator / (float lhs, const float4x4& rhs) { return float4x4(lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2, lhs / rhs.c3); }

		// modulo           :   a % b
		float4x4 operator % (const float4x4& rhs)	const	{ return float4x4(this->c0 % rhs.c0,	this->c1 % rhs.c1,		this->c2 % rhs.c2,		this->c3 % rhs.c3); }
		float4x4 operator % (float rhs)				const	{ return float4x4(this->c0 % rhs,		this->c1 % rhs,			this->c2 % rhs,			this->c3 % rhs); }
		friend float4x4 operator % (float lhs, const float4x4& rhs) { return float4x4(lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2, lhs % rhs.c3); }
		
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
		bool4x4 operator == (const float4x4& rhs)	const	{ return bool4x4(this->c0 == rhs.c0,	this->c1 == rhs.c1,		this->c2 == rhs.c2,		this->c3 == rhs.c3); }
		bool4x4 operator == (float rhs)				const	{ return bool4x4(this->c0 == rhs,		this->c1 == rhs,		this->c2 == rhs,		this->c3 == rhs); }
		friend bool4x4 operator == (float lhs, const float4x4& rhs) { return bool4x4(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2, lhs == rhs.c3); }

		// not equal to     :   a != b
		bool4x4 operator != (const float4x4& rhs)	const	{ return bool4x4(this->c0 != rhs.c0,	this->c1 != rhs.c1,		this->c2 != rhs.c2,		this->c3 != rhs.c3); }
		bool4x4 operator != (float rhs)				const	{ return bool4x4(this->c0 != rhs,		this->c1 != rhs,		this->c2 != rhs,		this->c3 != rhs); }
		friend bool4x4 operator != (float lhs, const float4x4& rhs) { return bool4x4(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2, lhs != rhs.c3); }

		// less than        :   a < b
		bool4x4 operator < (const float4x4& rhs)	const	{ return bool4x4(this->c0 < rhs.c0,		this->c1 < rhs.c1,		this->c2 < rhs.c2,		this->c3 < rhs.c3); }
		bool4x4 operator < (float rhs)				const	{ return bool4x4(this->c0 < rhs,		this->c1 < rhs,			this->c2 < rhs,			this->c3 < rhs); }
		friend bool4x4 operator < (float lhs, const float4x4& rhs) { return bool4x4(lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2, lhs < rhs.c3); }

		// greater than     :   a > b
		bool4x4 operator > (const float4x4& rhs)	const	{ return bool4x4(this->c0 > rhs.c0,		this->c1 > rhs.c1,		this->c2 > rhs.c2,		this->c3 > rhs.c3); }
		bool4x4 operator > (float rhs)				const	{ return bool4x4(this->c0 > rhs,		this->c1 > rhs,			this->c2 > rhs,			this->c3 > rhs); }
		friend bool4x4 operator > (float lhs, const float4x4& rhs) { return bool4x4(lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2, lhs > rhs.c3); }

		// less than or equal to    : a <= b	
		bool4x4 operator <= (const float4x4& rhs)	const	{ return bool4x4(this->c0 <= rhs.c0,	this->c1 <= rhs.c1,		this->c2 <= rhs.c2,		this->c3 <= rhs.c3); }
		bool4x4 operator <= (float rhs)				const	{ return bool4x4(this->c0 <= rhs,		this->c1 <= rhs,		this->c2 <= rhs,		this->c3 <= rhs); }
		friend bool4x4 operator <= (float lhs, const float4x4& rhs) { return bool4x4(lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2, lhs <= rhs.c3); }

		// greater than or equal to : a >= b
		bool4x4 operator >= (const float4x4& rhs)	const	{ return bool4x4(this->c0 >= rhs.c0,	this->c1 >= rhs.c1,		this->c2 >= rhs.c2,		this->c3 >= rhs.c3); }
		bool4x4 operator >= (float rhs)				const	{ return bool4x4(this->c0 >= rhs,		this->c1 >= rhs,		this->c2 >= rhs,		this->c3 >= rhs); }
		friend bool4x4 operator >= (float lhs, const float4x4& rhs) { return bool4x4(lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2, lhs >= rhs.c3); }

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
			if (index >= 4)
				throw std::exception("index must be between[0...3]");
#endif
			return data[index];
		}

		//=========================================================
        // METHOD
		//=========================================================
        /// <summary>Returns true if the float4x4 is equal to a given float4x4, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const float4x4& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2) && c3.Equals(rhs.c3); }

        /// <summary>Returns true if the float4x4 is equal to a given float4x4, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is float4x4 converted && Equals(converted); }


        /// <summary>Returns a hash code for the float4x4.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }


        /// <summary>Returns a string representation of the float4x4.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("float4x4({0}f, {1}f, {2}f, {3}f,  {4}f, {5}f, {6}f, {7}f,  {8}f, {9}f, {10}f, {11}f,  {12}f, {13}f, {14}f, {15}f)", c0.x, c1.x, c2.x, c3.x, c0.y, c1.y, c2.y, c3.y, c0.z, c1.z, c2.z, c3.z, c0.w, c1.w, c2.w, c3.w);
        }

		//=========================================================
		// matrix
		//=========================================================
    public:
        /// <summary>Constructs a float4x4 from a float3x3 rotation matrix and a float3 translation vector.</summary>
        /// <param name="rotation">The float3x3 rotation matrix.</param>
        /// <param name="translation">The translation vector.</param>
        float4x4(const float3x3& rotation, const float3& translation)
        {
            c0 = float4(rotation.c0, 0.0f);
            c1 = float4(rotation.c1, 0.0f);
            c2 = float4(rotation.c2, 0.0f);
            c3 = float4(translation, 1.0f);
        }

        /// <summary>Constructs a float4x4 from a quaternion and a float3 translation vector.</summary>
        /// <param name="rotation">The quaternion rotation.</param>
        /// <param name="translation">The translation vector.</param>
        float4x4(const quaternion& rotation, const float3& translation)
        {
            float3x3 rot = float3x3(rotation);
            c0 = float4(rot.c0, 0.0f);
            c1 = float4(rot.c1, 0.0f);
            c2 = float4(rot.c2, 0.0f);
            c3 = float4(translation, 1.0f);
        }

        /*
        /// <summary>Constructs a float4x4 from a RigidTransform.</summary>
        /// <param name="transform">The RigidTransform.</param>
        float4x4(RigidTransform transform)
        {
            float3x3 rot = float3x3(transform.rot);
            c0 = float4(rot.c0, 0.0f);
            c1 = float4(rot.c1, 0.0f);
            c2 = float4(rot.c2, 0.0f);
            c3 = float4(transform.pos, 1.0f);
        }
        */

        /// <summary>
        /// Returns a float4x4 matrix representing a rotation around a unit axis by an angle in radians.
        /// The rotation direction is clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="axis">The axis of rotation.</param>
        /// <param name="angle">The angle of rotation in radians.</param>
        /// <returns>The float4x4 matrix representing the rotation about an axis.</returns>
        static float4x4 AxisAngle(const float3& axis, float angle);

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in x-y-z order.</returns>
        static float4x4 EulerXYZ(const float3& xyz);

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the x-axis, then the z-axis and finally the y-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in x-z-y order.</returns>
        static float4x4 EulerXZY(const float3& xyz);

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the y-axis, then the x-axis and finally the z-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in y-x-z order.</returns>
        static float4x4 EulerYXZ(const float3& xyz);

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the y-axis, then the z-axis and finally the x-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in y-z-x order.</returns>
        static float4x4 EulerYZX(const float3& xyz);

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the z-axis, then the x-axis and finally the y-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// This is the default order rotation order in Unity.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in z-x-y order.</returns>
        static float4x4 EulerZXY(const float3& xyz);

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the z-axis, then the y-axis and finally the x-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in z-y-x order.</returns>
        static float4x4 EulerZYX(const float3& xyz);

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in x-y-z order.</returns>
        static float4x4 EulerXYZ(float x, float y, float z) { return EulerXYZ(float3(x, y, z)); }

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the x-axis, then the z-axis and finally the y-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in x-z-y order.</returns>
        static float4x4 EulerXZY(float x, float y, float z) { return EulerXZY(float3(x, y, z)); }

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the y-axis, then the x-axis and finally the z-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in y-x-z order.</returns>
        static float4x4 EulerYXZ(float x, float y, float z) { return EulerYXZ(float3(x, y, z)); }

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the y-axis, then the z-axis and finally the x-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in y-z-x order.</returns>
        static float4x4 EulerYZX(float x, float y, float z) { return EulerYZX(float3(x, y, z)); }

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the z-axis, then the x-axis and finally the y-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// This is the default order rotation order in Unity.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in z-x-y order.</returns>
        static float4x4 EulerZXY(float x, float y, float z) { return EulerZXY(float3(x, y, z)); }

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing a rotation around the z-axis, then the y-axis and finally the x-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in z-y-x order.</returns>
        static float4x4 EulerZYX(float x, float y, float z) { return EulerZYX(float3(x, y, z)); }

        /// <summary>
        /// Returns a float4x4 constructed by first performing 3 rotations around the principal axes in a given order.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// When the rotation order is known at compile time, it is recommended for performance reasons to use specific
        /// Euler rotation constructors such as EulerZXY(...).
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <param name="order">The order in which the rotations are applied.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in given order.</returns>
        static float4x4 Euler(float3 xyz, RotationOrder order = RotationOrder::Default)
        {
            switch (order)
            {
            case RotationOrder::XYZ:
                return EulerXYZ(xyz);
            case RotationOrder::XZY:
                return EulerXZY(xyz);
            case RotationOrder::YXZ:
                return EulerYXZ(xyz);
            case RotationOrder::YZX:
                return EulerYZX(xyz);
            case RotationOrder::ZXY:
                return EulerZXY(xyz);
            case RotationOrder::ZYX:
                return EulerZYX(xyz);
            default:
                return float4x4::identity;
            }
        }

        /// <summary>
        /// Returns a float4x4 rotation matrix constructed by first performing 3 rotations around the principal axes in a given order.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// When the rotation order is known at compile time, it is recommended for performance reasons to use specific
        /// Euler rotation constructors such as EulerZXY(...).
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <param name="order">The order in which the rotations are applied.</param>
        /// <returns>The float4x4 rotation matrix of the Euler angle rotation in given order.</returns>
        static float4x4 Euler(float x, float y, float z, RotationOrder order = RotationOrder::Default)
        {
            return Euler(float3(x, y, z), order);
        }

        /// <summary>Returns a float4x4 matrix that rotates around the x-axis by a given number of radians.</summary>
        /// <param name="angle">The clockwise rotation angle when looking along the x-axis towards the origin in radians.</param>
        /// <returns>The float4x4 rotation matrix that rotates around the x-axis.</returns>
        static float4x4 RotateX(float angle);

        /// <summary>Returns a float4x4 matrix that rotates around the y-axis by a given number of radians.</summary>
        /// <param name="angle">The clockwise rotation angle when looking along the y-axis towards the origin in radians.</param>
        /// <returns>The float4x4 rotation matrix that rotates around the y-axis.</returns>
        static float4x4 RotateY(float angle);

        /// <summary>Returns a float4x4 matrix that rotates around the z-axis by a given number of radians.</summary>
        /// <param name="angle">The clockwise rotation angle when looking along the z-axis towards the origin in radians.</param>
        /// <returns>The float4x4 rotation matrix that rotates around the z-axis.</returns>
        static float4x4 RotateZ(float angle);

        /// <summary>Returns a float4x4 scale matrix given 3 axis scales.</summary>
        /// <param name="s">The uniform scaling factor.</param>
        /// <returns>The float4x4 matrix that represents a uniform scale.</returns>
        static float4x4 Scale(float s)
        {
            return float4x4(s, 0.0f, 0.0f, 0.0f,
                            0.0f, s, 0.0f, 0.0f,
                            0.0f, 0.0f, s, 0.0f,
                            0.0f, 0.0f, 0.0f, 1.0f);
        }

        /// <summary>Returns a float4x4 scale matrix given a float3 vector containing the 3 axis scales.</summary>
        /// <param name="x">The x-axis scaling factor.</param>
        /// <param name="y">The y-axis scaling factor.</param>
        /// <param name="z">The z-axis scaling factor.</param>
        /// <returns>The float4x4 matrix that represents a non-uniform scale.</returns>
        static float4x4 Scale(float x, float y, float z)
        {
            return float4x4(x, 0.0f, 0.0f, 0.0f,
                            0.0f, y, 0.0f, 0.0f,
                            0.0f, 0.0f, z, 0.0f,
                            0.0f, 0.0f, 0.0f, 1.0f);
        }

        /// <summary>Returns a float4x4 scale matrix given a float3 vector containing the 3 axis scales.</summary>
        /// <param name="scales">The vector containing scale factors for each axis.</param>
        /// <returns>The float4x4 matrix that represents a non-uniform scale.</returns>
        static float4x4 Scale(float3 scales)
        {
            return Scale(scales.x, scales.y, scales.z);
        }

        /// <summary>Returns a float4x4 translation matrix given a float3 translation vector.</summary>
        /// <param name="vector">The translation vector.</param>
        /// <returns>The float4x4 translation matrix.</returns>
        static float4x4 Translate(float3 vector)
        {
            return float4x4(float4(1.0f, 0.0f, 0.0f, 0.0f),
                            float4(0.0f, 1.0f, 0.0f, 0.0f),
                            float4(0.0f, 0.0f, 1.0f, 0.0f),
                            float4(vector.x, vector.y, vector.z, 1.0f));
        }

        /// <summary>
        /// Returns a float4x4 view matrix given an eye position, a target point and a unit length up vector.
        /// The up vector is assumed to be unit length, the eye and target points are assumed to be distinct and
        /// the vector between them is assumes to be collinear with the up vector.
        /// If these assumptions are not met use float4x4.LookRotationSafe instead.
        /// </summary>
        /// <param name="eye">The eye position.</param>
        /// <param name="target">The view target position.</param>
        /// <param name="up">The eye up direction.</param>
        /// <returns>The float4x4 view matrix.</returns>
        static float4x4 LookAt(const float3& eye, const float3& target, const float3& up);

        /// <summary>
        /// Returns a float4x4 centered orthographic projection matrix.
        /// </summary>
        /// <param name="width">The width of the view volume.</param>
        /// <param name="height">The height of the view volume.</param>
        /// <param name="_near">The distance to the _near plane.</param>
        /// <param name="_far">The distance to the _far plane.</param>
        /// <returns>The float4x4 centered orthographic projection matrix.</returns>
        static float4x4 Ortho(float width, float height, float _near, float _far);

        /// <summary>
        /// Returns a float4x4 off-center orthographic projection matrix.
        /// </summary>
        /// <param name="left">The minimum x-coordinate of the view volume.</param>
        /// <param name="right">The maximum x-coordinate of the view volume.</param>
        /// <param name="bottom">The minimum y-coordinate of the view volume.</param>
        /// <param name="top">The minimum y-coordinate of the view volume.</param>
        /// <param name="_near">The distance to the _near plane.</param>
        /// <param name="_far">The distance to the _far plane.</param>
        /// <returns>The float4x4 off-center orthographic projection matrix.</returns>
        static float4x4 OrthoOffCenter(float left, float right, float bottom, float top, float _near, float _far);

        /// <summary>
        /// Returns a float4x4 perspective projection matrix based on field of view.
        /// </summary>
        /// <param name="verticalFov">Vertical Field of view in radians.</param>
        /// <param name="aspect">X:Y aspect ratio.</param>
        /// <param name="_near">Distance to _near plane. Must be greater than zero.</param>
        /// <param name="_far">Distance to _far plane. Must be greater than zero.</param>
        /// <returns>The float4x4 perspective projection matrix.</returns>
        static float4x4 PerspectiveFov(float verticalFov, float aspect, float _near, float _far);

        /// <summary>
        /// Returns a float4x4 off-center perspective projection matrix.
        /// </summary>
        /// <param name="left">The x-coordinate of the left side of the clipping frustum at the _near plane.</param>
        /// <param name="right">The x-coordinate of the right side of the clipping frustum at the _near plane.</param>
        /// <param name="bottom">The y-coordinate of the bottom side of the clipping frustum at the _near plane.</param>
        /// <param name="top">The y-coordinate of the top side of the clipping frustum at the _near plane.</param>
        /// <param name="_near">Distance to the _near plane. Must be greater than zero.</param>
        /// <param name="_far">Distance to the _far plane. Must be greater than zero.</param>
        /// <returns>The float4x4 off-center perspective projection matrix.</returns>
        static float4x4 PerspectiveOffCenter(float left, float right, float bottom, float top, float _near, float _far);

        /// <summary>
        /// Returns a float4x4 matrix representing a combined scale-, rotation- and translation transform.
        /// Equivalent to mul(translationTransform, mul(rotationTransform, scaleTransform)).
        /// </summary>
        /// <param name="translation">The translation vector.</param>
        /// <param name="rotation">The quaternion rotation.</param>
        /// <param name="scale">The scaling factors of each axis.</param>
        /// <returns>The float4x4 matrix representing the translation, rotation, and scale by the inputs.</returns>
        static float4x4 TRS(const float3& translation, const quaternion& rotation, const float3& scale);
	};
    __declspec(selectany) const float4x4    float4x4::identity  = float4x4(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f);
    __declspec(selectany) const float4x4	float4x4::zero      = float4x4(0.f, 0.f, 0.f, 0.f);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-float4x4
        //=========================================================
        /// <summary>Return the result of rotating a float3 vector by a float4x4 matrix</summary>
        /// <param name ="a">Left hand side matrix argument that specifies the rotation.</param>
        /// <param name ="b">Right hand side vector argument to be rotated.</param>
        /// <returns>The rotated vector.</returns>
        float3 rotate(const float4x4& a, const float3& b);

        /// <summary>Return the result of transforming a float3 point by a float4x4 matrix</summary>
        /// <param name ="a">Left hand side matrix argument that specifies the transformation.</param>
        /// <param name ="b">Right hand side point argument to be transformed.</param>
        /// <returns>The transformed point.</returns>
        float3 transform(const float4x4& a, const float3& b);

        /// <summary>Return the float4x4 transpose of a float4x4 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        float4x4 transpose(const float4x4& v);

        /// <summary>Returns the float4x4 full inverse of a float4x4 matrix.</summary>
        /// <param name="m">Matrix to invert.</param>
        /// <returns>The inverted matrix.</returns>
        float4x4 inverse(const float4x4& m);

        /// <summary>Fast matrix inverse for rigid transforms (orthonormal basis and translation)</summary>
        /// <param name="m">Matrix to invert.</param>
        /// <returns>The inverted matrix.</returns>
        float4x4 fastinverse(const float4x4& m);

        /// <summary>Returns the determinant of a float4x4 matrix.</summary>
        /// <param name="m">Matrix to use when computing determinant.</param>
        /// <returns>The determinant of the matrix.</returns>
        float determinant(const float4x4& m);

        /// <summary>Returns a uint hash code of a float4x4 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const float4x4& v);

        /// <summary>
        /// Returns a uint4 vector hash code of a float4x4 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint4 hash of the argument.</returns>
        uint4 hashwide(const float4x4& v);
    }

} // namespace ecs
