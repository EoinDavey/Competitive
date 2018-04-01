#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX_N = 15;
int N,b,t,sz;
ll d[MX_N][MX_N],L;
vector<int> bs,ts;
set<ll> ls;

bool checkSubs(int md){
    sort(bs.begin(),bs.end());
    sort(ts.begin(),ts.end());
    ls.clear();
    if(b > 0){
        do {
            ll dis = d[0][bs[0]];
            for(int i = 0; i < b-1;++i)
                dis+=d[bs[i]][bs[i+1]];
            dis+=d[bs[b-1]][md];
            ls.insert(dis);
        } while(next_permutation(bs.begin(),bs.end()));
    } else {
        ls.insert(d[0][md]);
    }
    if(t > 0){
        do {
            ll dis = d[md][ts[0]];
            for(int i = 0; i < t-1;++i)
                dis+=d[ts[i]][ts[i+1]];
            dis+=d[ts[t-1]][0];
            if(ls.count(L-dis) > 0)
                return true;
        } while(next_permutation(ts.begin(),ts.end()));
    } else {
        if(ls.count(L-d[md][0]) > 0)
            return true;
    }
    return false;
}

bool part(int md){
    for(int i = 0; i < (1<<N); ++i){
        int bcnt = 0;
        int tcnt = 0;
        for(int j = 1; j < N; ++j)
            if(j==md)
                continue;
            else if((i&(1<<j))!=0 && bcnt < b)
                bs[bcnt++] = j;
            else if((i&(1<<j))==0 && tcnt < t)
                ts[tcnt++] = j;
        if(bcnt!=b || tcnt!=t)
            continue;
        if(checkSubs(md))
            return true;
    }
    return false;
}

int main(){
    scanf("%d %lld",&N,&L);
    sz = N-2;
    b = sz/2;
    t = sz-b;
    bs.assign(b,0);
    ts.assign(t,0);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%lld",&d[i][j]);
    for(int i = 1; i < N; ++i){
        if(part(i)){
            puts("possible");
            return 0;
        }
    }
    puts("impossible");
    return 0;
}
