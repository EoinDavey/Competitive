#include<iostream>
#include<cstdio>

using namespace std;

const int MX_N = 33333;

int p[MX_N];
int sz[MX_N];

void insert(int i){
    p[i]=i;
    sz[i]=1;
}

int find(int i){
    if(p[i]==i)
        return i;
    return p[i]=find(p[i]);
}

void join(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa==pb)
        return;
    if(sz[pa]<sz[pb]){
        int t = pa;
        pa = pb;
        pb = t;
    }
    p[pb]=pa;
    sz[pa]+=sz[pb];
}

int main(){
    int _T;scanf("%d",&_T);
    while(_T--){
        int N,M;scanf("%d %d",&N,&M);
        for(int i = 0; i < N; i++)
            insert(i);
        int _a,_b;
        for(int i = 0; i < M; i++){
            scanf("%d %d",&_a,&_b);
            _a--; _b--;
            join(_a,_b);
        }
        int mx = 0;
        for(int i = 0; i < N; i++){
            mx = max(mx, sz[find(i)]);
        }
        printf("%d\n",mx);
    }
    return 0;
}
