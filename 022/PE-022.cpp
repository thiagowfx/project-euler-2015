/*
 * What is the total of all the name scores in the file?
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

vector<string> names;

inline long long int alphavalue(const std::string s) {
  long long int ret = 0;

  for(unsigned i = 1; i < s.size() - 1; ++i)
    ret += (s[i] + 1 - 'A');

  return ret;
}

long long int solve() {
  char input[50];
  while (scanf("%[^,],", input) == 1)
    names.push_back(input);

  sort(names.begin(), names.end());

  long long int answer = 0;

  for(unsigned i = 0; i < names.size(); ++i)
    answer += (alphavalue(names[i]) * (i + 1));

  return answer;
}

int main(int argc, char *argv[]) {
  std::cout << solve() << std::endl;
  return 0;
}
