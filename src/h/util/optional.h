#ifndef UTIL_OPTIONAL_INCL
#define UTIL_OPTIONAL_INCL

#include <experimental/optional>

template <typename T>
using Optional = std::experimental::optional<T>;

// TODO: how without define?
#define NullOpt std::experimental::nullopt

#endif