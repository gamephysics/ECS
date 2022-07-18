#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/quaternion.cs
	struct quaternion
	{
	public:
		static const  quaternion	identity;

		float4		value;

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
		quaternion() : value(0) {}
		quaternion(float x, float y, float z, float w)	{ value.x = x; value.y = y; value.z = z; value.w = w; }
		quaternion(const float4& v)						{ value = v; }
		quaternion(const float3x3& m);

		/// <summary>Constructs a unit quaternion from an orthonormal float4x4 matrix.</summary>
		/// <param name="m">The float4x4 orthonormal rotation matrix.</param>
		quaternion(const float4x4& m);

		//=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
		quaternion& operator = (const quaternion& rhs) { this->value = rhs.value; return (*this); }
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
		// subtraction      :   a - b
		// multiplication   :   a * b
		// division         :   a / b
		// modulo           :   a % b
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
		// not equal to     :   a != b
		// less than        :   a < b
		// greater than     :   a > b
		// less than or equal to    : a <= b	
		// greater than or equal to : a >= b

		//=========================================================
		// Conversion operators
		//=========================================================



		//=========================================================
		// Static METHODS
		//=========================================================
		/// <summary>
		/// Returns a quaternion representing a rotation around a unit axis by an angle in radians.
		/// The rotation direction is clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="axis">The axis of rotation.</param>
		/// <param name="angle">The angle of rotation in radians.</param>
		/// <returns>The quaternion representing a rotation around an axis.</returns>
		static quaternion AxisAngle(const float3& axis, float angle);

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in x-y-z order.</returns>
		static quaternion EulerXYZ(const float3& xyz);

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the x-axis, then the z-axis and finally the y-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in x-z-y order.</returns>
		static quaternion EulerXZY(const float3& xyz);

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the y-axis, then the x-axis and finally the z-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in y-x-z order.</returns>
		static quaternion EulerYXZ(const float3& xyz);

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the y-axis, then the z-axis and finally the x-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in y-z-x order.</returns>
		static quaternion EulerYZX(const float3& xyz);

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the z-axis, then the x-axis and finally the y-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// This is the default order rotation order in Unity.
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in z-x-y order.</returns>
		static quaternion EulerZXY(const float3& xyz);

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the z-axis, then the y-axis and finally the x-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in z-y-x order.</returns>
		static quaternion EulerZYX(const float3& xyz);

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="x">The rotation angle around the x-axis in radians.</param>
		/// <param name="y">The rotation angle around the y-axis in radians.</param>
		/// <param name="z">The rotation angle around the z-axis in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in x-y-z order.</returns>
		quaternion EulerXYZ(float x, float y, float z) { return EulerXYZ(float3(x, y, z)); }

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the x-axis, then the z-axis and finally the y-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="x">The rotation angle around the x-axis in radians.</param>
		/// <param name="y">The rotation angle around the y-axis in radians.</param>
		/// <param name="z">The rotation angle around the z-axis in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in x-z-y order.</returns>
		static quaternion EulerXZY(float x, float y, float z) { return EulerXZY(float3(x, y, z)); }

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the y-axis, then the x-axis and finally the z-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="x">The rotation angle around the x-axis in radians.</param>
		/// <param name="y">The rotation angle around the y-axis in radians.</param>
		/// <param name="z">The rotation angle around the z-axis in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in y-x-z order.</returns>
		static quaternion EulerYXZ(float x, float y, float z) { return EulerYXZ(float3(x, y, z)); }

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the y-axis, then the z-axis and finally the x-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="x">The rotation angle around the x-axis in radians.</param>
		/// <param name="y">The rotation angle around the y-axis in radians.</param>
		/// <param name="z">The rotation angle around the z-axis in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in y-z-x order.</returns>
		static quaternion EulerYZX(float x, float y, float z) { return EulerYZX(float3(x, y, z)); }

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the z-axis, then the x-axis and finally the y-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// This is the default order rotation order in Unity.
		/// </summary>
		/// <param name="x">The rotation angle around the x-axis in radians.</param>
		/// <param name="y">The rotation angle around the y-axis in radians.</param>
		/// <param name="z">The rotation angle around the z-axis in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in z-x-y order.</returns>
		static quaternion EulerZXY(float x, float y, float z) { return EulerZXY(float3(x, y, z)); }

		/// <summary>
		/// Returns a quaternion constructed by first performing a rotation around the z-axis, then the y-axis and finally the x-axis.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// </summary>
		/// <param name="x">The rotation angle around the x-axis in radians.</param>
		/// <param name="y">The rotation angle around the y-axis in radians.</param>
		/// <param name="z">The rotation angle around the z-axis in radians.</param>
		/// <returns>The quaternion representing the Euler angle rotation in z-y-x order.</returns>
		static quaternion EulerZYX(float x, float y, float z) { return EulerZYX(float3(x, y, z)); }

		/// <summary>
		/// Returns a quaternion constructed by first performing 3 rotations around the principal axes in a given order.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// When the rotation order is known at compile time, it is recommended for performance reasons to use specific
		/// Euler rotation constructors such as EulerZXY(...).
		/// </summary>
		/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
		/// <param name="order">The order in which the rotations are applied.</param>
		/// <returns>The quaternion representing the Euler angle rotation in the specified order.</returns>
		static quaternion Euler(const float3& xyz, RotationOrder order = RotationOrder::ZXY)
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
				return quaternion::identity;
			}
		}

		/// <summary>
		/// Returns a quaternion constructed by first performing 3 rotations around the principal axes in a given order.
		/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
		/// When the rotation order is known at compile time, it is recommended for performance reasons to use specific
		/// Euler rotation constructors such as EulerZXY(...).
		/// </summary>
		/// <param name="x">The rotation angle around the x-axis in radians.</param>
		/// <param name="y">The rotation angle around the y-axis in radians.</param>
		/// <param name="z">The rotation angle around the z-axis in radians.</param>
		/// <param name="order">The order in which the rotations are applied.</param>
		/// <returns>The quaternion representing the Euler angle rotation in the specified order.</returns>
		static quaternion Euler(float x, float y, float z, RotationOrder order = RotationOrder::Default)
		{
			return Euler(float3(x, y, z), order);
		}

		/// <summary>Returns a quaternion that rotates around the x-axis by a given number of radians.</summary>
		/// <param name="angle">The clockwise rotation angle when looking along the x-axis towards the origin in radians.</param>
		/// <returns>The quaternion representing a rotation around the x-axis.</returns>
		static quaternion RotateX(float angle);

		/// <summary>Returns a quaternion that rotates around the y-axis by a given number of radians.</summary>
		/// <param name="angle">The clockwise rotation angle when looking along the y-axis towards the origin in radians.</param>
		/// <returns>The quaternion representing a rotation around the y-axis.</returns>
		static quaternion RotateY(float angle);

		/// <summary>Returns a quaternion that rotates around the z-axis by a given number of radians.</summary>
		/// <param name="angle">The clockwise rotation angle when looking along the z-axis towards the origin in radians.</param>
		/// <returns>The quaternion representing a rotation around the z-axis.</returns>
		static quaternion RotateZ(float angle);

		/// <summary>
		/// Returns a quaternion view rotation given a unit length forward vector and a unit length up vector.
		/// The two input vectors are assumed to be unit length and not collinear.
		/// If these assumptions are not met use float3x3.LookRotationSafe instead.
		/// </summary>
		/// <param name="forward">The view forward direction.</param>
		/// <param name="up">The view up direction.</param>
		/// <returns>The quaternion view rotation.</returns>
		static quaternion LookRotation(const float3& forward, float3 up);

		/// <summary>
		/// Returns a quaternion view rotation given a forward vector and an up vector.
		/// The two input vectors are not assumed to be unit length.
		/// If the magnitude of either of the vectors is so extreme that the calculation cannot be carried out reliably or the vectors are collinear,
		/// the identity will be returned instead.
		/// </summary>
		/// <param name="forward">The view forward direction.</param>
		/// <param name="up">The view up direction.</param>
		/// <returns>The quaternion view rotation or the identity quaternion.</returns>
		static quaternion LookRotationSafe(float3 forward, float3 up);


		//=========================================================
		// METHOD
		//=========================================================
		/// <summary>Returns true if the quaternion is equal to a given quaternion, false otherwise.</summary>
		/// <param name="x">The quaternion to compare with.</param>
		/// <returns>True if the quaternion is equal to the input, false otherwise.</returns>
		bool Equals(quaternion x) const { return value.x == x.value.x && value.y == x.value.y && value.z == x.value.z && value.w == x.value.w; }

		/// <summary>Returns whether true if the quaternion is equal to a given quaternion, false otherwise.</summary>
		/// <param name="x">The object to compare with.</param>
		/// <returns>True if the quaternion is equal to the input, false otherwise.</returns>
		//override bool Equals(object x) { return x is quaternion converted && Equals(converted); }

		/// <summary>Returns a hash code for the quaternion.</summary>
		/// <returns>The hash code of the quaternion.</returns>
		//int GetHashCode() { return (int)math::hash(*this); }

		/// <summary>Returns a string representation of the quaternion.</summary>
		/// <returns>The string representation of the quaternion.</returns>
		std::string ToString()
		{
			return std::format("quaternion({0}f, {1}f, {2}f, {3}f)", value.x, value.y, value.z, value.w);
		}
	};
	__declspec(selectany) const quaternion	quaternion::identity = quaternion(0.0f, 0.0f, 0.0f, 1.0f);

	namespace math
	{
		//=========================================================
		// math-quaternion
		//=========================================================
		/// <summary>Returns the conjugate of a quaternion value.</summary>
		// <param name="q">The quaternion to conjugate.</param>
		// <returns>The conjugate of the input quaternion.</returns>
		quaternion conjugate(const quaternion& q);

		// <summary>Returns the inverse of a quaternion value.</summary>
		// <param name="q">The quaternion to invert.</param>
		// <returns>The quaternion inverse of the input quaternion.</returns>
		quaternion inverse(const quaternion& q);

		/// <summary>Returns the dot product of two quaternions.</summary>
		/// <param name="a">The first quaternion.</param>
		/// <param name="b">The second quaternion.</param>
		/// <returns>The dot product of two quaternions.</returns>
		float dot(const quaternion& a, const quaternion& b);

		/// <summary>Returns the length of a quaternion.</summary>
		/// <param name="q">The input quaternion.</param>
		/// <returns>The length of the input quaternion.</returns>
		float length(const quaternion& q);

		/// <summary>Returns the squared length of a quaternion.</summary>
		/// <param name="q">The input quaternion.</param>
		/// <returns>The length squared of the input quaternion.</returns>
		float lengthsq(const quaternion& q);

		/// <summary>Returns a normalized version of a quaternion q by scaling it by 1 / length(q).</summary>
		/// <param name="q">The quaternion to normalize.</param>
		/// <returns>The normalized quaternion.</returns>
		quaternion normalize(const quaternion& q);

		/// <summary>
		/// Returns a safe normalized version of the q by scaling it by 1 / length(q).
		/// Returns the identity when 1 / length(q) does not produce a finite number.
		/// </summary>
		/// <param name="q">The quaternion to normalize.</param>
		/// <returns>The normalized quaternion or the identity quaternion.</returns>
		quaternion normalizesafe(const quaternion& q);

		/// <summary>
		/// Returns a safe normalized version of the q by scaling it by 1 / length(q).
		/// Returns the given default value when 1 / length(q) does not produce a finite number.
		/// </summary>
		/// <param name="q">The quaternion to normalize.</param>
		/// <param name="defaultvalue">The default value.</param>
		/// <returns>The normalized quaternion or the default value.</returns>
		quaternion normalizesafe(const quaternion& q, const quaternion& defaultvalue);

		/// <summary>Returns the natural exponent of a quaternion. Assumes w is zero.</summary>
		/// <param name="q">The quaternion with w component equal to zero.</param>
		/// <returns>The natural exponent of the input quaternion.</returns>
		quaternion unitexp(const quaternion& q);

		/// <summary>Returns the natural exponent of a quaternion.</summary>
		/// <param name="q">The quaternion.</param>
		/// <returns>The natural exponent of the input quaternion.</returns>
		quaternion exp(const quaternion& q);

		/// <summary>Returns the natural logarithm of a unit length quaternion.</summary>
		/// <param name="q">The unit length quaternion.</param>
		/// <returns>The natural logarithm of the unit length quaternion.</returns>
		quaternion unitlog(const quaternion& q);

		/// <summary>Returns the natural logarithm of a quaternion.</summary>
		/// <param name="q">The quaternion.</param>
		/// <returns>The natural logarithm of the input quaternion.</returns>
		quaternion log(const quaternion& q);

		/// <summary>Returns the result of transforming the quaternion b by the quaternion a.</summary>
		/// <param name="a">The quaternion on the left.</param>
		/// <param name="b">The quaternion on the right.</param>
		/// <returns>The result of transforming quaternion b by the quaternion a.</returns>
		quaternion mul(const quaternion& a, const quaternion& b);

		/// <summary>Returns the result of transforming a vector by a quaternion.</summary>
		/// <param name="q">The quaternion transformation.</param>
		/// <param name="v">The vector to transform.</param>
		/// <returns>The transformation of vector v by quaternion q.</returns>
		float3 mul(const quaternion& q, const float3& v);

		/// <summary>Returns the result of rotating a vector by a unit quaternion.</summary>
		/// <param name="q">The quaternion rotation.</param>
		/// <param name="v">The vector to rotate.</param>
		/// <returns>The rotation of vector v by quaternion q.</returns>
		float3 rotate(const quaternion& q, const float3& v);

		/// <summary>Returns the result of a normalized linear interpolation between two quaternions q1 and a2 using an interpolation parameter t.</summary>
		/// <remarks>
		/// Prefer to use this over slerp() when you know the distance between q1 and q2 is small. This can be much
		/// higher performance due to avoiding trigonometric function evaluations that occur in slerp().
		/// </remarks>
		/// <param name="q1">The first quaternion.</param>
		/// <param name="q2">The second quaternion.</param>
		/// <param name="t">The interpolation parameter.</param>
		/// <returns>The normalized linear interpolation of two quaternions.</returns>
		quaternion nlerp(const quaternion& q1, const quaternion& q2, float t);

		/// <summary>Returns the result of a spherical interpolation between two quaternions q1 and a2 using an interpolation parameter t.</summary>
		/// <param name="q1">The first quaternion.</param>
		/// <param name="q2">The second quaternion.</param>
		/// <param name="t">The interpolation parameter.</param>
		/// <returns>The spherical linear interpolation of two quaternions.</returns>
		quaternion slerp(const quaternion& q1, const quaternion& q2, float t);

		/// <summary>Returns the angle in radians between two unit quaternions.</summary>
		/// <param name="q1">The first quaternion.</param>
		/// <param name="q2">The second quaternion.</param>
		/// <returns>The angle between two unit quaternions.</returns>
		float angle(const quaternion& q1, const quaternion& q2);

		/// <summary>
		/// Extracts the rotation from a matrix.
		/// </summary>
		/// <remarks>This method supports any type of rotation matrix: if the matrix has a non uniform scale you should use this method.</remarks>
		/// <param name="m">Matrix to extract rotation from</param>
		/// <returns>Extracted rotation</returns>
		quaternion rotation(const float3x3& m);

		float3x3 adj(const float3x3& m, OUT float& det);

		bool adjInverse(const float3x3& m, OUT float3x3& i, float epsilon = svd::k_EpsilonNormal);

		/// <summary>Returns a uint hash code of a quaternion.</summary>
		/// <param name="q">The quaternion to hash.</param>
		/// <returns>The hash code for the input quaternion.</returns>
		uint hash(const quaternion& q);

		/// <summary>
		/// Returns a uint4 vector hash code of a quaternion.
		/// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
		/// that are only reduced to a narrow uint hash at the very end instead of at every step.
		/// </summary>
		/// <param name="q">The quaternion to hash.</param>
		/// <returns>The uint4 vector hash code of the input quaternion.</returns>
		uint4 hashwide(const quaternion& q);

		/// <summary>
		/// Transforms the forward vector by a quaternion.
		/// </summary>
		/// <param name="q">The quaternion transformation.</param>
		/// <returns>The forward vector transformed by the input quaternion.</returns>
		float3 forward(const quaternion& q);    // for compatibility
	}

} // namespace ecs

