#include<iostream>
#include<cstdio>

using namespace std;

const int MAX_N = 50000;

int p[MAX_N];

int parent(int i){
    if(p[i]==i)
        return i;
    return parent(p[i]);
}

bool join(int i, int j){
    int pi = parent(i);
    int pj = parent(j);
    if(pi==pj)
        return false;
    p[pi]=pj;
    return true;
}

int main(){
    int _t = 1;
    while(1){
        int N,M; scanf("%d %d",&N,&M);
        if(N==0&&M==0)
            break;
        for(int i = 0; i < N; i++)
            p[i]=i;
        int _a,_b;
        int religions = N;
        for(int i = 0; i < M; i++){
            scanf("%d %d",&_a,&_b);
            _a--;_b--;
            if(join(_a,_b)){
                religions--;
            }
        }
        printf("Case %d: %d\n",_t++,religions);
    }
    return 0;
}
