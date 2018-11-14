#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef complex<double> pt;
typedef vector<int> district;
const int MX_DSZ = 16;
const int MX_PRS = 25;
const int MX_PTS = 500;
const double INF = 1e10;
double tspMem[MX_DSZ][1<<MX_DSZ];
double prMemo[1<<MX_PRS];
vector<district> distrs;
double pDists[MX_PRS][MX_PRS];
double dists[MX_PTS][MX_PTS];
vector<pt> points;
int D;

double tsp(const district& d){
    for(int p = 1; p < d.size(); ++p)
            tspMem[p-1][0] = dists[d[p]][d[0]];
    for(int state = 1; state < 1<<(d.size()-1); ++state){
        for(int p = 1; p < d.size(); ++p){
            tspMem[p-1][state] = INF;
            if((state&(1<<(p-1)))!=0)
                continue;
            for(int k = 1; k < d.size(); ++k){
                if((state&(1<<(k-1)))==0)
                    continue;
                tspMem[p-1][state] = min(tspMem[p-1][state],
                        dists[d[p]][d[k]] + tspMem[k-1][state^(1<<(k-1))]);
            }
        }
    }
    double mn = INF;
    for(int i = 1; i< d.size(); ++i)
        mn = min(mn, dists[d[0]][d[i]] + tspMem[i-1][((1<<(d.size()-1))-1)^(1<<(i-1))]);
    return mn;
}

double pairDp(){
    prMemo[0] = 0.0;
    for(int state = 1; state < (1 << (D/2)); ++state){
        int p = __builtin_popcount(state) - 1;
        prMemo[state] = INF;
        for(int i = 0; i < D/2; ++i)
            if((state&(1<<i))!=0)
                prMemo[state] = min(prMemo[state], pDists[p][i] + prMemo[state^(1<<i)]);
    }
    return prMemo[(1<<(D/2))-1];
}

inline double tspJoin(const district& a, const district& b){
    district nD(a);
    nD.insert(nD.end(), b.begin(), b.end());
    return tsp(nD);
}

int main(){
    scanf("%d", &D);
    distrs.resize(D);
    for(int i =0; i < D; ++i){
        int N; scanf("%d",&N);
        distrs[i].resize(N);
        int x,y;
        for(int j = 0;j < N; ++j){
            scanf("%d %d",&x,&y);
            points.pb({x,y});
            distrs[i][j] = points.size()-1;
        }
    }
    for(int i = 0; i < points.size(); ++i)
        for(int j = 0; j < i; ++j)
            dists[i][j] = dists[j][i] = abs(points[i] - points[j]);
    double prior = 0.0;
    for(int i = 0; i < D;++i)
        prior+=tsp(distrs[i]);
    for(int i = 0; i < D/2; ++i)
        for(int j = 0; j < D/2; ++j)
            pDists[i][j] = tspJoin(distrs[i], distrs[j+D/2]);
    printf("%.8lf %.8lf\n", prior, pairDp());
}
