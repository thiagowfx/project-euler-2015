/*
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

#include <bits/stdc++.h>

#define SIEVE_UPPER_LIMIT (29000)
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

// sum of factors of p^e
// is sum(p^e) = (p^(e + 1) - 1) / ( p - 1)
// demonstration: sum(p^e) = 1 + p + ... + p^e
// p * sum(p^e) = p + ... + p ^(e+1)
// subtract one from another
// analogous to geometric progression
long long int sumOfDivisorsBetter(long long int x) {
    long long int sum = 1;

    for(auto& p: primes_g) {
        int expo = 0;
        while(!(x % p)) {
            x /= p;
            ++expo;
        }
        sum *= (pow(p, expo + 1) - 1) / (p - 1);
    }

    // x is prime
    if (x > 1) {
        sum *= x + 1;
    }

    return sum;
}

long long int sumOfDivisorsNaive(long long int x) {
    long long int sum = 0;
    for(unsigned i = 1; i <= x; ++i)
        if(!(x % i))
            sum += i;
    return sum;
}

inline long long int sumProperDivisors(long long int x) {
    return sumOfDivisorsBetter(x) - x;
}

inline bool isPerfect(long long int x) {
    return sumProperDivisors(x) == x;
}

inline bool isDeficient(long long int x) {
    return sumProperDivisors(x) < x;
}

inline bool isAbundant(long long int x) {
    return sumProperDivisors(x) > x;
}

long long int solve() {
    long long int answer = 0;
    const int limit = 28123;
    std::vector<int> abundant_numbers;

    sieve();

    for(int i = 2; i <= limit; ++i) {
        if(isAbundant(i))
            abundant_numbers.push_back(i);
    }

    bool hash[limit + 1];
    memset(hash, false, sizeof hash);

    for(auto& ab1: abundant_numbers) {
        for(auto& ab2: abundant_numbers) {
            if(ab1 + ab2 <= limit)
                hash[ab1 + ab2] = true;
            else
                break;
        }
    }

    for(unsigned i = 0; i < sizeof(hash)/sizeof(bool); ++i) {
        if(!hash[i])
            answer +=i;
    }

    return answer;
}

int main(int argc, char *argv[]) {
    std::cout << solve() << std::endl;
    return 0;
}
