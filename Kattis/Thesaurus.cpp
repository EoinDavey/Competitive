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

const int MX_N = 10011;
int N, M;
int p[MX_N], mn[MX_N];
unordered_map<string, int> indMap;

int find(int i) { return p[i] = (p[i]== i ? i : find(p[i])); }
int join(int a, int b){
    a = find(a);
    b = find(b);
    p[b] = a;
    mn[a] = min(mn[a], mn[b]);
}

int insert(const string& s){
    if(indMap.count(s))
        return indMap[s];
    int ind = sz(indMap);
    indMap[s] = ind;
    p[ind] = ind;
    mn[ind] = sz(s);
    return ind;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd2(N,M);
    vector<int> sent;
    string a,b;
    for(int i = 0; i < N; ++i){
        rd(a);
        int j = insert(a);
        sent.pb(j);
    }
    for(int i = 0; i < M; ++i){
        rd2(a,b);
        int ia = insert(a);
        int ib = insert(b);
        join(ia,ib);
    }
    int cnt = 0;
    for(const auto& s : sent)
        cnt+=mn[find(s)];
    pr(cnt);
    return 0;
}
