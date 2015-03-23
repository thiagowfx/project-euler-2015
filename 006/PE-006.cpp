/*
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

long long int square_of_sum(long long int N) {
  long long int sum = ((1 + N) * N) / 2;
  return pow(sum, 2);
}

long long int sum_of_squares(long long int N) {
  long long int sum = 0;
  for (int i = 1; i <= N; ++i)
    sum += pow(i, 2);
  return sum;
}

long long int sum_of_squares_opt(long long int N) {
  long long int sum = (N * (N + 1) * (2 * N + 1)) / 6;
  return sum;
}

long long int solve(long long int N) {
  return square_of_sum(N) - sum_of_squares_opt(N);
}


int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  printf("%lld\n", solve(number));

  return 0;
}