#include<bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> edges;

void print(set<int> &s) {
    cout << s.size() << endl;
    for(const auto x : s) {
        cout << x << endl;
    }
}

int main() {
    cin >> N >> M;

    set<int> inc, dec;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if(u < v)
            inc.insert(i+1);
        else
            dec.insert(i+1);
    }
    if(inc.size() > dec.size())
        print(dec);
    else 
        print(inc);
    return 0;
}
