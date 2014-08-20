#include <iostream>

#include <merge_sort.hpp>

int main() {
  using ints = std::integer_sequence<int, 8,7,33,6,22,5,55,4,3,2,22,1,0>;
  ints i;

  // sort the thing
  std::cout << "\nsorted list: " << compile_sort(i) << '\n';
}
