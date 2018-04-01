#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 1000*1000 + 2;
const int INF = 1000*1000*1000;
int N,Tx,Ty;

struct liz {
    int x,y,h;
    int dist() const {
        if(abs(x-Tx)==0)
            return abs(y-Ty);
        return abs(x-Tx);
    }
    bool operator<(const liz &p) const {
        return dist() < p.dist();
    }
};
map<ii,vector<liz> > rows;

int lis(const vector<liz> &ls){
    int n = ls.size();
    int I[n+1];
    for(int i = 1; i < n+1; ++i)
        I[i]=INF;
    I[0] = -INF;
    int mx = 1;
    for(int i = 0; i < n; ++i){
        int ind = lower_bound(I,I+n+1,ls[i].h) - I;
        I[ind] = ls[i].h;
        mx = max(mx,ind);
    }
    return mx;
}

int main(){
    scanf("%d %d",&Tx,&Ty);
    scanf("%d",&N);
    int x,y,h;
    for(int i= 0; i < N; ++i){
        scanf("%d %d %d",&x,&y,&h);
        int dx = x - Tx;
        int dy = y - Ty;
        int g = abs(__gcd(dx,dy));
        rows[{dx/g,dy/g}].push_back({x,y,h});
    }
    int sm = 0;
    for(auto & p : rows){
        sort(p.second.begin(),p.second.end());
        sm+=lis(p.second);
    }
    printf("%d\n",sm);
    return 0;
}
