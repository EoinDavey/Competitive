#include<bits/stdc++.h>
using namespace std;

char board[8][8];
int rcnt[8];
int ccnt[8];

int main(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            scanf(" %c",&board[i][j]);
    int rdag = 0;
    int ldag = 0;
    bool fail = false;
    int cnt = 0;
    for(int i= 0; i < 8 && !fail; i++){
        for(int j = 0; j < 8 && !fail; j++){
            if(board[i][j]=='*'){
                cnt++;
                if(rcnt[i])
                    fail = true;
                if(ccnt[j])
                    fail = true;
                if((ldag&(1<<j))!=0)
                    fail = true;
                if((rdag&(1<<j))!=0)
                    fail = true;
                ldag |= (1<<j);
                rdag |= (1<<j);
                rcnt[i]++;
                ccnt[j]++;
            }
        }
        rdag <<= 1;
        ldag >>= 1;
    }
    fail |= (cnt!=8);
    if(fail)
        puts("invalid");
    else
        puts("valid");
    return 0;
}
