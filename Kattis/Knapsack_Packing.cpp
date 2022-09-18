#include<bits/stdc++.h>
#define MX_N 1 << 18 + 2

typedef long long ll;
using namespace std;

int N;
ll wts[MX_N];

int main() {
    cin >> N;
    multiset<ll> togo;
    vector<ll> cleared;
    for(int i = 0; i < (1 << N); i++) {
        cin >> wts[i];
        togo.insert(wts[i]);
    }
    if(togo.count(0) == 0) {
        cout << "impossible" << endl;
        return 0;
    }
    togo.erase(togo.find(0));
    cleared.push_back(0);

    sort(wts, wts + (1 << N));

    vector<ll> as;
    int w = 0;
    while(w < (1 << N)) {
        while(w < (1 << N) && togo.count(wts[w]) == 0)
            w++;
        if(w == (1 << N))
            break;
        as.push_back(wts[w]);
        vector<ll> new_cleared;
        for(const auto c : cleared) {
            ll nw = c + wts[w];
            if(togo.find(nw) == togo.end()) {
                cout << "impossible" << endl;
                return 0;
            }
            togo.erase(togo.find(nw));
            new_cleared.push_back(nw);
        }
        for(const auto c : new_cleared) {
            cleared.push_back(c);
        }
        w++;
    }
    if(as.size() != N) {
        cout << "impossible" << endl;
        return 0;
    }
    for(const auto a : as) {
        cout << a << endl;
    }
    return 0;
}
