#include <bits/stdc++.h>

inline int triangle(int n) {
	return n * (n + 1) / 2;
}

inline int square(int n) {
	return n * n;
}

inline int pentagon(int n) {
	return n * (3 * n - 1) / 2;
}

inline int hexagon(int n) {
	return n * (2 * n - 1);
}

inline int heptagon(int n) {
	return n * (5 * n - 3) / 2;
}

inline int octogon(int n) {
	return n * (3 * n - 2);
}

inline bool test_cycle(int a, int b) {
	return a % 100 == b / 100;
}

long long int solve() {
	const int lower = 1000;
	const int upper = 10000;

	std::set<int> p[6];

	auto generate_pol = [lower,upper](std::set<int>& s, std::function<int(int)> f) {
		for(int i = 0; ; ++i) {
			int next = f(i);
			if(next < lower)
				continue;
			if(next > upper)
				break;
			s.insert(next);
		}

	};

	generate_pol(p[0], triangle);
	generate_pol(p[1], square);
	generate_pol(p[2], pentagon);
	generate_pol(p[3], hexagon);
	generate_pol(p[4], heptagon);
	generate_pol(p[5], octogon);

	std::set<int>::iterator it[6];
	std::vector<int> a = {0, 1, 2, 3, 4, 5};

	do {
		for(it[a[0]] = p[a[0]].begin(); it[a[0]] != p[a[0]].end(); ++it[a[0]]) {
			for(it[a[1]] = p[a[1]].begin(); it[a[1]] != p[a[1]].end(); ++it[a[1]]) {
				if(!test_cycle(*it[a[0]], *it[a[1]]))
					continue;

				for(it[a[2]] = p[a[2]].begin(); it[a[2]] != p[a[2]].end(); ++it[a[2]]) {
					if(!test_cycle(*it[a[1]], *it[a[2]]))
						continue;

					for(it[a[3]] = p[a[3]].begin(); it[a[3]] != p[a[3]].end(); ++it[a[3]]) {
						if(!test_cycle(*it[a[2]], *it[a[3]]))
							continue;

						for(it[a[4]] = p[a[4]].begin(); it[a[4]] != p[a[4]].end(); ++it[a[4]]) {
							if(!test_cycle(*it[a[3]], *it[a[4]]))
								continue;

							for(it[a[5]] = p[a[5]].begin(); it[a[5]] != p[a[5]].end(); ++it[a[5]]) {
								if(!test_cycle(*it[a[4]], *it[a[5]]))
									continue;

								if(!test_cycle(*it[a[5]], *it[a[0]]))
									continue;
									
								return *it[a[0]] + *it[a[1]] + *it[a[2]] + *it[a[3]] + *it[a[4]] + *it[a[5]];
							}
						}
					}
				}
			}
		}
	} while(std::next_permutation(a.begin(), a.end()));
}

int main() {
	assert(test_cycle(1234, 3456));
	std::cout << solve() << std::endl;
	return 0;
}
