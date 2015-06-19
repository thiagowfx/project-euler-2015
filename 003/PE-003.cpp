/*
 * What is the largest prime factor of the number 600851475143?
 */

#include <cstdlib>
#include <iostream>
using namespace std;

long long int solve(long long int N) {
  long long int ans = 1, f;

  for (f = 2; f * f <= N; ++f) {
    while (!(N % f)) {
      ans = f;
      N /= f;
    }
  }
  if (N > 1)
    ans = N;

  return ans;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
