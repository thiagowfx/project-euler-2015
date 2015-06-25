/*
 * Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. What is the maximum 16-digit string for a "magic" 5-gon ring?
 */
#include <bits/stdc++.h>

inline bool ok(const std::vector<int>& p) {
	if (p[1] == 10 ||
	    p[2] == 10 ||
	    p[4] == 10 ||
	    p[6] == 10 ||
	    p[8] == 10) {
		return false;
	}

	if (p[0] > p[3] ||
	    p[0] > p[5] ||
	    p[0] > p[7] ||
	    p[0] > p[9] ) {
		return false;
	}

	auto sum = p[0] + p[1] + p[2];
	if ((sum != p[3] + p[2] + p[4]) ||
	    (sum != p[5] + p[4] + p[6]) ||
	    (sum != p[7] + p[6] + p[8]) ||
	    (sum!= p[9] + p[8] + p[1])) {
		return false;
	}

	return true;
}

std::string solve() {
	std::string ans;
	std::vector<int> p = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	do {
		if(ok(p)) {
			std::stringstream ss;
			ss << p[0] << p[1] << p[2] << p[3] << p[2] << p[4] << p[5] << p[4] << p[6] << p[7] << p[6] << p[8] << p[9] << p[8] << p[1];
			if(ss.str() > ans) {
				ans = ss.str();
			}
		}
	} while (std::next_permutation(p.begin(), p.end()));

	return ans;
}

int main(int argc, char *argv[]) {
	std::cout << solve() << std::endl;
	return 0;
}
