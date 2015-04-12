/*
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define sqr(x) ((x)*(x))

inline long long int c(long long int a, long long int b) {
  return sqrt(a * a + b * b);
}

inline bool ok(long long int N, long long int a, long long int b) {
  long long int myc = c(a,b);
  return (a + b + myc) == N && (a * a + b * b) == myc * myc;
}

long long int solve(long long int N) {
  long long int a, b;

  for (a = 1; a <= N; ++a)
    for (b = 1; b <= N; ++b)
      if (ok(N, a, b))
        return a * b * c(a,b);

  std::cout << "ERROR!" << std::endl;
  return -1; // error: this shouldn't happen but it is here so the compiler becomes happy
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
