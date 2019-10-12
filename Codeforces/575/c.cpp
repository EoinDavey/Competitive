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
const int INFI = 100000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 1000; //TODO
int Q;
struct rec{ int tb,bb,lb,rb;};
struct rbt{ int x, y; rec bnds;};

rec insct(const rec& a, const rec& b) {
    return {
        min(a.tb, b.tb), max(a.bb, b.bb), max(a.lb, b.lb), min(a.rb, b.rb)
    };
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(Q);
    while(Q-->0){
        vector<rec> recs;
        {
            int n; rd(n);
            int x,y,f1,f2,f3,f4;
            for(int i = 0; i < n; ++i){
                cin >> x >> y >> f1 >> f2 >> f3 >> f4;
                recs.pb({f2 == 0 ? y : INFI, f4 == 0 ? y : -INFI,
                            f1 == 0 ? x : -INFI, f3 == 0 ? x : INFI});
            }
        }
        rec field{INFI,-INFI,-INFI,INFI};
        for(const auto& r : recs){
            field = insct(field, r);
            dbg(printf("tb: %d, bb:%d, lb:%d, rb:%d\n", r.tb,r.bb,r.lb,r.rb));
        }
        if(field.tb < field.bb || field.rb < field.lb){
            pr("0");
            continue;
        }
        cout << 1 << ' ' << field.lb << ' ' << field.tb << endl;
    }
    return 0;
}
