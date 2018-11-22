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

const int MX_N = 505;
int N,M;
int board[MX_N][MX_N];
int p[MX_N*MX_N];
bool flt[MX_N*MX_N];
const int mvs[][2] = {0,1,0,-1,1,0,-1,0};

int find(int i) { return p[i] = (p[i]==i? i : find(p[i]));}
inline void join(int a, int b){
    a=find(a);b=find(b);
    p[a]=b;
}

inline int toC(int i, int j){ return i *M + j; }
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; }

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(M,N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            p[toC(i,j)] = toC(i,j);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            rd(board[i][j]);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            for(int k = 0; k < 4; ++k){
                int nx=i+mvs[k][0];
                int ny=j+mvs[k][1];
                if(valid(nx,ny) && board[i][j]==board[nx][ny])
                    join(toC(i,j),toC(nx,ny));
            }
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            for(int k = 0; k < 4; ++k){
                int nx=i+mvs[k][0];
                int ny=j+mvs[k][1];
                if(valid(nx,ny) && board[i][j] > board[nx][ny])
                    flt[find(toC(i,j))]=true;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            if(!flt[find(toC(i,j))])
                cnt++;
    pr(cnt);
    return 0;
}
