/*
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define D(x) std::cout << #x << " = " << x << std::endl;

std::vector<long long int> mycache;
std::vector<long long int> myprimes;

std::vector<long long int> sieve(long long int N) {
  std::vector<long long int> primes;
  std::vector<bool> in(N + 1, true);

  for (long long int i = 2; i * i <= N; ++i) {
    if (in[i]) {
      for (long long int j = i * i; j <= N; j += i) {
        in[j] = false;
      }
    }
  }

  for (long long int i = 2; i <= N; ++i) {
    if (in[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

// without sieve
std::vector<long long int> divisors(long long int x) {
  std::vector<long long int> ret;
  for (unsigned i = 1; i < x; ++i)
    if (!(x % i))
      ret.push_back(i);
  return ret;
}

long long int d(long long int x) {
  std::vector<long long int> v = divisors(x);
  long long int ret = 0;
  for (std::vector<long long int>::iterator it = v.begin(); it != v.end(); ++it)
    ret += *it;
  return ret;
}

long long int query(long long int x) {
  return mycache[x] == -1 ? (mycache[x] = d(x)) : mycache[x];
}

long long int solve(long long int N) {
  std::set<long long int> amicables;
  for (unsigned i = 1; i < N; ++i)
    for (unsigned j = i + 1; j < N; ++j)
      if (query(i) == j && query(j) == i) {
        // printf("%d, %d\n", i, j);
        amicables.insert(i);
        amicables.insert(j);
      }

  long long int ret = 0;
  for (std::set<long long int>::iterator it = amicables.begin();
       it != amicables.end(); ++it) {
    // D(*it);
    ret += *it;
  }

  return ret;
}

int main(int argc, char *argv[]) {
  long long int number = atoll(argv[1]);
  mycache = std::vector<long long int>(number + 1, -1);
  // myprimes = sieve(N);

  // assert(d(1) == 0);
  // assert(d(2) == 1);
  // assert(d(4) == 3);
  // assert(d(220) == 284);
  // assert(d(284) == 220);
  // assert(query(1) == 0);
  // assert(query(1) == 0);
  // assert(query(2) == 1);
  // assert(query(2) == 1);
  // assert(query(4) == 3);
  // assert(query(4) == 3);
  // assert(query(220) == 284);
  // assert(query(220) == 284);
  // assert(query(284) == 220);
  // assert(query(284) == 220);

  std::cout << solve(number) << std::endl;
  return 0;
}
