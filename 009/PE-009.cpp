/*
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define sqr(x) ((x) * (x))

long long int solve(long long int N) {
  long long int a, b;

  for (a = 1; a <= N / 2; ++a) {
    for (b = 1; b <= N / 2; ++b) {
      long long int c = N - a - b;
      if (sqr(a) + sqr(b) == sqr(c))
        return a * b * c;
    }
  }

  return -1; // error: this shouldn't happen but it is here so the compiler
             // becomes happy
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
