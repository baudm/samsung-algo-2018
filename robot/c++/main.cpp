#include <stdio.h>
#include <time.h>
extern int solve(int N, char message[100001], char presses[400001]);

int N;
char message[100001];
char presses[400001];

void get_input() {
    scanf("%d %s",&N,message);
}

int main() {
    clock_t start = clock();
    freopen("sample_input.txt", "r", stdin);
    int T;
    scanf("%d",&T);

    for(int case_num=1; case_num<=T; case_num++) {
        get_input();
        
        int ret = solve(N, message, presses);

        printf("%d ",ret);
        for(int i=0; i<ret; i++)
            printf("%c",presses[i]);
        printf("\n");
    }
    printf("execution_time: %.4f\n", (double) (clock() - start) / CLOCKS_PER_SEC * 1000);

    return 0;
}
