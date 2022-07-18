#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/affine_transform.cs
    struct AffineTransform
    {
    public:
        /// <summary>An AffineTransform representing the identity transform.</summary>
        static const AffineTransform identity;

        /// <summary>
        /// The rotation and scale part of the affine transformation.
        /// </summary>
        float3x3 rs;

        /// <summary>
        /// The translation part of the affine transformation.
        /// </summary>
        float3 t;

    public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        AffineTransform() : rs(float3x3::identity), t(float3::zero) {}

        /// <summary>Constructs an AffineTransform from a translation represented by a float3 vector and rotation represented by a unit quaternion.</summary>
        /// <param name="translation">The translation vector.</param>
        /// <param name="rotation">The rotation quaternion.</param>
        AffineTransform(const float3& translation, const quaternion& rotation)
        {
            rs = float3x3(rotation);
            t = translation;
        }

        /// <summary>Constructs an AffineTransform from a translation represented by a float3 vector, rotation represented by a unit quaternion and scale represented by a float3 vector.</summary>
        /// <param name="translation">The translation vector.</param>
        /// <param name="rotation">The rotation quaternion.</param>
        /// <param name="scale">The scale vector.</param>
        AffineTransform(const float3& translation, const quaternion& rotation, const float3& scale)
        {
            rs = math::mulScale(float3x3(rotation), scale);
            t = translation;
        }

        /// <summary>Constructs an AffineTransform from a translation represented by float3 vector and a float3x3 matrix representing both rotation and scale.</summary>
        /// <param name="translation">The translation vector.</param>
        /// <param name="rotationScale">The rotation and scale matrix.</param>
        AffineTransform(const float3& translation, const float3x3& rotationScale)
        {
            rs = rotationScale;
            t = translation;
        }

        /// <summary>Constructs an AffineTransform from float3x3 matrix representating both rotation and scale.</summary>
        /// <param name="rotationScale">The rotation and scale matrix.</param>
        AffineTransform(const float3x3& rotationScale)
        {
            rs = rotationScale;
            t = float3::zero;
        }

        /// <summary>Constructs an AffineTransform from a RigidTransform.</summary>
        /// <param name="rigid">The RigidTransform.</param>
        AffineTransform(const RigidTransform& rigid)
        {
            rs = float3x3(rigid.rot);
            t = rigid.pos;
        }

        /// <summary>Constructs an AffineTransform from a float3x4 matrix.</summary>
        /// <param name="m">The float3x4 matrix.</param>
        AffineTransform(const float3x4& m)
        {
            rs = float3x3(m.c0, m.c1, m.c2);
            t = m.c3;
        }

        /// <summary>Constructs an AffineTransform from a float4x4 matrix.</summary>
        /// <param name="m">The float4x4 matrix.</param>
        AffineTransform(const float4x4& m)
        {
            rs = float3x3(m.c0.xyz(), m.c1.xyz(), m.c2.xyz());
            t = m.c3.xyz();
        }

        //=========================================================
        // OPERATORS
        //=========================================================
        //=========================================================
        // Assignment operators : T&
        //=========================================================
        // simple assignment	            a = b	
        AffineTransform& operator = (const AffineTransform& rhs) { this->rs = rhs.rs; this->t = rhs.t; return (*this); }
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
        /// <summary>Implicit float3x4 cast operator.</summary>
        /// <param name="m">The AffineTransform.</param>
        operator float3x4() { return float3x4(this->rs.c0, this->rs.c1, this->rs.c2, this->t); }

        /// <summary>Implicit float4x4 cast operator.</summary>
        /// <param name="m">The AffineTransform.</param>
        operator float4x4() { return float4x4(float4(this->rs.c0, 0.f), float4(this->rs.c1, 0.f), float4(this->rs.c2, 0.f), float4(this->t, 1.f)); }

        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>Returns true if the AffineTransform is equal to a given AffineTransform, false otherwise.</summary>
        /// <param name="rhs">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        bool Equals(const AffineTransform& rhs) { return rs.Equals(rhs.rs) && t.Equals(rhs.t); }

        /// <summary>Returns true if the AffineTransform is equal to a given AffineTransform, false otherwise.</summary>
        /// <param name="o">Right hand side argument to compare equality with.</param>
        /// <returns>The result of the equality comparison.</returns>
        //override bool Equals(object o) { return o is AffineTransform converted && Equals(converted); }

        /// <summary>Returns a hash code for the AffineTransform.</summary>
        /// <returns>The computed hash code.</returns>
        //int GetHashCode() { return (int)math::hash(*this); }

        /// <summary>Returns a string representation of the AffineTransform.</summary>
        /// <returns>String representation of the value.</returns>
        std::string ToString()
        {
            return std::format("AffineTransform(({0}f, {1}f, {2}f,  {3}f, {4}f, {5}f,  {6}f, {7}f, {8}f), ({9}f, {10}f, {11}f))",
                rs.c0.x, rs.c1.x, rs.c2.x, rs.c0.y, rs.c1.y, rs.c2.y, rs.c0.z, rs.c1.z, rs.c2.z, t.x, t.y, t.z
            );
        }
    };
    __declspec(selectany) const AffineTransform AffineTransform::identity = AffineTransform(float3::zero, float3x3::identity);

    namespace math
    {
        //=========================================================
        // math-AffineTransform
        //=========================================================
        /// <summary>Returns the result of transforming the AffineTransform b by the const AffineTransform& a.</summary>
        /// <param name="a">The AffineTransform on the left.</param>
        /// <param name="b">The AffineTransform on the right.</param>
        /// <returns>The AffineTransform of a transforming b.</returns>
        AffineTransform mul(const AffineTransform& a, const AffineTransform& b);

        /// <summary>Returns the result of transforming the AffineTransform b by a float3x3 matrix a.</summary>
        /// <param name="a">The float3x3 matrix on the left.</param>
        /// <param name="b">The AffineTransform on the right.</param>
        /// <returns>The AffineTransform of a transforming b.</returns>
        AffineTransform mul(const float3x3& a, const AffineTransform& b);

        /// <summary>Returns the result of transforming the float3x3 b by an const AffineTransform& a.</summary>
        /// <param name="a">The AffineTransform on the left.</param>
        /// <param name="b">The float3x3 matrix on the right.</param>
        /// <returns>The AffineTransform of a transforming b.</returns>
        AffineTransform mul(const AffineTransform& a, const float3x3& b);

        /// <summary>Returns the result of transforming a float4 homogeneous coordinate by an AffineTransform.</summary>
        /// <param name="a">The AffineTransform.</param>
        /// <param name="pos">The position to be transformed.</param>
        /// <returns>The transformed position.</returns>
        float4 mul(const AffineTransform& a, const float4& pos);

        /// <summary>Returns the result of rotating a float3 vector by an AffineTransform.</summary>
        /// <param name="a">The AffineTransform.</param>
        /// <param name="dir">The direction vector to rotate.</param>
        /// <returns>The rotated direction vector.</returns>
        float3 rotate(const AffineTransform& a, const float3& dir);

        /// <summary>Returns the result of transforming a float3 point by an AffineTransform.</summary>
        /// <param name="a">The AffineTransform.</param>
        /// <param name="pos">The position to transform.</param>
        /// <returns>The transformed position.</returns>
        float3 transform(const AffineTransform& a, const float3& pos);

        /// <summary>Returns the inverse of an AffineTransform.</summary>
        /// <param name="t">The AffineTransform to invert.</param>
        /// <returns>The inverse AffineTransform.</returns>
        AffineTransform inverse(const AffineTransform& a);

        /// <summary>Decomposes the AffineTransform in translation, rotation and scale.</summary>
        /// <param name="a">The AffineTransform</param>
        /// <param name="translation">The decomposed translation vector of the AffineTransform.</param>
        /// <param name="rotation">The decomposed rotation quaternion of the AffineTransform.</param>
        /// <param name="scale">The decomposed scale of the AffineTransform.</param>
        void decompose(const AffineTransform& a, OUT float3& translation, OUT quaternion& rotation, OUT float3& scale);

        /// <summary>Returns a uint hash code of an AffineTransform.</summary>
        /// <param name="a">The AffineTransform to hash.</param>
        /// <returns>The hash code of the input AffineTransform.</returns>
        uint hash(const AffineTransform& a);

        /// <summary>
        /// Returns a uint4 vector hash code of an AffineTransform.
        /// When multiple elements are to be hashes together, it can more efficient to calculate and combine wide hash
        /// that are only reduced to a narrow uint hash at the very end instead of at every step.
        /// </summary>
        /// <param name="a">The AffineTransform to hash.</param>
        /// <returns>The uint4 wide hash code.</returns>
        uint4 hashwide(const AffineTransform& a);
    }

} // namespace ecs

