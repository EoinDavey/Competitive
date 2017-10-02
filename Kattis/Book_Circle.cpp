#include<bits/stdc++.h>
using namespace std;

constexpr int MX_SZ = 2222,INF=100000000;
int B,G,N,S,T;
map<int,int> bk;
int bkcnt=0;
bool vis[MX_SZ];
map<string,int> indMap;

map<int,int> res[MX_SZ];

int insert(const string& str){
    if(indMap.find(str) == indMap.end()){
        indMap[str] = ++bkcnt;
        return bkcnt;
    }
    return indMap[str];
}

int ff(int u, int minE){
    vis[u] = true;
    if(u==T)
        return minE;
    for(auto i = res[u].begin(); i != res[u].end(); i++){
        if(!vis[i->first] && i->second > 0){
            if(int f = ff(i->first,min(minE,i->second))){
                i->second -= f;
                res[i->first][u] += f;
                return f;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> B >> G;
    string in;
    S = 0;
    T = B+G+2;
    for(int i = 1; i <= B; ++i){
        cin >> in;
        cin >> N;
        for(int j = 0; j < N; ++j){
            cin >> in;
            int ind = insert(in);
            bk[ind] = i;
        }
        res[S][i] = 1;
    }
    for(int i = 1; i <= G; ++i){
        cin >> in;
        cin >> N;
        for(int j = 0; j < N; ++j){
            cin >> in;
            int ind = insert(in);
            res[bk[ind]][B+i] = INF;
        }
        res[B+i][T] = 1;
    }
    int mf = 0;
    while(1){
        memset(vis,0,sizeof(vis));
        int f = ff(S,INF);
        if(f==0)
            break;
        mf+=f;
    }
    cout << mf << endl;
    return 0;
}
