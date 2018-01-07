#pragma once
#include <chrono>
#include <functional>

class Timer {
private:
	std::chrono::high_resolution_clock::time_point m_begin;
	std::chrono::high_resolution_clock::time_point m_end;

	void start();
	void stop();
	double delta() const;

public:
	double timedRun(std::function<void()> func);
};
