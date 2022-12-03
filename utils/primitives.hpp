#pragma once

#include <cstddef>

// Primitive definition
template <typename T, T Value>
struct Primitive {
    const static T value = Value;
};

// Aliasses
template <char C>
using Char = Primitive<char, C>;

template <unsigned char C>
using UChar = Primitive<unsigned char, C>;

template <signed char C>
using SChar = Primitive<signed char, C>;

template <short S>
using Short = Primitive<short, S>;

template <unsigned short S>
using UShort = Primitive<unsigned short, S>;

template <int I>
using Int = Primitive<int, I>;

template <unsigned U>
using UInt = Primitive<unsigned, U>;

template <long L>
using Long = Primitive<long, L>;

template <unsigned long L>
using ULong = Primitive<unsigned long, L>;

template <long long L>
using LongLong = Primitive<long long, L>;

template <unsigned long long L>
using ULongLong = Primitive<unsigned long long, L>;

template <size_t L>
using SizeT = ULongLong<L>;
