/*
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

inline long long int c(long long int a, long long int b) {
  return sqrt(a * a + b * b);
}

inline bool ok(long long int a, long long int b, long long int c) {
  return (a + b + c) == 1000 && (a * a + b * b )== c * c;
}

long long int solve(long long int N) {
  long long int a, b;

  for (a = 1; a <= N; ++a)
    for (b = 1; b <= N; ++b)
      if (ok(a,b,c(a,b))) {
        // printf("%lld %lld %lld\n", a, b, c(a,b));
        return a * b * c(a,b);
      }

  return -1; //error
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  printf("%lld\n", solve(number));

  return 0;
}
