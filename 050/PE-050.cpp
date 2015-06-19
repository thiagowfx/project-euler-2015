/*
 * Which prime, below one-million, can be written as the sum of the most
 * consecutive primes?
 */

#include <bits/stdc++.h>

#define SIEVE_UPPER_LIMIT (1e7)
std::vector<long long int> primes_g;
std::vector<bool> is_prime_g;

void sieve(long long int N = SIEVE_UPPER_LIMIT) {
  std::vector<long long int> primes;
  std::vector<bool> in(N + 1, true);
  in[0] = in[1] = false;

  for (long long int i = 2; i <= N; ++i) {
    if (in[i]) {
      primes.push_back(i);
      for (long long int j = i * i; j <= N; j += i)
        in[j] = false;
    }
  }

  primes_g = primes;
  is_prime_g = in;
}

bool is_prime(long long int x) {
  if (x <= SIEVE_UPPER_LIMIT)
    return is_prime_g[x];
  else {
    for (auto &p : primes_g) {
      if (!(x % p))
        return false;
    }
    int last_prime = primes_g.back();
    if (last_prime == 2)
      ++last_prime;
    for (int i = last_prime + 2; i * i <= x; i += 2) {
      if (!(x % i))
        return false;
    }
    return true;
  }
}

long long int solve(long long int limit) {
  sieve(limit);

  // assert(!is_prime(15));
  // assert(!is_prime(150));

  long long int ans = -1;
  long long int max_consecutives_size = 0;

  // generate accumulated sum table
  std::set<long long int> acc;
  long long int sum = 0;
  acc.insert(0);
  for (auto &p : primes_g) {
    sum += p;
    if (sum > limit)
      break;
    acc.insert(sum);
  }

  std::set<long long int>::iterator it, jt;

  for (it = acc.begin(); it != acc.end(); ++it) {
    for (jt = it, ++jt; jt != acc.end(); ++jt) {
      long long int try_prime = *jt - *it;
      if (is_prime(try_prime)) {
        long long int consecutives_size = std::distance(it, jt);
        if (consecutives_size > max_consecutives_size) {
          max_consecutives_size = consecutives_size;
          ans = try_prime;
        }
      }
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  long long int limit = atoll(argv[1]);
  std::cout << solve(limit) << std::endl;
  return 0;
}