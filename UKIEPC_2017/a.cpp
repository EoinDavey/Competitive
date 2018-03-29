#include <bits/stdc++.h>
using namespace std;

struct Se {
    int day, start, end;
};

int n;
int night = 0;
Se ss[20];
int mh = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ss[i].day >> ss[i].start >> ss[i].end;
        if (ss[i].day * 1825 > mh) {
            mh = ss[i].day * 1825;
        }
        if (ss[i].end >= ss[i].start) {
            night++;
        }
    }

    for (int h = 0; h < mh; h++) {
        for (int j = 0; j < n; j++) {
            if (h % ss[j].day == ss[j].end) night++;
        }
        if (night == n) {
            cout << h << endl;
            return 0;
        }
        for (int j = 0; j < n; j++) {
            if (h % ss[j].day == ss[j].start) night--;
        }
    }
    cout << "impossible\n";
    return 0;
}
