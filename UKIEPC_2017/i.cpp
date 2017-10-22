#include <bits/stdc++.h>
using namespace std;

int s[10];
int n, h;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cin >> h;


    int bs = 0;
    int ll = h % s[0];
    for (int i = 1; i < n; i++) {
        if (h % s[i] < ll) {
            bs = i;
            ll = h % s[i];
        }
    }
    cout << s[bs] << '\n';
    return 0;
}
