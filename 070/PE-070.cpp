/*
 * Find the value of n, 1 < n < 1e7, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.
 */

#include <bits/stdc++.h>

#define SIEVE_UPPER_LIMIT (static_cast<long long int>(1e7))

std::vector<long long int> primes_g;
std::bitset<SIEVE_UPPER_LIMIT + 1> is_prime_g;

long long int mypow(long long int base, int exponent) {
	if(!exponent)
		return 1;
	long long int tmp = mypow(base, exponent / 2);
	return tmp * tmp * (exponent & 1 ? base : 1);
}

void sieve() {
    is_prime_g = std::bitset<SIEVE_UPPER_LIMIT + 1>{}.set();
    is_prime_g[0] = is_prime_g[1] = false;

    for(long long int i = 2; i <= SIEVE_UPPER_LIMIT; ++i) {
        if(is_prime_g[i]) {
            primes_g.push_back(i);
            for(long long int j = i * i; j <= SIEVE_UPPER_LIMIT; j += i)
                is_prime_g[j] = false;
        }
    }
}

inline bool is_prime(long long int x) {
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

inline int phi(long long int n) {
	if(is_prime(n))
		return n - 1;

	int ans = 1;

	for(const auto& p : primes_g) {
		int k = 0;
		
		while(!(n % p)) {
			++k;
			n /= p;
		}

		if(k >= 1)
			ans *= mypow(p, k - 1) * (p - 1);

		if(n == 1)
			return ans;
	}

	return ans;
}

long long int solve(long long int N = 1e7) {
	sieve();
	long long int ans = -1;
	double ratio = std::numeric_limits<double>::max();

	for(int i = 2; i < N; ++i) {
		printf("%d\n", i);
		double next = double(i) / phi(i);
		if(next < ratio) {
			ratio = next;
			ans = i;
		}
	}

	return ans;
}

int main(int argc, char *argv[]) {
	long long int N = atoll(argv[1]);
	std::cout << solve(N) << std::endl;
	return 0;
}
