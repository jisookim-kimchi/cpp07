
#include "iter.hpp"
#include <iostream>

template <typename T>
void addOne(T &t)
{
  t += 1;
}

int main(void)
{
  int arr[] = {1, 2, 3, 4, 5};
  iter(arr, 5, print<const int>);

  std::cout << std::endl;
  iter(arr, 5, addOne<int>);
  iter(arr, 5, print<const int>);

  std::cout << std::endl;
  float farr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
  iter(farr, 5, print<const float>);
  return 0;
}