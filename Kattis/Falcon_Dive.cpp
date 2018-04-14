#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int MX_N = 1001;
const int INF = 10000;
int N,M;
char C;
char fr1[MX_N][MX_N],fr2[MX_N][MX_N],out[MX_N][MX_N];

bool valid(int i, int j){ return i>=0 && j >= 0 && i < N && j < M; }

int main(){
    scanf("%d %d '%c'",&N,&M,&C);
    ii p1,p2;
    p1 = ii{INF,INF},p2=ii{INF,INF};
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            scanf(" %c",&fr1[i][j]);
            if(fr1[i][j] == C)
                p1 = min(p1,{i,j});
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            scanf(" %c",&fr2[i][j]);
            if(fr2[i][j] == C)
                p2 = min(p2,{i,j});
        }
    }
    ii vec = {p2.first-p1.first,p2.second-p1.second};
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(fr2[i][j]==C && valid(i+vec.first, j+vec.second))
                out[i+vec.first][j+vec.second] = C;
            if(!out[i][j] && fr2[i][j] != C)
                out[i][j] = fr2[i][j];
            if(!out[i][j] && fr1[i][j] != C)
                out[i][j] = fr1[i][j];
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j)
            putchar(out[i][j]);
        putchar('\n');
    }
    return 0;
}
