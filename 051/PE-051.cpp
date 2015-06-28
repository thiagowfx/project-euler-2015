/*
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
 */
#include <bits/stdc++.h>

#define SIEVE_UPPER_LIMIT (1e6)

std::vector<long long int> primes_g;
std::vector<bool> is_prime_g;

void sieve(long long int N = SIEVE_UPPER_LIMIT) {
  std::vector<long long int> primes;
  std::vector<bool> in(N + 1, true);
  in[0] = in[1] = false;

  for (long long int i = 2; i <= N; ++i) {
    if (in[i]) {
      primes.push_back(i);
      for (long long int j = i * i; j <= N; j += i)
        in[j] = false;
    }
  }

  primes_g = primes;
  is_prime_g = in;
}

inline bool is_prime(long long int x) {
  if (x <= SIEVE_UPPER_LIMIT)
    return is_prime_g[x];
  else {
    for (auto &p : primes_g) {
      if (!(x % p))
        return false;
    }
    int last_prime = primes_g.back();
    if (last_prime == 2)
      ++last_prime;
    for (int i = last_prime + 2; i * i <= x; i += 2) {
      if (!(x % i))
        return false;
    }
    return true;
  }
}

std::vector< std::vector<long long int> > patterns5;
inline void populate_patterns5() {
    patterns5 = std::vector< std::vector<long long int> >(4, std::vector<long long int>(5, 0));

    for(int i = 0; i < 4; ++i) {
        patterns5[i][i] = 1;
        patterns5[i][4] = 1;
    }
}

std::vector< std::vector<long long int> > patterns6;
inline void populate_patterns6() {
    patterns6 = std::vector< std::vector<long long int> >(10, std::vector<long long int>(6, 0));

    for(int i = 0; i < 10; ++i) {
        patterns6[i][5] = 1;
    }

    patterns6[0][0] = patterns6[0][1] = 1;
    patterns6[1][0] = patterns6[1][2] = 1;
    patterns6[2][0] = patterns6[2][3] = 1;
    patterns6[3][0] = patterns6[3][4] = 1;
    patterns6[4][1] = patterns6[4][2] = 1;
    patterns6[5][1] = patterns6[5][3] = 1;
    patterns6[6][1] = patterns6[6][4] = 1;
    patterns6[7][2] = patterns6[7][3] = 1;
    patterns6[8][2] = patterns6[8][4] = 1;
    patterns6[9][3] = patterns6[9][4] = 1;
}

long long int generateNumber(long long int repNumber, const std::vector<long long int>& filledPattern) {
    long long int temp = 0;

    for (unsigned i = 0; i < filledPattern.size(); ++i) {
        temp *= 10;
        temp += (filledPattern[i] == -1) ? repNumber : filledPattern[i];
    }

    return temp;
}

long long int familySize(long long int repeatingNumber, const std::vector<long long int>& pattern) {
    long long int familySize = 1;

    for (long long int i = repeatingNumber + 1; i < 10; ++i) {
        if (is_prime(generateNumber(i, pattern)))
            ++familySize;
    }

    return familySize;
}

std::vector<long long int> fillPattern(const std::vector<long long int>& pattern, long long int number) {
    std::vector<long long int> filledPattern(pattern.size(), 0);
    long long int temp = number;

    for(long long int i = static_cast<long long int>(filledPattern.size()) - 1; i >= 0; --i) {
        if (pattern[i] == 1) {
            filledPattern[i] = temp % 10;
            temp /= 10;
        }
        else {
            filledPattern[i] = -1;
        }
    }

    return filledPattern;
}

long long int solve() {
    long long int ans = std::numeric_limits<long long int>::max();

    populate_patterns5();
    populate_patterns6();
    sieve();

    for (long long int i = 11; i < 1000; i += 2) {

        // valid endings: 1, 3, 7, 9
        if (!(i % 5))
            continue;

        for(unsigned j = 0; j < (i < 100 ? patterns5.size() : patterns6.size()); ++j) {
            for(long long int k = 0; k <= 2; ++k) {

                // no candidates with leading zero, please
                if ((i < 100 ? !patterns5[j][0] : !patterns6[j][0]) && !k) {
                    continue;
                }

                auto pattern = fillPattern(i < 100 ? patterns5[j] : patterns6[j], i);
                long long int candidate = generateNumber(k, pattern);

                if (candidate < ans && is_prime(candidate)) {
                    if (familySize(k, pattern) == 8) {
                        ans = candidate;
                    }
                    break;
                }
            }
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {
    std::cout << solve() << std::endl;
    return 0;
}
