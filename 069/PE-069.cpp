/*
 * Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
 */

#include <bits/stdc++.h>

#define SIEVE_UPPER_LIMIT (1e6)

std::vector<long long int> primes_g;
std::vector<bool> is_prime_g;

long long int mypow(long long int base, long long int exponent) {
	if(!exponent)
		return 1;
	long long int tmp = mypow(base, exponent / 2);
	return tmp * tmp * (exponent & 1 ? base : 1);
}

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

inline long long int phi(long long int n) {
	if(is_prime(n))
		return n - 1;

	long long int ans = 1;

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

long long int solve(long long int N = 1e6) {
	sieve();
	long long int ans = -1;
	double ratio = -1;

/*
	assert(mypow(3,2) == 9);
	assert(mypow(3,3) == 27);
	assert(phi(7) == 6);
	assert(phi(5) == 4);
	assert(phi(9) == 6);
	assert(phi(10) == 4);
*/

	for(long long int i = 2; i <= N; ++i) {
		std::cout << i << std::endl;
		double next = double(i) / phi(i);
		if(next > ratio) {
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
