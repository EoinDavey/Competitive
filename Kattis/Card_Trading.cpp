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

const int MX_N = 1000; //TODO

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N, T, K; rd3(N,T,K);
    ll pr2[T];
    ll cnt[T]; memset(cnt, 0, sizeof(cnt));
    ll t,a,b;
    for(int i = 0; i < N; ++i){
        rd(t);
        --t;
        ++cnt[t];
    }
    ll mn = 0;
    for(int i = 0; i < T; ++i){
        rd2(a,b);
        if(cnt[i] >= 2)
            pr2[i] = cnt[i]*b;
        else if(cnt[i]==0)
            pr2[i] = 2*a;
        else
            pr2[i] = a+b;

        mn += cnt[i]*b;
    }
    sort(pr2, pr2+T);
    for(int i = 0; i < K; ++i)
        mn -= pr2[i];
    pr(mn);
    return 0;
}
