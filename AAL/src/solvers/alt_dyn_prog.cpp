#include "alt_dyn_prog.h"

Solution AltDynProgSolver::solve(const Matrix<int>& problem) const
{
	Matrix<int> matrix(problem);
	auto first_pass = DynProgSolver::solve(matrix);

	for (const auto& point : first_pass.getPoints()) {
		matrix(point.x(), point.y()) = -1;
	}
	auto second_pass = DynProgSolver::solve(matrix);
	first_pass.merge(second_pass);

	return first_pass;
}
