int solve(int N, char message[100001], char presses[400001]) {
    static char lookup_table[][5] = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"
    };

    int num_presses = 0;
    for (int i = 0; i < N; i++) {
        char *p = lookup_table[message[i] - 'a'];
        while (*p) {
            presses[num_presses++] = *(p++);
        }
    }
    
    return num_presses;
}
