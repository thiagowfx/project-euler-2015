/*
 * What is the sum of all the minimal product-sum numbers for 2 ≤ k ≤ 12000?
 * Adapted from: http://www.mathblog.dk/project-euler-88-minimal-product-sum-numbers/
 */
#include <bits/stdc++.h>

long long int solve(long long int K = 12000) {
    long long int maxNumber = 2 * K;
    long long int numFactors = log10(maxNumber) / log10(2);

    std::vector<long long int> factors(numFactors, 0);
    factors[0] = 1;

    std::vector<long long int> k(K + 1, 0);
    long long int tam = k.size();
    for(unsigned i = 0; i < tam; ++i) {
        k[i] = 2 * i;
    }
    k[1] = 0;

    long long int curMaxFactor = 1;
    long long int j = 0;

    while(true) {

        // first factor
        if(!j) {

            // used all possible factors
            if (curMaxFactor == numFactors)
                break;

            // increment is possible
            if (factors[0] < factors[1]) {
                ++factors[0];
            }

            // adding other factor
            else {
                ++curMaxFactor;
                factors[curMaxFactor - 1] = std::numeric_limits<long long int>::max();
                factors[0] = 2;
            }

            ++j;
            factors[1] = factors[0] - 1;
        }

        // max factor
        else if (j == curMaxFactor - 1) {
            ++factors[j];
            long long int sum = 0;
            long long int prod = 1;

            for (long long int i = 0; i < curMaxFactor; ++i) {
                prod *= factors[i];
                sum += factors[i];
            }

            // limit exceeded
            if (prod > maxNumber) {
                --j;
            }

            // check the result
            else {
                long long int pk = prod - sum + curMaxFactor;
                if (pk <= K && prod < k[pk]) {
                    k[pk] = prod;
                }
            }
        }

        else if (factors[j] < factors[j + 1]) {
            ++factors[j];
            factors[j + 1] = factors[j] - 1;
            ++j;
        }

        else if (factors[j] >= factors[j + 1]) {
            --j;
        }
    }

    // sum everything up
    long long int ans = 0;
    std::set<long long int> s(k.begin(), k.end());
    for (std::set<long long int>::iterator it = s.begin(); it != s.end(); ++it) {
        ans += *it;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    std::cout << solve(atoll(argv[1])) << std::endl;
    return 0;
}
