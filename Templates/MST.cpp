typedef pair<int,int> ii;
int p[MX_N],M,N;

// UFDS for sets
bool connected(int a, int b){ return find(a)==find(b);}

struct edge {
    int x,y,w;
    edge(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
    bool operator < (edge e) const {
        return w < e.w;
    }
};

int main(){
    for(int i = 0; i < N; i++)
        p[i]=i;
    vector<edge> eList;
    vector<ii> treeList;
    int u,v,w;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d",&u,&v,&w);
        eList.push_back(edge(u,v,w));
    }
    sort(eList.begin(),eList.end());
    int cost = 0;
    int sz=N;
    for(const auto &i : eList){
        v=i.x; u=i.y; w=i.w;
        if(!connected(u,v)){
            join(u,v);
            treeList.push_back({min(u,v),max(u,v)});
            sz--;
            cost+=w;
        }
    }
    if(sz!=1)
        puts("Impossible");
}
