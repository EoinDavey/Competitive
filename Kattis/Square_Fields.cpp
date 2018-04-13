#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 15;
ii pts[MX_N];
int N,K,SZ;
bool memo[1<<MX_N][MX_N];
bool vis[1<<MX_N][MX_N];

bool dp(int st,int k){
    if(st==(1<<N)-1)
        return true;
    if(k ==0)
        return false;
    if(vis[st][k])
        return memo[st][k];
    vis[st][k] = true;
    for(int i = 0; i < N; ++i){
        if((st&(1<<i))!=0)
            continue;
        for(int j = i+1; j < N; ++j){
            if((st&(1<<j))!=0)
                continue;
            int nst = st;
            ii tc = {max(pts[i].first,pts[j].first),max(pts[i].second,pts[j].second)};
            for(int k = 0; k < N; ++k)
                if(pts[k].first <= tc.first && pts[k].first >= tc.first-SZ
                        && pts[k].second <= tc.second && pts[k].second >= tc.second-SZ)
                    nst|=(1<<k);
            if(dp(nst,k-1))
                return memo[st][k]= true;
        }
    }
    for(int i = 0; i < N; ++i)
        if((st&(1<<i))==0 && dp(st|(1<<i),k-1))
            return memo[st][k] = true;
    return memo[st][k] = false;
}

bool pos(int k){
    SZ = k;
    memset(vis,0,sizeof(vis));
    return dp(0,K);
}

int main(){
    int T; scanf("%d",&T);
    for(int _t = 0; _t < T; _t++){
        scanf("%d %d",&N,&K);
        int x,y;
        for(int i = 0; i < N; ++i)
            scanf("%d %d",&pts[i].first,&pts[i].second);
        int L = 1;
        int R = 64004;
        while(L<R){
            int md = (L+R)/2;
            if(pos(md))
                R = md;
            else
                L = md+1;
        }
        printf("Case #%d: %d\n",_t+1,L);
    }
    return 0;
}
