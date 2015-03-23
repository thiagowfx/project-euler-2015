/*
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
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

unsigned count_exponent(unsigned divisor, unsigned number) {
    int ret = 0;
    while( !(number % divisor) ) {
        ++ret;
        number /= divisor;
    }
    return ret;
}

long long int solve(const long long int N) {
    vector<long long int> primes = sieve(N);
    long long int answer = 1;

    for (vector<long long int>::iterator prime_it = primes.begin(); prime_it != primes.end(); ++prime_it) {
        unsigned max_exponent = 0;
        for (unsigned n = 2; n <= N; ++n)
            max_exponent = max(max_exponent, count_exponent(*prime_it, n));
        answer *= pow(*prime_it, max_exponent);
    }

    return answer;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  printf("%lld\n", solve(number));

  return 0;
}
