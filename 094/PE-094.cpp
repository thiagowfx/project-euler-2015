/*
 * Find the sum of the perimeters of all almost equilateral triangles with
 * integral side lengths and area and whose perimeters do not exceed one billion
 * (1,000,000,000).
 */
#include <bits/stdc++.h>

inline bool triangle_ok(long long int a, long long int area) {
    return a > 0 && area > 0 && !(a % 3) && !(area % 3);
}

long long int solve(long long int LIMIT = 1e9) {
    long long int ans = 0;

    long long int x = 2, y = 1;
    long long int aTimes3, areaTimes3;

    while(true) {
        // case: b = a + 1
        aTimes3 = 2 * x - 1;
        areaTimes3 = y * (x - 2);
        if(aTimes3 > LIMIT)
            break;

        if(triangle_ok(aTimes3, areaTimes3)) {
            long long int a = aTimes3 / 3;
            ans += (a + a + (a + 1));
        }

        // case b = a - 1
        aTimes3 = 2 * x + 1;
        areaTimes3 = y * (x + 2);

        if(triangle_ok(aTimes3, areaTimes3)) {
            long long int a = aTimes3 / 3;
            ans += (a + a + (a - 1));
        }

        // next
        long long int nextx = 2 * x + 3 * y;
        long long int nexty = 2 * y + x;

        std::swap(x, nextx);
        std::swap(y, nexty);
    }

    return ans;
}

int main(int argc, char *argv[]) {
    long long int limit = atoll(argv[1]);
    std::cout << solve(limit) << std::endl;
    return 0;
}
