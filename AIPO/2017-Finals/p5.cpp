#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

int INF = 400;
int dis[8][8];

struct entry{
    int y,x,d;
    entry(int yi, int xi, int di): y(yi), x(xi), d(di){}
    bool operator < (const entry rhs) const {
        return d < rhs.d;
    }
};

int main(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            dis[i][j]=INF;
    priority_queue<entry> q;
    char sx,sy,fx,fy;
    scanf(" %c %c %c %c",&sx,&sy,&fx,&fy);
    sx = sx - ((int)'a');
    sy-='0'+1;
    fx = fx - ((int)'a');
    fy-='0'+1;
    dis[sx][sy] = 0;
    q.push(entry(sx,sy,0));
    while(!q.empty()){
        entry e = q.top(); q.pop();
        if(e.d > dis[e.y][e.x]) continue;
        dis[e.y][e.x] = e.d;
        if(e.y > 1){
            if(e.x > 0)
                if(e.d + 1 < dis[e.y-2][e.x-1])
                    q.push(entry(e.y-2, e.x-1, e.d+1));
            if(e.x < 7)
                if(e.d + 1 < dis[e.y-2][e.x+1])
                    q.push(entry(e.y-2, e.x+1, e.d+1));
        }
        if(e.x > 1){
            if(e.y > 0)
                if(e.d + 1 < dis[e.y-1][e.x-2])
                    q.push(entry(e.y-1, e.x-2, e.d+1));
            if(e.y < 7)
                if(e.d + 1 < dis[e.y+1][e.x-2])
                    q.push(entry(e.y+1, e.x-2, e.d+1));
        }
        if(e.y < 6){
            if(e.x > 0)
                if(e.d + 1 < dis[e.y+2][e.x-1])
                    q.push(entry(e.y+2, e.x-1, e.d+1));
            if(e.x < 7)
                if(e.d + 1 < dis[e.y+2][e.x+1])
                    q.push(entry(e.y+2, e.x+1, e.d+1));
        }
        if(e.x < 6){
            if(e.y > 0)
                if(e.d + 1 < dis[e.y-1][e.x+2])
                    q.push(entry(e.y-1, e.x+2, e.d+1));
            if(e.y < 7)
                if(e.d + 1 < dis[e.y+1][e.x+2])
                    q.push(entry(e.y+1, e.x+2, e.d+1));
        }
    }
    cout << dis[fx][fy] << endl;
    return 0;
}
