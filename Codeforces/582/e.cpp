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

const int MX_N = 1000; //TODO
int N;
string s,t;
string strs[] = {"abc","acb","bac","bca","cab","cba"};
int nstrs = 6;

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    rd2(s,t);
    int dobc = 0;
    pr("YES");
    if(s[0] == s[1]) ++dobc;
    if(t[0] == t[1]) ++dobc;
    if(N == 1 || !dobc){
        for(int i = 0; i < nstrs; ++i){
            string s1 = strs[i].substr(0,2);
            string s2 = strs[i].substr(1,2);
            if(s == s1 || s == s2 || t == s1 || t == s2)
                continue;
            for(int j = 0; j < 3; ++j)
                for(int k = 0; k < N; ++k)
                    cout << strs[i][j];
            putchar('\n');
            return 0;
        }
    } else {
        for(int i = 0; i < nstrs; ++i){
            bool pass = true;
            string ap = strs[i] + strs[i];
            for(int j = 0; j < sz(ap)-1 && pass; ++j){
                string sb = ap.substr(j, 2);
                if(s == sb || t == sb)
                    pass = false;
            }
            if(!pass)
                continue;
            for(int j = 0; j < N; ++j)
                cout << strs[i];
            cout << endl;
            break;
        }
    }
    return 0;
}
