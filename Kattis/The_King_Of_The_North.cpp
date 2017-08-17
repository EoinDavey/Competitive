#include<bits/stdc++.h>
using namespace std;

const int MX_RC=303;
const int INF = 1000000;
int R,C,S,T,mid;
int board[MX_RC][MX_RC];
bool vis[MX_RC*MX_RC*2+20];
int p[MX_RC*MX_RC*2+20];
int f;

int moves[][2] = {{0,1},{1,0},{0,-1},{-1,0}};

map<int,int> adjList[MX_RC*MX_RC*2+20];

int ctin(int i, int j){
    return i*C+j;
}

int ctout(int i, int j){
    return i*C+j + mid;
}

bool valid(int i, int j){
    return i>=0 && i < R && j >= 0 && j < C;
}

void aug(int u, int minE){
    if(u==S){
        f=minE;
        return;
    }
    if(p[u]!=-1){
        aug(p[u],min(minE,adjList[p[u]][u]));
        adjList[p[u]][u]-=f;
        adjList[u][p[u]]+=f;
    }
}

int main(){
    scanf("%d %d",&R,&C);
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            scanf(" %d",&board[i][j]);
    mid = R*C;
    S = 2*mid+10;
    T = S+1;
    int ni,nj,mi,mj;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            for(int k = 0; k < 4; k++){
                ni=i+moves[k][0];
                nj=j+moves[k][1];
                if(valid(ni,nj)){
                    adjList[ctout(i,j)][ctin(ni,nj)]=INF;
                }
            }
            adjList[ctin(i,j)][ctout(i,j)]=board[i][j];
            if(i==0 || i==R-1 || j==0 || j==C-1)
                adjList[S][ctin(i,j)]=INF;
        }
    }
    int cx,cy;scanf("%d %d",&cx,&cy);
    adjList[ctout(cx,cy)][T]=INF;
    int mf =0;
    while(1){
        memset(p,-1,sizeof(p));
        memset(vis,0,sizeof(vis));
        f=0;
        queue<int> q;
        vis[S]=true;
        q.push(S);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u==T)
                break;
            for(auto i = adjList[u].begin(); i != adjList[u].end(); i++){
                int v = i->first;
                int r = i-> second;
                if(r > 0 && !vis[v]){
                    p[v]=u;
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        aug(T,INF);
        if(f==0)
            break;
        mf+=f;
    }
    printf("%d\n",mf);
    return 0;
}
