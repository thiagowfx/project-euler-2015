/*
 * Find the least value of n for which p(n) is divisible by one million.
 */
#include <bits/stdc++.h>

inline long long int pentagonal(long long int n) {
	return n * (3 * n - 1) / 2;
}

// Upstream : https://en.wikipedia.org/wiki/Partition_%28number_theory%29#Generating_function
long long int solve(long long int N = 1e6) {
	long long int n = 1;

	std::deque<long long int> p;

	// p[0] = 1;
	p.push_back(1);

	while(true) {
		long long int i = 0;
		long long int penta = 1;
		p.push_back(0);

		while(penta <= n) {
			int sign = ((i % 4) > 1) ? (-1) : (+1);

			p[n] = (p[n] + (sign * p[n - penta])) % N;
			++i;

			long long int j = (!(i % 2)) ? (i / 2 + 1) : -(i / 2 + 1);
			penta = pentagonal(j);
		}

		if(!p[n])
			break;

		++n;
	}

	return n;
}

int main(int argc, char *argv[]) {
	long long int N = atoll(argv[1]);
	std::cout << solve(N) << std::endl;
	return 0;
}
