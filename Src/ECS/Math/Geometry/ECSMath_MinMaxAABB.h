#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/Geometry/MinMaxAABB.cs
	struct MinMaxAABB
	{
	public:
        /// <summary>
        /// The minimum point contained by the AABB.
        /// </summary>
        /// <remarks>
        /// If any component of <see cref="Min"/> is greater than <see cref="Max"/> then this AABB is invalid.
        /// </remarks>
        /// <seealso cref="IsValid"/>
        float3 Min;

        /// <summary>
        /// The maximum point contained by the AABB.
        /// </summary>
        /// <remarks>
        /// If any component of <see cref="Max"/> is less than <see cref="Min"/> then this AABB is invalid.
        /// </remarks>
        /// <seealso cref="IsValid"/>
        float3 Max;

	public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        MinMaxAABB() : Min(float3::zero), Max(float3::zero)         {}

        /// <summary>
        /// Constructs the AABB with the given minimum and maximum.
        /// </summary>
        /// <remarks>
        /// If you have a center and extents, you can call <see cref="CreateFromCenterAndExtents"/> or <see cref="CreateFromCenterAndHalfExtents"/>
        /// to create the AABB.
        /// </remarks>
        /// <param name="min">Minimum point inside AABB.</param>
        /// <param name="max">Maximum point inside AABB.</param>
        MinMaxAABB(const float3& min, const float3& max)
        {
            Min = min;
            Max = max;
        }

        //=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        MinMaxAABB& operator = (const MinMaxAABB& rhs) { this->Min = rhs.Min; this->Max = rhs.Max; return (*this); }
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
        // Static METHOD
        //=========================================================
        /// <summary>
        /// Creates the AABB from a center and extents.
        /// </summary>
        /// <remarks>
        /// This function takes full extents. It is the distance between <see cref="Min"/> and <see cref="Max"/>.
        /// If you have half extents, you can call <see cref="CreateFromCenterAndHalfExtents"/>.
        /// </remarks>
        /// <param name="center">Center of AABB.</param>
        /// <param name="extents">Full extents of AABB.</param>
        /// <returns>AABB created from inputs.</returns>
        static MinMaxAABB CreateFromCenterAndExtents(const float3& center, const float3& extents)
        {
            return CreateFromCenterAndHalfExtents(center, extents * 0.5f);
        }

        /// <summary>
        /// Creates the AABB from a center and half extents.
        /// </summary>
        /// <remarks>
        /// This function takes half extents. It is half the distance between <see cref="Min"/> and <see cref="Max"/>.
        /// If you have full extents, you can call <see cref="CreateFromCenterAndExtents"/>.
        /// </remarks>
        /// <param name="center">Center of AABB.</param>
        /// <param name="halfExtents">Half extents of AABB.</param>
        /// <returns>AABB created from inputs.</returns>
        static MinMaxAABB CreateFromCenterAndHalfExtents(const float3& center, const float3& halfExtents)
        {
            return MinMaxAABB(center - halfExtents, center + halfExtents);
        }

        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>
        /// Computes the extents of the AABB.
        /// </summary>
        /// <remarks>
        /// Extents is the componentwise distance between min and max.
        /// </remarks>
        float3 Extents()        const   { return Max - Min; }

        /// <summary>
        /// Computes the half extents of the AABB.
        /// </summary>
        /// <remarks>
        /// HalfExtents is half of the componentwise distance between min and max. Subtracting HalfExtents from Center
        /// gives Min and adding HalfExtents to Center gives Max.
        /// </remarks>
        float3 HalfExtents()    const   { return (Max - Min) * 0.5f; }

        /// <summary>
        /// Computes the center of the AABB.
        /// </summary>
        float3 Center()         const   { return  (Max + Min) * 0.5f; }

        /// <summary>
        /// Check if the AABB is valid.
        /// </summary>
        /// <remarks>
        /// An AABB is considered valid if <see cref="Min"/> is componentwise less than or equal to <see cref="Max"/>.
        /// </remarks>
        /// <returns>True if <see cref="Min"/> is componentwise less than or equal to <see cref="Max"/>.</returns>
        bool IsValid()          const   { return math::all(Min <= Max); }

        /// <summary>
        /// Computes the surface area for this axis aligned bounding box.
        /// </summary>
        float SurfaceArea()     const
        {
            float3 diff = Max - Min;
            return 2 * math::dot(diff, diff.yzx());
        }

        /// <summary>
        /// Tests if the input point is contained by the AABB.
        /// </summary>
        /// <param name="point">Point to test.</param>
        /// <returns>True if AABB contains the input point.</returns>
        bool Contains(const float3& point)      const { return math::all(point >= Min & point <= Max); }

        /// <summary>
        /// Tests if the input AABB is contained entirely by this AABB.
        /// </summary>
        /// <param name="aabb">AABB to test.</param>
        /// <returns>True if input AABB is contained entirely by this AABB.</returns>
        bool Contains(const MinMaxAABB& aabb)   const { return math::all((Min <= aabb.Min) & (Max >= aabb.Max)); }

        /// <summary>
        /// Tests if the input AABB overlaps this AABB.
        /// </summary>
        /// <param name="aabb">AABB to test.</param>
        /// <returns>True if input AABB overlaps with this AABB.</returns>
        bool Overlaps(const MinMaxAABB& aabb)   const
        {
            return math::all(Max >= aabb.Min & Min <= aabb.Max);
        }

        /// <summary>
        /// Expands the AABB by the given signed distance.
        /// </summary>
        /// <remarks>
        /// Positive distance expands the AABB while negative distance shrinks the AABB.
        /// </remarks>
        /// <param name="signedDistance">Signed distance to expand the AABB with.</param>
        void Expand(float signedDistance)
        {
            Min -= signedDistance;
            Max += signedDistance;
        }

        /// <summary>
        /// Encapsulates the given AABB.
        /// </summary>
        /// <remarks>
        /// Modifies this AABB so that it contains the given AABB. If the given AABB is already contained by this AABB,
        /// then this AABB doesn't change.
        /// </remarks>
        /// <seealso cref="Contains(Unity.Mathematics.Geometry.MinMaxAABB)"/>
        /// <param name="aabb">AABB to encapsulate.</param>
        void Encapsulate(const MinMaxAABB& aabb)
        {
            Min = math::min(Min, aabb.Min);
            Max = math::max(Max, aabb.Max);
        }

        /// <summary>
        /// Encapsulate the given point.
        /// </summary>
        /// <remarks>
        /// Modifies this AABB so that it contains the given point. If the given point is already contained by this AABB,
        /// then this AABB doesn't change.
        /// </remarks>
        /// <seealso cref="Contains(Unity.Mathematics.float3)"/>
        /// <param name="point">Point to encapsulate.</param>
        void Encapsulate(const float3& point)
        {
            Min = math::min(Min, point);
            Max = math::max(Max, point);
        }

        bool Equals(const MinMaxAABB& other)
        {
            return Min.Equals(other.Min) && Max.Equals(other.Max);
        }

        std::string ToString()
        {
            return std::format("MinMaxAABB({0}, {1})", Min.ToString(), Max.ToString());
        }
	};

    namespace math
    {
        //=========================================================
        // math-MinMaxAABB
        //=========================================================
        /// <summary>
        /// Transforms the AABB with the given transform.
        /// </summary>
        /// <remarks>
        /// The resulting AABB encapsulates the transformed AABB which may not be axis aligned after the transformation.
        /// </remarks>
        /// <param name="transform">Transform to apply to AABB.</param>
        /// <param name="aabb">AABB to be transformed.</param>
        /// <returns>Transformed AABB.</returns>
        inline MinMaxAABB Transform(const RigidTransform& transform, const MinMaxAABB& aabb)
        {
            float3 halfExtentsInA = aabb.HalfExtents();

            // Rotate each axis individually and find their positions in the rotated space.
            float3 x = math::rotate(transform.rot, float3(halfExtentsInA.x, 0, 0));
            float3 y = math::rotate(transform.rot, float3(0, halfExtentsInA.y, 0));
            float3 z = math::rotate(transform.rot, float3(0, 0, halfExtentsInA.z));

            // Find the max corner by summing the rotated axes.  Absolute value of each axis
            // since we are trying to find the max corner.
            float3 halfExtentsInB = math::abs(x) + math::abs(y) + math::abs(z);
            float3 centerInB = math::transform(transform, aabb.Center());

            return MinMaxAABB(centerInB - halfExtentsInB, centerInB + halfExtentsInB);
        }

        /// <summary>
        /// Transforms the AABB with the given transform.
        /// </summary>
        /// <remarks>
        /// The resulting AABB encapsulates the transformed AABB which may not be axis aligned after the transformation.
        /// </remarks>
        /// <param name="transform">Transform to apply to AABB.</param>
        /// <param name="aabb">AABB to be transformed.</param>
        /// <returns>Transformed AABB.</returns>
        inline MinMaxAABB Transform(const float3x3& transform, const MinMaxAABB& aabb)
        {
            // From Christer Ericson's Real-Time Collision Detection on page 86 and 87.
            // We want the transformed minimum and maximums of the AABB. Multiplying a 3x3 matrix on the left of a
            // column vector looks like so:
            //
            // [ c0.x c1.x c2.x ] [ x ]   [ c0.x * x + c1.x * y + c2.x * z ]
            // [ c0.y c1.y c2.y ] [ y ] = [ c0.y * x + c1.y * y + c2.y * z ]
            // [ c0.z c1.z c2.z ] [ z ]   [ c0.z * x + c1.z * y + c2.z * z ]
            //
            // The column vectors we will use are the input AABB's min and max. Simply multiplying those two vectors
            // with the transformation matrix won't guarantee we get the min and max since those are only two
            // points out of eight in the AABB and one of the other six may set the min or max.
            //
            // To ensure we get the correct min and max, we must transform all eight points. But it's not necessary
            // to actually perform eight matrix multiplies to get our final result. Instead, we can build the min and
            // max incrementally by computing each term in the above matrix multiply separately then summing the min
            // (or max). For instance, to find the minimum contributed by the original min and max x component, we
            // compute this:
            //
            // newMin.x = min(c0.x * Min.x, c0.x * Max.x);
            // newMin.y = min(c0.y * Min.x, c0.y * Max.x);
            // newMin.z = min(c0.z * Min.x, c0.z * Max.x);
            //
            // Then we add minimum contributed by the original min and max y components:
            //
            // newMin.x += min(c1.x * Min.y, c1.x * Max.y);
            // newMin.y += min(c1.y * Min.y, c1.y * Max.y);
            // newMin.z += min(c1.z * Min.y, c1.z * Max.y);
            //
            // And so on. Translation can be handled by simply initializing the min and max with the translation
            // amount since it does not affect the min and max bounds in local space.
            auto t1 = transform.c0.xyz() * aabb.Min.xxx();
            auto t2 = transform.c0.xyz() * aabb.Max.xxx();
            auto minMask = t1 < t2;
            auto transformed = MinMaxAABB(math::select(t2, t1, minMask), math::select(t2, t1, !minMask));
            t1 = transform.c1.xyz() * aabb.Min.yyy();
            t2 = transform.c1.xyz() * aabb.Max.yyy();
            minMask = t1 < t2;
            transformed.Min += math::select(t2, t1, minMask);
            transformed.Max += math::select(t2, t1, !minMask);
            t1 = transform.c2.xyz() * aabb.Min.zzz();
            t2 = transform.c2.xyz() * aabb.Max.zzz();
            minMask = t1 < t2;
            transformed.Min += math::select(t2, t1, minMask);
            transformed.Max += math::select(t2, t1, !minMask);
            return transformed;
        }

        /// <summary>
        /// Transforms the AABB with the given transform.
        /// </summary>
        /// <remarks>
        /// The resulting AABB encapsulates the transformed AABB which may not be axis aligned after the transformation.
        /// </remarks>
        /// <param name="transform">Transform to apply to AABB.</param>
        /// <param name="aabb">AABB to be transformed.</param>
        /// <returns>Transformed AABB.</returns>
        inline MinMaxAABB Transform(const float4x4& transform, const MinMaxAABB& aabb)
        {
            auto transformed = math::Transform(float3x3(transform), aabb);
            transformed.Min += transform.c3.xyz();
            transformed.Max += transform.c3.xyz();
            return transformed;
        }
    }

} // namespace ecs