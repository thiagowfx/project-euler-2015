/*
 * Find the next triangle number that is also pentagonal and hexagonal.
 */
#include <bits/stdc++.h>

inline long long int triangle(long long int n) { return n * (n + 1) / 2; }

inline long long int pentagonal(long long int n) { return n * (3 * n - 1) / 2; }

inline long long int hexagonal(long long int n) { return n * (2 * n - 1); }

bool isPentagonal(long long int n) {
  static std::set<long long int> pentagonal_set;

  if (pentagonal_set.find(n) != pentagonal_set.end())
    return true;
  else {
    long long int ind = pentagonal_set.size() + 1;
    while (true) {
      long long int next = pentagonal(ind++);
      pentagonal_set.insert(next);
      if (next == n)
        return true;
      else if (next > n)
        return false;
    }
  }
}

bool isHexagonal(long long int n) {
  static std::set<long long int> hexagonal_set;

  if (hexagonal_set.find(n) != hexagonal_set.end())
    return true;
  else {
    long long int ind = hexagonal_set.size() + 1;
    while (true) {
      long long int next = hexagonal(ind++);
      hexagonal_set.insert(next);
      if (next == n)
        return true;
      else if (next > n)
        return false;
    }
  }
}

long long int solve(long long int num = 3) {
  int counter = 0;

  for (long long int i = 1;; ++i) {
    long long int next = triangle(i);
    if (isPentagonal(next) && isHexagonal(next)) {
      if (++counter == num)
        return next;
    }
  }

  throw std::invalid_argument("I shouldn't reach here");
}

int main(int argc, char *argv[]) {
  /*
      assert(triangle(285) == 40755);
      assert(pentagonal(165) == 40755);
      assert(hexagonal(143) == 40755);
      assert(isPentagonal(40755));
      assert(isHexagonal(40755));
  */

  int num = 3;
  if (argc == 2)
    num = atoi(argv[1]);
  std::cout << solve(num) << std::endl;
  return 0;
}
