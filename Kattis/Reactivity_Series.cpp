#include<bits/stdc++.h>
using namespace std;

constexpr int MX_N = 1001;
vector<int> adjList[MX_N];
int out[MX_N],in[MX_N];
int N,K;

int main(){
    scanf("%d %d",&N,&K);
    int a,b;
    for(int i = 0; i < K; i++){
        scanf("%d %d",&a,&b);
        adjList[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(in[i]==0)
            q.push(i);
    }
    bool fail = false;
    vector<int> sortL;
    while(!q.empty()){
        if(q.size() > 1)
            fail = true;
        int u = q.front(); q.pop();
        sortL.push_back(u);
        for(auto v : adjList[u]){
            in[v]--;
            if(in[v] == 0)
                q.push(v);
        }
    }
    if(fail)
        puts("back to the lab");
    else{
        for(auto i : sortL)
            printf("%d ",i);
        putchar('\n');
    }
    return 0;
}
