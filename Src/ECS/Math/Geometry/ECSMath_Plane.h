#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/Geometry/Plane.cs
	struct Plane
	{
	public:
		/// <summary>
        /// A plane in the form Ax + By + Cz + Dw = 0.
        /// </summary>
        /// <remarks>
        /// Stores the plane coefficients A, B, C, D where (A, B, C) is a unit normal vector and D is the distance
        /// from the origin.  A plane stored with a unit normal vector is called a normalized plane.
        /// </remarks>
        float4 NormalAndDistance;


    public:
        //=========================================================
        // CONSTRUCTOR
        //=========================================================
        Plane() : NormalAndDistance(float4::zero)    {}

        Plane(const float4& v) : NormalAndDistance(v) {}

        /// <summary>
        /// Constructs a Plane from arbitrary coefficients A, B, C, D of the plane equation Ax + By + Cz + Dw = 0.
        /// </summary>
        /// <remarks>
        /// The constructed plane will be the normalized form of the plane specified by the given coefficients.
        /// </remarks>
        /// <param name="coefficientA">Coefficient A from plane equation.</param>
        /// <param name="coefficientB">Coefficient B from plane equation.</param>
        /// <param name="coefficientC">Coefficient C from plane equation.</param>
        /// <param name="coefficientD">Coefficient D from plane equation.</param>
        Plane(float coefficientA, float coefficientB, float coefficientC, float coefficientD)
        {
            NormalAndDistance = Normalize(float4(coefficientA, coefficientB, coefficientC, coefficientD));
        }

        /// <summary>
        /// Constructs a plane with a normal vector and distance from the origin.
        /// </summary>
        /// <remarks>
        /// The constructed plane will be the normalized form of the plane specified by the inputs.
        /// </remarks>
        /// <param name="normal">A non-zero vector that is perpendicular to the plane.  It may be any length.</param>
        /// <param name="distance">Distance from the origin along the normal.  A negative value moves the plane in the
        /// same direction as the normal while a positive value moves it in the opposite direction.</param>
        Plane(const float3& normal, float distance)
        {
            NormalAndDistance = Normalize(float4(normal, distance));
        }

        /// <summary>
        /// Constructs a plane with a normal vector and a point that lies in the plane.
        /// </summary>
        /// <remarks>
        /// The constructed plane will be the normalized form of the plane specified by the inputs.
        /// </remarks>
        /// <param name="normal">A non-zero vector that is perpendicular to the plane.  It may be any length.</param>
        /// <param name="pointInPlane">A point that lies in the plane.</param>
        Plane(const float3& normal, const float3& pointInPlane)
            : NormalAndDistance(normal, -math::dot(normal, pointInPlane))
        {
        }

        /// <summary>
        /// Constructs a plane with two vectors and a point that all lie in the plane.
        /// </summary>
        /// <remarks>
        /// The constructed plane will be the normalized form of the plane specified by the inputs.
        /// </remarks>
        /// <param name="vector1InPlane">A non-zero vector that lies in the plane.  It may be any length.</param>
        /// <param name="vector2InPlane">A non-zero vector that lies in the plane.  It may be any length and must not be a scalar multiple of <paramref name="vector1InPlane"/>.</param>
        /// <param name="pointInPlane">A point that lies in the plane.</param>
        Plane(const float3& vector1InPlane, const float3& vector2InPlane, const float3& pointInPlane)
            : Plane(math::cross(vector1InPlane, vector2InPlane), pointInPlane)
        {
        }
        //=========================================================
		// OPERATORS
		//=========================================================
		//=========================================================
		// Assignment operators : T&
		//=========================================================
		// simple assignment	            a = b	
        Plane& operator = (const Plane& rhs) { this->NormalAndDistance = rhs.NormalAndDistance; return (*this); }
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
        /// <summary>
        /// Implicitly converts a <see cref="Plane"/> to <see cref="float4"/>.
        /// </summary>
        /// <param name="plane">Plane to convert.</param>
        /// <returns>A <see cref="float4"/> representing the plane.</returns>
        operator float4() { return NormalAndDistance; }

        //=========================================================
        // Static METHOD
        //=========================================================
        /// <summary>
        /// Creates a normalized Plane directly without normalization cost.
        /// </summary>
        /// <remarks>
        /// If you have a unit length normal vector, you can create a Plane faster than using one of its constructors
        /// by calling this function.
        /// </remarks>
        /// <param name="unitNormal">A non-zero vector that is perpendicular to the plane.  It must be unit length.</param>
        /// <param name="distance">Distance from the origin along the normal.  A negative value moves the plane in the
        /// same direction as the normal while a positive value moves it in the opposite direction.</param>
        /// <returns>Normalized Plane constructed from given inputs.</returns>
        static Plane CreateFromUnitNormalAndDistance(const float3& unitNormal, float distance)
        {
            return Plane(float4(unitNormal, distance));
        }

        /// <summary>
        /// Creates a normalized Plane without normalization cost.
        /// </summary>
        /// <remarks>
        /// If you have a unit length normal vector, you can create a Plane faster than using one of its constructors
        /// by calling this function.
        /// </remarks>
        /// <param name="unitNormal">A non-zero vector that is perpendicular to the plane.  It must be unit length.</param>
        /// <param name="pointInPlane">A point that lies in the plane.</param>
        /// <returns>Normalized Plane constructed from given inputs.</returns>
        static Plane CreateFromUnitNormalAndPointInPlane(const float3& unitNormal, const float3& pointInPlane)
        {
            return Plane(float4(unitNormal, -math::dot(unitNormal, pointInPlane)));
        }

        //=========================================================
        // METHOD
        //=========================================================
        /// <summary>
        /// Get/set the normal vector of the plane.
        /// </summary>
        /// <remarks>
        /// It is assumed that the normal is unit length.  If you set a plane such that Ax + By + Cz + Dw = 0 but
        /// (A, B, C) is not unit length, then you must normalize the plane by calling <see cref="Normalize(Plane)"/>.
        /// </remarks>
        float3 Normal()                 { return NormalAndDistance.xyz();   }
        void   Normal(const float3& v)  { NormalAndDistance.xyz(v);         }

        /// <summary>
        /// Get/set the distance of the plane from the origin.  May be a negative value.
        /// </summary>
        /// <remarks>
        /// It is assumed that the normal is unit length.  If you set a plane such that Ax + By + Cz + Dw = 0 but
        /// (A, B, C) is not unit length, then you must normalize the plane by calling <see cref="Normalize(Plane)"/>.
        /// </remarks>
        float Distance()                { return NormalAndDistance.w;   }
        void  Distance(float v)         { NormalAndDistance.w = v;      }

        /// <summary>
        /// Normalizes the plane represented by the given plane coefficients.
        /// </summary>
        /// <remarks>
        /// The plane coefficients are A, B, C, D and stored in that order in the <see cref="float4"/>.
        /// </remarks>
        /// <param name="planeCoefficients">Plane coefficients A, B, C, D stored in x, y, z, w (respectively).</param>
        /// <returns>Normalized plane coefficients.</returns>
        static float4 Normalize(const float4& planeCoefficients)
        {
            float recipLength = math::rsqrt(math::lengthsq(planeCoefficients.xyz()));
            return Plane(planeCoefficients * recipLength);
        }
        /// <summary>
        /// Normalizes the given Plane.
        /// </summary>
        /// <param name="plane">Plane to normalize.</param>
        /// <returns>Normalized Plane.</returns>
        static Plane Normalize(const Plane& plane)
        {
            return Plane(Normalize(plane.NormalAndDistance));
        }

        /// <summary>
        /// Get the signed distance from the point to the plane.
        /// </summary>
        /// <remarks>
        /// Plane must be normalized prior to calling this function.  Distance is positive if point is on side of the
        /// plane the normal points to, negative if on the opposite side and zero if the point lies in the plane.
        /// Avoid comparing equality with 0.0f when testing if a point lies exactly in the plane and use an approximate
        /// comparison instead.
        /// </remarks>
        /// <param name="point">Point to find the signed distance with.</param>
        /// <returns>Signed distance of the point from the plane.</returns>
        float SignedDistanceToPoint(const float3& point)
        {
            CheckPlaneIsNormalized();
            return math::dot(NormalAndDistance, float4(point, 1.0f));
        }

        /// <summary>
        /// Projects the given point onto the plane.
        /// </summary>
        /// <remarks>
        /// Plane must be normalized prior to calling this function.  The result is the position closest to the point
        /// that still lies in the plane.
        /// </remarks>
        /// <param name="point">Point to project onto the plane.</param>
        /// <returns>Projected point that's inside the plane.</returns>
        float3 Projection(const float3& point)
        {
            CheckPlaneIsNormalized();
            return point - Normal() * SignedDistanceToPoint(point);
        }

        /// <summary>
        /// Flips the plane so the normal points in the opposite direction.
        /// </summary>
        Plane Flipped()     { return Plane(-NormalAndDistance); };

        void CheckPlaneIsNormalized()
        {
            float ll = math::lengthsq(Normal().xyz());
            const float lowerBound = 0.999f * 0.999f;
            const float upperBound = 1.001f * 1.001f;

            if (ll < lowerBound || ll > upperBound)
            {
                throw std::exception("Plane must be normalized. Call Plane.Normalize() to normalize plane.");
            }
        }
	};

} // namespace ecs
