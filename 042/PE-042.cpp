/*
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
 */

#include <bits/stdc++.h>

std::vector<bool> triangles;

void init(unsigned limit) {
    triangles.assign(limit, false);
    for(unsigned n = 1; ; ++n) {
        unsigned target = n * (n + 1) / 2;
        if(target >= limit)
            break;
        triangles[target] = true;
    }
}

inline bool isTriangleValue(long long int n) {
    return triangles.at(n);
}

bool isTriangleWord(std::string s) {
    long long int sum = 0;
    for(char& c: s) {
        sum += c - 'A' + 1;
    }
    return isTriangleValue(sum) ? true : false;
}

long long int solve(std::ifstream& ifs) {
    long long int ans = 0;

    std::string word;

    while(std::getline(ifs, word, ',')) {
        if(isTriangleWord(word.substr(1, word.size() - 2)))
            ++ans;
    }

    return ans;
}

int main(int argc, char *argv[]) {
    init(2000);

    assert(isTriangleValue(1));
    assert(isTriangleValue(3));
    assert(isTriangleValue(6));
    assert(isTriangleValue(10));
    assert(isTriangleValue(55));
    assert(isTriangleWord("SKY"));

    std::ifstream ifs(argv[1]);
    std::cout << solve(ifs) << std::endl;
    return 0;
}
