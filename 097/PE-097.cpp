/**
 *  Find the last ten digits of this prime number (28433×2^7830457+1).
 */
#include <bits/stdc++.h>
#include <gmpxx.h>

std::string solve() {
  mpz_class n;
  mpz_ui_pow_ui(n.get_mpz_t(), 2, 7830457);
  n *= 28433;
  n += 1;
  std::string s = n.get_str();
  return s.substr(s.size() - 10);
}

int main() {
  std::cout << solve() << std::endl;
  return 0;
}
