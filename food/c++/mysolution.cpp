#include <cstring>
#include <algorithm>
#include <iostream>

int copy[100000];

int solve(int N, int D[100000]) {
    memcpy(copy, D, N * sizeof(int));
    std::sort(copy, copy + N);
    // get median
    int x = N / 2;
    if (N % 2 == 0) {
        x++;
    }
    int target = copy[x];
    /*
    for (int i = 0; i < N; i++) {
        std::cout << "i = " << i << ", " << copy[i] << std::endl;
    }
    */
    //std::cout << "target = " << target << std::endl;
    int i;
    for (i = 0; i < N; i++) {
        if (D[i] == target) {
            break;
        }
    }
    return i;
}
