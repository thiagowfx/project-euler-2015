#include <bits/stdc++.h>
const long long int LIMIT = 1e8;

std::function<long long int(int)> getPentagonal;
std::function<bool(long long int)> isPentagonal;

void populate(long long int limit = LIMIT) {
    auto pentagonal = [](long long int n) -> long long int {
        return n * (3 * n - 1) / 2;
    };
    std::vector<long long int> *pentagonal_v = new std::vector<long long int>();
    std::set<long long int> *pentagonalSet = new std::set<long long int>();
    int n = 1;
    while(true) {
        long long int next = pentagonal(n++);
        if (next > limit)
            break;
        pentagonal_v->push_back(next);
        pentagonalSet->insert(next);
    }
    getPentagonal = [=](int i) -> long long int {
        return pentagonal_v->at(i-1);
    };
    isPentagonal = [=](long long int i) -> bool {
        return pentagonalSet->find(i) != pentagonalSet->end();
    };
}

long long int solve() {
    populate();

    //assert(getPentagonal(1) == 1);
    //assert(getPentagonal(2) == 5);
    //assert(getPentagonal(3) == 12);
    //assert(isPentagonal(1));
    //assert(isPentagonal(5));
    //assert(isPentagonal(12));

    long long int Dmin = std::numeric_limits<long long int>::max();

    for(int i = 1; ; ++i) {
        long long int pentai = getPentagonal(i);
        if(pentai >= (LIMIT / 2))
            break;
        for(int j = 1; ; ++j) {
            long long int pentaj = getPentagonal(j);
            if(pentaj >= pentai)
                break;

            //----------
            long long int D = pentai - pentaj;

            if(!(isPentagonal(pentai + pentaj) && isPentagonal(D)))
                continue;

            if(D < Dmin) {
                Dmin = D;
            }
        }
    }

    return Dmin;
}

int main(int argc, char *argv[]) {
    std::cout << solve() << std::endl;
    return 0;
}
