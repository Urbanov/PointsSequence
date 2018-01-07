#include "timer.h"

void Timer::start()
{
	m_begin = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
	m_end = std::chrono::high_resolution_clock::now();
}

double Timer::delta() const
{
	return std::chrono::duration<double, std::milli>(m_end - m_begin).count();
}

double Timer::timedRun(std::function<void()> func)
{
	start();
	func();
	stop();
	return delta();
}
