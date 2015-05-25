/**
 * ...With a base/exponent pair on each line, determine which line number has the
 * greatest numerical value.
 */

#include <bits/stdc++.h>
#include <gmpxx.h>

mpz_class mypow(const mpz_class& base, const mpz_class& exponent) {
	if(!exponent)
		return mpz_class("1");
	mpz_class tmp = mypow(base, exponent / 2);
	return tmp * tmp * ((exponent % 2 == 1) ? base : mpz_class("1"));
}

int solve(std::ifstream& ifs) {
	long long int ans = 0;
	mpz_class great("0");

	std::string line;
	int i = 0;

	while(std::getline(ifs, line)) {
		++i;
		long long int base, exponent;
		sscanf(line.c_str(), "%lld,%lld\n", &base, &exponent);
		mpz_class n = mypow(mpz_class(std::to_string(base)),
				    mpz_class(std::to_string(exponent)));

		if(n > great) {
			great = n;
			ans = i;
		}
	}

	return ans;
}

int main(int argc, char *argv[]) {
	std::ifstream ifs(argv[1]);
	std::cout << solve(ifs) << std::endl;
	return 0;
}
