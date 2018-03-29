#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    double r = 0.0;

    cin >> n;
    while (n--) {
        cin >> t;
        if (t == 0) r += 2.0;
        if (t == 1) r += 1.0;
        if (t == 2) r += 1.0/2;
        if (t == 4) r += 1.0/4;
        if (t == 8) r += 1.0/8;
        if (t == 16) r += 1.0/16;
    }

    cout << setprecision(10) << r << '\n';
    return 0;
}
