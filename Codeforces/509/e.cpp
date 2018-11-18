#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define rd3(x,y,z) cin >> x >> y >> z;
#define rd2(x,y) cin >> x >> y;
#define rd(x) cin >> x;
#define pr3(x,y,z) cout << x << ' ' << y << ' ' << z << endl;
#define pr2(x,y) cout << x << ' ' << y << endl;
#define pr(x) cout << x << endl;
#define debug(x) cout << #x << " = "<< x << ' ' << endl;
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 1001;
bool used[MX_N];
int cnt[MX_N];

int main(){
    ios::sync_with_stdio(false);
    vi st;
    int N,x,y;rd(N);
    for(int i = 0; i < N-1; ++i){
        rd2(x,y);
        if(x!=N && y != N){
            pr("NO");
            return 0;
        }
        int v = x != N ? x : y;
        if(!used[v]){
            used[v] = true;
            st.pb(v);
        }
        cnt[v]++;
    }
    sort(st.begin(), st.end());
    queue<int> q;
    for(int i= 1; i <= N; ++i)
        if(!used[i])
            q.push(i);

    vi chn[MX_N];
    for(int v : st){
        int n = cnt[v]-1;
        chn[v].pb(v);
        while(~--n){
            if(q.empty() || q.front() > v){
                pr("NO");
                return 0;
            }
            chn[v].pb(q.front());q.pop();
        }
        chn[v].pb(N);
    }
    pr("YES");
    for(int i =1; i <= N; ++i){
        for(int j = 1; j < sz(chn[i]); ++j){
            pr2(chn[i][j-1],chn[i][j]);
        }
    }
    return 0;
}
