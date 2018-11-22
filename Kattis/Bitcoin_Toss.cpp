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

int check(const string& s, int n){
    int ln = 1<<n;
    int msk = ln-1;
    int rsm = 0;
    int val[sz(s)]; memset(val, 0, sizeof(val));
    for(int i = 0; i < sz(s); ++i){
        if(s[i]=='H')
            rsm |= 1;

        if(i - n + 1 >= 0)
            val[i-n+1] = rsm;

        rsm <<= 1;
        rsm &= msk;
    }

    bool cnt[ln]; memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i + n*ln <= sz(s); ++i){
        bool b = false;
        for(int x = 0; x < ln; ++x){
            if(cnt[val[i+x*n]])
                b=true;
            cnt[val[i+x*n]]=true;
        }
        for(int x = 0; x < ln; ++x){
            cnt[val[i+x*n]]=false;
        }
        if(!b)
            return i;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T; rd(T);
    string a;
    while(T-->0){
        rd(a);
        for(int i = 10; i >= 0; --i){
            int ind = check(a, i);
            if(ind != -1){
                pr2(i, ind);
                break;
            }
        }
    }
    return 0;
}
