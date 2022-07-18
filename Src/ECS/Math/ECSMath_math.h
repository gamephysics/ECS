#pragma once


//=============================================================================
// ECS MATH ALGORITHM
//=============================================================================
namespace ecs
{
namespace math
{
    // https://github.com/Unity-Technologies/Unity.Mathematics/tree/master/src/Unity.Mathematics/math.cs

    const double E_DBL      = 2.71828182845904523536;   // The mathematical constant e also known as Euler's number. Approximately 2.72. This is a f64/double precision constant.
    const double LOG2E_DBL  = 1.44269504088896340736;   // The base 2 logarithm of e. Approximately 1.44. This is a f64/double precision constant.
    const double LOG10E_DBL = 0.434294481903251827651;  // The base 10 logarithm of e. Approximately 0.43. This is a f64/double precision constant.
    const double LN2_DBL    = 0.693147180559945309417;  // The natural logarithm of 2. Approximately 0.69. This is a f64/double precision constant.
    const double LN10_DBL   = 2.30258509299404568402;   // The natural logarithm of 10. Approximately 2.30. This is a f64/double precision constant.
    const double PI_DBL     = 3.14159265358979323846;   // The mathematical constant pi. Approximately 3.14. This is a f64/double precision constant.
    const double PI2_DBL    = PI_DBL * 2.0;             // The mathematical constant (2 * pi). Approximately 6.28. This is a f64/double precision constant. Also known as <see cref="TAU_DBL"/>.
    const double PIHALF_DBL = PI_DBL * 0.5;             // The mathematical constant (pi / 2). Approximately 1.57. This is a f64/double precision constant.
    const double TAU_DBL    = PI2_DBL;                  // The mathematical constant tau. Approximately 6.28. This is a f64/double precision constant. Also known as <see cref="PI2_DBL"/>.

    // The conversion constant used to convert radians to degrees. Multiply the radian value by this constant to get degrees.
    // <remarks>Multiplying by this constant is equivalent to using <see cref="math::degrees(double)"/>.</remarks>
    const double TODEGREES_DBL = 57.29577951308232;
    // The conversion constant used to convert degrees to radians. Multiply the degree value by this constant to get radians.
    // <remarks>Multiplying by this constant is equivalent to using <see cref="math::radians(double)"/>.</remarks>
    const double TORADIANS_DBL = 0.017453292519943296;
    
    const double SQRT2_DBL  = 1.41421356237309504880;    // The square root 2. Approximately 1.41. This is a f64/double precision constant.

    // The difference between 1.0 and the next representable f64/double precision number.
    // Beware: This value is different from System.Double.Epsilon, which is the smallest, positive, denormalized f64/double.
    const double EPSILON_DBL    = 2.22044604925031308085e-16;
    const double INFINITY_DBL   = DBL_MAX;              // Double precision constant for positive infinity.

    // Double precision constant for Not a Number.
    // NAN_DBL is considered unordered, which means all comparisons involving it are false except for not equal (operator !=).
    // As a consequence, NAN_DBL == NAN_DBL is false but NAN_DBL != NAN_DBL is true.
    // Additionally, there are multiple bit representations for Not a Number, so if you must test if your value
    // is NAN_DBL, use isnan().
    //const double NAN_DBL = Double.NaN;
    const float FLT_MIN_NORMAL = 1.175494351e-38F;          // The smallest positive normal number representable in a float.
    const double DBL_MIN_NORMAL = 2.2250738585072014e-308;  // The smallest positive normal number representable in a double. This is a f64/double precision constant.

    const float E = (float)E_DBL;                       // The mathematical constant e also known as Euler's number. Approximately 2.72.
    const float LOG2E = (float)LOG2E_DBL;               // The base 2 logarithm of e. Approximately 1.44.
    const float LOG10E = (float)LOG10E_DBL;             // The base 10 logarithm of e. Approximately 0.43.
    const float LN2 = (float)LN2_DBL;                   // The natural logarithm of 2. Approximately 0.69.
    const float LN10 = (float)LN10_DBL;                 // The natural logarithm of 10. Approximately 2.30.
    const float PI = (float)PI_DBL;                     // The mathematical constant pi. Approximately 3.14.
    const float PI2 = (float)PI2_DBL;                   // The mathematical constant (2 * pi). Approximately 6.28. Also known as <see cref="TAU"/>.
    const float PIHALF = (float)PIHALF_DBL;             // The mathematical constant (pi / 2). Approximately 1.57.
    const float TAU = (float)PI2_DBL;                   // The mathematical constant tau. Approximately 6.28. Also known as <see cref="PI2"/>.

    // The conversion constant used to convert radians to degrees. Multiply the radian value by this constant to get degrees.
    // <remarks>Multiplying by this constant is equivalent to using <see cref="math::degrees(float)"/>.</remarks>
    const float TODEGREES = (float)TODEGREES_DBL;

    // The conversion constant used to convert degrees to radians. Multiply the degree value by this constant to get radians.
    // <remarks>Multiplying by this constant is equivalent to using <see cref="math::radians(float)"/>.</remarks>
    const float TORADIANS = (float)TORADIANS_DBL;

    const float SQRT2 = (float)SQRT2_DBL;               // The square root 2. Approximately 1.41.

    // The difference between 1.f and the next representable f32/single precision number.
    ///
    // Beware:
    // This value is different from System.Single.Epsilon, which is the smallest, positive, denormalized f32/single.
    const float EPSILON = 1.1920928955078125e-7f;

    const float INFINITY_FLT = FLT_MAX;                 // Single precision constant for positive infinity.

    // Single precision constant for Not a Number.
    ///
    // NAN is considered unordered, which means all comparisons involving it are false except for not equal (operator !=).
    // As a consequence, NAN == NAN is false but NAN != NAN is true.
    ///
    // Additionally, there are multiple bit representations for Not a Number, so if you must test if your value
    // is NAN, use isnan().
    //const float NAN_FLT   = Single.NaN;

    //=============================================================================
    // 
    //=============================================================================
    inline uint     asuint(int x)           { return (uint)x;       }
    inline uint2    asuint(int2 x)          { return *(uint2*)&x;   }
    inline uint3    asuint(int3 x)          { return *(uint3*)&x;   }
    inline uint4    asuint(int4 x)          { return *(uint4*)&x;   }
    inline uint     asuint(float x)         { return *(uint*)&x;    }
    inline uint2    asuint(float2 x)        { return *(uint2*)&x;   }
    inline uint3    asuint(float3 x)        { return *(uint3*)&x;   }
    inline uint4    asuint(float4 x)        { return *(uint4*)&x;   }
    inline uint64   asuint64(int64 x)       { return (uint64)x;     }
    inline uint64   asuint64(double x)      { return *(uint64*)&x;  }
    inline int      asint(uint x)           { return *(int*)&x;     }
    inline int2     asint(uint2 x)          { return *(int2*)&x;    }
    inline int3     asint(uint3 x)          { return *(int3*)&x;    }
    inline int4     asint(uint4 x)          { return *(int4*)&x;    }
    inline int      asint(float x)          { return *(int*)&x;     }
    inline int2     asint(float2 x)         { return *(int2*)&x;    }
    inline int3     asint(float3 x)         { return *(int3*)&x;    }
    inline int4     asint(float4 x)         { return *(int4*)&x;    }
    inline int64    asint64(uint64 x)       { return (int64)x;      }
    inline int64    asint64(double x)       { return *(int64*)&x;   }
    inline float    asfloat(int x)          { return *(float*)&x;   }
    inline float2   asfloat(int2 x)         { return *(float2*)&x;  }
    inline float3   asfloat(int3 x)         { return *(float3*)&x;  }
    inline float4   asfloat(int4 x)         { return *(float4*)&x;  }
    inline float    asfloat(uint x)         { return *(float*)&x;   }
    inline float2   asfloat(uint2 x)        { return *(float2*)&x;  }
    inline float3   asfloat(uint3 x)        { return *(float3*)&x;  }
    inline float4   asfloat(uint4 x)        { return *(float4*)&x;  }
    inline double   asdouble(int64 x)       { return *(double*)&x;  }
    inline double   asdouble(uint64 x)      { return *(double*)&x;  }

