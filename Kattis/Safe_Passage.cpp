#include<bits/stdc++.h>
using namespace std;

struct path {
    int st, d;
    bool cp;
    path(int _st,bool _cp, int _d) : st(_st),cp(_cp), d(_d){}
    path(){}
    bool operator< (const path& p) const{
        return d > p.d;
    }
};

constexpr int MX_N=16, INF=1000000000;
int a[MX_N];
int N;

int dist[1 << MX_N][2];

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%d",&a[i]);
    int S = (1<<N) - 1;
    for(int i = 0; i < (1<<N); ++i)
        dist[i][0]=dist[i][1]=INF;
    dist[S][1] = 0;
    priority_queue<path> q;
    q.push(path(S,1,0));
    int st,d,nst,nd;
    bool cp;
    while(!q.empty()){
        path p = q.top(); q.pop();
        st = p.st, d=p.d, cp=p.cp;
        if(dist[st][cp] < d)
            continue;
        if(cp){
            for(int i = 0; i < N; ++i){
                if((st&(1<<i))==0)
                    continue;
                for(int j = i+1; j < N; ++j){
                    if((st&(1<<j))==0)
                        continue;
                    nst = (st^(1<<i))^(1<<j);
                    nd = d + max(a[i],a[j]);
                    if(nd < dist[nst][!cp]){
                        dist[nst][!cp] = nd;
                        q.push(path(nst,!cp,nd));
                    }
                }
            }
        } else {
            for(int i = 0; i < N; ++i){
                if((st&(1<<i))!=0)
                    continue;
                nst = st^(1<<i);
                nd = d + a[i];
                if(nd < dist[nst][!cp]){
                    dist[nst][!cp] = nd;
                    q.push(path(nst,!cp,nd));
                }
            }
        }
    }
    printf("%d\n",dist[0][0]);
    return 0;
}
