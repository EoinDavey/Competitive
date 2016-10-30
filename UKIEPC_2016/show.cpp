#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>


using namespace std;

char board[403][403];
bool vis[403][403];
int dis[403][403];
int INF = 10000000;

priority_queue<pair<int , pair<int, int> >,vector<pair<int , pair<int, int> > >, greater<pair<int , pair<int, int> > > >  q;

int main(){
    int R,C;
    cin >> R >> C;
    char ci;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%c",&ci);
            if(ci=='\n'){j--;continue;}
            board[i][j]=ci;
            dis[i][j] = INF;
        }
    }
    int r,c,v;
    scanf("%d %d",&r,&c);
    q.push(make_pair(0, make_pair(r-1,c-1)));
    pair<int, pair<int , int> > p;
    dis[r-1][c-1] = 0;
    int min = 1005000;
    while(!q.empty()){
        p = q.top();q.pop();
        r = p.second.first;
        c = p.second.second;
        v = p.first;
        if(v > dis[r][c]) continue;
        int dist = 0;
        if(r==0||r==R-1||c==0||c==C-1){
            if(v < min)min=v;
            continue;
        }
        if(board[r-1][c]!='#'){
            if(board[r-1][c]=='c')dist=1;
            if(board[r-1][c]=='D')dist=0;
            if(v + dist < dis[r-1][c]){
                dis[r-1][c] = v+dist;
                q.push(make_pair(dis[r-1][c],make_pair(r-1,c)));
            }
        }
        if(board[r+1][c]!='#'){
            if(board[r+1][c]=='c')dist=1;
            if(board[r+1][c]=='D')dist=0;
            if(v + dist < dis[r+1][c]){
                dis[r+1][c] = v+dist;
                q.push(make_pair(dis[r+1][c],make_pair(r+1,c)));
            }
        }
        if(board[r][c-1]!='#'){
            if(board[r][c-1]=='c')dist=1;
            if(board[r][c-1]=='D')dist=0;
            if(v + dist < dis[r][c-1]){
                dis[r][c-1] = v+dist;
                q.push(make_pair(dis[r][c-1],make_pair(r,c-1)));
            }
        }
        if(board[r][c+1]!='#'){
            if(board[r][c+1]=='c')dist=1;
            if(board[r][c+1]=='D')dist=0;
            if(v + dist < dis[r][c+1]){
                dis[r][c+1] = v+dist;
                q.push(make_pair(dis[r][c+1],make_pair(r,c+1)));
            }
        }
    }
    cout << min+1 << endl;
    return 0;
}
