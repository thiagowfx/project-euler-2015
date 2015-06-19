/*
 * Find the sum of the only eleven primes that are both truncatable from left to
 * right and right to left.
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

bool isTruncatablePrime(long long int n) {
  std::string sleft = std::to_string(n);
  std::string sright = sleft.substr(0, sleft.size() - 1);

  while (!sleft.empty()) {
    long long int x = atoll(sleft.c_str());
    if (!is_prime(x))
      return false;
    sleft = sleft.substr(1);
  }

  while (!sright.empty()) {
    std::cout << sright << std::endl;
    long long int x = atoll(sright.c_str());
    if (!is_prime(x))
      return false;
    sright = sright.substr(0, sright.size() - 1);
  }

  return true;
}

long long int solve() {
  sieve(1e7);
  long long int ans = 0;
  unsigned count = 0;

  // assert(isTruncatablePrime(3797));

  for (std::vector<long long int>::iterator it =
           upper_bound(primes_g.begin(), primes_g.end(), 7);
       it != primes_g.end(); ++it) {
    if (isTruncatablePrime(*it)) {
      ans += *it;
      ++count;
      if (count == 11)
        break;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::cout << solve() << std::endl;
  return 0;
}
