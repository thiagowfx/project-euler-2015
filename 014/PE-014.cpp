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

long long int solve() {
  long long int maxchain = -1;
  long long int maxchain_number = -1;

  for (long long int n = 1; n < 1e6; ++n) {
    long long int work = n;
    long long int chaincount = 1;
    while(work != 1) {
      if (work & 1)
        work = 3 * work + 1;
      else
        work /= 2;
      ++chaincount;
    }
    if(chaincount > maxchain) {
      maxchain = chaincount;
      maxchain_number = n;
    }
  }

  return maxchain_number;
}

int main(int argc, char *argv[]) {
  printf("%lld\n", solve());
  return 0;
}
