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

const int MX_N = 1000*1000+2;
vi adjList[MX_N];
vi radjList[MX_N];

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 0;
    int scr[] = {1,1};
    while(scr[0] <MX_N && scr[1]<MX_N){
        adjList[scr[t]].pb(scr[!t]);
        radjList[scr[!t]].pb(scr[t]);
        scr[t] += scr[!t];
        t=!t;
    }
    int N; rd(N);
    map<int,int> ind;
    int m;
    bool found = false;
    for(int i = 0; i < N && !found; ++i){
        scanf("%d",&m);
        for(int x : adjList[m]){
            if(ind.count(x)){
                pr2(i+1,ind[x]);
                found=true;
                break;
            }
        }
        if(found)
            break;
        for(int x : radjList[m]){
            if(ind.count(x)){
                pr2(ind[x], i+1);;
                found=true;
                break;
            }
        }
        ind[m] = i+1;
    }
    if(!found)
        pr("impossible");
    return 0;
}
