#pragma once
#include <random>
#include "../structures/matrix.h"

class Generator {
private:
	static constexpr double MIN_DENSITY = 0.02;
	static constexpr double MAX_DENSITY = 0.2;
	static constexpr double MIN_RATIO = 1.0;
	static constexpr double MAX_RATIO = 1.8;
	static constexpr int MIN_WEIGHT = 0;
	static constexpr int MAX_WEIGHT = 10;

	std::random_device m_seed;
	mutable std::mt19937 m_generator;

public:
	Generator();
	int random(int min, int max) const;
	double random(double min, double max) const;
	Matrix<int> generate(int size) const;
};
