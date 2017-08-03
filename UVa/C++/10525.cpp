#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ii pair<int,int>

using namespace std;

const int INF = 1000000000;
const ii INF_II = make_pair(INF,INF);
const ii ZERO_II = make_pair(0,0);
ii adjMap[100][100];

ii add(ii a, ii b){
    return make_pair(a.first+b.first,a.second+b.second);
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int N,M; scanf(" %d %d",&N,&M);
        int a,b,c,d;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j<=N; j++)
                if(i!=j)
                    adjMap[i][j] = INF_II;
                else
                    adjMap[i][j] = ZERO_II;
        for(int i = 0; i < M; i++){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            adjMap[a][b] = adjMap[b][a] = min(make_pair(c,d),adjMap[a][b]);
        }
        for(int k = 1; k <= N; k++)
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    adjMap[i][j] = min(adjMap[i][j], add(adjMap[i][k],adjMap[k][j]));
        int Q;scanf("%d",&Q);
        while(Q--){
            scanf(" %d %d",&a,&b);
            if(adjMap[a][b] >= INF_II)
                puts("No Path.");
            else printf("Distance and time to reach destination is %d & %d.\n",adjMap[a][b].second,adjMap[a][b].first);
        }
        if(T!=0)
            putchar('\n');
    }
}
