#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1002;

int N, K;
string nodes[MAX_N];
int p[MAX_N];

int find(int u) { return p[u] = (p[u] == u ? u : find(p[u])); }
void join(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa != pb)
        p[pa] = pb;
}

struct edge {
    int u;
    int v;
    int w;
    bool operator<(const edge &e) const {
        return w < e.w;
    }
};

int cost(string &s1, string &s2) {
    int cst = 0;
    for(int i = 0; i < K; ++i) {
        if(s1[i] != s2[i])
            cst++;
    }
    return cst;
}

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> nodes[i];
    }

    vector<edge> es;
    for(int i = 0; i < N; ++i)
        for(int j = i+1; j < N; ++j)
            es.push_back(edge{i, j, cost(nodes[i], nodes[j])});
    sort(es.begin(), es.end());
    for(int i = 0; i < N; ++i)
        p[i] = i;

    vector<edge> used;
    int wt = 0;
    for(const auto& e : es) {
        if(find(e.u) == find(e.v))
            continue;
        join(e.u, e.v);
        used.push_back(e);
        wt += e.w;
    }
    printf("%d\n", wt);
    for(const auto& e : used) {
        printf("%d %d\n", e.u, e.v);
    }
    return 0;
}
