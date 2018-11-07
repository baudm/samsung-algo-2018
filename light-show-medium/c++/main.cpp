#include <stdio.h>
#include <time.h>

extern int solve(int N, int M, int L[10], int B[10][3], int out[]);

int N,M;
int L[10];
int B[10][3];
int out[10];

void get_input() {
    scanf("%d %d",&N,&M);

    for(int i=0; i<M; i++) {
        scanf("%d",&L[i]);

        for(int j=0; j<L[i]; j++)
            scanf("%d",&B[i][j]);
    }
}

int main() {
    freopen("sample_input.txt", "r", stdin);
    clock_t start = clock();
    int T;
    scanf("%d",&T);

    for(int case_num=1; case_num<=T; case_num++) {
        get_input();

        for(int i=0; i<10; i++)
            out[i] = -1;
        
        int ret = solve(N,M,L,B,out);

        for(int i=0; i<ret; i++) {
            if(i>0)
                printf(" ");
            printf("%d",out[i]);
        }
        printf("\n");
    }

    printf("execution_time: %.4f\n", (double) (clock() - start) / CLOCKS_PER_SEC * 1000);
    return 0;
}