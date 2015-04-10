/*
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <cstdio>
#include <cstdlib>
using namespace std;

int mdc(int a, int b) {
  if (!b)
    return a;
  return mdc(b, a % b);
}

long long int solve(int a, int b, long long int limit) {
  long long int sum = 0;
  --limit;

  long long int mmc = a * b / mdc(a, b);

  long long int diva = limit / a;
  long long int divb = limit / b;
  long long int divmmc = limit / mmc;

  // a
  sum += ((a + (a + (diva - 1) * a)) * diva) / 2;

  // b
  sum += ((b + (b + (divb - 1) * b)) * divb) / 2;

  // limit
  sum -= ((mmc + (mmc + (divmmc - 1) * mmc)) * divmmc) / 2;

  return sum;
}

int main(int argc, char *argv[]) {
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  long long int limit = atoll(argv[3]);

  printf("%lld\n", solve(a, b, limit));
  return 0;
}
