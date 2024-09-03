#pragma once

#include <cmath>

struct NeumaierSum {
  double sum;
  double compensation;

  using self = NeumaierSum;

  NeumaierSum() : sum(0.), compensation(0.) {}

  self &operator+=(double x) {
    double newsum = sum + x;
    if (std::abs(sum) >= std::abs(x)) {
      compensation += (sum - newsum) + x;
    } else {
      compensation += (x - newsum) + sum;
    }
    sum = newsum;
    return *this;
  }

  double result() const { return sum + compensation; }

  void clear() {
    sum = 0.;
    compensation = 0.;
  }
};
