/*
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <gmpxx.h>
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

long long int count_exponent(long long int divisor, long long int number) {
  long long int ret = 0;
  while (!(number % divisor)) {
    ++ret;
    number /= divisor;
  }
  return ret;
}

mpz_class solve(long long int N) {
  std::vector<long long int> primes = sieve(N);
  mpz_class answer("1");

  for (vector<long long int>::iterator prime_it = primes.begin();
       prime_it != primes.end(); ++prime_it) {
    long long int max_exponent = 0;
    for (long long int n = 2; n <= N; ++n)
      max_exponent = max(max_exponent, count_exponent(*prime_it, n));
    answer *= pow(*prime_it, max_exponent);
  }

  return answer;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
