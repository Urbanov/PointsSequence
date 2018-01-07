#include <iostream>
#include <vector>
#include <cxxopts.hpp>
#include "literals.h"
#include "solvers/solver.h"
#include "utils/test.h"

int main(int argc, char** argv)
{
	int mode;
	std::string algorithms;
	bool txt;
	int size;
	int iter;
	int inst;
	int step;

	cxxopts::Options options(PROGRAM_NAME);
	try {
		options.add_options()
			(MODE_PARAM, MODE_DESC, cxxopts::value<int>(mode))
			(ALG_PARAM, ALG_DESC, cxxopts::value<std::string>(algorithms))
			(TXT_PARAM, TXT_DESC, cxxopts::value<bool>(txt)->default_value("false"))
			(SIZE_PARAM, SIZE_DESC, cxxopts::value<int>(size))
			(ITER_PARAM, ITER_DESC, cxxopts::value<int>(iter)->default_value("1"))
			(INST_PARAM, INST_DESC, cxxopts::value<int>(inst)->default_value("1"))
			(STEP_PARAM, STEP_DESC, cxxopts::value<int>(step)->default_value("0"))
			(HELP_PARAM, HELP_DESC)
		;
		auto result = options.parse(argc, argv);
		auto check = [&](const std::string& opt) {
			if (result.count(opt) == 0) {
				throw cxxopts::OptionException("Missing mandatory '" + opt + "' option");
			}
		};
		auto valid = [](const std::string& opt, bool expr) {
			if (!expr) {
				throw std::runtime_error("Incorrent value in '" + opt + "' option");
			}
		};

		if (result.count(HELP_PARAM) > 0) {
			std::cout << DETAILED_HELP;
			std::cout << options.help({ "" });
			return 0;
		}

		check(MODE_PARAM);
		check(ALG_PARAM);
		valid(ITER_PARAM, iter >= 0);
		valid(STEP_PARAM, step >= 0);
		valid(INST_PARAM, inst >= 0);

		std::vector<Solver::Type> solvers;
		for (char solver_type : algorithms) {
			solvers.push_back(static_cast<Solver::Type>(solver_type - '0'));
		}

		switch (mode) {
		case 1:
			Test::singleRun(solvers, std::cin, txt);
			break;

		case 2:
			check(SIZE_PARAM);
			valid(SIZE_PARAM, size > 0);
			Test::singleRun(solvers, size, txt);
			break;

		case 3:
			valid(ALG_PARAM, solvers.size() == 1);
			check(SIZE_PARAM);
			valid(SIZE_PARAM, size > 0);
			Test::benchmark(solvers.front(), iter, size, step, inst);
			break;

		case 4:
			valid(ALG_PARAM, solvers.size() == 2);
			check(SIZE_PARAM);
			valid(SIZE_PARAM, size > 0);
			Test::compare(solvers, iter, size, step, inst);
			break;

		default:
			throw std::runtime_error("Unknown mode '" + std::to_string(mode) + "'");
		}
	}
	catch (const cxxopts::OptionException& e) {
		std::cout << "argument parsing error: " << e.what() << std::endl;
		std::cout << options.help({ "" });
	}
	catch (const std::exception& e) {
		std::cout << "runtime error: " << e.what() << std::endl;
	}

	return 0;
}
