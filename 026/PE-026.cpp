/*
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle
 * in its decimal fraction part.
 */

#include <bits/stdc++.h>

inline long long int calc(long long int n) {
  std::vector<long long int> remainders_pos(n, 0);
  long long int position = 0;
  long long int dividend = 1;

  // stop if dividend is divisible by n
  // or if this dividend appeared (before) already
  while (remainders_pos[dividend] == 0 && dividend != 0) {
    remainders_pos[dividend] = position;
    dividend *= 10;
    dividend %= n;
    ++position;
  }

  return position - remainders_pos[dividend];
}

long long int solve(long long int N) {
  long long int max_cycle = -1;
  long long int ans = -1;
  for (long long int i = 2; i <= N; ++i) {
    auto cycle_size = calc(i);
    std::cout << "cycle size = " << cycle_size << std::endl;
    std::cout << "i = " << i << std::endl;
    if (cycle_size > max_cycle) {
      max_cycle = cycle_size;
      ans = i;
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
