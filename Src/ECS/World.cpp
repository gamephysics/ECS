#include "ECS.h"

namespace ecs
{	
	//--------------------------------------------------------------------
	// Code : SeekDatum()
	// Desc	: Seek registered Datum of SystemBase with it's name
	//--------------------------------------------------------------------
	auto CWorld::SeekDatum(const std::string& name)->Datum::SharedPtr
	{
		std::lock_guard<decltype(lock_)> lock(lock_);

		if (auto iterS = repo_1.find(name); iterS != repo_1.end())
			return (*iterS).second;

		return nullptr;
	}

	//--------------------------------------------------------------------
	// Code : Insert()
	// Desc	: Insert System 
	//--------------------------------------------------------------------
	bool CWorld::Insert(SystemBaseSharedPtr pSystemBase)
	{
		std::lock_guard<decltype(lock_)>	lock(lock_);

		if (!pSystemBase)
			return false;

		// Derived Class 이름을 설정한다.
		auto DerivedClassName = typeid(*pSystemBase).name();

		//	중복검사 
		if (auto pDatum = SeekDatum(DerivedClassName))
			return false;

		auto	newDatum = std::make_shared<Datum>();
		if (!newDatum)
			throw std::bad_alloc();

		++m_Priority;

		//	컨테이너에 적재
		newDatum->pSender = pSystemBase;
		newDatum->iterator_1 = repo_1.emplace(DerivedClassName, newDatum).first;
		newDatum->iterator_2 = repo_2.emplace(m_Priority,		pSystemBase).first;
		newDatum->iterator_3 = repo_3.emplace(m_Priority,		newDatum).first;

		return true;
	}

	void CWorld::Delete(const std::string& name)
	{
		std::lock_guard<decltype(lock_)>	lock(lock_);

		if (auto pDatum = SeekDatum(name))
		{
			if (pDatum->iterator_1 != repo_1.end())	repo_1.erase(pDatum->iterator_1);
			if (pDatum->iterator_2 != repo_2.end()) repo_2.erase(pDatum->iterator_2);
			if (pDatum->iterator_3 != repo_3.end()) repo_3.erase(pDatum->iterator_3);			
		}
	}

	auto CWorld::Seek(const std::string& name)->SystemBaseSharedPtr			// repo_1
	{
		std::lock_guard<decltype(lock_)>	lock(lock_);

		if (auto pDatum = SeekDatum(name))
		{
			return pDatum->pSender;
		}
		return nullptr;
	}

	//--------------------------------------------------------------------
	// Code : DestroySystem()
	// Desc	: SystemBase 제거한다.
	//--------------------------------------------------------------------
	void	CWorld::DestroySystem(SystemBaseSharedPtr pSystemBase)
	{
		if (!pSystemBase)
		{
			// Derived Class 이름을 설정한다.
			auto DerivedClassName = typeid(*pSystemBase).name();

			// 제거
			pSystemBase->OnDestroy();
			Delete(DerivedClassName);
		}
	}

	//--------------------------------------------------------------------
	// Code : Update()
	// Desc	: ECS World 에 등록되어진 SystemBase 을 호출한다. ( 매 프레임 호출 )
	//--------------------------------------------------------------------
	void	CWorld::Update(time_t gametimeMS)
	{
		std::lock_guard<decltype(lock_)>	lock(lock_);

		// OnStart
		if (repo_3.size() > 0)
		{
			// 등록후 OnStart를 호출하지 않은 SystemBase를 호출한다.
			for (auto iterS = repo_3.begin(); iterS != repo_3.end(); ++iterS)
			{
				if (auto pDatum = (*iterS).second.lock())
				{
					if(pDatum->pSender)
						pDatum->pSender->OnStart();
					
					// 제거
					pDatum->iterator_3 = repo_3.end();
				}
			}
			// 일괄 초기화
			repo_3.clear();
		}

		// Check Frame Per Seconds
		if (m_nextUpdateInMS > gametimeMS)	return;
		m_nextUpdateInMS = gametimeMS + m_updateRateInMS;			
		if (m_updateRateInMS > 0) m_nextUpdateInMS = m_nextUpdateInMS / m_updateRateInMS * m_updateRateInMS;

		// OnUpdate
		for(auto iterS = repo_2.begin(); iterS != repo_2.end(); ++iterS)
		{
			if (auto pSystemBase = (*iterS).second.lock())
			{
				pSystemBase->OnUpdate(gametimeMS);
			}
		}
	}

	//--------------------------------------------------------------------
	// Code : Loop()
	// Desc	: Update 를 일정간격으로 반복하기위한 함수
	//--------------------------------------------------------------------
	using default_clock = std::chrono::system_clock;
	default_clock::time_point point_start	= default_clock::now();
	default_clock::time_point point_prev	= default_clock::now();
	default_clock::time_point point_curr	= default_clock::now();

	void	CWorld::Loop()
	{
		//============================================================
		// Worker Style Sleep Loop
		//============================================================
		while (!(GetKeyState(VK_ESCAPE) & 0x8000))
		{
			point_curr = default_clock::now();

			auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(point_curr - point_start).count();

			// Update
			Update(millisec);

			auto	interval = std::chrono::duration_cast<std::chrono::milliseconds>(point_curr - point_prev).count();
			if (interval < 10)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
			point_prev = point_curr;
		}
	}
}