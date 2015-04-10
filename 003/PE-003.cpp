/*
 * What is the largest prime factor of the number 600851475143?
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<long long int> sieve(long long int N) {
  std::vector<long long int> primes;
  std::vector<bool> in(N + 1, true);

  for (long long int i = 2; i * i <= N; ++i) {
    if(in[i]) {
      for (long long int j = i * i; j <= N; j += i) {
        in[j] = false;
      }
    }
  }

  for(long long int i = 2; i <= N; ++i) {
    if(in[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

long long int solve(long long int N) {
  std::vector<long long int> primes = sieve(sqrt(N));
  long long int size = primes.size();

  for (long long int i = size - 1; i >= 0; --i) {
    if ( (N % primes[i]) == 0 ) {
      return primes[i];
    }
  }

  return -1; //error
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
