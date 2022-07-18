#pragma once


class FieldSystem : public ecs::CSystemBase
{
public:
	FieldSystem(ecs::CWorld& world) : ecs::CSystemBase(world) {}
	
	//============================================================
	// Virtual 
	//============================================================
	void OnCreate() final {

		// sample example
		//1. create entities
		std::vector<entt::entity> entities(1000000);
		std::cout << "Creating 1000000 entities at once" << std::endl;
		
		CTimer timer;
		World.create(entities.begin(), entities.end());
		timer.elapsed();
		
		// 2. mathematics 
		auto a = float3::one;
		auto b = a * 3;
		std::cout << b.ToString() << std::endl;

	}

	void OnUpdate(time_t timeInMS) final {


	}

};