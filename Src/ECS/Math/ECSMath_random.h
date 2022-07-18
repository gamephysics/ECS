#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
    /// <summary>
    /// Random Number Generator based on xorshift.
    /// Designed for minimal state (32bits) to be easily embeddable into components.
    /// Core functionality is integer multiplication free to improve vectorization
    /// on less capable SIMD instruction sets.
    /// </summary>
	// https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/random.cs
	struct Random
	{
	public:
		/// <summary>
		/// The random number generator state. It should not be zero.
		/// </summary>
		uint state;

	public:
		//=========================================================
		// CONSTRUCTOR
		//=========================================================
	    /// <summary>
        /// Constructs a Random instance with a given seed value. The seed must be non-zero.
        /// </summary>
        /// <param name="seed">The seed to initialize with.</param>
        Random(uint seed)
        {
            state = seed;
            CheckInitState();
            NextState();
        }

        /// <summary>
        /// Constructs a <see cref="Random"/> instance with an index that gets hashed.  The index must not be UINT_MAX.
        /// </summary>
        /// <remarks>
        /// Use this function when you expect to create several Random instances in a loop.
        /// </remarks>
        /// <example>
        /// <code>
        /// for (uint i = 0; i &lt; 4096; ++i)
        /// {
        ///     Random rand = Random.CreateFromIndex(i);
        ///
        ///     // Random numbers drawn from loop iteration j will be very different
        ///     // from every other loop iteration k.
        ///     rand.NextUInt();
        /// }
        /// </code>
        /// </example>
        /// <param name="index">An index that will be hashed for Random creation.  Must not be UINT_MAX.</param>
        /// <returns><see cref="Random"/> created from an index.</returns>
        static Random CreateFromIndex(uint index)
        {
            CheckIndexForHash(index);

            // Wang hash will hash 61 to zero but we want UINT_MAX to hash to zero.  To make this happen
            // we must offset by 62.
            return Random(WangHash(index + 62u));
        }

    private:
        //=========================================================
        // INTERNAL
        //=========================================================
        static uint WangHash(uint n)
        {
            // https://gist.github.com/badboy/6267743#hash-function-construction-principles
            // Wang hash: this has the property that none of the outputs will
            // collide with each other, which is important for the purposes of
            // seeding a random number generator.  This was verified empirically
            // by checking all 2^32 uints.
            n = (n ^ 61u) ^ (n >> 16);
            n *= 9u;
            n = n ^ (n >> 4);
            n *= 0x27d4eb2du;
            n = n ^ (n >> 15);

            return n;
        }

    public:
        /// <summary>
        /// Initialized the state of the Random instance with a given seed value. The seed must be non-zero.
        /// </summary>
        /// <param name="seed">The seed to initialize with.</param>
        void InitState(uint seed = 0x6E624EB7u)
        {
            state = seed;
            NextState();
        }

        /// <summary>Returns a uniformly random bool value.</summary>
        /// <returns>A uniformly random boolean value.</returns>
        bool NextBool()
        {
            return (NextState() & 1) == 1;
        }

        /// <summary>Returns a uniformly random bool2 value.</summary>
        /// <returns>A uniformly random bool2 value.</returns>
        bool2 NextBool2()
        {
            uint v = NextState();
            return (uint2(v) & uint2(1, 2)) == 0;
        }

        /// <summary>Returns a uniformly random bool3 value.</summary>
        /// <returns>A uniformly random bool3 value.</returns>
        bool3 NextBool3()
        {
            uint v = NextState();
            return (uint3(v) & uint3(1, 2, 4)) == 0;
        }

        /// <summary>Returns a uniformly random bool4 value.</summary>
        /// <returns>A uniformly random bool4 value.</returns>
        bool4 NextBool4()
        {
            uint v = NextState();
            return (uint4(v) & uint4(1, 2, 4, 8)) == 0;
        }


        /// <summary>Returns a uniformly random int value in the interval [-2147483647, 2147483647].</summary>
        /// <returns>A uniformly random integer value.</returns>
        int NextInt()
        {
            return (int)NextState() ^ -2147483648;
        }

        /// <summary>Returns a uniformly random int2 value with all components in the interval [-2147483647, 2147483647].</summary>
        /// <returns>A uniformly random int2 value.</returns>
        int2 NextInt2()
        {
            return int2((int)NextState(), (int)NextState()) ^ -2147483648;
        }

        /// <summary>Returns a uniformly random int3 value with all components in the interval [-2147483647, 2147483647].</summary>
        /// <returns>A uniformly random int3 value.</returns>
        int3 NextInt3()
        {
            return int3((int)NextState(), (int)NextState(), (int)NextState()) ^ -2147483648;
        }

        /// <summary>Returns a uniformly random int4 value with all components in the interval [-2147483647, 2147483647].</summary>
        /// <returns>A uniformly random int4 value.</returns>
        int4 NextInt4()
        {
            return int4((int)NextState(), (int)NextState(), (int)NextState(), (int)NextState()) ^ -2147483648;
        }

        /// <summary>Returns a uniformly random int value in the interval [0, max).</summary>
        /// <param name="max">The maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random int value in the range [0, max).</returns>
        int NextInt(int max)
        {
            CheckNextIntMax(max);
            return (int)((NextState() * (uint64)max) >> 32);
        }

        /// <summary>Returns a uniformly random int2 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random int2 value with all components in the range [0, max).</returns>
        int2 NextInt2(int2 max)
        {
            CheckNextIntMax(max.x);
            CheckNextIntMax(max.y);
            return int2((int)(NextState() * (uint64)max.x >> 32),
                        (int)(NextState() * (uint64)max.y >> 32));
        }

        /// <summary>Returns a uniformly random int3 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random int3 value with all components in the range [0, max).</returns>
        int3 NextInt3(int3 max)
        {
            CheckNextIntMax(max.x);
            CheckNextIntMax(max.y);
            CheckNextIntMax(max.z);
            return int3((int)(NextState() * (uint64)max.x >> 32),
                        (int)(NextState() * (uint64)max.y >> 32),
                        (int)(NextState() * (uint64)max.z >> 32));
        }

        /// <summary>Returns a uniformly random int4 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random int4 value with all components in the range [0, max).</returns>
        int4 NextInt4(int4 max)
        {
            CheckNextIntMax(max.x);
            CheckNextIntMax(max.y);
            CheckNextIntMax(max.z);
            CheckNextIntMax(max.w);
            return int4((int)(NextState() * (uint64)max.x >> 32),
                        (int)(NextState() * (uint64)max.y >> 32),
                        (int)(NextState() * (uint64)max.z >> 32),
                        (int)(NextState() * (uint64)max.w >> 32));
        }

        /// <summary>Returns a uniformly random int value in the interval [min, max).</summary>
        /// <param name="min">The minimum value to generate, inclusive.</param>
        /// <param name="max">The maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random integer between [min, max).</returns>
        int NextInt(int min, int max)
        {
            CheckNextIntMinMax(min, max);
            uint range = (uint)(max - min);
            return (int)(NextState() * (uint64)range >> 32) + min;
        }

        /// <summary>Returns a uniformly random int2 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random int2 between [min, max).</returns>
        int2 NextInt2(int2 min, int2 max)
        {
            CheckNextIntMinMax(min.x, max.x);
            CheckNextIntMinMax(min.y, max.y);
            uint2 range = (uint2)(max - min);
            return int2((int)(NextState() * (uint64)range.x >> 32),
                        (int)(NextState() * (uint64)range.y >> 32)) + min;
        }

        /// <summary>Returns a uniformly random int3 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random int3 between [min, max).</returns>
        int3 NextInt3(int3 min, int3 max)
        {
            CheckNextIntMinMax(min.x, max.x);
            CheckNextIntMinMax(min.y, max.y);
            CheckNextIntMinMax(min.z, max.z);
            uint3 range = (uint3)(max - min);
            return int3((int)(NextState() * (uint64)range.x >> 32),
                        (int)(NextState() * (uint64)range.y >> 32),
                        (int)(NextState() * (uint64)range.z >> 32)) + min;
        }

        /// <summary>Returns a uniformly random int4 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random int4 between [min, max).</returns>
        int4 NextInt4(int4 min, int4 max)
        {
            CheckNextIntMinMax(min.x, max.x);
            CheckNextIntMinMax(min.y, max.y);
            CheckNextIntMinMax(min.z, max.z);
            CheckNextIntMinMax(min.w, max.w);
            uint4 range = (uint4)(max - min);
            return int4((int)(NextState() * (uint64)range.x >> 32),
                        (int)(NextState() * (uint64)range.y >> 32),
                        (int)(NextState() * (uint64)range.z >> 32),
                        (int)(NextState() * (uint64)range.w >> 32)) + min;
        }

        /// <summary>Returns a uniformly random uint value in the interval [0, 4294967294].</summary>
        /// <returns>A uniformly random unsigned integer.</returns>
        uint NextUInt()
        {
            return NextState() - 1u;
        }

        /// <summary>Returns a uniformly random uint2 value with all components in the interval [0, 4294967294].</summary>
        /// <returns>A uniformly random uint2.</returns>
        uint2 NextUInt2()
        {
            return uint2(NextState(), NextState()) - 1u;
        }

        /// <summary>Returns a uniformly random uint3 value with all components in the interval [0, 4294967294].</summary>
        /// <returns>A uniformly random uint3.</returns>
        uint3 NextUInt3()
        {
            return uint3(NextState(), NextState(), NextState()) - 1u;
        }

        /// <summary>Returns a uniformly random uint4 value with all components in the interval [0, 4294967294].</summary>
        /// <returns>A uniformly random uint4.</returns>
        uint4 NextUInt4()
        {
            return uint4(NextState(), NextState(), NextState(), NextState()) - 1u;
        }


        /// <summary>Returns a uniformly random uint value in the interval [0, max).</summary>
        /// <param name="max">The maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random unsigned integer in the range [0, max).</returns>
        uint NextUInt(uint max)
        {
            return (uint)((NextState() * (uint64)max) >> 32);
        }

        /// <summary>Returns a uniformly random uint2 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random uint2 in the range [0, max).</returns>
        uint2 NextUInt2(uint2 max)
        {
            return uint2(   (uint)(NextState() * (uint64)max.x >> 32),
                            (uint)(NextState() * (uint64)max.y >> 32));
        }

        /// <summary>Returns a uniformly random uint3 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random uint3 in the range [0, max).</returns>
        uint3 NextUInt3(uint3 max)
        {
            return uint3(   (uint)(NextState() * (uint64)max.x >> 32),
                            (uint)(NextState() * (uint64)max.y >> 32),
                            (uint)(NextState() * (uint64)max.z >> 32));
        }

        /// <summary>Returns a uniformly random uint4 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random uint4 in the range [0, max).</returns>
        uint4 NextUInt4(uint4 max)
        {
            return uint4(   (uint)(NextState() * (uint64)max.x >> 32),
                            (uint)(NextState() * (uint64)max.y >> 32),
                            (uint)(NextState() * (uint64)max.z >> 32),
                            (uint)(NextState() * (uint64)max.w >> 32));
        }

        /// <summary>Returns a uniformly random uint value in the interval [min, max).</summary>
        /// <param name="min">The minimum value to generate, inclusive.</param>
        /// <param name="max">The maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random unsigned integer in the range [min, max).</returns>
        uint NextUInt(uint min, uint max)
        {
            CheckNextUIntMinMax(min, max);
            uint range = max - min;
            return (uint)(NextState() * (uint64)range >> 32) + min;
        }

        /// <summary>Returns a uniformly random uint2 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random uint2 in the range [min, max).</returns>
        uint2 NextUInt2(uint2 min, uint2 max)
        {
            CheckNextUIntMinMax(min.x, max.x);
            CheckNextUIntMinMax(min.y, max.y);
            uint2 range = max - min;
            return uint2((uint)(NextState() * (uint64)range.x >> 32),
                         (uint)(NextState() * (uint64)range.y >> 32)) + min;
        }

        /// <summary>Returns a uniformly random uint3 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random uint3 in the range [min, max).</returns>
        uint3 NextUInt3(uint3 min, uint3 max)
        {
            CheckNextUIntMinMax(min.x, max.x);
            CheckNextUIntMinMax(min.y, max.y);
            CheckNextUIntMinMax(min.z, max.z);
            uint3 range = max - min;
            return uint3((uint)(NextState() * (uint64)range.x >> 32),
                         (uint)(NextState() * (uint64)range.y >> 32),
                         (uint)(NextState() * (uint64)range.z >> 32)) + min;
        }

        /// <summary>Returns a uniformly random uint4 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random uint4 in the range [min, max).</returns>
        uint4 NextUInt4(uint4 min, uint4 max)
        {
            CheckNextUIntMinMax(min.x, max.x);
            CheckNextUIntMinMax(min.y, max.y);
            CheckNextUIntMinMax(min.z, max.z);
            CheckNextUIntMinMax(min.w, max.w);
            uint4 range = (uint4)(max - min);
            return uint4((uint)(NextState() * (uint64)range.x >> 32),
                         (uint)(NextState() * (uint64)range.y >> 32),
                         (uint)(NextState() * (uint64)range.z >> 32),
                         (uint)(NextState() * (uint64)range.w >> 32)) + min;
        }

        /// <summary>Returns a uniformly random float value in the interval [0, 1).</summary>
        /// <returns>A uniformly random float value in the range [0, 1).</returns>
        float NextFloat()
        {
            return math::asfloat(0x3f800000 | (NextState() >> 9)) - 1.0f;
        }

        /// <summary>Returns a uniformly random float2 value with all components in the interval [0, 1).</summary>
        /// <returns>A uniformly random float2 value in the range [0, 1).</returns>
        float2 NextFloat2()
        {
            return math::asfloat(0x3f800000 | (uint2(NextState(), NextState()) >> 9)) - 1.0f;
        }

        /// <summary>Returns a uniformly random float3 value with all components in the interval [0, 1).</summary>
        /// <returns>A uniformly random float3 value in the range [0, 1).</returns>
        float3 NextFloat3()
        {
            return math::asfloat(0x3f800000 | (uint3(NextState(), NextState(), NextState()) >> 9)) - 1.0f;
        }

        /// <summary>Returns a uniformly random float4 value with all components in the interval [0, 1).</summary>
        /// <returns>A uniformly random float4 value in the range [0, 1).</returns>
        float4 NextFloat4()
        {
            return math::asfloat(0x3f800000 | (uint4(NextState(), NextState(), NextState(), NextState()) >> 9)) - 1.0f;
        }


        /// <summary>Returns a uniformly random float value in the interval [0, max).</summary>
        /// <param name="max">The maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random float value in the range [0, max).</returns>
        float NextFloat(float max) { return NextFloat() * max; }

        /// <summary>Returns a uniformly random float2 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random float2 value in the range [0, max).</returns>
        float2 NextFloat2(float2 max) { return NextFloat2() * max; }

        /// <summary>Returns a uniformly random float3 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random float3 value in the range [0, max).</returns>
        float3 NextFloat3(float3 max) { return NextFloat3() * max; }

        /// <summary>Returns a uniformly random float4 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random float4 value in the range [0, max).</returns>
        float4 NextFloat4(float4 max) { return NextFloat4() * max; }


        /// <summary>Returns a uniformly random float value in the interval [min, max).</summary>
        /// <param name="min">The minimum value to generate, inclusive.</param>
        /// <param name="max">The maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random float value in the range [min, max).</returns>
        float NextFloat(float min, float max) { return NextFloat() * (max - min) + min; }

        /// <summary>Returns a uniformly random float2 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random float2 value in the range [min, max).</returns>
        float2 NextFloat2(float2 min, float2 max) { return NextFloat2() * (max - min) + min; }

        /// <summary>Returns a uniformly random float3 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random float3 value in the range [min, max).</returns>
        float3 NextFloat3(float3 min, float3 max) { return NextFloat3() * (max - min) + min; }

        /// <summary>Returns a uniformly random float4 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random float4 value in the range [min, max).</returns>
        float4 NextFloat4(float4 min, float4 max) { return NextFloat4() * (max - min) + min; }



        /// <summary>Returns a uniformly random double value in the interval [0, 1).</summary>
        /// <returns>A uniformly random double value in the range [0, 1).</returns>
        double NextDouble()
        {
            uint64 sx = ((uint64)NextState() << 20) ^ NextState();
            return math::asdouble(0x3ff0000000000000 | sx) - 1.0;
        }

        /// <summary>Returns a uniformly random double2 value with all components in the interval [0, 1).</summary>
        /// <returns>A uniformly random double2 value in the range [0, 1).</returns>
        double2 NextDouble2()
        {
            uint64 sx = ((uint64)NextState() << 20) ^ NextState();
            uint64 sy = ((uint64)NextState() << 20) ^ NextState();
            return double2(math::asdouble(0x3ff0000000000000 | sx),
                           math::asdouble(0x3ff0000000000000 | sy)) - 1.0;
        }

        /// <summary>Returns a uniformly random double3 value with all components in the interval [0, 1).</summary>
        /// <returns>A uniformly random double3 value in the range [0, 1).</returns>
        double3 NextDouble3()
        {
            uint64 sx = ((uint64)NextState() << 20) ^ NextState();
            uint64 sy = ((uint64)NextState() << 20) ^ NextState();
            uint64 sz = ((uint64)NextState() << 20) ^ NextState();
            return double3(math::asdouble(0x3ff0000000000000 | sx),
                           math::asdouble(0x3ff0000000000000 | sy),
                           math::asdouble(0x3ff0000000000000 | sz)) - 1.0;
        }

        /// <summary>Returns a uniformly random double4 value with all components in the interval [0, 1).</summary>
        /// <returns>A uniformly random double4 value in the range [0, 1).</returns>
        double4 NextDouble4()
        {
            uint64 sx = ((uint64)NextState() << 20) ^ NextState();
            uint64 sy = ((uint64)NextState() << 20) ^ NextState();
            uint64 sz = ((uint64)NextState() << 20) ^ NextState();
            uint64 sw = ((uint64)NextState() << 20) ^ NextState();
            return double4(math::asdouble(0x3ff0000000000000 | sx),
                           math::asdouble(0x3ff0000000000000 | sy),
                           math::asdouble(0x3ff0000000000000 | sz),
                           math::asdouble(0x3ff0000000000000 | sw)) - 1.0;
        }


        /// <summary>Returns a uniformly random double value in the interval [0, max).</summary>
        /// <param name="max">The maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random double value in the range [0, max).</returns>
        double NextDouble(double max) { return NextDouble() * max; }

        /// <summary>Returns a uniformly random double2 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random double2 value in the range [0, max).</returns>
        double2 NextDouble2(double2 max) { return NextDouble2() * max; }

        /// <summary>Returns a uniformly random double3 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random double3 value in the range [0, max).</returns>
        double3 NextDouble3(double3 max) { return NextDouble3() * max; }

        /// <summary>Returns a uniformly random double4 value with all components in the interval [0, max).</summary>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random double4 value in the range [0, max).</returns>
        double4 NextDouble4(double4 max) { return NextDouble4() * max; }


        /// <summary>Returns a uniformly random double value in the interval [min, max).</summary>
        /// <param name="min">The minimum value to generate, inclusive.</param>
        /// <param name="max">The maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random double value in the range [min, max).</returns>
        double NextDouble(double min, double max) { return NextDouble() * (max - min) + min; }

        /// <summary>Returns a uniformly random double2 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random double2 value in the range [min, max).</returns>
        double2 NextDouble2(double2 min, double2 max) { return NextDouble2() * (max - min) + min; }

        /// <summary>Returns a uniformly random double3 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random double3 value in the range [min, max).</returns>
        double3 NextDouble3(double3 min, double3 max) { return NextDouble3() * (max - min) + min; }

        /// <summary>Returns a uniformly random double4 value with all components in the interval [min, max).</summary>
        /// <param name="min">The componentwise minimum value to generate, inclusive.</param>
        /// <param name="max">The componentwise maximum value to generate, exclusive.</param>
        /// <returns>A uniformly random double4 value in the range [min, max).</returns>
        double4 NextDouble4(double4 min, double4 max) { return NextDouble4() * (max - min) + min; }

        /// <summary>Returns a unit length float2 vector representing a uniformly random 2D direction.</summary>
        /// <returns>A uniformly random unit length float2 vector.</returns>
        float2 NextFloat2Direction()
        {
            float angle = NextFloat() * math::PI * 2.0f;
            float s, c;
            math::sincos(angle, OUT s, OUT c);
            return float2(c, s);
        }

        /// <summary>Returns a unit length double2 vector representing a uniformly random 2D direction.</summary>
        /// <returns>A uniformly random unit length double2 vector.</returns>
        double2 NextDouble2Direction()
        {
            double angle = NextDouble() * math::PI_DBL * 2.0;
            double s, c;
            math::sincos(angle, OUT s, OUT c);
            return double2(c, s);
        }

        /// <summary>Returns a unit length float3 vector representing a uniformly random 3D direction.</summary>
        /// <returns>A uniformly random unit length float3 vector.</returns>
        float3 NextFloat3Direction()
        {
            float2 rnd = NextFloat2();
            float z = rnd.x * 2.0f - 1.0f;
            float r = math::sqrt(math::max(1.0f - z * z, 0.0f));
            float angle = rnd.y * math::PI * 2.0f;
            float s, c;
            math::sincos(angle, OUT s, OUT c);
            return float3(c*r, s*r, z);
        }

        /// <summary>Returns a unit length double3 vector representing a uniformly random 3D direction.</summary>
        /// <returns>A uniformly random unit length double3 vector.</returns>
        double3 NextDouble3Direction()
        {
            double2 rnd = NextDouble2();
            double z = rnd.x * 2.0 - 1.0;
            double r = math::sqrt(math::max(1.0 - z * z, 0.0));
            double angle = rnd.y * math::PI_DBL * 2.0;
            double s, c;
            math::sincos(angle, OUT s, OUT c);
            return double3(c * r, s * r, z);
        }

        /// <summary>Returns a unit length quaternion representing a uniformly 3D rotation.</summary>
        /// <returns>A uniformly random unit length quaternion.</returns>
        quaternion NextQuaternionRotation()
        {
            float3 rnd = NextFloat3(float3(2.0f * math::PI, 2.0f * math::PI, 1.0f));
            float u1 = rnd.z;
            float2 theta_rho = rnd.xy();

            float i = math::sqrt(1.0f - u1);
            float j = math::sqrt(u1);

            float2 sin_theta_rho;
            float2 cos_theta_rho;
            math::sincos(theta_rho, OUT sin_theta_rho, OUT cos_theta_rho);

            quaternion q = quaternion(i * sin_theta_rho.x, i * cos_theta_rho.x, j * sin_theta_rho.y, j * cos_theta_rho.y);
            return quaternion(math::select(q.value, -q.value, q.value.w < 0.0f));
        }

        //=========================================================
		// PRIVATE
		//=========================================================
    private:
        uint NextState()
        {
            CheckState();
            uint t = state;
            state ^= state << 13;
            state ^= state >> 17;
            state ^= state << 5;
            return t;
        }

        void CheckInitState()
        {
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
            if (state == 0)
                throw std::exception("Seed must be non-zero");
#endif
        }

        static void CheckIndexForHash(uint index)
        {
            if (index == UINT_MAX)
                throw std::exception("Index must not be UINT_MAX");
        }

        void CheckState()
        {
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
            if(state == 0)
                throw std::exception("Invalid state 0. Random object has not been properly initialized");
#endif
        }

        void CheckNextIntMax(int max)
        {
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
            if (max < 0)
                throw std::exception("max must be positive");
#endif
        }

        void CheckNextIntMinMax(int min, int max)
        {
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
            if (min > max)
                throw std::exception("min must be less than or equal to max");
#endif
        }

        void CheckNextUIntMinMax(uint min, uint max)
        {
#if defined(_DEBUG ) || defined(DEBUG_IN_RELEASE)
            if (min > max)
                throw std::exception("min must be less than or equal to max");
#endif
        }
	};

} // namespace ecs