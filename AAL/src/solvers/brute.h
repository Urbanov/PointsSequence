#pragma once
#include "solver.h"

class BruteSolver : public Solver {
protected:
	virtual bool valid(const Solution& solution) const;

public:
	Solution solve(const Matrix<int>& problem) const override;
	long long complexity(int n) const override;
};
