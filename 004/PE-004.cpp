/*
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

bool isPal(long long int x) {
  std::string s = std::to_string(x);
  unsigned size = s.size();

  for (unsigned i = 0; i < size / 2; ++i) {
    if (s[i] != s[size - 1 - i])
      return false;
  }

  return true;
}

long long int solve(long long int n) {
  long long int greatest = std::numeric_limits<long long int>::min();

  long long int upper = pow(10, n) - 1;
  long long int lower = pow(10, n - 1);
  for (long long int i = upper; i >= lower; --i) {
    for (long long int j = i; j >= lower; --j) {
      long long int tmp = i * j;
      if (tmp > greatest && !(tmp % 33) && isPal(tmp))
        greatest = tmp;
    }
  }

  return greatest;
}

int main(int argc, char *argv[]) {
  long long int n = atoll(argv[1]);
  std::cout << solve(n) << std::endl;
  return 0;
}
