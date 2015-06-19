/*
 * Find the value of D ≤ 1000 in minimal solutions of x for which the largest
 * value of x is obtained.
 * Pell's equation.
 * Upstream reference: https://en.wikipedia.org/wiki/Pell%27s_equation
 */
#include <bits/stdc++.h>
#include <gmpxx.h>

inline bool pell(const mpz_class &x, const mpz_class &y, const mpz_class &D) {
  return x * x - D * y * y == 1;
}

mpz_class solve(mpz_class N = 1000) {
  mpz_class ans;
  mpz_class maximum = -1;

  for (mpz_class D = 2; D <= N; ++D) {
    mpz_class a0 = sqrt(D);

    // D is a perfect square, so we skip it
    if (a0 * a0 == D)
      continue;

    // compare this with problem 64
    mpz_class m = 0;
    mpz_class d = 1;
    mpz_class a = a0;

    mpz_class num1 = 1;
    mpz_class num = a;
    mpz_class den1 = 0;
    mpz_class den = 1;

    while (!pell(num, den, D)) {
      m = d * a - m;
      d = (D - m * m) / d;
      a = (a0 + m) / d;

      mpz_class num2 = num1;
      num1 = num;

      mpz_class den2 = den1;
      den1 = den;

      num = a * num1 + num2;
      den = a * den1 + den2;
    }

    if (num > maximum) {
      maximum = num;
      ans = D;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  long long int N = atoll(argv[1]);
  std::cout << solve(mpz_class(std::to_string(N))) << std::endl;
  return 0;
}
