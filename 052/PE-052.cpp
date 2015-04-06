/*
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool ok(const int x) {
    int v[10];
    memset(v, 0, sizeof(v));

    std::stringstream ss;
    ss << x;
    std::string s = ss.str();

    for(std::string::iterator it = s.begin(); it != s.end(); ++it)
        v[*it - '0']++;

    int w[10];

    for (unsigned j = 2; j <= 6; ++j) {
        int next = j * x;

        memset(w, 0, sizeof(w));
        std::stringstream tt;
        tt << next;
        std::string t = tt.str();

        for(std::string::iterator it = t.begin(); it != t.end(); ++it)
            w[*it - '0']++;

        for(unsigned k = 0; k < 10; ++k)
            if(v[k] != w[k])
                return false;
    }

    return true;
}

long long int solve() {
    unsigned i = 1;

    while(true) {
        if(ok(i))
            return i;
        ++i;
    }

    return -1; // error
}

int main(int argc, char *argv[]) {
    assert(ok(142857));
    std::cout << solve() << std::endl;
    return 0;
}
