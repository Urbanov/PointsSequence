#pragma once
#include "seg_tree.h"

class AltSegTreeSolver : public SegTreeSolver {
public:
	Solution solve(const Matrix<int>& problem) const override;
};