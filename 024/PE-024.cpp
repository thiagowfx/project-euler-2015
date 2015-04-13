/*
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
#define UNDEF (-1)

std::string next_perm(std::string s) {
  const unsigned size = s.size();

  int crit = UNDEF;

  for(unsigned i = size - 1; i >= 1; --i) {
    if(s[i-1] < s[i]) {
      crit = i - 1;
      break;
    }
  }

  if(crit == UNDEF) {
    std::reverse(s.begin(), s.end()); //sort
    return s;
  }

  else {
    int inext = UNDEF;

    for(int i = size - 1; i > crit; --i) {
      if(s[i] > s[crit]) {
        inext = i;
        break;
      }
    }

    std::swap(s[crit], s[inext]);
    std::sort(s.begin() + crit + 1, s.end());
    return s;
  }
}

std::string solve(long long int N) {
  std::string s = "0123456789";

  for (long long int i = 1; i < N; ++i) {
    std::next_permutation(s.begin(), s.end());
    // s = next_perm(s);
  }

  return s;
}

int main(int argc, char *argv[]) {
  assert(next_perm("123") == "132");
  assert(next_perm("132") == "213");
  assert(next_perm("213") == "231");
  assert(next_perm("231") == "312");
  assert(next_perm("312") == "321");
  assert(next_perm("321") == "123");

  long long int number = atoll(argv[1]);
  std::cout << solve(number) << std::endl;
  return 0;
}
