#include <stdio.h>
#include <time.h>

#define TEAMWORK 0
#define POWERUP 1
#define END 2

extern void init(int N, int P[100000]);
extern void powerup(int x, int y);
extern int teamwork(int x, int y);

int N;
int P[100000];

void get_input() {
    scanf("%d",&N);

    for(int i=0; i<N; i++)
        scanf("%d",&P[i]);
}

int main() {
    clock_t start = clock();
    freopen("sample_input.txt", "r", stdin);
    int T;
    scanf("%d",&T);

    for(int case_num=1; case_num<=T; case_num++) {
        get_input();

        init(N,P);

        while(true) {
            int command;
            scanf("%d", &command);
            
            if(command==END)
                break;
            else if(command==POWERUP) {
                int x,y;
                scanf("%d %d",&x,&y);
                powerup(x,y);
            }
            else if(command==TEAMWORK) {
                int a,b;
                scanf("%d %d",&a,&b);
                printf("%d ", teamwork(a,b));
            }
        }
	printf("\n");
    }
    printf("execution_time: %.4f\n", (double) (clock() - start) / CLOCKS_PER_SEC * 1000);
    return 0;
}
