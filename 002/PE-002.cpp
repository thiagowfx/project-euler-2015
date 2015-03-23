/*
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long int solve(long long int limit) {
  long long int sum = 0;

  int fprev = 1;
  int fcurr = 2;
  int fnext = 3;

  while(fcurr < limit) {
    sum += fcurr;

    fprev = fcurr + fnext;
    fcurr = fprev + fnext;
    fnext = fprev + fcurr;
  }

  return sum;
}

int main(int argc, char *argv[]) {
  long long int limit = atoi(argv[1]);
  printf("%lld\n", solve(limit));

  return 0;
}
