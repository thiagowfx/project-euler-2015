/*
 * What is the value of the first triangle number to have over five hundred divisors?
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<long long int> primes_g;

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

inline long long int numdiv(long long int N) {
  long long int answer = 1;
  vector<long long int>::iterator it = primes_g.begin();
  // printf("--> N: %lld\n", N);
  while(N != 1) {
    int count = 0;
    while(!(N % *it)) {
      ++count;
      N /= *it;
    }
    // printf(" - %lld^%d\n", *it, count);
    answer *= (count + 1);
    ++it;
  }
  return answer;
}

long long int solve(long long int N) {
  long long int current = 1;
  long long int trial = 2;

  while(true) {
    current += trial;
    ++trial;

    long long int num_div = numdiv(current);
    if (num_div > N)
      return current;
  }

  return -1; //error
}

int main(int argc, char *argv[]) {
  primes_g = sieve(1e7);
  long long int number = atoll(argv[1]);
  printf("%lld\n", solve(number));
  return 0;
}
