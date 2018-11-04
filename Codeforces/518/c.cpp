#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 111;
vector<ii> rks[MX_N];
int N, M;

int main(){
    scanf("%d %d",&N,&M);
    int x,y;
    for(int i = 1; i <= M; ++i){
        scanf("%d %d",&x,&y);
        //i is x-coordinate
        //x, y are y-coordinates
        rks[x].pb({i,x});
        rks[y].pb({i,y});
    }
    for(int i = 1; i <= N; ++i)
        if(rks[i].size()==0)
            rks[i].pb({M+i,i});
    for(int i= 1; i <= N; ++i){
        printf("%lu\n", rks[i].size());
        for(auto& j : rks[i])
            printf("%d %d\n",j.fi,j.se);
    }
    return 0;
}
