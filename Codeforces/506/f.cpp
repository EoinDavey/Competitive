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
    ll a,b; rd2(a,b);
    if(b < a)
        swap(a,b);
    ll lim = sqrt(a) + 2;
    for(ll i = 1; i <=lim; ++i){
        if(a % i == 0){
            //i * (a/i) rectangle
        }
    }
    return 0;
}
