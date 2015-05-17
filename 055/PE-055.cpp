/*
 * How many Lychrel numbers are there below ten-thousand?
 */

#include <bits/stdc++.h>
#include <gmpxx.h>
#define MAX_ITERATIONS (50)
#define LIMIT (10000)

inline bool isPal(const std::string& s) {
    unsigned tam = s.size();
    for(unsigned i = 0; i < tam / 2; ++i)
        if(s[i] != s[tam-1-i])
            return false;
    return true;
}

inline bool isPal(const mpz_class& x) {
	return isPal(x.get_str());
}

inline std::string reverse(std::string t) {
	std::reverse(t.begin(), t.end());
	return t;
}

inline std::string remove_zeroes_front(std::string s) {
	for(std::string::iterator it = s.begin(); it != s.end(); ++it)
		if(*it != '0')
			return s.substr(std::distance(s.begin(), it));
	return "0";
}

inline mpz_class reverse(const mpz_class& x) {
	return mpz_class(remove_zeroes_front(reverse(x.get_str())));
}

inline mpz_class rev_and_add(const mpz_class& x) {
	return x + reverse(x);
}

inline bool isLychrel(mpz_class x) {
	for(int i = 1; i <= MAX_ITERATIONS; ++i) {
		x = rev_and_add(x);
		if(isPal(x))
			return false;
	}

	return true;
}

long long int solve() {
	long long int ans = 0;

	for(int i = 1; i <= LIMIT; ++i) {
		if(isLychrel(mpz_class(std::to_string(i))))
			++ans;
	}

	return ans;
}

int main(int argc, char *argv[]) {
	//assert(isPal("1221"));
	//assert(isPal(mpz_class("1221")));
	//assert(rev_and_add(mpz_class("47")) == mpz_class("121"));
	//assert(reverse("47") == "74");
	//assert(reverse(mpz_class("47")) == mpz_class("74"));
	//assert(isLychrel(mpz_class("196")));
	std::cout << solve() << std::endl;
	return 0;
}
