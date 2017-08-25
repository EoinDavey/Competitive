#include<bits/stdc++.h>
using namespace std;

const int MX_N = 1001;
int N;
int p[MX_N];
int memo[MX_N][101][101];
int mn[MX_N];
int mx[MX_N];

bool possible(int u, int s, int lb){
    if(s > 100)
        return false;
    if(u==N)
        return s==100;
    if(memo[u][s][lb]!=-1)
        return memo[u][s][lb];
    if(p[u]!=-1){
        if(p[u] < lb)
            return memo[u][s][lb] = false;
        return memo[u][s][lb] = possible(u+1,s+p[u],p[u]);
    }
    bool pos=false;
    for(int i = lb; i + s <= 100; i++){
        if(possible(u+1,s+i,i)){
            pos=true;
            mn[u] = min(mn[u],i);
            mx[u] = max(mx[u],i);
        }
    }
    return memo[u][s][lb] = pos;
}

int main(){
    scanf("%d",&N);
    memset(memo,-1,sizeof(memo));
    string names[N],in;
    int rem = 100;
    for(int i = N-1; i >= 0; i--){
        cin >> names[i] >> in;
        if(in=="?")
            p[i]=-1;
        else
            p[i]=stoi(in),rem-=p[i];
    }
    for(int i = 0; i < N; i++)
        mn[i] = 10000,mx[i]=-1;
    possible(0,0,0);
    for(int i = N-1; i >=0; i--){
        cout << names[i] << " ";
        if(p[i]==-1)
            cout << mn[i] << " " << mx[i];
        else
            cout << p[i] << " " << p[i];
        cout << endl;
    }
    return 0;
}
