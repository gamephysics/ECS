#pragma once

class FieldWorld : public ecs::CWorld
{
public:
	FieldWorld(uint updateRateInMS) : ecs::CWorld(updateRateInMS)
	{
		// World �� System ���� ����Ѵ�.
		CreateSystem<FieldSystem>();
	}
};