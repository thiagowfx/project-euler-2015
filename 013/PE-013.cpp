/*
 * Work out the first ten digits of the sum of the following one-hundred
 * 50-digit numbers.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <gmpxx.h>
#include <sstream>
using namespace std;

std::string solve(std::ifstream &ifs, long long int number) {
  mpz_class sum("0");

  for (unsigned i = 0; i < 100; ++i) {
    std::string input;
    std::getline(ifs, input);

    mpz_class next(input.c_str());
    sum += next;
  }

  std::stringstream ss;
  ss << sum;
  std::string answer = ss.str().substr(0, number);

  return answer;
}

int main(int argc, char *argv[]) {
  std::ifstream ifs(argv[1]);
  long long int number = 10;
  if (argc == 3)
    number = atoll(argv[2]);
  std::cout << solve(ifs, number) << std::endl;
  return 0;
}
