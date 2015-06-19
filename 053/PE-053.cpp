/*
 * How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are
 * greater than one-million?
 */

#include <bits/stdc++.h>
#include <gmpxx.h>

std::function<mpz_class(int)> factorial;

long long int solve(long long int N = 100, long long int upper = 1000000) {
  long long int ans = 0;

  auto populate_factorial = [](int limit) -> void {
    std::vector<mpz_class> _factorial;

    _factorial.push_back(mpz_class("1"));
    mpz_class product("1");

    for (int i = 1; i <= limit; ++i) {
      product *= i;
      _factorial.push_back(product);
    }

    factorial = [=](int n) { return _factorial.at(n); };
  };

  populate_factorial(N);

  // assert(factorial(4) == mpz_class("24"));
  // assert(factorial(5) == mpz_class("120"));

  for (int n = 0; n <= N; ++n) {
    for (int r = 0; r <= n; ++r) {
      mpz_class c = factorial(n) / (factorial(r) * factorial(n - r));
      if (c > mpz_class(std::to_string(upper)))
        ++ans;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  long long int N = atoll(argv[1]);
  long long int upper = atoll(argv[2]);
  std::cout << solve(N, upper) << std::endl;
  return 0;
}