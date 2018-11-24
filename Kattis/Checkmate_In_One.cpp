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

const int MX_N = 10;
bool th[MX_N][MX_N];
char board[MX_N][MX_N], tboard[MX_N][MX_N];
inline bool valid(int x, int y){return x >= 0&&y >= 0 && x < 8 && y < 8; }
int N = 8;
const int kmoves[][2] = {1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};

bool check(){
    ii Rpos, kpos,Kpos;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(tboard[i][j]=='K')
                Kpos={i,j};
            if(tboard[i][j]=='R')
                Rpos={i,j};
            if(tboard[i][j]=='k')
                kpos={i,j};
        }
    }
    memset(th, 0, sizeof(th));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            if((i==Rpos.fi) ^ (j==Rpos.se))
                th[i][j] = true;
    for(int k = 0; k < 8; ++k){
        int nx,ny;
        nx = Kpos.fi + kmoves[k][0];
        ny = Kpos.se + kmoves[k][1];
        if(valid(nx, ny))
            th[nx][ny] = true;
    }
    if(!th[kpos.fi][kpos.se])
        return false;
    for(int k = 0; k < 8; ++k){
        int nx,ny;
        nx = kpos.fi + kmoves[k][0];
        ny = kpos.se + kmoves[k][1];
        if(valid(nx, ny) && !th[nx][ny])
            return false;
    }
    return true;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            rd(board[i][j]);
    ii Rpos, Kpos, kpos;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(board[i][j]=='K')
                Kpos={i,j};
            if(board[i][j]=='R')
                Rpos={i,j};
            if(board[i][j]=='k')
                kpos={i,j};
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(((i==Rpos.fi) ^ (j==Rpos.se)) && board[i][j] != 'K'){
                memcpy(tboard, board, sizeof board);
                tboard[Rpos.fi][Rpos.se]='.';
                tboard[i][j]='R';
                if(check()){
                    pr("Yes");
                    return 0;
                }
            }
        }
    }
    for(int k = 0; k < 8; ++k){
        int nx,ny;
        nx = Kpos.fi + kmoves[k][0];
        ny = Kpos.se + kmoves[k][1];
        if(valid(nx, ny) && board[nx][ny] != 'R' && max(abs(nx-kpos.fi),abs(kpos.se-ny)) > 1){
            memcpy(tboard, board, sizeof board);
            tboard[Kpos.fi][Kpos.se]='.';
            tboard[nx][ny]='K';
            if(check()){
                pr("Yes");
                return 0;
            }
        }
    }
    pr("No");
    return 0;
}
