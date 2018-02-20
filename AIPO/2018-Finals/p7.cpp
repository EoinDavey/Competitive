#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MX_RG = 400002;
constexpr int MX_H = 895;
constexpr ll MD_7 =  1000000007LL;

ll tb[2][MX_RG];

int S,R,G;

int mx_size(int k){
    return floor(-0.5 + sqrt(0.25 + (2.0*k)));
}

int main(){
    bool c = true;
    scanf("%d %d",&R,&G);
    S = R+G;
    int h = mx_size(S);
    int blcks = (h*(h+1))/2;
    tb[!c][0] = 1LL;
    for(int i = 1; i <= h; ++i){
        for(int j = 0; j <= (i*(i+1))/2; ++j){
            tb[c][j] = (tb[!c][j] + (j >= i ? tb[!c][j-i] : 0LL))%MD_7;
        }
        c = !c;
    }
    ll sm = 0;
    for(int i = 0; i <= R; ++i){
        int g = blcks - i;
        if(i <= R && g <= G)
            sm = (sm+tb[!c][i])%MD_7;
    }
    printf("%lld\n",sm);
    return 0;
}
