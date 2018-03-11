#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX_NM=100001;

int N,M;
ll c[MX_NM];
int cnt[MX_NM];
vector<int> adjList[MX_NM];

int trav(int u, int c){
    cnt[u]=c;
    for(auto v : adjList[u])
        if(cnt[v]==-1)
            trav(v,c);
}

int main(){
    memset(cnt,-1,sizeof(cnt));
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; ++i)
        scanf("%lld",c+i);
    int x,y;
    for(int i = 0; i < M; ++i){
        scanf("%d %d",&x,&y);
        x--,y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    int col = 1;
    for(int i = 0; i < N; ++i){
        if(cnt[i]==-1){
            trav(i,col++);
        }
    }
    map<int,ll> mn;
    for(int i = 0; i < N; ++i){
        if(mn.count(cnt[i]) <= 0)
            mn[cnt[i]] = c[i];
        else
            mn[cnt[i]] = min(mn[cnt[i]],c[i]);
    }
    ll sum = 0;
    for(auto v : mn)
        sum+=v.second;
    printf("%lld\n",sum);
    return 0;
}
