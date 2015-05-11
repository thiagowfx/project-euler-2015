/*
 * What 12-digit number do you form by concatenating the three terms in this sequence?
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

bool perm4(int a, int b, int c) {
    int h[10];
    memset(h, 0, sizeof h);

    while(a > 0) {
        h[a % 10]++;
        a /= 10;
    }

    // test b
    int m[10];
    memset(m, 0, sizeof m);

    while(b > 0) {
        m[b % 10]++;
        b /= 10;
    }

    for(int i = 0; i < 10; ++i)
        if(h[i] != m[i])
            return false;

    // test c
    int n[10];
    memset(n, 0, sizeof n);

    while(c > 0) {
        n[c % 10]++;
        c /= 10;
    }

    for(int i = 0; i < 10; ++i)
        if(h[i] != n[i])
            return false;

    return true;
}

std::string solve() {
    sieve(1e5);

    for(std::vector<long long int>::iterator it = lower_bound(primes_g.begin(), primes_g.end(), 1000); *it < 1e4; ++it) {
        if(*it == 1487)
            continue;
        for(int i = 2; *it + 2 * i < 1e4; i += 2) {
            int p1 = *it;
            int p2 = *it + i;
            if(!is_prime(p2))
                continue;
            int p3 = *it + 2 * i;
            if(!is_prime(p3))
                continue;
            if(perm4(p1,p2,p3))
                return std::to_string(p1) + std::to_string(p2) + std::to_string(p3);
        }
    }

    throw std::runtime_error("You didn't find the answer.");
}

int main(int argc, char *argv[]) {
    assert(perm4(1487, 4817, 8147));
    assert(perm4(1111, 1111, 1111));

    std::cout << solve() << std::endl;
    return 0;
}

