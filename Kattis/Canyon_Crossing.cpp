#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int MX_N = 1002;
const int INF = 1000 * 1000 * 1000 + 1;
const int mvs[][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int R, C, K;

int board[MX_N][MX_N];
int dist[MX_N][MX_N];
bool vis[MX_N][MX_N];

inline bool valid(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

bool test(int mn_h) {
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            dist[i][j] = INF;

    deque<ii> dq;
    for(int j = 0; j < C; ++j) {
        if(board[0][j] < mn_h) {
            dist[0][j] = 1;
            dq.push_back({0, j});
        } else {
            dist[0][j] = 0;
            dq.push_front({0, j});
        }
    }

    while(dq.size() > 0) {
        ii u = dq.front(); dq.pop_front();
        int i = u.first;
        int j = u.second;
        for(int k = 0; k < 4; ++k) {
            int ni = i + mvs[k][0];
            int nj = j + mvs[k][1];
            if(!valid(ni, nj))
                continue;
            if(dist[ni][nj] < INF)
                continue;
            if(board[ni][nj] < mn_h) {
                dist[ni][nj] = dist[i][j] + 1;
                dq.push_back({ni, nj});
            } else {
                dist[ni][nj] = dist[i][j];
                dq.push_front({ni, nj});
            }
        }
    }

    for(int j = 0; j < C; ++j)
        if(dist[R-1][j] <= K)
            return true;
    return false;
}

int main(){
    cin >> R >> C >> K;
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            cin >> board[i][j];

    int L = 0;
    int R = INF;
    while(L < R) {
        int md = (L + R + 1) / 2;
        if(test(md)) {
            L = md;
        } else {
            R = md - 1;
        }
    }
    printf("%d\n", L);
    return 0;
}
