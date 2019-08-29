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

const int MX_N = 2002;
char board[MX_N][MX_N];
int rsum[MX_N][MX_N],csum[MX_N][MX_N];
int rtot[MX_N], ctot[MX_N];
int N, K;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N, K);
    {
        string s;
        for(int i = 0; i < N; ++i){
            rd(s);
            for(int j = 0; j < N; ++j){
                board[i][j] = s[j];
            }
        }
    }
    int free = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            rtot[i] += board[i][j] == 'B', ctot[i] += board[j][i] == 'B';
        free += rtot[i] == 0;
        free += ctot[i] == 0;
    }
    for(int i = 0; i < N; ++i){
        int rwinl = 0;
        int cwinl = 0;
        for(int j = 0; j < N; ++j){
            rwinl += board[i][j] == 'B';
            cwinl += board[j][i] == 'B';
            if(j - K >= 0)
                rwinl -= board[i][j-K] == 'B', cwinl -= board[j-K][i] == 'B';

            if(rtot[i] && rwinl == rtot[i] && j - K + 1 >= 0){
                int l = j - K + 1;
                int lb = max(0, i - K + 1);
                int ub = min(i, N - K);
                csum[lb][l] += 1;
                if(ub + 1 < N)
                    csum[ub+1][l] -= 1;
            }

            if(ctot[i] && cwinl == ctot[i] && j - K + 1 >= 0){
                int l = j - K + 1;
                int lb = max(0, i - K + 1);
                int ub = min(i, N - K);
                rsum[l][lb] += 1;
                if(ub + 1 < N)
                    rsum[l][ub+1] -= 1;
            }
        }
    }
    for(int i = 0; i < N; ++i)
        for(int j = 1; j < N; ++j)
            rsum[i][j] += rsum[i][j-1], csum[j][i] += csum[j-1][i];
    int mx = 0;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            mx = max(mx, rsum[i][j] + csum[i][j]);
    pr(mx + free);
    return 0;
}
