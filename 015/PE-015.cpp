/*
 * How many such routes are there through a 20×20 grid? (Lattice paths)
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
using namespace std;

void solve(long long int N) {
  mpz_class answer = 1;

  /* P^{40}_{20,20} (permutation) */

  for (long long int i = N + 1; i <= 2 * N; ++i)
    answer *= mpz_class(std::to_string(i));

  for (unsigned long long int i = 1; i <= N; ++i)
    answer /= mpz_class(std::to_string(i));

  std::cout << answer << std::endl;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  solve(number);
  return 0;
}
