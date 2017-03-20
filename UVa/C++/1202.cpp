#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

struct state{
    int x,y,d;
    state(int _x, int _y, int _d) : x(_x), y(_y), d(_d){}
    state(){}
    bool operator < (state r) const {
        if(d!=r.d) return d > r.d;
        if(x!=r.x) return x < r.x;
        return y < r.y;
    }
};

int N,M,mx,my;
int tx,ty;
int grid[220][220]; // 1-Left, 2 - Right, 4 - Up, 8 - Down
int door[220][220];
int dist[220][220];
int INF = 1000000;

int main(){
    while(true){
        cin >> M >> N;
        if(M==-1 && N==-1)
            break;
        int x,y,d,t,ix,iy;
        mx = my = 0;
        memset(grid,0,sizeof(grid));
        memset(door,0,sizeof(door));
        for(int i = 0; i < M; i++){
            scanf("%d %d %d %d",&ix, &iy, &d, &t);
            x = ix;
            y = iy;
            mx = max(mx,x);
            my = max(my,y);
            if(d==0){
                for(int j = x; j < x+t; j++){
                    grid[j][y] |= 8;
                    grid[j][y-1] |= 4;
                }
            }
            if(d==1){
                for(int j = y; j < y+t; j++){
                    grid[x][j] |= 1;
                    grid[x-1][j] |= 2;
                }
            }
        }
        t = 1;
        for(int i = 0; i < N; i++){
            scanf("%d %d %d",&ix, &iy, &d);
            mx = max(mx,x);
            my = max(my,y);
            if(d==0){
                door[ix][iy] |=8;
                door[ix][iy-1] |= 4;
            }
            if(d==1){
                door[ix][iy] |= 1;
                door[ix-1][iy] |= 2;
            }
        }
        double itx,ity;
        scanf("%lf %lf",&itx,&ity);
        tx = (int) (floor(itx));
        ty = (int) (floor(ity));
        for(int i = 0; i < 200; i++)
            for(int j = 0; j < 200; j++)
                dist[i][j] = INF;
        int r[][3] = {{0,1,4},{0,-1,8},{1,0,2},{-1,0,1}};
        if(tx > 200 || ty > 200){
            cout << 0 << endl;
            continue;
        }
        mx = max(tx,mx);
        my = max(ty,my);
        mx+=4;
        my+=4;
        dist[0][0] = 0;
        priority_queue<state> q;
        q.push(state(0,0,0));
        int c,nx,ny;
        while(!q.empty()){
            state e = q.top(); q.pop();
            if(dist[e.x][e.y] < e.d) continue;
            for(int i = 0; i < 4; i++){
                nx = e.x+r[i][0];
                ny = e.y+r[i][1];
                if(nx >= 0 && nx < mx && ny >= 0 && ny < my){
                    if((grid[e.x][e.y] & (r[i][2])) != 0 && (door[e.x][e.y] & r[i][2]) == 0)
                        continue;
                    int c = ((door[e.x][e.y] & r[i][2]) == 0) ? 0:1;
                    if(e.d + c < dist[nx][ny]){
                        dist[nx][ny] = e.d + c;
                        q.push(state(nx,ny,e.d+c));
                    }
                }
            }
        }
        printf("%d\n", ((dist[tx][ty]!=INF) ? dist[tx][ty] : -1));
    }
    return 0;
}
