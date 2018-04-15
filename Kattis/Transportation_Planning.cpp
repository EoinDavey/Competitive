#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 101;
const double INF = 1e10;
const double EPS = 1e-8;
int N;
ii pts[MX_N];
double dist[MX_N][MX_N];

double eucDist(ii x, ii y){
    double dx = x.first - y.first;
    double dy = x.second - y.second;
    return sqrt(dx*dx + dy*dy);
}

int main(){
    while(scanf("%d",&N),N){
        for(int i = 0; i < N; ++i)
            scanf("%d %d",&pts[i].first,&pts[i].second);
        for(int i = 0; i < N; ++i)
            for(int j = i+1; j < N; ++j)
                dist[i][j] = dist[j][i] = INF;
        int M; scanf("%d",&M);
        int a,b;
        for(int i = 0; i < M; ++i){
            scanf("%d %d",&a,&b);
            dist[a][b] = dist[b][a] = eucDist(pts[a],pts[b]);
        }
        for(int k =0; k < N; ++k)
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        double sm = 0;
        for(int i = 0; i < N; ++i)
            for(int j = i+1; j < N; ++j)
                sm+=dist[i][j];
        double nmn = INF;
        for(int i = 0; i < N; ++i){
            for(int j = i+1; j < N; ++j){
                double cst = 0.0;
                double d = eucDist(pts[i],pts[j]);
                for(int k = 0; k < N; ++k)
                    for(int l = k+1; l < N; ++l)
                        cst+=min(dist[k][l],min(dist[k][i]+d+dist[j][l],dist[k][j] + d + dist[i][l]));
                if(cst<nmn+EPS){
                    nmn = cst;
                    a = i; b = j;
                }
            }
        }
        if(nmn < sm)
            printf("adding %d %d reduces %.10lf to %.10lf\n",a,b,sm,nmn);
        else
            printf("no addition reduces %.10lf\n",sm);
    }
    return 0;
}
