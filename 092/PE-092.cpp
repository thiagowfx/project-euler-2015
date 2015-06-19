/*
 * How many starting numbers below ten million will arrive at 89?
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define sqr(x) ((x) * (x))

inline int apply(int x) {
  std::string s = std::to_string(x);
  int ret = 0;

  for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    ret += sqr(*it - '0');

  return ret;
}

inline bool ok(int x) {
  while (!(x == 1 || x == 89))
    x = apply(x);

  return x == 1 ? false : true;
}

long long int solve(long long int number) {
  long long int ret = 0;

  for (int i = 1; i < number; ++i) {
    if (ok(i))
      ++ret;
  }

  return ret;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
