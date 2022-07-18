#pragma once


//=============================================================================
// ECS MATH ALGORITHM
//=============================================================================
namespace ecs 
{
namespace math
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/matrix.gen.cs
    /// <summary>Returns the float value result of a matrix multiplication between a float value and a float value.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float mul(float a, float b)
    {
        return a * b;
    }

    /// <summary>Returns the float value result of a matrix multiplication between a float2 row vector and a float2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float mul(const float2& a, const float2& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    /// <summary>Returns the float2 row vector result of a matrix multiplication between a float2 row vector and a float2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2 mul(const float2& a, const float2x2& b)
    {
        return float2(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y);
    }

    /// <summary>Returns the float3 row vector result of a matrix multiplication between a float2 row vector and a float2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3 mul(const float2& a, const float2x3& b)
    {
        return float3(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y,
            a.x * b.c2.x + a.y * b.c2.y);
    }

    /// <summary>Returns the float4 row vector result of a matrix multiplication between a float2 row vector and a float2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4 mul(const float2& a, const float2x4& b)
    {
        return float4(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y,
            a.x * b.c2.x + a.y * b.c2.y,
            a.x * b.c3.x + a.y * b.c3.y);
    }

    /// <summary>Returns the float value result of a matrix multiplication between a float3 row vector and a float3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float mul(const float3& a, const float3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    /// <summary>Returns the float2 row vector result of a matrix multiplication between a float3 row vector and a float3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2 mul(const float3& a, const float3x2& b)
    {
        return float2(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z);
    }

    /// <summary>Returns the float3 row vector result of a matrix multiplication between a float3 row vector and a float3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3 mul(const float3& a, const float3x3& b)
    {
        return float3(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z);
    }

    /// <summary>Returns the float4 row vector result of a matrix multiplication between a float3 row vector and a float3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4 mul(const float3& a, const float3x4& b)
    {
        return float4(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z,
            a.x * b.c3.x + a.y * b.c3.y + a.z * b.c3.z);
    }

    /// <summary>Returns the float value result of a matrix multiplication between a float4 row vector and a float4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float mul(const float4& a, const float4& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    /// <summary>Returns the float2 row vector result of a matrix multiplication between a float4 row vector and a float4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2 mul(const float4& a, const float4x2& b)
    {
        return float2(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w);
    }

    /// <summary>Returns the float3 row vector result of a matrix multiplication between a float4 row vector and a float4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3 mul(const float4& a, const float4x3& b)
    {
        return float3(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z + a.w * b.c2.w);
    }

    /// <summary>Returns the float4 row vector result of a matrix multiplication between a float4 row vector and a float4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4 mul(const float4& a, const float4x4& b)
    {
        return float4(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z + a.w * b.c2.w,
            a.x * b.c3.x + a.y * b.c3.y + a.z * b.c3.z + a.w * b.c3.w);
    }

