/*
 * How many different ways can £2 be made using any number of coins?
 */

#include <bits/stdc++.h>

const int LOOKUP[] = {200, 100, 50, 20, 10, 5, 2, 1};
const int COINS = sizeof(LOOKUP)/sizeof(int);

long long int recurse(long long int money, int index_base) {
    // the end
    if(money < 0)
        return 0;
    if(money == 0)
        return 1;
    if(index_base == COINS)
        return 0;

    return recurse(money - LOOKUP[index_base], index_base) +
           recurse(money, index_base + 1);
}

long long int solve(long long int money) {
    return recurse(money, 0);
}

int main(int argc, char *argv[]) {
    long long int money = atoll(argv[1]);
    std::cout << solve(money) << std::endl;
    return 0;
}
