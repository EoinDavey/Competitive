#include<bits/stdc++.h>
#define mm(x,y) ((x*y)%MOD)
#define ma(x,y) (((x+y)%MOD+MOD)%MOD)
using namespace std;
typedef long long ll;
const int MOD = 1000*1000*1000+7;
const int MX_N = 100001;
int ocnt[MX_N], a[MX_N];
int N, Q;
ll pws[MX_N];

int main(){
    scanf("%d %d",&N,&Q);
    char c;
    for(int i = 0; i < N; ++i){
        scanf(" %c",&c);
        a[i] = c=='1';
    }
    ocnt[0] = a[0]==1;
    for(int i = 1; i < N; ++i)
        ocnt[i] = ocnt[i-1] + (a[i]==1);
    pws[0] = 1LL;
    for(int i = 1; i <= N; ++i){
        pws[i] = mm(2LL,pws[i-1]);
    }
    int l,r;
    for(int i = 0; i < Q; ++i){
        scanf("%d %d",&l,&r);
        --l,--r;
        int ones = ocnt[r] - (l > 0 ? ocnt[l-1] : 0);
        int ln = (r-l+1);
        int zeros = ln - ones;
        ll ans = ma(ma(pws[ln], -1), - ma(pws[zeros], -1));
        cout << ans << endl;
    }
    return 0;
}
