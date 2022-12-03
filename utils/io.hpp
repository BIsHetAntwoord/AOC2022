#pragma once

#include "primitives.hpp"
#include "list.hpp"

// SplitLines
template <typename List>
struct SplitLines;

template<>
struct SplitLines<ListEnd> {
    using value = List<ListEnd, ListEnd>;
};

template <typename Next>
struct SplitLines<List<Char<'\n'>, Next>> {
    using next_result = SplitLines<Next>::value;

    using value = List<ListEnd, next_result>;
};

template <char C, typename Next>
struct SplitLines<List<Char<C>, Next>> {
    using next_result = SplitLines<Next>::value;
    using first_string = Get<next_result, 0>::value;
    using first_string_appended = List<Char<C>, first_string>;

    using value = Set<next_result, first_string_appended, 0>::value;
};

// SplitBlocks
template <typename List>
struct SplitBlocks {};

template <>
struct SplitBlocks<ListEnd> {
    using value = List<ListEnd, ListEnd>;
};

template <typename Next>
struct SplitBlocks<List<ListEnd, Next>> {
    using next_result = SplitBlocks<Next>::value;

    using value = List<ListEnd, next_result>;
};

template <typename Item, typename Next>
struct SplitBlocks<List<Item, Next>> {
    using next_result = SplitBlocks<Next>::value;
    using first_item = Get<next_result, 0>::value;

    using value = Set<next_result, List<Item, first_item>, 0>::value;
};