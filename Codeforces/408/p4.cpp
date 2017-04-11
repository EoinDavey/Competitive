#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int mx_n = 300003;
int N,K,D;
vector<int> stations; bool station[mx_n];
vector<pair<int,int> > adjList[mx_n];
bool visited[mx_n];
bool rem[mx_n];
bool keep[mx_n];

int main(){
    cin >> N >> K >> D;
    int ik;
    for(int i = 0; i < K; i++){
        scanf("%d",&ik);
        if(station[ik])
            continue;
        station[ik]=true,stations.push_back(ik);
    }
    int iu, iv;
    for(int i = 0; i < N-1; i++){
        scanf("%d %d",&iu,&iv);
        adjList[iu].push_back(make_pair(iv,i));
        adjList[iv].push_back(make_pair(iu,i));
    }
    queue<pair<int, int > > q;
    for(int i = 0; i < stations.size(); i++){
        q.push(make_pair(stations[i],-1));
    }
    int s = 0;
    while(!q.empty()){
        pair<int,int> p = q.front(); q.pop();
        int u = p.first;
        int ur = p.second;
        if(visited[u]){
            if(!rem[ur])s++,rem[ur]=true;;
            continue;
        }
        visited[u] = true;
        for(int i = 0; i < adjList[u].size(); i++){
            int v = adjList[u][i].first;
            int r = adjList[u][i].second;
            if(r!=ur)
                q.push(make_pair(v,r));
        }
    }
    cout << s << endl;
    for(int i = 0; i <= N; i++)
        if(rem[i])
            printf("%d ",i+1);
    cout << endl;
    return 0;
}
