#include<bits/stdc++.h>
using namespace std;
typedef uint32_t state;
constexpr int N = 23,INF=50;

int memo[1<<23];

int dp(state s){
    if(memo[s]!=-1)
        return memo[s];
    bool mv=false;
    int mn = INF;
    for(int i = 0; i < N; ++i){
        if((s&(1<<i))==0)
            continue;
        if(i < N-3){
            if((s&(1<<(i+1)))!=0 && (s&(1<<(i+2)))==0){
                mn = min(mn, dp(((s ^ (1<<i)) ^ (1<<(i+1))) ^ (1<<(i+2))));
                mv = true;
            }
        }
        if(i > 2){
            if((s&(1<<(i-1)))!=0 && (s&(1<<(i-2)))==0){
                mn = min(mn, dp(((s ^ (1<<i)) ^ (1<<(i-1))) ^ (1<<(i-2))));
                mv = true;
            }
        }
    }
    if(!mv){
        int cnt = 0;
        for(int i = 0; i < N; ++i)
            if((s&(1<<i))!=0)
                cnt++;
        return memo[s]=cnt;
    }
    return memo[s] = mn;
}

int main(){
    memset(memo,-1,sizeof(memo));
    int T; scanf("%d",&T);
    char buff[30];
    for(int i = 0; i < T; i++){
        scanf(" %s",buff);
        state s = 0;
        for(int j = 0; j < N; ++j)
            if(buff[j]=='o')
                s |= (1<<j);
        printf("%d\n",dp(s));
    }
    return 0;
}
