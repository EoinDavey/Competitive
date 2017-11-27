#include<bits/stdc++.h>
using namespace std;

const int MX_A = 10000100;
const int MX_N = 1000100;

int sieve[MX_A];
unordered_set<int> mp[MX_N];
int N;
int a[MX_N],par[MX_N];
int l[MX_N],r[MX_N];

inline void pf(unordered_set<int>& out, int x){
    while(x > 1){
        out.insert(sieve[x]);
        x/=sieve[x];
    }
}

inline int getRoot(int L, int R){
    if(L>R)
        return -1;
    for(int d = 0; d < R-L+1; ++d){
        if(l[L+d] < L && r[L+d] > R)
            return L+d;
        if(l[R-d] < L && r[R-d] > R)
            return R-d;
    }
    return -1;
}

bool build(int L, int R, int p){
    if(L > R)
        return true;
    int ind = getRoot(L,R);
    if(ind == -1)
        return false;
    par[ind] = p;
    return build(L,ind-1,ind) && build(ind+1,R,ind);
}

int main(){
    for(int i = 2; i<MX_A; i++){
        if(sieve[i]==0)
            for(int j = i; j < MX_A; j+=i)
                sieve[j]=i;
    }
    scanf("%d",&N);
    memset(l,-1,sizeof(l));
    for(int i = 0; i < N; ++i) r[i]=MX_N+1;
    bool hasOne = false;
    for(int i = 0; i < N;++i){
        scanf("%d",a+i);
        pf(mp[i],a[i]);
        if(a[i]==1)
            hasOne=true;
    }
    unordered_map<int,int> prs;
    for(int i = 0; i < N; ++i){
        for(auto c : mp[i]){
            if(prs.count(c) > 0)
                l[i] = max(l[i],prs[c]);
            prs[c]=i;
        }
        if(a[i] != 1 && prs.count(1) > 0)
            l[i] = max(l[i],prs[1]);
        if(a[i]==1)
            prs[1]=i;
    }
    prs.clear();
    for(int i = N-1; i >= 0; --i){
        for(auto c : mp[i]){
            if(prs.count(c) > 0)
                r[i] = min(r[i],prs[c]);
            prs[c]=i;
        }
        if(a[i]!=1 && prs.count(1) > 0)
            r[i] = min(r[i],prs[1]);
        if(a[i]==1)
            prs[1]=i;
    }
    if(build(0,N-1,-1)){
        for(int i = 0; i < N; ++i)
            printf("%d ",par[i]+1);
        putchar('\n');
    } else
        puts("impossible");
    return 0;
}