    // <summary>Returns a bools indicating for each component of a vector whether it is a NaN (not a number) floating point value.</summary>
    // <remarks>NaN has several representations and may vary across architectures. Use this function to check if you have a NaN.</remarks>
    // <param name="x">Input value.</param>
    // <returns>True if the component was NaN; false otherwise.</returns>
    inline bool     isnan(float x)          { return (asuint(x) & 0x7FFFFFFF) > 0x7F800000; }
    inline bool2    isnan(float2 x)         { return (asuint(x) & 0x7FFFFFFF) > 0x7F800000; }
    inline bool3    isnan(float3 x)         { return (asuint(x) & 0x7FFFFFFF) > 0x7F800000; }
    inline bool4    isnan(float4 x)         { return (asuint(x) & 0x7FFFFFFF) > 0x7F800000; }
    inline bool     isnan(double x)         { return (asuint64(x) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000; }
    inline bool2    isnan(double2 x)        { return bool2( (asuint64(x.x) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000,
                                                            (asuint64(x.y) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000);}
    inline bool3    isnan(double3 x)        { return bool3( (asuint64(x.x) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000,
                                                            (asuint64(x.y) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000,
                                                            (asuint64(x.z) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000);}
    inline bool4    isnan(double4 x)        { return bool4( (asuint64(x.x) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000,
                                                            (asuint64(x.y) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000,
                                                            (asuint64(x.z) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000,
                                                            (asuint64(x.w) & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000);}

    // <summary>Checks if each component of the input is a power of two.</summary>
    // <remarks>If a component of x is less than or equal to zero, then this function returns false in that component.</remarks>
    // <param name="x">int2 input</param>
    // <returns>bool2 where true in a component indicates the same component in the input was a power of two.</returns>
    inline bool     ispow2(uint x)              { return x > 0 && ((x & (x - 1)) == 0);   }
    inline bool2    ispow2(uint2 x)             { return bool2(ispow2(x.x), ispow2(x.y)); }
    inline bool3    ispow2(uint3 x)             { return bool3(ispow2(x.x), ispow2(x.y), ispow2(x.z)); }
    inline bool4    ispow2(uint4 x)             { return bool4(ispow2(x.x), ispow2(x.y), ispow2(x.z), ispow2(x.w)); }
    inline bool     ispow2(int x)               { return x > 0 && ((x & (x - 1)) == 0);   }   
    inline bool2    ispow2(int2 x)              { return bool2(ispow2(x.x), ispow2(x.y)); }
    inline bool3    ispow2(int3 x)              { return bool3(ispow2(x.x), ispow2(x.y), ispow2(x.z));}
    inline bool4    ispow2(int4 x)              { return bool4(ispow2(x.x), ispow2(x.y), ispow2(x.z), ispow2(x.w)); }

    // <summary>Returns the componentwise minimum of two vectors.</summary>
    // <param name="x">The first input value.</param>
    // <param name="y">The second input value.</param>
    // <returns>The componentwise minimum of the two input values.</returns>
    inline uint     min(uint x, uint y)         { return x < y ? x : y; }
    inline uint2    min(uint2 x, uint2 y)       { return uint2(min(x.x, y.x), min(x.y, y.y)); }
    inline uint3    min(uint3 x, uint3 y)       { return uint3(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z)); }
    inline uint4    min(uint4 x, uint4 y)       { return uint4(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z), min(x.w, y.w)); }
    inline uint64   min(uint64 x, uint64 y)     { return x < y ? x : y; }
    inline int      min(int x, int y)           { return x < y ? x : y;   }
    inline int2     min(int2 x, int2 y)         { return int2(min(x.x, y.x), min(x.y, y.y)); }
    inline int3     min(int3 x, int3 y)         { return int3(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z)); }
    inline int4     min(int4 x, int4 y)         { return int4(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z), min(x.w, y.w)); }
    inline int64    min(int64 x, int64 y)       { return x < y ? x : y; }
    inline float    min(float x, float y)       { return std::isnan(y) || x < y ? x : y; }
    inline float2   min(float2 x, float2 y)     { return float2(min(x.x, y.x), min(x.y, y.y)); }
    inline float3   min(float3 x, float3 y)     { return float3(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z)); }
    inline float4   min(float4 x, float4 y)     { return float4(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z), min(x.w, y.w)); }
    inline double   min(double x, double y)     { return std::isnan(y) || x < y ? x : y; }
    inline double2  min(double2 x, double2 y)   { return double2(min(x.x, y.x), min(x.y, y.y)); }
    inline double3  min(double3 x, double3 y)   { return double3(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z)); }
    inline double4  min(double4 x, double4 y)   { return double4(min(x.x, y.x), min(x.y, y.y), min(x.z, y.z), min(x.w, y.w)); }
    
    /// <summary>Returns the componentwise maximum of two vectors.</summary>
    /// <param name="x">The first input value.</param>
    /// <param name="y">The second input value.</param>
    /// <returns>The componentwise maximum of the two input values.</returns>
    inline uint     max(uint x, uint y)         { return x > y ? x : y; }
    inline uint2    max(uint2 x, uint2 y)       { return uint2(max(x.x, y.x), max(x.y, y.y)); }
    inline uint3    max(uint3 x, uint3 y)       { return uint3(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z)); }
    inline uint4    max(uint4 x, uint4 y)       { return uint4(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z), max(x.w, y.w)); }
    inline uint64   max(uint64 x, uint64 y)     { return x > y ? x : y; }
    inline int      max(int x, int y)           { return x > y ? x : y; }
    inline int2     max(int2 x, int2 y)         { return int2(max(x.x, y.x), max(x.y, y.y)); }
    inline int3     max(int3 x, int3 y)         { return int3(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z)); }
    inline int4     max(int4 x, int4 y)         { return int4(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z), max(x.w, y.w)); }
    inline int64    max(int64 x, int64 y)       { return x > y ? x : y; }
    inline float    max(float x, float y)       { return std::isnan(y) || x > y ? x : y; }
    inline float2   max(float2 x, float2 y)     { return float2(max(x.x, y.x), max(x.y, y.y)); }
    inline float3   max(float3 x, float3 y)     { return float3(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z)); }
    inline float4   max(float4 x, float4 y)     { return float4(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z), max(x.w, y.w)); }
    inline double   max(double x, double y)     { return std::isnan(y) || x > y ? x : y; }
    inline double2  max(double2 x, double2 y)   { return double2(max(x.x, y.x), max(x.y, y.y)); }
    inline double3  max(double3 x, double3 y)   { return double3(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z)); }
    inline double4  max(double4 x, double4 y)   { return double4(max(x.x, y.x), max(x.y, y.y), max(x.z, y.z), max(x.w, y.w)); }


    // <summary>Returns the result of a componentwise linear interpolating from x to y using the interpolation parameter t.</summary>
    // <remarks>If the interpolation parameter is not in the range [0, 1], then this function extrapolates.</remarks>
    // <param name="start">The start point, corresponding to the interpolation parameter value of 0.</param>
    // <param name="end">The end point, corresponding to the interpolation parameter value of 1.</param>
    // <param name="t">The interpolation parameter. May be a value outside the interval [0, 1].</param>
    // <returns>The componentwise interpolation from x to y.</returns>
    inline float    lerp(float start, float end, float t)   { return start + t * (end - start); }
    inline float2   lerp(float2 start, float2 end, float t) { return start + t * (end - start); }
    inline float3   lerp(float3 start, float3 end, float t) { return start + t * (end - start); }
    inline float4   lerp(float4 start, float4 end, float t) { return start + t * (end - start); }
    inline float2   lerp(float2 start, float2 end, float2 t) { return start + t * (end - start); }
    inline float3   lerp(float3 start, float3 end, float3 t) { return start + t * (end - start); }
    inline float4   lerp(float4 start, float4 end, float4 t) { return start + t * (end - start); }
    inline double   lerp(double start, double end, double t) { return start + t * (end - start); }
    inline double2  lerp(double2 start, double2 end, double t) { return start + t * (end - start); }
    inline double3  lerp(double3 start, double3 end, double t) { return start + t * (end - start); }
    inline double4  lerp(double4 start, double4 end, double t) { return start + t * (end - start); }
    inline double2  lerp(double2 start, double2 end, double2 t) { return start + t * (end - start); }
    inline double3  lerp(double3 start, double3 end, double3 t) { return start + t * (end - start); }
    inline double4  lerp(double4 start, double4 end, double4 t) { return start + t * (end - start); }


    // <summary>Returns the componentwise result of normalizing a floating point value x to a range [a, b]. The opposite of lerp. Equivalent to (x - a) / (b - a).</summary>
    // <param name="start">The start point of the range.</param>
    // <param name="end">The end point of the range.</param>
    // <param name="x">The value to normalize to the range.</param>
    // <returns>The componentwise interpolation parameter of x with respect to the input range [a, b].</returns>
    inline float    unlerp(float start, float end, float x) { return (x - start) / (end - start); }
    inline float2   unlerp(float2 start, float2 end, float2 x) { return (x - start) / (end - start); }
    inline float3   unlerp(float3 start, float3 end, float3 x) { return (x - start) / (end - start); }
    inline float4   unlerp(float4 start, float4 end, float4 x) { return (x - start) / (end - start); }
    inline double   unlerp(double start, double end, double x) { return (x - start) / (end - start); }
    inline double2  unlerp(double2 start, double2 end, double2 x) { return (x - start) / (end - start); }
    inline double3  unlerp(double3 start, double3 end, double3 x) { return (x - start) / (end - start); }
    inline double4  unlerp(double4 start, double4 end, double4 x) { return (x - start) / (end - start); }


    // <summary>Returns the componentwise result of a non-clamping linear remapping of a value x from source range [srcStart, srcEnd] to the destination range [dstStart, dstEnd].</summary>
    // <param name="srcStart">The start point of the source range [srcStart, srcEnd].</param>
    // <param name="srcEnd">The end point of the source range [srcStart, srcEnd].</param>
    // <param name="dstStart">The start point of the destination range [dstStart, dstEnd].</param>
    // <param name="dstEnd">The end point of the destination range [dstStart, dstEnd].</param>
    // <param name="x">The value to remap from the source to destination range.</param>
    // <returns>The componentwise remap of input x from the source range to the destination range.</returns>
    inline float    remap(float srcStart, float srcEnd, float dstStart, float dstEnd, float x) { return lerp(dstStart, dstEnd, unlerp(srcStart, srcEnd, x)); }
    inline float2   remap(float2 srcStart, float2 srcEnd, float2 dstStart, float2 dstEnd, float2 x) { return lerp(dstStart, dstEnd, unlerp(srcStart, srcEnd, x)); }
    inline float3   remap(float3 srcStart, float3 srcEnd, float3 dstStart, float3 dstEnd, float3 x) { return lerp(dstStart, dstEnd, unlerp(srcStart, srcEnd, x)); }
    inline float4   remap(float4 srcStart, float4 srcEnd, float4 dstStart, float4 dstEnd, float4 x) { return lerp(dstStart, dstEnd, unlerp(srcStart, srcEnd, x)); }
    inline double   remap(double srcStart, double srcEnd, double dstStart, double dstEnd, double x) { return lerp(dstStart, dstEnd, unlerp(srcStart, srcEnd, x)); }
    inline double2  remap(double2 srcStart, double2 srcEnd, double2 dstStart, double2 dstEnd, double2 x) { return lerp(dstStart, dstEnd, unlerp(srcStart, srcEnd, x)); }
    inline double3  remap(double3 srcStart, double3 srcEnd, double3 dstStart, double3 dstEnd, double3 x) { return lerp(dstStart, dstEnd, unlerp(srcStart, srcEnd, x)); }
    inline double4  remap(double4 srcStart, double4 srcEnd, double4 dstStart, double4 dstEnd, double4 x) { return lerp(dstStart, dstEnd, unlerp(srcStart, srcEnd, x)); }


    // <summary>Returns the result of a componentwise multiply-add operation (a * b + c) on 3 int2 vectors.</summary>
    // <param name="mulA">First value to multiply.</param>
    // <param name="mulB">Second value to multiply.</param>
    // <param name="addC">Third value to add to the product of a and b.</param>
    // <returns>The componentwise multiply-add of the inputs.</returns>
    inline uint     mad(uint mulA, uint mulB, uint addC)            { return mulA * mulB + addC; }
    inline uint2    mad(uint2 mulA, uint2 mulB, uint2 addC)         { return mulA * mulB + addC; }
    inline uint3    mad(uint3 mulA, uint3 mulB, uint3 addC)         { return mulA * mulB + addC; }
    inline uint4    mad(uint4 mulA, uint4 mulB, uint4 addC)         { return mulA * mulB + addC; }
    inline uint64   mad(uint64 mulA, uint64 mulB, uint64 addC)      { return mulA * mulB + addC; }
    inline int      mad(int mulA, int mulB, int addC)               { return mulA * mulB + addC; }
    inline int2     mad(int2 mulA, int2 mulB, int2 addC)            { return mulA * mulB + addC; }
    inline int3     mad(int3 mulA, int3 mulB, int3 addC)            { return mulA * mulB + addC; }
    inline int4     mad(int4 mulA, int4 mulB, int4 addC)            { return mulA * mulB + addC; }
    inline int64    mad(int64 mulA, int64 mulB, int64 addC)         { return mulA * mulB + addC; }
    inline float    mad(float mulA, float mulB, float addC)         { return mulA * mulB + addC; }
    inline float2   mad(float2 mulA, float2 mulB, float2 addC)      { return mulA * mulB + addC; }
    inline float3   mad(float3 mulA, float3 mulB, float3 addC)      { return mulA * mulB + addC; }
    inline float4   mad(float4 mulA, float4 mulB, float4 addC)      { return mulA * mulB + addC; }
    inline double   mad(double mulA, double mulB, double addC)      { return mulA * mulB + addC; }
    inline double2  mad(double2 mulA, double2 mulB, double2 addC)   { return mulA * mulB + addC; }
    inline double3  mad(double3 mulA, double3 mulB, double3 addC)   { return mulA * mulB + addC; }
    inline double4  mad(double4 mulA, double4 mulB, double4 addC)   { return mulA * mulB + addC; }

    // <summary>Returns the result of a componentwise clamping of the x into the interval [a, b], where a and b are vectors.</summary>
    // <param name="valueToClamp">Input value to be clamped.</param>
    // <param name="lowerBound">Lower bound of the interval.</param>
    // <param name="upperBound">Upper bound of the interval.</param>
    // <returns>The componentwise clamping of the input valueToClamp into the interval (inclusive) [lowerBound, upperBound].</returns>
    inline uint     clamp(uint valueToClamp, uint lowerBound, uint upperBound)          { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline uint2    clamp(uint2 valueToClamp, uint2 lowerBound, uint2 upperBound)       { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline uint3    clamp(uint3 valueToClamp, uint3 lowerBound, uint3 upperBound)       { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline uint4    clamp(uint4 valueToClamp, uint4 lowerBound, uint4 upperBound)       { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline uint64   clamp(uint64 valueToClamp, uint64 lowerBound, uint64 upperBound)    { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline int      clamp(int valueToClamp, int lowerBound, int upperBound)             { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline int2     clamp(int2 valueToClamp, int2 lowerBound, int2 upperBound)          { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline int3     clamp(int3 valueToClamp, int3 lowerBound, int3 upperBound)          { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline int4     clamp(int4 valueToClamp, int4 lowerBound, int4 upperBound)          { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline int64    clamp(int64 valueToClamp, int64 lowerBound, int64 upperBound)       { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline float    clamp(float valueToClamp, float lowerBound, float upperBound)       { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline float2   clamp(float2 valueToClamp, float2 lowerBound, float2 upperBound)    { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline float3   clamp(float3 valueToClamp, float3 lowerBound, float3 upperBound)    { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline float4   clamp(float4 valueToClamp, float4 lowerBound, float4 upperBound)    { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline double   clamp(double valueToClamp, double lowerBound, double upperBound)    { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline double2  clamp(double2 valueToClamp, double2 lowerBound, double2 upperBound) { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline double3  clamp(double3 valueToClamp, double3 lowerBound, double3 upperBound) { return max(lowerBound, min(upperBound, valueToClamp)); }
    inline double4  clamp(double4 valueToClamp, double4 lowerBound, double4 upperBound) { return max(lowerBound, min(upperBound, valueToClamp)); }


    // <summary>Returns the result of a componentwise clamping of the vector x into the interval [0, 1].</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise clamping of the input into the interval [0, 1].</returns>
    inline float    saturate(float x)       { return clamp(x, 0.f, 1.f); }
    inline float2   saturate(float2 x)      { return clamp(x, float2(0.f), float2(1.f)); }
    inline float3   saturate(float3 x)      { return clamp(x, float3(0.f), float3(1.f)); }
    inline float4   saturate(float4 x)      { return clamp(x, float4(0.f), float4(1.f)); }
    inline double   saturate(double x)      { return clamp(x, 0.0, 1.0); }
    inline double2  saturate(double2 x)     { return clamp(x, double2(0.0), double2(1.0)); }
    inline double3  saturate(double3 x)     { return clamp(x, double3(0.0), double3(1.0)); }
    inline double4  saturate(double4 x)     { return clamp(x, double4(0.0), double4(1.0)); }

    // <summary>Returns the componentwise absolute value of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise absolute value of the input.</returns>
    inline int      abs(int x)              { return max(-x, x); }
    inline int2     abs(int2 x)             { return max(-x, x); }
    inline int3     abs(int3 x)             { return max(-x, x); }
    inline int4     abs(int4 x)             { return max(-x, x); }
    inline int64    abs(int64 x)            { return max(-x, x); }
    inline float    abs(float x)            { return asfloat(asuint(x) & 0x7FFFFFFF); }
    inline float2   abs(float2 x)           { return asfloat(asuint(x) & 0x7FFFFFFF); }
    inline float3   abs(float3 x)           { return asfloat(asuint(x) & 0x7FFFFFFF); }
    inline float4   abs(float4 x)           { return asfloat(asuint(x) & 0x7FFFFFFF); }
    inline double   abs(double x)           { return asdouble(asuint64(x) & 0x7FFFFFFFFFFFFFFF); }
    inline double2  abs(double2 x)          { return double2(asdouble(asuint64(x.x) & 0x7FFFFFFFFFFFFFFF), asdouble(asuint64(x.y) & 0x7FFFFFFFFFFFFFFF)); }
    inline double3  abs(double3 x)          { return double3(asdouble(asuint64(x.x) & 0x7FFFFFFFFFFFFFFF), asdouble(asuint64(x.y) & 0x7FFFFFFFFFFFFFFF), asdouble(asuint64(x.z) & 0x7FFFFFFFFFFFFFFF)); }
    inline double4  abs(double4 x)          { return double4(asdouble(asuint64(x.x) & 0x7FFFFFFFFFFFFFFF), asdouble(asuint64(x.y) & 0x7FFFFFFFFFFFFFFF), asdouble(asuint64(x.z) & 0x7FFFFFFFFFFFFFFF), asdouble(asuint64(x.w) & 0x7FFFFFFFFFFFFFFF)); }

    // <summary>Returns the dot product of two vectors.</summary>
    // <param name="x">The first vector.</param>
    // <param name="y">The second vector.</param>
    // <returns>The dot product of two vectors.</returns>
    inline uint     dot(uint x, uint y)     { return x * y; }
    inline uint     dot(uint2 x, uint2 y)   { return x.x * y.x + x.y * y.y; }
    inline uint     dot(uint3 x, uint3 y)   { return x.x * y.x + x.y * y.y + x.z * y.z; }
    inline uint     dot(uint4 x, uint4 y)   { return x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w; }
    inline int      dot(int x, int y)       { return x * y; }
    inline int      dot(int2 x, int2 y)     { return x.x * y.x + x.y * y.y; }
    inline int      dot(int3 x, int3 y)     { return x.x * y.x + x.y * y.y + x.z * y.z; }
    inline int      dot(int4 x, int4 y)     { return x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w; }
    inline float    dot(float x, float y)   { return x * y; }
    inline float    dot(float2 x, float2 y) { return x.x * y.x + x.y * y.y; }
    inline float    dot(float3 x, float3 y) { return x.x * y.x + x.y * y.y + x.z * y.z; }
    inline float    dot(float4 x, float4 y) { return x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w; }
    inline double   dot(double x, double y) { return x * y; }
    inline double   dot(double2 x, double2 y) { return x.x * y.x + x.y * y.y; }
    inline double   dot(double3 x, double3 y) { return x.x * y.x + x.y * y.y + x.z * y.z; }
    inline double   dot(double4 x, double4 y) { return x.x * y.x + x.y * y.y + x.z * y.z + x.w * y.w; }

    // <summary>Returns the componentwise tangent of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise tangent of the input.</returns>
    inline float    tan(float x)            { return (float)std::tan(x); }
    inline float2   tan(float2 x)           { return float2(tan(x.x), tan(x.y)); }
    inline float3   tan(float3 x)           { return float3(tan(x.x), tan(x.y), tan(x.z)); }
    inline float4   tan(float4 x)           { return float4(tan(x.x), tan(x.y), tan(x.z), tan(x.w)); }
    inline double   tan(double x)           { return std::tan(x); }
    inline double2  tan(double2 x)          { return double2(tan(x.x), tan(x.y)); }
    inline double3  tan(double3 x)          { return double3(tan(x.x), tan(x.y), tan(x.z)); }
    inline double4  tan(double4 x)          { return double4(tan(x.x), tan(x.y), tan(x.z), tan(x.w)); }

    // <summary>Returns the componentwise hyperbolic tangent of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise hyperbolic tangent of the input.</returns>
    inline float    tanh(float x)           { return (float)std::tanh(x); }
    inline float2   tanh(float2 x)          { return float2(tanh(x.x), tanh(x.y)); }
    inline float3   tanh(float3 x)          { return float3(tanh(x.x), tanh(x.y), tanh(x.z)); }
    inline float4   tanh(float4 x)          { return float4(tanh(x.x), tanh(x.y), tanh(x.z), tanh(x.w)); }
    inline double   tanh(double x)          { return std::tanh(x); }
    inline double2  tanh(double2 x)         { return double2(tanh(x.x), tanh(x.y)); }
    inline double3  tanh(double3 x)         { return double3(tanh(x.x), tanh(x.y), tanh(x.z)); }
    inline double4  tanh(double4 x)         { return double4(tanh(x.x), tanh(x.y), tanh(x.z), tanh(x.w)); }

    // <summary>Returns the componentwise arctangent of a vector.</summary>
    // <param name="x">A tangent value, usually the ratio y/x on the unit circle.</param>
    // <returns>The componentwise arctangent of the input, in radians.</returns>
    inline float    atan(float x)           { return (float)std::atan(x); }
    inline float2   atan(float2 x)          { return float2(atan(x.x), atan(x.y)); }
    inline float3   atan(float3 x)          { return float3(atan(x.x), atan(x.y), atan(x.z)); }
    inline float4   atan(float4 x)          { return float4(atan(x.x), atan(x.y), atan(x.z), atan(x.w)); }
    inline double   atan(double x)          { return std::atan(x); }
    inline double2  atan(double2 x)         { return double2(atan(x.x), atan(x.y)); }
    inline double3  atan(double3 x)         { return double3(atan(x.x), atan(x.y), atan(x.z)); }
    inline double4  atan(double4 x)         { return double4(atan(x.x), atan(x.y), atan(x.z), atan(x.w)); }


    // <summary>Returns the componentwise 2-argument arctangent of a pair of vectors.</summary>
    // <param name="y">Numerator of the ratio y/x, usually the y component on the unit circle.</param>
    // <param name="x">Denominator of the ratio y/x, usually the x component on the unit circle.</param>
    // <returns>The componentwise arctangent of the ratio y/x, in radians.</returns>
    inline float    atan2(float y, float x)     { return (float)std::atan2(y, x); }
    inline float2   atan2(float2 y, float2 x)   { return float2(atan2(y.x, x.x), atan2(y.y, x.y)); }
    inline float3   atan2(float3 y, float3 x)   { return float3(atan2(y.x, x.x), atan2(y.y, x.y), atan2(y.z, x.z)); }
    inline float4   atan2(float4 y, float4 x)   { return float4(atan2(y.x, x.x), atan2(y.y, x.y), atan2(y.z, x.z), atan2(y.w, x.w)); }
    inline double   atan2(double y, double x)   { return std::atan2(y, x); }
    inline double2  atan2(double2 y, double2 x) { return double2(atan2(y.x, x.x), atan2(y.y, x.y)); }
    inline double3  atan2(double3 y, double3 x) { return double3(atan2(y.x, x.x), atan2(y.y, x.y), atan2(y.z, x.z)); }
    inline double4  atan2(double4 y, double4 x) { return double4(atan2(y.x, x.x), atan2(y.y, x.y), atan2(y.z, x.z), atan2(y.w, x.w)); }

    // <summary>Returns the componentwise cosine of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise cosine cosine of the input.</returns>
    inline float    cos(float x)                { return (float)std::cos(x); }
    inline float2   cos(float2 x)               { return float2(cos(x.x), cos(x.y)); }
    inline float3   cos(float3 x)               { return float3(cos(x.x), cos(x.y), cos(x.z)); }
    inline float4   cos(float4 x)               { return float4(cos(x.x), cos(x.y), cos(x.z), cos(x.w)); }
    inline double   cos(double x)               { return std::cos(x); }
    inline double2  cos(double2 x)              { return double2(cos(x.x), cos(x.y)); }
    inline double3  cos(double3 x)              { return double3(cos(x.x), cos(x.y), cos(x.z)); }
    inline double4  cos(double4 x)              { return double4(cos(x.x), cos(x.y), cos(x.z), cos(x.w)); }


    /// <summary>Returns the componentwise hyperbolic cosine of a vector.</summary>
    /// <param name="x">Input value.</param>
    /// <returns>The componentwise hyperbolic cosine of the input.</returns>
    inline float    cosh(float x)               { return (float)std::cosh(x); }
    inline float2   cosh(float2 x)              { return float2(cosh(x.x), cosh(x.y)); }
    inline float3   cosh(float3 x)              { return float3(cosh(x.x), cosh(x.y), cosh(x.z)); }
    inline float4   cosh(float4 x)              { return float4(cosh(x.x), cosh(x.y), cosh(x.z), cosh(x.w)); }
    inline double   cosh(double x)              { return std::cosh(x); }
    inline double2  cosh(double2 x)             { return double2(cosh(x.x), cosh(x.y)); }
    inline double3  cosh(double3 x)             { return double3(cosh(x.x), cosh(x.y), cosh(x.z)); }
    inline double4  cosh(double4 x)             { return double4(cosh(x.x), cosh(x.y), cosh(x.z), cosh(x.w)); }


    // <summary>Returns the componentwise arccosine of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise arccosine of the input.</returns>
    inline float    acos(float x)               { return (float)std::acos((float)x); }
    inline float2   acos(float2 x)              { return float2(acos(x.x), acos(x.y)); }
    inline float3   acos(float3 x)              { return float3(acos(x.x), acos(x.y), acos(x.z)); }
    inline float4   acos(float4 x)              { return float4(acos(x.x), acos(x.y), acos(x.z), acos(x.w)); }
    inline double   acos(double x)              { return std::acos(x); }
    inline double2  acos(double2 x)             { return double2(acos(x.x), acos(x.y)); }
    inline double3  acos(double3 x)             { return double3(acos(x.x), acos(x.y), acos(x.z)); }
    inline double4  acos(double4 x)             { return double4(acos(x.x), acos(x.y), acos(x.z), acos(x.w)); }
    
    // <summary>Returns the componentwise sine of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise sine of the input.</returns>
    inline float    sin(float x)                { return (float)std::sin((float)x); }
    inline float2   sin(float2 x)               { return float2(sin(x.x), sin(x.y)); }
    inline float3   sin(float3 x)               { return float3(sin(x.x), sin(x.y), sin(x.z)); }
    inline float4   sin(float4 x)               { return float4(sin(x.x), sin(x.y), sin(x.z), sin(x.w)); }
    inline double   sin(double x)               { return std::sin(x); }
    inline double2  sin(double2 x)              { return double2(sin(x.x), sin(x.y)); }
    inline double3  sin(double3 x)              { return double3(sin(x.x), sin(x.y), sin(x.z)); }
    inline double4  sin(double4 x)              { return double4(sin(x.x), sin(x.y), sin(x.z), sin(x.w)); }


    // <summary>Returns the componentwise hyperbolic sine of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise hyperbolic sine of the input.</returns>
    inline float    sinh(float x)               { return (float)std::sinh((float)x); }
    inline float2   sinh(float2 x)              { return float2(sinh(x.x), sinh(x.y)); }
    inline float3   sinh(float3 x)              { return float3(sinh(x.x), sinh(x.y), sinh(x.z)); }
    inline float4   sinh(float4 x)              { return float4(sinh(x.x), sinh(x.y), sinh(x.z), sinh(x.w)); }
    inline double   sinh(double x)              { return std::sinh(x); }
    inline double2  sinh(double2 x)             { return double2(sinh(x.x), sinh(x.y)); }
    inline double3  sinh(double3 x)             { return double3(sinh(x.x), sinh(x.y), sinh(x.z)); }
    inline double4  sinh(double4 x)             { return double4(sinh(x.x), sinh(x.y), sinh(x.z), sinh(x.w)); }

    // <summary>Returns the componentwise arcsine of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise arcsine of the input.</returns>
    inline float    asin(float x)               { return (float)std::asin((float)x); }
    inline float2   asin(float2 x)              { return float2(asin(x.x), asin(x.y)); }
    inline float3   asin(float3 x)              { return float3(asin(x.x), asin(x.y), asin(x.z)); }
    inline float4   asin(float4 x)              { return float4(asin(x.x), asin(x.y), asin(x.z), asin(x.w)); }
    inline double   asin(double x)              { return std::asin(x); }
    inline double2  asin(double2 x)             { return double2(asin(x.x), asin(x.y)); }
    inline double3  asin(double3 x)             { return double3(asin(x.x), asin(x.y), asin(x.z)); }
    inline double4  asin(double4 x)             { return double4(asin(x.x), asin(x.y), asin(x.z), asin(x.w)); }

    // <summary>Returns the result of rounding each component of a vector value down to the nearest value less or equal to the original value.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise round down to nearest integral value of the input.</returns>
    inline float    floor(float x)              { return (float)std::floor((float)x); }
    inline float2   floor(float2 x)             { return float2(floor(x.x), floor(x.y)); }
    inline float3   floor(float3 x)             { return float3(floor(x.x), floor(x.y), floor(x.z)); }
    inline float4   floor(float4 x)             { return float4(floor(x.x), floor(x.y), floor(x.z), floor(x.w)); }
    inline double   floor(double x)             { return std::floor(x); }
    inline double2  floor(double2 x)            { return double2(floor(x.x), floor(x.y)); }
    inline double3  floor(double3 x)            { return double3(floor(x.x), floor(x.y), floor(x.z)); }
    inline double4  floor(double4 x)            { return double4(floor(x.x), floor(x.y), floor(x.z), floor(x.w)); }


    // <summary>Returns the result of rounding each component of a vector value up to the nearest value greater or equal to the original value.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise round up to nearest integral value of the input.</returns>
    inline float    ceil(float x)               { return (float)std::ceil((float)x); }
    inline float2   ceil(float2 x)              { return float2(ceil(x.x), ceil(x.y)); }
    inline float3   ceil(float3 x)              { return float3(ceil(x.x), ceil(x.y), ceil(x.z)); }
    inline float4   ceil(float4 x)              { return float4(ceil(x.x), ceil(x.y), ceil(x.z), ceil(x.w)); }
    inline double   ceil(double x)              { return std::ceil(x); }
    inline double2  ceil(double2 x)             { return double2(ceil(x.x), ceil(x.y)); }
    inline double3  ceil(double3 x)             { return double3(ceil(x.x), ceil(x.y), ceil(x.z)); }
    inline double4  ceil(double4 x)             { return double4(ceil(x.x), ceil(x.y), ceil(x.z), ceil(x.w)); }


    // <summary>Returns the result of rounding each component of a vector value to the nearest integral value.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise round to nearest integral value of the input.</returns>
    inline float    round(float x)              { return (float)std::round((float)x); }
    inline float2   round(float2 x)             { return float2(round(x.x), round(x.y)); }
    inline float3   round(float3 x)             { return float3(round(x.x), round(x.y), round(x.z)); }
    inline float4   round(float4 x)             { return float4(round(x.x), round(x.y), round(x.z), round(x.w)); }
    inline double   round(double x)             { return std::round(x); }
    inline double2  round(double2 x)            { return double2(round(x.x), round(x.y)); }
    inline double3  round(double3 x)            { return double3(round(x.x), round(x.y), round(x.z)); }
    inline double4  round(double4 x)            { return double4(round(x.x), round(x.y), round(x.z), round(x.w)); }


    // <summary>Returns the result of a componentwise truncation of a value to an integral float2 value.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise truncation of the input.</returns>
    inline float    trunc(float x)              { return (float)std::trunc((float)x); }
    inline float2   trunc(float2 x)             { return float2(trunc(x.x), trunc(x.y)); }
    inline float3   trunc(float3 x)             { return float3(trunc(x.x), trunc(x.y), trunc(x.z)); }
    inline float4   trunc(float4 x)             { return float4(trunc(x.x), trunc(x.y), trunc(x.z), trunc(x.w)); }
    inline double   trunc(double x)             { return std::trunc(x); }
    inline double2  trunc(double2 x)            { return double2(trunc(x.x), trunc(x.y)); }
    inline double3  trunc(double3 x)            { return double3(trunc(x.x), trunc(x.y), trunc(x.z)); }
    inline double4  trunc(double4 x)            { return double4(trunc(x.x), trunc(x.y), trunc(x.z), trunc(x.w)); }


    // <summary>Returns the componentwise fractional parts of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise fractional part of the input.</returns>
    inline float    frac(float x)               { return x - floor(x); }
    inline float2   frac(float2 x)              { return x - floor(x); }
    inline float3   frac(float3 x)              { return x - floor(x); }
    inline float4   frac(float4 x)              { return x - floor(x); }
    inline double   frac(double x)              { return x - floor(x); }
    inline double2  frac(double2 x)             { return x - floor(x); }
    inline double3  frac(double3 x)             { return x - floor(x); }
    inline double4  frac(double4 x)             { return x - floor(x); }

    // <summary>Returns the componentwise reciprocal a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise reciprocal of the input.</returns>
    inline float    rcp(float x)                { return 1.f / x; }
    inline float2   rcp(float2 x)               { return 1.f / x; }
    inline float3   rcp(float3 x)               { return 1.f / x; }
    inline float4   rcp(float4 x)               { return 1.f / x; }
    inline double   rcp(double x)               { return 1.0  / x; }
    inline double2  rcp(double2 x)              { return 1.0  / x; }
    inline double3  rcp(double3 x)              { return 1.0  / x; }
    inline double4  rcp(double4 x)              { return 1.0  / x; }

    // <summary>Returns the componentwise sign of a value. 1 for positive components, 0 for zero components and -1 for negative components.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise sign of the input.</returns>
    inline int      sign(int x)                 { return (x > 0 ? 1 : 0) - (x < 0 ? 1 : 0); }
    inline int2     sign(int2 x)                { return int2(sign(x.x), sign(x.y)); }
    inline int3     sign(int3 x)                { return int3(sign(x.x), sign(x.y), sign(x.z)); }
    inline int4     sign(int4 x)                { return int4(sign(x.x), sign(x.y), sign(x.z), sign(x.w)); }
    inline float    sign(float x)               { return (x > 0.f ? 1.f : 0.f) - (x < 0.f ? 1.f : 0.f); }
    inline float2   sign(float2 x)              { return float2(sign(x.x), sign(x.y)); }
    inline float3   sign(float3 x)              { return float3(sign(x.x), sign(x.y), sign(x.z)); }
    inline float4   sign(float4 x)              { return float4(sign(x.x), sign(x.y), sign(x.z), sign(x.w)); }
    inline double   sign(double x)              { return x == 0 ? 0 : (x > 0.0 ? 1.0 : 0.0) - (x < 0.0 ? 1.0 : 0.0); }
    inline double2  sign(double2 x)             { return double2(sign(x.x), sign(x.y)); }
    inline double3  sign(double3 x)             { return double3(sign(x.x), sign(x.y), sign(x.z)); }
    inline double4  sign(double4 x)             { return double4(sign(x.x), sign(x.y), sign(x.z), sign(x.w)); }


    // <summary>Returns the componentwise result of raising x to the power y.</summary>
    // <param name="x">The exponent base.</param>
    // <param name="y">The exponent power.</param>
    // <returns>The componentwise result of raising x to the power y.</returns>
    inline float    pow(float x, float y)       { return (float)std::pow((float)x, (float)y); }
    inline float2   pow(float2 x, float2 y)     { return float2(pow(x.x, y.x), pow(x.y, y.y)); }
    inline float3   pow(float3 x, float3 y)     { return float3(pow(x.x, y.x), pow(x.y, y.y), pow(x.z, y.z)); }
    inline float4   pow(float4 x, float4 y)     { return float4(pow(x.x, y.x), pow(x.y, y.y), pow(x.z, y.z), pow(x.w, y.w)); }
    inline double   pow(double x, double y)     { return std::pow(x, y); }
    inline double2  pow(double2 x, double2 y)   { return double2(pow(x.x, y.x), pow(x.y, y.y)); }
    inline double3  pow(double3 x, double3 y)   { return double3(pow(x.x, y.x), pow(x.y, y.y), pow(x.z, y.z)); }
    inline double4  pow(double4 x, double4 y)   { return double4(pow(x.x, y.x), pow(x.y, y.y), pow(x.z, y.z), pow(x.w, y.w)); }


    // <summary>Returns the componentwise base-e exponential of x.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise base-e exponential of the input.</returns>
    inline float    exp(float x)                { return (float)std::exp((float)x); }
    inline float2   exp(float2 x)               { return float2(exp(x.x), exp(x.y)); }
    inline float3   exp(float3 x)               { return float3(exp(x.x), exp(x.y), exp(x.z)); }
    inline float4   exp(float4 x)               { return float4(exp(x.x), exp(x.y), exp(x.z), exp(x.w)); }
    inline double   exp(double x)               { return std::exp(x); }
    inline double2  exp(double2 x)              { return double2(exp(x.x), exp(x.y)); }
    inline double3  exp(double3 x)              { return double3(exp(x.x), exp(x.y), exp(x.z)); }
    inline double4  exp(double4 x)              { return double4(exp(x.x), exp(x.y), exp(x.z), exp(x.w)); }


    // <summary>Returns the componentwise base-2 exponential of x.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise base-2 exponential of the input.</returns>
    inline float    exp2(float x)               { return (float)std::exp((float)x * 0.69314718f); }
    inline float2   exp2(float2 x)              { return float2(exp2(x.x), exp2(x.y)); }
    inline float3   exp2(float3 x)              { return float3(exp2(x.x), exp2(x.y), exp2(x.z)); }
    inline float4   exp2(float4 x)              { return float4(exp2(x.x), exp2(x.y), exp2(x.z), exp2(x.w)); }
    inline double   exp2(double x)              { return std::exp(x * 0.693147180559945309); }
    inline double2  exp2(double2 x)             { return double2(exp2(x.x), exp2(x.y)); }
    inline double3  exp2(double3 x)             { return double3(exp2(x.x), exp2(x.y), exp2(x.z)); }
    inline double4  exp2(double4 x)             { return double4(exp2(x.x), exp2(x.y), exp2(x.z), exp2(x.w)); }


    // <summary>Returns the componentwise base-10 exponential of x.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise base-10 exponential of the input.</returns>
    inline float    exp10(float x)              { return (float)std::exp((float)x * 2.30258509f); }
    inline float2   exp10(float2 x)             { return float2(exp10(x.x), exp10(x.y)); }
    inline float3   exp10(float3 x)             { return float3(exp10(x.x), exp10(x.y), exp10(x.z)); }
    inline float4   exp10(float4 x)             { return float4(exp10(x.x), exp10(x.y), exp10(x.z), exp10(x.w)); }
    inline double   exp10(double x)             { return std::exp(x * 2.302585092994045684); }
    inline double2  exp10(double2 x)            { return double2(exp10(x.x), exp10(x.y)); }
    inline double3  exp10(double3 x)            { return double3(exp10(x.x), exp10(x.y), exp10(x.z)); }
    inline double4  exp10(double4 x)            { return double4(exp10(x.x), exp10(x.y), exp10(x.z), exp10(x.w)); }

    // <summary>Returns the componentwise natural logarithm of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise natural logarithm of the input.</returns>
    inline float    log(float x)                { return (float)std::log((float)x); }
    inline float2   log(float2 x)               { return float2(log(x.x), log(x.y)); }
    inline float3   log(float3 x)               { return float3(log(x.x), log(x.y), log(x.z)); }
    inline float4   log(float4 x)               { return float4(log(x.x), log(x.y), log(x.z), log(x.w)); }
    inline double   log(double x)               { return std::log(x); }
    inline double2  log(double2 x)              { return double2(log(x.x), log(x.y)); }
    inline double3  log(double3 x)              { return double3(log(x.x), log(x.y), log(x.z)); }
    inline double4  log(double4 x)              { return double4(log(x.x), log(x.y), log(x.z), log(x.w)); }


    // <summary>Returns the componentwise base-2 logarithm of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise base-2 logarithm of the input.</returns>
    inline float    log2(float x)               { return (float)std::log2((float)x); }
    inline float2   log2(float2 x)              { return float2(log2(x.x), log2(x.y)); }
    inline float3   log2(float3 x)              { return float3(log2(x.x), log2(x.y), log2(x.z)); }
    inline float4   log2(float4 x)              { return float4(log2(x.x), log2(x.y), log2(x.z), log2(x.w)); }
    inline double   log2(double x)              { return std::log2(x); }
    inline double2  log2(double2 x)             { return double2(log2(x.x), log2(x.y)); }
    inline double3  log2(double3 x)             { return double3(log2(x.x), log2(x.y), log2(x.z)); }
    inline double4  log2(double4 x)             { return double4(log2(x.x), log2(x.y), log2(x.z), log2(x.w)); }

    // <summary>Returns the componentwise base-10 logarithm of a vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise base-10 logarithm of the input.</returns>
    inline float    log10(float x)              { return (float)std::log10((float)x); }
    inline float2   log10(float2 x)             { return float2(log10(x.x), log10(x.y)); }
    inline float3   log10(float3 x)             { return float3(log10(x.x), log10(x.y), log10(x.z)); }
    inline float4   log10(float4 x)             { return float4(log10(x.x), log10(x.y), log10(x.z), log10(x.w)); }
    inline double   log10(double x)             { return std::log10(x); }
    inline double2  log10(double2 x)            { return double2(log10(x.x), log10(x.y)); }
    inline double3  log10(double3 x)            { return double3(log10(x.x), log10(x.y), log10(x.z)); }
    inline double4  log10(double4 x)            { return double4(log10(x.x), log10(x.y), log10(x.z), log10(x.w)); }


    // <summary>Returns the componentwise floating point remainder of x/y.</summary>
    // <param name="x">The dividend in x/y.</param>
    // <param name="y">The divisor in x/y.</param>
    // <returns>The componentwise remainder of x/y.</returns>
    inline float    fmod(float x, float y)      { return std::fmod(x, y); }
    inline float2   fmod(float2 x, float2 y)    { return float2(std::fmod(x.x, y.x), std::fmod(x.y, y.y)); }
    inline float3   fmod(float3 x, float3 y)    { return float3(std::fmod(x.x, y.x), std::fmod(x.y, y.y), std::fmod(x.z, y.z)); }
    inline float4   fmod(float4 x, float4 y)    { return float4(std::fmod(x.x, y.x), std::fmod(x.y, y.y), std::fmod(x.z, y.z), std::fmod(x.w, y.w)); }
    inline double   fmod(double x, double y)    { return std::fmod(x, y); }
    inline double2  fmod(double2 x, double2 y)  { return double2(std::fmod(x.x, y.x), std::fmod(x.y, y.y)); }
    inline double3  fmod(double3 x, double3 y)  { return double3(std::fmod(x.x, y.x), std::fmod(x.y, y.y), std::fmod(x.z, y.z)); }
    inline double4  fmod(double4 x, double4 y)  { return double4(std::fmod(x.x, y.x), std::fmod(x.y, y.y), std::fmod(x.z, y.z), std::fmod(x.w, y.w)); }


    // <summary>
    // Performs a componentwise split of a float2 vector into an integral part i and a fractional part that gets returned.
    // Both parts take the sign of the corresponding input component.
    // </summary>
    // <param name="x">Value to split into integral and fractional part.</param>
    // <param name="i">Output value containing integral part of x.</param>
    // <returns>The componentwise fractional part of x.</returns>
    inline float    modf(float x,  OUT float&  i)   { i = trunc(x); return x - i; }
    inline float2   modf(float2 x, OUT float2& i)   { i = trunc(x); return x - i; }
    inline float3   modf(float3 x, OUT float3& i)   { i = trunc(x); return x - i; }
    inline float4   modf(float4 x, OUT float4& i)   { i = trunc(x); return x - i; }
    inline double   modf(double x, OUT double& i)   { i = trunc(x); return x - i; }
    inline double2  modf(double2 x, OUT double2& i) { i = trunc(x); return x - i; }
    inline double3  modf(double3 x, OUT double3& i) { i = trunc(x); return x - i; }
    inline double4  modf(double4 x, OUT double4& i) { i = trunc(x); return x - i; }


    // <summary>Returns the componentwise square root of a vector.</summary>
    // <param name="x">Value to use when computing square root.</param>
    // <returns>The componentwise square root.</returns>
    inline float    sqrt(float x)               { return (float)std::sqrt((float)x); }
    inline float2   sqrt(float2 x)              { return float2(sqrt(x.x), sqrt(x.y)); }
    inline float3   sqrt(float3 x)              { return float3(sqrt(x.x), sqrt(x.y), sqrt(x.z)); }
    inline float4   sqrt(float4 x)              { return float4(sqrt(x.x), sqrt(x.y), sqrt(x.z), sqrt(x.w)); }
    inline double   sqrt(double x)              { return std::sqrt(x); }
    inline double2  sqrt(double2 x)             { return double2(sqrt(x.x), sqrt(x.y)); }
    inline double3  sqrt(double3 x)             { return double3(sqrt(x.x), sqrt(x.y), sqrt(x.z)); }
    inline double4  sqrt(double4 x)             { return double4(sqrt(x.x), sqrt(x.y), sqrt(x.z), sqrt(x.w)); }
    inline float    rsqrt(float x)              { return 1.f / sqrt(x); }
    inline float2   rsqrt(float2 x)             { return 1.f / sqrt(x); }
    inline float3   rsqrt(float3 x)             { return 1.f / sqrt(x); }
    inline float4   rsqrt(float4 x)             { return 1.f / sqrt(x); }
    inline double   rsqrt(double x)             { return 1.0 / sqrt(x); }
    inline double2  rsqrt(double2 x)            { return 1.0 / sqrt(x); }
    inline double3  rsqrt(double3 x)            { return 1.0 / sqrt(x); }
    inline double4  rsqrt(double4 x)            { return 1.0 / sqrt(x); }

    // <summary>Returns the length of a vector.</summary>
    // <param name="x">Vector to use when computing length.</param>
    // <returns>Length of vector x.</returns>
    inline float    length(float x)             { return abs(x); }
    inline float    length(float2 x)            { return sqrt(dot(x, x)); }
    inline float    length(float3 x)            { return sqrt(dot(x, x)); }
    inline float    length(float4 x)            { return sqrt(dot(x, x)); }
    inline double   length(double x)            { return abs(x); }
    inline double   length(double2 x)           { return sqrt(dot(x, x)); }
    inline double   length(double3 x)           { return sqrt(dot(x, x)); }
    inline double   length(double4 x)           { return sqrt(dot(x, x)); }

    // <summary>Returns the squared length of a vector.</summary>
    // <param name="x">Vector to use when computing squared length.</param>
    // <returns>Squared length of vector x.</returns>
    inline float    lengthsq(float x)           { return x * x; }
    inline float    lengthsq(float2 x)          { return dot(x, x); }
    inline float    lengthsq(float3 x)          { return dot(x, x); }
    inline float    lengthsq(float4 x)          { return dot(x, x); }
    inline double   lengthsq(double x)          { return x * x; }
    inline double   lengthsq(double2 x)         { return dot(x, x); }
    inline double   lengthsq(double3 x)         { return dot(x, x); }
    inline double   lengthsq(double4 x)         { return dot(x, x); }


    // <summary>Returns the distance between two vectors.</summary>
    // <param name="x">First vector to use in distance computation.</param>
    // <param name="y">Second vector to use in distance computation.</param>
    // <returns>The distance between x and y.</returns>
    inline float    distance(float x, float y)      { return abs(y - x); }
    inline float    distance(float2 x, float2 y)    { return length(y - x); }
    inline float    distance(float3 x, float3 y)    { return length(y - x); }
    inline float    distance(float4 x, float4 y)    { return length(y - x); }
    inline double   distance(double x, double y)    { return abs(y - x); }
    inline double   distance(double2 x, double2 y)  { return length(y - x); }
    inline double   distance(double3 x, double3 y)  { return length(y - x); }
    inline double   distance(double4 x, double4 y)  { return length(y - x); }


    // <summary>Returns the squared distance between two vectors.</summary>
    // <param name="x">First vector to use in distance computation.</param>
    // <param name="y">Second vector to use in distance computation.</param>
    // <returns>The squared distance between x and y.</returns>
    inline float    distancesq(float x, float y)    { return (y - x) * (y - x); }
    inline float    distancesq(float2 x, float2 y)  { return lengthsq(y - x); }
    inline float    distancesq(float3 x, float3 y)  { return lengthsq(y - x); }
    inline float    distancesq(float4 x, float4 y)  { return lengthsq(y - x); }
    inline double   distancesq(double x, double y)  { return (y - x) * (y - x); }
    inline double   distancesq(double2 x, double2 y){ return lengthsq(y - x); }
    inline double   distancesq(double3 x, double3 y){ return lengthsq(y - x); }
    inline double   distancesq(double4 x, double4 y){ return lengthsq(y - x); }


    // <summary>Returns the cross product of two vectors.</summary>
    // <param name="x">First vector to use in cross product.</param>
    // <param name="y">Second vector to use in cross product.</param>
    // <returns>The cross product of x and y.</returns>
    inline float3   cross(float3 x, float3 y)       { return (x * y.yzx() - x.yzx() * y).yzx(); }
    inline double3  cross(double3 x, double3 y)     { return (x * y.yzx() - x.yzx() * y).yzx(); }


    // <summary>Returns a componentwise smooth Hermite interpolation between 0.f and 1.f when x is in the interval (inclusive) [xMin, xMax].</summary>
    // <param name="xMin">The minimum range of the x parameter.</param>
    // <param name="xMax">The maximum range of the x parameter.</param>
    // <param name="x">The value to be interpolated.</param>
    /// <returns>Returns component values camped to the range [0, 1].</returns>
    inline float smoothstep(float xMin, float xMax, float x)
    {
        auto t = saturate((x - xMin) / (xMax - xMin));
        return t * t * (3.f - (2.f * t));
    }
    inline float2 smoothstep(float2 xMin, float2 xMax, float2 x)
    {
        auto t = saturate((x - xMin) / (xMax - xMin));
        return t * t * (3.f - (2.f * t));
    }
    inline float3 smoothstep(float3 xMin, float3 xMax, float3 x)
    {
        auto t = saturate((x - xMin) / (xMax - xMin));
        return t * t * (3.f - (2.f * t));
    }
    inline float4 smoothstep(float4 xMin, float4 xMax, float4 x)
    {
        auto t = saturate((x - xMin) / (xMax - xMin));
        return t * t * (3.f - (2.f * t));
    }
    inline double smoothstep(double xMin, double xMax, double x)
    {
        auto t = saturate((x - xMin) / (xMax - xMin));
        return t * t * (3.0 - (2.0 * t));
    }
    inline double2 smoothstep(double2 xMin, double2 xMax, double2 x)
    {
        auto t = saturate((x - xMin) / (xMax - xMin));
        return t * t * (3.0 - (2.0 * t));
    }
    inline double3 smoothstep(double3 xMin, double3 xMax, double3 x)
    {
        auto t = saturate((x - xMin) / (xMax - xMin));
        return t * t * (3.0 - (2.0 * t));
    }
    inline double4 smoothstep(double4 xMin, double4 xMax, double4 x)
    {
        auto t = saturate((x - xMin) / (xMax - xMin));
        return t * t * (3.0 - (2.0 * t));
    }

    
    // <summary>Returns true if the input float is a finite floating point value, false otherwise.</summary>
    // <param name="x">The float value to test.</param>
    // <returns>True if the float is finite, false otherwise.</returns>
    inline bool     isfinite(float x)       { return abs(x) < INFINITY_FLT; }
    inline bool2    isfinite(float2 x)      { return abs(x) < INFINITY_FLT; }
    inline bool3    isfinite(float3 x)      { return abs(x) < INFINITY_FLT; }
    inline bool4    isfinite(float4 x)      { return abs(x) < INFINITY_FLT; }
    inline bool     isfinite(double x)      { return abs(x) < INFINITY_DBL; }
    inline bool2    isfinite(double2 x)     { return abs(x) < INFINITY_DBL; }
    inline bool3    isfinite(double3 x)     { return abs(x) < INFINITY_DBL; }
    inline bool4    isfinite(double4 x)     { return abs(x) < INFINITY_DBL; }

    // <summary>Returns a bools indicating for each component of a vector whether it is an infinite floating point value.</summary>
    // <param name="x">Input value.</param>
    // <returns>True if the component was an infinite value; false otherwise.</returns>
    inline bool     isinf(float x)          { return abs(x) == INFINITY_FLT; }
    inline bool2    isinf(float2 x)         { return abs(x) == INFINITY_FLT; }
    inline bool3    isinf(float3 x)         { return abs(x) == INFINITY_FLT; }
    inline bool4    isinf(float4 x)         { return abs(x) == INFINITY_FLT; }
    inline bool     isinf(double x)         { return abs(x) == INFINITY_DBL; }
    inline bool2    isinf(double2 x)        { return abs(x) == INFINITY_DBL; }
    inline bool3    isinf(double3 x)        { return abs(x) == INFINITY_DBL; }
    inline bool4    isinf(double4 x)        { return abs(x) == INFINITY_DBL; }

    // <summary>Returns true if any component of the input vector is true, false otherwise.</summary>
    // <param name="x">Vector of values to compare.</param>
    // <returns>True if any the components of x are true, false otherwise.</returns>
    inline bool     any(bool2 x)                    { return x.x || x.y; }
    inline bool     any(bool3 x)                    { return x.x || x.y || x.z; }
    inline bool     any(bool4 x)                    { return x.x || x.y || x.z || x.w; }
    inline bool     any(uint2 x)                    { return x.x != 0 || x.y != 0; }
    inline bool     any(uint3 x)                    { return x.x != 0 || x.y != 0 || x.z != 0; }
    inline bool     any(uint4 x)                    { return x.x != 0 || x.y != 0 || x.z != 0 || x.w != 0; }
    inline bool     any(int2 x)                     { return x.x != 0 || x.y != 0; }
    inline bool     any(int3 x)                     { return x.x != 0 || x.y != 0 || x.z != 0; }
    inline bool     any(int4 x)                     { return x.x != 0 || x.y != 0 || x.z != 0 || x.w != 0; }
    inline bool     any(float2 x)                   { return x.x != 0.f || x.y != 0.f; }
    inline bool     any(float3 x)                   { return x.x != 0.f || x.y != 0.f || x.z != 0.f; }
    inline bool     any(float4 x)                   { return x.x != 0.f || x.y != 0.f || x.z != 0.f || x.w != 0.f; }
    inline bool     any(double2 x)                  { return x.x != 0.0 || x.y != 0.0; }
    inline bool     any(double3 x)                  { return x.x != 0.0 || x.y != 0.0 || x.z != 0.0; }
    inline bool     any(double4 x)                  { return x.x != 0.0 || x.y != 0.0 || x.z != 0.0 || x.w != 0.0; }


    // <summary>Returns true if all components of the input vector are true, false otherwise.</summary>
    // <param name="x">Vector of values to compare.</param>
    // <returns>True if all the components of x are true, false otherwise.</returns>
    inline bool     all(bool2 x)                    { return x.x && x.y; }
    inline bool     all(bool3 x)                    { return x.x && x.y && x.z; }
    inline bool     all(bool4 x)                    { return x.x && x.y && x.z && x.w; }
    inline bool     all(uint2 x)                    { return x.x != 0 && x.y != 0; }
    inline bool     all(uint3 x)                    { return x.x != 0 && x.y != 0 && x.z != 0; }
    inline bool     all(uint4 x)                    { return x.x != 0 && x.y != 0 && x.z != 0 && x.w != 0; }
    inline bool     all(int2 x)                     { return x.x != 0 && x.y != 0; }
    inline bool     all(int3 x)                     { return x.x != 0 && x.y != 0 && x.z != 0; }
    inline bool     all(int4 x)                     { return x.x != 0 && x.y != 0 && x.z != 0 && x.w != 0; }
    inline bool     all(float2 x)                   { return x.x != 0.f && x.y != 0.f; }
    inline bool     all(float3 x)                   { return x.x != 0.f && x.y != 0.f && x.z != 0.f; }
    inline bool     all(float4 x)                   { return x.x != 0.f && x.y != 0.f && x.z != 0.f && x.w != 0.f; }
    inline bool     all(double2 x)                  { return x.x != 0.0 && x.y != 0.0; }
    inline bool     all(double3 x)                  { return x.x != 0.0 && x.y != 0.0 && x.z != 0.0; }
    inline bool     all(double4 x)                  { return x.x != 0.0 && x.y != 0.0 && x.z != 0.0 && x.w != 0.0; }


    // <summary>Returns trueValue if test is true, falseValue otherwise.</summary>
    // <param name="falseValue">Value to use if test is false.</param>
    // <param name="trueValue">Value to use if test is true.</param>
    // <param name="test">Bool value to choose between falseValue and trueValue.</param>
    // <returns>The selection between falseValue and trueValue according to bool test.</returns>
    inline uint     select(uint falseValue, uint trueValue, bool test)      { return test ? trueValue : falseValue; }
    inline uint2    select(uint2 falseValue, uint2 trueValue, bool test)    { return test ? trueValue : falseValue; }
    inline uint3    select(uint3 falseValue, uint3 trueValue, bool test)    { return test ? trueValue : falseValue; }
    inline uint4    select(uint4 falseValue, uint4 trueValue, bool test)    { return test ? trueValue : falseValue; }
    inline uint2    select(uint2 falseValue, uint2 trueValue, bool2 test)   { return uint2(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y); }
    inline uint3    select(uint3 falseValue, uint3 trueValue, bool3 test)   { return uint3(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y, test.z ? trueValue.z : falseValue.z); }
    inline uint4    select(uint4 falseValue, uint4 trueValue, bool4 test)   { return uint4(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y, test.z ? trueValue.z : falseValue.z, test.w ? trueValue.w : falseValue.w); }
    inline uint64   select(uint64 falseValue, uint64 trueValue, bool test)  { return test ? trueValue : falseValue; }
    inline int      select(int falseValue, int trueValue, bool test)        { return test ? trueValue : falseValue; }
    inline int2     select(int2 falseValue, int2 trueValue, bool test)      { return test ? trueValue : falseValue; }
    inline int3     select(int3 falseValue, int3 trueValue, bool test)      { return test ? trueValue : falseValue; }
    inline int4     select(int4 falseValue, int4 trueValue, bool test)      { return test ? trueValue : falseValue; }
    inline int2     select(int2 falseValue, int2 trueValue, bool2 test)     { return int2(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y); }
    inline int3     select(int3 falseValue, int3 trueValue, bool3 test)     { return int3(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y, test.z ? trueValue.z : falseValue.z); }
    inline int4     select(int4 falseValue, int4 trueValue, bool4 test)     { return int4(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y, test.z ? trueValue.z : falseValue.z, test.w ? trueValue.w : falseValue.w); }
    inline int64    select(int64 falseValue, int64 trueValue, bool test)    { return test ? trueValue : falseValue; }
    inline float    select(float falseValue, float trueValue, bool test)    { return test ? trueValue : falseValue; }
    inline float2   select(float2 falseValue, float2 trueValue, bool test)  { return test ? trueValue : falseValue; }
    inline float3   select(float3 falseValue, float3 trueValue, bool test)  { return test ? trueValue : falseValue; }
    inline float4   select(float4 falseValue, float4 trueValue, bool test)  { return test ? trueValue : falseValue; }
    inline float2   select(float2 falseValue, float2 trueValue, bool2 test) { return float2(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y); }
    inline float3   select(float3 falseValue, float3 trueValue, bool3 test) { return float3(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y, test.z ? trueValue.z : falseValue.z); }
    inline float4   select(float4 falseValue, float4 trueValue, bool4 test) { return float4(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y, test.z ? trueValue.z : falseValue.z, test.w ? trueValue.w : falseValue.w); }
    inline double   select(double falseValue, double trueValue, bool test)  { return test ? trueValue : falseValue; }
    inline double2  select(double2 falseValue, double2 trueValue, bool test){ return test ? trueValue : falseValue; }
    inline double3  select(double3 falseValue, double3 trueValue, bool test){ return test ? trueValue : falseValue; }
    inline double4  select(double4 falseValue, double4 trueValue, bool test){ return test ? trueValue : falseValue; }
    inline double2  select(double2 falseValue, double2 trueValue, bool2 test){ return double2(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y); }
    inline double3  select(double3 falseValue, double3 trueValue, bool3 test){ return double3(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y, test.z ? trueValue.z : falseValue.z); }
    inline double4  select(double4 falseValue, double4 trueValue, bool4 test){ return double4(test.x ? trueValue.x : falseValue.x, test.y ? trueValue.y : falseValue.y, test.z ? trueValue.z : falseValue.z, test.w ? trueValue.w : falseValue.w); }


    // <summary>Returns the result of a componentwise step function where each component is 1.f when x &gt;= threshold and 0.f otherwise.</summary>
    // <param name="threshold">Vector of values to be used as a threshold for returning 1.</param>
    // <param name="x">Vector of values to compare against threshold.</param>
    // <returns>1 if the componentwise comparison x &gt;= threshold is true, otherwise 0.</returns>
    inline float    step(float threshold, float x)              { return select(0.f, 1.f, x >= threshold); }
    inline float2   step(float2 threshold, float2 x)            { return select(float2(0.f), float2(1.f), x >= threshold); }
    inline float3   step(float3 threshold, float3 x)            { return select(float3(0.f), float3(1.f), x >= threshold); }
    inline float4   step(float4 threshold, float4 x)            { return select(float4(0.f), float4(1.f), x >= threshold); }
    inline double   step(double threshold, double x)            { return select(0.0, 1.0, x >= threshold); }
    inline double2  step(double2 threshold, double2 x)          { return select(double2(0.0), double2(1.0), x >= threshold); }
    inline double3  step(double3 threshold, double3 x)          { return select(double3(0.0), double3(1.0), x >= threshold); }
    inline double4  step(double4 threshold, double4 x)          { return select(double4(0.0), double4(1.0), x >= threshold); }

    
    // <summary>Returns a normalized version of the vector x by scaling it by 1 / length(x).</summary>
    // <param name="x">Vector to normalize.</param>
    // <returns>The normalized vector.</returns>
    inline float2   normalize(float2 x)         { return rsqrt(dot(x, x)) * x; }
    inline float3   normalize(float3 x)         { return rsqrt(dot(x, x)) * x; }
    inline float4   normalize(float4 x)         { return rsqrt(dot(x, x)) * x; }
    inline double2  normalize(double2 x)        { return rsqrt(dot(x, x)) * x; }
    inline double3  normalize(double3 x)        { return rsqrt(dot(x, x)) * x; }
    inline double4  normalize(double4 x)        { return rsqrt(dot(x, x)) * x; }


    // <summary>
    // Returns a safe normalized version of the vector x by scaling it by 1 / length(x).
    // Returns the given default value when 1 / length(x) does not produce a finite number.
    // </summary>
    // <param name="x">Vector to normalize.</param>
    // <param name="defaultvalue">Vector to return if normalized vector is not finite.</param>
    // <returns>The normalized vector or the default value if the normalized vector is not finite.</returns>
    inline float2 normalizesafe(float2 x, float2 defaultvalue = float2::zero)
    {
        float len = math::dot(x, x);
        return math::select(defaultvalue, x * math::rsqrt(len), len > FLT_MIN_NORMAL);
    }
    inline float3 normalizesafe(float3 x, float3 defaultvalue = float3::zero)
    {
        float len = math::dot(x, x);
        return math::select(defaultvalue, x * math::rsqrt(len), len > FLT_MIN_NORMAL);
    }
    inline float4 normalizesafe(float4 x, float4 defaultvalue = float4::zero)
    {
        float len = math::dot(x, x);
        return math::select(defaultvalue, x * math::rsqrt(len), len > FLT_MIN_NORMAL);
    }
    inline double2 normalizesafe(double2 x, double2 defaultvalue = double2())
    {
        double len = math::dot(x, x);
        return math::select(defaultvalue, x * math::rsqrt(len), len > FLT_MIN_NORMAL);
    }
    inline double3 normalizesafe(double3 x, double3 defaultvalue = double3())
    {
        double len = math::dot(x, x);
        return math::select(defaultvalue, x * math::rsqrt(len), len > FLT_MIN_NORMAL);
    }
    inline double4 normalizesafe(double4 x, double4 defaultvalue = double4())
    {
        double len = math::dot(x, x);
        return math::select(defaultvalue, x * math::rsqrt(len), len > FLT_MIN_NORMAL);
    }

    // <summary>Given an incident vector i and a normal vector n, returns the reflection vector r = i - 2.f * dot(i, n) * n.</summary>
    // <param name="i">Incident vector.</param>
    // <param name="n">Normal vector.</param>
    // <returns>Reflection vector.</returns>
    inline float2   reflect(float2 i, float2 n)                 { return i - 2.f * n * dot(i, n); }
    inline float3   reflect(float3 i, float3 n)                 { return i - 2.f * n * dot(i, n); }
    inline float4   reflect(float4 i, float4 n)                 { return i - 2.f * n * dot(i, n); }
    inline double2  reflect(double2 i, double2 n)               { return i - 2.0 * n * dot(i, n); }
    inline double3  reflect(double3 i, double3 n)               { return i - 2.0 * n * dot(i, n); }
    inline double4  reflect(double4 i, double4 n)               { return i - 2.0 * n * dot(i, n); }


    // <summary>Returns the refraction vector given the incident vector i, the normal vector n and the refraction index.</summary>
    // <param name="i">Incident vector.</param>
    // <param name="n">Normal vector.</param>
    // <param name="indexOfRefraction">Index of refraction.</param>
    // <returns>Refraction vector.</returns>
    inline float2 refract(float2 i, float2 n, float indexOfRefraction)
    {
        float ni = dot(n, i);
        float k = 1.f - indexOfRefraction * indexOfRefraction * (1.f - ni * ni);
        return select(0.f, indexOfRefraction * i - (indexOfRefraction * ni + sqrt(k)) * n, k >= 0);
    }
    inline float3 refract(float3 i, float3 n, float indexOfRefraction)
    {
        float ni = dot(n, i);
        float k = 1.f - indexOfRefraction * indexOfRefraction * (1.f - ni * ni);
        return select(0.f, indexOfRefraction * i - (indexOfRefraction * ni + sqrt(k)) * n, k >= 0);
    }
    inline float4 refract(float4 i, float4 n, float indexOfRefraction)
    {
        float ni = dot(n, i);
        float k = 1.f - indexOfRefraction * indexOfRefraction * (1.f - ni * ni);
        return select(0.f, indexOfRefraction * i - (indexOfRefraction * ni + sqrt(k)) * n, k >= 0);
    }
    inline double2 refract(double2 i, double2 n, double indexOfRefraction)
    {
        double ni = dot(n, i);
        double k = 1.0 - indexOfRefraction * indexOfRefraction * (1.0 - ni * ni);
        return select(0.f, indexOfRefraction * i - (indexOfRefraction * ni + sqrt(k)) * n, k >= 0);
    }
    inline double3 refract(double3 i, double3 n, double indexOfRefraction)
    {
        double ni = dot(n, i);
        double k = 1.0 - indexOfRefraction * indexOfRefraction * (1.0 - ni * ni);
        return select(0.f, indexOfRefraction * i - (indexOfRefraction * ni + sqrt(k)) * n, k >= 0);
    }
    inline double4 refract(double4 i, double4 n, double indexOfRefraction)
    {
        double ni = dot(n, i);
        double k = 1.0 - indexOfRefraction * indexOfRefraction * (1.0 - ni * ni);
        return select(0.f, indexOfRefraction * i - (indexOfRefraction * ni + sqrt(k)) * n, k >= 0);
    }

        
    // <summary>
    // Compute vector projection of a onto b.
    // </summary>
    // <remarks>
    // Some finite vectors a and b could generate a non-finite result. This is most likely when a's components
    // are very large (close to Single.MaxValue) or when b's components are very small (close to FLT_MIN_NORMAL).
    // In these cases, you can call <see cref="projectsafe(Unity.Mathematics.float3,Unity.Mathematics.float3,Unity.Mathematics.float3)"/>
    // which will use a given default value if the result is not finite.
    // </remarks>
    // <param name="a">Vector to project.</param>
    // <param name="ontoB">Non-zero vector to project onto.</param>
    // <returns>Vector projection of a onto b.</returns>
    inline float2   project(float2 a, float2 ontoB)             {   return (dot(a, ontoB) / dot(ontoB, ontoB)) * ontoB;     }
    inline float3   project(float3 a, float3 ontoB)             {   return (dot(a, ontoB) / dot(ontoB, ontoB)) * ontoB;     }
    inline float4   project(float4 a, float4 ontoB)             {   return (dot(a, ontoB) / dot(ontoB, ontoB)) * ontoB;     }
    inline double2  project(double2 a, double2 ontoB)           {   return (dot(a, ontoB) / dot(ontoB, ontoB)) * ontoB;     }
    inline double3  project(double3 a, double3 ontoB)           {   return (dot(a, ontoB) / dot(ontoB, ontoB)) * ontoB;     }
    inline double4  project(double4 a, double4 ontoB)           {   return (dot(a, ontoB) / dot(ontoB, ontoB)) * ontoB;     }
        
    // <summary>
    // Compute vector projection of a onto b. If result is not finite, then return the default value instead.
    // </summary>
    // <remarks>
    // This function performs extra checks to see if the result of projecting a onto b is finite. If you know that
    // your inputs will generate a finite result or you don't care if the result is finite, then you can call
    // <see cref="project(Unity.Mathematics.float3,Unity.Mathematics.float3)"/> instead which is faster than this
    // function.
    // </remarks>
    // <param name="a">Vector to project.</param>
    // <param name="ontoB">Non-zero vector to project onto.</param>
    // <param name="defaultValue">Default value to return if projection is not finite.</param>
    // <returns>Vector projection of a onto b or the default value.</returns>
    inline float2 projectsafe(float2 a, float2 ontoB, float2 defaultValue = float2::zero)
    {
        auto proj = project(a, ontoB);
        return select(defaultValue, proj, all(isfinite(proj)));
    }
    inline float3 projectsafe(float3 a, float3 ontoB, float3 defaultValue = float3::zero)
    {
        auto proj = project(a, ontoB);
        return select(defaultValue, proj, all(isfinite(proj)));
    }
    inline float4 projectsafe(float4 a, float4 ontoB, float4 defaultValue = float4::zero)
    {
        auto proj = project(a, ontoB);
        return select(defaultValue, proj, all(isfinite(proj)));
    }
    inline double2 projectsafe(double2 a, double2 ontoB, double2 defaultValue = double2())
    {
        auto proj = project(a, ontoB);
        return select(defaultValue, proj, all(isfinite(proj)));
    }
    inline double3 projectsafe(double3 a, double3 ontoB, double3 defaultValue = double3())
    {
        auto proj = project(a, ontoB);
        return select(defaultValue, proj, all(isfinite(proj)));
    }
    inline double4 projectsafe(double4 a, double4 ontoB, double4 defaultValue = double4())
    {
        auto proj = project(a, ontoB);
        return select(defaultValue, proj, all(isfinite(proj)));
    }

    // <summary>Conditionally flips a vector n if two vectors i and ng are pointing in the same direction. Returns n if dot(i, ng) &lt; 0, -n otherwise.</summary>
    // <param name="n">Vector to conditionally flip.</param>
    // <param name="i">First vector in direction comparison.</param>
    // <param name="ng">Second vector in direction comparison.</param>
    // <returns>-n if i and ng point in the same direction; otherwise return n unchanged.</returns>
    inline float2   faceforward(float2 n, float2 i, float2 ng)          { return select(n, -n, dot(ng, i) >= 0.f); }
    inline float3   faceforward(float3 n, float3 i, float3 ng)          { return select(n, -n, dot(ng, i) >= 0.f); }
    inline float4   faceforward(float4 n, float4 i, float4 ng)          { return select(n, -n, dot(ng, i) >= 0.f); }
    inline double2  faceforward(double2 n, double2 i, double2 ng)       { return select(n, -n, dot(ng, i) >= 0.f); }
    inline double3  faceforward(double3 n, double3 i, double3 ng)       { return select(n, -n, dot(ng, i) >= 0.f); }
    inline double4  faceforward(double4 n, double4 i, double4 ng)       { return select(n, -n, dot(ng, i) >= 0.f); }


    // <summary>Returns the componentwise sine and cosine of the input vector x through the out parameters s and c.</summary>
    // <remarks>When Burst compiled, his method is faster than calling sin() and cos() separately.</remarks>
    // <param name="x">Input vector containing angles in radians.</param>
    // <param name="s">Output vector containing the componentwise sine of the input.</param>
    // <param name="c">Output vector containing the componentwise cosine of the input.</param>
    inline void     sincos(float x, OUT float& s, OUT float& c)         { s = sin(x); c = cos(x); }
    inline void     sincos(float2 x, OUT float2& s, OUT float2& c)      { s = sin(x); c = cos(x); }
    inline void     sincos(float3 x, OUT float3& s, OUT float3& c)      { s = sin(x); c = cos(x); }
    inline void     sincos(float4 x, OUT float4& s, OUT float4& c)      { s = sin(x); c = cos(x); }
    inline void     sincos(double x, OUT double& s, OUT double& c)      { s = sin(x); c = cos(x); }
    inline void     sincos(double2 x, OUT double2& s, OUT double2& c)   { s = sin(x); c = cos(x); }
    inline void     sincos(double3 x, OUT double3& s, OUT double3& c)   { s = sin(x); c = cos(x); }
    inline void     sincos(double4 x, OUT double4& s, OUT double4& c)   { s = sin(x); c = cos(x); }


    // <summary>Returns component-wise number of 1-bits in the binary representation of an vector. Also known as the Hamming weight, popcnt on x86, and vcnt on ARM.</summary>
    // <param name="x">int2 value in which to count bits for each component.</param>
    // <returns>int2 containing number of bits set to 1 within each component of x.</returns>
    inline int      countbits(uint x)
    {
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        return (int)((((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24);
    }
    inline int2     countbits(uint2 x)
    {
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        return int2((((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24);
    }
    inline int3     countbits(uint3 x)
    {
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        return int3((((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24);
    }
    inline int4     countbits(uint4 x)
    {
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        return int4((((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24);
    }
    inline int      countbits(uint64 x)
    {
        x = x - ((x >> 1) & 0x5555555555555555);
        x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
        return (int)((((x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F) * 0x0101010101010101) >> 56);
    }
    inline int      countbits(int x)                { return countbits((uint)x); }
    inline int2     countbits(int2 x)               { return countbits((uint2)x); }
    inline int3     countbits(int3 x)               { return countbits((uint3)x); }
    inline int4     countbits(int4 x)               { return countbits((uint4)x); }
    inline int      countbits(int64 x)              { return countbits((uint64)x); }

    union LongDoubleUnion
    {
        int64   longValue;
        double  doubleValue;
    };

    // <summary>Returns the componentwise number of leading zeros in the binary representations of an vector.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise number of leading zeros of the input.</returns>
    inline int      lzcnt(uint x)
    {
        if (x == 0)
            return 32;
        LongDoubleUnion u;
        u.doubleValue = 0.0;
        u.longValue = 0x4330000000000000L + x;
        u.doubleValue -= 4503599627370496.0;
        return 0x41E - (int)(u.longValue >> 52);
    }
    inline int2     lzcnt(uint2 x)                  { return int2(lzcnt(x.x), lzcnt(x.y)); }
    inline int3     lzcnt(uint3 x)                  { return int3(lzcnt(x.x), lzcnt(x.y), lzcnt(x.z)); }
    inline int4     lzcnt(uint4 x)                  { return int4(lzcnt(x.x), lzcnt(x.y), lzcnt(x.z), lzcnt(x.w)); }
    inline int      lzcnt(uint64 x)
    {
        if (x == 0)
            return 64;

        uint xh = (uint)(x >> 32);
        uint bits = xh != 0 ? xh : (uint)x;
        int offset = xh != 0 ? 0x41E : 0x43E;

        LongDoubleUnion u;
        u.doubleValue = 0.0;
        u.longValue = 0x4330000000000000L + bits;
        u.doubleValue -= 4503599627370496.0;
        return offset - (int)(u.longValue >> 52);
    }
    inline int      lzcnt(int x)                    { return lzcnt((uint)x); }
    inline int2     lzcnt(int2 x)                   { return int2(lzcnt(x.x), lzcnt(x.y)); }
    inline int3     lzcnt(int3 x)                   { return int3(lzcnt(x.x), lzcnt(x.y), lzcnt(x.z)); }
    inline int4     lzcnt(int4 x)                   { return int4(lzcnt(x.x), lzcnt(x.y), lzcnt(x.z), lzcnt(x.w)); }
    inline int      lzcnt(int64 x)                  { return lzcnt((uint64)x); }

    /// <summary>
    /// Computes the component-wise trailing zero count in the binary representation of the input value.
    /// </summary>
    /// <remarks>
    /// Assuming that the least significant bit is on the right, the integer value 4 has a binary representation
    /// 0100 and the trailing zero count is two. The integer value 1 has a binary representation 0001 and the
    /// trailing zero count is zero.
    /// </remarks>
    /// <param name="x">Input to use when computing the trailing zero count.</param>
    /// <returns>Returns the component-wise trailing zero count of the input.</returns>
    inline int      tzcnt(uint x)
    {
        if (x == 0)
            return 32;

        x &= unary_minus_operator(x);   //x &= (uint)-x;
        LongDoubleUnion u;
        u.doubleValue = 0.0;
        u.longValue = 0x4330000000000000L + x;
        u.doubleValue -= 4503599627370496.0;
        return (int)(u.longValue >> 52) - 0x3FF;
    }
    inline int2     tzcnt(uint2 x)                  { return int2(tzcnt(x.x), tzcnt(x.y)); }
    inline int3     tzcnt(uint3 x)                  { return int3(tzcnt(x.x), tzcnt(x.y), tzcnt(x.z)); }
    inline int4     tzcnt(uint4 x)                  { return int4(tzcnt(x.x), tzcnt(x.y), tzcnt(x.z), tzcnt(x.w)); }
    inline int      tzcnt(uint64 x)
    {
        if (x == 0)
            return 64;

        x = x & (uint64) - (int64)x;
        uint xl = (uint)x;

        uint bits = xl != 0 ? xl : (uint)(x >> 32);
        int offset = xl != 0 ? 0x3FF : 0x3DF;

        LongDoubleUnion u;
        u.doubleValue = 0.0;
        u.longValue = 0x4330000000000000L + bits;
        u.doubleValue -= 4503599627370496.0;
        return (int)(u.longValue >> 52) - offset;
    }
    inline int      tzcnt(int x)                    { return tzcnt((uint)x); }
    inline int2     tzcnt(int2 x)                   { return int2(tzcnt(x.x), tzcnt(x.y)); }
    inline int3     tzcnt(int3 x)                   { return int3(tzcnt(x.x), tzcnt(x.y), tzcnt(x.z)); }
    inline int4     tzcnt(int4 x)                   { return int4(tzcnt(x.x), tzcnt(x.y), tzcnt(x.z), tzcnt(x.w)); }
    inline int      tzcnt(int64 x)                  { return tzcnt((uint64)x); }

    // <summary>Returns the result of performing a componentwise reversal of the bit pattern of an vector.</summary>
    // <param name="x">Value to reverse.</param>
    // <returns>Value with componentwise reversed bits.</returns>
    inline uint     reversebits(uint x)
    {
        x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
        x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
        x = ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4);
        x = ((x >> 8) & 0x00FF00FF) | ((x & 0x00FF00FF) << 8);
        return (x >> 16) | (x << 16);
    }
    inline uint2    reversebits(uint2 x)
    {
        x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
        x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
        x = ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4);
        x = ((x >> 8) & 0x00FF00FF) | ((x & 0x00FF00FF) << 8);
        return (x >> 16) | (x << 16);
    }
    inline uint3    reversebits(uint3 x)
    {
        x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
        x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
        x = ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4);
        x = ((x >> 8) & 0x00FF00FF) | ((x & 0x00FF00FF) << 8);
        return (x >> 16) | (x << 16);
    }
    inline uint4    reversebits(uint4 x)
    {
        x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
        x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
        x = ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4);
        x = ((x >> 8) & 0x00FF00FF) | ((x & 0x00FF00FF) << 8);
        return (x >> 16) | (x << 16);
    }
    inline uint64   reversebits(uint64 x)
    {
        x = ((x >> 1) & 0x5555555555555555ul) | ((x & 0x5555555555555555ul) << 1);
        x = ((x >> 2) & 0x3333333333333333ul) | ((x & 0x3333333333333333ul) << 2);
        x = ((x >> 4) & 0x0F0F0F0F0F0F0F0Ful) | ((x & 0x0F0F0F0F0F0F0F0Ful) << 4);
        x = ((x >> 8) & 0x00FF00FF00FF00FFul) | ((x & 0x00FF00FF00FF00FFul) << 8);
        x = ((x >> 16) & 0x0000FFFF0000FFFFul) | ((x & 0x0000FFFF0000FFFFul) << 16);
        return (x >> 32) | (x << 32);
    }
    inline int      reversebits(int x)              { return (int)reversebits((uint)x); }
    inline int2     reversebits(int2 x)             { return (int2)reversebits((uint2)x); }
    inline int3     reversebits(int3 x)             { return (int3)reversebits((uint3)x); }
    inline int4     reversebits(int4 x)             { return (int4)reversebits((uint4)x); }
    inline int64    reversebits(int64 x)            { return (int64)reversebits((uint64)x); }

    /// <summary>Returns the componentwise result of rotating the bits of an left by bits n.</summary>
    /// <param name="x">Value to rotate.</param>
    /// <param name="n">Number of bits to rotate.</param>
    /// <returns>The componentwise rotated value.</returns>
    inline uint     rol(uint x, int n)              { return (x << n) | (x >> (32 - n)); }
    inline uint2    rol(uint2 x, int n)             { return (x << n) | (x >> (32 - n)); }
    inline uint3    rol(uint3 x, int n)             { return (x << n) | (x >> (32 - n)); }
    inline uint4    rol(uint4 x, int n)             { return (x << n) | (x >> (32 - n)); }
    inline uint64   rol(uint64 x, int n)            { return (x << n) | (x >> (64 - n)); }

    inline int      rol(int x, int n)               { return (int)rol((uint)x, n); }
    inline int2     rol(int2 x, int n)              { return (int2)rol((uint2)x, n); }
    inline int3     rol(int3 x, int n)              { return (int3)rol((uint3)x, n); }
    inline int4     rol(int4 x, int n)              { return (int4)rol((uint4)x, n); }
    inline int64    rol(int64 x, int n)             { return (int64)rol((uint64)x, n); }
  


    // <summary>Returns the componentwise result of rotating the bits of an right by bits n.</summary>
    // <param name="x">Value to rotate.</param>
    // <param name="n">Number of bits to rotate.</param>
    // <returns>The componentwise rotated value.</returns>
    inline uint     ror(uint x, int n)              { return (x >> n) | (x << (32 - n)); }
    inline uint2    ror(uint2 x, int n)             { return (x >> n) | (x << (32 - n)); }
    inline uint3    ror(uint3 x, int n)             { return (x >> n) | (x << (32 - n)); }
    inline uint4    ror(uint4 x, int n)             { return (x >> n) | (x << (32 - n)); }
    inline uint64   ror(uint64 x, int n)            { return (x >> n) | (x << (64 - n)); }

    inline int      ror(int x, int n)               { return (int)ror((uint)x, n); }
    inline int2     ror(int2 x, int n)              { return (int2)ror((uint2)x, n); }
    inline int3     ror(int3 x, int n)              { return (int3)ror((uint3)x, n); }
    inline int4     ror(int4 x, int n)              { return (int4)ror((uint4)x, n); }
    inline int64    ror(int64 x, int n)             { return (int64)ror((uint64)x, n); }

    // <summary>Returns the result of a componentwise calculation of the smallest power of two greater than or equal to the input.</summary>
    // <param name="x">Input value.</param>
    // <returns>The componentwise smallest power of two greater than or equal to the input.</returns>
    inline uint     ceilpow2(uint x)
    {
        x -= 1;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return x + 1;
    }
    inline uint2    ceilpow2(uint2 x)
    {
        x -= 1;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return x + 1;
    }
    inline uint3    ceilpow2(uint3 x)
    {
        x -= 1;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return x + 1;
    }
    inline uint4    ceilpow2(uint4 x)
    {
        x -= 1;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return x + 1;
    }
    inline uint64   ceilpow2(uint64 x)
    {
        x -= 1;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        x |= x >> 32;
        return x + 1;
    }
    inline int      ceilpow2(int x)
	{
		x -= 1;
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;
		return x + 1;
	}
    inline int2     ceilpow2(int2 x)
	{
		x -= 1;
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;
		return x + 1;
	}
    inline int3     ceilpow2(int3 x)
	{
		x -= 1;
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;
		return x + 1;
	}
    inline int4     ceilpow2(int4 x)
	{
		x -= 1;
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;
		return x + 1;
	}
    inline int64    ceilpow2(int64 x)
    {
        x -= 1;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        x |= x >> 32;
        return x + 1;
    }

    // <summary>Computes the componentwise ceiling of the base-2 logarithm of x.</summary>
    // <remarks>Components of x must be greater than 0, otherwise the result for that component is undefined.</remarks>
    // <param name="x">int2 to be used as input.</param>
    // <returns>Componentwise ceiling of the base-2 logarithm of x.</returns>
    inline int      ceillog2(uint x)                {   return 32 - lzcnt(x - 1);   }
    inline int2     ceillog2(uint2 x)               {   return int2(ceillog2(x.x), ceillog2(x.y));  }
    inline int3     ceillog2(uint3 x)               {   return int3(ceillog2(x.x), ceillog2(x.y), ceillog2(x.z));   }
    inline int4     ceillog2(uint4 x)               {   return int4(ceillog2(x.x), ceillog2(x.y), ceillog2(x.z), ceillog2(x.w));    }

    inline int      ceillog2(int x)                 {   return 32 - lzcnt((uint)x - 1);    }
    inline int2     ceillog2(int2 x)                {   return int2(ceillog2(x.x), ceillog2(x.y));  }
    inline int3     ceillog2(int3 x)                {   return int3(ceillog2(x.x), ceillog2(x.y), ceillog2(x.z));   }
    inline int4     ceillog2(int4 x)                {   return int4(ceillog2(x.x), ceillog2(x.y), ceillog2(x.z), ceillog2(x.w));    }
        
    // <summary>Computes the componentwise floor of the base-2 logarithm of x.</summary>
    // <remarks>Components of x must be greater than zero, otherwise the result of the component is undefined.</remarks>
    // <param name="x">int2 to be used as input.</param>
    // <returns>Componentwise floor of base-2 logarithm of x.</returns>
    inline int      floorlog2(uint x)               {   return 31 - lzcnt(x);   }
    inline int2     floorlog2(uint2 x)              {   return int2(floorlog2(x.x), floorlog2(x.y));    }
    inline int3     floorlog2(uint3 x)              {   return int3(floorlog2(x.x), floorlog2(x.y), floorlog2(x.z));    }
    inline int4     floorlog2(uint4 x)              {   return int4(floorlog2(x.x), floorlog2(x.y), floorlog2(x.z), floorlog2(x.w));    }

    inline int      floorlog2(int x)                {   return 31 - lzcnt((uint)x); }
    inline int2     floorlog2(int2 x)               {   return int2(floorlog2(x.x), floorlog2(x.y));    }
    inline int3     floorlog2(int3 x)               {   return int3(floorlog2(x.x), floorlog2(x.y), floorlog2(x.z));    }
    inline int4     floorlog2(int4 x)               {   return int4(floorlog2(x.x), floorlog2(x.y), floorlog2(x.z), floorlog2(x.w));    }

    // <summary>Returns the result of a componentwise conversion of a vector from degrees to radians.</summary>
    // <param name="x">Vector containing angles in degrees.</param>
    // <returns>Vector containing angles converted to radians.</returns>
    inline float    radians(float x)                { return x * TORADIANS; }
    inline float2   radians(float2 x)               { return x * TORADIANS; }
    inline float3   radians(float3 x)               { return x * TORADIANS; }
    inline float4   radians(float4 x)               { return x * TORADIANS; }
    inline double   radians(double x)               { return x * TORADIANS_DBL; }
    inline double2  radians(double2 x)              { return x * TORADIANS_DBL; }
    inline double3  radians(double3 x)              { return x * TORADIANS_DBL; }
    inline double4  radians(double4 x)              { return x * TORADIANS_DBL; }


    // <summary>Returns the result of a componentwise conversion of a vector from radians to degrees.</summary>
    // <param name="x">Vector containing angles in radians.</param>
    // <returns>Vector containing angles converted to degrees.</returns>
    inline float    degrees(float x)                { return x * TODEGREES; }
    inline float2   degrees(float2 x)               { return x * TODEGREES; }
    inline float3   degrees(float3 x)               { return x * TODEGREES; }
    inline float4   degrees(float4 x)               { return x * TODEGREES; }
    inline double   degrees(double x)               { return x * TODEGREES_DBL; }
    inline double2  degrees(double2 x)              { return x * TODEGREES_DBL; }
    inline double3  degrees(double3 x)              { return x * TODEGREES_DBL; }
    inline double4  degrees(double4 x)              { return x * TODEGREES_DBL; }


    // <summary>Returns the minimum component of an vector.</summary>
    // <param name="x">The vector to use when computing the minimum component.</param>
    // <returns>The value of the minimum component of the vector.</returns>
    inline uint     cmin(uint2 x)                   { return min(x.x, x.y); }
    inline uint     cmin(uint3 x)                   { return min(min(x.x, x.y), x.z); }
    inline uint     cmin(uint4 x)                   { return min(min(x.x, x.y), min(x.z, x.w)); }
    inline int      cmin(int2 x)                    { return min(x.x, x.y); }
    inline int      cmin(int3 x)                    { return min(min(x.x, x.y), x.z); }
    inline int      cmin(int4 x)                    { return min(min(x.x, x.y), min(x.z, x.w)); }
    inline float    cmin(float2 x)                  { return min(x.x, x.y); }
    inline float    cmin(float3 x)                  { return min(min(x.x, x.y), x.z); }
    inline float    cmin(float4 x)                  { return min(min(x.x, x.y), min(x.z, x.w)); }
    inline double   cmin(double2 x)                 { return min(x.x, x.y); }
    inline double   cmin(double3 x)                 { return min(min(x.x, x.y), x.z); }
    inline double   cmin(double4 x)                 { return min(min(x.x, x.y), min(x.z, x.w)); }

    // <summary>Returns the maximum component of an vector.</summary>
    // <param name="x">The vector to use when computing the maximum component.</param>
    // <returns>The value of the maximum component of the vector.</returns>
    inline uint     cmax(uint2 x)                   { return max(x.x, x.y); }
    inline uint     cmax(uint3 x)                   { return max(max(x.x, x.y), x.z); }
    inline uint     cmax(uint4 x)                   { return max(max(x.x, x.y), max(x.z, x.w)); }
    inline int      cmax(int2 x)                    { return max(x.x, x.y); }
    inline int      cmax(int3 x)                    { return max(max(x.x, x.y), x.z); }
    inline int      cmax(int4 x)                    { return max(max(x.x, x.y), max(x.z, x.w)); }
    inline float    cmax(float2 x)                  { return max(x.x, x.y); }
    inline float    cmax(float3 x)                  { return max(max(x.x, x.y), x.z); }
    inline float    cmax(float4 x)                  { return max(max(x.x, x.y), max(x.z, x.w)); }
    inline double   cmax(double2 x)                 { return max(x.x, x.y); }
    inline double   cmax(double3 x)                 { return max(max(x.x, x.y), x.z); }
    inline double   cmax(double4 x)                 { return max(max(x.x, x.y), max(x.z, x.w)); }


    // <summary>Returns the horizontal sum of components of an vector.</summary>
    // <param name="x">The vector to use when computing the horizontal sum.</param>
    // <returns>The horizontal sum of of components of the vector.</returns>
    inline uint     csum(uint2 x)                   { return x.x + x.y; }
    inline uint     csum(uint3 x)                   { return x.x + x.y + x.z; }
    inline uint     csum(uint4 x)                   { return x.x + x.y + x.z + x.w; }
    inline int      csum(int2 x)                    { return x.x + x.y; }
    inline int      csum(int3 x)                    { return x.x + x.y + x.z; }
    inline int      csum(int4 x)                    { return x.x + x.y + x.z + x.w; }
    inline float    csum(float2 x)                  { return x.x + x.y; }
    inline float    csum(float3 x)                  { return x.x + x.y + x.z; }
    inline float    csum(float4 x)                  { return (x.x + x.y) + (x.z + x.w); }
    inline double   csum(double2 x)                 { return x.x + x.y; }
    inline double   csum(double3 x)                 { return x.x + x.y + x.z; }
    inline double   csum(double4 x)                 { return (x.x + x.y) + (x.z + x.w); }

        
    // <summary>Computes the component-wise square (x * x) of the input argument x.</summary>
    // <param name="x">Value to square.</param>
    // <returns>Returns the square of the input.</returns>
    inline float    square(float x)                 { return x * x; }
    inline float2   square(float2 x)                { return x * x; }
    inline float3   square(float3 x)                { return x * x; }
    inline float4   square(float4 x)                { return x * x; }
    inline double   square(double x)                { return x * x; }
    inline double2  square(double2 x)               { return x * x; }
    inline double3  square(double3 x)               { return x * x; }
    inline double4  square(double4 x)               { return x * x; }

    // <summary>Computes the component-wise square (x * x) of the input argument x.</summary>
    /// <remarks>
    // Due to integer overflow, it's not always guaranteed that <c>square(x)</c> is positive. For example, <c>square(new int2(46341))</c>
    // will return <c>new int2(-2147479015)</c>.
    // </remarks>
    // <param name="x">Value to square.</param>
    // <returns>Returns the square of the input.</returns>
    inline uint     square(uint x)                  { return x * x; }
    inline uint2    square(uint2 x)                 { return x * x; }
    inline uint3    square(uint3 x)                 { return x * x; }
    inline uint4    square(uint4 x)                 { return x * x; }
    inline int      square(int x)                   { return x * x; }
    inline int2     square(int2 x)                  { return x * x; }
    inline int3     square(int3 x)                  { return x * x; }
    inline int4     square(int4 x)                  { return x * x; }

        
    // <summary>Packs components with an enabled mask to the left.</summary>
    // <remarks>
    // This function is also known as left packing. The effect of this function is to filter out components that
    // are not enabled and leave an output buffer tightly packed with only the enabled components. A common use
    // case is if you perform intersection tests on arrays of data in structure of arrays (SoA) form and need to
    // produce an output array of the things that intersected.
    // </remarks>
    // <param name="output">Pointer to packed output array where enabled components should be stored to.</param>
    // <param name="index">Index into output array where first enabled component should be stored to.</param>
    // <param name="val">The value to to compress.</param>
    // <param name="mask">Mask indicating which components are enabled.</param>
    // <returns>Index to element after the last one stored.</returns>
    inline int compress(int *output, int index, int4 val, bool4 mask)
    {
        if (mask.x)
            output[index++] = val.x;
        if (mask.y)
            output[index++] = val.y;
        if (mask.z)
            output[index++] = val.z;
        if (mask.w)
            output[index++] = val.w;

        return index;
    }
    inline int compress(uint *output, int index, uint4 val, bool4 mask)
    {
        return compress((int *)output, index, *(int4 *)&val, mask);
    }
    inline int compress(float* output, int index, float4 val, bool4 mask)
    {
        return compress((int *)output, index, *(int4 *)&val, mask);
    }
    /*
    // <summary>Returns the floating point representation of a half-precision floating point vector.</summary>
    // <param name="x">The half precision float vector.</param>
    // <returns>The single precision float vector representation of the half precision float vector.</returns>
    inline float f16tof32(uint x)
    {
        const uint shifted_exp = (0x7c00 << 13);
        uint uf = (x & 0x7fff) << 13;
        uint e = uf & shifted_exp;
        uf += (127 - 15) << 23;
        uf += select(0, (128u - 16u) << 23, e == shifted_exp);
        uf = select(uf, asuint(asfloat(uf + (1 << 23)) - 6.10351563e-05f), e == 0);
        uf |= (x & 0x8000) << 16;
        return asfloat(uf);
    }
    inline float2 f16tof32(uint2 x)
    {
        const uint shifted_exp = (0x7c00 << 13);
        uint2 uf = (x & 0x7fff) << 13;
        uint2 e = uf & shifted_exp;
        uf += (127 - 15) << 23;
        uf += select(0, (128u - 16u) << 23, e == shifted_exp);
        uf = select(uf, asuint(asfloat(uf + (1 << 23)) - 6.10351563e-05f), e == 0);
        uf |= (x & 0x8000) << 16;
        return asfloat(uf);
    }
    inline float3 f16tof32(uint3 x)
    {
        const uint shifted_exp = (0x7c00 << 13);
        uint3 uf = (x & 0x7fff) << 13;
        uint3 e = uf & shifted_exp;
        uf += (127 - 15) << 23;
        uf += select(0, (128u - 16u) << 23, e == shifted_exp);
        uf = select(uf, asuint(asfloat(uf + (1 << 23)) - 6.10351563e-05f), e == 0);
        uf |= (x & 0x8000) << 16;
        return asfloat(uf);
    }
    inline float4 f16tof32(uint4 x)
    {
        const uint shifted_exp = (0x7c00 << 13);
        uint4 uf = (x & 0x7fff) << 13;
        uint4 e = uf & shifted_exp;
        uf += (127 - 15) << 23;
        uf += select(0, (128u - 16u) << 23, e == shifted_exp);
        uf =  select(uf, asuint(asfloat(uf + (1 << 23)) - 6.10351563e-05f), e == 0);
        uf |= (x & 0x8000) << 16;
        return asfloat(uf);
    }

    // <summary>Returns the result of a componentwise conversion of a vector to its nearest half-precision floating point representation.</summary>
    // <param name="x">The single precision float vector.</param>
    // <returns>The half precision float vector representation of the single precision float vector.</returns>
    inline uint f32tof16(float x)
    {
        const int infinity_32 = 255 << 23;
        const uint msk = 0x7FFFF000u;

        uint ux = asuint(x);
        uint uux = ux & msk;
        uint h = (uint)(asuint(min(asfloat(uux) * 1.92592994e-34f, 260042752.0.f)) + 0x1000) >> 13; // Clamp to signed infinity if overflowed
        h = select(h, select(0x7c00u, 0x7e00u, (int)uux > infinity_32), (int)uux >= infinity_32);  // NaN->qNaN and Inf->Inf
        return h | (ux & ~msk) >> 16;
    }
    inline uint2 f32tof16(float2 x)
    {
        const int infinity_32 = 255 << 23;
        const uint msk = 0x7FFFF000u;

        uint2 ux = asuint(x);
        uint2 uux = ux & msk;
        uint2 h = (uint2)(asint(min(asfloat(uux) * 1.92592994e-34f, 260042752.0.f)) + 0x1000) >> 13; // Clamp to signed infinity if overflowed
        h = select(h, select(0x7c00u, 0x7e00u, (int2)uux > infinity_32), (int2)uux >= infinity_32); // NaN->qNaN and Inf->Inf
        return h | (ux & ~msk) >> 16;
    }
    inline uint3 f32tof16(float3 x)
    {
        const int infinity_32 = 255 << 23;
        const uint msk = 0x7FFFF000u;

        uint3 ux = asuint(x);
        uint3 uux = ux & msk;
        uint3 h = (uint3)(asint(min(asfloat(uux) * 1.92592994e-34f, 260042752.0.f)) + 0x1000) >> 13; // Clamp to signed infinity if overflowed
        h = select(h, select(0x7c00u, 0x7e00u, (int3)uux > infinity_32), (int3)uux >= infinity_32); // NaN->qNaN and Inf->Inf
        return h | (ux & ~msk) >> 16;
    }
    inline uint4 f32tof16(float4 x)
    {
        const int infinity_32 = 255 << 23;
        const uint msk = 0x7FFFF000u;

        uint4 ux = asuint(x);
        uint4 uux = ux & msk;
        uint4 h = (uint4)(asint(min(asfloat(uux) * 1.92592994e-34f, 260042752.0.f)) + 0x1000) >> 13; // Clamp to signed infinity if overflowed
        h = select(h, select(0x7c00u, 0x7e00u, (int4)uux > infinity_32), (int4)uux >= infinity_32); // NaN->qNaN and Inf->Inf
        return h | (ux & ~msk) >> 16;
    }
    */
    // <summary>Generate an orthonormal basis given a single unit length normal vector.</summary>
    // <remarks>
    // This implementation is from "Building an Orthonormal Basis, Revisited"
    // https://graphics.pixar.com/library/OrthonormalB/paper.pdf
    // </remarks>
    // <param name="normal">Unit length normal vector.</param>
    // <param name="basis1">Output unit length vector, orthogonal to normal vector.</param>
    // <param name="basis2">Output unit length vector, orthogonal to normal vector and basis1.</param>
    inline void orthonormal_basis(float3 normal, OUT float3& basis1, OUT float3& basis2)
    {
        auto sign = normal.z >= 0.f ? 1.f : -1.f;
        auto a = -1.f / (sign + normal.z);
        auto b = normal.x * normal.y * a;
        basis1.x = 1.f + sign * normal.x * normal.x * a;
        basis1.y = sign * b;
        basis1.z = -sign * normal.x;
        basis2.x = b;
        basis2.y = sign + normal.y * normal.y * a;
        basis2.z = -normal.y;
    }
    inline void orthonormal_basis(double3 normal, OUT double3& basis1, OUT double3& basis2)
    {
        auto sign = normal.z >= 0.0 ? 1.0 : -1.0;
        auto a = -1.0 / (sign + normal.z);
        auto b = normal.x * normal.y * a;
        basis1.x = 1.0 + sign * normal.x * normal.x * a;
        basis1.y = sign * b;
        basis1.z = -sign * normal.x;
        basis2.x = b;
        basis2.y = sign + normal.y * normal.y * a;
        basis2.z = -normal.y;
    }

    // <summary>Change the sign of components of x based on the most significant bit of components of y [msb(y) ? -x : x].</summary>
    // <param name="x">The single precision float vector to change the sign.</param>
    // <param name="y">The single precision float vector used to test the most significant bit.</param>
    // <returns>Returns vector x with changed sign based on vector y.</returns>
    inline float    chgsign(float x, float y)           {   return asfloat(asuint(x) ^ (asuint(y) & 0x80000000));   }
    inline float2   chgsign(float2 x, float2 y)         {   return asfloat(asuint(x) ^ (asuint(y) & 0x80000000));   }
    inline float3   chgsign(float3 x, float3 y)         {   return asfloat(asuint(x) ^ (asuint(y) & 0x80000000));   }
    inline float4   chgsign(float4 x, float4 y)         {   return asfloat(asuint(x) ^ (asuint(y) & 0x80000000));   }

    // <summary>Returns a uint hash from a block of memory using the xxhash32 algorithm. Can only be used in an unsafe context.</summary>
    // <param name="pBuffer">A pointer to the beginning of the data.</param>
    // <param name="numBytes">Number of bytes to hash.</param>
    // <param name="seed">Starting seed value.</param>
    // <returns>The 32 bit hash of the input data buffer.</returns>
    inline uint     hash(void *pBuffer, int numBytes, uint seed = 0)
    {
        //unchecked
        {
            const uint Prime1 = 2654435761;
            const uint Prime2 = 2246822519;
            const uint Prime3 = 3266489917;
            const uint Prime4 = 668265263;
            const uint Prime5 = 374761393;

            uint4 *p = (uint4 *)pBuffer;
            uint hash = seed + Prime5;
            if (numBytes >= 16)
            {
                //uint4 state = uint4(Prime1 + Prime2, Prime2, 0, (uint)-Prime1) + seed;
                uint4 state = uint4(Prime1 + Prime2, Prime2, 0, unary_minus_operator(Prime1)) + seed;

                int count = numBytes >> 4;
                for (int i = 0; i < count; ++i)
                {
                    state += *p++ * Prime2;
                    state = (state << 13) | (state >> 19);
                    state *= Prime1;
                }

                hash = rol(state.x, 1) + rol(state.y, 7) + rol(state.z, 12) + rol(state.w, 18);
            }

            hash += (uint)numBytes;

            uint *puint = (uint *)p;
            for (int i = 0; i < ((numBytes >> 2) & 3); ++i)
            {
                hash += *puint++ * Prime3;
                hash = rol(hash, 17) * Prime4;
            }

            byte *pbyte = (byte *)puint;
            for (int i = 0; i < ((numBytes)&3); ++i)
            {
                hash += (*pbyte++) * Prime5;
                hash = rol(hash, 11) * Prime1;
            }

            hash ^= hash >> 15;
            hash *= Prime2;
            hash ^= hash >> 13;
            hash *= Prime3;
            hash ^= hash >> 16;

            return hash;
        }
    }

    // <summary>Unity's up axis (0, 1, 0).</summary>
    // <remarks>Matches [https://docs.unity3d.com/ScriptReference/Vector3-up.html](https://docs.unity3d.com/ScriptReference/Vector3-up.html)</remarks>
    // <returns>The up axis.</returns>
    inline float3   up()            { return float3(0.f, 1.f, 0.f); }  // for compatibility
    
    // <summary>Unity's down axis (0, -1, 0).</summary>
    // <remarks>Matches [https://docs.unity3d.com/ScriptReference/Vector3-down.html](https://docs.unity3d.com/ScriptReference/Vector3-down.html)</remarks>
    // <returns>The down axis.</returns>
    inline float3   down()          { return float3(0.f, -1.f, 0.f); }

    // <summary>Unity's forward axis (0, 0, 1).</summary>
    // <remarks>Matches [https://docs.unity3d.com/ScriptReference/Vector3-forward.html](https://docs.unity3d.com/ScriptReference/Vector3-forward.html)</remarks>
    // <returns>The forward axis.</returns>
    inline float3   forward()       { return float3(0.f, 0.f, 1.f); }
    
    // <summary>Unity's back axis (0, 0, -1).</summary>
    // <remarks>Matches [https://docs.unity3d.com/ScriptReference/Vector3-back.html](https://docs.unity3d.com/ScriptReference/Vector3-back.html)</remarks>
    // <returns>The back axis.</returns>
    inline float3   back()          { return float3(0.f, 0.f, -1.f); }

        
    // <summary>Unity's left axis (-1, 0, 0).</summary>
    // <remarks>Matches [https://docs.unity3d.com/ScriptReference/Vector3-left.html](https://docs.unity3d.com/ScriptReference/Vector3-left.html)</remarks>
    // <returns>The left axis.</returns>
    inline float3   left()          { return float3(-1.f, 0.f, 0.f); }

        
    // <summary>Unity's right axis (1, 0, 0). </summary>       
    // <remarks>Matches [https://docs.unity3d.com/ScriptReference/Vector3-right.html](https://docs.unity3d.com/ScriptReference/Vector3-right.html)</remarks>
    // <returns>The right axis.</returns>
    inline float3   right()         { return float3(1.f, 0.f, 0.f); }

    // <summary>
    // Returns the Euler angle representation of the quaternion following the XYZ rotation order.
    // All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
    // </summary>
    // <param name="q">The quaternion to convert to Euler angles.</param>
    // <returns>The Euler angle representation of the quaternion in XYZ order.</returns>
    inline float3   EulerXYZ(quaternion q)
    {
        const float epsilon = 1e-6f;
        const float cutoff = (1.f - 2.f * epsilon) * (1.f - 2.f * epsilon);

        // prepare the data
        auto qv = q.value;
        auto d1 = qv * qv.wwww() * float4(2.f); //xw, yw, zw, ww
        auto d2 = qv * qv.yzxw() * float4(2.f); //xy, yz, zx, ww
        auto d3 = qv * qv;
        auto euler = float3::zero;

        auto y1 = d2.z - d1.y;
        if (y1 * y1 < cutoff)
        {
            auto x1 = d2.y + d1.x;
            auto x2 = d3.z + d3.w - d3.y - d3.x;
            auto z1 = d2.x + d1.z;
            auto z2 = d3.x + d3.w - d3.y - d3.z;
            euler = float3(atan2(x1, x2), -asin(y1), atan2(z1, z2));
        }
        else //xzx
        {
            y1 = clamp(y1, -1.f, 1.f);
            auto abcd = float4(d2.z, d1.y, d2.x, d1.z);
            auto x1 = 2.f * (abcd.x * abcd.w + abcd.y * abcd.z); //2(ad+bc)
            auto x2 = csum(abcd * abcd * float4(-1.f, 1.f, -1.f, 1.f));
            euler = float3(atan2(x1, x2), -asin(y1), 0.f);
        }

        return euler;
    }

        
    // <summary>
    // Returns the Euler angle representation of the quaternion following the XZY rotation order.
    // All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
    // </summary>
    // <param name="q">The quaternion to convert to Euler angles.</param>
    // <returns>The Euler angle representation of the quaternion in XZY order.</returns>
    inline float3 EulerXZY(quaternion q)
    {
        const float epsilon = 1e-6f;
        const float cutoff = (1.f - 2.f * epsilon) * (1.f - 2.f * epsilon);

        // prepare the data
        auto qv = q.value;
        auto d1 = qv * qv.wwww() * float4(2.f); //xw, yw, zw, ww
        auto d2 = qv * qv.yzxw() * float4(2.f); //xy, yz, zx, ww
        auto d3 = qv * qv;
        auto euler = float3::zero;

        auto y1 = d2.x + d1.z;
        if (y1 * y1 < cutoff)
        {
            auto x1 = -d2.y + d1.x;
            auto x2 = d3.y + d3.w - d3.z - d3.x;
            auto z1 = -d2.z + d1.y;
            auto z2 = d3.x + d3.w - d3.y - d3.z;
            euler = float3(atan2(x1, x2), asin(y1), atan2(z1, z2));
        }
        else //xyx
        {
            y1 = clamp(y1, -1.f, 1.f);
            auto abcd = float4(d2.x, d1.z, d2.z, d1.y);
            auto x1 = 2.f * (abcd.x * abcd.w + abcd.y * abcd.z); //2(ad+bc)
            auto x2 = csum(abcd * abcd * float4(-1.f, 1.f, -1.f, 1.f));
            euler = float3(atan2(x1, x2), asin(y1), 0.f);
        }

        return euler.xzy();
    }

        
    // <summary>
    // Returns the Euler angle representation of the quaternion following the YXZ rotation order.
    // All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
    // </summary>
    // <param name="q">The quaternion to convert to Euler angles.</param>
    // <returns>The Euler angle representation of the quaternion in YXZ order.</returns>
    inline float3 EulerYXZ(quaternion q)
    {
        const float epsilon = 1e-6f;
        const float cutoff = (1.f - 2.f * epsilon) * (1.f - 2.f * epsilon);

        // prepare the data
        auto qv = q.value;
        auto d1 = qv * qv.wwww() * float4(2.f); //xw, yw, zw, ww
        auto d2 = qv * qv.yzxw() * float4(2.f); //xy, yz, zx, ww
        auto d3 = qv * qv;
        auto euler = float3::zero;

        auto y1 = d2.y + d1.x;
        if (y1 * y1 < cutoff)
        {
            auto x1 = -d2.z + d1.y;
            auto x2 = d3.z + d3.w - d3.x - d3.y;
            auto z1 = -d2.x + d1.z;
            auto z2 = d3.y + d3.w - d3.z - d3.x;
            euler = float3(atan2(x1, x2), asin(y1), atan2(z1, z2));
        }
        else //yzy
        {
            y1 = clamp(y1, -1.f, 1.f);
            auto abcd = float4(d2.x, d1.z, d2.y, d1.x);
            auto x1 = 2.f * (abcd.x * abcd.w + abcd.y * abcd.z); //2(ad+bc)
            auto x2 = csum(abcd * abcd * float4(-1.f, 1.f, -1.f, 1.f));
            euler = float3(atan2(x1, x2), asin(y1), 0.f);
        }

        return euler.yxz();
    }

    
    // <summary>
    // Returns the Euler angle representation of the quaternion following the YZX rotation order.
    // All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
    // </summary>
    // <param name="q">The quaternion to convert to Euler angles.</param>
    // <returns>The Euler angle representation of the quaternion in YZX order.</returns>
    inline float3 EulerYZX(quaternion q)
    {
        const float epsilon = 1e-6f;
        const float cutoff = (1.f - 2.f * epsilon) * (1.f - 2.f * epsilon);

        // prepare the data
        auto qv = q.value;
        auto d1 = qv * qv.wwww() * float4(2.f); //xw, yw, zw, ww
        auto d2 = qv * qv.yzxw() * float4(2.f); //xy, yz, zx, ww
        auto d3 = qv * qv;
        auto euler = float3::zero;

        auto y1 = d2.x - d1.z;
        if (y1 * y1 < cutoff)
        {
            auto x1 = d2.z + d1.y;
            auto x2 = d3.x + d3.w - d3.z - d3.y;
            auto z1 = d2.y + d1.x;
            auto z2 = d3.y + d3.w - d3.x - d3.z;
            euler = float3(atan2(x1, x2), -asin(y1), atan2(z1, z2));
        }
        else //yxy
        {
            y1 = clamp(y1, -1.f, 1.f);
            auto abcd = float4(d2.x, d1.z, d2.y, d1.x);
            auto x1 = 2.f * (abcd.x * abcd.w + abcd.y * abcd.z); //2(ad+bc)
            auto x2 = csum(abcd * abcd * float4(-1.f, 1.f, -1.f, 1.f));
            euler = float3(atan2(x1, x2), -asin(y1), 0.f);
        }

        return euler.zxy();
    }

    
    // Returns the Euler angle representation of the quaternion following the ZXY rotation order.
    // All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
    
    // <param name="q">The quaternion to convert to Euler angles.</param>
    // <returns>The Euler angle representation of the quaternion in ZXY order.</returns>
    
    inline float3 EulerZXY(quaternion q)
    {
        const float epsilon = 1e-6f;
        const float cutoff = (1.f - 2.f * epsilon) * (1.f - 2.f * epsilon);

        // prepare the data
        auto qv = q.value;
        auto d1 = qv * qv.wwww() * float4(2.f); //xw, yw, zw, ww
        auto d2 = qv * qv.yzxw() * float4(2.f); //xy, yz, zx, ww
        auto d3 = qv * qv;
        auto euler = float3::zero;

        auto y1 = d2.y - d1.x;
        if (y1 * y1 < cutoff)
        {
            auto x1 = d2.x + d1.z;
            auto x2 = d3.y + d3.w - d3.x - d3.z;
            auto z1 = d2.z + d1.y;
            auto z2 = d3.z + d3.w - d3.x - d3.y;
            euler = float3(atan2(x1, x2), -asin(y1), atan2(z1, z2));
        }
        else //zxz
        {
            y1 = clamp(y1, -1.f, 1.f);
            auto abcd = float4(d2.z, d1.y, d2.y, d1.x);
            auto x1 = 2.f * (abcd.x * abcd.w + abcd.y * abcd.z); //2(ad+bc)
            auto x2 = csum(abcd * abcd * float4(-1.f, 1.f, -1.f, 1.f));
            euler = float3(atan2(x1, x2), -asin(y1), 0.f);
        }

        return euler.yzx();
    }

    
    // <summary>
    // Returns the Euler angle representation of the quaternion following the ZYX rotation order.
    // All rotation angles are in radians and clockwise when looking along the rotation axis towards the origin.
    // </summary>
    // <param name="q">The quaternion to convert to Euler angles.</param>
    // <returns>The Euler angle representation of the quaternion in ZYX order.</returns>    
    inline float3 EulerZYX(quaternion q)
    {
        const float epsilon = 1e-6f;
        const float cutoff = (1.f - 2.f * epsilon) * (1.f - 2.f * epsilon);

        auto qv = q.value;
        auto d1 = qv * qv.wwww() * float4(2.f); //xw, yw, zw, ww
        auto d2 = qv * qv.yzxw() * float4(2.f); //xy, yz, zx, ww
        auto d3 = qv * qv;
        auto euler = float3::zero;

        auto y1 = d2.z + d1.y;
        if (y1 * y1 < cutoff)
        {
            auto x1 = -d2.x + d1.z;
            auto x2 = d3.x + d3.w - d3.y - d3.z;
            auto z1 = -d2.y + d1.x;
            auto z2 = d3.z + d3.w - d3.y - d3.x;
            euler = float3(atan2(x1, x2), asin(y1), atan2(z1, z2));
        }
        else //zxz
        {
            y1 = clamp(y1, -1.f, 1.f);
            auto abcd = float4(d2.z, d1.y, d2.y, d1.x);
            auto x1 = 2.f * (abcd.x * abcd.w + abcd.y * abcd.z); //2(ad+bc)
            auto x2 = csum(abcd * abcd * float4(-1.f, 1.f, -1.f, 1.f));
            euler = float3(atan2(x1, x2), asin(y1), 0.f);
        }

        return euler.zyx();
    }

    
    // <summary>
    // Returns the Euler angle representation of the quaternion. The returned angles depend on the specified order to apply the
    // three rotations around the principal axes. All rotation angles are in radians and clockwise when looking along the
    // rotation axis towards the origin.
    // When the rotation order is known at compile time, to get the best performance you should use the specific
    // Euler rotation constructors such as EulerZXY(...).
    // </summary>
    // <param name="q">The quaternion to convert to Euler angles.</param>
    // <param name="order">The order in which the rotations are applied.</param>
    // <returns>The Euler angle representation of the quaternion in the specified order.</returns>    
    inline float3 Euler(quaternion q, RotationOrder order = RotationOrder::Default)
    {
        switch (order)
        {
            case RotationOrder::XYZ:
                return EulerXYZ(q);
            case RotationOrder::XZY:
                return EulerXZY(q);
            case RotationOrder::YXZ:
                return EulerYXZ(q);
            case RotationOrder::YZX:
                return EulerYZX(q);
            case RotationOrder::ZXY:
                return EulerZXY(q);
            case RotationOrder::ZYX:
                return EulerZYX(q);
            default:
                return float3::zero;
        }
    }

        
    // <summary>
    // Matrix columns multiplied by scale components
    // m.c0.x * s.x | m.c1.x * s.y | m.c2.x * s.z
    // m.c0.y * s.x | m.c1.y * s.y | m.c2.y * s.z
    // m.c0.z * s.x | m.c1.z * s.y | m.c2.z * s.z
    // </summary>
    // <param name="m">Matrix to scale.</param>
    // <param name="s">Scaling coefficients for each column.</param>
    // <returns>The scaled matrix.</returns>    
    inline float3x3 mulScale(float3x3 m, float3 s) { return float3x3(m.c0 * s.x, m.c1 * s.y, m.c2 * s.z); }

    
    // <summary>
    // Matrix rows multiplied by scale components
    // m.c0.x * s.x | m.c1.x * s.x | m.c2.x * s.x
    // m.c0.y * s.y | m.c1.y * s.y | m.c2.y * s.y
    // m.c0.z * s.z | m.c1.z * s.z | m.c2.z * s.z
    // </summary>
    // <param name="s">Scaling coefficients for each row.</param>
    // <param name="m">Matrix to scale.</param>
    // <returns>The scaled matrix.</returns>
    inline float3x3 scaleMul(float3 s, float3x3 m) { return float3x3(m.c0 * s, m.c1 * s, m.c2 * s); }


    //===================================================================
    // Internal
    //===================================================================
    // SSE shuffles
    inline float4 unpacklo(float4 a, float4 b)
    {
        return shuffle(a, b, ShuffleComponent::LeftX, ShuffleComponent::RightX, ShuffleComponent::LeftY, ShuffleComponent::RightY);
    }
    
    inline double4 unpacklo(double4 a, double4 b)
    {
        return shuffle(a, b, ShuffleComponent::LeftX, ShuffleComponent::RightX, ShuffleComponent::LeftY, ShuffleComponent::RightY);
    }
        
    inline float4 unpackhi(float4 a, float4 b)
    {
        return shuffle(a, b, ShuffleComponent::LeftZ, ShuffleComponent::RightZ, ShuffleComponent::LeftW, ShuffleComponent::RightW);
    }
        
    inline double4 unpackhi(double4 a, double4 b)
    {
        return shuffle(a, b, ShuffleComponent::LeftZ, ShuffleComponent::RightZ, ShuffleComponent::LeftW, ShuffleComponent::RightW);
    }
        
    inline float4 movelh(float4 a, float4 b)
    {
        return shuffle(a, b, ShuffleComponent::LeftX, ShuffleComponent::LeftY, ShuffleComponent::RightX, ShuffleComponent::RightY);
    }
    
    inline double4 movelh(double4 a, double4 b)
    {
        return shuffle(a, b, ShuffleComponent::LeftX, ShuffleComponent::LeftY, ShuffleComponent::RightX, ShuffleComponent::RightY);
    }
    
    inline float4 movehl(float4 a, float4 b)
    {
        return shuffle(b, a, ShuffleComponent::LeftZ, ShuffleComponent::LeftW, ShuffleComponent::RightZ, ShuffleComponent::RightW);
    }
    
    inline double4 movehl(double4 a, double4 b)
    {
        return shuffle(b, a, ShuffleComponent::LeftZ, ShuffleComponent::LeftW, ShuffleComponent::RightZ, ShuffleComponent::RightW);
    }
        
    inline uint fold_to_uint(double x)  // utility for double hashing
    {
        LongDoubleUnion u;
        u.longValue     = 0;
        u.doubleValue   = x;
        return (uint)(u.longValue >> 32) ^ (uint)u.longValue;
    }

    
    inline uint2 fold_to_uint(double2 x) { return uint2(fold_to_uint(x.x), fold_to_uint(x.y)); }
    
    inline uint3 fold_to_uint(double3 x) { return uint3(fold_to_uint(x.x), fold_to_uint(x.y), fold_to_uint(x.z)); }
    
    inline uint4 fold_to_uint(double4 x) { return uint4(fold_to_uint(x.x), fold_to_uint(x.y), fold_to_uint(x.z), fold_to_uint(x.w)); }


}
} // namespace ecs