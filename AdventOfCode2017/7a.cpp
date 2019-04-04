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

const int MX_N = 2000; //TODO
map<string, vector<string> > adjList;
map<string, string> p;
set<string> strs;
map<string, int> wght;
map<string, int> tWght;

void dfs(const string& u){
    int w = wght[u];
    for(const auto& v : adjList[u]){
        dfs(v);
        w += tWght[v];
    }
    tWght[u] = w;
}

void fix(const string& u, int sz){
    cout << u << endl;
    int w = 0;
    for(const auto& v : adjList[u])
        w+=tWght[v];
    cout << sz-w << endl;
}

bool check(const string& u){
    map<int, int> count;
    for(const auto& v : adjList[u])
        count[tWght[v]]++;
    int mx = 0;
    int ans = 0;
    for(const auto& p : count)
        if(p.se > mx){
            mx = p.se;
            ans = p.fi;
        }
    for(const auto& v : adjList[u]){
        if(check(v))
            return true;
        if(tWght[v] != ans){
            fix(v,ans);
            return true;
        }
    }
    return false;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s, t, b;
    char c;
    int w;
    while(getline(cin, s)){
        stringstream ss(s);
        ss >> t;
        strs.insert(t);
        ss >> c;
        ss >> w;
        ss >> c;
        wght[t] = w;
        if(ss >> b){
            while(ss>>b){
                if(b.back()==',')
                    b.pop_back();
                adjList[t].pb(b);
                p[b] = t;
            }
        }
    }
    string root;
    for(const auto& s : strs)
        if(!p.count(s))
            root = s;
    dfs(root);
    check(root);
    return 0;
}
