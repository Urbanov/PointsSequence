#include <string>
#include "brute.h"
#include <algorithm>

bool BruteSolver::valid(const Solution& solution) const
{
	auto it = std::adjacent_find(solution.getPoints().cbegin(), solution.getPoints().cend(), Point::invalidConnection);
	if (it != solution.getPoints().cend()) {
		return false;
	}
	return true;
}

Solution BruteSolver::solve(const Matrix<int>& problem) const
{
	std::vector<Point> points;

	for (int x = 0; x < problem.width(); ++x ) {
		for (int y = 0; y < problem.height(); ++y) {
			if (problem(x, y) != -1) {
				points.emplace_back(x, y, problem(x, y));
			}
		}
	}

	Solution best;
	for (int elements = 1; elements <= points.size(); ++elements) {
		std::string bitmask(elements, 1);
		bitmask.resize(points.size(), 0);
		do {
			std::vector<Point> combination;
			for (int i = 0; i < points.size(); ++i) {
				if (bitmask[i]) {
					combination.push_back(points[i]);
				}
			}
			do {
				Solution possible(combination);
				if (valid(possible) && possible.sum() > best.sum()) {
					best = possible;
				}
			} while (std::next_permutation(combination.begin(), combination.end()));
		} while (std::prev_permutation(bitmask.begin(), bitmask.end()));
	}
	return best;
}

long long BruteSolver::complexity(int n) const
{
	long long ret = 1;
	for (int i = 1; i <= n; ++i) {
		ret *= i;
	}
	return ret;
}
