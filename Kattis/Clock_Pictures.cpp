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

const int SZ = 360000;
const int MX_N = 2*SZ+3;
int N;
bool a[MX_N], b[MX_N];

vector<int> buildFailure(){
    vector<int> T(SZ+1,0);
    T[0]=-1;
    int j = 0;
    for(int i = 1; i < SZ; ++i){
        if(a[i]==a[j]){
            T[i]=T[j];
            j++;
        } else{
            T[i] = j;
            j = T[j];
            while(j >= 0 && a[i]!=a[j])
                j = T[j];
            j++;
        }
    }
    T[SZ] = j;
    return T;
}

bool search(){
    auto T=buildFailure();
    vector<int> p;
    int k = 0;
    int j = 0;
    while(j < 2*SZ){
        if(a[k]==b[j]){
            k++; j++;
            if(k==SZ){
                return true;
            }
        }else{
            k = T[k];
            if(k < 0)
                j+=1, k+=1;
        }
    }
    return false;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rd(N);
    int ai;
    for(int i = 0; i < N; ++i){
        rd(ai);
        a[ai]=true;
    }
    for(int i = 0; i < N; ++i){
        rd(ai);
        b[ai]=true;
        b[SZ+ai]=true;
    }
    if(search())
        pr("possible");
    else
        pr("impossible");
    return 0;
}
