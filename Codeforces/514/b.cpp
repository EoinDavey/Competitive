#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define rd2(x,y) scanf("%d %d", &x, &y)
#define rd(x) scanf("%d", &x)
#define pr3(x,y,z) printf("%d %d %d\n", x, y, z)
#define pr2(x,y) printf("%d %d\n", x, y)
#define pr(x) printf("%d\n", x)
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int INFI = 1000*1000*1000;
const int MX_N = 1001;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;
int N, M;
char grd[MX_N][MX_N];
char egrd[MX_N][MX_N];
int moves[][2] = {0,1,0,-1,1,0,-1,0, 1, 1, -1, -1, 1, -1, -1, 1};
inline bool valid(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

bool safe(int x, int y){
    int nx,ny;
    for(int k = 0; k < 8; ++k){
        nx = x+moves[k][0];
        ny = y+moves[k][1];
        if(!valid(nx,ny) || grd[nx][ny]=='.')
            return false;
    }
    return true;
}

void fill(int x, int y){
    int nx,ny;
    for(int k = 0; k < 8; ++k){
        nx = x+moves[k][0];
        ny = y+moves[k][1];
        egrd[nx][ny] = '#';
    }
}

int main(){
    rd2(N,M);
    memset(egrd,'.',sizeof egrd);
    for(int i= 0; i < N; ++i)
        for(int j = 0;j < M; ++j)
            scanf(" %c",&grd[i][j]);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(safe(i,j))
                fill(i,j);
        }
    }
    bool fail = false;
    for(int i = 0; i < N && !fail; ++i)
        for(int j = 0; j < M && !fail; ++j)
            if(grd[i][j] != egrd[i][j])
                fail=true;
    if(!fail)
        puts("YES");
    else
        puts("NO");
    return 0;
}
