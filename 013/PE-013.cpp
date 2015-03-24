/*
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <gmpxx.h>
using namespace std;

void solve() {
  mpz_t sum, next;
  mpz_init(sum);
  
  for (unsigned i = 0; i < 100; ++i) {
    std::string input;
    std::getline(std::cin, input);

    mpz_init(next);
    mpz_init_set_str(next, input.c_str(), 0);
    // gmp_printf("%Zd\n", next); // TODO
    mpz_add(sum, sum, next);

    mpz_clear(next);
  }

  char answer[20];
  gmp_sprintf(answer, "%Zd\n", sum);

  answer[10] = '\0';
  printf("%s\n", answer);

  mpz_clear(sum);
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
