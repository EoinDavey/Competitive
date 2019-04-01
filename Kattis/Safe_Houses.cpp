#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) cin >> x >> y >> z
#define rd2(x,y) cin >> x >> y
#define rd(x) cin >> x
#define pr3(x,y,z) cout << x << ' ' << y << ' ' << z << endl
#define pr2(x,y) cout << x << ' ' << y << endl
#define pr(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << ' ' << endl
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 111;
const int moves[][2] = {0,1,1,0,0,-1,-1,0};
char board[MX_N][MX_N];
bool vis[MX_N][MX_N];
int dist[MX_N][MX_N];
int N;

bool valid(int i, int j){ return i >= 0 && j >= 0 && j < N && i < N;}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
        scanf(" %c", &board[i][j]);
    queue<ii> q;
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
        if(board[i][j] == 'H')
          q.push({i,j}), vis[i][j] = true;
        else
          dist[i][j] = INFI;
    int x, y, nx, ny;
    while(!q.empty()){
      x = q.front().fi;
      y = q.front().se;
      q.pop();
      for(int k = 0; k < 4; ++k){
        nx = x + moves[k][0];
        ny = y + moves[k][1];
        if(valid(nx,ny) && !vis[nx][ny]){
          vis[nx][ny] = true;
          dist[nx][ny] = dist[x][y] + 1;
          q.push({nx,ny});
        }
      }
    }
    int mx = 0;
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
        if(board[i][j] == 'S')
          mx = max(mx, dist[i][j]);
    pr(mx);
    return 0;
}
