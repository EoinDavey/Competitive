#include<bits/stdc++.h>
using namespace std;
string S = "ICPCASIASG";
const int MX_N = 101;
int N;
int moves[][2] = {{-1,2},{1,2},{-1,-2},{1,-2},{-2,1},{-2,-1},{2,1},{2,-1}};
char board[MX_N][MX_N];

bool valid(int x, int y) { return x >= 0 && y >= 0 && x < N && y < N;}
bool search(int x, int y, int k){
    if(k==10)
        return true;
    for(int l = 0; l < 8; ++l){
        int nx,ny;
        nx = x+moves[l][0];
        ny = y+moves[l][1];
        if(valid(nx,ny) && board[nx][ny]==S[k])
            if(search(nx,ny,k+1))
                return true;
    }
    return false;
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) scanf(" %c",&board[i][j]);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if(board[i][j]=='I' && search(i,j,1)){
                puts("YES");
                return 0;
            }
    puts("NO");
    return 0;
}
