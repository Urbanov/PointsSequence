#include "solver.h"
#include "brute.h"
#include "dyn_prog.h"
#include "alt_brute.h"
#include "alt_dyn_prog.h"
#include "seg_tree.h"
#include "alt_seg_tree.h"
#include <string>

std::unique_ptr<Solver> Solver::create(Type type)
{
	switch (type) {
	case BRUTE:
		return std::make_unique<BruteSolver>();

	case DYN_PROG:
		return std::make_unique<DynProgSolver>();

	case SEG_TREE:
		return std::make_unique<SegTreeSolver>();

	case ALT_BRUTE:
		return std::make_unique<AltBruteSolver>();

	case ALT_DYN_PROG:
		return std::make_unique<AltDynProgSolver>();

	case ALT_SEG_TREE:
		return std::make_unique<AltSegTreeSolver>();

	default:
		throw std::runtime_error("Unknown solver algorithm '" + std::to_string(type) + "'");
	}
}
