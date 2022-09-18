#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N;

int main() {
    cin >> N;

    for(ll d = 1; d*d <= N; d++) {
        if(N % d != 0)
            continue;
        ll x = d;
        ll y = N / d;

        ll m = (x + y) / 2;
        ll k = y - m;

        if(m * m - k * k != N)
            continue;

        cout << m << " " << k << endl;
        return 0;
    }
    cout << "impossible" << endl;
    return 0;
}
