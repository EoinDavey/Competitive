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
#ifdef JUDGE
#define dbg(x) x
#else
#define dbg(x)
#endif
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;
typedef vector<ii> vii;

const int MX_N = 2000; //TODO
vii cvses;
int cnt[MX_N], N;
set<int> pgs, npgs;

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    for(int i = 0; i < N; ++i){
        int l, r; rd2(l, r);
        cvses.pb({l, r});
    }
    int p; rd(p);
    for(int i = 0; i < p; ++i){
        int x; rd(x);
        pgs.insert(x);
        for(int j = 0; j < N; ++j){
            if(x >= cvses[j].fi && x <= cvses[j].se)
                ++cnt[j];
        }
    }
    for(int i = 1; i < N; ++i){
        if(cvses[i-1].se == cvses[i].fi && cnt[i-1] < 2 && cnt[i] < 2 && !pgs.count(cvses[i].fi)){
            int x = cvses[i].fi;
            pgs.insert(x);
            npgs.insert(x);
            ++cnt[i];
            ++cnt[i-1];
        }
    }
    for(int i = 0; i < N; ++i){
        while(cnt[i] < 2){
            for(int x = cvses[i].fi+1; x < cvses[i].se; ++x){
                if(pgs.count(x) != 0)
                    continue;
                pgs.insert(x);
                npgs.insert(x);
                ++cnt[i];
                break;
            }
        }
    }
    bool fail = false;
    for(int i = 0; i < N; ++i)
        if(cnt[i] != 2)
            fail = true;
    if(fail)
        pr("impossible");
    else{
        pr(sz(npgs));
        for(int x : npgs){
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}
