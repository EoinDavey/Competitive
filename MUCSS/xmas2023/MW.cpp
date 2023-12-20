#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll M = 1000000000 + 7;
const int MX_RG = 200002;

ll dp_prv[MX_RG];
ll dp_nxt[MX_RG];

int t(int n) {
    return (n*(n+1)) / 2ll;
}

int calcH(int r, int g) {
    int lh = 0;
    for(int h = 1; h <= 1000; h++)
        if(t(h) <= r + g)
            lh = h;
    return lh;
}

ll dp(int mxh, int R, int G){
    for(int r = 0; r <= R; r++){
        dp_prv[r] = 1;
        dp_nxt[r] = 0;
    }
    for(int h = mxh-1; h >= 0; --h){
        for(int r = 0; r <= R; r++){
            int g = (R+G) - t(h) - r;
            ll sm = 0;
            if(r >= h + 1)
                sm += dp_prv[r-(h+1)];
            if(g >= h + 1)
                sm += dp_prv[r];
            dp_nxt[r] = sm % M;
        }
        for(int r = 0; r <= R; r++){
            ll t = dp_prv[r];
            dp_prv[r] = dp_nxt[r];
            dp_nxt[r] = t;
        }
    }
    return dp_prv[R];
}

int main() {
    int R, G;
    cin >> R >> G;
    cout << dp(calcH(R, G), R, G) << endl;
    return 0;
}
