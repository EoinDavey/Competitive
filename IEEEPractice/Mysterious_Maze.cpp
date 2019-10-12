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

const int MX_N = 1033;
ii p[MX_N][MX_N];
bool open[MX_N][MX_N];
const int mvs[][2] = {0,1,1,0,0,-1,-1,0};

ii find(ii i){ return p[i.fi][i.se] = (i == p[i.fi][i.se] ? i : find(p[i.fi][i.se]));}
void join(ii a, ii b){
    dbg(printf("Join (%d,%d) and (%d,%d)\n",a.fi,a.se,b.fi,b.se));
    a = find(a);b=find(b);
    p[a.fi][a.se] = b;
    assert(find(a) == find(b));
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N; rd(N);

    for(int i = 0; i <= N+1; ++i)
        for(int j = 1; j <= N; ++j)
            p[i][j] = {i,j};

    for(int i = 1; i <= N; ++i){
        if(i > 1){
            join({0, i}, {0, i-1});
            join({N+1, i}, {N+1, i-1});
        }
        open[0][i] = open[N+1][i] = true;
    }

    { int x, y, nx, ny;
        for(int i = 0;; ++i){
            rd(x);
            if(x == -1){
                pr(-1);
                break;
            }
            rd(y);
            open[x][y] = true;
            for(int k = 0; k < 4; ++k){
                nx = x + mvs[k][0];
                ny = y + mvs[k][1];
                if(nx < 0 || nx > N+1 || ny < 1 || ny > N)
                    continue;
                if(open[nx][ny])
                    join({x,y}, {nx,ny});
            }
            if(find({0,1}) == find({N+1, 1})){
                pr(i + 1);
                break;
            }
        }
    }
    return 0;
}
