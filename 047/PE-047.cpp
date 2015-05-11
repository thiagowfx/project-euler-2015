/*
 * Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
 */

#include <bits/stdc++.h>

#define SIEVE_UPPER_LIMIT (1e7)
std::vector<long long int> primes_g;
std::vector<bool> is_prime_g;

void sieve(long long int N = SIEVE_UPPER_LIMIT) {
    std::vector<long long int> primes;
    std::vector<bool> in(N + 1, true);
    in[0] = in[1] = false;

    for(long long int i = 2; i <= N; ++i) {
        if(in[i]) {
            primes.push_back(i);
            for(long long int j = i * i; j <= N; j += i)
                in[j] = false;
        }
    }

    primes_g = primes;
    is_prime_g = in;
}

bool is_prime(long long int x) {
    if (x <= SIEVE_UPPER_LIMIT)
        return is_prime_g[x];
    else {
        for (auto& p : primes_g) {
            if(!(x % p))
                return false;
        }
        int last_prime = primes_g.back();
        if(last_prime == 2)
            ++last_prime;
        for(int i = last_prime + 2; i * i <= x; i += 2) {
            if(!(x % i))
                return false;
        }
        return true;
    }
}

int distinct_primes(int n) {
    int ans = 0;
    for(auto& p : primes_g) {
        if(p > n)
            break;
        if(!(n % p))
            ++ans;
    }
    return ans;
}

long long int solve(long long int n) {
    int limit = pow(10, 7);
    sieve(limit);
    int streak = 0;

    assert(distinct_primes(14) == 2);
    assert(distinct_primes(15) == 2);
    assert(distinct_primes(644) == 3);
    assert(distinct_primes(645) == 3);
    assert(distinct_primes(646) == 3);

    for(int i = 2; i < limit; ++i) {
        if(distinct_primes(i) != n) {
            streak = 0;
        }
        else {
            ++streak;
            if(streak == n)
                return i - (n - 1);
        }
    }

    throw std::runtime_error("Couldn't find your number!");
}

int main(int argc, char *argv[]) {
    long long int n = atoll(argv[1]);
    std::cout << solve(n) << std::endl;
    return 0;
}

