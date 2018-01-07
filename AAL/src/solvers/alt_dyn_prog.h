#pragma once
#include "dyn_prog.h"

class AltDynProgSolver : public DynProgSolver {
public:
	Solution solve(const Matrix<int>& problem) const override;
};
