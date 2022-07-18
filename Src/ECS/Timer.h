#pragma once

//=============================================================================
// timer
//=============================================================================
struct CTimer final {
	CTimer() : start{ std::chrono::system_clock::now() } {}

	void elapsed() {
		auto now = std::chrono::system_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count() << " milliseconds" << std::endl;
	}

private:
	std::chrono::time_point<std::chrono::system_clock> start;
};