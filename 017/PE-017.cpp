/*
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 */

#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define D(x) std::cout << #x << " = " << x << std::endl;

inline long long int h(std::string str) {
    long long int ret = 0;
    for(std::string::iterator it = str.begin(); it != str.end(); ++it)
        if(isalpha(*it))
            ++ret;
    return ret;
}

// from 1 to 1000
long long int solve() {
    const std::string basics1 = "one two three four five six seven eight nine";
    const std::string basics2 = "twenty thirty forty fifty sixty seventy eighty ninety";
    const std::string basics2_special = "ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen";

    long long int ret = 0;

    // "one thousand" number
    ret += h("one thousand");
    D(ret);

    // "hundred" word
    ret += h("hundred") * 900;
    D(ret);

    // quantifier of the "hundred" word
    ret += h(basics1) * 100;
    D(ret);

    // "and" word
    ret += h("and") * (900 - 9);
    D(ret);

    // 20s, 30s, 40s, ..., 90s
    ret += 10 * 10 * h(basics2);
    D(ret);

    // 10, 11, ..., 19
    ret += 10 * h(basics2_special);
    D(ret);

    ret += 10 * 9 * h(basics1);
    D(ret);

    return ret;
}

int main() {
    assert(h("hello") == 5);
    assert(h("hello world") == 10);
    assert(h("hello-world") == 10);
    assert(h("      hey     --1-2!!@3q") == 4);
    assert(h("one two") == 6);

    std::cout << solve() << std::endl;
    return 0;
}
