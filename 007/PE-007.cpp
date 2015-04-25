/*
 * What is the 10 001st prime number?
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

std::vector<long long int> sieve(long long int N) {
    std::vector<long long int> primes;
  std::vector<bool> in(N + 1, true);

  for (long long int i = 2; i <= N; ++i) {
    if(in[i]) {
      primes.push_back(i);
      for (long long int j = i * i; j <= N; j += i) {
        in[j] = false;
      }
    }
  }

  return primes;
}

long long int solve(long long int N) {
  // https://en.wikipedia.org/wiki/Prime_number_theorem#Approximations_for_the_nth_prime_number
  // https://en.wikipedia.org/wiki/Rosser%27s_theorem
  // log is base e
  long long int limit = N * (log(N) + log(log(N)));

  // this only hols for N >= 6, so:
  limit = max(limit, 13LL);

  return sieve(limit)[N-1];
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
