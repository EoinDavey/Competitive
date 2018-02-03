#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 1000011;
int N,Q;
int p[MX_N];

int find(int a){ return p[a] = (a==p[a]) ? a : find(p[a]);}

inline void join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa==pb)
        return;
    p[pa]=pb;
}

inline bool same(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa==pb)
        return true;
    return false;
}

int main(){
    scanf("%d %d",&N,&Q);
    int a,b;
    char c;
    for(int i = 0; i < N; ++i)
        p[i]=i;
    for(int i =0; i < Q; ++i){
        scanf(" %c %d %d",&c,&a,&b);
        if(c=='?'){
            if(same(a,b))
                puts("yes");
            else
                puts("no");
        }else {
            join(a,b);
        }
    }
    return 0;
}
