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
#ifdef JUDGE
#define dbg(x) x
#else
#define dbg(x)
#endif
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

/*
 * 0: North
 * 1: South
 * 2: East
 * 3: West
 */
const int mvs[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const int blkd[] = {1, 0, 3, 2};
const int MX_N = 10;
const int MX_ST = 1 << 16;
char board[MX_N][MX_N];
ll memo[MX_ST][8][8][4][2];
vector<ii> positions;
map<ii, int> posMap;

ll search(int bSt, int wX, int wY, int dir, bool king){
    if(bSt == (1 << sz(positions)) - 1)
        return 1LL;

    if(memo[bSt][wX][wY][dir][king] != -1)
        return memo[bSt][wX][wY][dir][king];

    int nx, ny, cx, cy;

    ll sm = 0LL;

    for(int d = 0; d < 4; ++d){
        if(d == blkd[dir] || (d == 1 && !king))
            continue;
        int cnt = 0;
        for(int ln = 1; ln <= 8 && cnt <= 1 && !(!king && ln > 2); ++ln){
            nx = wX + ln * mvs[d][0];
            ny = wY + ln * mvs[d][1];
            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                break;

            if(board[nx][ny] == 'x')
                ++cnt, cx = nx, cy = ny;

            if(cnt && board[nx][ny] == '.'){
                board[nx][ny] = 'o';
                board[wX][wY] = '.';
                board[cx][cy] = '.';

                assert(posMap.count({cx, cy}) > 0);
                int p = posMap[{cx, cy}];
                assert(0 <= p && p < 16);
                assert((bSt & (1 << p)) == 0);

                sm += search(bSt | (1 << p), nx, ny, d, king || nx == 0);

                board[cx][cy] = 'x';
                board[wX][wY] = 'o';
                board[nx][ny] = '.';
            }
        }
    }
    return memo[bSt][wX][wY][dir][king] = sm;
}

void solve(){
    memset(memo, -1, sizeof(memo));
    positions.clear();
    posMap.clear();
    getchar();
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            board[i][j] = getchar();
        }
        getchar();
    }
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(board[i][j] == 'x'){
                positions.pb({i, j});
                posMap[{i,j}] = sz(positions)-1;
            }
        }
    }
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(board[i][j] == 'o'){
                pr(search(0, i, j, (i == 0 ? 1 : 0), i == 0));
                return;
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T; scanf("%d", &T);
    while(T-->0){
        solve();
    }
    solve();
    return 0;
}
