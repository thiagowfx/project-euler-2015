/*
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <gmpxx.h>
using namespace std;
#define sqr(x) ((x) * (x))

mpz_class square_of_sum(mpz_class N) { return sqr(((1 + N) * N) / 2); }

mpz_class sum_of_squares(mpz_class N) {
  return (N * (N + 1) * (2 * N + 1)) / 6;
}

mpz_class solve(long long int N) {
  return square_of_sum(mpz_class(std::to_string(N))) -
         sum_of_squares(mpz_class(std::to_string(N)));
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
