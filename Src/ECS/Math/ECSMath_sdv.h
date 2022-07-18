#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/svd.cs

    // SVD algorithm as described in:
    // Computing the singular value decomposition of 3x3 matrices with minimal branching and elementary floating point operations,
    // A.McAdams, A.Selle, R.Tamstorf, J.Teran and E.Sifakis, University of Wisconsin - Madison technical report TR1690, May 2011
    struct svd
    {
        static const float k_EpsilonDeterminant;
        static const float k_EpsilonRCP;
        static const float k_EpsilonNormalSqrt;
        static const float k_EpsilonNormal;

        static void condSwap(bool c, OUT float& x, OUT float& y);

        static void condNegSwap(bool c, OUT float3& x, OUT float3& y);

        static quaternion condNegSwapQuat(bool c, const quaternion& q, const float4& mask);

        static void sortSingularValues(OUT float3x3& b, OUT quaternion& v);

        static quaternion approxGivensQuat(const float3& pq, const float4& mask);

        static quaternion qrGivensQuat(const float2& pq, const float4& mask);

        static quaternion givensQRFactorization(const float3x3& b, OUT float3x3& r);

        static quaternion jacobiIteration(OUT float3x3& s, int iterations = 5);

        static float3 singularValuesDecomposition(const float3x3& a, OUT quaternion& u, OUT quaternion& v);

        static float3 rcpsafe(const float3& x, float epsilon = k_EpsilonRCP);


        //=========================================================
        // INTERNAL
        //=========================================================
        static float3x3     svdInverse(const float3x3& a);
        static quaternion   svdRotation(const float3x3& a);
    };
    __declspec(selectany) const float		svd::k_EpsilonDeterminant = 1e-6f;
    __declspec(selectany) const float		svd::k_EpsilonRCP = 1e-9f;
    __declspec(selectany) const float		svd::k_EpsilonNormalSqrt = 1e-15f;
    __declspec(selectany) const float		svd::k_EpsilonNormal = 1e-30f;
} // namespace ecs
