#pragma once

//=============================================================================
// ECS MATH 
//=============================================================================
namespace ecs
{
	// A static class to contain various math functions and constants.
	// Extrinsic rotation order. Specifies in which order rotations around the principal axes (x, y and z) are to be applied.
	enum class RotationOrder : byte
	{
		XYZ,
		XZY,
		YXZ,
		YZX,
		ZXY,
		ZYX,
		Default = ZXY
	};

	// Specifies a shuffle component.
	enum class ShuffleComponent : byte
	{
		LeftX,
		LeftY,
		LeftZ,
		LeftW,
		RightX,
		RightY,
		RightZ,
		RightW
	};
	
	// unary minus operator applied to unsigned type, result still unsigned
	// https://stackoverflow.com/questions/8026694/c-unary-minus-operator-behavior-with-unsigned-operands
	inline uint unary_minus_operator(uint v)
	{
		return (~v + 1);
	}

} // namespace ecs
