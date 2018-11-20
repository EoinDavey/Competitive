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
struct edge {
    int v,c,p;
};

const int MX_N = 10001;
unordered_map<string, int> indMap;
vector<edge> adjList[MX_N];
int cst[MX_N], prst[MX_N];
bool vis[MX_N];
int N,B;
int dp[2][MX_N];
int cost[2][MX_N];

inline int insert(const string& s){
    if(indMap.count(s))
        return indMap[s];
    int ind = indMap.size();
    indMap[s] = ind;
    return ind;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(B,N);
    string a,b,d;
    int c,p;
    for(int i = 0;i < N; ++i){
        cin >> a >> b >> d >> c >> p;
        int inda = insert(a);
        int indb = insert(b);
        adjList[inda].pb({indb,c,p});
    }

    vi ord;
    stack<ii> st;
    for(int i = 0; i < sz(indMap); ++i){
        if(vis[i])
            continue;
        st.push({i,0});
        while(!st.empty()){
            int u = st.top().fi;
            int ind = st.top().se;
            st.pop();
            vis[u] = true;
            bool b = false;
            for(int j = ind; j < sz(adjList[u]); ++j){
                if(!vis[adjList[u][j].v]){
                    b=true;
                    st.push({u, j+1});
                    st.push({adjList[u][j].v,0});
                    break;
                }
            }
            if(!b)
                ord.pb(u);
        }
    }

    for(int i : ord){
        if(!sz(adjList[i])){
            cst[i]=prst[i]=0;
            continue;
        }
        cst[i] = prst[i] = INFI;
        for(const auto& v : adjList[i]){
            if(cst[v.v] + v.c < cst[i]){
                prst[i] = prst[v.v] + v.p;
                cst[i] = cst[v.v] + v.c;
            } else if(cst[v.v] + v.c == cst[i]){
                prst[i] = max(prst[i], prst[v.v] + v.p);
            }
        }
    }

    int f = 1;
    for(int b = 0; b <= B; ++b){
        dp[f][b] = b < cst[0] ? 0 : prst[0];
        if(dp[f][b])
            cost[f][b] = cst[0];
    }

    for(int i = 1; i < sz(indMap); ++i){
        f = 1-f;
        for(int b = 0; b <= B; ++b){
            dp[f][b] = max(dp[1-f][b], b >= cst[i] ? prst[i] + dp[1-f][b-cst[i]] : 0);
            if(b < cst[i] || dp[1-f][b] > prst[i] + dp[1-f][b-cst[i]])
                cost[f][b] = cost[1-f][b];
            else if(prst[i] + dp[1-f][b-cst[i]] > dp[1-f][b])
                cost[f][b] = cst[i] + cost[1-f][b-cst[i]];
            else
                cost[f][b] = min(cost[1-f][b], cst[i] + cost[1-f][b-cst[i]]);
        }
    }
    pr(dp[f][B]);
    pr(cost[f][B]);
    return 0;
}
