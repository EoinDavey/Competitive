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

struct t {
    int cnt[26];
    t(){ memset(cnt, 0, sizeof cnt); }
    bool operator<(const t& p) const {
        for(int i = 0; i < 26; ++i)
            if(cnt[i] != p.cnt[i])
                return cnt[i] < p.cnt[i];
        return false;
    }
    t& operator=(const t& p) {
        for(int i = 0; i < 26; ++i)
            cnt[i]=p.cnt[i];
    }
};

const int MX_N = 1000; //TODO

int check(const string& a, const string& b, int k){
    set<t> mp;
    t cnt;
    int N = sz(a);
    for(int i = 0; i < N; ++i){
        ++cnt.cnt[a[i]-'a'];

        if(i + 1 >= k)
            mp.insert(cnt);

        if(i + 1 >= k)
            --cnt.cnt[a[i+1-k]-'a'];
    }
    cnt = t{};
    for(int i = 0; i < N; ++i){
        ++cnt.cnt[b[i]-'a'];

        if(i + 1 >= k)
            if(mp.count(cnt))
                return i+1-k;

        if(i + 1 >= k)
            --cnt.cnt[b[i+1-k]-'a'];
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T; rd(T);
    string a,b;
    while(T-->0){
        rd2(a,b);
        bool ba=true;
        for(int k = sz(a);ba && k > 0; --k){
            int ind = check(b,a,k);
            if(ind!=-1){
                pr(a.substr(ind,k));
                ba=false;
            }
        }
        if(ba)
            pr("NONE");
    }
    return 0;
}
