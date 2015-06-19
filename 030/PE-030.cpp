/*
 * Find the sum of all the numbers that can be written as the sum of fifth
 * powers of their digits.
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

long long int mypow(long long int base, long long int exp) {
  if (!exp)
    return 1;
  long long int tmp = mypow(base, exp / 2);
  return tmp * tmp * (exp & 1 ? base : 1);
}

inline bool ok(long long int x, long long int N) {
  stringstream ss;
  ss << x;
  std::string s = ss.str();

  int sum = 0;

  for (string::iterator it = s.begin(); it != s.end(); ++it)
    sum += mypow((*it - '0'), N);

  return sum == x ? true : false;
}

long long int solve(long long int N) {
  long long int ans = 0;

  for (long long int i = 10; i <= mypow(10, N + 1); ++i)
    if (ok(i, N))
      ans += i;

  return ans;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
