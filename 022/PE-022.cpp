/*
 * What is the total of all the name scores in the file?
 */

#include <bits/stdc++.h>
using namespace std;

std::vector<string> names;

inline long long int alphavalue(const std::string s) {
  long long int ret = 0;

  for(unsigned i = 1; i < s.size() - 1; ++i)
    ret += (s[i] + 1 - 'A');

  return ret;
}

long long int solve(std::ifstream& ifs) {
  std::string line;
  while(std::getline(ifs, line, ','))
    names.push_back(line);

  sort(names.begin(), names.end());

  long long int answer = 0;

  for(unsigned i = 0; i < names.size(); ++i)
    answer += (alphavalue(names[i]) * (i + 1));

  return answer;
}

int main(int argc, char *argv[]) {
  std::ifstream ifs(argv[1]);
  std::cout << solve(ifs) << std::endl;
  return 0;
}
