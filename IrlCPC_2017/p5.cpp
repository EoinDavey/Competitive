#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

const int mx_n = 10011;
int R,S;
int deg[mx_n];
vector<int> adjList[mx_n];

int main(){
    int N; cin >> N;
    while(N--){
        cin >> S >> R;
        int iu, iv;
        for(int i = 0; i < S; i++)
            adjList[i].clear();
        memset(deg,0,sizeof(deg));
        for(int i = 0; i < R; i++){
            scanf("%d %d",&iu,&iv);
            adjList[iv].push_back(iu);
            deg[iu]++;
        }
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < S; i++){
            if(deg[i]==0)
                q.push(i);
        }
        bool s = false;
        while(!q.empty()){
            int u = q.top(); q.pop();
            if(s)
                printf(" ");
            s=true;
            printf("%d",u);
            for(int i = 0; i < adjList[u].size(); i++){
                int v = adjList[u][i];
                deg[v]--;
                if(deg[v]==0)
                    q.push(v);
            }
        }
        printf("\n");
    }
    return 0;
}
