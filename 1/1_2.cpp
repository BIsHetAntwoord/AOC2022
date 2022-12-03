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
using Nr1 = Reduce<TotalCalories, Max>::value;
using Remove1 = Remove<TotalCalories, Nr1>::value;

using Nr2 = Reduce<Remove1, Max>::value;
using Remove2 = Remove<Remove1, Nr2>::value;

using Nr3 = Reduce<Remove2, Max>::value;

using Result = UInt<Nr1::value + Nr2::value + Nr3::value>;

using Output = Result::output;
