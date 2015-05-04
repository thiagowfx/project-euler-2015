/*
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 */

#include <algorithm>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//long long int factorial(long long int x) {
    //return !x ? 1 : x * factorial(x-1);
//}

int factorial[10];

void populate() {
    factorial[0] = 1;
    for (int i = 1; i <= 9; ++i)
        factorial[i] = factorial[i - 1] * i;
}

long long int factdig(int x) {
    std::string s = std::to_string(x);

    long long int ret = 0;
    for(std::string::iterator it = s.begin(); it != s.end(); ++it) {
        ret += factorial[*it - '0'];
    }
    return ret;
}

bool ok(int x) {
    return factdig(x) == x;
}

long long int solve(long long int limit) {
    long long int ret = 0;
    for (int i = 10; i <= limit; ++i)
        if(ok(i))
            ret += i;
    return ret;
}

int main(int argc, char* argv[]) {
    populate();

    //assert(factdig(1) == 1);
    //assert(factdig(145) == 145);
    //assert(ok(145));

    long long int limit;
    if(argc == 2)
        limit = atoll(argv[1]);
    else
        limit = 10000000;

    std::cout << solve(limit) << std::endl;
    return 0;
}
