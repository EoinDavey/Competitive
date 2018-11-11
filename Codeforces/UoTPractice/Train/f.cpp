#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int MX_N = 100002;
ll a[MX_N];

int main(){
    ios::sync_with_stdio(false);
    int T;cin >> T;
    while(T-->0) {
        unordered_set<ll> st;
        int N; cin >> N;
        for(int i = 0; i < N; ++i){
            cin >> a[i];
            st.insert(a[i]);
        }
        ll sm = 0;
        for(int i = 0; i < N; ++i){
            ll lm = sqrt(a[i])+1;
            ll ans = a[i];
            for(ll j = 1; j <= lm; ++j){
                if(a[i]%j==0){
                    if(st.find(j)!=st.end()){
                        ans = min(ans, j);
                        break;
                    }
                    if(st.find(a[i]/j) != st.end())
                        ans = min(ans, a[i]/j);
                }
            }
            sm+=ans;
        }
        cout << sm << endl;
    }
    return 0;
}
