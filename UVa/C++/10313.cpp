#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long memo[303][303];

long long solve(int n){
    for(int j = 0; j<=n; j++)
        memo[0][j]=1L;
    for(int i = 1; i <=n; i++)
        for(int j= 1; j <=n; j++)
            memo[i][j] = memo[i][j-1] + (i>=j? memo[i-j][j] : 0L);
}

int main(){
    int N,L1,L2;
    memset(memo,0,sizeof(memo));
    solve(300);
    char buff[40];
    for(int i = 0; i < 7; i++){
        printf("%d: ",i);
        for(int j = 0; j < 7; j++)
            printf("%d ",j);
        putchar('\n');
    }
    while(gets(buff)!=NULL){
        int n = sscanf(buff,"%d %d %d",&N,&L1,&L2);
        switch(n){
            case 1:
                printf("%lld\n",memo[N][300]);
                break;
            case 2:
                L1 = min(300,L1);
                printf("%lld\n",memo[N][L1]);
                break;
            case 3:
                L1 = min(300,L1);
                L2 = min(300,L2);
                printf("%lld\n",memo[N][L2] - (L1>0 ? memo[N][L1-1] : 0));
        }
    }
    return 0;
}
