#include<bits/stdc++.h>
using namespace std;
const int INF = 1000*1000*1000;
const int MX_N = 1000*1000;
const int MX_LG = 20;
int mxtable[MX_N][MX_LG];
int mntable[MX_N][MX_LG];
int N,r[MX_N],M,C;

inline int rmxq(int u, int v){
    if(u > v)
        return -INF;
    int k = (int) floor(log2((double) (v-u+1)));
    if(r[mxtable[u][k]] > r[mxtable[v-(1<<k) + 1][k]])
        return r[mxtable[u][k]];
    return r[mxtable[v-(1<<k) + 1][k]];
}

inline int rmnq(int u, int v){
    if(u > v)
        return INF;
    int k = (int) floor(log2((double) (v-u+1)));
    if(r[mntable[u][k]] < r[mntable[v-(1<<k) + 1][k]])
        return r[mntable[u][k]];
    return r[mntable[v-(1<<k) + 1][k]];
}

int main(){
    scanf("%d %d %d",&N,&M,&C);
    for(int i = 0; i < N; ++i)
        scanf("%d",r+i);
    for(int i = 0; i < N; i++)
        mxtable[i][0] = mntable[i][0] = i;
    for(int j = 1; (1 << j) <= N; j++)
        for(int i = 0; i + (1<<j)-1 < N; ++i)
            if(r[mxtable[i][j-1]] > r[mxtable[i + (1 << (j-1))][j-1]])
                mxtable[i][j] = mxtable[i][j-1];
            else
                mxtable[i][j] = mxtable[i+(1<<(j-1))][j-1];
    for(int j = 1; (1 << j) <= N; j++)
        for(int i = 0; i + (1<<j)-1 < N; ++i)
            if(r[mntable[i][j-1]] < r[mntable[i + (1 << (j-1))][j-1]])
                mntable[i][j] = mntable[i][j-1];
            else
                mntable[i][j] = mntable[i+(1<<(j-1))][j-1];
    int cnt = 0;
    for(int i = 0; i < N-M+1; ++i){
        if(rmxq(i,i+M-1) - rmnq(i,i+M-1) <= C)
            printf("%d\n",i+1),cnt++;
    }
    if(!cnt)
        puts("NONE");
    return 0;
}
