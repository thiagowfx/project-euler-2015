/*
 * What is the largest prime factor of the number 600851475143?
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<long long int> sieve(long long int N) {
  vector<long long int> primes;
  vector<bool> in(N, true);

  for (long long int i = 2; i <= sqrt(N); ++i) {
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
  vector<long long int> primes = sieve(sqrt(N));
  int size = primes.size();

  for (int i = size - 1; i >= 0; --i) {
    if ( (N % primes[i]) == 0 ) {
      return primes[i];
    }
  }
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  printf("%lld\n", solve(number));

  return 0;
}
