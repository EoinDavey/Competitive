#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

struct edge{
    int u,v,w;
    bool operator< (const edge &e) const {
        return w < e.w;
    }
};

const int MX_N = 2002;
int p[MX_N],T,M,C,N,rnk[MX_N];
edge lst[MX_N*MX_N];

int find(int u){ return p[u] = (p[u]==u ? u : find(p[u]));}
inline int join(const edge &e){
    int pa = find(e.u);
    int pb = find(e.v);
    if(pa==pb)
        return 0;
    if(rnk[pa] < rnk[pb])
        swap(pa,pb);
    p[pb] = pa;
    if(rnk[pa]==rnk[pb])
        rnk[pa]++;
    return e.w;
}

inline int read_int(){
    int o = 0;
    char c;
    for(;;){
        c = getchar_unlocked();
        if(c >= '0' && c <= '9')
            break;
    }
    while(c >= '0' && c <= '9'){
        o = o*10 + c - '0';
        c = getchar_unlocked();
    }
    return o;
}

int main(){
    T = read_int();
    while(T-->0){
        memset(rnk,0,sizeof(rnk));
        M = read_int();
        C = read_int();
        N = (C*(C-1))/2;
        for(int i = 0; i < C; ++i)
            p[i]=i;
        for(int i = 0; i < N; ++i){
            lst[i].u = read_int();
            lst[i].v = read_int();
            lst[i].w = read_int();
        }
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
