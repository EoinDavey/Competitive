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

const int MX_N = 100001;
ll ls[2][MX_N];
int N;

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    for(int i = 0; i < N; ++i)
        rd(ls[0][i]);
    for(int i = 0; i < N; ++i)
        rd(ls[1][i]);
    sort(ls[0], ls[0]+N, greater<ll>());
    sort(ls[1], ls[1]+N, greater<ll>());
    ll t = 0;
    ll sum[2] = {0,0};
    ll ptr[2] = {0,0};
    while(ptr[0] < N || ptr[1] < N){
        if(ptr[0] < N && ptr[1] < N){
            if(ls[t][ptr[t]] > ls[!t][ptr[!t]])
                sum[t] += ls[t][ptr[t]++];
            else
                ptr[!t]++;
        } else if(ptr[t] < N)
            sum[t] += ls[t][ptr[t]++];
        else
            ptr[!t]++;
        t = 1-t;
    }
    pr(sum[0]-sum[1]);
    return 0;
}
