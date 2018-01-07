#include "seg_tree.h"
#include <algorithm>
#include "../structures/tree.h"

Solution SegTreeSolver::solve(const Matrix<int>& problem) const
{
	std::vector<std::pair<int, Point>> lut;

	int index = 0;
	for (int y = 0; y < problem.height(); ++y) {
		for (int x = 0; x < problem.width(); ++x) {
			if (problem(x, y) != -1) {
				lut.push_back(std::make_pair(index++, Point(x, y, problem(x, y))));
			}
		}
	}
	if (index == 0) {
		++index;
	}
	
	std::sort(lut.begin(), lut.end(), [](const auto& first, const auto& second) { return first.second < second.second; });
	SegmentTree<Solution> solutions(index);

	for(auto&& data : lut) {
		Solution best = solutions.max(data.first);
		best.insert(data.second);
		solutions.insert(data.first, best);
	}

	return solutions.max();
}

long long SegTreeSolver::complexity(int n) const
{
	return static_cast<long long>(round(log(n) * n));
}