/*
 * Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */

#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

mpz_class mypow(mpz_class base, int exponent) {
  if (!exponent)
    return mpz_class("1");
  mpz_class tmp = mypow(base, exponent / 2);
  return tmp * tmp * (exponent & 1 ? base : mpz_class("1"));
}

mpz_class sum_series(long long int N) {
  mpz_class sum("0");
  for (unsigned i = 1; i <= N; ++i) {
    sum += mypow(mpz_class(std::to_string(i)), i);
  }
  return sum;
}

inline mpz_class last_ten_digits(mpz_class x) { return x % 1e10; }

mpz_class solve(long long int N) { return last_ten_digits(sum_series(N)); }

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
