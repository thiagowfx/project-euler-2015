/*
 * How many such routes are there through a 20×20 grid? (Lattice paths)
 */

#include <cstdlib>
#include <iostream>
#include <gmpxx.h>
using namespace std;

/* P^{2n}_{n,n} (permutation) */
mpz_class solve(long long int N) {
  mpz_class answer = 1;

  for (long long int i = N + 1; i <= 2 * N; ++i)
    answer *= mpz_class(std::to_string(i));

  for (long long int i = 1; i <= N; ++i)
    answer /= mpz_class(std::to_string(i));

  return answer;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
