/*
 * Find the sum of all the primes below two million.
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<long long int> sieve(long long int N) {
  vector<long long int> primes;
  vector<bool> in(N, true);

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
  vector<long long int> primes = sieve(N);
  long long int ans = 0;
  for (vector<long long int>::iterator it = primes.begin(); it != primes.end(); ++it)
  	ans += *it;
  return ans;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  printf("%lld\n", solve(number));

  return 0;
}
