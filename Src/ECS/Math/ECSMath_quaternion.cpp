#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	//=========================================================
	// quaternion
	//=========================================================
	quaternion::quaternion(const float3x3& m)
	{
		float3 u = m.c0;
		float3 v = m.c1;
		float3 w = m.c2;

		uint u_sign = (math::asuint(u.x) & 0x80000000);
		float t = v.y + math::asfloat(math::asuint(w.z) ^ u_sign);
		uint4 u_mask = uint4((int)u_sign >> 31);
		uint4 t_mask = uint4(math::asint(t) >> 31);

		float tr = 1.0f + math::abs(u.x);

		uint4 sign_flips = uint4(0x00000000, 0x80000000, 0x80000000, 0x80000000) ^ (u_mask & uint4(0x00000000, 0x80000000, 0x00000000, 0x80000000)) ^ (t_mask & uint4(0x80000000, 0x80000000, 0x80000000, 0x00000000));

		value = float4(tr, u.y, w.x, v.z) + math::asfloat(math::asuint(float4(t, v.x, u.z, w.y)) ^ sign_flips);   // +---, +++-, ++-+, +-++

		value = math::asfloat((math::asuint(value) & ~u_mask) | (math::asuint(value.zwxy()) & u_mask));
		value = math::asfloat((math::asuint(value.wzyx()) & ~t_mask) | (math::asuint(value) & t_mask));
		value = math::normalize(value);
	}

	/// <summary>Constructs a unit quaternion from an orthonormal float4x4 matrix.</summary>
	/// <param name="m">The float4x4 orthonormal rotation matrix.</param>
	quaternion::quaternion(const float4x4& m)
	{
		float4 u = m.c0;
		float4 v = m.c1;
		float4 w = m.c2;

		uint u_sign = (math::asuint(u.x) & 0x80000000);
		float t = v.y + math::asfloat(math::asuint(w.z) ^ u_sign);
		uint4 u_mask = uint4((int)u_sign >> 31);
		uint4 t_mask = uint4(math::asint(t) >> 31);

		float tr = 1.0f + math::abs(u.x);

		uint4 sign_flips = uint4(0x00000000, 0x80000000, 0x80000000, 0x80000000) ^ (u_mask & uint4(0x00000000, 0x80000000, 0x00000000, 0x80000000)) ^ (t_mask & uint4(0x80000000, 0x80000000, 0x80000000, 0x00000000));

		value = float4(tr, u.y, w.x, v.z) + math::asfloat(math::asuint(float4(t, v.x, u.z, w.y)) ^ sign_flips);   // +---, +++-, ++-+, +-++

		value = math::asfloat((math::asuint(value) & ~u_mask) | (math::asuint(value.zwxy()) & u_mask));
		value = math::asfloat((math::asuint(value.wzyx()) & ~t_mask) | (math::asuint(value) & t_mask));
		value = math::normalize(value);
	}

	/// <summary>
	/// Returns a quaternion representing a rotation around a unit axis by an angle in radians.
	/// The rotation direction is clockwise when looking along the rotation axis towards the origin.
	/// </summary>
	/// <param name="axis">The axis of rotation.</param>
	/// <param name="angle">The angle of rotation in radians.</param>
	/// <returns>The quaternion representing a rotation around an axis.</returns>
	quaternion quaternion::AxisAngle(const float3& axis, float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle, OUT sina, OUT cosa);
		return quaternion(float4(axis * sina, cosa));
	}

	/// <summary>
	/// Returns a quaternion constructed by first performing a rotation around the x-axis, then the y-axis and finally the z-axis.
	/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
	/// </summary>
	/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
	/// <returns>The quaternion representing the Euler angle rotation in x-y-z order.</returns>
	quaternion quaternion::EulerXYZ(const float3& xyz)
	{
		// return mul(rotateZ(xyz.z), mul(rotateY(xyz.y), rotateX(xyz.x)));
		float3 s, c;
		math::sincos(0.5f * xyz, OUT s, OUT c);
		return quaternion(
			// s.x * c.y * c.z - s.y * s.z * c.x,
			// s.y * c.x * c.z + s.x * s.z * c.y,
			// s.z * c.x * c.y - s.x * s.y * c.z,
			// c.x * c.y * c.z + s.y * s.z * s.x
			float4(s.xyz(), c.x) * c.yxxy() * c.zzyz() + s.yxxy() * s.zzyz() * float4(c.xyz(), s.x) * float4(-1.0f, 1.0f, -1.0f, 1.0f)
		);
	}

	/// <summary>
	/// Returns a quaternion constructed by first performing a rotation around the x-axis, then the z-axis and finally the y-axis.
	/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
	/// </summary>
	/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
	/// <returns>The quaternion representing the Euler angle rotation in x-z-y order.</returns>
	quaternion quaternion::EulerXZY(const float3& xyz)
	{
		// return mul(rotateY(xyz.y), mul(rotateZ(xyz.z), rotateX(xyz.x)));
		float3 s, c;
		math::sincos(0.5f * xyz, OUT s, OUT c);
		return quaternion(
			// s.x * c.y * c.z + s.y * s.z * c.x,
			// s.y * c.x * c.z + s.x * s.z * c.y,
			// s.z * c.x * c.y - s.x * s.y * c.z,
			// c.x * c.y * c.z - s.y * s.z * s.x
			float4(s.xyz(), c.x) * c.yxxy() * c.zzyz() + s.yxxy() * s.zzyz() * float4(c.xyz(), s.x) * float4(1.0f, 1.0f, -1.0f, -1.0f)
		);
	}

	/// <summary>
	/// Returns a quaternion constructed by first performing a rotation around the y-axis, then the x-axis and finally the z-axis.
	/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
	/// </summary>
	/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
	/// <returns>The quaternion representing the Euler angle rotation in y-x-z order.</returns>
	quaternion quaternion::EulerYXZ(const float3& xyz)
	{
		// return mul(rotateZ(xyz.z), mul(rotateX(xyz.x), rotateY(xyz.y)));
		float3 s, c;
		math::sincos(0.5f * xyz, OUT s, OUT c);
		return quaternion(
			// s.x * c.y * c.z - s.y * s.z * c.x,
			// s.y * c.x * c.z + s.x * s.z * c.y,
			// s.z * c.x * c.y + s.x * s.y * c.z,
			// c.x * c.y * c.z - s.y * s.z * s.x
			float4(s.xyz(), c.x) * c.yxxy() * c.zzyz() + s.yxxy() * s.zzyz() * float4(c.xyz(), s.x) * float4(-1.0f, 1.0f, 1.0f, -1.0f)
		);
	}

	/// <summary>
	/// Returns a quaternion constructed by first performing a rotation around the y-axis, then the z-axis and finally the x-axis.
	/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
	/// </summary>
	/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
	/// <returns>The quaternion representing the Euler angle rotation in y-z-x order.</returns>
	quaternion quaternion::EulerYZX(const float3& xyz)
	{
		// return mul(rotateX(xyz.x), mul(rotateZ(xyz.z), rotateY(xyz.y)));
		float3 s, c;
		math::sincos(0.5f * xyz, OUT s, OUT c);
		return quaternion(
			// s.x * c.y * c.z - s.y * s.z * c.x,
			// s.y * c.x * c.z - s.x * s.z * c.y,
			// s.z * c.x * c.y + s.x * s.y * c.z,
			// c.x * c.y * c.z + s.y * s.z * s.x
			float4(s.xyz(), c.x) * c.yxxy() * c.zzyz() + s.yxxy() * s.zzyz() * float4(c.xyz(), s.x) * float4(-1.0f, -1.0f, 1.0f, 1.0f)
		);
	}

	/// <summary>
	/// Returns a quaternion constructed by first performing a rotation around the z-axis, then the x-axis and finally the y-axis.
	/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
	/// This is the default order rotation order in Unity.
	/// </summary>
	/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
	/// <returns>The quaternion representing the Euler angle rotation in z-x-y order.</returns>
	quaternion quaternion::EulerZXY(const float3& xyz)
	{
		// return mul(rotateY(xyz.y), mul(rotateX(xyz.x), rotateZ(xyz.z)));
		float3 s, c;
		math::sincos(0.5f * xyz, OUT s, OUT c);
		return quaternion(
			// s.x * c.y * c.z + s.y * s.z * c.x,
			// s.y * c.x * c.z - s.x * s.z * c.y,
			// s.z * c.x * c.y - s.x * s.y * c.z,
			// c.x * c.y * c.z + s.y * s.z * s.x
			float4(s.xyz(), c.x) * c.yxxy() * c.zzyz() + s.yxxy() * s.zzyz() * float4(c.xyz(), s.x) * float4(1.0f, -1.0f, -1.0f, 1.0f)
		);
	}

	/// <summary>
	/// Returns a quaternion constructed by first performing a rotation around the z-axis, then the y-axis and finally the x-axis.
	/// All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
	/// </summary>
	/// <param name="xyz">A float3 vector containing the rotation angles around the x-, y- and z-axis measures in radians.</param>
	/// <returns>The quaternion representing the Euler angle rotation in z-y-x order.</returns>
	quaternion quaternion::EulerZYX(const float3& xyz)
	{
		// return mul(rotateX(xyz.x), mul(rotateY(xyz.y), rotateZ(xyz.z)));
		float3 s, c;
		math::sincos(0.5f * xyz, OUT s, OUT c);
		return quaternion(
			// s.x * c.y * c.z + s.y * s.z * c.x,
			// s.y * c.x * c.z - s.x * s.z * c.y,
			// s.z * c.x * c.y + s.x * s.y * c.z,
			// c.x * c.y * c.z - s.y * s.x * s.z
			float4(s.xyz(), c.x) * c.yxxy() * c.zzyz() + s.yxxy() * s.zzyz() * float4(c.xyz(), s.x) * float4(1.0f, -1.0f, 1.0f, -1.0f)
		);
	}

	/// <summary>Returns a quaternion that rotates around the x-axis by a given number of radians.</summary>
	/// <param name="angle">The clockwise rotation angle when looking along the x-axis towards the origin in radians.</param>
	/// <returns>The quaternion representing a rotation around the x-axis.</returns>
	quaternion quaternion::RotateX(float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle, OUT sina, OUT cosa);
		return quaternion(sina, 0.0f, 0.0f, cosa);
	}

	/// <summary>Returns a quaternion that rotates around the y-axis by a given number of radians.</summary>
	/// <param name="angle">The clockwise rotation angle when looking along the y-axis towards the origin in radians.</param>
	/// <returns>The quaternion representing a rotation around the y-axis.</returns>
	quaternion quaternion::RotateY(float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle, OUT sina, OUT cosa);
		return quaternion(0.0f, sina, 0.0f, cosa);
	}

	/// <summary>Returns a quaternion that rotates around the z-axis by a given number of radians.</summary>
	/// <param name="angle">The clockwise rotation angle when looking along the z-axis towards the origin in radians.</param>
	/// <returns>The quaternion representing a rotation around the z-axis.</returns>
	quaternion quaternion::RotateZ(float angle)
	{
		float sina, cosa;
		math::sincos(0.5f * angle, OUT sina, OUT cosa);
		return quaternion(0.0f, 0.0f, sina, cosa);
	}

	/// <summary>
	/// Returns a quaternion view rotation given a unit length forward vector and a unit length up vector.
	/// The two input vectors are assumed to be unit length and not collinear.
	/// If these assumptions are not met use float3x3.LookRotationSafe instead.
	/// </summary>
	/// <param name="forward">The view forward direction.</param>
	/// <param name="up">The view up direction.</param>
	/// <returns>The quaternion view rotation.</returns>
	quaternion quaternion::LookRotation(const float3& forward, float3 up)
	{
		float3 t = math::normalize(math::cross(up, forward));
		return quaternion(float3x3(t, math::cross(forward, t), forward));
	}

	/// <summary>
	/// Returns a quaternion view rotation given a forward vector and an up vector.
	/// The two input vectors are not assumed to be unit length.
	/// If the magnitude of either of the vectors is so extreme that the calculation cannot be carried OUT reliably or the vectors are collinear,
	/// the identity will be returned instead.
	/// </summary>
	/// <param name="forward">The view forward direction.</param>
	/// <param name="up">The view up direction.</param>
	/// <returns>The quaternion view rotation or the identity quaternion.</returns>
	quaternion quaternion::LookRotationSafe(float3 forward, float3 up)
	{
		float forwardLengthSq = math::dot(forward, forward);
		float upLengthSq = math::dot(up, up);

		forward *= math::rsqrt(forwardLengthSq);
		up *= math::rsqrt(upLengthSq);

		float3 t = math::cross(up, forward);
		float tLengthSq = math::dot(t, t);
		t *= math::rsqrt(tLengthSq);

		float mn = math::min(math::min(forwardLengthSq, upLengthSq), tLengthSq);
		float mx = math::max(math::max(forwardLengthSq, upLengthSq), tLengthSq);

		bool accept = mn > 1e-35f && mx < 1e35f && isfinite(forwardLengthSq) && isfinite(upLengthSq) && isfinite(tLengthSq);
		return quaternion(math::select(float4(0.0f, 0.0f, 0.0f, 1.0f), quaternion(float3x3(t, math::cross(forward, t), forward)).value, accept));
	}

    namespace math
    {
	    //=========================================================
	    // math-quaternion
	    //=========================================================
        /// <summary>Returns the conjugate of a quaternion value.</summary>
        // <param name="q">The quaternion to conjugate.</param>
        // <returns>The conjugate of the input quaternion.</returns>
        quaternion conjugate(const quaternion& q)
        {
            return quaternion(q.value * float4(-1.0f, -1.0f, -1.0f, 1.0f));
        }

        // <summary>Returns the inverse of a quaternion value.</summary>
        // <param name="q">The quaternion to invert.</param>
        // <returns>The quaternion inverse of the input quaternion.</returns>
        quaternion inverse(const quaternion& q)
        {
            float4 x = q.value;
            return quaternion(math::rcp(math::dot(x, x)) * x * float4(-1.0f, -1.0f, -1.0f, 1.0f));
        }

        /// <summary>Returns the dot product of two quaternions.</summary>
        /// <param name="a">The first quaternion.</param>
        /// <param name="b">The second quaternion.</param>
        /// <returns>The dot product of two quaternions.</returns>
        float dot(const quaternion& a, const quaternion& b)
        {
            return math::dot(a.value, b.value);
        }

        /// <summary>Returns the length of a quaternion.</summary>
        /// <param name="q">The input quaternion.</param>
        /// <returns>The length of the input quaternion.</returns>
        float length(const quaternion& q)
        {
            return math::sqrt(math::dot(q.value, q.value));
        }

        /// <summary>Returns the squared length of a quaternion.</summary>
        /// <param name="q">The input quaternion.</param>
        /// <returns>The length squared of the input quaternion.</returns>
        float lengthsq(const quaternion& q)
        {
            return dot(q.value, q.value);
        }

        /// <summary>Returns a normalized version of a quaternion q by scaling it by 1 / length(q).</summary>
        /// <param name="q">The quaternion to normalize.</param>
        /// <returns>The normalized quaternion.</returns>
        quaternion normalize(const quaternion& q)
        {
            float4 x = q.value;
            return quaternion(math::rsqrt(math::dot(x, x)) * x);
        }

        /// <summary>
        /// Returns a safe normalized version of the q by scaling it by 1 / length(q).
        /// Returns the identity when 1 / length(q) does not produce a finite number.
        /// </summary>
        /// <param name="q">The quaternion to normalize.</param>
        /// <returns>The normalized quaternion or the identity quaternion.</returns>
        quaternion normalizesafe(const quaternion& q)
        {
            float4 x = q.value;
            float len = math::dot(x, x);
            return quaternion(math::select(quaternion::identity.value, x * math::rsqrt(len), len > FLT_MIN_NORMAL));
        }

        /// <summary>
        /// Returns a safe normalized version of the q by scaling it by 1 / length(q).
        /// Returns the given default value when 1 / length(q) does not produce a finite number.
        /// </summary>
        /// <param name="q">The quaternion to normalize.</param>
        /// <param name="defaultvalue">The default value.</param>
        /// <returns>The normalized quaternion or the default value.</returns>
        quaternion normalizesafe(const quaternion& q, const quaternion& defaultvalue)
        {
            float4 x = q.value;
            float len = math::dot(x, x);
            return quaternion(math::select(defaultvalue.value, x * math::rsqrt(len), len > FLT_MIN_NORMAL));
        }

        /// <summary>Returns the natural exponent of a quaternion. Assumes w is zero.</summary>
        /// <param name="q">The quaternion with w component equal to zero.</param>
        /// <returns>The natural exponent of the input quaternion.</returns>
        quaternion unitexp(const quaternion& q)
        {
            float v_rcp_len = math::rsqrt(math::dot(q.value.xyz(), q.value.xyz()));
            float v_len = math::rcp(v_rcp_len);
            float sin_v_len, cos_v_len;
            math::sincos(v_len, OUT sin_v_len, OUT cos_v_len);
            return quaternion(float4(q.value.xyz() * v_rcp_len * sin_v_len, cos_v_len));
        }

        /// <summary>Returns the natural exponent of a quaternion.</summary>
        /// <param name="q">The quaternion.</param>
        /// <returns>The natural exponent of the input quaternion.</returns>
        quaternion exp(const quaternion& q)
        {
            float v_rcp_len = rsqrt(dot(q.value.xyz(), q.value.xyz()));
            float v_len = rcp(v_rcp_len);
            float sin_v_len, cos_v_len;
            math::sincos(v_len, OUT sin_v_len, OUT cos_v_len);
            return quaternion(float4(q.value.xyz() * v_rcp_len * sin_v_len, cos_v_len) * math::exp(q.value.w));
        }

        /// <summary>Returns the natural logarithm of a unit length quaternion.</summary>
        /// <param name="q">The unit length quaternion.</param>
        /// <returns>The natural logarithm of the unit length quaternion.</returns>
        quaternion unitlog(const quaternion& q)
        {
            float w = math::clamp(q.value.w, -1.0f, 1.0f);
            float s = math::acos(w) * math::rsqrt(1.0f - w*w);
            return quaternion(float4(q.value.xyz() * s, 0.0f));
        }

        /// <summary>Returns the natural logarithm of a quaternion.</summary>
        /// <param name="q">The quaternion.</param>
        /// <returns>The natural logarithm of the input quaternion.</returns>
        quaternion log(const quaternion& q)
        {
            float v_len_sq = math::dot(q.value.xyz(), q.value.xyz());
            float q_len_sq = v_len_sq + q.value.w*q.value.w;

            float s = math::acos(math::clamp(q.value.w * math::rsqrt(q_len_sq), -1.0f, 1.0f)) * math::rsqrt(v_len_sq);
            return quaternion(float4(q.value.xyz() * s, 0.5f * log(q_len_sq)));
        }

        /// <summary>Returns the result of transforming the quaternion b by the quaternion a.</summary>
        /// <param name="a">The quaternion on the left.</param>
        /// <param name="b">The quaternion on the right.</param>
        /// <returns>The result of transforming quaternion b by the quaternion a.</returns>
        quaternion mul(const quaternion& a, const quaternion& b)
        {
            return quaternion(a.value.wwww() * b.value + (a.value.xyzx() * b.value.wwwx() + a.value.yzxy() * b.value.zxyy()) * float4(1.0f, 1.0f, 1.0f, -1.0f) - a.value.zxyz() * b.value.yzxz());
        }

        /// <summary>Returns the result of transforming a vector by a quaternion.</summary>
        /// <param name="q">The quaternion transformation.</param>
        /// <param name="v">The vector to transform.</param>
        /// <returns>The transformation of vector v by quaternion q.</returns>
        float3 mul(const quaternion& q, const float3& v)
        {
            float3 t = 2 * cross(q.value.xyz(), v);
            return v + q.value.w * t + cross(q.value.xyz(), t);
        }

        /// <summary>Returns the result of rotating a vector by a unit quaternion.</summary>
        /// <param name="q">The quaternion rotation.</param>
        /// <param name="v">The vector to rotate.</param>
        /// <returns>The rotation of vector v by quaternion q.</returns>
        float3 rotate(const quaternion& q, const float3& v)
        {
            float3 t = 2 * math::cross(q.value.xyz(), v);
            return v + q.value.w * t + math::cross(q.value.xyz(), t);
        }

        /// <summary>Returns the result of a normalized linear interpolation between two quaternions q1 and a2 using an interpolation parameter t.</summary>
        /// <remarks>
        /// Prefer to use this over slerp() when you know the distance between q1 and q2 is small. This can be much
        /// higher performance due to avoiding trigonometric function evaluations that occur in slerp().
        /// </remarks>
        /// <param name="q1">The first quaternion.</param>
        /// <param name="q2">The second quaternion.</param>
        /// <param name="t">The interpolation parameter.</param>
        /// <returns>The normalized linear interpolation of two quaternions.</returns>
        quaternion nlerp(const quaternion& q1, const quaternion& q2, float t)
        {
            return math::normalize(q1.value + t * (math::chgsign(q2.value, math::dot(q1, q2)) - q1.value));
        }

        /// <summary>Returns the result of a spherical interpolation between two quaternions q1 and a2 using an interpolation parameter t.</summary>
        /// <param name="q1">The first quaternion.</param>
        /// <param name="q2">The second quaternion.</param>
        /// <param name="t">The interpolation parameter.</param>
        /// <returns>The spherical linear interpolation of two quaternions.</returns>
        quaternion slerp(const quaternion& q1, quaternion q2, float t)
        {
            float dt = math::dot(q1, q2);
            if (dt < 0.0f)
            {
                dt = -dt;
                q2.value = -q2.value;
            }

            if (dt < 0.9995f)
            {
                float angle = math::acos(dt);
                float s  = math::rsqrt(1.0f - dt * dt);    // 1.0f / sin(angle)
                float w1 = math::sin(angle * (1.0f - t)) * s;
                float w2 = math::sin(angle * t) * s;
                return quaternion(q1.value * w1 + q2.value * w2);
            }
            else
            {
                // if the angle is small, use linear interpolation
                return math::nlerp(q1, q2, t);
            }
        }

        /// <summary>Returns the angle in radians between two unit quaternions.</summary>
        /// <param name="q1">The first quaternion.</param>
        /// <param name="q2">The second quaternion.</param>
        /// <returns>The angle between two unit quaternions.</returns>
        float angle(const quaternion& q1, const quaternion& q2)
        {
            float diff = math::asin(math::length(math::normalize(math::mul(math::conjugate(q1), q2)).value.xyz()));
            return diff + diff;
        }

        /// <summary>
        /// Extracts the rotation from a matrix.
        /// </summary>
        /// <remarks>This method supports any type of rotation matrix: if the matrix has a non uniform scale you should use this method.</remarks>
        /// <param name="m">Matrix to extract rotation from</param>
        /// <returns>Extracted rotation</returns>
        quaternion rotation(const float3x3& m)
        {
            float det = math::determinant(m);
            if (math::abs(1.f - det) < svd::k_EpsilonDeterminant)
                return quaternion(m);

            if (math::abs(det) > svd::k_EpsilonDeterminant)
            {
                float3x3 tmp = mulScale(m, math::rsqrt(float3(math::lengthsq(m.c0), math::lengthsq(m.c1), math::lengthsq(m.c2))));
                if (math::abs(1.f - math::determinant(tmp)) < svd::k_EpsilonDeterminant)
                    return quaternion(tmp);
            }

            return svd::svdRotation(m);
        }

        float3x3 adj(const float3x3& m, OUT float& det)
        {
            float3x3 adjT;
            adjT.c0 = math::cross(m.c1, m.c2);
            adjT.c1 = math::cross(m.c2, m.c0);
            adjT.c2 = math::cross(m.c0, m.c1);
            det = math::dot(m.c0, adjT.c0);

            return math::transpose(adjT);
        }

        bool adjInverse(const float3x3& m, OUT float3x3& i, float epsilon /*= svd::k_EpsilonNormal*/)
        {
            float det;
            i = adj(m, OUT det);
            bool c = math::abs(det) > epsilon;
            float3 detInv = math::select(float3(1.f), math::rcp(det), c);
            i = scaleMul(detInv, i);
            return c;
        }

        /// <summary>Returns a uint hash code of a quaternion.</summary>
        /// <param name="q">The quaternion to hash.</param>
        /// <returns>The hash code for the input quaternion.</returns>
        uint hash(const quaternion& q)
        {
            return hash(q.value);
        }

        /// <summary>
        /// Returns a uint4 vector hash code of a quaternion.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="q">The quaternion to hash.</param>
        /// <returns>The uint4 vector hash code of the input quaternion.</returns>
        uint4 hashwide(const quaternion& q)
        {
            return math::hashwide(q.value);
        }

        /// <summary>
        /// Transforms the forward vector by a quaternion.
        /// </summary>
        /// <param name="q">The quaternion transformation.</param>
        /// <returns>The forward vector transformed by the input quaternion.</returns>
        float3 forward(const quaternion& q) { return math::mul(q, float3(0, 0, 1)); }  // for compatibility
    }

} // namespace ecs
