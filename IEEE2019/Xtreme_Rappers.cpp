#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

long long solve(ll K, ll J){
    ll alph = 2*J - K;
    if(alph%3LL != 0)
        return -1;
    ll bet = 2*K - J;
    if(bet%3LL != 0)
        return -1;
    return alph/3LL + bet/3LL;
}

ll srch(ll K, ll J){
    ll mx = 0;
    for(ll dj = 0; dj < 20; ++dj){
        for(ll dk = 0; dk < 20; ++dk){
            ll nk = K - dk;
            ll nj = J - dj;
            if(nk <= 0 || nj <= 0)
                continue;
            mx = max(mx, solve(nk,nj));
        }
    }
    return mx;
}

int main() {
    long long a, b;
    cin >> a >> b;
    long long cnt = 0;
    while ((a >= 2 && b >= 1) || (a >= 1 && b >=2)) {
        long long amount = 1;
        if(a == b){
            cnt += srch(a, b);
            a = 0;b = 0;
            break;
        }
        if (a > b) {
            long long diff = a - b;
            amount = diff / 2L > 1L ? diff / 2L : 1L;
            if (a - (2 * amount) < 0L) {
                amount = a / 2;
            }
            if ((b - amount) < 0L) {
                amount = b;
            }
            a -= (2L * amount);
            b -= (1L * amount);
        }
        else{
            long long diff = b - a;
            amount = diff / 2L > 1L ? diff / 2L : 1L;
            if (b - (2L * amount) < 0L) {
                amount = b / 2L;
            }
            if ((a - amount) < 0L) {
                amount = a;
            }
            b -= (2L * amount);
            a -= (1L * amount);
        }
        cnt += amount;
    }
    cout << cnt << endl;
    return 0;
}
