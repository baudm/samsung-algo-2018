#include <iostream>
#include <cstdint>

static uint_fast32_t order[100000] = {0};

extern void init(int N, int M, int C[100000][2]) {
    // Initial ordering
    for (int i = 0; i < N; i++) {
        order[i] = i;
    }
	for (int i = 0; i < M; i++) {
		int subordinate = C[i][0];
		int superior = C[i][1];
        // swap
        if (order[subordinate] > order[superior]) {
            int tmp = order[subordinate];
            order[subordinate] = order[superior];
            order[superior] = tmp;
        }
	}
	for (int i = 0; i < N; i++) {
        std::cout << "order[" << i << "] = " << order[i] << std::endl;
    }
}

extern int superior(int a, int b) {
    return order[a] > order[b] ? a : b;
}
