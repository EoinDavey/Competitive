#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> ii;

int x1,y1,x2,y2;

bool vis[8][8];
ii p[8][8];

int moves[][2] = {{1,1},{1,-1},{-1,-1},{-1,1}};

bool valid(int i, int j){
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

bool pr(int i, int j, int d){
    ii _i = p[i][j];
    int x = _i.first;
    int y = _i.second;
    if(x==i && y==j){
        if(d <= 4){
            printf("%d %c %d",d,i+'A',j+1);
            return true;
        }
        return false;
    }
    if(pr(x,y,d+1)){
        printf(" %c %d",i+'A',j+1);
        return true;
    }
    return false;
}

int main(){
    char _x1,_x2;
    int N; scanf("%d",&N);
    for(int i = 0; i < N; ++i){
        memset(vis,0,sizeof(vis));
        scanf(" %c %d %c %d",&_x1,&y1,&_x2,&y2);
        x1 = _x1-'A';
        x2 = _x2-'A';
        --y1,--y2;
        queue<ii> q;
        vis[x1][y1] = true;
        q.push(make_pair(x1,y1));
        p[x1][y1] = make_pair(x1,y1);
        int x,y,nx,ny;
        while(!q.empty()){
            ii _i = q.front(); q.pop();
            x = _i.first; y = _i.second;
            for(int k = 0; k < 4; k++){
                int n = 1;
                while(valid(x+moves[k][0]*n,y+moves[k][1]*n)){
                    nx = x+moves[k][0]*n, ny= y+moves[k][1]*n;
                    if(!vis[nx][ny]){
                        vis[nx][ny] = true;
                        p[nx][ny] = make_pair(x,y);
                        q.push(make_pair(nx,ny));
                    }
                    n++;
                }
            }
        }
        if(!vis[x2][y2] || !pr(x2,y2,0))
            puts("Impossible");
        else
            putchar('\n');
    }
    return 0;
}
