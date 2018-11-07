#include <stdio.h>
#include <time.h>
extern void init(int N, int M, int C[100000][2]);
extern int superior(int a, int b);

int N,M,Q;
int C[100000][2];
int query[100000][2];

void get_input() {
    scanf("%d %d",&N,&M);

    for(int i=0; i<M; i++)
        scanf("%d %d",&C[i][0],&C[i][1]);
    
    scanf("%d",&Q);
    for(int i=0; i<Q; i++) {
        scanf("%d %d", &query[i][0], &query[i][1]);
    }
}

int main() {
    clock_t start = clock();
    freopen("sample_input.txt", "r", stdin);
    int T;
    scanf("%d",&T);

    for(int case_num=1; case_num<=T; case_num++) {
        get_input();

        init(N,M,C);
        
        for(int i=0; i<Q; i++)
            printf("%d ",superior(query[i][0],query[i][1]));
	printf("\n");
    }
    printf("execution_time: %.4f\n", (double) (clock() - start) / CLOCKS_PER_SEC * 1000);

    return 0;
}
