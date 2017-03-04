#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int N, M;
char board[200][200];
long long memo[200][200];
long long mod = ((long long) pow(10,9)) + 7;

long long dp(int y, int x){
    if(memo[y][x]!=-1)
        return memo[y][x];
    if(y==N-1 && x == M-1){
        return 1;
    }
    long long sum = 0;
    if(y<N-1)
        if(board[y+1][x] == '.'){
            sum+=dp(y+1,x);
            sum = sum % mod;
        }
    if(x<M-1){
        if(board[y][x+1] == '.'){
            sum+=dp(y,x+1);
            sum = sum % mod;
        }
    }
    return memo[y][x] = sum;
}

int main(){
    memset(memo,-1,sizeof(memo));
    cin >> N >> M;
    for(int i= 0; i < N; i ++){
        for(int j = 0; j < M; j++)
            scanf(" %c",&board[i][j]);
    }
    cout << dp(0,0) << endl;
    return 0;
}
