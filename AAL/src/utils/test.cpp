#include "test.h"
#include <iostream>
#include <iomanip>
#include "generator.h"
#include "timer.h"
#include "../plot/plot.h"

void Test::progressBar(int current, int iterations)
{
	std::stringstream ss;
	ss << "[";
	int arrow = BAR_WIDTH * (current + 1) / iterations;
	for (int pos = 1; pos <= BAR_WIDTH; ++pos) {
		if (pos < arrow) {
			ss << "=";
		}
		else if (pos == arrow) {
			ss << ">";
		}
		else {
			ss << " ";
		}
	}
	ss << "] " << current + 1 << "/" << iterations;
	std::cout << std::left << std::setw(FULL_WIDTH) << ss.str();
}

void Test::clean()
{
	std::string dummy(FULL_WIDTH * 2, ' ');
	std::cout << dummy << "\r";
}

void Test::performSingleRun(const std::vector<Solver::Type>& solvers, Matrix<int>&& problem, bool text)
{
	Plot plot(problem);
	for (int i = 0; i < solvers.size(); ++i) {
		Solution solution = Solver::create(solvers[i])->solve(problem);
		std::cout << "Solution " << i + 1 << ": " << solution.sum() << std::endl;
		if (text) {
			std::cout << solution << std::endl;
		}
		plot.addSolution(solution);
	}
	if (!text) {
		plot.show();
	}
}

void Test::singleRun(const std::vector<Solver::Type>& solvers, int size, bool text)
{
	Generator generator;
	performSingleRun(solvers, generator.generate(size), text);
}

void Test::singleRun(const std::vector<Solver::Type>& solvers, std::istream& is, bool text)
{
	Matrix<int> problem(is);
	performSingleRun(solvers, std::move(problem), text);
}

void Test::benchmark(Solver::Type solver_type, int iterations, int start, int step, int instances)
{
	std::vector<int> samples;
	std::vector<double> times;
	samples.reserve(iterations);
	times.reserve(iterations);

	std::unique_ptr<Solver> solver = Solver::create(solver_type);
	Generator generator;
	Timer timer;

	for (int iter = 0, sample_size = start; iter < iterations; ++iter, sample_size += step) {
		samples.push_back(sample_size);
		double run_time = 0;

		for (int instance = 0; instance < instances; ++instance) {
			//fancy progress bar
			progressBar(instance, instances);
			progressBar(iter, iterations);
			std::cout << "\r";

			auto problem = generator.generate(sample_size);
			run_time += timer.timedRun([&]() { solver->solve(problem); });
		}

		times.push_back(run_time / instances);
	}

	clean();
	std::cout << std::left << std::setw(20) << "n" << std::setw(20) << "t(n)[ms]" << std::setw(20) << "q(n)" << std::endl;
	for (int i = 0; i < iterations; ++i) {
		double q = times[i] * solver->complexity(samples[iterations / 2]) / solver->complexity(samples[i]) / times[iterations / 2];
		std::cout << std::left << std::setw(20) << samples[i] << std::setw(20) << times[i] << std::setw(20) << q << std::endl;
	}
}

void Test::compare(const std::vector<Solver::Type>& solvers, int iterations, int start, int step, int instances)
{
	double ratio = 0;
	std::unique_ptr<Solver> first = Solver::create(solvers.front());
	std::unique_ptr<Solver> second = Solver::create(solvers.back());
	Generator generator;

	for (int iter = 0, sample_size = start; iter < iterations; ++iter, sample_size += step) {
		for (int instance = 0; instance < instances; ++instance) {
			//fancy progress bar
			progressBar(instance, instances);
			progressBar(iter, iterations);
			std::cout << "\r";

			auto problem = generator.generate(sample_size);
			ratio += static_cast<double>(first->solve(problem).sum()) / second->solve(problem).sum();
		}
	}
	ratio /= iterations * instances;

	clean();
	std::cout.precision(2);
	std::cout << "Algorithm 1: ";
	if (ratio >= 1) {
		std::cout << "100.00%\nAlgorithm 2: " << std::fixed << 100 / ratio << "%\n";
	}
	else {
		std::cout << std::fixed << 100 * ratio << "%\nAlgorithm 2: 100.00%\n";
	}
}
