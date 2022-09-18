#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 110;

int N;
ll inp[MAX_N][MAX_N];
ll n_paths[MAX_N][MAX_N];
ll path_sum[MAX_N][MAX_N];
ll edge[MAX_N][MAX_N];
bool vis[MAX_N];

vector<int> top;

void top_sort(int u) {
    vis[u] = true;
    for(int i = 0; i < N; ++i) {
        if(inp[u][i] == -1)
            continue;
        if(vis[i])
            continue;
        top_sort(i);
    }
    top.push_back(u);
}

int main() {
    cin >> N;
    memset(edge, -1, sizeof(edge));
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> inp[i][j];

    for(int i = 0; i < N; ++i)
        if(!vis[i])
            top_sort(i);

    for(int ui = 0; ui < N; ++ui){
        int u = top[ui];
        for(int vi = ui-1; vi >= 0; --vi) {
            int v = top[vi];
            if(inp[u][v] == -1)
                continue;
            for(int wi = ui-1; wi > vi; --wi) {
                int w = top[wi];
                if(edge[w][v] == -1LL)
                    continue;
                n_paths[u][v] += n_paths[u][w];
                path_sum[u][v] += path_sum[u][w] + n_paths[u][w] * edge[w][v];
            }
            ll e = inp[u][v] * (n_paths[u][v] + 1) - path_sum[u][v];
            if(n_paths[u][v] != 0LL && e >= inp[u][v])
                continue;
            edge[u][v] = e;
            n_paths[u][v] += 1LL;
            path_sum[u][v] += e;
        }
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
