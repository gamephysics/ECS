#pragma once

namespace ecs
{
	//--------------------------------------------------------------------
	// Class: CSystemBase
	// Desc	: ECS World 에 등록되어 매 프레임 호출되어지는 Manager
	//--------------------------------------------------------------------
	class CSystemBase : public std::enable_shared_from_this<CSystemBase>
	{
	public:
		ecs::CWorld&			World;			// entt::registry 

	public:
		typedef	std::shared_ptr<CSystemBase>	SharedPtr;
		typedef	std::weak_ptr<CSystemBase>		WeakPtr;

	public:
		CSystemBase() = delete;
		CSystemBase(ecs::CWorld& world) : World(world)	{}
		virtual ~CSystemBase() = default;
		//
		CSystemBase::SharedPtr self() { return shared_from_this(); }


		template <typename T>
		std::shared_ptr<T>	GetExistingSystem() //where T : CSystemBase
		{
			return World.GetExistingSystem<T>();
		}
		template <typename T>
		std::shared_ptr<T>	GetOrCreateSystem() //where T : CSystemBase
		{
			return World.GetOrCreateSystem<T>();
		}
		
	public:
		//=====================================================
		// VIRTUAL
		//=====================================================
		virtual void	OnCreate()  {};
		virtual void	OnStart()   {};
		virtual void	OnUpdate(time_t timeInMS) = 0;
		virtual void	OnDestroy() {};
	};

}
