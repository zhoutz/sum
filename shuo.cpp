// 用计算机计算1+1/2+1/3+...1/100000怎么减少误差？ - 陈硕的回答 - 知乎
// https://www.zhihu.com/question/41196926/answer/90059025
#include <cstdio>
#include <cstdlib>
#include <gsl/gsl_math.h> // M_EULER
#include <gsl/gsl_sf_psi.h>

constexpr int N = 2e9;

int main(int argc, char *argv[]) {
  double digamma = gsl_sf_psi_int(N + 1);
  printf("    gsl %.20f\n", digamma + M_EULER);

  double dsum = 0;
  for (int i = 1; i <= N; ++i) {
    dsum += 1.0 / i;
  }
  printf(" double %.15f\n", dsum);

  dsum = 0;
  for (int i = N; i >= 1; --i) {
    dsum += 1.0 / i;
  }
  printf("reverse %.20f\n", dsum);
  printf("  naive %.20f\n", log(N) + M_EULER);
}
