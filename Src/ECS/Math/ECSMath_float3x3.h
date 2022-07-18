#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/float3x3.gen.cs
#pragma pack(push,1)
	struct float3x3
	{
	public:
		static const float3x3		identity;	/// <summary>float3x3 identity transform.</summary>
		static const float3x3		zero;       /// <summary>float3x3 zero value.</summary>
		union {
			struct
			{
				float3	c0;	/// <summary>Column 0 of the matrix.</summary>
				float3 c1;	/// <summary>Column 1 of the matrix.</summary>
				float3 c2;	/// <summary>Column 2 of the matrix.</summary>
			};
			float3		data[3];
		};

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        float3x3() : c0(0.f), c1(0.f), c2(0.f) {}
		float3x3(const float3& _c0, const float3& _c1, const float3& _c2)	{	c0 = _c0;	c1 = _c1;	c2 = _c2;	}

		/// <summary>Constructs a float3x3 matrix from 9 float values given in row-major order.</summary>
		/// mXY : The matrix at row X, column Y will be set to this value
		float3x3(	float m00, float m01, float m02, 
					float m10, float m11, float m12, 
					float m20, float m21, float m22)
		{
			c0 = float3(m00, m10, m20);
			c1 = float3(m01, m11, m21);
			c2 = float3(m02, m12, m22);
		}

		float3x3(bool v);
		float3x3(uint v)			{	c0 = v;				c1 = v;				c2 = v;		}
		float3x3(int v)				{	c0 = v;				c1 = v;				c2 = v;		}
		float3x3(float v)			{	c0 = v;				c1 = v;				c2 = v;		}
		float3x3(double v)			{	c0 = (float3)v;		c1 = (float3)v;		c2 = (float3)v;		}

		float3x3(const bool3x3& v);
		float3x3(const uint3x3& v);
		float3x3(const int3x3& v);
		float3x3(const float3x3& v);
		float3x3(const double3x3& v);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		float3x3& operator = (const float3x3& rhs)			{ this->c0 = rhs.c0;  this->c1 = rhs.c1;  this->c2 = rhs.c2;  return (*this); }
		// addition assignment	            a += b	
		float3x3& operator +=(const float3x3& rhs)			{ this->c0 += rhs.c0; this->c1 += rhs.c1; this->c2 += rhs.c2; return (*this); }
		// subtraction assignment	        a -= b	
		float3x3& operator -=(const float3x3& rhs)			{ this->c0 -= rhs.c0; this->c1 -= rhs.c1; this->c2 -= rhs.c2; return (*this); }
		// multiplication assignment	    a *= b	
		float3x3& operator *=(const float3x3& rhs)			{ this->c0 *= rhs.c0; this->c1 *= rhs.c1; this->c2 *= rhs.c2; return (*this); }
		// division assignment	            a /= b	
		float3x3& operator /=(const float3x3& rhs)			{ this->c0 /= rhs.c0; this->c1 /= rhs.c1; this->c2 /= rhs.c2; return (*this); }
		// modulo assignment	            a %= b	
		float3x3& operator %=(const float3x3& rhs)			{ this->c0 %= rhs.c0; this->c1 %= rhs.c1; this->c2 %= rhs.c2; return (*this); }
		
		// bitwise AND assignment	        a &= b	
		// bitwise OR assignment	        a |= b	
		// bitwise XOR assignment	        a ^= b	
		// bitwise left shift assignment	a <<= b	
		// bitwise right shift assignment   a >>= b

		//=========================================================
		// Increment/decrement operators
		//=========================================================
		// pre-increment    : 	++a		T&
		float3x3& operator ++ ()							{ ++this->c0; ++this->c1; ++this->c2; return (*this);	}
		// pre - decrement  : 	--a		T&
		float3x3& operator -- ()							{ --this->c0; --this->c1; --this->c2; return (*this);	}
		// post-increment   : 	a++
		float3x3 operator ++ (int)							{ auto temp = *this; ++(*this); return (temp); }
		// post-decrement   :	a--
		float3x3 operator -- (int)							{ auto temp = *this; --(*this); return (temp); }
		
		//=========================================================
		// Arithmetic operators
		//=========================================================
		// unary plus       :   +a
		float3x3 operator + () const						{ return float3x3(+this->c0, +this->c1, +this->c2); }

		// unary minus      :   -a
		float3x3 operator - () const						{ return float3x3(-this->c0, -this->c1, -this->c2); }

		// addition         :   a + b
		float3x3 operator + (const float3x3& rhs)	const	{ return float3x3(this->c0 + rhs.c0,	this->c1 + rhs.c1,		this->c2 + rhs.c2); }
		float3x3 operator + (float rhs)				const	{ return float3x3(this->c0 + rhs,		this->c1 + rhs,			this->c2 + rhs); }
		friend float3x3 operator + (float lhs, const float3x3& rhs) { return float3x3(lhs + rhs.c0, lhs + rhs.c1, lhs + rhs.c2); }

		// subtraction      :   a - b
		float3x3 operator - (const float3x3& rhs)	const	{ return float3x3(this->c0 - rhs.c0,	this->c1 - rhs.c1,		this->c2 - rhs.c2); }
		float3x3 operator - (float rhs)				const	{ return float3x3(this->c0 - rhs,		this->c1 - rhs,			this->c2 - rhs); }
		friend float3x3 operator - (float lhs, const float3x3& rhs) { return float3x3(lhs - rhs.c0, lhs - rhs.c1, lhs - rhs.c2); }

		// multiplication   :   a * b
		float3x3 operator * (const float3x3& rhs)	const	{ return float3x3(this->c0 * rhs.c0,	this->c1 * rhs.c1,		this->c2 * rhs.c2); }
		float3x3 operator * (float rhs)				const	{ return float3x3(this->c0 * rhs,		this->c1 * rhs,			this->c2 * rhs); }
		friend float3x3 operator * (float lhs, const float3x3& rhs) { return float3x3(lhs * rhs.c0, lhs * rhs.c1, lhs * rhs.c2); }

		// division         :   a / b
		float3x3 operator / (const float3x3& rhs)	const	{ return float3x3(this->c0 / rhs.c0,	this->c1 / rhs.c1,		this->c2 / rhs.c2); }
		float3x3 operator / (float rhs)				const	{ return float3x3(this->c0 / rhs,		this->c1 / rhs,			this->c2 / rhs); }
		friend float3x3 operator / (float lhs, const float3x3& rhs) { return float3x3(lhs / rhs.c0, lhs / rhs.c1, lhs / rhs.c2); }

		// modulo           :   a % b
		float3x3 operator % (const float3x3& rhs)	const	{ return float3x3(this->c0 % rhs.c0,	this->c1 % rhs.c1,		this->c2 % rhs.c2); }
		float3x3 operator % (float rhs)				const	{ return float3x3(this->c0 % rhs,		this->c1 % rhs,			this->c2 % rhs); }
		friend float3x3 operator % (float lhs, const float3x3& rhs) { return float3x3(lhs % rhs.c0, lhs % rhs.c1, lhs % rhs.c2); }

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
		bool3x3 operator == (const float3x3& rhs)	const	{ return bool3x3(this->c0 == rhs.c0,	this->c1 == rhs.c1,		this->c2 == rhs.c2); }
		bool3x3 operator == (float rhs)				const	{ return bool3x3(this->c0 == rhs,		this->c1 == rhs,		this->c2 == rhs); }
		friend bool3x3  operator ==(float lhs, const float3x3& rhs) { return bool3x3(lhs == rhs.c0, lhs == rhs.c1, lhs == rhs.c2); }

		// not equal to     :   a != b
		bool3x3 operator != (const float3x3& rhs)	const	{ return bool3x3(this->c0 != rhs.c0,	this->c1 != rhs.c1,		this->c2 != rhs.c2); }
		bool3x3 operator != (float rhs)				const	{ return bool3x3(this->c0 != rhs,		this->c1 != rhs,		this->c2 != rhs); }
		friend bool3x3  operator !=(float lhs, const float3x3& rhs) { return bool3x3(lhs != rhs.c0, lhs != rhs.c1, lhs != rhs.c2); }

		// less than        :   a < b
		bool3x3 operator < (const float3x3& rhs)	const	{ return bool3x3(this->c0 < rhs.c0,		this->c1 < rhs.c1,		this->c2 < rhs.c2); }
		bool3x3 operator < (float rhs)				const	{ return bool3x3(this->c0 < rhs,		this->c1 < rhs,			this->c2 < rhs); }
		friend bool3x3  operator < (float lhs, const float3x3& rhs) { return bool3x3(lhs < rhs.c0, lhs < rhs.c1, lhs < rhs.c2); }

		// greater than     :   a > b
		bool3x3 operator > (const float3x3& rhs)	const	{ return bool3x3(this->c0 > rhs.c0,		this->c1 > rhs.c1,		this->c2 > rhs.c2); }
		bool3x3 operator > (float rhs)				const	{ return bool3x3(this->c0 > rhs,		this->c1 > rhs,			this->c2 > rhs); }
		friend bool3x3  operator > (float lhs, const float3x3& rhs) { return bool3x3(lhs > rhs.c0, lhs > rhs.c1, lhs > rhs.c2); }

		// less than or equal to    : a <= b	
		bool3x3 operator <= (const float3x3& rhs)	const	{ return bool3x3(this->c0 <= rhs.c0,	this->c1 <= rhs.c1,		this->c2 <= rhs.c2); }
		bool3x3 operator <= (float rhs)				const	{ return bool3x3(this->c0 <= rhs,		this->c1 <= rhs,		this->c2 <= rhs); }
		friend bool3x3  operator <=(float lhs, const float3x3& rhs) { return bool3x3(lhs <= rhs.c0, lhs <= rhs.c1, lhs <= rhs.c2); }

		// greater than or equal to : a >= b
		bool3x3 operator >= (const float3x3& rhs)	const	{ return bool3x3(this->c0 >= rhs.c0,	this->c1 >= rhs.c1,		this->c2 >= rhs.c2); }
		bool3x3 operator >= (float rhs)				const	{ return bool3x3(this->c0 >= rhs,		this->c1 >= rhs,		this->c2 >= rhs); }
		friend bool3x3  operator >=(float lhs, const float3x3& rhs) { return bool3x3(lhs >= rhs.c0, lhs >= rhs.c1, lhs >= rhs.c2); }

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
			if (index >= 3)
				throw std::exception("index must be between[0...2]");
#endif
			return data[index];
		}

		//=========================================================
        // METHOD
		//=========================================================
		/// <summary>Returns true if the float3x3 is equal to a given float3x3, false otherwise.</summary>
		/// <param name="rhs">Right hand side argument to compare equality with.</param>
		/// <returns>The result of the equality comparison.</returns>
		bool Equals(const float3x3& rhs) const { return c0.Equals(rhs.c0) && c1.Equals(rhs.c1) && c2.Equals(rhs.c2); }

		/// <summary>Returns true if the float3x3 is equal to a given float3x3, false otherwise.</summary>
		/// <param name="o">Right hand side argument to compare equality with.</param>
		/// <returns>The result of the equality comparison.</returns>
		//override bool Equals(object o) { return o is float3x3 converted && Equals(converted); }


		/// <summary>Returns a hash code for the float3x3.</summary>
		/// <returns>The computed hash code.</returns>
		//int GetHashCode()   { return (int)math::hash(*this); }


		/// <summary>Returns a string representation of the float3x3.</summary>
		/// <returns>String representation of the value.</returns>
		std::string ToString()
		{
			return std::format("float3x3({0}f, {1}f, {2}f,  {3}f, {4}f, {5}f,  {6}f, {7}f, {8}f)", c0.x, c1.x, c2.x, c0.y, c1.y, c2.y, c0.z, c1.z, c2.z);
		}

		//=========================================================
		// matrix
		//=========================================================
    public:
        /// <summary>
        /// Constructs a float3x3 from the upper left 3x3 of a float4x4.
        /// </summary>
        /// <param name="f4x4"><see cref="float4x4"/> to extract a float3x3 from.</param>
        float3x3(const float4x4& f4x4);

        /// <summary>Constructs a float3x3 matrix from a unit quaternion.</summary>
        /// <param name="q">The quaternion rotation.</param>
        float3x3(const quaternion& q);

        /// <summary>
        /// Returns a float3x3 matrix representing a rotation around a unit axis by an angle in radians.
        /// The rotation direction is clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="axis">The rotation axis.</param>
        /// <param name="angle">The angle of rotation in radians.</param>
        /// <returns>The float3x3 matrix representing the rotation around an axis.</returns>
        static float3x3 AxisAngle(const float3& axis, float angle);

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in x-y-z order.</returns>
        static float3x3 EulerXYZ(const float3& xyz);

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the x-axis, then the z-axis and finally the y-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in x-z-y order.</returns>
        static float3x3 EulerXZY(const float3& xyz);

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the y-axis, then the x-axis and finally the z-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in y-x-z order.</returns>
        static float3x3 EulerYXZ(const float3& xyz);

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the y-axis, then the z-axis and finally the x-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in y-z-x order.</returns>
        static float3x3 EulerYZX(const float3& xyz);

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the z-axis, then the x-axis and finally the y-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// This is the default order rotation order in Unity.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in z-x-y order.</returns>
        static float3x3 EulerZXY(const float3& xyz);

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the z-axis, then the y-axis and finally the x-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in z-y-x order.</returns>
        static float3x3 EulerZYX(const float3& xyz);

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in x-y-z order.</returns>
        static float3x3 EulerXYZ(float x, float y, float z) { return EulerXYZ(float3(x, y, z)); }

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the x-axis, then the z-axis and finally the y-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in x-z-y order.</returns>
        static float3x3 EulerXZY(float x, float y, float z) { return EulerXZY(float3(x, y, z)); }

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the y-axis, then the x-axis and finally the z-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in y-x-z order.</returns>
        static float3x3 EulerYXZ(float x, float y, float z) { return EulerYXZ(float3(x, y, z)); }

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the y-axis, then the z-axis and finally the x-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in y-z-x order.</returns>
        static float3x3 EulerYZX(float x, float y, float z) { return EulerYZX(float3(x, y, z)); }

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the z-axis, then the x-axis and finally the y-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// This is the default order rotation order in Unity.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in z-x-y order.</returns>
        static float3x3 EulerZXY(float x, float y, float z) { return EulerZXY(float3(x, y, z)); }

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing a rotation around the z-axis, then the y-axis and finally the x-axis.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in z-y-x order.</returns>
        static float3x3 EulerZYX(float x, float y, float z) { return EulerZYX(float3(x, y, z)); }

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing 3 rotations around the principal axes in a given order.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// When the rotation order is known at compile time, it is recommended for performance reasons to use specific
        /// Euler rotation constructors such as EulerZXY(...).
        /// </summary>
        /// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
        /// <param name="order">The order in which the rotations are applied.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in the given order.</returns>
        static float3x3 Euler(float3 xyz, RotationOrder order = RotationOrder::Default)
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
                return float3x3::identity;
            }
        }

        /// <summary>
        /// Returns a float3x3 rotation matrix constructed by first performing 3 rotations around the principal axes in a given order.
        /// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
        /// When the rotation order is known at compile time, it is recommended for performance reasons to use specific
        /// Euler rotation constructors such as EulerZXY(...).
        /// </summary>
        /// <param name="x">The rotation angle around the x-axis in radians.</param>
        /// <param name="y">The rotation angle around the y-axis in radians.</param>
        /// <param name="z">The rotation angle around the z-axis in radians.</param>
        /// <param name="order">The order in which the rotations are applied.</param>
        /// <returns>The float3x3 rotation matrix representing the rotation by Euler angles in the given order.</returns>
        static float3x3 Euler(float x, float y, float z, RotationOrder order = RotationOrder::Default)
        {
            return Euler(float3(x, y, z), order);
        }

        /// <summary>Returns a float3x3 matrix that rotates around the x-axis by a given number of radians.</summary>
        /// <param name="angle">The clockwise rotation angle when looking along the x-axis towards the origin in radians.</param>
        /// <returns>The float3x3 rotation matrix representing a rotation around the x-axis.</returns>
        static float3x3 RotateX(float angle);


        /// <summary>Returns a float3x3 matrix that rotates around the y-axis by a given number of radians.</summary>
        /// <param name="angle">The clockwise rotation angle when looking along the y-axis towards the origin in radians.</param>
        /// <returns>The float3x3 rotation matrix representing a rotation around the y-axis.</returns>
        static float3x3 RotateY(float angle);

        /// <summary>Returns a float3x3 matrix that rotates around the z-axis by a given number of radians.</summary>
        /// <param name="angle">The clockwise rotation angle when looking along the z-axis towards the origin in radians.</param>
        /// <returns>The float3x3 rotation matrix representing a rotation around the z-axis.</returns>
        static float3x3 RotateZ(float angle);

        /// <summary>Returns a float3x3 matrix representing a uniform scaling of all axes by s.</summary>
        /// <param name="s">The uniform scaling factor.</param>
        /// <returns>The float3x3 matrix representing a uniform scale.</returns>
        static float3x3 Scale(float s)
        {
            return float3x3(s, 0.0f, 0.0f,
                            0.0f, s, 0.0f,
                            0.0f, 0.0f, s);
        }

        /// <summary>Returns a float3x3 matrix representing a non-uniform axis scaling by x, y and z.</summary>
        /// <param name="x">The x-axis scaling factor.</param>
        /// <param name="y">The y-axis scaling factor.</param>
        /// <param name="z">The z-axis scaling factor.</param>
        /// <returns>The float3x3 rotation matrix representing a non-uniform scale.</returns>
        static float3x3 Scale(float x, float y, float z)
        {
            return float3x3(x, 0.0f, 0.0f,
                            0.0f, y, 0.0f,
                            0.0f, 0.0f, z);
        }

        /// <summary>Returns a float3x3 matrix representing a non-uniform axis scaling by the components of the float3 vector v.</summary>
        /// <param name="v">The vector containing non-uniform scaling factors.</param>
        /// <returns>The float3x3 rotation matrix representing a non-uniform scale.</returns>
        static float3x3 Scale(float3 v)
        {
            return Scale(v.x, v.y, v.z);
        }

        /// <summary>
        /// Returns a float3x3 view rotation matrix given a unit length forward vector and a unit length up vector.
        /// The two input vectors are assumed to be unit length and not collinear.
        /// If these assumptions are not met use float3x3.LookRotationSafe instead.
        /// </summary>
        /// <param name="forward">The forward vector to align the center of view with.</param>
        /// <param name="up">The up vector to point top of view toward.</param>
        /// <returns>The float3x3 view rotation matrix.</returns>
        static float3x3 LookRotation(const float3& forward, const float3& up);

        /// <summary>
        /// Returns a float3x3 view rotation matrix given a forward vector and an up vector.
        /// The two input vectors are not assumed to be unit length.
        /// If the magnitude of either of the vectors is so extreme that the calculation cannot be carried out reliably or the vectors are collinear,
        /// the identity will be returned instead.
        /// </summary>
        /// <param name="forward">The forward vector to align the center of view with.</param>
        /// <param name="up">The up vector to point top of view toward.</param>
        /// <returns>The float3x3 view rotation matrix or the identity matrix.</returns>
        static float3x3 LookRotationSafe(float3 forward, float3 up);

        /// <summary>
        /// Converts a float4x4 to a float3x3.
        /// </summary>
        /// <param name="f4x4">The float4x4 to convert to a float3x3.</param>
        /// <returns>The float3x3 constructed from the upper left 3x3 of the input float4x4 matrix.</returns>
        //static explicit operator float3x3(float4x4 f4x4) = > new float3x3(f4x4);
	};
    __declspec(selectany) const float3x3    float3x3::identity  = float3x3(1.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 1.f);
    __declspec(selectany) const float3x3	float3x3::zero      = float3x3(0.f, 0.f, 0.f);
#pragma pack(pop)

    namespace math
    {
        //=========================================================
        // math-float3x3
        //=========================================================
        /// <summary>Return the float3x3 transpose of a float3x3 matrix.</summary>
        /// <param name="v">Value to transpose.</param>
        /// <returns>Transposed value.</returns>
        float3x3 transpose(const float3x3& v);

        /// <summary>Returns the float3x3 full inverse of a float3x3 matrix.</summary>
        /// <param name="m">Matrix to invert.</param>
        /// <returns>The inverted matrix.</returns>
        float3x3 inverse(const float3x3& m);

        /// <summary>Returns the determinant of a float3x3 matrix.</summary>
        /// <param name="m">Matrix to use when computing determinant.</param>
        /// <returns>The determinant of the matrix.</returns>
        float determinant(const float3x3& m);

        /// <summary>Returns a uint hash code of a float3x3 matrix.</summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint hash of the argument.</returns>
        uint hash(const float3x3& v);

        /// <summary>
        /// Returns a uint3 vector hash code of a float3x3 matrix.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="v">Matrix value to hash.</param>
        /// <returns>uint3 hash of the argument.</returns>
        uint3 hashwide(const float3x3& v);
    }

} // namespace ecs
