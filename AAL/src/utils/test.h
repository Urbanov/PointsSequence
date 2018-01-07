#pragma once
#include <vector>
#include "../solvers/solver.h"

class Test {
private:
	static const int BAR_WIDTH = 25;
	static const int FULL_WIDTH = 38;

	static void progressBar(int current, int iterations);
	static void clean();
	static void performSingleRun(const std::vector<Solver::Type>& solvers, Matrix<int>&& problem, bool text);

public:
	static void singleRun(const std::vector<Solver::Type>& solvers, int size, bool text);
	static void singleRun(const std::vector<Solver::Type>& solvers, std::istream& is, bool text);
	static void benchmark(Solver::Type solver_type, int iterations, int start, int step, int instances);
	static void compare(const std::vector<Solver::Type>& solvers, int iterations, int start, int step, int instances);
};
