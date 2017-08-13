#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;

const int MX_N=200002;
int N,M;
int colours[MX_N];
bool visited[MX_N];
vector<int> adjList[MX_N];
int mCount[2];

bool solve(int u, int c){
    colours[u]=c;
    visited[u]=true;
    mCount[c]++;
    for(auto i = adjList[u].begin(); i!=adjList[u].end(); i++){
        if(colours[*i]==c || (!visited[*i] && solve(*i,1-c)))
            return true;
    }
    return false;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; i++){
        colours[i]=-1;
        adjList[i].clear();
    }
    int a,b,c;
    vector<ii> lists[3];
    for(int i=0; i < M; i++){
        scanf("%d %d %d",&a,&b,&c);
        a--,b--;
        lists[c].push_back(make_pair(a,b));
    }
    bool fail = false;
    for(auto i = lists[0].begin(); i!=lists[0].end(); i++){
        colours[i->first]=colours[i->second]=0;
    }
    for(auto i = lists[2].begin(); i!=lists[2].end()&&!fail; i++){
        fail |= (colours[i->first]==0 || colours[i->second]==0);
        colours[i->first]=colours[i->second]=1;
    }
    for(auto i = lists[1].begin(); i!=lists[1].end()&&!fail; i++){
        adjList[i->first].push_back(i->second);
        adjList[i->second].push_back(i->first);
    }
    for(int i = 0; i < N&&!fail; i++){
        if(colours[i]!=-1){
            fail |= solve(i,colours[i]);
        }
    }
    int sm = 0;
    for(int i = 0; i < N; i++){
        sm+=colours[i]==1;
    }
    for(int i = 0; i < N && !fail; i++){
        if(colours[i]==-1){
            mCount[1]=mCount[0]=0;
            fail |= solve(i,0);
            sm+=min(mCount[0],mCount[1]);
        }
    }
    if(fail)
        puts("impossible");
    else
        printf("%d\n",sm);
    return 0;
}
