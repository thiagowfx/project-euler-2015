/*
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 * formed in the same way?
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

long long int solve(long long int N) {
  long long int ans = 1;
  long long int curr = 1;

  for (unsigned i = 1; i <= ((N - 1) / 2); ++i) {
    int inc = 2 * i;
    for (unsigned j = 0; j < 4; ++j) {
      curr += inc;
      ans += curr;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
