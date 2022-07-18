#pragma once

//=============================================================================
// TYPEDEFS
//=============================================================================
typedef		  unsigned int	uint;
typedef		  uint64_t		uint64;
typedef		  int64_t		int64;

typedef	unsigned long long  UInt64;
typedef   signed long long  Int64;
typedef		  unsigned int	UInt32;
typedef			signed int  Int32;
typedef unsigned short int  UInt16;
typedef   signed short int  Int16;
typedef       unsigned char UInt8;
typedef         signed char Int8;

typedef       unsigned char BYTE;
typedef		  std::wstring	String;


//=============================================================================
// FORWARD
//=============================================================================
namespace ecs
{
	struct	bool2;
	struct	bool2x2;
	struct	bool2x3;
	struct	bool2x4;

	struct	bool3;
	struct	bool3x2;
	struct	bool3x3;
	struct	bool3x4;

	struct	bool4;
	struct	bool4x2;
	struct	bool4x3;
	struct	bool4x4;

	struct	uint2;
	struct	uint2x2;
	struct	uint2x3;
	struct	uint2x4;

	struct	uint3;
	struct	uint3x2;
	struct	uint3x3;
	struct	uint3x4;

	struct	uint4;
	struct	uint4x2;
	struct	uint4x3;
	struct	uint4x4;

	struct	int2;
	struct	int2x2;
	struct	int2x3;
	struct	int2x4;

	struct	int3;
	struct	int3x2;
	struct	int3x3;
	struct	int3x4;

	struct	int4;
	struct	int4x2;
	struct	int4x3;
	struct	int4x4;

	struct	float2;
	struct	float2x2;
	struct	float2x3;
	struct	float2x4;

	struct	float3;
	struct	float3x2;
	struct	float3x3;
	struct	float3x4;

	struct	float4;
	struct	float4x2;
	struct	float4x3;
	struct	float4x4;

	struct	double2;
	struct	double2x2;
	struct	double2x3;
	struct	double2x4;

	struct	double3;
	struct	double3x2;
	struct	double3x3;
	struct	double3x4;

	struct	double4;
	struct	double4x2;
	struct	double4x3;
	struct	double4x4;

	struct	quaternion;
	struct	AffineTransform;
	struct	RigidTransform;

	struct	MinMaxAABB;
	struct	Plane;
};


namespace ecs
{
	

	class CWorld;
	class CSystemBase;
	class CEntityManager;

	typedef std::shared_ptr<CSystemBase>		SystemBaseSharedPtr;
	typedef std::weak_ptr<CSystemBase>			SystemBaseWeakPtr;
}