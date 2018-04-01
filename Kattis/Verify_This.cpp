#include<bits/stdc++.h>
using namespace std;
const int MX_N = 5005;
bool board[MX_N][MX_N];
int N;

inline bool check(){
    bitset<MX_N> rd,ld;
    for(int i = 0; i < N; ++i){
        bool b = false;
        for(int j = 0; j < N; ++j){
            if((b || rd[j] || ld[j]) && board[i][j]){
                return false;
            }else if(board[i][j]){
                b = true;
                rd[j] = true;
                ld[j] = true;
            }
        }
        rd <<= 1;
        ld >>=1;
    }
    for(int i = 0; i < N; ++i){
        bool b = false;
        for(int j = 0; j < N; ++j)
            if(b && board[j][i])
                return false;
            else
                b|=board[j][i];
    }
    return true;
}

int main(){
    scanf("%d",&N);
    int x,y;
    for(int i = 0; i < N; ++i){
        scanf("%d %d",&x,&y);
        board[x][y] = true;
    }
    if(check())
        puts("CORRECT");
    else
        puts("INCORRECT");
    return 0;
}
