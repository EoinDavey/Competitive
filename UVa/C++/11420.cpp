#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int N,S;
long long memo[100][100][2];

long long solve(int k, int s, bool sec){
    if(k==0)
        return ((long long) s==0);
    if(memo[k][s][sec]!=-1)
        return memo[k][s][sec];
    return memo[k][s][sec] = solve(k-1,s,false) + solve(k-1,s-sec,true);
}

int main(){
    memset(memo,-1,sizeof(memo));
    while(1){
        scanf("%d %d",&N,&S);
        if(N<0&&S<0)
            break;
        printf("%lld\n",solve(N,S,true));
    }
    return 0;
}
