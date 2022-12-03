#include "utils/primitives.hpp"
#include "utils/list.hpp"
#include "utils/math.hpp"
#include "utils/io.hpp"
#include "utils/string.hpp"

#include "1/input.hpp"

// Input parsing
using Parsed = SplitLines<Input>::value;
using Blocks = SplitBlocks<Parsed>::value;

// Convert input to integers
template <typename List>
using ConvertList = Map<List, ToUInt>;
using IntegerBlocks = Map<Blocks, ConvertList>::value;

// Sum all integers together
template <typename List>
using AddBlocks = Reduce<List, Add>;
using TotalCalories = Map<IntegerBlocks, AddBlocks>::value;

// Find the maximum
using MaxCalories = Reduce<TotalCalories, Max>::value;

using Output = MaxCalories::output;