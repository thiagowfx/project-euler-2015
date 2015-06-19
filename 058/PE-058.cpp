/*
 * If this process is continued, what is the side length of the square spiral
 * for which the ratio of primes along both diagonals first falls below 10%?
 */
#include <bits/stdc++.h>

#define sqr(x) ((x) * (x))

#define SIEVE_UPPER_LIMIT (1e9)
#define LIMIT_POPULATE_IN_DIAGONAL (1e9)
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

inline long long int lower(long long int n) { return sqr(2 * n - 1) + 1; }

inline long long int upper(long long int n) { return sqr(2 * n + 1); }

inline long long int diagonal(long long int n) { return 4 * n + 1; }

inline long long int count_primes(long long int a, long long int b) {
  // from a to b (both sides included)
  long long int ans = 0;
  for (long long int i = a; i <= b; ++i) {
    if (is_prime(i))
      ++ans;
  }
  return ans;
}

std::function<bool(long long int)> in_diagonal;

void populate_in_diagonal(long long int limit = LIMIT_POPULATE_IN_DIAGONAL) {
  std::set<long long int> s;

  long long int k = 1;
  s.insert(k);
  long long int inc = 2;

  while (k <= limit) {
    for (unsigned i = 0; i < 4 && k <= limit; ++i) {
      k += inc;
      s.insert(k);
    }

    inc += 2;
  }

  in_diagonal = [=](long long int n) { return s.find(n) != s.end(); };
}

inline long long int count_primes_diagonal(long long int a, long long int b) {
  // from a to b (both sides included)
  long long int ans = 0;
  for (long long int i = a; i <= b; ++i) {
    if (is_prime(i) && in_diagonal(i))
      ++ans;
  }
  return ans;
}

long long int solve(int percentage = 10) {
  sieve();
  populate_in_diagonal();

  /*
  assert(lower(1) == 2);
  assert(lower(2) == 10);
  assert(lower(3) == 26);
  assert(upper(1) == 9);
  assert(upper(2) == 25);
  assert(upper(3) == 49);
  assert(diagonal(2) == 9);
  assert(diagonal(3) == 13);
  assert(in_diagonal(3));
  assert(in_diagonal(5));
  assert(in_diagonal(7));
  assert(in_diagonal(13));
  assert(in_diagonal(17));
  assert(in_diagonal(31));
  assert(in_diagonal(37));
  assert(in_diagonal(43));
  assert(!in_diagonal(41));
  assert(!in_diagonal(23));
  assert(count_primes(1, 10) == 4);
  assert(count_primes(1, 11) == 5);
  assert(count_primes(2, 11) == 5);
  assert(count_primes(3, 11) == 4);
  assert(count_primes_diagonal(1, 49) == 8);
  assert(count_primes_diagonal(lower(1), upper(1)) == 3);
  assert(count_primes_diagonal(lower(2), upper(2)) == 2);
  assert(count_primes_diagonal(lower(3), upper(3)) == 3);
  */

  long long int n = 1;
  long long int nprimes = 0;
  while (true) {
    std::cout << "n = " << n << std::endl;

    nprimes += count_primes_diagonal(lower(n), upper(n));

    long long int numerator = nprimes;
    long long int denominator = diagonal(n);

    if ((double(numerator) / double(denominator)) < (double(percentage) / 100))
      break;

    ++n;
  }

  return 2 * n + 1;
}

int main(int argc, char *argv[]) {
  int percentage = atoi(argv[1]);
  std::cout << solve(percentage) << std::endl;
  return 0;
}
