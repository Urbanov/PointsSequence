#pragma once

static constexpr char PROGRAM_NAME[] = "aal";

static constexpr char MODE_PARAM[] = "mode";
static constexpr char MODE_DESC[] = "Specify mode (mandatory)";

static constexpr char ALG_PARAM[] = "alg";
static constexpr char ALG_DESC[] = "Algorithm(s) to use (mandatory)";

static constexpr char TXT_PARAM[] = "txt";
static constexpr char TXT_DESC[] = "Text-only representation in modes which support visual representation";

static constexpr char SIZE_PARAM[] = "size";
static constexpr char SIZE_DESC[] = "Size of auto-generated problem";

static constexpr char ITER_PARAM[] = "iter";
static constexpr char ITER_DESC[] = "Number of iterations";

static constexpr char INST_PARAM[] = "inst";
static constexpr char INST_DESC[] = "Number of tests in one iteration";

static constexpr char STEP_PARAM[] = "step";
static constexpr char STEP_DESC[] = "Difference between problem sizes between iterations";

static constexpr char HELP_PARAM[] = "help";
static constexpr char HELP_DESC[] = "Show detailed help";

static constexpr char DETAILED_HELP[] = R"(Available modes:

1. Read problem instance from stdin and solve it using algorithms specified in --alg. Result is presented on a plot or, with --txt option, displayed in the console as a list of points.

Data syntax:
max_width       max_height
point_1_x       point_1_y         point_1_weight
.               .                 .
.               .                 .
.               .                 .
point_n_x       point_n_y         point_n_weight


2. Generate problem instance with given size and solve it using algorithms specified in --alg. Result is presented on a plot or, with --txt option, displayed in the console as a list of points.

3. Benchmark single algorithm on an auto-generated set of problems consisting of --iter iterations with increasing problem sizes starting with --size and growing by --step every iteration. Every iteration consists of --inst instances to ensure accurate results.

4. Compare two algorithms on an auto-generated set of problems consisting of --iter iterations with increasing problem sizes starting with --size and growing by --step every iteration. Every iteration consists of --inst instances to ensure accurate results. Result of comparision is a percentage ratio between two results provided by algorithms.


Available algorithms:
1. Brute solver
2. Dynamic programming solver
3. Dynamic programming solver with tree
4. Alternative brute solver
5. Alternative dynamic programming solver
6. Alternative dynamic programming solver with tree
)";