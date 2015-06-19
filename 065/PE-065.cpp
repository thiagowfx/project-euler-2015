/*
 * Find the sum of digits in the numerator of the 100th convergent of the
 * continued fraction for e.
 */
#include <bits/stdc++.h>
#include <gmpxx.h>

long long int sumDigits(const std::string &s) {
  long long int ans = 0;
  for (auto &c : s) {
    ans += c - '0';
  }
  return ans;
}

long long int solve(int N) {
  mpz_class d = 1;
  mpz_class n = 2;

  // 1. Manually recreate some fractions
  //	2, 3/2, 8/3, 11/4, 19/7, ...
  // 2. Obtain the sequence:
  //	2 --> 3 --> 8 --> 11 --> 19 --> 87 --> ...
  // almost fibonacci: kth = (mult_k) * (k-1)th + (k-2)th
  // where mult_k = (2/3) of (k/3) each k multiple of 3, or 1 (=no effect)
  // otherwise
  //
  // An alternative (more brute force) solution would be to manually
  // generate those fractions in each iteration.
  for (int i = 2; i <= N; ++i) {
    mpz_class tmp = d;
    int c = !(i % 3) ? 2 * (i / 3) : 1;
    d = n;
    n = c * d + tmp;
  }

  return sumDigits(n.get_str());
}

int main(int argc, char *argv[]) {
  // assert(sumDigits("123") == 6);
  int N = atoi(argv[1]);
  std::cout << solve(N) << std::endl;
  return 0;
}
