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
int board[MX_N][MX_N];
ii dist[3][MX_N][MX_N][3][MX_N][MX_N];
int N;
ii pos[MX_N*MX_N];

tuple<int,int,int> fromK(int k){
    int a,b,c;
    a = k/(N*N);
    k%=(N*N);
    b = k/N;
    k%=N;
    c = k;
    return {a,b,c};
}

ii operator+(const ii& a, const ii& b){
    return {a.fi+b.fi, a.se+b.se};
}

ii memo[3][MX_N*MX_N];
bool mset[3][MX_N*MX_N];

ii dp(int p, int n){
    if(n==N*N-1)
        return {0,0};
    if(mset[p][n])
        return memo[p][n];
    ii nxtPos = pos[n+1];

    //keep
    ii mn = dp(p, n+1) + dist[p][pos[n].fi][pos[n].se][p][nxtPos.fi][nxtPos.se];
    //switch1
    mn = min(mn, dp((p+1)%3, n+1) + dist[p][pos[n].fi][pos[n].se][(p+1)%3][nxtPos.fi][nxtPos.se]);
    //switch2
    mn = min(mn, dp((p+2)%3, n+1) + dist[p][pos[n].fi][pos[n].se][(p+2)%3][nxtPos.fi][nxtPos.se]);
    mset[p][n] = true;
    return memo[p][n] = mn;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            rd(board[i][j]);
    for(int i= 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            pos[board[i][j]-1] = {i,j};

    int k1,x1,y1,k2,x2,y2,k3,x3,y3;
    for(int i = 0; i < 3*N*N; ++i){
        tie(k1,x1,y1) = fromK(i);
        for(int j = i; j < 3*N*N; ++j){
            tie(k2,x2,y2) = fromK(j);
            if(i==j){
                dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {0,0};
                continue;
            }
            if(x1==x2 && y1==y2){
                dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {1, 1};
                continue;
            }
            if(k1 != k2){
                dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {INFI,INFI};
                continue;
            }
            if(k1 == 0){ // BISHOP
                if(abs(x1-x2) == abs(y1-y2))
                    dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {1,0};
                else
                    dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {INFI, INFI};
            }
            if(k1==1){ // ROOK
                if(x1==x2 || y1==y2)
                    dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {1, 0};
                else
                    dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {INFI, INFI};
            }
            if(k1==2){ // KNIGHT
                if((abs(x1-x2)==2 && abs(y1-y2)==1)
                        || abs(x1-x2)==1 && abs(y1-y2)==2)
                    dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {1, 0};
                else
                    dist[k1][x1][y1][k2][x2][y2] = dist[k2][x2][y2][k1][x1][y1] = {INFI, INFI};
            }
        }
    }
    for(int k = 0; k < 3*N*N; ++k){
        tie(k3,x3,y3) = fromK(k);
        for(int i = 0; i < 3*N*N; ++i){
            tie(k1,x1,y1) = fromK(i);
            for(int j = 0; j < 3*N*N; ++j){
                tie(k2,x2,y2) = fromK(j);
                dist[k1][x1][y1][k2][x2][y2] = 
                    min(dist[k1][x1][y1][k2][x2][y2],
                            dist[k1][x1][y1][k3][x3][y3] + dist[k3][x3][y3][k2][x2][y2]);
            }
        }
    }
    ii mn = dp(0, 0);
    mn = min(mn, dp(1,0));
    mn = min(mn, dp(2,0));
    pr(mn.first << ' ' << mn.se);

    return 0;
}
