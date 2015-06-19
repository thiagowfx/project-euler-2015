/*
 * What is the largest n-digit pandigital prime that exists?
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

inline bool isPandigital(std::string s, unsigned n = 9) {
  if (s.size() != n)
    return false;

  std::vector<int> hash(10, 0);

  for (auto &c : s)
    hash[c - '0']++;

  if (hash[0])
    return false;

  for (unsigned i = 1; i <= n; ++i)
    if (hash[i] != 1)
      return false;

  return true;
}

inline bool isPandigital(long long int x, unsigned n = 9) {
  return isPandigital(std::to_string(x), n);
}

long long int solve() {
  // Manual run: there are no pandigital primes with 9 digits.
  // So I'm beginning with 8.
  sieve(1e8);

  for (std::vector<long long int>::reverse_iterator it = primes_g.rbegin();
       it != primes_g.rend(); ++it) {
    if (isPandigital(*it, std::to_string(*it).size()))
      return *it;
  }

  throw std::runtime_error("No pandigital primes found!");
}

int main(int argc, char *argv[]) {
  std::cout << solve() << std::endl;
  return 0;
}
