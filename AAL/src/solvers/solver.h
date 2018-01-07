#pragma once

#include <memory>
#include "../structures/solution.h"
#include "../structures/matrix.h"

class Solver {
public:
	enum Type { BRUTE = 1, DYN_PROG = 2, SEG_TREE = 3, ALT_BRUTE = 4, ALT_DYN_PROG = 5, ALT_SEG_TREE = 6 };

	virtual ~Solver() = default;
	virtual Solution solve(const Matrix<int>& problem) const = 0;
	virtual long long complexity(int n) const = 0;
	static std::unique_ptr<Solver> create(Type type);
};
