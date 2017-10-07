#include<bits/stdc++.h>
using namespace std;

struct team{
    int a,b;
    team(int _a, int _b) : a(_a), b(_b){}
    team() : a(0), b(0){}
    bool operator < (const team& t) const {
        if(a!=t.a)
            return a<t.a;
        return b > t.b;
    }
    bool operator > (const team& t) const {
        if(a!=t.a)
            return a>t.a;
        return b < t.b;
    }
};

constexpr int MX_N = 100001;
int N,M;
team ts[MX_N];

int main(){
    set<int> bgr;
    scanf("%d %d",&N,&M);
    int t,p;
    for(int i = 0; i < M; ++i){
        scanf("%d %d",&t,&p);
        --t;
        ts[t].a++,ts[t].b+=p;
        if(t==0){
            set<int> nbgr;
            for(auto b : bgr)
                if(ts[b] > ts[0])
                    nbgr.insert(b);
            bgr = nbgr;
        } else if(ts[t] > ts[0]){
            if(bgr.count(t) <= 0)
                bgr.insert(t);
        }
        printf("%d\n",bgr.size()+1);
    }
    return 0;
}
