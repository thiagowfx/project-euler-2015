#include <bits/stdc++.h>
#define SIEVE_UPPER_LIMIT (1e7)

std::vector<bool> sieve(long long int N) {
    std::vector<long long int> primes;
    std::vector<bool> in(N + 1, true);
    in[0] = in[1] = false;

    for(long long int i = 2; i <= N; ++i) {
        if(in[i]) {
            primes.push_back(i);
            for(long long int j = i * i; j <= N; j += i)
                in[j] = false;
        }
    }

    return in;
}

inline long long eval(int a, int b, int n) {
    return n * n + a * n + b;
}

long long int solve(long long int limita, long long int limitb) {
    auto isPrime = sieve(SIEVE_UPPER_LIMIT);

    long long int answer = -1;
    int longest_seq_size = 0;

    for(int a = -(limita - 1); a <= (limita - 1); ++a) {
        for(int b = -(limitb - 1); b <= (limitb - 1); ++b) {
            int k = 0;
            while(true) {
                if(!isPrime[abs(eval(a, b, k))])
                    break;
                else
                    ++k;
            }
            if(k > longest_seq_size) {
                longest_seq_size = k;
                answer = a * b;
            }
        }
    }

    return answer;
}

int main(int argc, char *argv[]) {
    long long int limita = atoll(argv[1]);
    long long int limitb = atoll(argv[2]);
    std::cout << solve(limita, limitb) << std::endl;
    return 0;
}
