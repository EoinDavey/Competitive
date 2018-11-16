#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int MX_N = 2 * 100 * 1000 + 2;
int N, K;
int s[MX_N];
int cnt[MX_N];
struct pr {
    int c, v;
    bool operator<(const pr& p) const {
        if(c!=p.c)
            return c < p.c;
        return v < p.v;
    }
};

bool pos(int t, bool prt){
    priority_queue<pr> q;
    for(int i = 0; i < MX_N; ++i){
        if(cnt[i])
            q.push({cnt[i], i});
    }
    for(int k = 0; k < K; ++k){
        if(q.top().c < t)
            return false;
        int rem = q.top().c - t;
        int v = q.top().v;
        if(prt)
            printf("%d ", v);
        q.pop();
        if(rem > 0)
            q.push({rem, v});
    }
    if(prt)
        putchar('\n');
    return true;
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        scanf("%d",s+i);
        cnt[s[i]]++;
    }
    int L = 1; int R = N; 
    while(L < R){
        int md = (L+R+1)/2;
        if(pos(md, false))
            L = md;
        else
            R = md-1;
    }
    pos(L, true);
    return 0;
}
