#include<bits/stdc++.h>
using namespace std;

struct window {
    int b,e;
    window(int _b, int _e) : b(_b),e(_e) {}
    window(){}
    bool operator < (const window &w) const {
        if(e != w.e)
            return e < w.e;
        return b < w.b;
    }
};

constexpr int MX_M=1001,MX_P=2002;
int M,P;
window w[MX_M];
bool done[MX_M];

bool wknds(){
    memset(done,0,sizeof(done));
    for(int d = 1; d <= 100; d++){
        int p = P;
        for(int i = 0; i < M;  i++)
            if(!done[i] && w[i].b <= d && p > 1 && w[i].e >= d)
                p-=2,done[i]=true;
    }
    for(int i =0; i < M; i++)
        if(!done[i])
            return false;
    return true;
}

bool noWknds(){
    memset(done,0,sizeof(done));
    for(int d = 1; d <= 100; d++){
        if(d % 7 == 6 || d %7==0)
            continue;
        int p = P;
        for(int i = 0; i < M;  i++)
            if(!done[i] && w[i].b <= d && p > 1 && w[i].e >= d)
                p-=2,done[i]=true;
    }
    for(int i =0; i < M; i++)
        if(!done[i])
            return false;
    return true;
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%d %d",&M,&P);
        for(int i = 0; i < M; ++i)
            scanf("%d %d",&w[i].b,&w[i].e);
        sort(w,w+M);
        if(noWknds())
            puts("fine");
        else if(wknds())
            puts("weekend work");
        else
            puts("serious trouble");
    }
    return 0;
}
