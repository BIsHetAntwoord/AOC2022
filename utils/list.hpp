#pragma once

#include <cstddef>

// List type
template <typename Item, typename Next>
struct List {
    using item = Item;
    using next = Next;
};

struct ListEnd {};

// Size
template <typename T>
struct Size;

template <typename Item, typename Next>
struct Size<List<Item, Next>> {
    const size_t value = Size<Next>::value + 1;
};

template <>
struct Size<ListEnd> {
    const size_t value = 0;
};

// Get
template <typename T, size_t Index>
struct Get;

template <typename Item, typename Next, size_t Index>
struct Get<List<Item, Next>, Index> {
    using value = Get<Next, Index-1>::value;
};

template <typename Item, typename Next>
struct Get<List<Item, Next>, size_t(0)> {
    using value = Item;
};

// Set
template <typename T, typename Value, size_t Index>
struct Set;

template <typename Item, typename Next, typename Value, size_t Index>
struct Set<List<Item, Next>, Value, Index> {
    using value = List<Item, typename Set<Next, Value, Index-1>::value>;
};

template <typename Item, typename Next, typename Value>
struct Set<List<Item, Next>, Value, size_t(0)> {
    using value = List<Value, Next>;
};

// Append
template <typename List, typename Value>
struct Append;

template <typename Item, typename Next, typename Value>
struct Append<List<Item, Next>, Value> {
    using value = List<Item, typename Append<Next, Value>::value>;
};

template <typename Value>
struct Append<ListEnd, Value> {
    using value = List<Value, ListEnd>;
};

// Reverse
template <typename List>
struct Reverse;

template <>
struct Reverse<ListEnd> {
    using value = ListEnd;
};

template <typename Item, typename Next>
struct Reverse<List<Item, Next>> {
    using reverse_next = Reverse<Next>::value;

    using value = Append<reverse_next, Item>::value;
};

// Remove
template <typename List, typename Value>
struct Remove;

template <typename Value>
struct Remove<ListEnd, Value> {
    using value = ListEnd;
};

template <typename Next, typename Value>
struct Remove<List<Value, Next>, Value> {
    using value = Next;
};

template <typename Item, typename Next, typename Value>
struct Remove<List<Item, Next>, Value> {
    using value = List<Item, typename Remove<Next, Value>::value>;
};

// Map
template <typename List, template <typename I> typename Operation>
struct Map;

template <typename Item, typename Next, template <typename I> typename Operation>
struct Map<List<Item, Next>, Operation> {
    using value = List<typename Operation<Item>::value, typename Map<Next, Operation>::value>;
};

template <template <typename I> typename Operation>
struct Map<ListEnd, Operation> {
    using value = ListEnd;
};

// Reduce
template <typename List, template <typename A, typename B> typename Operation>
struct Reduce;

template <typename Item, template <typename A, typename B> typename Operation>
struct Reduce<List<Item, ListEnd>, Operation> {
    using value = Item;
};

template <typename Item, typename Next, template <typename A, typename B> typename Operation>
struct Reduce<List<Item, Next>, Operation> {
    using next_result = Reduce<Next, Operation>::value;

    using value = Operation<Item, next_result>::value;
};
