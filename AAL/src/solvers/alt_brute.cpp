#include "alt_brute.h"
#include <algorithm>

bool AltBruteSolver::valid(const Solution& solution) const
{
	auto it = std::adjacent_find(solution.getPoints().begin(), solution.getPoints().end(), Point::invalidConnection);
	if (it == solution.getPoints().end()) {
		return true;
	}

	// second pass
	it = std::adjacent_find(++it, solution.getPoints().end(), Point::invalidConnection);
	if (it != solution.getPoints().end()) {
		return false;
	}
	return true;
}
