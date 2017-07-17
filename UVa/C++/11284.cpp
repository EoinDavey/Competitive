#include<iostream>
#include<cstdio>

using namespace std;

const double INF = 100000;
int N,M,P;
double adjMat[52][52];
int locs[14];
double prices[14];
double memo[9000][20];

// Travelling salesman
double tsp(int state, int k){
    if(memo[state][k]!=-1)
        return memo[state][k];
    if(state==(1<<P)-1)
        return memo[state][k] = adjMat[locs[k]][0];
    double mn = INF;
    for(int i = 0; i < P; i++){
        if((state&(1<<i))==0){
            mn=min(mn,adjMat[locs[k]][locs[i]]+tsp((state|(1<<i)),i)); // Go
            mn=min(mn,prices[i] + tsp((state|(1<<i)),k)); // Dont go
        }
    }
    return memo[state][k] = mn;
}

int main(){
    int T; scanf("%d",&T);
    for(int _t = 0; _t < T; _t++){
        scanf("%d %d",&N,&M);
        N++;
        for(int i = 0; i < N; i++)
            for(int j = i+1; j < N; j++)
                adjMat[i][j]=adjMat[j][i]=INF;
        for(int i = 0; i < 9000; i++)
            for(int j = 0; j < 20; j++)
                memo[i][j]=-1;
        int _x,_y; double _c;
        for(int i = 0; i < M; i++){
            scanf("%d %d %lf",&_x,&_y,&_c);
            if(_c < adjMat[_x][_y])
                adjMat[_x][_y]=adjMat[_y][_x]=_c;
        }
        // Floyd Warshall
        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
        scanf("%d",&P);
        double tot = 0.0;
        for(int i= 1; i <= P; i++)
            scanf("%d %lf",&locs[i],&prices[i]);
        for(int i = 1; i <=P; i++)
            tot+=prices[i];
        P++;
        double t = tsp(1,0);
        if(tot-t < 0.00001)
            printf("Don't leave the house\n");
        else 
            printf("Daniel can save $%.2lf\n",tot-t);
    }
    return 0;
}
