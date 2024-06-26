/*
 * How many distinct terms are in the sequence generated by ab for 2 ≤ a ≤ 100
 * and 2 ≤ b ≤ 100?
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <gmpxx.h>
#include <sstream>
using namespace std;

mpz_class mypow(mpz_class base, long long int exp) {
  if (!exp)
    return mpz_class("1");
  mpz_class tmp = mypow(base, exp / 2);
  return tmp * tmp * (exp & 1 ? base : mpz_class("1"));
}

long long int solve(long long int A, long long int B) {
  std::set<mpz_class> s;

  for (unsigned ia = 2; ia <= 100; ++ia)
    for (unsigned ib = 2; ib <= 100; ++ib)
      s.insert(mypow(mpz_class(std::to_string(ia)), ib));

  return s.size();
}

int main(int argc, char *argv[]) {
  long long int number_a = atoll(argv[1]);
  long long int number_b = atoll(argv[2]);
  std::cout << solve(number_a, number_b) << std::endl;
  return 0;
}
