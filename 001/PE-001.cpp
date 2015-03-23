/*
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <cstdio>
#include <cstdlib>
using namespace std;

long long int solve(int a, int b, int limit) {
  long long int sum = 0;
  for (int n = 0; n < limit; ++n) {
    if (!(n % a)  || !(n % b))
      sum += n;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int limit = atoi(argv[3]);

  printf("%lld\n", solve(a, b, limit));
  return 0;
}
