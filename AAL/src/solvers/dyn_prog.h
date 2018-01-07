#pragma once
#include "solver.h"

class DynProgSolver : public Solver {
private:
	Solution bestValid(const std::vector<Solution>& solutions, const Point& point) const;

public:
	Solution solve(const Matrix<int>& problem) const override;
	long long complexity(int n) const override;
};
