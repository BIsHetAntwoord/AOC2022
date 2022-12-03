#pragma once

// String to UInt
template <typename String>
struct ToUIntInternal;

template <typename String>
using ToUInt = ToUIntInternal<typename Reverse<String>::value>;

template <>
struct ToUIntInternal<ListEnd> {
    using value = UInt<0>;
};

template <typename Item, typename Next>
struct ToUIntInternal<List<Item, Next>> {
    using next_result = ToUIntInternal<Next>::value;

    using value = UInt<next_result::value * 10 + Item::value - '0'>;
};