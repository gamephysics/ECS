#include "ECS.h"

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    namespace math
    {
        //=========================================================
        // math-AffineTransform
        //=========================================================
        AffineTransform mul(const AffineTransform& a, const AffineTransform& b)
        {
            return AffineTransform(transform(a, b.t), math::mul(a.rs, b.rs));
        }
        AffineTransform mul(const float3x3& a, const AffineTransform& b)
        {
            return AffineTransform(math::mul(a, b.t), math::mul(a, b.rs));
        }
        AffineTransform mul(const AffineTransform& a, const float3x3& b)
        {
            return AffineTransform(a.t, math::mul(b, a.rs));
        }
        float4 mul(const AffineTransform& a, const float4& pos)
        {
            return float4(math::mul(a.rs, pos.xyz()) + a.t * pos.w, pos.w);
        }
        float3 rotate(const AffineTransform& a, const float3& dir)
        {
            return math::mul(a.rs, dir);
        }
        float3 transform(const AffineTransform& a, const float3& pos)
        {
            return a.t + math::mul(a.rs, pos);
        }
        AffineTransform inverse(const AffineTransform& a)
        {
            AffineTransform inv;
            inv.rs = math::pseudoinverse(a.rs);
            inv.t  = math::mul(inv.rs, -a.t);
            return inv;
        }
        void decompose(const AffineTransform& a, OUT float3& translation, OUT quaternion& rotation, OUT float3& scale)
        {
            translation = a.t;
            rotation = math::rotation(a.rs);
            auto sm  = math::mul(float3x3(math::conjugate(rotation)), a.rs);
            scale = float3(sm.c0.x, sm.c1.y, sm.c2.z);
        }
        uint hash(const AffineTransform& a)
        {
            return math::hash(a.rs) + 0xC5C5394Bu * math::hash(a.t);
        }

        uint4 hashwide(const AffineTransform& a)
        {
            return math::hashwide(a.rs).xyzz() + 0xC5C5394Bu * math::hashwide(a.t).xyzz();
        }
    }

} // namespace ecs
