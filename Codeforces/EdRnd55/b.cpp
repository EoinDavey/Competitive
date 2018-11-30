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

const int MX_N = 200002; //TODO
int p[MX_N];
int sz[MX_N];
int N;

int find(int i) { return p[i] = (p[i]==i ? i : find(p[i]));}
void join(int a, int b){
    a = find(a); b = find(b);
    if(a==b)
        return;
    p[a] = b;
    sz[b] += sz[a];
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string S;
    rd2(N, S);
    int totsz;
    for(int i = 0;i < N; ++i)
        p[i] = i, sz[i]=1;
    for(int i = 1; i < N; ++i)
        if(S[i]=='G' && S[i-1]=='G')
            join(i, i-1);
    int tot = 0;
    for(int i = 0; i < N; ++i)
        tot+=S[i]=='G';
    int mx = 0;
    for(int i = 0; i < N; ++i)
        if(S[i]=='G')
            mx = max(mx, sz[find(i)]);
    for(int i = 0; i < N; ++i){
        if(S[i]=='G')
            continue;
        if(i > 0 && i < N-1 
                && S[i-1] == 'G' && S[i+1]=='G'){
            if(sz[find(i-1)] + sz[find(i+1)] != tot)
                mx = max(mx, sz[find(i-1)] + sz[find(i+1)] + 1);
            else
                mx = max(mx, sz[find(i-1)] + sz[find(i+1)]);
        }
        if(i > 0 && S[i-1]=='G' && sz[find(i-1)] != tot)
            mx = max(mx, sz[find(i-1)] + 1);
        if(i < N-1 && S[i+1]=='G' && sz[find(i+1)] != tot)
            mx = max(mx, sz[find(i+1)] + 1);
    }
    pr(mx);
    return 0;
}
