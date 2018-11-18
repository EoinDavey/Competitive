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

const int MX_N = 100011;
int memo[MX_N][6], nt[MX_N], N;

bool dp(int p, int f){
    if(memo[p][f] != -1)
        return memo[p][f];
    if(p==0)
        return memo[p][f] = true;
    int cnt = nt[p];
    int pnt = nt[p-1];
    if(cnt > pnt){
        for(int i = 1; i < f; ++i)
            if(dp(p-1, i))
                return memo[p][f] = true;
    } else if(cnt < pnt){
        for(int i = f+1; i <= 5; ++i)
            if(dp(p-1, i))
                return memo[p][f] = true;
    } else {
        for(int i = 1; i <= 5; ++i)
            if(i!=f && dp(p-1, i))
                return memo[p][f] = true;
    }
    return memo[p][f] = false;
}

vi ans;
void prt(int p, int f){
    ans.pb(f);
    if(p==0)
        return;
    int cnt = nt[p];
    int pnt = nt[p-1];
    if(cnt > pnt){
        for(int i = 1; i < f; ++i)
            if(dp(p-1, i)){
                prt(p-1,i);
                return;
            }
    } else if(cnt < pnt){
        for(int i = f+1; i <= 5; ++i)
            if(dp(p-1, i)){
                prt(p-1,i);
                return;
            }
    } else {
        for(int i = 1; i <= 5; ++i)
            if(i!=f && dp(p-1, i)){
                prt(p-1,i);
                return;
            }
    }
}

int main(){
    ios::sync_with_stdio(false);
    memset(memo, -1, sizeof(memo));
    rd(N);
    for(int i = 0; i < N; ++i)
        rd(nt[i]);

    int a = -1;
    for(int i = 1; i<= 5; ++i){
        if(dp(N-1, i)){
            a = i;
            break;
        }
    }

    if(a==-1)
        pr("-1");
    else{
        prt(N-1, a);
        for(auto v = ans.rbegin(); v != ans.rend(); v++)
            cout << *v << ' ';
        cout << endl;
    }
    return 0;
}
