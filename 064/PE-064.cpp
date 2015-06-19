/*
 * How many continued fractions for N ≤ 10000 have an odd period?
 * Upstream reference:
 * https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion
 */
#include <bits/stdc++.h>

long long int solve(long long int N = 10000) {
  long long int ans = 0;

  for (long long int n = 2; n <= N; ++n) {
    int a0 = sqrt(n);

    // n is a perfect square, so we skip it
    if (a0 * a0 == n)
      continue;

    int period = 0;
    int m = 0;
    int d = 1;
    int a = a0;

    while (a != 2 * a0) {
      m = d * a - m;
      d = (n - m * m) / d;
      a = (a0 + m) / d;
      ++period;
    }

    if (period & 1)
      ++ans;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  long long int N = atoll(argv[1]);
  std::cout << solve(N) << std::endl;
  return 0;
}
