struct edge {
    int x,y,w;
    bool operator < (edge e) const {
        return w < e.w;
    }
};

int main(){
    vector<edge> eList; //Input
    for(int i = 0; i < N; i++)// Set up UFDS
        p[i]=i;
    vector<ii> treeList;
    sort(eList.begin(),eList.end());
    int cost = 0;
    int sz=N;
    int u,v,w;
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