    /// <summary>Returns the float2 column vector result of a matrix multiplication between a float2x2 matrix and a float2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2 mul(const float2x2& a, const float2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the float2x2 matrix result of a matrix multiplication between a float2x2 matrix and a float2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x2 mul(const float2x2& a, const float2x2& b)
    {
        return float2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the float2x3 matrix result of a matrix multiplication between a float2x2 matrix and a float2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x3 mul(const float2x2& a, const float2x3& b)
    {
        return float2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the float2x4 matrix result of a matrix multiplication between a float2x2 matrix and a float2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x4 mul(const float2x2& a, const float2x4& b)
    {
        return float2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the float2 column vector result of a matrix multiplication between a float2x3 matrix and a float3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2 mul(const float2x3& a, const float3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the float2x2 matrix result of a matrix multiplication between a float2x3 matrix and a float3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x2 mul(const float2x3& a, const float3x2& b)
    {
        return float2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the float2x3 matrix result of a matrix multiplication between a float2x3 matrix and a float3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x3 mul(const float2x3& a, const float3x3& b)
    {
        return float2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the float2x4 matrix result of a matrix multiplication between a float2x3 matrix and a float3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x4 mul(const float2x3& a, const float3x4& b)
    {
        return float2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the float2 column vector result of a matrix multiplication between a float2x4 matrix and a float4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2 mul(const float2x4& a, const float4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the float2x2 matrix result of a matrix multiplication between a float2x4 matrix and a float4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x2 mul(const float2x4& a, const float4x2& b)
    {
        return float2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the float2x3 matrix result of a matrix multiplication between a float2x4 matrix and a float4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x3 mul(const float2x4& a, const float4x3& b)
    {
        return float2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the float2x4 matrix result of a matrix multiplication between a float2x4 matrix and a float4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float2x4 mul(const float2x4& a, const float4x4& b)
    {
        return float2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the float3 column vector result of a matrix multiplication between a float3x2 matrix and a float2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3 mul(const float3x2& a, const float2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the float3x2 matrix result of a matrix multiplication between a float3x2 matrix and a float2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x2 mul(const float3x2& a, const float2x2& b)
    {
        return float3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the float3x3 matrix result of a matrix multiplication between a float3x2 matrix and a float2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x3 mul(const float3x2& a, const float2x3& b)
    {
        return float3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the float3x4 matrix result of a matrix multiplication between a float3x2 matrix and a float2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x4 mul(const float3x2& a, const float2x4& b)
    {
        return float3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the float3 column vector result of a matrix multiplication between a float3x3 matrix and a float3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3 mul(const float3x3& a, const float3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the float3x2 matrix result of a matrix multiplication between a float3x3 matrix and a float3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x2 mul(const float3x3& a, const float3x2& b)
    {
        return float3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the float3x3 matrix result of a matrix multiplication between a float3x3 matrix and a float3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x3 mul(const float3x3& a, const float3x3& b)
    {
        return float3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the float3x4 matrix result of a matrix multiplication between a float3x3 matrix and a float3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x4 mul(const float3x3& a, const float3x4& b)
    {
        return float3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the float3 column vector result of a matrix multiplication between a float3x4 matrix and a float4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3 mul(const float3x4& a, const float4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the float3x2 matrix result of a matrix multiplication between a float3x4 matrix and a float4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x2 mul(const float3x4& a, const float4x2& b)
    {
        return float3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the float3x3 matrix result of a matrix multiplication between a float3x4 matrix and a float4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x3 mul(const float3x4& a, const float4x3& b)
    {
        return float3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the float3x4 matrix result of a matrix multiplication between a float3x4 matrix and a float4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float3x4 mul(const float3x4& a, const float4x4& b)
    {
        return float3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the float4 column vector result of a matrix multiplication between a float4x2 matrix and a float2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4 mul(const float4x2& a, const float2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the float4x2 matrix result of a matrix multiplication between a float4x2 matrix and a float2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x2 mul(const float4x2& a, const float2x2& b)
    {
        return float4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the float4x3 matrix result of a matrix multiplication between a float4x2 matrix and a float2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x3 mul(const float4x2& a, const float2x3& b)
    {
        return float4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the float4x4 matrix result of a matrix multiplication between a float4x2 matrix and a float2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x4 mul(const float4x2& a, const float2x4& b)
    {
        return float4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the float4 column vector result of a matrix multiplication between a float4x3 matrix and a float3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4 mul(const float4x3& a, const float3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the float4x2 matrix result of a matrix multiplication between a float4x3 matrix and a float3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x2 mul(const float4x3& a, const float3x2& b)
    {
        return float4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the float4x3 matrix result of a matrix multiplication between a float4x3 matrix and a float3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x3 mul(const float4x3& a, const float3x3& b)
    {
        return float4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the float4x4 matrix result of a matrix multiplication between a float4x3 matrix and a float3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x4 mul(const float4x3& a, const float3x4& b)
    {
        return float4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the float4 column vector result of a matrix multiplication between a float4x4 matrix and a float4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4 mul(const float4x4& a, const float4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the float4x2 matrix result of a matrix multiplication between a float4x4 matrix and a float4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x2 mul(const float4x4& a, const float4x2& b)
    {
        return float4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the float4x3 matrix result of a matrix multiplication between a float4x4 matrix and a float4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x3 mul(const float4x4& a, const float4x3& b)
    {
        return float4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the float4x4 matrix result of a matrix multiplication between a float4x4 matrix and a float4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline float4x4 mul(const float4x4& a, const float4x4& b)
    {
        return float4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the double value result of a matrix multiplication between a double value and a double value.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double mul(double a, double b)
    {
        return a * b;
    }

    /// <summary>Returns the double value result of a matrix multiplication between a double2 row vector and a double2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double mul(const double2& a, const double2& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    /// <summary>Returns the double2 row vector result of a matrix multiplication between a double2 row vector and a double2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2 mul(const double2& a, const double2x2& b)
    {
        return double2(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y);
    }

    /// <summary>Returns the double3 row vector result of a matrix multiplication between a double2 row vector and a double2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3 mul(const double2& a, const double2x3& b)
    {
        return double3(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y,
            a.x * b.c2.x + a.y * b.c2.y);
    }

    /// <summary>Returns the double4 row vector result of a matrix multiplication between a double2 row vector and a double2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4 mul(const double2& a, const double2x4& b)
    {
        return double4(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y,
            a.x * b.c2.x + a.y * b.c2.y,
            a.x * b.c3.x + a.y * b.c3.y);
    }

    /// <summary>Returns the double value result of a matrix multiplication between a double3 row vector and a double3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double mul(const double3& a, const double3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    /// <summary>Returns the double2 row vector result of a matrix multiplication between a double3 row vector and a double3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>

    inline double2 mul(const double3& a, const double3x2& b)
    {
        return double2(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z);
    }

    /// <summary>Returns the double3 row vector result of a matrix multiplication between a double3 row vector and a double3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3 mul(const double3& a, const double3x3& b)
    {
        return double3(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z);
    }

    /// <summary>Returns the double4 row vector result of a matrix multiplication between a double3 row vector and a double3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4 mul(const double3& a, const double3x4& b)
    {
        return double4(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z,
            a.x * b.c3.x + a.y * b.c3.y + a.z * b.c3.z);
    }

    /// <summary>Returns the double value result of a matrix multiplication between a double4 row vector and a double4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double mul(const double4& a, const double4& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    /// <summary>Returns the double2 row vector result of a matrix multiplication between a double4 row vector and a double4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2 mul(const double4& a, const double4x2& b)
    {
        return double2(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w);
    }

    /// <summary>Returns the double3 row vector result of a matrix multiplication between a double4 row vector and a double4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3 mul(const double4& a, const double4x3& b)
    {
        return double3(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z + a.w * b.c2.w);
    }

    /// <summary>Returns the double4 row vector result of a matrix multiplication between a double4 row vector and a double4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4 mul(const double4& a, const double4x4& b)
    {
        return double4(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z + a.w * b.c2.w,
            a.x * b.c3.x + a.y * b.c3.y + a.z * b.c3.z + a.w * b.c3.w);
    }

    /// <summary>Returns the double2 column vector result of a matrix multiplication between a double2x2 matrix and a double2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2 mul(const double2x2& a, const double2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the double2x2 matrix result of a matrix multiplication between a double2x2 matrix and a double2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x2 mul(const double2x2& a, const double2x2& b)
    {
        return double2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the double2x3 matrix result of a matrix multiplication between a double2x2 matrix and a double2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x3 mul(const double2x2& a, const double2x3& b)
    {
        return double2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the double2x4 matrix result of a matrix multiplication between a double2x2 matrix and a double2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x4 mul(const double2x2& a, const double2x4& b)
    {
        return double2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the double2 column vector result of a matrix multiplication between a double2x3 matrix and a double3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2 mul(const double2x3& a, const double3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the double2x2 matrix result of a matrix multiplication between a double2x3 matrix and a double3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x2 mul(const double2x3& a, const double3x2& b)
    {
        return double2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the double2x3 matrix result of a matrix multiplication between a double2x3 matrix and a double3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x3 mul(const double2x3& a, const double3x3& b)
    {
        return double2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the double2x4 matrix result of a matrix multiplication between a double2x3 matrix and a double3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x4 mul(const double2x3& a, const double3x4& b)
    {
        return double2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the double2 column vector result of a matrix multiplication between a double2x4 matrix and a double4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2 mul(const double2x4& a, const double4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the double2x2 matrix result of a matrix multiplication between a double2x4 matrix and a double4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x2 mul(const double2x4& a, const double4x2& b)
    {
        return double2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the double2x3 matrix result of a matrix multiplication between a double2x4 matrix and a double4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x3 mul(const double2x4& a, const double4x3& b)
    {
        return double2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the double2x4 matrix result of a matrix multiplication between a double2x4 matrix and a double4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double2x4 mul(const double2x4& a, const double4x4& b)
    {
        return double2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the double3 column vector result of a matrix multiplication between a double3x2 matrix and a double2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3 mul(const double3x2& a, const double2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the double3x2 matrix result of a matrix multiplication between a double3x2 matrix and a double2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x2 mul(const double3x2& a, const double2x2& b)
    {
        return double3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the double3x3 matrix result of a matrix multiplication between a double3x2 matrix and a double2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x3 mul(const double3x2& a, const double2x3& b)
    {
        return double3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the double3x4 matrix result of a matrix multiplication between a double3x2 matrix and a double2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x4 mul(const double3x2& a, const double2x4& b)
    {
        return double3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the double3 column vector result of a matrix multiplication between a double3x3 matrix and a double3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3 mul(const double3x3& a, const double3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the double3x2 matrix result of a matrix multiplication between a double3x3 matrix and a double3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x2 mul(const double3x3& a, const double3x2& b)
    {
        return double3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the double3x3 matrix result of a matrix multiplication between a double3x3 matrix and a double3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x3 mul(const double3x3& a, const double3x3& b)
    {
        return double3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the double3x4 matrix result of a matrix multiplication between a double3x3 matrix and a double3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x4 mul(const double3x3& a, const double3x4& b)
    {
        return double3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the double3 column vector result of a matrix multiplication between a double3x4 matrix and a double4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3 mul(const double3x4& a, const double4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the double3x2 matrix result of a matrix multiplication between a double3x4 matrix and a double4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x2 mul(const double3x4& a, const double4x2& b)
    {
        return double3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the double3x3 matrix result of a matrix multiplication between a double3x4 matrix and a double4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x3 mul(const double3x4& a, const double4x3& b)
    {
        return double3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the double3x4 matrix result of a matrix multiplication between a double3x4 matrix and a double4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double3x4 mul(const double3x4& a, const double4x4& b)
    {
        return double3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the double4 column vector result of a matrix multiplication between a double4x2 matrix and a double2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4 mul(const double4x2& a, const double2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the double4x2 matrix result of a matrix multiplication between a double4x2 matrix and a double2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x2 mul(const double4x2& a, const double2x2& b)
    {
        return double4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the double4x3 matrix result of a matrix multiplication between a double4x2 matrix and a double2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x3 mul(const double4x2& a, const double2x3& b)
    {
        return double4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the double4x4 matrix result of a matrix multiplication between a double4x2 matrix and a double2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x4 mul(const double4x2& a, const double2x4& b)
    {
        return double4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the double4 column vector result of a matrix multiplication between a double4x3 matrix and a double3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4 mul(const double4x3& a, const double3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the double4x2 matrix result of a matrix multiplication between a double4x3 matrix and a double3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x2 mul(const double4x3& a, const double3x2& b)
    {
        return double4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the double4x3 matrix result of a matrix multiplication between a double4x3 matrix and a double3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x3 mul(const double4x3& a, const double3x3& b)
    {
        return double4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the double4x4 matrix result of a matrix multiplication between a double4x3 matrix and a double3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x4 mul(const double4x3& a, const double3x4& b)
    {
        return double4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the double4 column vector result of a matrix multiplication between a double4x4 matrix and a double4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4 mul(const double4x4& a, const double4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the double4x2 matrix result of a matrix multiplication between a double4x4 matrix and a double4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x2 mul(const double4x4& a, const double4x2& b)
    {
        return double4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the double4x3 matrix result of a matrix multiplication between a double4x4 matrix and a double4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x3 mul(const double4x4& a, const double4x3& b)
    {
        return double4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the double4x4 matrix result of a matrix multiplication between a double4x4 matrix and a double4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline double4x4 mul(const double4x4& a, const double4x4& b)
    {
        return double4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the int value result of a matrix multiplication between an int value and an int value.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int mul(int a, int b)
    {
        return a * b;
    }

    /// <summary>Returns the int value result of a matrix multiplication between an int2 row vector and an int2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int mul(const int2& a, const int2& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    /// <summary>Returns the int2 row vector result of a matrix multiplication between an int2 row vector and an int2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2 mul(const int2& a, const int2x2& b)
    {
        return int2(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y);
    }

    /// <summary>Returns the int3 row vector result of a matrix multiplication between an int2 row vector and an int2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3 mul(const int2& a, const int2x3& b)
    {
        return int3(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y,
            a.x * b.c2.x + a.y * b.c2.y);
    }

    /// <summary>Returns the int4 row vector result of a matrix multiplication between an int2 row vector and an int2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4 mul(const int2& a, const int2x4& b)
    {
        return int4(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y,
            a.x * b.c2.x + a.y * b.c2.y,
            a.x * b.c3.x + a.y * b.c3.y);
    }

    /// <summary>Returns the int value result of a matrix multiplication between an int3 row vector and an int3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int mul(const int3& a, const int3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    /// <summary>Returns the int2 row vector result of a matrix multiplication between an int3 row vector and an int3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2 mul(const int3& a, const int3x2& b)
    {
        return int2(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z);
    }

    /// <summary>Returns the int3 row vector result of a matrix multiplication between an int3 row vector and an int3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3 mul(const int3& a, const int3x3& b)
    {
        return int3(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z);
    }

    /// <summary>Returns the int4 row vector result of a matrix multiplication between an int3 row vector and an int3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4 mul(const int3& a, const int3x4& b)
    {
        return int4(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z,
            a.x * b.c3.x + a.y * b.c3.y + a.z * b.c3.z);
    }

    /// <summary>Returns the int value result of a matrix multiplication between an int4 row vector and an int4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int mul(const int4& a, const int4& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    /// <summary>Returns the int2 row vector result of a matrix multiplication between an int4 row vector and an int4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2 mul(const int4& a, const int4x2& b)
    {
        return int2(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w);
    }

    /// <summary>Returns the int3 row vector result of a matrix multiplication between an int4 row vector and an int4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3 mul(const int4& a, const int4x3& b)
    {
        return int3(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z + a.w * b.c2.w);
    }

    /// <summary>Returns the int4 row vector result of a matrix multiplication between an int4 row vector and an int4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4 mul(const int4& a, const int4x4& b)
    {
        return int4(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z + a.w * b.c2.w,
            a.x * b.c3.x + a.y * b.c3.y + a.z * b.c3.z + a.w * b.c3.w);
    }

    /// <summary>Returns the int2 column vector result of a matrix multiplication between an int2x2 matrix and an int2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2 mul(const int2x2& a, const int2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the int2x2 matrix result of a matrix multiplication between an int2x2 matrix and an int2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x2 mul(const int2x2& a, const int2x2& b)
    {
        return int2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the int2x3 matrix result of a matrix multiplication between an int2x2 matrix and an int2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x3 mul(const int2x2& a, const int2x3& b)
    {
        return int2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the int2x4 matrix result of a matrix multiplication between an int2x2 matrix and an int2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x4 mul(const int2x2& a, const int2x4& b)
    {
        return int2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the int2 column vector result of a matrix multiplication between an int2x3 matrix and an int3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2 mul(const int2x3& a, const int3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the int2x2 matrix result of a matrix multiplication between an int2x3 matrix and an int3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x2 mul(const int2x3& a, const int3x2& b)
    {
        return int2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the int2x3 matrix result of a matrix multiplication between an int2x3 matrix and an int3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x3 mul(const int2x3& a, const int3x3& b)
    {
        return int2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the int2x4 matrix result of a matrix multiplication between an int2x3 matrix and an int3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x4 mul(const int2x3& a, const int3x4& b)
    {
        return int2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the int2 column vector result of a matrix multiplication between an int2x4 matrix and an int4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2 mul(const int2x4& a, const int4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the int2x2 matrix result of a matrix multiplication between an int2x4 matrix and an int4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x2 mul(const int2x4& a, const int4x2& b)
    {
        return int2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the int2x3 matrix result of a matrix multiplication between an int2x4 matrix and an int4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x3 mul(const int2x4& a, const int4x3& b)
    {
        return int2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the int2x4 matrix result of a matrix multiplication between an int2x4 matrix and an int4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int2x4 mul(const int2x4& a, const int4x4& b)
    {
        return int2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the int3 column vector result of a matrix multiplication between an int3x2 matrix and an int2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3 mul(const int3x2& a, const int2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the int3x2 matrix result of a matrix multiplication between an int3x2 matrix and an int2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x2 mul(const int3x2& a, const int2x2& b)
    {
        return int3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the int3x3 matrix result of a matrix multiplication between an int3x2 matrix and an int2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x3 mul(const int3x2& a, const int2x3& b)
    {
        return int3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the int3x4 matrix result of a matrix multiplication between an int3x2 matrix and an int2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x4 mul(const int3x2& a, const int2x4& b)
    {
        return int3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the int3 column vector result of a matrix multiplication between an int3x3 matrix and an int3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3 mul(const int3x3& a, const int3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the int3x2 matrix result of a matrix multiplication between an int3x3 matrix and an int3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x2 mul(const int3x3& a, const int3x2& b)
    {
        return int3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the int3x3 matrix result of a matrix multiplication between an int3x3 matrix and an int3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x3 mul(const int3x3& a, const int3x3& b)
    {
        return int3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the int3x4 matrix result of a matrix multiplication between an int3x3 matrix and an int3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x4 mul(const int3x3& a, const int3x4& b)
    {
        return int3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the int3 column vector result of a matrix multiplication between an int3x4 matrix and an int4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3 mul(const int3x4& a, const int4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the int3x2 matrix result of a matrix multiplication between an int3x4 matrix and an int4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x2 mul(const int3x4& a, const int4x2& b)
    {
        return int3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the int3x3 matrix result of a matrix multiplication between an int3x4 matrix and an int4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x3 mul(const int3x4& a, const int4x3& b)
    {
        return int3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the int3x4 matrix result of a matrix multiplication between an int3x4 matrix and an int4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int3x4 mul(const int3x4& a, const int4x4& b)
    {
        return int3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the int4 column vector result of a matrix multiplication between an int4x2 matrix and an int2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4 mul(const int4x2& a, const int2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the int4x2 matrix result of a matrix multiplication between an int4x2 matrix and an int2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x2 mul(const int4x2& a, const int2x2& b)
    {
        return int4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the int4x3 matrix result of a matrix multiplication between an int4x2 matrix and an int2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x3 mul(const int4x2& a, const int2x3& b)
    {
        return int4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the int4x4 matrix result of a matrix multiplication between an int4x2 matrix and an int2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x4 mul(const int4x2& a, const int2x4& b)
    {
        return int4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the int4 column vector result of a matrix multiplication between an int4x3 matrix and an int3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4 mul(const int4x3& a, const int3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the int4x2 matrix result of a matrix multiplication between an int4x3 matrix and an int3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x2 mul(const int4x3& a, const int3x2& b)
    {
        return int4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the int4x3 matrix result of a matrix multiplication between an int4x3 matrix and an int3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x3 mul(const int4x3& a, const int3x3& b)
    {
        return int4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the int4x4 matrix result of a matrix multiplication between an int4x3 matrix and an int3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x4 mul(const int4x3& a, const int3x4& b)
    {
        return int4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the int4 column vector result of a matrix multiplication between an int4x4 matrix and an int4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4 mul(const int4x4& a, const int4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the int4x2 matrix result of a matrix multiplication between an int4x4 matrix and an int4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x2 mul(const int4x4& a, const int4x2& b)
    {
        return int4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the int4x3 matrix result of a matrix multiplication between an int4x4 matrix and an int4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x3 mul(const int4x4& a, const int4x3& b)
    {
        return int4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the int4x4 matrix result of a matrix multiplication between an int4x4 matrix and an int4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline int4x4 mul(const int4x4& a, const int4x4& b)
    {
        return int4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the uint value result of a matrix multiplication between a uint value and a uint value.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint mul(uint a, uint b)
    {
        return a * b;
    }

    /// <summary>Returns the uint value result of a matrix multiplication between a uint2 row vector and a uint2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint mul(const uint2& a, const uint2& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    /// <summary>Returns the uint2 row vector result of a matrix multiplication between a uint2 row vector and a uint2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2 mul(const uint2& a, const uint2x2& b)
    {
        return uint2(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y);
    }

    /// <summary>Returns the uint3 row vector result of a matrix multiplication between a uint2 row vector and a uint2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3 mul(const uint2& a, const uint2x3& b)
    {
        return uint3(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y,
            a.x * b.c2.x + a.y * b.c2.y);
    }

    /// <summary>Returns the uint4 row vector result of a matrix multiplication between a uint2 row vector and a uint2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4 mul(const uint2& a, const uint2x4& b)
    {
        return uint4(
            a.x * b.c0.x + a.y * b.c0.y,
            a.x * b.c1.x + a.y * b.c1.y,
            a.x * b.c2.x + a.y * b.c2.y,
            a.x * b.c3.x + a.y * b.c3.y);
    }

    /// <summary>Returns the uint value result of a matrix multiplication between a uint3 row vector and a uint3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint mul(const uint3& a, const uint3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    /// <summary>Returns the uint2 row vector result of a matrix multiplication between a uint3 row vector and a uint3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2 mul(const uint3& a, const uint3x2& b)
    {
        return uint2(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z);
    }

    /// <summary>Returns the uint3 row vector result of a matrix multiplication between a uint3 row vector and a uint3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3 mul(const uint3& a, const uint3x3& b)
    {
        return uint3(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z);
    }

    /// <summary>Returns the uint4 row vector result of a matrix multiplication between a uint3 row vector and a uint3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4 mul(const uint3& a, const uint3x4& b)
    {
        return uint4(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z,
            a.x * b.c3.x + a.y * b.c3.y + a.z * b.c3.z);
    }

    /// <summary>Returns the uint value result of a matrix multiplication between a uint4 row vector and a uint4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint mul(const uint4& a, const uint4& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    /// <summary>Returns the uint2 row vector result of a matrix multiplication between a uint4 row vector and a uint4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2 mul(const uint4& a, const uint4x2& b)
    {
        return uint2(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w);
    }

    /// <summary>Returns the uint3 row vector result of a matrix multiplication between a uint4 row vector and a uint4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3 mul(const uint4& a, const uint4x3& b)
    {
        return uint3(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z + a.w * b.c2.w);
    }

    /// <summary>Returns the uint4 row vector result of a matrix multiplication between a uint4 row vector and a uint4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4 mul(const uint4& a, const uint4x4& b)
    {
        return uint4(
            a.x * b.c0.x + a.y * b.c0.y + a.z * b.c0.z + a.w * b.c0.w,
            a.x * b.c1.x + a.y * b.c1.y + a.z * b.c1.z + a.w * b.c1.w,
            a.x * b.c2.x + a.y * b.c2.y + a.z * b.c2.z + a.w * b.c2.w,
            a.x * b.c3.x + a.y * b.c3.y + a.z * b.c3.z + a.w * b.c3.w);
    }

    /// <summary>Returns the uint2 column vector result of a matrix multiplication between a uint2x2 matrix and a uint2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2 mul(const uint2x2& a, const uint2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the uint2x2 matrix result of a matrix multiplication between a uint2x2 matrix and a uint2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x2 mul(const uint2x2& a, const uint2x2& b)
    {
        return uint2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the uint2x3 matrix result of a matrix multiplication between a uint2x2 matrix and a uint2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x3 mul(const uint2x2& a, const uint2x3& b)
    {
        return uint2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the uint2x4 matrix result of a matrix multiplication between a uint2x2 matrix and a uint2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x4 mul(const uint2x2& a, const uint2x4& b)
    {
        return uint2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the uint2 column vector result of a matrix multiplication between a uint2x3 matrix and a uint3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2 mul(const uint2x3& a, const uint3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the uint2x2 matrix result of a matrix multiplication between a uint2x3 matrix and a uint3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x2 mul(const uint2x3& a, const uint3x2& b)
    {
        return uint2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the uint2x3 matrix result of a matrix multiplication between a uint2x3 matrix and a uint3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x3 mul(const uint2x3& a, const uint3x3& b)
    {
        return uint2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the uint2x4 matrix result of a matrix multiplication between a uint2x3 matrix and a uint3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x4 mul(const uint2x3& a, const uint3x4& b)
    {
        return uint2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the uint2 column vector result of a matrix multiplication between a uint2x4 matrix and a uint4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2 mul(const uint2x4& a, const uint4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the uint2x2 matrix result of a matrix multiplication between a uint2x4 matrix and a uint4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x2 mul(const uint2x4& a, const uint4x2& b)
    {
        return uint2x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the uint2x3 matrix result of a matrix multiplication between a uint2x4 matrix and a uint4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x3 mul(const uint2x4& a, const uint4x3& b)
    {
        return uint2x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the uint2x4 matrix result of a matrix multiplication between a uint2x4 matrix and a uint4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint2x4 mul(const uint2x4& a, const uint4x4& b)
    {
        return uint2x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the uint3 column vector result of a matrix multiplication between a uint3x2 matrix and a uint2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3 mul(const uint3x2& a, const uint2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the uint3x2 matrix result of a matrix multiplication between a uint3x2 matrix and a uint2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x2 mul(const uint3x2& a, const uint2x2& b)
    {
        return uint3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the uint3x3 matrix result of a matrix multiplication between a uint3x2 matrix and a uint2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x3 mul(const uint3x2& a, const uint2x3& b)
    {
        return uint3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the uint3x4 matrix result of a matrix multiplication between a uint3x2 matrix and a uint2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x4 mul(const uint3x2& a, const uint2x4& b)
    {
        return uint3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the uint3 column vector result of a matrix multiplication between a uint3x3 matrix and a uint3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3 mul(const uint3x3& a, const uint3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the uint3x2 matrix result of a matrix multiplication between a uint3x3 matrix and a uint3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x2 mul(const uint3x3& a, const uint3x2& b)
    {
        return uint3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the uint3x3 matrix result of a matrix multiplication between a uint3x3 matrix and a uint3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x3 mul(const uint3x3& a, const uint3x3& b)
    {
        return uint3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the uint3x4 matrix result of a matrix multiplication between a uint3x3 matrix and a uint3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x4 mul(const uint3x3& a, const uint3x4& b)
    {
        return uint3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the uint3 column vector result of a matrix multiplication between a uint3x4 matrix and a uint4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3 mul(const uint3x4& a, const uint4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the uint3x2 matrix result of a matrix multiplication between a uint3x4 matrix and a uint4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x2 mul(const uint3x4& a, const uint4x2& b)
    {
        return uint3x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the uint3x3 matrix result of a matrix multiplication between a uint3x4 matrix and a uint4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x3 mul(const uint3x4& a, const uint4x3& b)
    {
        return uint3x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the uint3x4 matrix result of a matrix multiplication between a uint3x4 matrix and a uint4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint3x4 mul(const uint3x4& a, const uint4x4& b)
    {
        return uint3x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns the uint4 column vector result of a matrix multiplication between a uint4x2 matrix and a uint2 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4 mul(const uint4x2& a, const uint2& b)
    {
        return a.c0 * b.x + a.c1 * b.y;
    }

    /// <summary>Returns the uint4x2 matrix result of a matrix multiplication between a uint4x2 matrix and a uint2x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x2 mul(const uint4x2& a, const uint2x2& b)
    {
        return uint4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y);
    }

    /// <summary>Returns the uint4x3 matrix result of a matrix multiplication between a uint4x2 matrix and a uint2x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x3 mul(const uint4x2& a, const uint2x3& b)
    {
        return uint4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y);
    }

    /// <summary>Returns the uint4x4 matrix result of a matrix multiplication between a uint4x2 matrix and a uint2x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x4 mul(const uint4x2& a, const uint2x4& b)
    {
        return uint4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y,
            a.c0 * b.c1.x + a.c1 * b.c1.y,
            a.c0 * b.c2.x + a.c1 * b.c2.y,
            a.c0 * b.c3.x + a.c1 * b.c3.y);
    }

    /// <summary>Returns the uint4 column vector result of a matrix multiplication between a uint4x3 matrix and a uint3 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4 mul(const uint4x3& a, const uint3& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z;
    }

    /// <summary>Returns the uint4x2 matrix result of a matrix multiplication between a uint4x3 matrix and a uint3x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x2 mul(const uint4x3& a, const uint3x2& b)
    {
        return uint4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z);
    }

    /// <summary>Returns the uint4x3 matrix result of a matrix multiplication between a uint4x3 matrix and a uint3x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x3 mul(const uint4x3& a, const uint3x3& b)
    {
        return uint4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z);
    }

    /// <summary>Returns the uint4x4 matrix result of a matrix multiplication between a uint4x3 matrix and a uint3x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x4 mul(const uint4x3& a, const uint3x4& b)
    {
        return uint4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z);
    }

    /// <summary>Returns the uint4 column vector result of a matrix multiplication between a uint4x4 matrix and a uint4 column vector.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4 mul(const uint4x4& a, const uint4& b)
    {
        return a.c0 * b.x + a.c1 * b.y + a.c2 * b.z + a.c3 * b.w;
    }

    /// <summary>Returns the uint4x2 matrix result of a matrix multiplication between a uint4x4 matrix and a uint4x2 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x2 mul(const uint4x4& a, const uint4x2& b)
    {
        return uint4x2(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w);
    }

    /// <summary>Returns the uint4x3 matrix result of a matrix multiplication between a uint4x4 matrix and a uint4x3 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x3 mul(const uint4x4& a, const uint4x3& b)
    {
        return uint4x3(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w);
    }

    /// <summary>Returns the uint4x4 matrix result of a matrix multiplication between a uint4x4 matrix and a uint4x4 matrix.</summary>
    /// <param name="a">Left hand side argument of the matrix multiply.</param>
    /// <param name="b">Right hand side argument of the matrix multiply.</param>
    /// <returns>The computed matrix multiplication.</returns>
    inline uint4x4 mul(const uint4x4& a, const uint4x4& b)
    {
        return uint4x4(
            a.c0 * b.c0.x + a.c1 * b.c0.y + a.c2 * b.c0.z + a.c3 * b.c0.w,
            a.c0 * b.c1.x + a.c1 * b.c1.y + a.c2 * b.c1.z + a.c3 * b.c1.w,
            a.c0 * b.c2.x + a.c1 * b.c2.y + a.c2 * b.c2.z + a.c3 * b.c2.w,
            a.c0 * b.c3.x + a.c1 * b.c3.y + a.c2 * b.c3.z + a.c3 * b.c3.w);
    }

    /// <summary>Returns an orthonormalized version of a float3x3 matrix.</summary>
    /// <param name="i">The float3x3 to be orthonormalized.</param>
    /// <returns>The orthonormalized float3x3 matrix.</returns>
    inline float3x3 orthonormalize(const float3x3& i)
    {
        float3x3 o;

        float3 u = i.c0;
        float3 v = i.c1 - i.c0 * math::dot(i.c1, i.c0);

        float lenU = math::length(u);
        float lenV = math::length(v);

        bool c = lenU > 1e-30f && lenV > 1e-30f;

        o.c0 = math::select(float3(1, 0, 0), u / lenU, c);
        o.c1 = math::select(float3(0, 1, 0), v / lenV, c);
        o.c2 = math::cross(o.c0, o.c1);

        return o;
    }

    /// <summary>
    /// Computes the pseudoinverse of a matrix.
    /// </summary>
    /// <param name="m">Matrix to invert.</param>
    /// <returns>The pseudoinverse of m.</returns>
    inline float3x3 pseudoinverse(const float3x3& m)
    {
        float scaleSq = 0.333333f * (math::lengthsq(m.c0) + math::lengthsq(m.c1) + math::lengthsq(m.c2));
        if (scaleSq < svd::k_EpsilonNormal)
            return float3x3::zero;

        float3 scaleInv = math::rsqrt(scaleSq);
        float3x3 ms = mulScale(m, scaleInv);
        float3x3 i;
        if (!math::adjInverse(ms, OUT i, svd::k_EpsilonDeterminant))
        {
            i = svd::svdInverse(ms);
        }

        return mulScale(i, scaleInv);
    }
}
} // namespace ecs