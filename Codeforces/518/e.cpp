#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 100010;
const int END = MX_N + 2;
vector<int> adjList[MX_N];
int vis[MX_N];
int sz[MX_N];
int N, K;

int main(){
    scanf("%d %d",&N,&K);
    int x,y;
    for(int i = 0; i < N-1; ++i){
        scanf("%d %d",&x,&y);
        --x,--y;
        adjList[x].pb(y);
        adjList[y].pb(x);
    }
    int stages = 0;
    queue<int> leaves;
    for(int i = 0; i < N; ++i)
        if(adjList[i].size()==1)
            leaves.push(i), vis[i]=1, sz[i]=3;
    leaves.push(END);
    bool fail = false;
    while(!fail){
        //printf("Stage %d\n", stages);
        if(leaves.empty())
            break;
        stages+=1;
        while(!fail){
            int u = leaves.front(); leaves.pop();
            if(u==END)
                break;
            //printf("%d ", u);
            if(sz[u] < 3)
                fail = true;
            for(int v : adjList[u]){
                if(!vis[v]){
                    vis[v] = vis[u]+1;
                    leaves.push(v);
                }
                if(vis[v]==vis[u])
                    fail=true;
                sz[v]++;
            }
        }
        //putchar('\n');
        if(!leaves.empty())
            leaves.push(END);
    }
    if(fail || stages-1!= K)
        puts("No");
    else
        puts("Yes");
    return 0;
}
