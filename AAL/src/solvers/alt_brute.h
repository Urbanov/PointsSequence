#pragma once
#include "brute.h"

class AltBruteSolver : public BruteSolver {
protected:
	bool valid(const Solution& solution) const override;
};
