#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 5005;
constexpr int MD = 5318008;
int memo[MX_N][MX_N];
int N;
int SX,SY,TX,TY;

constexpr int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int dist(int x1, int y1, int x2, int y2){
    return max(abs(x1-x2),abs(y1-y2));
}

bool valid(int x, int y){
    return x >= 0 && y >= 0 && x < N && y < N;
}

int ways(int x, int y){
    if(x==SX && y == SY)
        return 1;
    if(memo[x][y] != -1)
        return memo[x][y];
    int w = 0;
    for(int i = 0; i < 8; ++i){
        int nx = x+moves[i][0];
        int ny = y+moves[i][1];
        if(valid(nx,ny) && dist(SX,SY,nx,ny) + 1 == dist(SX,SY,x,y))
            w=(w+ways(nx,ny))%MD;
    }
    return memo[x][y] = w % MD;
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        scanf("%d",&N);
        memset(memo,-1,sizeof(memo));
        scanf("%d %d %d %d",&SX,&SY,&TX,&TY);
        --SX,--SY,--TX,--TY;
        printf("%d\n",ways(TX,TY));
    }
    return 0;
}
