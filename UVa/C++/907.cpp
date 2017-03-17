#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int N,K;
int idis[606];
int dis[606];
int memo[606][303];
int INF = 1000000;

int dp(int pos, int depth, int nights){
    if(pos == N-1) return 0;
    if(nights == 0) return INF;
    if(memo[pos][nights]!=-1) return memo[pos][nights];
    int mn = INF;
    for(int i = pos+1; i < N; i++){
        int t = max(dis[i]-dis[pos], dp(i,depth+1,nights-1));
        if(t < mn)mn = t;
    }
    return memo[pos][nights] = mn;
}

int main(){
    while(cin >> N >> K){
        memset(memo,-1,sizeof(memo));
        N+=2;
        K++;
        dis[0] = idis[0] = 0;
        for(int i =1; i < N; i++){
            scanf("%d",&idis[i]);
            dis[i]=idis[i]+dis[i-1];
        }
        cout << dp(0,0,K) << endl;
    }
    return 0;
}
