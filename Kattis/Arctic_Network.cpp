#include<bits/stdc++.h>
using namespace std;

constexpr int MX_S = 101,MX_P=500;
constexpr double EPS = 1e-7;
int S,P;
int x[MX_P];
int y[MX_P];
bool vis[MX_P];

inline double dist(int u, int v){
    return sqrt(pow(x[u]-x[v],2) + pow(y[u]-y[v],2));
}

void dfs(int u, double D){
    vis[u] = true;
    for(int i = 0; i < P; i++)
        if(!vis[i] && (dist(u,i) + EPS) <= D)
            dfs(i,D);
}

bool check(double D){
    memset(vis,0,sizeof(vis));
    int cnt = 0;
    for(int i = 0; i < P; i++){
        if(!vis[i]){
            cnt++;
            dfs(i,D);
        }
    }
    if(cnt<=S)
        return true;
    return false;
}

int main(){
    int T; scanf("%d",&T);
    while(T --> 0){
        scanf("%d %d",&S,&P);
        for(int i = 0; i < P; i++)
            scanf("%d %d",&x[i],&y[i]);
        double L,R;
        L = 0.0; R =20000.0;
        while(1){
            if(abs(L-R) < EPS){
                printf("%.2lf\n",L);
                break;
            }
            double md = (L+R)/2.0; if(check(md))
                R=md;
            else
                L=md;
        }
    }
    return 0;
}
