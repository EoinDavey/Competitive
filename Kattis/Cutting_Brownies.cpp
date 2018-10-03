#include<bits/stdc++.h>
using namespace std;
const int MX_N = 505;
int memo[MX_N][MX_N];

//True if RxC block is lost by H
int dp(int R, int C){
    if(R==1)
        return true;
    if(memo[R][C]!=-1)
        return memo[R][C];
    for(int i = 1; i < R; ++i){
        //split into ixC and (R-i)xC
        //Flip co-ordinates as next player is V
        if(dp(C,i) && dp(C,R-i))
            return memo[R][C] = false;
    }
    return memo[R][C] = true;
}

int main(){
    memset(memo,-1,sizeof(memo));
    int N; scanf("%d",&N);
    char name[10]; int R,C;
    while(N-->0){
        scanf("%d %d %s",&R,&C,name);
        if(name[0]=='H'){
            if(dp(C,R))
                puts("Harry cannot win");
            else
                puts("Harry can win");
        } else {
            if(dp(R,C))
                puts("Vicky cannot win");
            else
                puts("Vicky can win");
        }
    }
    return 0;
}
