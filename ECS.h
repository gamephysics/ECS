#pragma once

#define NOMINMAX

//=========================================================
// STANDARD
//=========================================================
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include <atomic>
#include <set>
#include <limits>
#include <queue>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <bitset>
#include <string>
#include <functional>
#include <sstream>
#include <random>
#include <regex>
#include <tuple>
#include <iterator>
#include <fstream>
#include <numeric>
#include <cmath>
#include <cctype>
#include <shared_mutex>
#include <codecvt>
#include <format>

#include <stddef.h>
#include <fcntl.h>
#include <io.h>
#include <cwctype>
#include <any>
#include <type_traits>

#include <strsafe.h>
#include <string.h>
#include <atlbase.h>
#include <atlconv.h>
#include <concrt.h>

#include <filesystem>

// Performance Data Helper
#include <psapi.h>
#include <pdh.h>

// mini Dumper
#include <Windows.h>
#include <dbghelp.h>
#include <signal.h>
#include <strsafe.h>
#include <direct.h>

//	Memory Leak
#include <crtdbg.h>
#include <csignal>

//=========================================================
// ENTT (Entity Component System)
// https://github.com/skypjack/entt
//=========================================================
#include "entt/entt.hpp"

//=========================================================
// ECS
//=========================================================
#include "ECS/ECSTypeDef.h"

#include "ECS/Math/ECSMath.h"
#include "ECS/Math/ECSMath_sdv.h"

//======= VECTOR =======
#include "ECS/Math/ECSMath_bool2.h"
#include "ECS/Math/ECSMath_bool2x2.h"
#include "ECS/Math/ECSMath_bool2x3.h"
#include "ECS/Math/ECSMath_bool2x4.h"

#include "ECS/Math/ECSMath_uint2.h"
#include "ECS/Math/ECSMath_uint2x2.h"
#include "ECS/Math/ECSMath_uint2x3.h"
#include "ECS/Math/ECSMath_uint2x4.h"

#include "ECS/Math/ECSMath_int2.h"
#include "ECS/Math/ECSMath_int2x2.h"
#include "ECS/Math/ECSMath_int2x3.h"
#include "ECS/Math/ECSMath_int2x4.h"

#include "ECS/Math/ECSMath_float2.h"
#include "ECS/Math/ECSMath_float2x2.h"
#include "ECS/Math/ECSMath_float2x3.h"
#include "ECS/Math/ECSMath_float2x4.h"

#include "ECS/Math/ECSMath_double2.h"
#include "ECS/Math/ECSMath_double2x2.h"
#include "ECS/Math/ECSMath_double2x3.h"
#include "ECS/Math/ECSMath_double2x4.h"

#include "ECS/Math/ECSMath_bool3.h"
#include "ECS/Math/ECSMath_bool3x2.h"
#include "ECS/Math/ECSMath_bool3x3.h"
#include "ECS/Math/ECSMath_bool3x4.h"

#include "ECS/Math/ECSMath_uint3.h"
#include "ECS/Math/ECSMath_uint3x2.h"
#include "ECS/Math/ECSMath_uint3x3.h"
#include "ECS/Math/ECSMath_uint3x4.h"

#include "ECS/Math/ECSMath_int3.h"
#include "ECS/Math/ECSMath_int3x2.h"
#include "ECS/Math/ECSMath_int3x3.h"
#include "ECS/Math/ECSMath_int3x4.h"

#include "ECS/Math/ECSMath_float3.h"
#include "ECS/Math/ECSMath_float3x2.h"
#include "ECS/Math/ECSMath_float3x3.h"
#include "ECS/Math/ECSMath_float3x4.h"

#include "ECS/Math/ECSMath_double3.h"
#include "ECS/Math/ECSMath_double3x2.h"
#include "ECS/Math/ECSMath_double3x3.h"
#include "ECS/Math/ECSMath_double3x4.h"

#include "ECS/Math/ECSMath_bool4.h"
#include "ECS/Math/ECSMath_bool4x2.h"
#include "ECS/Math/ECSMath_bool4x3.h"
#include "ECS/Math/ECSMath_bool4x4.h"

#include "ECS/Math/ECSMath_uint4.h"
#include "ECS/Math/ECSMath_uint4x2.h"
#include "ECS/Math/ECSMath_uint4x3.h"
#include "ECS/Math/ECSMath_uint4x4.h"

#include "ECS/Math/ECSMath_int4.h"
#include "ECS/Math/ECSMath_int4x2.h"
#include "ECS/Math/ECSMath_int4x3.h"
#include "ECS/Math/ECSMath_int4x4.h"

#include "ECS/Math/ECSMath_float4.h"
#include "ECS/Math/ECSMath_float4x2.h"
#include "ECS/Math/ECSMath_float4x3.h"
#include "ECS/Math/ECSMath_float4x4.h"

#include "ECS/Math/ECSMath_double4.h"
#include "ECS/Math/ECSMath_double4x2.h"
#include "ECS/Math/ECSMath_double4x3.h"
#include "ECS/Math/ECSMath_double4x4.h"

#include "ECS/Math/ECSMath_quaternion.h"

#include "ECS/Math/ECSMath_math.h"
#include "ECS/Math/ECSMath_matrix.h"

#include "ECS/Math/ECSMath_Rigidtransform.h"
#include "ECS/Math/ECSMath_AffineTransform.h"
#include "ECS/Math/ECSMath_random.h"

#include "ECS/Math/Geometry/ECSMath_MinMaxAABB.h"
#include "ECS/Math/Geometry/ECSMath_Plane.h"

//======= ECS FRAMEWORK ======= 
#include "ECS/Timer.h"
#include "ECS/World.h"
#include "ECS/System.h"


//======= CONTENT ======= 
using namespace ecs;
#include "World/System/FieldSystem.h"
#include "World/FieldWorld.h"


