/*
 * In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
 */

#include <bits/stdc++.h>
#include <gmpxx.h>

mpz_class gcd(mpz_class a, mpz_class b) {
	if(!b)
		return a;
	return gcd(b, a % b);
}

class Frac {

	mpz_class num;
	mpz_class den;

public:
	Frac(mpz_class numerator, mpz_class denominator) : num(numerator), den(denominator) {
		mpz_class g = gcd(num, den);
		num /= g;
		den /= g;
	}

	Frac(mpz_class numerator) : num(numerator), den(1) {}

	bool operator==(const Frac& that) const {
		return num == that.num && den == that.den;
	}

	void operator=(const Frac& that) {
		num = that.num;
		den = that.den;
	}

	Frac operator+(const Frac& that) const {
		return Frac(num * that.den + den * that.num, den * that.den);
	}

	void operator+=(const Frac& that) {
		operator=(*this + that);
	}

	Frac inverted() const {
		return Frac(den, num);
	}

	bool test() const {
		return num.get_str().size() > den.get_str().size();
	}

	void print() const {
		std::cout << num << "/" << den;
	}

	void println() const {
		print();
		std::cout << std::endl;
	}
};

long long int solve(long long int limit = 1000) {
	long long int ans = 0;

	Frac work(1, 2);

	for(int i = 2; i <= limit; ++i) {
		work = (work + Frac(2)).inverted();

		Frac to_test = work + Frac(1);
		if(to_test.test()) {
			++ans;
		}
	}

	return ans;
}

int main(int argc, char *argv[]) {
	long long int limit = atoll(argv[1]);
	std::cout << solve(limit) << std::endl;
	return 0;
}