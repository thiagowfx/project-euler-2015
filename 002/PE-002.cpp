/*
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 */

#include <iostream>
#include <cstdlib>
#include <gmpxx.h>
using namespace std;

mpz_class solve(mpz_class limit) {
  mpz_class sum("0");

  mpz_class fprev("1");
  mpz_class fcurr("2");
  mpz_class fnext("3");

  while(fcurr < limit) {
    sum += fcurr;

    fprev = fcurr + fnext;
    fcurr = fprev + fnext;
    fnext = fprev + fcurr;
  }

  return sum;
}

int main(int argc, char *argv[]) {
  long long int limit = atoll(argv[1]);
  std::cout << solve(mpz_class(std::to_string(limit))) << std::endl;
  return 0;
}
