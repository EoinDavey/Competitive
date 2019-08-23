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

const int MX_N = 110;
int N, M;
int adjMat[MX_N][MX_N], dist[MX_N][MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N;
    string s; getline(cin, s);
    for(int i = 0; i < N; ++i){
        getline(cin, s);
        for(int j = 0; j < N; ++j)
            adjMat[i][j] = s[j] == '1';
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            dist[i][j] = adjMat[i][j] ? 1 : INFI;
    for(int i = 0; i < N; ++i)
        dist[i][i] = 0;

    for(int k = 0; k < N; ++k)
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    cin >> M;
    vector<int> p(M);
    for(int i = 0; i < M; ++i)
        cin >> p[i];

    vector<int> out; out.pb(0);
    for(int it = 0; it + 1 < M;){
        int lst = it;
        dbg(printf("Starting at %d\n", p[lst]));
        while(it + 1 < M){
            if(dist[p[lst]-1][p[it+1]-1] < it+1 - lst){
                dbg(printf("Can't take %d\n", p[it+1]));
                break;
            }
            ++it;
            dbg(printf("Taking %d\n", p[it]));
        }
        out.pb(it);
    }
    cout << out.size() << endl;
    for(auto i : out)
        cout << p[i] << ' ';
    cout << endl;
    return 0;
}
