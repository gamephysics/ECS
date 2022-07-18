#pragma once

namespace ecs
{
	//--------------------------------------------------------------------
	// Class: CWorld 
	// Desc	: ECS World = entt::registry
	//	Entity 가 관리되어지는 기반 Class 이고
	//  System 이 구동되어지는 기반 Class 이다
	//--------------------------------------------------------------------
	class CWorld : public entt::registry
	{
	public:
		typedef	std::shared_ptr<CWorld>		SharedPtr;
		typedef	std::weak_ptr<CWorld>		WeakPtr;
		
	public:
		//=====================================================
		// SystemBase Datum
		//=====================================================
		struct Datum
		{
			typedef std::shared_ptr<Datum>	SharedPtr;
			typedef std::weak_ptr<Datum>	WeakPtr;

			SystemBaseSharedPtr		pSender = nullptr;

			using NAME_SYSTEMBASE		= std::unordered_map<std::string,	Datum::SharedPtr>;
			using PRIORITY_SYSTEMBASE	= std::map<int64_t,					SystemBaseWeakPtr>;
			using FIRST_SYSTEMBASE		= std::map<int64_t,					Datum::WeakPtr>;

			NAME_SYSTEMBASE::iterator			iterator_1; // (map)	:	SystemBase Class Name
			PRIORITY_SYSTEMBASE::iterator		iterator_2; // (map)	:	call order (OnUpdate)
			FIRST_SYSTEMBASE::iterator			iterator_3; // (map)	:	call order (OnStart)
		};
		//
		std::recursive_mutex				lock_;
		Datum::NAME_SYSTEMBASE				repo_1;
		Datum::PRIORITY_SYSTEMBASE			repo_2;
		Datum::FIRST_SYSTEMBASE				repo_3;
		//=====================================================

		auto	SeekDatum(const std::string& name)->Datum::SharedPtr;
	public:
		bool	Insert(SystemBaseSharedPtr pSystemBase);
		void	Delete(const std::string& name);
		auto	Seek(const std::string& name)->SystemBaseSharedPtr;			// repo_1

	public:
		std::string		m_Name;
		int64_t			m_Priority = 0;
		time_t			m_nextUpdateInMS = 0;
		time_t			m_updateRateInMS = 0;
		//
		CWorld(uint updateRateInMS = 0) : m_updateRateInMS(updateRateInMS) {}
		~CWorld()						{	entt::registry::clear();  }
	public:
		//--------------------------------------------------------------------
		// Code : CreateSystem()
		// Desc	: SystemBase 를 생성한다.
		//--------------------------------------------------------------------
		template<typename T>
		std::shared_ptr<T>	CreateSystem()
		{
			auto newSystem = std::make_shared<T>(*this);
			if (!newSystem)
				throw std::bad_alloc();

			if (Insert(newSystem))
			{
				// 생성
				newSystem->OnCreate();
				return newSystem;
			}
			else
			{
				return nullptr;
			}
		}

		//--------------------------------------------------------------------
		// Code : GetExistingSystem()
		// Desc	: SystemBase 를 가져온다.
		//--------------------------------------------------------------------
		template<typename T>
		std::shared_ptr<T>	GetExistingSystem()
		{
			auto name = typeid(T).name();

			return Seek(name);
		}

		//--------------------------------------------------------------------
		// Code : GetOrCreateSystem()
		// Desc	: SystemBase 가 없으면 생성해 가져온다.
		//--------------------------------------------------------------------
		template<typename T>
		std::shared_ptr<T>	GetOrCreateSystem()
		{
			auto system = GetExistingSystem();
			if (system == nullptr)
			{
				return CreateSystem();
			}

			return system;
		}

		//--------------------------------------------------------------------
		// Code : DestroySystem()
		// Desc	: SystemBase 제거한다.
		//--------------------------------------------------------------------
		void	DestroySystem(SystemBaseSharedPtr system);

		//--------------------------------------------------------------------
		// Code : Loop()
		// Desc	: Update를 일정간격으로 반복하기위한 함수
		//--------------------------------------------------------------------
		void	Loop();


private:
		//--------------------------------------------------------------------
		// Code : Update()
		// Desc	: ECS World 에 등록되어진 SystemBase 을 호출한다. ( 매 프레임 호출 )
		//--------------------------------------------------------------------
		void	Update(time_t gametimeMS);

	};
}