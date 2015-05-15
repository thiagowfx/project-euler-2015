#include <bits/stdc++.h>

long long int mdc(long long int a, long long int b) {
    if(!b)
        return a;
    return mdc(b, a % b);
}

long long int solve() {
    int ansnum = 1;
    int ansden = 1;

    for(int num = 10; num < 100; ++num) {
        for(int den = num + 1; den < 100; ++den) {
            // trivial examples
            if(num == den || !(den % 10))
                continue;

            std::pair<int,int> n = std::make_pair(num / 10, num % 10);
            std::pair<int,int> d = std::make_pair(den / 10, den % 10);

            if(!(n.first == d.first || n.first == d.second || n.second == d.first || n.second == d.second))
                continue;

            if(n.first == d.first && n.first == d.second && n.second == d.first && n.second == d.second)
                continue;

            int x;

            if(n.first == d.first || n.first == d.second)
                x = n.first;
            else
                x = n.second;

            // other than x:
            int a = (n.first == x ? n.second : n.first);
            int b = (d.first == x ? d.second : d.first);

            if(num * b == den * a) {
                ansnum *= a;
                ansden *= b;
                // the fractions
                // std::cout << num << "/" << den << std::endl;
                // debug
                // std::cout << a << "/" << b << std::endl;
            }
        }
    }

    ansden /= mdc(ansnum, ansden);
    return ansden;
}

int main() {
    std::cout << solve() << std::endl;
    return 0;
}
