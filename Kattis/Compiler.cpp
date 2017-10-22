#include<bits/stdc++.h>
using namespace std;
constexpr int MX_SZ = 300, EMP=280, INF=100000;

int op[MX_SZ][MX_SZ][MX_SZ];
int dist[MX_SZ][MX_SZ][MX_SZ];

struct state {
    int a,s1,s2;
    state(int _a, int _s1, int _s2) : a(_a),s1(_s1),s2(_s2){}
    state(){}
    bool operator != (const state& s) const {
        return a!=s.a || s1!=s.s1 || s2 != s.s2;
    }
};

state p[MX_SZ][MX_SZ][MX_SZ];

string codes[] = {"PH A",
    "PL A",
    "AD",
    "ZE A",
    "ST A",
    "DI A"};

int main(){
    int N; scanf("%d",&N);
    for(int i = 0; i < MX_SZ;++i)
        for(int j = 0; j < MX_SZ; ++j)
            for(int k = 0; k < MX_SZ; ++k)
                dist[i][j][k] = op[i][j][k] = INF;
    queue<state> q;
    state m1(-1,-1,-1);
    // ST A
    q.push(state(1,EMP,EMP));
    p[1][EMP][EMP] = m1;
    op[1][EMP][EMP] = 4;
    dist[1][EMP][EMP] = 2;
    int a,s1,s2,d;
    while(!q.empty()){
        state s = q.front(); q.pop();
        a=s.a;
        s1=s.s1;
        s2=s.s2;
        d = dist[a][s1][s2];
        //PH A
        if(op[a][a][s1] == INF){
            op[a][a][s1] = 0;
            dist[a][a][s1] = d+1;
            p[a][a][s1] = s;
            q.push(state(a,a,s1));
        }
        //PL A
        if(s1!=EMP && op[s1][s2][EMP] == INF){
            op[s1][s2][EMP] = 1;
            p[s1][s2][EMP] = s;
            dist[s1][s2][EMP] = d+1;
            q.push(state(s1,s2,EMP));
        }
        //AD
        if(s1!=EMP && s2 != EMP && op[a][(s1+s2)&255][EMP] == INF){
            op[a][(s1+s2)&255][EMP] = 2;
            dist[a][(s1+s2)&255][EMP] = d+1;
            p[a][(s1+s2)&255][EMP] = s;
            q.push(state(a,(s1+s2)&255,EMP));
        }
        // ZE A
        if(op[0][s1][s2] == INF){
            op[0][s1][s2] = 3;
            dist[0][s1][s2] = d+1;
            p[0][s1][s2] = s;
            q.push(state(0,s1,s2));
        }
        // ST A
        if(op[1][s1][s2] == INF){
            op[1][s1][s2] = 4;
            dist[1][s1][s2] = d+1;
            p[1][s1][s2] = s;
            q.push(state(1,s1,s2));
        }
    }
    state mnState;
    int mn = INF;
    for(int i = 0; i < MX_SZ; ++i){
        for(int j = 0; j < MX_SZ; ++j){
            if(dist[N][i][j] < mn){
                mn = dist[N][i][j];
                mnState = state(N,i,j);
            }
        }
    }
    vector<string> v;
    v.push_back(codes[5]);
    while(mnState != m1){
        a = mnState.a;
        s1 = mnState.s1;
        s2 = mnState.s2;
        v.push_back(codes[op[a][s1][s2]]);
        mnState = p[a][s1][s2];
    }
    for(auto i = v.rbegin(); i != v.rend(); i++){
        cout << *i << endl;
    }
    return 0;
}
