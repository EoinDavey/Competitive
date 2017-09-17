#include<bits/stdc++.h>
using namespace std;
struct coord {
    int x,y,z;
    coord(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
    coord(){}
};

constexpr int MX_N=202, INF=1000000000;
double adjMat[MX_N][MX_N];
int nxt[MX_N][MX_N];
coord places[MX_N];
int N,M;

double eucdist(int a, int b){
    return sqrt(pow(places[a].x-places[b].x,2) + pow(places[a].y-places[b].y,2) + pow(places[a].z-places[b].z,2));
}

int main(){
    scanf("%d %d",&N,&M);
    int z,x,y;
    for(int i = 0; i < N; ++i){
        scanf("%d %d %d",&places[i].z,&places[i].x,&places[i].y);
        places[i].z*=5;
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            adjMat[i][j] = INF;
    int a,b;
    char buff[40];
    for(int i = 0;i < M; ++i){
        scanf("%d %d %s",&a,&b,buff);
        if(buff[0]=='w' || buff[0]=='s'){
            double d = eucdist(a,b);
            adjMat[a][b] = min(adjMat[a][b], d);
            adjMat[b][a] = min(adjMat[b][a], d);
        } else if(buff[0] == 'l'){
            adjMat[a][b] = min(adjMat[a][b],1.0);
            adjMat[b][a] = min(adjMat[b][a],1.0);
        } else if(buff[0]=='e'){
            adjMat[a][b] = min(adjMat[a][b],1.0);
            adjMat[b][a] = min(adjMat[b][a],eucdist(a,b)*3.0);
        }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            nxt[i][j] = j;
    for(int k = 0; k < N; ++k)
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                if(adjMat[i][j] > adjMat[i][k] + adjMat[k][j]){
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    nxt[i][j] = nxt[i][k];
                }
    int Q; scanf("%d",&Q);
    for(int i = 0; i < Q; ++i){
        scanf("%d %d",&a,&b);
        vector<int> path;
        path.push_back(a);
        while(a != b){
            a = nxt[a][b];
            path.push_back(a);
        }
        for(auto i : path){
            printf("%d ",i);
        }
        putchar('\n');
    }
    return 0;
}
