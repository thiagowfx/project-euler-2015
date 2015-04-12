#include <cmath>
#include <vector>
using namespace std;

std::vector<long long int> sieve(long long int N) {
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
