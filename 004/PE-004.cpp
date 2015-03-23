/*
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isPal(long long int x) {
  stringstream ss;
  ss << x;
  string s = ss.str();
  int size = s.size();

  for (int i = 0; i < size / 2; ++i) {
    if (s[i] != s[size-1-i])
      return false;
  }

  return true;
}

void solve(int n) {
  long long int greatest = -1;

  int upper = pow(10, n) - 1;
  int lower = pow(10, n - 1);
  for (int i = upper; i >= lower; --i) {
    for (int j = upper; j >= lower; --j) {
      long long int tmp = i * j;
      if (tmp > greatest && isPal(tmp))
        greatest = tmp;
    }
  }
  
  printf("%lld\n", greatest);
}


int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  solve(n);

  return 0;
}
