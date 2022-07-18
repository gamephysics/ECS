#pragma once

class FieldWorld : public ecs::CWorld
{
public:
	FieldWorld(uint updateRateInMS) : ecs::CWorld(updateRateInMS)
	{
		// World 에 System 들을 등록한다.
		CreateSystem<FieldSystem>();
	}
};