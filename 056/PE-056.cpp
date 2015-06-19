/*
 * Considering natural numbers of the form, ab, where a, b < 100, what is the
 * maximum digital sum?
 */

#include <bits/stdc++.h>
#include <gmpxx.h>

mpz_class myexp(const mpz_class &base, const mpz_class &exponent) {
  if (exponent == mpz_class("0"))
    return mpz_class("1");
  mpz_class tmp = myexp(base, exponent / 2);
  return tmp * tmp * ((exponent % 2 == 1) ? base : mpz_class("1"));
}

inline long long int sum(const std::string &s) {
  long long int ans = 0;
  for (auto &c : s)
    ans += c - '0';
  return ans;
}

inline long long int sum(const long long int &x) {
  return sum(std::to_string(x));
}

inline long long int sum(const mpz_class &x) { return sum(x.get_str()); }

inline long long int proc(long long int a, long long int b) {
  return sum(myexp(mpz_class(std::to_string(a)), mpz_class(std::to_string(b))));
}

long long int solve(long long int limit = 100) {
  long long int ans = 0;

  for (int a = 2; a < limit; ++a) {
    for (int b = 1; b < limit; ++b) {
      auto s = proc(a, b);
      if (s > ans)
        ans = s;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  // assert(sum(mpz_class("123")) == 6);
  // assert(myexp(3,3) == mpz_class("27"));

  long long int limit = atoll(argv[1]);
  std::cout << solve(limit) << std::endl;
  return 0;
}