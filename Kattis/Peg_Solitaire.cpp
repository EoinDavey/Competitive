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

const int MX_PG = 9;
const int N = 5;
const int M = 9;
const int mvs[][2] = {0,1,1,0,0,-1,-1,0};

char board[N][M];
int ind[N][M], pgC, tot;
ii pgs[MX_PG];
bool d[MX_PG];
ii ans;

bool is_valid(int i, int j) {return i >=0&&j>=0&&i<N&&j<M;}

void rec(int dpth){
    ans = min(ans, {tot, dpth});
    int x,y,nx,ny,nnx,nny;
    for(int i = 0; i < pgC; ++i){
        if(d[i])
            continue;

        x = pgs[i].fi;
        y = pgs[i].se;

        assert(ind[x][y] == i);

        assert(is_valid(x,y));

        for(int k = 0; k < 4; ++k){
            nx = x + mvs[k][0];
            ny = y + mvs[k][1];
            nnx = nx + mvs[k][0];
            nny = ny + mvs[k][1];
            if(!is_valid(nx,ny) || !is_valid(nnx,nny) || board[nx][ny] != 'o' || board[nnx][nny] != '.')
                continue;

            int dInd = ind[nx][ny];

            int oinnxnny;

            oinnxnny = ind[nnx][nny];

            board[x][y] = '.';
            board[nx][ny] = '.';
            board[nnx][nny] = 'o';
            ind[nnx][nny] = i;
            --tot;
            pgs[i] = {nnx,nny};

            d[dInd] = true;

            rec(dpth+1);

            board[x][y] = 'o';
            board[nx][ny] = 'o';
            board[nnx][nny] = '.';

            ind[nnx][nny] = oinnxnny;

            d[dInd] = false;
            ++tot;
            pgs[i] = {x,y};
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int Q; rd(Q);
    string s;
    while(Q-->0){
        for(int i = 0; i < N; ++i){
            rd(s);
            for(int j = 0; j < M; ++j)
                board[i][j] = s[j];
        }
        pgC=0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(board[i][j] == 'o'){
                    pgs[pgC] = {i,j};
                    ind[i][j] = pgC;
                    ++pgC;
                }
            }
        }
        ans = {INFI,INFI};
        tot = pgC;
        rec(0);
        pr(ans.fi << ' ' << ans.se);
    }
    return 0;
}
