/*
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 * the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */
#include <bits/stdc++.h>

inline bool isPandigital(std::string s, unsigned n = 9) {
  if (s.size() != n)
    return false;

  int hash[10];
  memset(hash, 0, sizeof hash);

  for (auto &c : s)
    ++hash[c - '0'];

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

inline bool hasRepeatedDigits(long long int x) {
  int v[10];
  memset(v, 0, sizeof v);
  std::string s = std::to_string(x);
  for (auto &c : s) {
    ++v[c - '0'];
  }
  for (int i = 0; i < 10; ++i) {
    if (v[i] > 1)
      return true;
  }
  return false;
}

inline long long int countDigits(long long int x) {
  return std::to_string(x).size();
}

long long int solve() {
  long long int ans = -1;

  for (long long int a = 100; a <= 9999; ++a) {
    if (hasRepeatedDigits(a))
      continue;

    for (int n = 2; n <= 3; ++n) {
      std::string s9;
      for (int i = 0; i < n; ++i) {
        long long int next = (i + 1) * a;
        if (hasRepeatedDigits(next))
          break;
        else
          s9 += std::to_string(next);
      }
      if (isPandigital(s9))
        ans = std::max(ans, atoll(s9.c_str()));
    }
  }

  return ans;
}

int main() {
  /*
  assert(hasRepeatedDigits(111));
  assert(hasRepeatedDigits(121));
  assert(!hasRepeatedDigits(123));
  assert(countDigits(111) == 3);
  assert(countDigits(1112) == 4);
  assert(isPandigital(123456789));
  assert(!isPandigital(1234567890));
  assert(!isPandigital(123456788));
  */

  std::cout << solve() << std::endl;
  return 0;
}