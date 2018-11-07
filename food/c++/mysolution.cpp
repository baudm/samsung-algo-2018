#include <array>
#include <algorithm>

static std::array<int, 100000> copy;

int solve(int N, int D[100000]) {
    std::copy(D, D + N, std::begin(copy));
    std::sort(std::begin(copy), std::begin(copy) + N);
    // Instead of manually computing each distance,
    // just get the median of the population.
    int median = N / 2;
    if (N % 2 == 0) {
        median++;
    }
    int target = copy[median];

    for (int i = 0; i < N; i++) {
        if (D[i] == target) {
            return i;
        }
    }
    // Unreachable code
    return -1;
}
