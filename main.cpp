#include "neumaier.hpp"
#include <iomanip>
#include <iostream>

constexpr int N = 2e9;

int main() {
  NeumaierSum sum;
  for (int i = 1; i <= N; ++i) {
    sum += 1.0 / i;
  }
  std::cout << std::setprecision(20) << sum.result() << std::endl;

  sum.clear();
  for (int i = N; i >= 1; --i) {
    sum += 1.0 / i;
  }
  std::cout << std::setprecision(20) << sum.result() << std::endl;
}
