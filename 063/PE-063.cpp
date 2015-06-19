/*
 * How many n-digit positive integers exist which are also an nth power?
 */
#include <bits/stdc++.h>
#include <gmpxx.h>

long long int mypow(long long int base, long long int exponent) {
  if (!exponent)
    return 1;
  long long int tmp = mypow(base, exponent / 2);
  return tmp * tmp * (exponent & 1 ? base : 1);
}

mpz_class mypow(mpz_class base, long long int exponent) {
  if (!exponent)
    return mpz_class("1");
  mpz_class tmp = mypow(base, exponent / 2);
  return tmp * tmp * (exponent & 1 ? base : mpz_class("1"));
}

inline long long int countDigits(long long int n) {
  return std::to_string(n).size();
}

inline long long int countDigits(const mpz_class &n) {
  return n.get_str().size();
}

long long int solve() {
  long long int ans = 0;

  // alternatively, instead of bools all over the place, use n <= 25 and a <=
  // 150 (arbitrary constants)
  for (long long int n = 1;; ++n) {
    bool first = false;
    bool not_found = false;
    for (long long int a = 1;; ++a) {
      mpz_class next = mypow(mpz_class(std::to_string(a)), n);

      if (countDigits(next) == n) {
        first = true;
        ++ans;
      } else {
        if (first) {
          if (!not_found)
            not_found = true;
          else
            break;
        } else {
          if (countDigits(next) > n)
            return ans;
        }
      }
    }
  }

  return ans;
}

int main() {
  std::cout << solve() << std::endl;
  return 0;
}