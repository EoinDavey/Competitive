#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int memo[111][111][11];

int solve(int minX, int maxX, int boxes){
    if(memo[minX][maxX][boxes]!=-1)
        return memo[minX][maxX][boxes];
    if(boxes==1){
        int m = 0;
        for(int i = minX+1; i < maxX; i++)
            m+=i;
        return memo[minX][maxX][boxes] = m;
    }
    if(maxX-minX==1){
        return 0;
    }
    int mx = 10000000;
    for(int i = minX+1; i < maxX; i++){
        int a = i + max(solve(i,maxX,boxes), solve(minX,i,boxes-1));
        mx = min(a,mx);
    }
    return memo[minX][maxX][boxes] = mx;
}

int main(){
    int N;scanf("%d",&N);
    memset(memo,-1,sizeof(memo));
    for(int _n=0; _n<N;_n++){
        int k,m; scanf("%d %d",&k,&m);
        printf("%d\n",solve(0,m+1,k));
    }
    return 0;
}
