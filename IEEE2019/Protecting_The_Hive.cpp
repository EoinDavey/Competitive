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

const int MX_N = 1000; //TODO
map<ii, ii> p;
map<ii, int> perim;
set<ii> active;
int N, M;

const int mvs[][6][2] =
{
    {{-1,0},{-1,1},{0,1},{1,1},{1,0},{0,-1}},
    {{-1,-1},{-1,0},{0,1},{1,0},{1,-1},{0,-1}}
};

ii find(ii i) { return p[i] = (i == p[i] ? i : find(p[i]));}
void join(ii a, ii b){
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    p[a] = b;
}

bool valid(int x, int y){
    if(x%2){
        return x >= 1 && y >= 1 && x <= N && y <= M;
    }
    return x >= 1 && y >= 1 && x <= N && y < M;
}

int activate(int x, int y){
#define active(x,y) (active.count({x,y}) > 0)
    set<ii> nbrids;
    int diff = 0;
    for(int k = 0; k < 6; ++k){
        int nx, ny;
        nx = x + mvs[x%2][k][0];
        ny = y + mvs[x%2][k][1];

        if(active(nx,ny))
            diff -= 1;
        else 
            diff += 1;

        if(valid(nx,ny) && active(nx,ny))
            nbrids.insert(find({nx,ny}));
    }
    for(const auto &i : nbrids)
        diff += perim[i];
    for(auto i : nbrids)
        join(find({x,y}), i);
    perim[find({x,y})] = diff;
    for(auto i : nbrids)
        perim[i] = diff;
    active.insert({x,y});
    return diff;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,M);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            p[{i,j}] = {i,j};
            perim[{i,j}] = 0;
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N - (1 - i%2); ++j){
            int x; rd(x);
            if(x)
                activate(i,j);
        }
    }
    int Q; rd(Q);
    char c; int x, y;
    while(Q-->0){
        rd3(c,x,y);
        if(c == 'a'){
            activate(x,y);
        } else {
            pr(perim[find({x,y})]);
        }
    }
    return 0;
}
