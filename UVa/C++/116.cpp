#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N,M;
int board[20][200];
int memo[20][200];
const int INF = 100000000;

const int moves[3] ={-1,0,1};

inline int mod(int n,int k){
    return ((n % k) + k) % k;
}

int solve(int r, int c){
    if(c==M)
        return memo[r][c] = 0;
    if(memo[r][c]!=-1)
        return memo[r][c];
    int m = INF;
    for(int i = 0; i < 3; i++)
        m = min(m, solve(mod(r+moves[i],N),c+1));
    m+=board[r][c];
    return memo[r][c] = m;
}

void print(int r, int c){
    int t,m,n;
    m = n = INF;
    for(int i = 0; i < 3; i++){
        t = memo[mod(r+moves[i],N)][c+1];
        if(t < m)
            m = t,n=mod(r+moves[i],N);
        if(m==t)
            n = min(n,mod(r+moves[i],N));
    }
    printf("%d",r+1);
    if(c<M-1){
        putchar(' ');
        print(n,c+1);
    }
}

int main(){
    while(scanf("%d %d",&N,&M)==2){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                scanf("%d",&board[i][j]);
        memset(memo,-1,sizeof(memo));
        int b = INF, ind = 0;
        for(int i = 0; i < N; i++){
            int c = solve(i,0);
            if(c < b)
                b=c,ind=i;
        }
        print(ind,0);
        printf("\n%d\n",b);
    }
    return 0;
}
