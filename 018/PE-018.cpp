/*
 * Find the maximum total from top to bottom of the triangle below.
 */

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define LINES 15
#define D(x) std::cout << #x << " = " << x << std::endl;

int solve(std::ifstream& ifs) {
    std::vector<int> in[LINES];
    for (unsigned i = 0; i < LINES; ++i) {
        for(unsigned j = 0; j < i + 1; ++j) {
            int tmp;
            ifs >> tmp;
            in[i].push_back(tmp);
        }
    }

    std::vector<int> pd[LINES];
    pd[0].push_back(in[0][0]);
    for (unsigned i = 1; i < LINES; ++i) {
        for(unsigned j = 0; j < i + 1; ++j) {
            int curr = in[i][j];

            if (!j)
                pd[i].push_back(pd[i-1][j] + curr);
            else if (j == i)
                pd[i].push_back(pd[i-1][j - 1] + curr);
            else {
                int greater = std::max(pd[i-1][j], pd[i-1][j-1]);
                pd[i].push_back(greater + curr);
            }
        }
    }

    int ans = -1;
    for (unsigned j = 0; j < LINES; ++j)
        ans = std::max(ans, pd[LINES-1][j]);
    return ans;
}

int main(int argc, char *argv[]) {
    std::ifstream ifs(argv[1]);
    std::cout << solve(ifs) << std::endl;
    return 0;
}
