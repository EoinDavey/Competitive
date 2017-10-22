#include <bits/stdc++.h>
#define rep(_v, _e) for (decltype(_e) _v  = 0; _v < _e; _v++)
using namespace std;

static int overlap(int a1, int a2, int b1, int b2) {
    int la = min(a1, a2);
    int lb = min(b1, b2);
    int ma = max(a1, a2);
    int mb = max(b1, b2);

    // No overlap
    if (la >= mb || lb >= ma) return 0;
    // Complete overlap
    if ((la <= lb && ma >= mb) || (lb <= la && mb >= ma)) return 1;
    // Check if colliding?
    return (a1 < a2 && b2 < b1) || (a1 > a2 && b2 > b1);
}

int b[2][2][3]; // bot, kind, xyz
int md[2];
vector<int> dirs[2];

static void pc() {
    printf("(%d %d %d) (%d %d %d)\n",
            b[0][0][0], b[0][0][1], b[0][0][2],
            b[1][0][0], b[1][0][1], b[1][0][2]);
}

static int sgn(int a) {
    return (a > 0) - (a < 0);
}

static void mv(int x) {
    if (dirs[x].empty()) return;
    int d = dirs[x][0];
    b[x][0][d] += sgn(b[x][1][d] - b[x][0][d]);
    if (b[x][0][d] == b[x][1][d]) dirs[x].erase(dirs[x].begin());

    printf("CHECK ");
    pc();
    assert(!(b[0][0][0] == b[1][0][0] && b[0][0][1] == b[1][0][1] && b[0][0][2] == b[1][0][2]));
}

int main() {
    rep(i, 2) rep(j, 2) rep(k, 3) {
        cin >> b[i][j][k];
    }

    int oc = 0;
    int la = -1;
    int nudge, tonudge = 0;

    rep (i, 3) {
        int t =  overlap(b[0][0][i], b[0][1][i], b[1][0][i], b[1][1][i]);
        if (t) la = i;
        oc += t;

        if (b[0][0][i] != b[0][1][i]) dirs[0].push_back(i);
        md[0] += abs(b[0][0][i] - b[0][1][i]);
        md[1] += abs(b[1][0][i] - b[1][1][i]);
    }

    for (int i = 2; i >= 0; i--) {
        if (b[1][0][i] != b[1][1][i]) dirs[1].push_back(i);
    }
    if (dirs[1].size() >= 2) swap(dirs[1][0], dirs[1][1]);

    pc();
    if (oc == 1) {
        nudge = ((la + 1) % 3);
        if (md[0] > md[1]) tonudge = 1;
        b[tonudge][0][nudge]++;
        mv(!tonudge);
        pc();
    }

    while (!dirs[0].empty() || !dirs[1].empty()) {
        mv(0);
        mv(1);
        pc();
    }

    if (oc == 1) {
        b[tonudge][0][nudge]--;
        pc();
    }

    return 0;
}
