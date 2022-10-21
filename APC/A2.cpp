#include<bits/stdc++.h>
#define pb push_back

typedef long long ll;

using namespace std;

vector<string> lines;
int n, l;
string _s;

int compP(int u, int v){
    for(int i = 0; i < l; ++i) {
        if(lines[u][i] != lines[v][i]) {
            return i+1;
        }
    }
    return l;
}

int cst(int i) {
    int r = 0;
    if(i > 0) {
        r = max(r, compP(i, i-1));
    }
    if(i + 1 < n) {
        r = max(r, compP(i, i+1));
    }
    //printf("%s = %d\n", lines[i], r);
    return r;
}

int main() {
    cin >> n >> l;
    for(int i = 0; i < n; ++i) {
        cin >> _s;
        lines.pb(_s);
    }
    sort(lines.begin(), lines.end());
    int sm = 0;
    for(int i = 0; i < n; ++i)
        sm += cst(i);
    printf("%d\n", sm);
    return 0;
}
