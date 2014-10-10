#include <iostream>

#include <merge_sort.hpp>
#include <tuple_utilities.hpp>

int main() {
  using ints = std::integer_sequence<int, 8,7,33,6,22,5,55,4,3,2,22,1,0>;
  ints i;

  // sort the thing
  std::cout << "\nsorted list: " << compile_sort(i) << '\n';
  std::cout << std::boolalpha << '\n' <<
    all_unique_tuple<std::tuple<int, char, std::string>>::value << '\n' <<
    all_unique_tuple<std::tuple<int, char, std::string, signed>>::value << '\n';
}
