#include<iostream>
#include<cstdio>

using namespace std;

int R,C;
char K,T;
char board[1000][1000];

void fill(int y, int x){
    board[y][x] = K;
    if(y>0)
        if(board[y-1][x]==T)
            fill(y-1,x);
    if(x>0)
        if(board[y][x-1]==T)
            fill(y,x-1);
    if(y<R-1)
        if(board[y+1][x]==T)
            fill(y+1,x);
    if(x<C-1)
        if(board[y][x+1]==T)
            fill(y,x+1);
}

int main(){
    cin >> R >> C;
    char temp;
    for(int i= 0; i < R; i++)
        for(int j = 0; j < C; j++){
            scanf(" %c",&board[i][j]);
        }
    int Y,X;
    cin >> Y >> X >> K;
    T = board[Y][X];
    if(T!=K) fill(Y,X);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++)
            printf("%c",board[i][j]);
        printf("\n");
    }
    return 0;
}
