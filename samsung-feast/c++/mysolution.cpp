#include <algorithm>
#include <vector>
#include <numeric>
#include <cstdint>

int solve(int N, char A[2][10001]) {
    std::vector<int_fast8_t> line1;
    std::vector<int_fast8_t> line2;
    
    // By choosing elements from the set {-1, 0, 1}, and setting E = -1 (or 1), I = 1 (or -1), and L = 0,
    // we can represent the lines as N-dim vectors, V1 and V2.
    // The HP can be easily computed by calculating the dot product, i.e. HP = V1 * V2
    //
    // We can then model the problem as finding the maximum dot product between V1 (or V2)
    // and all the cyclic permutations of the other vector.
    
    // Lookup table to translate from char values to values suited for vector representation:
    // The numeric values of E, I, and L are very close to each other, so we can afford to
    // create a small lookup table and just add dummy values in between.
    //                              E           I        L
    static int_fast8_t lookup[] = {-1, 0, 0, 0, 1, 0, 0, 0};
    
    for (int i = 0; i < N; i++) {
        line1.push_back(lookup[A[0][i] - 'E']);
        line2.push_back(lookup[A[1][i] - 'E']);
    }
    
    int max_score = 0;
    
    for (int i = 0; i < N; i++) {
        int score = std::inner_product(line1.begin(), line1.end(), line2.begin(), 0);
        if (score > max_score) {
            max_score = score;
        }
        // Get next permutation of V1
        std::rotate(line1.begin(), line1.begin() + 1, line1.end());
    }
    
    return max_score;
}
