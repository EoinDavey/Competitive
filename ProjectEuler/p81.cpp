#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> ii;

const int N = 80;
const int INF = 1000000;
int board[N][N];
int dist[N][N];

int moves[][2] = {{0,1},{1,0}};

int main(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d,",&board[i][j]),dist[i][j]=INF;
    ii s = make_pair(0,0);
    dist[0][0] = board[0][0];
    priority_queue<pair<int, ii> >  q;
    q.push(make_pair(board[0][0],s));
    while(!q.empty()){
        pair<int,ii> t = q.top(); q.pop();
        ii u = t.second;
        int d = t.first;
        if(dist[u.first][u.second] < d)
            continue;
        dist[u.first][u.second]=d;
        for(int i = 0; i < 2; i++){
            ii nu = make_pair(u.first+moves[i][0],u.second+moves[i][1]);
            if(nu.first < 0 || nu.first >=N || nu.second < 0 || nu.second >= N)
                continue;
            int nd = d+board[nu.first][nu.second];
            if(nd < dist[nu.first][nu.second])
                q.push(make_pair(nd,nu));
        }
    }
    printf("%d\n",dist[N-1][N-1]);
    return 0;
}
