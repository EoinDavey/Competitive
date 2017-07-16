#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int M; scanf("%d",&M);
    for(int _m = 0; _m < M; _m++){
        int S,N,r1,c1,r2,c2,a[111][111];
        scanf("%d %d",&S,&N);
        memset(a,0,sizeof(a));
        for(int _n = 0; _n < N; _n++){
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            for(int i = r1; i <= r2; i++)
                for(int j = c1; j<=c2; j++)
                    a[i][j]=1;
        }
        for(int i = 1; i <= S; i++)
            for(int j = 1; j <= S; j++)
                a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        int best = 0;
        for(r1 = 1; r1 <= S; r1++)
            for(c1 = 1; c1 <= S; c1++)
                for(r2 = r1; r2 <= S; r2++)
                    for(c2 = c1; c2 <= S; c2++)
                        if(!(a[r2][c2] - a[r1-1][c2] - a[r2][c1-1] + a[r1-1][c1-1]))
                            best = max(best,(r2-r1+1)*(c2-c1+1));
        printf("%d\n",best);
    }
    return 0;
}
