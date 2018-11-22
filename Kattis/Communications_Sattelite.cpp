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

const int MX_N = 2002;
cc circs[MX_N];
double r[MX_N], dis[MX_N];
bool used[MX_N];
int N;

inline double dist(int a, int b){
    return abs(circs[a]-circs[b]) - r[a] - r[b];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    double x,y;
    for(int i = 0; i < N; ++i){
        rd3(x,y,r[i]);
        circs[i]={x,y};
    }
    for(int i = 0; i < N; ++i)
        dis[i] = 1e10;
    typedef pair<double, int> pd;
    priority_queue<pd, vector<pd>, greater<pd> > q;
    q.push({0,0});
    dis[0] = 0.0;
    double cst = 0.0;
    while(!q.empty()){
        pd p = q.top(); q.pop();
        if(used[p.se])
            continue;
        used[p.se]=true;
        cst+=p.fi;
        for(int i = 0; i < N; ++i){
            if(used[i])
                continue;
            if(dist(p.se, i) < dis[i]){
                dis[i] = dist(p.se, i);
                q.push({dis[i], i});
            }
        }
    }
    pr(fixed << setprecision(8) << cst);
    return 0;
}
