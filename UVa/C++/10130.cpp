#include<iostream>
#include<cstdio>

using namespace std;

int T;

int memo[1002][32];

int solve(int N,int k, int * p, int * w, int rw){
    if(k >= N){
        return 0;
    }
    if(memo[k][rw]!=-1){
        return memo[k][rw];
    }
    if(w[k] > rw){
        return memo[k][rw] = solve(N,k+1,p,w,rw);
    }
    return memo[k][rw] = max(p[k]+solve(N,k+1,p,w,rw-w[k]),solve(N,k+1,p,w,rw));
}

int main(){
    scanf("%d",&T);
    for(int _t = 0; _t < T; _t++){
        int N; scanf("%d",&N);
        int p[N], w[N];
        for(int _n = 0; _n < N; _n++){
            scanf("%d %d",&p[_n],&w[_n]);
        }
        int G; scanf("%d",&G);
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= 30; j++){
                memo[i][j]=-1;
            }
        }
        int tot=0;
        for(int _g = 0; _g < G; _g++){
            int MW; scanf("%d",&MW);
            tot+=solve(N,0,p,w,MW);
        }
        printf("%d\n",tot);
    }
    return 0;
}
