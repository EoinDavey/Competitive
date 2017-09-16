#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

constexpr int INF= 100000000;

int moves[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int i, int j){
    return i>=0 && i < 3 && j >= 0 && j < 3;
}

int main(){
    int dist[(1<<10)];
    for(int i = 0; i < (1<<9); i++)
        dist[i]=INF;
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int d = dist[u];
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                int nst = u^(1<<(i*3+j));
                for(int k = 0; k < 4; ++k){
                    int ni,nj;
                    ni = i+moves[k][0];
                    nj = j+moves[k][1];
                    if(valid(ni,nj)){
                        nst^=(1<<(ni*3+nj));
                    }
                }
                if(dist[nst]==INF){
                    dist[nst]=d+1;
                    q.push(nst);
                }
            }
        }
    }
    int P; scanf("%d",&P);
    while(P-->0){
        int t; t=0;
        char in;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3;++j){
                scanf(" %c",&in);
                if(in=='*'){
                    t |= (1 << (i*3 + j));
                }
            }
        }
        printf("%d\n",dist[t]);
    }
    return 0;
}
