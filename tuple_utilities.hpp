#include <tuple>
#include <type_traits>

namespace detail {
	struct null { };
}

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
