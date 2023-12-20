#include<bits/stdc++.h>
using namespace std;
const int MX_N = 200002;
vector<int> adj[MX_N];
int col[MX_N];
int oc[MX_N];

int main() {
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; ++i)
        cin >> oc[i];
    int c = 0;
    for(int i = 1; i <= N; ++i){
        if(col[i] != 0)
            continue;
        c++;
        stack<int> st;
        st.push(i);
        col[i] = c;
        while(!st.empty()){
            int u = st.top(); st.pop();
            for(int v : adj[u]) {
                if(col[v] != 0 || oc[v] == oc[u])
                    continue;
                col[v] = c;
                st.push(v);
            }
        }
    }
    bool fnd = false;
    for(int i = 1; i <= N; ++i)
        for(int j : adj[i])
            if(oc[i] == oc[j] && col[i] == col[j])
                fnd = true;
    if(fnd)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
