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
#define msub(a,b,m) ((((a - b) % m) + m) % m)
using namespace std;
typedef long long ll;
typedef complex<double> cc;
typedef pair<int, int> ii;
typedef vector<int> vi;
const double EPS = 1e-8;
const int INFI = 1000*1000*1000;
const ll INFL = 1000LL*1000LL*1000LL*1000LL*1000LL;

const int MX_N = 1000; //TODO

int wrongPlace(const vi &v){
    int cnt[4] = {0,0,0,0};
    for(int i : v)
        cnt[i]++;

    int elcnt = 1;
    for(int i : v)
        elcnt = max(elcnt, i+1);
    assert(elcnt <= 4);

    queue<int> qs[elcnt];
    for(int i = 0; i < elcnt; ++i)
        qs[i] = queue<int>();

    int sm = 0;
    for(int x : v){
        for(int i = 0; i < elcnt; ++i){
            if(sz(qs[i]) < cnt[i]){
                if(x != i)
                    ++sm;
                qs[i].push(x);
                break;
            }
        }
    }
    int mn = sm;
    for(int i = 0; i < (1+sz(v))/2; ++i){
        for(int j = 0; j < elcnt; ++j){
            int val = qs[j].front(); qs[j].pop();
            if(val != j)
                sm -= 1;
            qs[msub(j,1,elcnt)].push(val);
            if(val != msub(j,1,elcnt))
                sm += 1;
        }
        mn = min(mn, sm);
    }
    return mn;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T; rd(T);
    while(T -->0){
        string s; rd(s);
        set<char> st;
        for(char x : s)
            st.insert(x);
        int elcnt = sz(st);
        map<char,int> indmp;
        for(char x : st)
            indmp[x] = sz(indmp);

        int perm[elcnt];
        for(int i = 0; i < elcnt; ++i)
            perm[i] = i;

        int mn = INFI;
        do {
            vi v(sz(s));
            for(int i = 0; i < sz(s); ++i)
                v[i] = perm[indmp[s[i]]];
            int cst = wrongPlace(v);
            mn = min(cst, mn);
        }while(next_permutation(perm, perm+elcnt));
        pr(mn);
    }
    return 0;
}
