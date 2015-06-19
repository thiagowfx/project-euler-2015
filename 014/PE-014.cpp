/*
 * Which starting number, under one million, produces the longest chain? (3n + 1
 * problem)
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#define UNDEF (-1)
using namespace std;

long long int solve(const long long int N) {
  long long int maxchain = -1;
  long long int maxchain_number = -1;

  for (long long int n = 1; n < N; ++n) {
    long long int work = n;
    long long int chaincount = 1;
    while (work != 1) {
      if (work & 1)
        work = 3 * work + 1;
      else
        work /= 2;
      ++chaincount;
    }
    if (chaincount > maxchain) {
      maxchain = chaincount;
      maxchain_number = n;
    }
  }

  return maxchain_number;
}

// Daqui para baixo: resolvendo com "árvore" (memoization)
std::map<long long int, long long int> ans;

long long int next(long long int x) {
  if (!ans[x]) {
    if (x == 1)
      return ans[x] = 1;

    if (x & 1) {
      return ans[x] = 1 + next(3 * x + 1);
    } else {
      return ans[x] = 1 + next(x / 2);
    }
  } else {
    return ans[x];
  }
}

long long int solve_tree(const long long int N) {
  long long int ret = UNDEF;
  long long int num = UNDEF;

  /*
    assert(next(1) == 1);
    assert(next(2) == 2);
    assert(next(4) == 3);
    */

  for (unsigned i = 1; i < N; ++i) {
    long long int tmp = next(i);
    if (tmp > ret) {
      ret = tmp;
      num = i;
    }
  }

  return num;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);

  // sem memoization
  std::cout << solve(number) << std::endl;

  // com memoization
  // std::cout << solve_tree(number) << std::endl;
  return 0;
}
