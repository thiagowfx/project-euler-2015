/*
 * How many circular primes are there below one million?
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

inline bool isCircularPrime(long long int x) {
    unsigned num_rot = !x ? 1 : log10(x) + 1;

    for(unsigned i = 0; i < num_rot; ++i) {
        long long int r = (x / pow(10, i)) + ((x % (long long int)(pow(10, i))) * pow(10, num_rot - i));

        if(!is_prime(r))
            return false;
    }

    return true;
}

long long int solve(long long int limit) {
    sieve(limit);
    long long int ans = 0;

    for(long long int i = 2; i <= limit; ++i)
        ans += isCircularPrime(i);

    return ans;
}

int main(int argc, char *argv[]) {
    //assert(isCircularPrime(2));
    //assert(isCircularPrime(3));
    //assert(isCircularPrime(5));
    //assert(isCircularPrime(7));
    //assert(isCircularPrime(11));
    //assert(isCircularPrime(13));
    //assert(isCircularPrime(17));
    //assert(isCircularPrime(31));
    //assert(isCircularPrime(37));
    //assert(isCircularPrime(71));
    //assert(isCircularPrime(73));
    //assert(isCircularPrime(79));
    //assert(isCircularPrime(97));
    //assert(!isCircularPrime(1));
    //assert(!isCircularPrime(0));
    //assert(!isCircularPrime(10));
    //assert(!isCircularPrime(200));
    //assert(!isCircularPrime(900));

    long long int limit = atoll(argv[1]);
    std::cout << solve(limit) << std::endl;
    return 0;
}

