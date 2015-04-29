/*
 * Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
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

inline long long eval(int a, int b, int n) {
    return n * n + a * n + b;
}

long long int solve(long long int limita, long long int limitb) {
    sieve(SIEVE_UPPER_LIMIT);

    long long int answer = -1;
    int longest_seq_size = 0;

    for(int a = -(limita - 1); a <= (limita - 1); ++a) {
        for(int b = -(limitb - 1); b <= (limitb - 1); ++b) {
            int k = 0;
            while(true) {
                if(!is_prime(abs(eval(a, b, k))))
                    break;
                else
                    ++k;
            }
            if(k > longest_seq_size) {
                longest_seq_size = k;
                answer = a * b;
            }
        }
    }

    return answer;
}

int main(int argc, char *argv[]) {
    long long int limita = atoll(argv[1]);
    long long int limitb = atoll(argv[2]);
    std::cout << solve(limita, limitb) << std::endl;
    return 0;
}
