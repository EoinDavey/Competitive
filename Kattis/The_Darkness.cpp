#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

const int MX_RC=41;
const int MX_L = 1200;
const int INF = 10000000;
int B,H,R,C,f;
int S=0;
int T=1;
int lights[MX_RC][MX_RC];
ld lum[MX_RC][MX_RC];
bool lit[MX_RC][MX_RC];
bool vis[MX_L];
int p[MX_L];
map<int,int> res[MX_L];

const int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

ld sq(int u){
    return (ld) u*u;
}

bool valid(int i, int j){
    return i >= 0 && i < R && j >=0 && j < C;
}

int ctol(int i, int j){
    return 2 + i*C + j;
}

void augment(int u, int minE){
    if(u==S){
        f = minE;
        return;
    }
    if(p[u]!=-1){
        augment(p[u],min(minE,res[p[u]][u]));
        res[p[u]][u]-=f;
        res[u][p[u]]+=f;
    }
}

int main(){
    scanf("%d",&B);
    scanf("%d",&H);
    scanf("%d %d",&R,&C);
    char c;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf(" %c",&c);
            lights[i][j] = c-'0';
        }
    }
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            for(int k = 0; k < R; k++)
                for(int l = 0; l < C; l++)
                    lum[k][l] += (lights[i][j]*1.0L)/(sq(k-i)+sq(l-j)+sq(H));
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            lit[i][j] = (lum[i][j]+1e-9L) >= B*1.0L;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            for(int k = 0; k < 4; k++){
                int nx = i+moves[k][0];
                int ny = j+moves[k][1];
                if(valid(nx,ny)){
                    res[ctol(i,j)][ctol(nx,ny)] = (lit[i][j] && lit[nx][ny] ? 43:11);
                }
            }
            if(lit[i][j] && (i==0 || i==R-1 || j==0 || j==C-1))
                res[S][ctol(i,j)]=INF;
            if(!lit[i][j])
                res[ctol(i,j)][T]=INF;
        }
    }
    int mf = 0;
    while(1){
        f = 0;
        memset(vis,0,sizeof(vis));
        memset(p,-1,sizeof(p));
        queue<int> q;
        q.push(S);
        vis[S]=true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u==T)
                break;
            for(auto i : res[u]){
                if(!vis[i.first] && i.second > 0){
                    vis[i.first]=true;
                    p[i.first] = u;
                    q.push(i.first);
                }
            }
        }
        augment(T,INF);
        if(f==0)
            break;
        mf+=f;
    }
    printf("%d\n",mf);
    return 0;
}
