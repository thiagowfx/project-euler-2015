/*
 * What is the greatest product of four adjacent numbers in the same direction
 * (up, down, left, right, or diagonally) in the 20×20 grid?
 */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long long int solve(std::ifstream &ifs, long long int N) {
  long long int m[20][20];
  for (unsigned i = 0; i < 20; ++i)
    for (unsigned j = 0; j < 20; ++j)
      ifs >> m[i][j];

  long long int ans = -1;

  // horizontally
  for (unsigned i = 0; i < 20; ++i) {
    for (unsigned j = 0; j <= 20 - N; ++j) {
      long long int product = 1;
      for (unsigned k = 0; k < N; ++k) {
        product *= m[i][j + k];
      }
      ans = max(ans, product);
    }
  }

  // vertically
  for (unsigned i = 0; i < 20; ++i) {
    for (unsigned j = 0; j <= 20 - N; ++j) {
      long long int product = 1;
      for (unsigned k = 0; k < N; ++k) {
        product *= m[j + k][i];
      }
      ans = max(ans, product);
    }
  }

  // diagonally (1)
  for (unsigned i = 0; i <= 20 - N; ++i) {
    for (unsigned j = 0; j <= 20 - N; ++j) {
      long long int product = 1;
      for (unsigned k = 0; k < N; ++k) {
        product *= m[i + k][j + k];
      }
      ans = max(ans, product);
    }
  }

  // diagonally (2)
  for (unsigned i = N - 1; i < 20; ++i) {
    for (unsigned j = 0; j <= 20 - N; ++j) {
      long long int product = 1;
      for (unsigned k = 0; k < N; ++k) {
        product *= m[i - k][j + k];
      }
      ans = max(ans, product);
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::ifstream ifs(argv[1]);
  long long int number = atoll(argv[2]);
  std::cout << solve(ifs, number) << std::endl;
  return 0;
}
