/*
 * Find the sum of the digits in the number 100!
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

mpz_class factorial(mpz_class number) {
    if (number == mpz_class("0"))
      return mpz_class("1");
    else
      return number * factorial(number - 1);
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
  std::cout << sum_digits(factorial(mpz_class(std::to_string(N)))) << std::endl;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  solve(number);
  return 0;
}
