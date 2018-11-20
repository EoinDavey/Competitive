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

const int MX_N = 200002;

int tree[MX_N*4 + 2];
int a[MX_N];
int N, Q;
int nd[MX_N],beg[MX_N];

void construct(int p, int L, int R){
    if(L==R){
        tree[p] = a[L];
        return;
    }
    if(R<L)
        return;
    int md = (L+R)/2;
    construct(2*p,L,md);
    construct(2*p+1,md+1,R);
    tree[p] = min(tree[2*p],tree[2*p+1]);
}

int rmq(int p, int L, int R, int l, int r){
    if(r < L || l > R)
        return INFI;
    if(l>=L && r<=R)
        return tree[p];
    int md = (l+r)/2;
    return min(rmq(2*p,L,R,l,md),rmq(2*p+1,L,R,md+1,r));
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(nd, -1, sizeof(nd));
    memset(beg, -1, sizeof(beg));
    rd2(N,Q);
    for(int i = 0; i < N; ++i)
        rd(a[i]);
    bool hasQ = false;
    bool has0 = false;
    for(int i = 0; i < N; ++i)
        if(a[i]==Q)
            hasQ=true;
    for(int i = 0; i < N; ++i)
        if(a[i]==0)
            has0=true;
    if(!hasQ && !has0){
        pr("NO");
        return 0;
    }
    for(int i = 0; i < N; ++i)
        if(beg[a[i]]==-1)
            beg[a[i]]=i;
    for(int i = N-1; i >=0; --i)
        if(nd[a[i]]==-1)
            nd[a[i]]=i;
    for(int i = 0; i < N; ++i)
        if(a[i]==0)
            a[i]=INFI;
    construct(1, 0, N-1);
    bool fail = false;
    for(int i = 1; i <= Q && !fail; ++i){
        if(beg[i]==-1)
            continue;
        int mn = rmq(1, beg[i], nd[i],0,N-1);
        if(mn < i)
            fail=true;
    }
    if(fail){
        pr("NO");
        return 0;
    }
    for(int i = 0; i < N && !hasQ; ++i)
        if(a[i]==INFI)
            a[i]=Q,hasQ=true;
    queue<int> q;
    for(int i = 0; i < N; ++i){
        if(a[i]==INFI)
            q.push(i);
        else{
            while(!q.empty()){
                a[q.front()] = a[i];
                q.pop();
            }
        }
    }
    while(!q.empty())
        q.pop();
    for(int i = N-1; i >= 0; --i){
        if(a[i]==INFI)
            q.push(i);
        else{
            while(!q.empty()){
                a[q.front()] = a[i];
                q.pop();
            }
        }
    }
    while(!q.empty()){
        a[q.front()] = 1;
        q.pop();
    }
    pr("YES");
    for(int i = 0; i < N; ++i)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
