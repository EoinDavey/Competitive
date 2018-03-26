#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int dist[8][8];
int moves[][2] = {{1,2},{-1,2},{2,1},{-2,1},
                  {1,-2},{-1,-2},{2,-1},{-2,-1}};

bool valid(int x, int y){ return x >=0 && y>=0 && x < 8 && y < 8; }

int main(){
    int N; scanf("%d",&N);
    while(N-->0){
        char _c; int r,c;
        scanf(" %c%d",&_c,&r);
        c = _c-'a';
        r = 8-r;
        memset(dist,-1,sizeof(dist));
        queue<ii> q;
        dist[r][c] = 0;
        q.push({r,c});
        while(!q.empty()){
            ii p = q.front();q.pop();
            r = p.first; c = p.second;
            for(int k = 0; k < 8; ++k){
                int nr = r+moves[k][0];
                int nc = c+moves[k][1];
                if(valid(nr,nc) && dist[nr][nc]==-1){
                    dist[nr][nc] = dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j)
                mx = max(mx,dist[i][j]);
        printf("%d ",mx);
        for(int i = 0; i < 8; ++i)
            for(int j = 0; j < 8; ++j)
                if(dist[i][j]==mx)
                    printf("%c%d ",j+'a',8-i);
    }
    return 0;
}
