#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cc;

struct edge {
    int u,v;
    double w;
    edge(int _u, int _v, double _w) : u(_u), v(_v) , w(_w) {}
    edge(){}
    bool operator < (const edge &e) const {
        return w < e.w;
    }
};

const int MX_N = 1001;

int p[MX_N];

int find(int i) { return p[i] = (i==p[i] ? i : find(p[i])); }

bool join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa!=pb){
        p[pa]=pb;
        return true;
    }
    return false;
}

int main(){
    int T; scanf("%d",&T);
    while(T-->0){
        int N; scanf("%d",&N);
        cc points[N];
        double _x,_y;
        for(int i = 0; i < N; i++){
            p[i]=i;
            scanf("%lf %lf",&_x,&_y);
            points[i] = cc(_x,_y);
        }
        vector<edge> edges;
        for(int i = 0; i < N; i++)
            for(int j = i+1; j < N; j++)
                edges.push_back(edge(i,j,abs(points[i]-points[j])));
        sort(edges.begin(), edges.end());
        double cost = 0.0;
        for(auto i = edges.begin(); i != edges.end(); i++){
            if(join(i->u,i->v))
                cost+=i->w;
        }
        printf("%.2lf\n",cost);
        if(T > 0)
            putchar('\n');
    }
    return 0;
}
