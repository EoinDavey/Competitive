#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ii pair<int,int>
using namespace std;

const int MX_SZ = 555;
int N,M;
int board[MX_SZ][MX_SZ];
vector<vector<int>> paths;

int findDiag(int k, int l, int r){
    int sz = paths[k].size();
    vector<int>::iterator mn = lower_bound(paths[k].begin(), paths[k].end(),l);
    if(mn == paths[k].end())
        return 0;
    vector<int>::iterator up = upper_bound(paths[k].begin(), paths[k].end(), r);
    up--;
    return (up-paths[k].begin()) - (mn-paths[k].begin()) + 1;
}

int main(){
    while(scanf("%d %d",&N,&M), N||M){
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                scanf("%d",&board[i][j]);
        paths.clear();
        paths.resize(N+M-1);
        int idx = 0;
        for(int k = N-1; k >= 0; k--){
            for(int i = 0; i < min(N-k,M); i++){
                paths[idx].push_back(board[k+i][i]);
            }
            idx++;
        }
        for(int k = 1; k < M; k++){
            for(int i = 0; i <= min(M-k-1,N-1); i++){
                paths[idx].push_back(board[i][k+i]);
            }
            idx++;
        }
        int Q; scanf("%d",&Q);
        int l,r;
        while(Q--){
            scanf("%d %d",&l,&r);
            int mx = 0;
            for(int i = 0; i < paths.size(); i++){
                mx = max(mx,findDiag(i,l,r));
            }
            printf("%d\n",mx);
        }
        puts("-");
    }
    return 0;
}
