#include <vector>
#include "dyn_prog.h"

Solution DynProgSolver::bestValid(const std::vector<Solution>& solutions, const Point& point) const
{
	Solution best = solutions.front();
	for (const auto& solution : solutions) {
		if (Point::validConnection(solution.getPoints().back(), point) && solution.sum() > best.sum()) {
			best = solution;
		}
	}
	return best;
}

Solution DynProgSolver::solve(const Matrix<int>& problem) const
{
	std::vector<Solution> solutions;
	Point dummy(0, 0, 0);
	solutions.emplace_back(dummy);

	for (int x = 0; x < problem.width(); ++x) {
		for (int y = 0; y < problem.height(); ++y) {
			if (problem(x, y) != -1) {
				Point point(x, y, problem(x, y));
				solutions.push_back(bestValid(solutions, point).insert(point));
			}
		}
	}

	Point last(problem.width() - 1, problem.height() - 1, 0);
	std::vector<Point> tmp = bestValid(solutions, last).getPoints();
	tmp.erase(tmp.begin());
	return Solution(tmp);
}

long long DynProgSolver::complexity(int n) const
{
	return static_cast<long long>(n) * n;
}