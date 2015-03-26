/*
 * What is the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <gmpxx.h>
#include <sstream>
using namespace std;

bool ok(mpz_class x) {
  stringstream ss;
  ss << x;
  return ss.str().size() >= 1000;
}

void solve(long long int N) {
  mpz_class prev("0");
  mpz_class curr("1");
  long long int term = 1;

  while(true) {
    prev += curr;
    swap(curr, prev);
    ++term;

    if(ok(curr)) {
      std::cout << term << std::endl;
      return;
    }
  }
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  solve(number);
  return 0;
}
