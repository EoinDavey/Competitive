#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int MX_N = 200002;
ll N, T;
ll prces[MX_N];
ll prceTree[MX_N];
ll cdyTree[MX_N];

inline int LSOne(int i){ return i&(-i);}
void update(int k, ll v, ll tree[]){
    for(;k<MX_N;k+=LSOne(k))
        tree[k]+=v;
}
ll query(int k, ll tree[]){
    ll out=0;
    for(;k;k-=LSOne(k))
        out+=tree[k];
    return out;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> T;
    for(int i = 1; i <= N; ++i){
        cin >> prces[i];
        update(i, prces[i], prceTree);
        update(i, 1, cdyTree);
    }
    ll candies = 0;
    for(;;){
        // First go around fully as many times as possible
        ll fullCycSum = query(N,prceTree);
        ll num = query(N, cdyTree);
        if(num==0)
            break;

        ll tms = T/fullCycSum;
        T-=fullCycSum*tms;
        candies += tms*num;

        // there is now a shop we cannot afford
        ll L = 1;  ll R = N;
        while(L < R){
            ll md = (L+R)/2;
            if(query(md, prceTree) <= T){
                L = md+1;
            } else {
                R = md;
            }
        }
        // L is the shop we can't afford
        update(L, -prces[L], prceTree);
        update(L, -1, cdyTree);
    }
    cout << candies << endl;
    return 0;
}
