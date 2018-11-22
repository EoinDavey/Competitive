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

const int MX_N = 50040;
vector<int> strs[MX_N];
vector<string> dict;

vector<int> buildFailure(const string& s){
    int n = sz(s);
    vector<int> T(n+1,0);
    T[0]=-1;
    int j = 0;
    for(int i = 1; i < s.size();++i){
        if(s[i]==s[j]){
            T[i]=T[j];
            j++;
        } else{
            T[i] = j;
            j = T[j];
            while(j >= 0 && s[i]!=s[j])
                j = T[j];
            j++;
        }
    }
    T[s.size()] = j;
    return T;
}

vector<int> search(const string& W, const string& S){
    auto T=buildFailure(W);
    vector<int> p;
    int k = 0;
    int j = 0;
    while(j < S.size()){
        if(W[k]==S[j]){
            k++; j++;
            if(k==W.size()){
                p.push_back(j-k);
                k = T[k];
            }
        }else{
            k = T[k];
            if(k < 0)
                j+=1, k+=1;
        }
    }
    return p;
}

void slve(const string& s){
    for(int i = 0; i < sz(s); ++i)
        strs[i].clear();
    for(int i = 0; i < sz(dict); ++i){
        auto v = search(dict[i], s);
        for(int u : v){
            strs[u].pb(i);
        }
    }
    int dp[sz(s)+1]; memset(dp, 0, sizeof(dp));
    for(int i = sz(s)-1; i >= 0; --i){
        dp[i] = dp[i+1];
        for(int v : strs[i])
            dp[i] = max(dp[i], 1 + dp[i + sz(dict[v])]);
    }
    pr(dp[0]);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a;
    for(;;){
        rd(a);
        if(a=="#")
            break;
        dict.pb(a);
    }
    stringstream ss;
    for(;;){
        ss = stringstream();
        char c;
        for(;;){
            rd(c);
            if(c=='|' || c=='#')
                break;
            if(c>='a' && c <= 'z')
                ss << c;
        }
        if(c=='#')
            break;
        string w = ss.str();
        slve(w);
    }
    return 0;
}
