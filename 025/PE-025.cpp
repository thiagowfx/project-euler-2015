/*
 * What is the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <gmpxx.h>
#include <sstream>
using namespace std;

bool ok(mpz_class x) {
  stringstream ss;
  ss << x;
  return ss.str().size() >= 1000;
}

long long int solve(long long int N) {
  mpz_class prev("0");
  mpz_class curr("1");
  long long int term = 1;

  while(true) {
    prev += curr;
    swap(curr, prev);
    ++term;

    if(ok(curr)) {
      return term;
    }
  }
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
