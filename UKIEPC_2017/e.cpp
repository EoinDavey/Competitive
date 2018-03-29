#include <bits/stdc++.h>
using namespace std;

int N,M;

struct bld{
    int rnt,cap,ind;
    bld(int _r, int _c) : rnt(_r), cap(_c){}
    bld(){}
    bool operator < (const bld& b) const {
        if(rnt!=b.rnt)
            return rnt < b.rnt;
        return cap < b.cap;
    }
};

struct dep {
    int std,ind;
    dep(int _s, int _i) : std(_s), ind(_i){}
    dep(){}
    bool operator < (const dep& d) const {
        return std > d.std;
    }
};

int main() {
    scanf("%d %d",&N,&M);
    dep deps[N];
    bld in[M];
    int out[N];
    bool arr[M]; memset(arr,0,sizeof(arr));
    for(int i = 0; i < N; ++i){
        scanf("%d",&deps[i].std);
        deps[i].ind=i;
    }
    sort(deps,deps+N);
    for(int i = 0; i < M; ++i){
        scanf("%d",&in[i].cap);
        in[i].ind=i;
    }
    for(int i = 0; i < M; ++i)
        scanf("%d",&in[i].rnt);
    sort(in,in+M);
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(!arr[j] && in[j].cap >= deps[i].std){
                arr[j] = true;
                cnt++;
                out[deps[i].ind] = in[j].ind+1;
                break;
            }
        }
    }
    if(cnt==N){
        for(int i = 0; i < N; ++i)
            printf("%d ",out[i]);
        putchar('\n');
    } else
        puts("impossible");
    return 0;
}
