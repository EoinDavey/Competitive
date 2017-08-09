#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MX_N = 111;
const int MX_S = 30003;
const int INF = 1000000;
int N,S;

int memo[MX_N][MX_S];
int reached[MX_S];
int a[MX_N];

int ways(int k, int w){
    if(memo[k][w]!=-1)
        return memo[k][w];
    if(k==N-1 && w <= 0)
        return memo[k][w] = w==0;
    return memo[k][w] = (k<N-1? ways(k+1,w):0) + (w>=a[k] ? ways(k, w-a[k]):0);
}

void pr(int k, int w){
    if(k==N-1 && w <= 0)
        return;
    if(k<N-1 && memo[k+1][w]==1)
        pr(k+1,w);
    else if(w>=a[k] && memo[k][w-a[k]]==1){
        printf("%d ",k+1);
        pr(k,w-a[k]);
    }
}


int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    int tot=0;
    for(int i = 0; i < N; i++)
        tot+=a[i];
    int lim = min(tot+1,MX_S);
    memset(memo,-1,sizeof(memo));

    int M;scanf("%d",&M);
    for(int i = 0; i < M; i++){
        scanf("%d",&S);
        int ans = ways(0,S);
        if(ans==0){
            puts("Impossible");
        } else if(ans==1){
            pr(0,S);
            putchar('\n');
        } else {
            puts("Ambigous");
        }
    }
    return 0;
}
