#include <bits/stdc++.h>

inline bool isPandigital(std::string s, unsigned n = 9) {
    if(s.size() != n)
        return false;

    std::vector<int> hash(10, 0);

    for(auto& c : s)
        hash[c - '0']++;

    if(hash[0])
        return false;

    for(unsigned i = 1; i <= n; ++i)
        if(hash[i] != 1)
            return false;

    return true;
}

inline bool isPandigital(long long int x, unsigned n = 9) {
    return isPandigital(std::to_string(x), n);
}

inline bool isPandigitalMult(int mult1, int mult2) {
    return isPandigital(std::to_string(mult1) + std::to_string(mult2) + std::to_string(mult1 * mult2));
}

inline bool digitSeveralTimes(int x) {
    std::string s = std::to_string(x);
    std::sort(s.begin(), s.end());
    for(unsigned i = 1; i < s.size(); ++i)
        if(s[i] == s[i-1])
            return true;
    return false;
}

int solve() {
    int ans = 0;
    std::set<int> s;

    /* First approach: from 1 to 9999.
     * Second approach: from 1 to 9876.
     * Third approach: digitSeveralTimes.
     */
    for(int a = 1; a <= 9876; ++a) {
        if(digitSeveralTimes(a))
            continue;
        for(int b = a + 1; b <= 9876; ++b) {
            if(isPandigitalMult(a, b))
                s.insert(a * b);
        }
    }

    for(auto& el: s)
        ans += el;

    return ans;
}

int main() {
    //assert(isPandigital(12345, 5));
    //assert(!isPandigital(12345, 4));
    //assert(!isPandigital(12345, 6));
    //assert(isPandigital(53142, 5));
    //assert(!isPandigital(543210, 5));
    //assert(!isPandigital(12812, 5));
    //assert(!isPandigital(112345, 5));
    //assert(!isPandigital(34567, 5));
    //assert(!isPandigital(67890, 5));
    //assert(isPandigital(123456789, 9));
    //assert(isPandigital(123456789));
    //assert(isPandigital("53142", 5));
    //assert(isPandigitalMult(39, 186));
    //assert(!isPandigitalMult(10000, 1));
    //assert(!isPandigitalMult(9999, 2));
    assert(!digitSeveralTimes(1234));
    assert(digitSeveralTimes(1134));
    assert(digitSeveralTimes(1314));

    std::cout << solve() << std::endl;
    return 0;
}
