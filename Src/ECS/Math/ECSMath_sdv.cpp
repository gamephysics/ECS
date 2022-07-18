#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    void svd::condSwap(bool c, OUT float&x, OUT float&y)
    {
        auto tmp = x;
        x = math::select(x, y, c);
        y = math::select(y, tmp, c);
    }

    void svd::condNegSwap(bool c, OUT float3& x, OUT float3& y)
    {
        auto tmp = -x;
        x = math::select(x, y, c);
        y = math::select(y, tmp, c);
    }

    quaternion svd::condNegSwapQuat(bool c, const quaternion& q, const float4& mask)
    {
        const float halfSqrt2 = 0.707106781186548f;
        return math::mul(q, math::select(quaternion::identity.value, mask * halfSqrt2, c));
    }

    void svd::sortSingularValues(OUT float3x3& b, OUT quaternion& v)
    {
        auto l0 = math::lengthsq(b.c0);
        auto l1 = math::lengthsq(b.c1);
        auto l2 = math::lengthsq(b.c2);

        auto c = l0 < l1;
        condNegSwap(c, OUT b.c0, OUT b.c1);
        v = condNegSwapQuat(c, v, float4(0.f, 0.f, 1.f, 1.f));
        condSwap(c, OUT l0, OUT l1);

        c = l0 < l2;
        condNegSwap(c, OUT b.c0, OUT b.c2);
        v = condNegSwapQuat(c, v, float4(0.f, -1.f, 0.f, 1.f));
        condSwap(c, OUT l0, OUT l2);

        c = l1 < l2;
        condNegSwap(c, OUT b.c1, OUT b.c2);
        v = condNegSwapQuat(c, v, float4(1.f, 0.f, 0.f, 1.f));
    }

    quaternion svd::approxGivensQuat(const float3& pq, const float4& mask)
    {
        const float c8 = 0.923879532511287f; // cos(pi/8)
        const float s8 = 0.38268343236509f; // sin(pi/8)
        const float g  = 5.82842712474619f; // 3 + 2 * sqrt(2)

        auto ch = 2.f * (pq.x - pq.y); // approx cos(a/2)
        auto sh = pq.z; // approx sin(a/2)
        auto r = math::select(float4(s8, s8, s8, c8), float4(sh, sh, sh, ch), g * sh * sh < ch* ch) * mask;
        return math::normalize(r);
    }

    quaternion svd::qrGivensQuat(const float2& pq, const float4& mask)
    {
        auto l = math::sqrt(pq.x * pq.x + pq.y * pq.y);
        auto sh = math::select(0.f, pq.y, l > k_EpsilonNormalSqrt);
        auto ch = math::abs(pq.x) + math::max(l, k_EpsilonNormalSqrt);
        condSwap(pq.x < 0.f, OUT sh, OUT ch);

        return math::normalize(float4(sh, sh, sh, ch) * mask);
    }

    quaternion svd::givensQRFactorization(const float3x3& b, OUT float3x3& r)
    {
        auto u = qrGivensQuat(float2(b.c0.x, b.c0.y), float4(0.f, 0.f, 1.f, 1.f));
        auto qmt = float3x3(math::conjugate(u));
        r = math::mul(qmt, b);

        auto q = qrGivensQuat(float2(r.c0.x, r.c0.z), float4(0.f, -1.f, 0.f, 1.f));
        u = math::mul(u, q);
        qmt = float3x3(math::conjugate(q));
        r = math::mul(qmt, r);

        q = qrGivensQuat(float2(r.c1.y, r.c1.z), float4(1.f, 0.f, 0.f, 1.f));
        u = math::mul(u, q);
        qmt = float3x3(math::conjugate(q));
        r = math::mul(qmt, r);

        return u;
    }

    quaternion svd::jacobiIteration(OUT float3x3& s, int iterations/* = 5*/)
    {
        float3x3 qm;
        quaternion q;
        quaternion v = quaternion::identity;

        for (int i = 0; i < iterations; ++i)
        {
            q = approxGivensQuat(float3(s.c0.x, s.c1.y, s.c0.y), float4(0.f, 0.f, 1.f, 1.f));
            v = math::mul(v, q);
            qm = float3x3(q);
            s = math::mul(math::mul(math::transpose(qm), s), qm);

            q = approxGivensQuat(float3(s.c1.y, s.c2.z, s.c1.z), float4(1.f, 0.f, 0.f, 1.f));
            v = math::mul(v, q);
            qm = float3x3(q);
            s = math::mul(math::mul(math::transpose(qm), s), qm);

            q = approxGivensQuat(float3(s.c2.z, s.c0.x, s.c2.x), float4(0.f, 1.f, 0.f, 1.f));
            v = math::mul(v, q);
            qm = float3x3(q);
            s = math::mul(math::mul(math::transpose(qm), s), qm);
        }

        return v;
    }

    float3 svd::singularValuesDecomposition(const float3x3& a, OUT quaternion& u, OUT quaternion& v)
    {
        u = quaternion::identity;
        v = quaternion::identity;

        auto s = math::mul(math::transpose(a), a);
        v = jacobiIteration(OUT s);
        auto b = float3x3(v);
        b = math::mul(a, b);
        sortSingularValues(OUT b, OUT v);
        float3x3 e;
        u = givensQRFactorization(b, OUT e);

        return float3(e.c0.x, e.c1.y, e.c2.z);
    }

    float3 svd::rcpsafe(const float3& x, float epsilon /*= k_EpsilonRCP*/)
    {
        return math::select(math::rcp(x), float3::zero, math::abs(x) < epsilon);
    }        

    //=========================================================
	// INTERNAL
	//=========================================================
    float3x3 svd::svdInverse(const float3x3& a)
    {
        quaternion u, v;
        auto e = singularValuesDecomposition(a, OUT u, OUT v);
        auto um = float3x3(u);
        auto vm = float3x3(v);

        return math::mul(vm, math::scaleMul(rcpsafe(e, k_EpsilonDeterminant), math::transpose(um)));
    }

    quaternion svd::svdRotation(const float3x3& a)
    {
        quaternion u, v;
        singularValuesDecomposition(a, OUT u, OUT v);
        return math::mul(u, math::conjugate(v));
    }

} // namespace ecs
