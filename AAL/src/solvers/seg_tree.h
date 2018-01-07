#pragma once
#include "solver.h"

class SegTreeSolver : public Solver {
public:
	Solution solve(const Matrix<int>& problem) const override;
	long long complexity(int n) const override;
};
