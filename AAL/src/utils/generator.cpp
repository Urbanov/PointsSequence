#include "generator.h"

Generator::Generator() 
	: m_generator(m_seed()) 
{}

int Generator::random(int min, int max) const
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(m_generator);
}

double Generator::random(double min, double max) const
{
	std::uniform_real_distribution<double> distribution(min, max);
	return distribution(m_generator);
}

Matrix<int> Generator::generate(int size) const
{
	double density = random(MIN_DENSITY, MAX_DENSITY);
	double ratio = random(MIN_RATIO, MAX_RATIO);
	int height = static_cast<int>(round(sqrt(size / density / ratio)));
	int width = static_cast<int>(round(height * ratio));

	/*if (random(0, 1)) {
		std::swap(height, width);
	}*/

	Matrix<int> data(width, height);

	for (int i = 0; i < size; ++i) {
		int x, y;

		do {
			x = random(0, width - 1);
			y = random(0, height - 1);
		}
		while (data(x, y) != -1);

		data(x, y) = random(MIN_WEIGHT, MAX_WEIGHT);
	}

	return data;
}
