#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <chrono>
#include <iostream>

#define CLOCK(FUNCTION,CHRONO_UNIT) { Clock c; FUNCTION; c.stop(); c.print<CHRONO_UNIT>(#FUNCTION); }
#define CLOCK_MS(FUNCTION) CLOCK(FUNCTION, std::chrono::milliseconds);
#define CLOCK_US(FUNCTION) CLOCK(FUNCTION, std::chrono::microseconds);

class Clock
{
public:
	Clock() { start_ = std::chrono::high_resolution_clock::now(); }

	inline void stop() { end_ = std::chrono::high_resolution_clock::now(); }

	template<typename T>
	int getDurationAs() { return std::chrono::duration_cast<T>(end_ - start_ ).count(); }

	template<typename T>
	void print() { std::cout << "Execution took : " << getDurationAs<T>() << unit<T>() << std::endl; }

	template<typename T>
	void print(const char* func_name) { std::cout << func_name << " execution took : " << getDurationAs<T>() << unit<T>() << std::endl; }

private:
	template<typename T>
	inline std::string unit() { return ""; }

	std::chrono::high_resolution_clock::time_point start_;
	std::chrono::high_resolution_clock::time_point end_;
};

// Template specialization
template<>
inline std::string Clock::unit<std::chrono::milliseconds>() { return " ms";}

template<>
inline std::string Clock::unit<std::chrono::microseconds>() { return " us";}

template<>
inline std::string Clock::unit<std::chrono::nanoseconds>() { return " ns";}

#endif