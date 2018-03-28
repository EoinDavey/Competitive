#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    ll x, y;
    bool operator < (const point &p) const {
        if(x!=p.x)
            return x < p.x;
        return y < p.y;
    }
    bool operator==(const point &p) const {
        return x==p.x&&y==p.y;
    }
    point operator+(const point &p) const {
        return {x+p.x,y+p.y};
    }
    point operator-(const point &p) const {
        return {x-p.x,y-p.y};
    }
};

const int MX_N = 10002;
int perm[MX_N];
point V[MX_N];
int N;

inline ll cross(const point& a, const point& b){
    return a.x*b.y - a.y*b.x;
}

inline bool ccw(const point& a,const point& b, const point& c){
    if(a==b || b==c || a==c)
        return false;
    point u = b-c;
    point v = b-a;
    ll cr = cross(u,v);
    return cr > 0LL;
}

int main(){
    while(scanf("%d",&N),N){
        set<point> ins;
        point p;
        int ln = 0;
        for(int i = 0; i < N; i++){
            perm[i]=i;
            scanf("%lld %lld",&p.x,&p.y);
            if(ins.count(p) > 0)
                continue;
            V[ln++] = p;
            ins.insert(p);
        }
        if(ln==1){
            puts("1");
            printf("%lld %lld\n",V[0].x,V[0].y);
            continue;
        }
        sort(perm,perm+ln,[](int a, int b){return V[a] < V[b];});
        vector<int> L; vector<int> U;
        for(int i = 0; i < ln;){
            int t = L.size();
            if(t >= 2 && !ccw(V[L[t-2]],V[L[t-1]],V[perm[i]]))
                L.pop_back();
            else
                L.push_back(perm[i++]);
        }
        for(int i = ln-1; i >=0;){
            int t = U.size();
            if(t >= 2 && !ccw(V[U[t-2]],V[U[t-1]],V[perm[i]]))
                U.pop_back();
            else
                U.push_back(perm[i--]);
        }
        vector<int> hull;
        for(int i = 0; i < L.size()-1; ++i)
            hull.push_back(L[i]);
        for(int i = 0; i < U.size()-1; ++i)
            hull.push_back(U[i]);
        if(hull.size()==2 && V[hull[0]] == V[hull[1]]){
            puts("1");
            printf("%lld %lld\n",V[hull[0]].x,V[hull[1]].y);
        } else {
            printf("%d\n",hull.size());
            for(auto h : hull)
                printf("%lld %lld\n",V[h].x,V[h].y);
        }
    }
    return 0;
}
