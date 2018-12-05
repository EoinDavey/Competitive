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

const int MX_N = 50005;
int N;
set<ii> adjList[MX_N];
multiset<int> cols[MX_N];
bool bad[MX_N];

void dfs(int u, int p){
    bad[u]=true;
    auto i = adjList[u].begin();
    while(i != adjList[u].end()){
        if(i->first==p){
            i++;
            continue;
        }
        dfs(i->first, u);
        i = next(i);
        adjList[u].erase(prev(i));
    }
}

void check(int u){
    auto i = adjList[u].begin();
    while(i != adjList[u].end()){
        if(cols[u].count(i->se) > 1){
            dfs(i->first,u);
            i++;
            adjList[u].erase(prev(i));
        } else {
            i++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    int a,b,c;
    for(int i= 0; i < N-1; ++i){
        rd3(a,b,c);
        adjList[a].insert({b,c});
        adjList[b].insert({a,c});
    }
    for(int i = 1; i <= N; ++i)
        for(const auto& e : adjList[i])
            cols[i].insert(e.se);
    for(int i = 1; i <= N; ++i)\
        check(i);
    int cnt = 0;
    for(int i = 1; i <= N; ++i)
        cnt+=!bad[i];
    pr(cnt);
    for(int i = 1; i <= N; ++i)
        if(!bad[i])
            pr(i);
    return 0;
}
