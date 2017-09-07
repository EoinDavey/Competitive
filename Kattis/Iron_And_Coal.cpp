#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

constexpr int MX_N=100010;
constexpr int INF = 100000000;
int N,M,K,C,O;
vector<int> adjList[MX_N];
vector<int> revAdjList[MX_N];
int dist[3][MX_N];

int read_int(){
    char c;
    int out = 0;
    while(1){
        c = getchar_unlocked();
        if(c!=' '&&c!='\n')
            break;
    }
    do {
        out = out*10 + (c-'0');
        c=getchar_unlocked();
    } while(c!=' '&&c!='\n');
    return out;
}

void trav(vector<int> v[],int s,int c){
    for(int i = 0; i < N; i++)
        dist[c][i]=INF;
    dist[c][s] = 0;
    queue<int> q;
    q.push(s);
    int u,d;
    while(!q.empty()){
        u = q.front(); q.pop();
        d = dist[c][u];
        for(auto i : v[u]){
            if(dist[c][i]==INF){
                dist[c][i] = d+1;
                q.push(i);
            }
        }
    }
}

int main(){
    N = read_int();
    M = read_int();
    K = read_int();
    C = N+1;
    O=N+2;
    for(int i = 0; i < M; i++){
        revAdjList[O].push_back(read_int()-1);
    }
    for(int i = 0; i < K; i++)
        revAdjList[C].push_back(read_int()-1);
    for(int i = 0; i < N; i++){
        int a = read_int();
        while(~--a){
            int c = read_int()-1;
            adjList[i].push_back(c);
            revAdjList[c].push_back(i);
        }
    }
    trav(adjList,0,0);
    trav(revAdjList,C,1);
    trav(revAdjList,O,2);
    int mn = INF;
    for(int i =0;i < N; i++)
        mn = min(mn,dist[0][i]+dist[1][i]+dist[2][i]-2);
    if(mn>=400000)
        puts("impossible");
    else
        printf("%d\n",mn);
    return 0;
}
