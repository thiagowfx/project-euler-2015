/*
 * Find the sum of all numbers, less than one million, which are palindromic in
 * base 10 and base 2.
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

inline bool isPal(std::string s) {
  unsigned tam = s.size();
  for (unsigned i = 0; i < tam / 2; ++i)
    if (s[i] != s[tam - 1 - i])
      return false;
  return true;
}

inline bool isPal(int x) {
  stringstream ss;
  ss << x;
  return isPal(ss.str());
}

std::string trim(std::string s) {
  for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
    if (*it == '0')
      continue;
    else
      return std::string(it, s.end());
  }
  return "";
}

inline bool isPal2(int x) {
  std::bitset<70> b(x);
  return isPal(trim(b.to_string()));
}

bool ok(int x) { return isPal(x) && isPal2(x); }

long long int solve(long long int N) {
  long long int ret = 0;
  for (unsigned i = 1; i <= N; ++i)
    if (ok(i))
      ret += i;
  return ret;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);

  assert(trim("00100") == std::string("100"));
  assert(trim("100") == std::string("100"));

  std::cout << solve(number) << std::endl;
  return 0;
}
