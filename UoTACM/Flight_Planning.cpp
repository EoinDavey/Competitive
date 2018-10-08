#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef complex<double> cc;
typedef vector<int> vi;
const int MX_N = 2505;
const int INF = 1000*1000;
bool adjMat[MX_N][MX_N];
vi adjList[MX_N];
vector<ii> edgeList;
bool vis[MX_N];
int p[MX_N];
int N;

inline ii bfsF(int s){
    memset(vis,0,sizeof(vis));
    int u = s;
    int md = 0;
    queue<ii> q;
    q.push({u,md});
    vis[u]=true;
    while(!q.empty()){
        ii p = q.front(); q.pop();
        u = p.first;
        md = p.second;
        for(auto v : adjList[u]){
            if(!adjMat[u][v])
                continue;
            if(!vis[v]){
                vis[v]=true;
                q.push({v,md+1});
            }
        }
    }
    return {u,md};
}

int fCent(int u){
    int v1 = bfsF(u).first;
    int v2 = bfsF(v1).first;
    memset(p,-1,sizeof(p));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(v1);
    while(!q.empty()){
        int v  = q.front();q.pop();
        vis[v]=true;
        for(int n : adjList[v])
            if(!vis[n] && adjMat[v][n]){
                p[n] = v;
                q.push(n);
            }
    }
    int dis = 0;
    int climb1,climb2; climb1=climb2=v2;
    while(p[climb1]!=-1){
        climb1 = p[climb1];
        if(dis%2==1)
            climb2 = p[climb2];
        ++dis;
    }
    return climb2;
}

inline int diam(int s){
    ii o = bfsF(s);
    o = bfsF(o.first);
    return o.second;
}

int main(){
    scanf("%d",&N);
    int a,b;
    for(int i = 0; i < N-1; ++i){
        scanf("%d %d",&a,&b);
        adjMat[a][b] = adjMat[b][a] = true;
        adjList[b].push_back(a);
        adjList[a].push_back(b);
        edgeList.push_back({a,b});
    }
    int mn = INF;
    ii rem;
    ii add;
    for(const ii& e : edgeList){
        int u = e.first; int v = e.second;
        //printf("Removing edge %d %d\n", u,v);
        adjMat[u][v] = adjMat[v][u] = false;

        int nU = fCent(u);
        int nV = fCent(v);
        adjList[nU].push_back(nV);
        adjList[nV].push_back(nU);
        adjMat[nU][nV] = adjMat[nV][nU] = true;

        int ndis = diam(1);

        if(ndis < mn){
            mn = ndis;
            rem = {min(u,v),max(u,v)};
            add = {min(nU, nV),max(nU,nV)};
        }

        adjMat[nU][nV] = adjMat[nV][nU] = false;
        adjList[nU].pop_back();
        adjList[nV].pop_back();
        adjMat[u][v] = adjMat[v][u] = true;
    }
    printf("%d\n%d %d\n%d %d\n",mn,rem.first,rem.second,add.first,add.second);
    return 0;
}
