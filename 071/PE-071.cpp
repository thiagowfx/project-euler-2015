/*
 * By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending
 * order of size, find the numerator of the fraction immediately to the left of
 * 3/7.
 */

#include <bits/stdc++.h>

#define SIEVE_UPPER_LIMIT (1e6)

std::vector<long long int> primes_g;
std::vector<bool> is_prime_g;

long long int mypow(long long int base, long long int exponent) {
  if (!exponent)
    return 1;
  long long int tmp = mypow(base, exponent / 2);
  return tmp * tmp * (exponent & 1 ? base : 1);
}

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

inline bool is_prime(long long int x) {
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

inline bool coprime(long long int a, long long int b) {
  std::set<int> div_a;

  for (const int &p : primes_g) {
    while (!(a % p)) {
      a /= p;
      div_a.insert(p);
    }

    if (a == 1)
      break;
  }

  for (const int &p : primes_g) {
    while (!(b % p)) {
      b /= p;
      if (div_a.find(p) != div_a.end()) {
        return false;
      }
    }

    if (b == 1)
      break;
  }

  return true;
}

inline long long int less_than_should(long long int n) {
  double target = (3.0 / 7.0) * n;
  int target_int = floor(target);
  const double EPS = 1e-5;
  int x = fabs(target_int - target) <= EPS ? target_int - 1 : target_int;
  // printf("%lld %d %lf %d\n", n, target_int, target, x);
  return x;
}

long long int solve(long long int N = 1e6) {
  sieve(N);

  long long int latest_prime = primes_g.back();
  long long int candidate_numerator = less_than_should(latest_prime);
  long long int candidate_denominator = latest_prime;

  assert(coprime(4, 3));
  assert(coprime(10, 3));
  assert(!coprime(6, 3));
  assert(!coprime(6, 9));

  for (long long int i = N; i > latest_prime; --i) {
    for (long long int j = less_than_should(i); j > candidate_numerator; --j) {
      if (coprime(j, i) &&
          double(j) / double(i) >
              double(candidate_numerator) / double(candidate_denominator)) {
        candidate_numerator = j;
      }
    }
  }

  return candidate_numerator;
}

int main(int argc, char *argv[]) {
  long long int N = atoll(argv[1]);
  std::cout << solve(N) << std::endl;
  return 0;
}
