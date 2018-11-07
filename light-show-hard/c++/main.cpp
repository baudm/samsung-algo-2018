#include <stdio.h>

extern long long solve(int N, int M, int L[100000], int B[100000][50]);

int N,M;
int L[100000];
int B[100000][50];

void get_input() {
    scanf("%d %d",&N,&M);

    for(int i=0; i<M; i++) {
        scanf("%d",&L[i]);

        for(int j=0; j<L[i]; j++)
            scanf("%d",&B[i][j]);
    }
}

int main() {
    int T;
    scanf("%d",&T);

    for(int case_num=1; case_num<=T; case_num++) {
        get_input();

        long long ret = solve(N,M,L,B);

        printf("%lld\n",ret);
    }

    return 0;
}