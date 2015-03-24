/*
 * Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <gmpxx.h>
#include <sstream>
using namespace std;

mpz_class mypow(mpz_class base, int exp) {
  if (!exp)
    return mpz_class("1");
  mpz_class partial = mypow(base, exp/2);
  return partial * partial * (exp & 1 ? base : mpz_class("1"));
}

mpz_class sum_series(long long int N) {
  mpz_class sum = 0;
  for (unsigned i = 1; i <= N; ++i) {
    sum += mypow(mpz_class(std::to_string(i)), i);
  }
  return sum;
}

mpz_class last_ten_digits(mpz_class x) {
  return x % 1e10;
}

void solve(long long int N) {
  std::cout << last_ten_digits(sum_series(N)) << std::endl;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  solve(number);
  return 0;
}
