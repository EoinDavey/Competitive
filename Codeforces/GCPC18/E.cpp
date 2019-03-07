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

const int MX_N = 10*1000*1000; //TODO
bool sieve[MX_N];

int rdI(string& s){
    int o = 0;
    int i = 0;
    while(i < s.size() && s[i] != '.'){
        o = 10*o + s[i]-'0';
        ++i;
    }
    if(i < s.size() && s[i]=='.')
        ++i;
    for(int j = 0; j < 5; ++j){
        o *= 10;
        if(i < s.size()){
            o += s[i]-'0';
            ++i;
        }
    }
    return o;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i = 2; i < MX_N; ++i){
        if(!sieve[i]){
            for(int j = 2*i; j < MX_N; j+=i)
                sieve[j]=true;
        }
    }
    sieve[0] = true;
    sieve[1] = true;
    int N; rd(N);
    while(N-->0){
        string s1,s2;
        cin >> s1 >> s2;
        int a = rdI(s1);
        int b = rdI(s2);
        int g = __gcd(a,b);
        a/=g;b/=g;
        if(a==b)
            pr2(2,2);
        else if(!sieve[a] && !sieve[b])
            pr2(a,b);
        else
            pr("impossible");
    }
    return 0;
}
