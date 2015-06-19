/*
 * Find the sum of all the primes below two million.
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

std::vector<long long int> sieve(long long int N) {
  std::vector<long long int> primes;
  std::vector<bool> in(N + 1, true);

  for (long long int i = 2; i * i <= N; ++i) {
    if (in[i]) {
      for (long long int j = i * i; j <= N; j += i) {
        in[j] = false;
      }
    }
  }

  for (long long int i = 2; i <= N; ++i) {
    if (in[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

long long int solve(long long int N) {
  vector<long long int> primes = sieve(N);
  long long int ans = 0;
  for (vector<long long int>::iterator it = primes.begin(); it != primes.end();
       ++it)
    ans += *it;
  return ans;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
