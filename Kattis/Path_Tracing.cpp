#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int x,y,mnx,mxx,mny,mxy;

void check(){
    mnx=min(mnx,x);
    mxx=max(mxx,x);
    mny=min(mny,y);
    mxy=max(mxy,y);
}

int main(){
    char board[1111][1111];
    memset(board,' ',sizeof(board));
    x=y=mnx=mxx=mny=mxy = 520;
    char buff[20];
    while(scanf("%s",buff)==1){
        switch(buff[0]){
            case 'd':
                x+=1;
                break;
            case 'r':
                y+=1;
                break;
            case 'u':
                x-=1;
                break;
            case 'l':
                y-=1;
                break;
        }
        check();
        board[x][y]='*';
    }
    board[520][520]='S';
    board[x][y]='E';
    for(int i = 0; i<=mxy-mny+2; i++)
        putchar('#');
    putchar('\n');
    for(int i = mnx; i <= mxx; i++){
        putchar('#');
        for(int j = mny; j <= mxy; j++)
            printf("%c",board[i][j]);
        puts("#");
    }
    for(int i = 0; i<=mxy-mny+2; i++)
        putchar('#');
    putchar('\n');
    return 0;
}
