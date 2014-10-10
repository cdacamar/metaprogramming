#pragma once

#include <tuple>
#include <type_traits>

#include <and_bools.hpp>

namespace detail {
struct null { };
}

// find if a tuple contains T
template <typename T, typename Tuple>
struct tuple_contains;

template <typename T, typename... Ts>
struct tuple_contains<T, std::tuple<Ts...>> :
  std::conditional<
    std::is_same<
      std::tuple<typename std::conditional<std::is_same<T, Ts>::value, detail::null, Ts>::type...>,
      std::tuple<Ts...>
    >::value,
    std::false_type,
    std::true_type
  >::type
{ };

// find if a tuple contains all unique Ts...
template <typename Tuple>
struct all_unique_tuple;

template <typename... Ts>
struct all_unique_tuple<std::tuple<Ts...>> : std::true_type { };

template <typename T, typename... Ts>
struct all_unique_tuple<std::tuple<T, Ts...>> :
  std::conditional<
    and_bools<(!std::is_same<T, Ts>::value)...>::value,
    all_unique_tuple<std::tuple<Ts...>>,
    std::false_type
  >::type
{ };
