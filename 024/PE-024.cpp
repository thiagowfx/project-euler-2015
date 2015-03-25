/*
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void solve(long long int N) {
  std::string s = "0123456789";

  for (long long int i = 1; i < N; ++i)
    std::next_permutation(s.begin(), s.end());

  std::cout << s << std::endl;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  solve(number);
  return 0;
}
