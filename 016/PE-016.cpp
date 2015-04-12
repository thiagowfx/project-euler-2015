/*
 * What is the sum of the digits of the number 2^1000?
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

long long int sum_digits(mpz_class number) {
  std::stringstream ss;
  ss << number;
  std::string s = ss.str();
  long long int sum = 0;

  for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
    sum += (*it - '0');
  }

  return sum;
}

void solve(long long int N) {
  mpz_class number = mypow(2, N);
  std::cout << sum_digits(number) << std::endl;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  solve(number);
  return 0;
}
