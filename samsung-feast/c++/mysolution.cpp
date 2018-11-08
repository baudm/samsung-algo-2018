#include <algorithm>
#include <vector>
#include <numeric>
#include <limits>
#include <cstdint>

int solve(int N, char A[2][10001]) {
    std::vector<int_fast8_t> V1;
    std::vector<int_fast8_t> V2;
    
    // By choosing elements from the set {-1, 0, 1}, and setting E = -1 (or 1), I = 1 (or -1), and L = 0,
    // we can represent the lines as N-dim vectors, V1 and V2, and we can efficiently compute HP
    // by calculating the dot product of V1 and V2, i.e. HP = V1 * V2
    //
    // We can then model the problem as finding the maximum dot product between V1 (or V2)
    // and all the cyclic permutations of the other vector.
    
    // Lookup table to translate from char values to values suited for vector representation:
    // The numeric values of E, I, and L are very close to each other, so we can afford to
    // create a small lookup table and just add dummy values in between.
    //                              E           I        L
    static int_fast8_t lookup[] = {-1, 8, 8, 8, 1, 8, 8, 0};

    for (int i = 0; i < N; i++) {
        V1.push_back(lookup[A[0][i] - 'E']);
        V2.push_back(lookup[A[1][i] - 'E']);
    }
    
    int max_HP = std::numeric_limits<int>::min();
    for (int i = 0; i < N; i++) {
        int HP = std::inner_product(V1.begin(), V1.end(), V2.begin(), 0);
        if (HP > max_HP) {
            max_HP = HP;
        }
        // Get next permutation of V1
        std::rotate(V1.begin(), V1.begin() + 1, V1.end());
    }
    
    return max_HP;
}
