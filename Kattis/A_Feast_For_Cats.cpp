#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
    bool operator< (const edge &e) const {
        return w < e.w;
    }
};

const int MX_N = 2002;
int p[MX_N],T,M,C,N;
edge lst[MX_N*MX_N];

int find(int u){ return p[u] = (p[u]==u ? u : find(p[u]));}
int join(const edge &e){
    int pa = find(e.u);
    int pb = find(e.v);
    if(pa==pb)
        return 0;
    p[pa] = pb;
    return e.w;
}

int main(){
    scanf("%d",&T);
    while(T-->0){
        scanf("%d %d",&M,&C);
        N = (C*(C-1))/2;
        for(int i = 0; i < C; ++i)
            p[i]=i;
        for(int i = 0; i < N; ++i)
            scanf("%d %d %d",&lst[i].u,&lst[i].v,&lst[i].w);
        sort(lst,lst+N);
        int cst = 0;
        for(int i = 0; i < N; ++i)
            cst+=join(lst[i]);
        if(cst+C <= M)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
