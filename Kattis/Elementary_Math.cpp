#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const int MX_N=11111;
const int INF=10000000;
int N,S,T,idx;
map<ll,int> idxMap;
map<int,ll> revMap;
vector<int> adjList[MX_N];
int graph[MX_N][MX_N],res[MX_N][MX_N];
bool vis[MX_N];

int insert(int u,ll a,int w){
    if(idxMap.find(a)==idxMap.end()){
        idxMap[a]=idx;
        revMap[idx++]=a;
    }
    int b = idxMap[a];
    adjList[u].push_back(b);
    adjList[b].push_back(u);
    graph[u][b]=res[u][b]=w;
}

int ff(int u, int minE){
    vis[u]=true;
    if(u==T)
        return minE;
    for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
        if(!vis[*i] && res[u][*i] > 0){
            if(int f = ff(*i,min(minE,res[u][*i]))){
                res[*i][u]+=f;
                res[u][*i]-=f;
                return f;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d",&N);
    idx=N+4;
    vector<ii> pList;
    ll a,b;
    for(int i = 1; i <= N; i++){
        scanf("%lld %lld",&a,&b);
        insert(i,a+b,INF);
        insert(i,a*b,INF);
        insert(i,a-b,INF);
        pList.push_back(make_pair(a,b));
    }
    S=0;T=idx;
    for(int i = 1; i <= N; i++){
        graph[0][i]=res[0][i]=1;
        adjList[0].push_back(i);
        adjList[i].push_back(0);
    }
    for(int i = N+4; i < idx; i++){
        graph[i][T]=res[i][T]=1;
        adjList[i].push_back(T);
        adjList[T].push_back(i);
    }
    int mf = 0;
    while(1){
        memset(vis,0,sizeof(vis));
        int f = ff(S,INF);
        if(f==0)
            break;
        mf+=f;
    }
    if(mf<N)
        puts("impossible");
    else {
        for(int i = 1; i <= N; i++){
            ii p = pList[i-1];
            a=p.first;b=p.second;
            for(auto j = adjList[i].begin(); j != adjList[i].end(); j++){
                if(*j >= N+4 && *j < T && graph[i][*j] > 0 && res[i][*j] < graph[i][*j]){
                    ll ans = revMap[*j];
                    if(a+b==ans){
                        printf("%lld + %lld = %lld\n",a,b,ans);
                    } else if(a-b==ans){
                        printf("%lld - %lld = %lld\n",a,b,ans);
                    } else {
                        printf("%lld * %lld = %lld\n",a,b,ans);
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
