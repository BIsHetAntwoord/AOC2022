#pragma once

#include "utils/primitives.hpp"

// Add
template <typename A, typename B>
struct Add;

template <unsigned A, unsigned B>
struct Add<UInt<A>, UInt<B>> {
    using value = UInt<A + B>;
};

// Min
template <typename A, typename B>
struct Min;

template <unsigned A, unsigned B>
struct Min<UInt<A>, UInt<B>> {
    using value = UInt<(A < B ? A : B)>;
};

// Max
template <typename A, typename B>
struct Max;

template <unsigned A, unsigned B>
struct Max<UInt<A>, UInt<B>> {
    using value = UInt<(A > B ? A : B)>;
};